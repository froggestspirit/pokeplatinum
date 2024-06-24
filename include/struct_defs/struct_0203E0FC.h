#ifndef POKEPLATINUM_STRUCT_0203E0FC_H
#define POKEPLATINUM_STRUCT_0203E0FC_H

#include "struct_decls/struct_02025CCC_decl.h"
#include "trainer_info.h"
#include "struct_decls/pokedexdata_decl.h"
#include "game_options.h"
#include "struct_decls/struct_0202B370_decl.h"
#include "journal.h"
#include "struct_decls/struct_0202C878_decl.h"
#include "game_records.h"
#include "struct_decls/struct_0202DA40_decl.h"
#include "struct_decls/struct_020797DC_decl.h"
#include "struct_decls/struct_party_decl.h"
#include "bag.h"
#include "savedata.h"

typedef struct {
    UnkStruct_0202DA40 * unk_00;
    UnkStruct_02025CCC * unk_04;
    Party * unk_08;
    PCBoxes * unk_0C;
    PokedexData * unk_10;
    UnkStruct_0202B370 * unk_14;
    UnkStruct_0202C878 * unk_18;
    TrainerInfo * unk_1C;
    SaveData * unk_20;
    Options * unk_24;
    GameRecords *records;
    Journal * unk_2C;
    Bag * unk_30;
    int unk_34;
    int unk_38;
    int unk_3C;
    int unk_40;
} UnkStruct_0203E0FC;

#endif // POKEPLATINUM_STRUCT_0203E0FC_H
