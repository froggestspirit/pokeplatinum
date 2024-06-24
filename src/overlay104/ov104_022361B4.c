#include <nitro.h>
#include <string.h>

#include "message.h"
#include "struct_decls/struct_02018340_decl.h"
#include "strbuf.h"
#include "trainer_info.h"
#include "struct_decls/struct_020302DC_decl.h"
#include "struct_decls/struct_0203041C_decl.h"
#include "struct_decls/struct_0203068C_decl.h"
#include "pokemon.h"
#include "struct_decls/struct_party_decl.h"
#include "savedata.h"
#include "overlay104/struct_ov104_022320B4_decl.h"

#include "struct_defs/struct_0204B184.h"
#include "struct_defs/struct_0205AA50.h"
#include "overlay104/struct_ov104_022320B4_t.h"
#include "overlay104/struct_ov104_0223597C.h"
#include "overlay104/struct_ov104_0223A348_sub1.h"
#include "overlay104/struct_ov104_0223A348_sub2.h"
#include "overlay104/struct_ov104_0223BA10.h"
#include "overlay104/struct_ov104_0223C4CC.h"

#include "message.h"
#include "string_template.h"
#include "unk_0200DA60.h"
#include "heap.h"
#include "unk_02018340.h"
#include "unk_0201D670.h"
#include "strbuf.h"
#include "save_state.h"
#include "unk_0202CD50.h"
#include "unk_020302D0.h"
#include "unk_0203061C.h"
#include "communication_information.h"
#include "communication_system.h"
#include "vars_flags.h"
#include "unk_0205DFC4.h"
#include "unk_0206AFE0.h"
#include "pokemon.h"
#include "party.h"
#include "overlay104/ov104_0222DCE0.h"
#include "overlay104/ov104_0222E63C.h"
#include "overlay104/ov104_0222ECE8.h"
#include "overlay104/ov104_022361B4.h"
#include "overlay104/ov104_0223B6F4.h"

UnkStruct_ov104_0223BA10 * ov104_022361B4(SaveData * param0, u16 param1, u8 param2, u16 param3, u16 param4, u16 param5, u16 * param6);
void ov104_02236514(UnkStruct_ov104_0223BA10 * param0, u16 param1);
static void ov104_02236528(UnkStruct_ov104_0223BA10 * param0);
static void ov104_022365F8(UnkStruct_ov104_0223BA10 * param0);
static void ov104_022366A4(UnkStruct_ov104_0223BA10 * param0);
void ov104_022367AC(UnkStruct_ov104_0223BA10 * param0);
void ov104_022367DC(UnkStruct_ov104_0223BA10 * param0, void * param1);
u16 ov104_02236834(void * param0, u8 param1);
void ov104_02236BF0(UnkStruct_ov104_0223BA10 * param0);
void ov104_02236BF8(UnkStruct_ov104_0223BA10 * param0);
void ov104_02236C50(UnkStruct_ov104_0223BA10 * param0);
int ov104_02236D10(UnkStruct_ov104_0223BA10 * param0);
BOOL ov104_02236F70(UnkStruct_ov104_0223BA10 * param0, u16 param1, u16 param2);
void ov104_02236FC0(UnkStruct_ov104_022320B4 * param0, UnkStruct_ov104_0223BA10 * param1);
void ov104_022370E0(UnkStruct_ov104_022320B4 * param0, UnkStruct_ov104_0223BA10 * param1);
void ov104_02237180(UnkStruct_ov104_022320B4 * param0, UnkStruct_ov104_0223BA10 * param1);
static void ov104_022370C0(BGL * param0, Window * param1);
static void ov104_02237284(UnkStruct_ov104_022320B4 * param0, Window * param1, TrainerInfo * param2, u16 param3);
u16 ov104_02237338(UnkStruct_ov104_0223BA10 * param0);

UnkStruct_ov104_0223BA10 * ov104_022361B4 (SaveData * param0, u16 param1, u8 param2, u16 param3, u16 param4, u16 param5, u16 * param6)
{
    u32 v0, v1;
    Party * v2;
    Pokemon * v3;
    UnkStruct_020302DC * v4;
    u8 v5, v6;
    u16 v7, v8;
    static UnkStruct_ov104_0223BA10 * v9;
    UnkStruct_0203041C * v10;

    v9 = Heap_AllocFromHeap(11, sizeof(UnkStruct_ov104_0223BA10));
    MI_CpuClear8(v9, sizeof(UnkStruct_ov104_0223BA10));

    v9->unk_08 = sub_020302DC(param0);
    v9->unk_04 = param0;
    v9->unk_00 = 11;
    v9->unk_28 = Party_New(11);
    v9->unk_2C = Party_New(11);
    v9->unk_A20 = param6;

    v4 = v9->unk_08;
    v10 = sub_0203041C(param0);

    if (param1 == 0) {
        v9->unk_10 = param2;
        v9->unk_11 = 0;

        sub_020302D0(v4);

        if (v9->unk_10 == 3) {
            v5 = sub_0206B6FC(SaveData_GetVarsFlags(v9->unk_04));
        } else {
            v5 = (u8)sub_02030470(v10, 9, v9->unk_10, 0, NULL);
        }

        if (v5 == 1) {
            v9->unk_14 = sub_02030698(sub_0203068C(v9->unk_04), sub_0205E5E0(v9->unk_10), sub_0205E6A8(sub_0205E5E0(v9->unk_10)));
        } else {
            v9->unk_14 = 0;

            sub_020306E4(sub_0203068C(v9->unk_04), sub_0205E630(v9->unk_10), sub_0205E6A8(sub_0205E630(v9->unk_10)), 0);
            sub_020306E4(sub_0203068C(v9->unk_04), sub_0205E658(param2), sub_0205E6A8(sub_0205E658(param2)), 0);

            for (v7 = 0; v7 < 3; v7++) {
                sub_020306E4(sub_0203068C(v9->unk_04), sub_0205E5B4(v9->unk_10, v7), sub_0205E6A8(sub_0205E5B4(v9->unk_10, v7)), 1);
            }
        }

        v9->unk_16 = (u16)(v9->unk_14 / 7);
        v9->unk_18 = 0;
        v9->unk_24[0] = param3;
        v9->unk_24[1] = param4;
        v9->unk_24[2] = param5;
        v9->unk_20 = sub_02030698(sub_0203068C(v9->unk_04), sub_0205E630(v9->unk_10), sub_0205E6A8(sub_0205E630(v9->unk_10)));

        sub_02030804(sub_0203068C(v9->unk_04), sub_0205E630(v9->unk_10), sub_0205E6A8(sub_0205E630(v9->unk_10)), 10);
    } else {
        v9->unk_10 = (u8)sub_02030398(v4, 0, 0, 0, NULL);
        v9->unk_11 = (u8)sub_02030398(v4, 1, 0, 0, NULL);
        v9->unk_14 = sub_02030698(sub_0203068C(v9->unk_04), sub_0205E5E0(v9->unk_10), sub_0205E6A8(sub_0205E5E0(v9->unk_10)));
        v9->unk_16 = (u16)(v9->unk_14 / 7);

        for (v7 = 0; v7 < 3; v7++) {
            v9->unk_24[v7] = (u8)sub_02030398(v4, 7, v7, 0, NULL);
        }
    }

    for (v7 = 0; v7 < 3; v7++) {
        v3 = Party_GetPokemonBySlotIndex(Party_GetFromSavedata(v9->unk_04), v9->unk_24[v7]);
        v9->unk_36A[v7] = Pokemon_GetValue(v3, MON_DATA_HELD_ITEM, NULL);
    }

    v2 = Party_GetFromSavedata(v9->unk_04);
    v6 = ov104_0223B7A8(v9->unk_10, 0);

    for (v7 = 0; v7 < v6; v7++) {
        Party_AddPokemon(v9->unk_28, Party_GetPokemonBySlotIndex(v2, v9->unk_24[v7]));

        v3 = Party_GetPokemonBySlotIndex(v9->unk_28, v7);
        v0 = 0;

        Pokemon_SetValue(v3, 6, &v0);

        if (Pokemon_GetValue(v3, MON_DATA_LEVEL, NULL) > 50) {
            v1 = Pokemon_GetSpeciesBaseExpAt(Pokemon_GetValue(v3, MON_DATA_SPECIES, NULL), 50);
            Pokemon_SetValue(v3, 8, &v1);
            Pokemon_CalcLevelAndStats(v3);
        }
    }

    if (ov104_0223BA14(v9->unk_10) == 1) {
        ov104_0222E630(v9->unk_04);
    }

    return v9;
}

void ov104_02236514 (UnkStruct_ov104_0223BA10 * param0, u16 param1)
{
    if (param1 == 0) {
        ov104_02236528(param0);
    } else {
        ov104_022365F8(param0);
    }

    return;
}

static void ov104_02236528 (UnkStruct_ov104_0223BA10 * param0)
{
    u8 v0;
    int v1;
    UnkStruct_ov104_0223A348_sub2 v2;
    Pokemon * v3;
    Party * v4;
    u16 v5[6];
    u16 v6[6];

    v0 = Party_GetCurrentCount(param0->unk_28);

    for (v1 = 0; v1 < v0; v1++) {
        v3 = Party_GetPokemonBySlotIndex(param0->unk_28, v1);

        param0->unk_394[v1][0] = Pokemon_GetValue(v3, MON_DATA_MOVE1_CUR_PP, NULL);
        param0->unk_394[v1][1] = Pokemon_GetValue(v3, MON_DATA_MOVE2_CUR_PP, NULL);
        param0->unk_394[v1][2] = Pokemon_GetValue(v3, MON_DATA_MOVE3_CUR_PP, NULL);
        param0->unk_394[v1][3] = Pokemon_GetValue(v3, MON_DATA_MOVE4_CUR_PP, NULL);
    }

    ov104_0223B760(param0->unk_10, ov104_0223BB60(param0), param0->unk_30, (7 * 2));

    for (v1 = 0; v1 < (7 * 2); v1++) {
        (void)0;
    }

    ov104_0222E4BC(ov104_0223B7DC(param0->unk_10, 1), param0->unk_30[param0->unk_11], param0->unk_30[param0->unk_11 + 7], param0->unk_26C, param0->unk_288, param0->unk_274, param0->unk_278, ov104_0223BA14(param0->unk_10));

    for (v1 = 0; v1 < 4; v1++) {
        (void)0;
    }

    return;
}

static void ov104_022365F8 (UnkStruct_ov104_0223BA10 * param0)
{
    u16 v0;
    int v1;
    Pokemon * v2;
    u8 v3;
    UnkStruct_ov104_0223A348_sub2 v4[6];
    u8 v5[6];
    u16 v6[6];
    u32 v7[6];

    ov104_022366A4(param0);

    for (v1 = 0; v1 < (7 * 2); v1++) {
        param0->unk_30[v1] = (u16)sub_02030398(param0->unk_08, 6, v1, 0, NULL);
    }

    for (v1 = 0; v1 < 4; v1++) {
        v6[v1] = (u16)sub_02030398(param0->unk_08, 8, v1, 0, NULL);
        param0->unk_26C[v1] = v6[v1];
    }

    ov104_0222E330(v4, v6, v5, NULL, v7, 4, 11, 179);

    v2 = Pokemon_New(11);

    for (v1 = 0; v1 < 4; v1++) {
        ov104_0222DF40(&v4[v1], v2, ov104_0223BA10(param0));
        ov104_0223BAA0(param0, param0->unk_2C, v2);
    }

    Heap_FreeToHeap(v2);

    return;
}

static void ov104_022366A4 (UnkStruct_ov104_0223BA10 * param0)
{
    u8 v0;
    u32 v1;
    u16 v2;
    u8 v3;
    int v4;
    Pokemon * v5;

    v0 = Party_GetCurrentCount(param0->unk_28);

    for (v4 = 0; v4 < v0; v4++) {
        v5 = Party_GetPokemonBySlotIndex(param0->unk_28, v4);

        v2 = (u16)sub_02030398(param0->unk_08, 2, v4, 0, NULL);
        Pokemon_SetValue(v5, 163, &v2);

        v3 = (u8)sub_02030398(param0->unk_08, 3, v4, 0, NULL);
        Pokemon_SetValue(v5, 58, &v3);

        v3 = (u8)sub_02030398(param0->unk_08, 3, v4, 1, NULL);
        Pokemon_SetValue(v5, 59, &v3);

        v3 = (u8)sub_02030398(param0->unk_08, 3, v4, 2, NULL);
        Pokemon_SetValue(v5, 60, &v3);

        v3 = (u8)sub_02030398(param0->unk_08, 3, v4, 3, NULL);
        Pokemon_SetValue(v5, 61, &v3);

        v1 = (u32)sub_02030398(param0->unk_08, 4, v4, 0, NULL);
        Pokemon_SetValue(v5, 160, &v1);

        v2 = (u16)sub_02030398(param0->unk_08, 5, v4, 0, NULL);
        Pokemon_SetValue(v5, 6, &v2);
    }

    return;
}

void ov104_022367AC (UnkStruct_ov104_0223BA10 * param0)
{
    int v0;

    if (param0 == NULL) {
        return;
    }

    if (param0->unk_28 != NULL) {
        Heap_FreeToHeap(param0->unk_28);
    }

    if (param0->unk_2C != NULL) {
        Heap_FreeToHeap(param0->unk_2C);
    }

    MI_CpuClear8(param0, sizeof(UnkStruct_ov104_0223BA10));
    Heap_FreeToHeap(param0);

    param0 = NULL;

    return;
}

void ov104_022367DC (UnkStruct_ov104_0223BA10 * param0, void * param1)
{
    int v0;
    UnkStruct_ov104_0223597C * v1 = param1;

    for (v0 = 0; v0 < 6; v0++) {
        param0->unk_380[v0] = ov104_02236834(param1, v0);
    }

    for (v0 = 0; v0 < 4; v0++) {
        param0->unk_370[v0] = v1->unk_08[v0];
        param0->unk_374[v0] = v1->unk_0C[v0];
        param0->unk_378[v0] = v1->unk_10[v0];
        param0->unk_37C[v0] = v1->unk_14[v0];
    }

    param0->unk_A1C = v1->unk_28;
    return;
}

u16 ov104_02236834 (void * param0, u8 param1)
{
    UnkStruct_ov104_0223597C * v0 = param0;

    if (param1 >= 6) {
        GF_ASSERT(0);
        return 0;
    }

    return v0->unk_20;
}

void ov104_02236848(UnkStruct_ov104_0223BA10 * param0, u8 param1);
u16 ov104_02236B48(UnkStruct_ov104_0223BA10 * param0);
u16 ov104_02236B54(UnkStruct_ov104_0223BA10 * param0);
u16 ov104_02236B58(UnkStruct_ov104_0223BA10 * param0, u8 param1);
void ov104_02236B8C(UnkStruct_ov104_0223BA10 * param0);
void ov104_02236BD0(UnkStruct_ov104_0223BA10 * param0);

void ov104_02236848 (UnkStruct_ov104_0223BA10 * param0, u8 param1)
{
    u16 v0, v1, v2;
    u8 v3;
    u8 v4[4];
    u16 v5[4];
    u32 v6[4];
    u32 v7, v8, v9;
    UnkStruct_0203068C * v10;
    Pokemon * v11;
    UnkStruct_020302DC * v12 = param0->unk_08;
    UnkStruct_0203041C * v13 = sub_0203041C(param0->unk_04);

    v10 = sub_0203068C(param0->unk_04);
    v3 = ov104_0223B7DC(param0->unk_10, 1);
    v4[0] = param0->unk_10;

    sub_02030308(param0->unk_08, 0, 0, 0, v4);
    sub_020302F4(param0->unk_08, 1);

    v4[0] = param0->unk_11;

    sub_02030308(param0->unk_08, 1, 0, 0, v4);
    sub_020306E4(v10, sub_0205E5E0(param0->unk_10), sub_0205E6A8(sub_0205E5E0(param0->unk_10)), param0->unk_14);

    if (param1 != 2) {
        v1 = sub_02030698(v10, sub_0205E608(param0->unk_10), sub_0205E6A8(sub_0205E608(param0->unk_10)));
        v7 = sub_02030848(v10, sub_0205E608(param0->unk_10), sub_0205E6A8(sub_0205E608(param0->unk_10)), param0->unk_14);
        v2 = sub_02030698(v10, sub_0205E608(param0->unk_10), sub_0205E6A8(sub_0205E608(param0->unk_10)));
        v9 = sub_02030698(v10, sub_0205E630(param0->unk_10), sub_0205E6A8(sub_0205E630(param0->unk_10)));

        if (param0->unk_14 == v1) {
            sub_02030848(v10, sub_0205E680(param0->unk_10), sub_0205E6A8(sub_0205E680(param0->unk_10)), v9);
        } else if (v1 < v2) {
            sub_020306E4(v10, sub_0205E680(param0->unk_10), sub_0205E6A8(sub_0205E680(param0->unk_10)), v9);
        }

        v4[0] = param0->unk_27;
        sub_02030430(v13, 9, param0->unk_10, 0, v4);

        if (param0->unk_10 == 3) {
            sub_020306E4(v10, 108, sub_0205E6A8(108), param0->unk_27);
        }
    }

    for (v0 = 0; v0 < (7 * 2); v0++) {
        v5[0] = param0->unk_30[v0];
        sub_02030308(param0->unk_08, 6, v0, 0, v5);
    }

    for (v0 = 0; v0 < 3; v0++) {
        v4[0] = param0->unk_24[v0];
        sub_02030308(param0->unk_08, 7, v0, 0, v4);
    }

    v8 = Party_GetCurrentCount(param0->unk_28);

    for (v0 = 0; v0 < v8; v0++) {
        v11 = Party_GetPokemonBySlotIndex(param0->unk_28, v0);

        v5[0] = Pokemon_GetValue(v11, MON_DATA_CURRENT_HP, NULL);
        sub_02030308(param0->unk_08, 2, v0, 0, v5);

        v4[0] = Pokemon_GetValue(v11, MON_DATA_MOVE1_CUR_PP, NULL);
        sub_02030308(param0->unk_08, 3, v0, 0, v4);

        v4[0] = Pokemon_GetValue(v11, MON_DATA_MOVE2_CUR_PP, NULL);
        sub_02030308(param0->unk_08, 3, v0, 1, v4);

        v4[0] = Pokemon_GetValue(v11, MON_DATA_MOVE3_CUR_PP, NULL);
        sub_02030308(param0->unk_08, 3, v0, 2, v4);

        v4[0] = Pokemon_GetValue(v11, MON_DATA_MOVE4_CUR_PP, NULL);
        sub_02030308(param0->unk_08, 3, v0, 3, v4);

        v6[0] = Pokemon_GetValue(v11, MON_DATA_STATUS_CONDITION, NULL);
        sub_02030308(param0->unk_08, 4, v0, 0, v6);

        v5[0] = Pokemon_GetValue(v11, MON_DATA_HELD_ITEM, NULL);
        sub_02030308(param0->unk_08, 5, v0, 0, v5);
    }

    v8 = Party_GetCurrentCount(param0->unk_2C);

    for (v0 = 0; v0 < v8; v0++) {
        v11 = Party_GetPokemonBySlotIndex(param0->unk_2C, v0);
        v5[0] = param0->unk_26C[v0];

        sub_02030308(param0->unk_08, 8, v0, 0, v5);
    }

    return;
}

u16 ov104_02236B48 (UnkStruct_ov104_0223BA10 * param0)
{
    param0->unk_11++;
    return param0->unk_11;
}

u16 ov104_02236B54 (UnkStruct_ov104_0223BA10 * param0)
{
    return param0->unk_11;
}

u16 ov104_02236B58 (UnkStruct_ov104_0223BA10 * param0, u8 param1)
{
    UnkStruct_ov104_0223A348_sub1 v0;
    UnkStruct_0204B184 * v1;
    u8 v2;

    v2 = param0->unk_11 + (param1 * 7);
    v1 = ov104_0222DD04(&v0, param0->unk_30[v2], 11, 178);

    Heap_FreeToHeap(v1);

    return ov104_0222E10C(v0.unk_04);
}

void ov104_02236B8C (UnkStruct_ov104_0223BA10 * param0)
{
    u16 v0[4];
    int v1;

    v0[0] = 1;

    for (v1 = 0; v1 < 3; v1++) {
        sub_020306E4(sub_0203068C(param0->unk_04), sub_0205E5B4(param0->unk_10, v1), sub_0205E6A8(sub_0205E5B4(param0->unk_10, v1)), 1);
    }

    ov104_02236848(param0, 1);

    return;
}

void ov104_02236BD0 (UnkStruct_ov104_0223BA10 * param0)
{
    param0->unk_27 = 1;

    if (param0->unk_16 < 8) {
        param0->unk_16++;
    }

    param0->unk_11 = 0;
    ov104_02236848(param0, 0);

    return;
}

void ov104_02236BF0 (UnkStruct_ov104_0223BA10 * param0)
{
    ov104_0223BAB8(param0);
    return;
}

void ov104_02236BF8 (UnkStruct_ov104_0223BA10 * param0)
{
    int v0, v1, v2;

    ov104_0222E4BC(ov104_0223B7DC(param0->unk_10, 1), param0->unk_30[param0->unk_11], param0->unk_30[param0->unk_11 + 7], param0->unk_26C, param0->unk_288, param0->unk_274, param0->unk_278, ov104_0223BA14(param0->unk_10));

    for (v0 = 0; v0 < 4; v0++) {
        (void)0;
    }

    ov104_0223BAB8(param0);
    return;
}

void ov104_02236C50 (UnkStruct_ov104_0223BA10 * param0)
{
    u8 v0, v1;
    int v2, v3;
    Pokemon * v4;

    if (CommSys_CurNetId() == 0) {
        v0 = 0;
    } else {
        v0 = 2;
    }

    v1 = ov104_0223B7A8(param0->unk_10, 0);
    v3 = Party_GetCurrentCount(param0->unk_28);

    for (v2 = v0; v2 < (v1 + v0); v2++) {
        v4 = Party_GetPokemonBySlotIndex(param0->unk_28, v2);

        param0->unk_394[v2 - v0][0] = Pokemon_GetValue(v4, MON_DATA_MOVE1_CUR_PP, NULL);
        param0->unk_394[v2 - v0][1] = Pokemon_GetValue(v4, MON_DATA_MOVE2_CUR_PP, NULL);
        param0->unk_394[v2 - v0][2] = Pokemon_GetValue(v4, MON_DATA_MOVE3_CUR_PP, NULL);
        param0->unk_394[v2 - v0][3] = Pokemon_GetValue(v4, MON_DATA_MOVE4_CUR_PP, NULL);
    }

    ov104_0223BA24(param0->unk_28);

    for (v2 = 0; v2 < 4; v2++) {
        param0->unk_370[v2] = 0;
        param0->unk_374[v2] = 0;
        param0->unk_378[v2] = 0;
        param0->unk_37C[v2] = 0;
    }

    return;
}

int ov104_02236D10 (UnkStruct_ov104_0223BA10 * param0)
{
    u8 v0, v1, v2;
    u32 v3, v4;
    int v5, v6, v7, v8;
    Pokemon * v9;
    u8 v10[20];
    int v11 = 0;

    for (v5 = 0; v5 < 20; v5++) {
        v10[v5] = 0;
    }

    param0->unk_12 = 0;
    v8 = 0;

    if (CommSys_CurNetId() == 0) {
        v2 = 0;
    } else {
        v2 = 2;
    }

    v0 = ov104_0223B7A8(param0->unk_10, 0);
    v1 = ov104_0223B7DC(param0->unk_10, 1);

    for (v5 = v2; v5 < (v0 + v2); v5++) {
        v9 = Party_GetPokemonBySlotIndex(param0->unk_28, v5);

        if (Pokemon_GetValue(v9, MON_DATA_SPECIES_EXISTS, NULL) == 0) {
            continue;
        }

        v3 = Pokemon_GetValue(v9, MON_DATA_CURRENT_HP, NULL);
        v4 = Pokemon_GetValue(v9, MON_DATA_MAX_HP, NULL);

        if (v3 > 0) {
            v10[0]++;

            if (v3 == v4) {
                v10[1]++;
            } else {
                if (v3 >= (v4 / 2)) {
                    v10[2]++;
                } else {
                    v10[3]++;
                }
            }

            if (Pokemon_GetValue(v9, MON_DATA_STATUS_CONDITION, NULL) == 0) {
                v10[4]++;
            }
        } else {
            param0->unk_12 = 1;
        }

        v8 += Pokemon_GetValue(v9, MON_DATA_MOVE1_CUR_PP, NULL);
        v8 += Pokemon_GetValue(v9, MON_DATA_MOVE2_CUR_PP, NULL);
        v8 += Pokemon_GetValue(v9, MON_DATA_MOVE3_CUR_PP, NULL);
        v8 += Pokemon_GetValue(v9, MON_DATA_MOVE4_CUR_PP, NULL);
    }

    for (v5 = 0; v5 < v1; v5++) {
        if (param0->unk_374[v5] == 1) {
            v10[8]++;
        } else if (param0->unk_374[v5] == 2) {
            (void)0;
        }
    }

    v7 = 0;

    for (v5 = 0; v5 < v0; v5++) {
        for (v6 = 0; v6 < 4; v6++) {
            v7 += param0->unk_394[v5][v6];
        }
    }

    if ((v7 - v8) <= 5) {
        v10[5]++;
    } else if ((v7 - v8) <= 10) {
        v10[6]++;
    } else if ((v7 - v8) <= 15) {
        v10[7]++;
    }

    v11 += v10[0] * 3;
    v11 += v10[1] * 3;
    v11 += v10[2] * 2;
    v11 += v10[3] * 1;
    v11 += v10[4] * 1;
    v11 += v10[5] * 8;
    v11 += v10[6] * 6;
    v11 += v10[7] * 4;
    v11 += v10[8] * 7;

    if (v11 <= 0) {
        v11 = 1;
    }

    return v11;
}

void ov104_02236ED8 (SaveData * param0, u8 param1, int param2)
{
    u16 v0;

    v0 = sub_02030698(sub_0203068C(param0), sub_0205E630(param1), sub_0205E6A8(sub_0205E630(param1)));

    if (v0 + param2 > 9999) {
        sub_020306E4(sub_0203068C(param0), sub_0205E630(param1), sub_0205E6A8(sub_0205E630(param1)), 9999);
    } else {
        sub_02030804(sub_0203068C(param0), sub_0205E630(param1), sub_0205E6A8(sub_0205E630(param1)), param2);
    }

    sub_0202CF70(sub_0202CD88(param0), (1 + 64), param2);
    return;
}

BOOL ov104_02236F70 (UnkStruct_ov104_0223BA10 * param0, u16 param1, u16 param2)
{
    int v0;

    switch (param1) {
    case 0:
        v0 = ov104_0222F3B8(param0);
        break;
    case 1:
        v0 = ov104_0222F44C(param0);
        break;
    case 2:
        v0 = ov104_0222F4B8(param0);
        break;
    case 3:
        v0 = ov104_0222F5D4(param0);
        break;
    case 4:
        v0 = ov104_0222F6C8(param0, param2);
        break;
    case 5:
        v0 = ov104_0222F710(param0, param2);
        break;
    case 6:
        v0 = ov104_0222F758(param0);
        break;
    }

    return v0;
}

void ov104_02236FC0 (UnkStruct_ov104_022320B4 * param0, UnkStruct_ov104_0223BA10 * param1)
{
    UnkStruct_ov104_0223C4CC * v0 = ov104_0222E924(param0);

    GF_ASSERT(param0->unk_A8 == NULL);
    GF_ASSERT(param0->unk_AC == NULL);

    if (ov104_0223BA14(param1->unk_10) == 0) {
        param0->unk_A8 = sub_0201A778(11, 1);
        BGL_AddWindow(v0->unk_00, param0->unk_A8, 1, 1, 1, 10, 4, 14, (((((1024 - (18 + 12)) - 9) - (27 * 4)) - (11 * 22)) - (10 * 4)));
        ov104_022370C0(v0->unk_00, param0->unk_A8);
    } else {
        param0->unk_A8 = sub_0201A778(11, 1);
        param0->unk_AC = sub_0201A778(11, 1);

        BGL_AddWindow(v0->unk_00, param0->unk_A8, 1, 1, 1, 10, 4, 14, (((((1024 - (18 + 12)) - 9) - (27 * 4)) - (11 * 22)) - (10 * 4)));
        BGL_AddWindow(v0->unk_00, param0->unk_AC, 1, 21, 1, 10, 4, 14, ((((((1024 - (18 + 12)) - 9) - (27 * 4)) - (11 * 22)) - (10 * 4)) - (10 * 4)));

        ov104_022370C0(v0->unk_00, param0->unk_A8);
        ov104_022370C0(v0->unk_00, param0->unk_AC);
    }

    ov104_02237180(param0, param1);
    return;
}

static void ov104_022370C0 (BGL * param0, Window * param1)
{
    Window_Show(param1, 1, ((1024 - (18 + 12)) - 9), 12);
    BGL_FillWindow(param1, 15);

    return;
}

void ov104_022370E0 (UnkStruct_ov104_022320B4 * param0, UnkStruct_ov104_0223BA10 * param1)
{
    Window * v0;
    Window * v1;

    if (ov104_0223BA14(param1->unk_10) == 0) {
        GF_ASSERT(param0->unk_A8 != NULL);
        v0 = param0->unk_A8;
        Window_Clear(v0, 0);
        sub_0201A928(v0, 1);
    } else {
        GF_ASSERT(param0->unk_A8 != NULL);
        GF_ASSERT(param0->unk_AC != NULL);

        if (CommSys_CurNetId() == 0) {
            v0 = param0->unk_A8;
            v1 = param0->unk_AC;
        } else {
            v0 = param0->unk_AC;
            v1 = param0->unk_A8;
        }

        Window_Clear(v0, 0);
        sub_0201A928(v0, 1);
        Window_Clear(v1, 0);
        sub_0201A928(v1, 1);
    }

    param0->unk_A8 = NULL;
    param0->unk_AC = NULL;

    return;
}

void ov104_02237180 (UnkStruct_ov104_022320B4 * param0, UnkStruct_ov104_0223BA10 * param1)
{
    u16 v0, v1;

    if (ov104_0223BA14(param1->unk_10) == 0) {
        GF_ASSERT(param0->unk_A8 != NULL);
        v0 = sub_02030698(sub_0203068C(param1->unk_04), sub_0205E630(param1->unk_10), sub_0205E6A8(sub_0205E630(param1->unk_10)));
        ov104_02237284(param0, param0->unk_A8, SaveData_GetTrainerInfo(param1->unk_04), v0);
    } else {
        GF_ASSERT(param0->unk_A8 != NULL);
        GF_ASSERT(param0->unk_AC != NULL);

        if (CommSys_CurNetId() == 0) {
            v0 = sub_02030698(sub_0203068C(param1->unk_04), sub_0205E630(param1->unk_10), sub_0205E6A8(sub_0205E630(param1->unk_10)));
            v1 = param1->unk_A1C;
        } else {
            v0 = param1->unk_A1C;
            v1 = sub_02030698(sub_0203068C(param1->unk_04), sub_0205E630(param1->unk_10), sub_0205E6A8(sub_0205E630(param1->unk_10)));
        }

        ov104_02237284(param0, param0->unk_A8, CommInfo_TrainerInfo(0), v0);
        ov104_02237284(param0, param0->unk_AC, CommInfo_TrainerInfo(1), v1);
    }

    return;
}

static void ov104_02237284 (UnkStruct_ov104_022320B4 * param0, Window * param1, TrainerInfo * param2, u16 param3)
{
    MessageLoader * v0;
    Strbuf* v1 = Strbuf_Init((10 * 2), param0->unk_34);
    Strbuf* v2 = Strbuf_Init((10 * 2), param0->unk_34);

    v0 = MessageLoader_Init(0, 26, 199, 11);

    StringTemplate_SetNumber(param0->unk_44, 0, param3, 4, 1, 1);
    MessageLoader_GetStrbuf(v0, 2, v1);

    StringTemplate_Format(param0->unk_44, v2, v1);
    PrintStringSimple(param1, 0, v2, 16, 2 * 8, 0xff, NULL);
    StringTemplate_SetPlayerName(param0->unk_44, 0, param2);

    MessageLoader_GetStrbuf(v0, 0, v1);

    StringTemplate_Format(param0->unk_44, v2, v1);
    PrintStringSimple(param1, 0, v2, 0, 0, 0, NULL);

    Strbuf_Free(v1);
    Strbuf_Free(v2);
    MessageLoader_Free(v0);

    sub_0201A954(param1);

    return;
}

u16 ov104_02237338 (UnkStruct_ov104_0223BA10 * param0)
{
    u8 v0;
    u16 v1;
    static const u8 v2[8 + 1] = {0, 3, 3, 4, 4, 5, 5, 7, 7};
    static const u8 v3[8 + 1] = {0, 8, 9, 11, 12, 14, 15, 18, 18};

    v1 = param0->unk_16;

    if ((param0->unk_10 == 0) || (param0->unk_10 == 1)) {
        if (v1 >= 8) {
            v0 = v2[8];
        } else {
            v0 = v2[v1];
        }
    } else {
        if (v1 >= 8) {
            v0 = v3[8];
        } else {
            v0 = v3[v1];
        }
    }

    if (param0->unk_10 == 0) {
        if ((param0->unk_14 == 21) || (param0->unk_14 == 49)) {
            v0 = 20;
        }
    }

    return v0;
}
