#include <nitro.h>
#include <string.h>

#include "core_sys.h"

#include "struct_decls/struct_02006C24_decl.h"
#include "struct_decls/sys_task.h"
#include "struct_decls/struct_020203AC_decl.h"

#include "struct_defs/struct_020170F4.h"
#include "struct_defs/struct_02017248.h"
#include "struct_defs/struct_02017294.h"
#include "struct_defs/struct_0207C690.h"
#include "struct_defs/struct_02099F80.h"
#include "overlay115/camera_angle.h"

#include "unk_02002328.h"
#include "unk_02005474.h"
#include "overlay_manager.h"
#include "narc.h"
#include "unk_0200D9E8.h"
#include "unk_0200F174.h"
#include "unk_020170BC.h"
#include "unk_02017728.h"
#include "heap.h"
#include "unk_0201E3D8.h"
#include "gx_layers.h"
#include "unk_02020020.h"
#include "unk_0202419C.h"
#include "unk_02024220.h"
#include "dw_warp/dw_warp.h"

typedef struct DistortionWorldWarp {
    GenericPointerData * p3DCallback;
    UnkStruct_020203AC * camera;
    SysTask * task;
    int frameCnt;
    int soundEffectCnt;
    UnkStruct_02017294 animationObj;
    UnkStruct_02017248 animationAnimation;
    UnkStruct_02017248 animationAnimation2;
    UnkStruct_020170F4 animationModel;
    u32 moveFrame;
    int cameraAngle;
    int cameraAngleCalc;
    fx32 cameraDistance;
    int cameraPerspective;
    NNSFndAllocator allocator;
} DistortionWorldWarp;

static void DW_Update(SysTask * task, void * data);
static void DW_VBlankIntr(void * data);
static void DW_VramSetBank(void);
static void DW_InitCamera(DistortionWorldWarp * warp);
static void DWWarp_CameraEnd(DistortionWorldWarp * warp);
static void DWWarp_InitModel(DistortionWorldWarp * warp);
static void DWWarp_DeleteModel(DistortionWorldWarp * warp);
static void Model3D_Update(DistortionWorldWarp * warp);
static GenericPointerData * DWWarp_Init3D(int heapId);
static void DWWarp_Setup3D(void);
static void DWWarp_Exit3D(GenericPointerData * param0);
static void DWWarp_CameraMove(DistortionWorldWarp * warp);

int DWWarp_Init (OverlayManager * ovy, int * state)
{
    SetMainCallback(NULL, NULL);
    DisableHBlank();
    GXLayers_DisableEngineALayers();
    GXLayers_DisableEngineBLayers();

    GX_SetVisiblePlane(0);
    GXS_SetVisiblePlane(0);
    GX_SetVisibleWnd(GX_WNDMASK_NONE);
    GXS_SetVisibleWnd(GX_WNDMASK_NONE);
    G2_BlendNone();
    G2S_BlendNone();

    Heap_Create(HEAP_ID_APPLICATION, HEAP_ID_DISTORTION_WORLD_WARP, HEAP_SIZE_DISTORTION_WORLD_WARP);

    DistortionWorldWarp* dww = OverlayManager_NewData(ovy, sizeof(DistortionWorldWarp), HEAP_ID_DISTORTION_WORLD_WARP);
    MI_CpuClear8(dww, sizeof(DistortionWorldWarp));
    dww->p3DCallback = DWWarp_Init3D(HEAP_ID_DISTORTION_WORLD_WARP);

    SetAutorepeat(4, 8);
    DW_VramSetBank();
    sub_0201E3D8();
    sub_0201E450(4);

    DWWarp_InitModel(dww);
    DW_InitCamera(dww);
    sub_0200F174(0, 1, 1, 0x0, 16, 1, HEAP_ID_DISTORTION_WORLD_WARP);

    gCoreSys.unk_65 = 0;

    GXLayers_SwapDisplay();
    GXLayers_TurnBothDispOn();
    sub_02002AC8(1);
    sub_02002AE4(0);
    sub_02002B20(0);

    dww->task = SysTask_Start(DW_Update, dww, 60000);
    SetMainCallback(DW_VBlankIntr, dww);

    return TRUE;
}

enum {
    DWARP_SEQ_SCREENWIPE = 0,
    DWARP_SEQ_LOOP,
    DWARP_SEQ_CLEAR_SCREEN,
    DWARP_SEQ_WAIT
};

int DWWarp_Main (OverlayManager * ovy, int * state)
{
    DistortionWorldWarp * warp = OverlayManager_Data(ovy);

    // Handle the different states of the warp effect.
    switch (*state) {
    case DWARP_SEQ_SCREENWIPE:
        if (ScreenWipe_Done() == TRUE) {
            (*state)++;
        }
        break;
    case DWARP_SEQ_LOOP:
        // Play the portal sound effect after 15 frames
        if (warp->soundEffectCnt == 15) {
            Sound_PlayEffect(1491);
        }

        warp->soundEffectCnt++;
        warp->frameCnt++;

        // Continue to the next sequence after 85 frames
        if (warp->frameCnt > 85) {
            (*state)++;
        }
        break;
    case DWARP_SEQ_CLEAR_SCREEN:
        // Clear the screen to black
        sub_0200F174(0, 0, 0, 0x0, 20, 1, 30);
        (*state)++;
        break;
    case DWARP_SEQ_WAIT:
        // Wait for the screen wipe to finish
        if (ScreenWipe_Done() == TRUE) {
            return 1;
        }
        break;
    }

    DWWarp_CameraMove(warp);

    return 0;
}

// Exits the Distortion World warp effect overlay.
int DWWarp_Exit (OverlayManager * ovy, int * state)
{
    DistortionWorldWarp * warp = OverlayManager_Data(ovy);

    SysTask_Done(warp->task);

    DWWarp_DeleteModel(warp);
    DWWarp_CameraEnd(warp);
    DWWarp_Exit3D(warp->p3DCallback);

    SetMainCallback(NULL, NULL);
    DisableHBlank();
    sub_0201E530();
    sub_02002AC8(0);
    sub_02002AE4(0);
    sub_02002B20(0);
    OverlayManager_FreeData(ovy);
    Heap_Destroy(30);

    return TRUE;
}

static void DW_Update (SysTask * task, void * data)
{
    DistortionWorldWarp * dw = data;

    Model3D_Update(dw);
    G3_RequestSwapBuffers(GX_SORTMODE_MANUAL, GX_BUFFERMODE_W);
}

static void DW_VBlankIntr (void * data)
{
    DistortionWorldWarp * dw = data;
    OS_SetIrqCheckFlag(OS_IE_V_BLANK);
}

static void DW_VramSetBank (void)
{
    GXLayers_DisableEngineALayers();
    GXLayers_DisableEngineBLayers();

    UnkStruct_02099F80 vramBank = {
        GX_VRAM_BG_128_C,
        GX_VRAM_BGEXTPLTT_NONE,
        GX_VRAM_SUB_BG_32_H,
        GX_VRAM_SUB_BGEXTPLTT_NONE,
        GX_VRAM_OBJ_64_E,
        GX_VRAM_OBJEXTPLTT_NONE,
        GX_VRAM_SUB_OBJ_16_I,
        GX_VRAM_SUB_OBJEXTPLTT_NONE,
        GX_VRAM_TEX_01_AB,
        GX_VRAM_TEXPLTT_01_FG
    };

    GXLayers_SetBanks(&vramBank);

    MI_CpuClear32((void *)HW_BG_VRAM, HW_BG_VRAM_SIZE);
    MI_CpuClear32((void *)HW_DB_BG_VRAM, HW_DB_BG_VRAM_SIZE);
    MI_CpuClear32((void *)HW_OBJ_VRAM, HW_OBJ_VRAM_SIZE);
    MI_CpuClear32((void *)HW_DB_OBJ_VRAM, HW_DB_OBJ_VRAM_SIZE);
}

static void DW_InitCamera (DistortionWorldWarp * warp)
{
    static const CameraAngle DWW_CameraAngle = {
        0x10000 - 0x1c7d,
        0,
        0,
    };
    VecFx32 target = {0, 0, 0};

    warp->camera = sub_020203AC(HEAP_ID_DISTORTION_WORLD_WARP);

    sub_020206D0(&target, (160 << FX32_SHIFT), &DWW_CameraAngle, (((22 * 0xffff) / 360)), 0, 0, warp->camera);
    sub_020206BC(0, (FX32_ONE * 300), warp->camera);

    CameraAngle angle = {0, 0, 0, 0};

    angle = sub_02020A94(warp->camera);
    angle.x = (0x10000 - 0x3fef);

    Camera_SetAngle(&angle, warp->camera);

    sub_020203D4(warp->camera);
}

static void DWWarp_CameraEnd (DistortionWorldWarp * warp)
{
    sub_020203B8(warp->camera);
}

static void DWWarp_InitModel (DistortionWorldWarp * warp)
{
    NARC * narc;

    Heap_FndInitAllocatorForExpHeap(&warp->allocator, HEAP_ID_DISTORTION_WORLD_WARP, 4);

    narc = NARC_ctor(NARC_INDEX_DEMO__TITLE__TITLEDEMO, HEAP_ID_DISTORTION_WORLD_WARP);

    sub_020170D8(&warp->animationModel, narc, 16, HEAP_ID_DISTORTION_WORLD_WARP);

    NNS_G3dMdlUseMdlAlpha(warp->animationModel.unk_08);
    NNS_G3dMdlUseMdlPolygonID(warp->animationModel.unk_08);

    sub_02017164(&warp->animationAnimation, &warp->animationModel, narc, 18, HEAP_ID_DISTORTION_WORLD_WARP, &warp->allocator);
    sub_02017240(&warp->animationAnimation, 0);

    sub_02017164(&warp->animationAnimation2, &warp->animationModel, narc, 17, HEAP_ID_DISTORTION_WORLD_WARP, &warp->allocator);
    sub_02017240(&warp->animationAnimation2, 0);
    sub_02017258(&warp->animationObj, &warp->animationModel);

    sub_02017350(&warp->animationObj, 0, 0, 0);
    sub_0201736C(&warp->animationObj, FX32_ONE, FX32_ONE, FX32_ONE);
    sub_02017348(&warp->animationObj, 1);

    sub_0201727C(&warp->animationObj, &warp->animationAnimation);
    sub_0201727C(&warp->animationObj, &warp->animationAnimation2);

    NARC_dtor(narc);

    warp->cameraAngle = ((0x10000 - 0x3fef) - (0x10000 - 0x1c7d)) / 30;
    warp->cameraAngleCalc = 0x10000 - 0x1c7d;
    warp->cameraDistance = FX32_ONE;
    warp->cameraPerspective = 60 << 8;
}

static void DWWarp_DeleteModel (DistortionWorldWarp * warp)
{
    sub_02017110(&warp->animationModel);
    sub_020171A0(&warp->animationAnimation, &warp->allocator);
    sub_020171A0(&warp->animationAnimation2, &warp->allocator);
}

static void Model3D_Update (DistortionWorldWarp * warp)
{
    VecFx32 scaleVec, transVec;
    MtxFx33 rot33;

    scaleVec.x = FX32_ONE;
    scaleVec.y = FX32_ONE;
    scaleVec.z = FX32_ONE;

    transVec.x = 0;
    transVec.y = 0;
    transVec.z = 0;

    MTX_Identity33(&rot33);

    sub_020241B4();
    sub_020203D4(warp->camera);
    sub_02020854(0, warp->camera);
    sub_020203EC();

    NNS_G3dGlbLightVector(0, 0, -FX32_ONE, 0);
    NNS_G3dGlbLightColor(0, GX_RGB(28, 28, 28));
    NNS_G3dGlbMaterialColorDiffAmb(GX_RGB(31, 31, 31), GX_RGB(31, 31, 31), FALSE);
    NNS_G3dGlbMaterialColorSpecEmi(GX_RGB(31, 31, 31), GX_RGB(31, 31, 31), FALSE);
    NNS_G3dGlbSetBaseTrans(&transVec);
    NNS_G3dGlbSetBaseRot(&rot33);
    NNS_G3dGlbSetBaseScale(&scaleVec);

    sub_020171CC(&warp->animationAnimation, FX32_ONE);
    sub_020171CC(&warp->animationAnimation2, FX32_ONE);

    NNS_G3dGePushMtx();

    sub_02017294(&warp->animationObj);
    NNS_G3dGePopMtx(1);
}

static GenericPointerData * DWWarp_Init3D (int param0)
{
    return sub_02024220(param0, 0, 2, 0, 2, DWWarp_Setup3D);
}

static void DWWarp_Setup3D (void)
{
    GXLayers_EngineAToggleLayers(GX_PLANEMASK_BG0, 1);

    G2_SetBG0Priority(1);

    G3X_SetShading(GX_SHADING_TOON);
    G3X_AntiAlias(TRUE);
    G3X_AlphaTest(FALSE, 0);
    G3X_AlphaBlend(TRUE);
    G3X_EdgeMarking(FALSE);
    G3X_SetFog(FALSE, GX_FOGBLEND_COLOR_ALPHA, GX_FOGSLOPE_0x8000, 0);
    G3X_SetClearColor(GX_RGB(0, 0, 0), 0, 0x7fff, 63, FALSE);
    G3_ViewPort(0, 0, 255, 191);
}

static void DWWarp_Exit3D (GenericPointerData * param0)
{
    sub_020242C4(param0);
}

static void DWWarp_CameraMove (DistortionWorldWarp * warp)
{
    VecFx32 v0 = {0, 0, 0};
    CameraAngle v1 = {0, 0, 0, 0};
    int v2;

    sub_0202094C(-(warp->cameraPerspective >> 8), warp->camera);
    warp->cameraPerspective -= 0x80;

    if (warp->cameraPerspective < (16 << 8)) {
        warp->cameraPerspective = (16 << 8);
    }

    warp->moveFrame++;
}
