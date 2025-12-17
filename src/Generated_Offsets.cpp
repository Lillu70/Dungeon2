
// ===================================
// Copyright (c) 2025 by Valtteri Kois
// All rights reserved.
// ===================================

// --- This is a generated file. Do not edit manually! ---


// ---- GENERATE_ENTITY_FN ----
SIG _inline GENERATE_ENTITY_FN_Offset Offset(GENERATE_ENTITY_FN* pointer, Game_State* game_state)
{
    Assert(game_state->executable_base_address);
    GENERATE_ENTITY_FN_Offset offset = {};
    if(pointer)
    {
        offset = {u64((char*)pointer - game_state->executable_base_address) + 1};
    }
    return offset;
}

SIG _inline GENERATE_ENTITY_FN* Pointer(GENERATE_ENTITY_FN_Offset offset, Game_State* game_state)
{
    GENERATE_ENTITY_FN* pointer = {};
    if(offset.v)
    {
        pointer = (GENERATE_ENTITY_FN*)(game_state->executable_base_address + offset.v - 1);
    }
    return pointer;
}
// -------- 

// ---- PROTOTYPE_ENT_GS ----
SIG _inline PROTOTYPE_ENT_GS_Offset Offset(PROTOTYPE_ENT_GS* pointer, Game_State* game_state)
{
    Assert(game_state->executable_base_address);
    PROTOTYPE_ENT_GS_Offset offset = {};
    if(pointer)
    {
        offset = {u64((char*)pointer - game_state->executable_base_address) + 1};
    }
    return offset;
}

SIG _inline PROTOTYPE_ENT_GS* Pointer(PROTOTYPE_ENT_GS_Offset offset, Game_State* game_state)
{
    PROTOTYPE_ENT_GS* pointer = {};
    if(offset.v)
    {
        pointer = (PROTOTYPE_ENT_GS*)(game_state->executable_base_address + offset.v - 1);
    }
    return pointer;
}
// -------- 

// ---- PROTOTYPE_ENT_ENT_GS ----
SIG _inline PROTOTYPE_ENT_ENT_GS_Offset Offset(PROTOTYPE_ENT_ENT_GS* pointer, Game_State* game_state)
{
    Assert(game_state->executable_base_address);
    PROTOTYPE_ENT_ENT_GS_Offset offset = {};
    if(pointer)
    {
        offset = {u64((char*)pointer - game_state->executable_base_address) + 1};
    }
    return offset;
}

SIG _inline PROTOTYPE_ENT_ENT_GS* Pointer(PROTOTYPE_ENT_ENT_GS_Offset offset, Game_State* game_state)
{
    PROTOTYPE_ENT_ENT_GS* pointer = {};
    if(offset.v)
    {
        pointer = (PROTOTYPE_ENT_ENT_GS*)(game_state->executable_base_address + offset.v - 1);
    }
    return pointer;
}
// -------- 

// ---- PROTOTYPE_EFFINST_ENT_GS ----
SIG _inline PROTOTYPE_EFFINST_ENT_GS_Offset Offset(PROTOTYPE_EFFINST_ENT_GS* pointer, Game_State* game_state)
{
    Assert(game_state->executable_base_address);
    PROTOTYPE_EFFINST_ENT_GS_Offset offset = {};
    if(pointer)
    {
        offset = {u64((char*)pointer - game_state->executable_base_address) + 1};
    }
    return offset;
}

SIG _inline PROTOTYPE_EFFINST_ENT_GS* Pointer(PROTOTYPE_EFFINST_ENT_GS_Offset offset, Game_State* game_state)
{
    PROTOTYPE_EFFINST_ENT_GS* pointer = {};
    if(offset.v)
    {
        pointer = (PROTOTYPE_EFFINST_ENT_GS*)(game_state->executable_base_address + offset.v - 1);
    }
    return pointer;
}
// -------- 

// ---- PROTOTYPE_EFFINST_ENT_ENT_GS ----
SIG _inline PROTOTYPE_EFFINST_ENT_ENT_GS_Offset Offset(PROTOTYPE_EFFINST_ENT_ENT_GS* pointer, Game_State* game_state)
{
    Assert(game_state->executable_base_address);
    PROTOTYPE_EFFINST_ENT_ENT_GS_Offset offset = {};
    if(pointer)
    {
        offset = {u64((char*)pointer - game_state->executable_base_address) + 1};
    }
    return offset;
}

SIG _inline PROTOTYPE_EFFINST_ENT_ENT_GS* Pointer(PROTOTYPE_EFFINST_ENT_ENT_GS_Offset offset, Game_State* game_state)
{
    PROTOTYPE_EFFINST_ENT_ENT_GS* pointer = {};
    if(offset.v)
    {
        pointer = (PROTOTYPE_EFFINST_ENT_ENT_GS*)(game_state->executable_base_address + offset.v - 1);
    }
    return pointer;
}
// -------- 

// ---- PROTOTYPE_EFFINST_ENT_ENT_AR_GS ----
SIG _inline PROTOTYPE_EFFINST_ENT_ENT_AR_GS_Offset Offset(PROTOTYPE_EFFINST_ENT_ENT_AR_GS* pointer, Game_State* game_state)
{
    Assert(game_state->executable_base_address);
    PROTOTYPE_EFFINST_ENT_ENT_AR_GS_Offset offset = {};
    if(pointer)
    {
        offset = {u64((char*)pointer - game_state->executable_base_address) + 1};
    }
    return offset;
}

SIG _inline PROTOTYPE_EFFINST_ENT_ENT_AR_GS* Pointer(PROTOTYPE_EFFINST_ENT_ENT_AR_GS_Offset offset, Game_State* game_state)
{
    PROTOTYPE_EFFINST_ENT_ENT_AR_GS* pointer = {};
    if(offset.v)
    {
        pointer = (PROTOTYPE_EFFINST_ENT_ENT_AR_GS*)(game_state->executable_base_address + offset.v - 1);
    }
    return pointer;
}
// -------- 

// ---- PROTOTYPE_EFFINST_ENTOFF_ENT_DDR_GS ----
SIG _inline PROTOTYPE_EFFINST_ENTOFF_ENT_DDR_GS_Offset Offset(PROTOTYPE_EFFINST_ENTOFF_ENT_DDR_GS* pointer, Game_State* game_state)
{
    Assert(game_state->executable_base_address);
    PROTOTYPE_EFFINST_ENTOFF_ENT_DDR_GS_Offset offset = {};
    if(pointer)
    {
        offset = {u64((char*)pointer - game_state->executable_base_address) + 1};
    }
    return offset;
}

SIG _inline PROTOTYPE_EFFINST_ENTOFF_ENT_DDR_GS* Pointer(PROTOTYPE_EFFINST_ENTOFF_ENT_DDR_GS_Offset offset, Game_State* game_state)
{
    PROTOTYPE_EFFINST_ENTOFF_ENT_DDR_GS* pointer = {};
    if(offset.v)
    {
        pointer = (PROTOTYPE_EFFINST_ENTOFF_ENT_DDR_GS*)(game_state->executable_base_address + offset.v - 1);
    }
    return pointer;
}
// -------- 

// ---- PROTOTYPE_EFFINST_ENT_S32PTR_STR_GS ----
SIG _inline PROTOTYPE_EFFINST_ENT_S32PTR_STR_GS_Offset Offset(PROTOTYPE_EFFINST_ENT_S32PTR_STR_GS* pointer, Game_State* game_state)
{
    Assert(game_state->executable_base_address);
    PROTOTYPE_EFFINST_ENT_S32PTR_STR_GS_Offset offset = {};
    if(pointer)
    {
        offset = {u64((char*)pointer - game_state->executable_base_address) + 1};
    }
    return offset;
}

SIG _inline PROTOTYPE_EFFINST_ENT_S32PTR_STR_GS* Pointer(PROTOTYPE_EFFINST_ENT_S32PTR_STR_GS_Offset offset, Game_State* game_state)
{
    PROTOTYPE_EFFINST_ENT_S32PTR_STR_GS* pointer = {};
    if(offset.v)
    {
        pointer = (PROTOTYPE_EFFINST_ENT_S32PTR_STR_GS*)(game_state->executable_base_address + offset.v - 1);
    }
    return pointer;
}
// -------- 

// ---- PROTOTYPE_EFFINST_ENT_STAT_S32PTR_S16PTR_GS ----
SIG _inline PROTOTYPE_EFFINST_ENT_STAT_S32PTR_S16PTR_GS_Offset Offset(PROTOTYPE_EFFINST_ENT_STAT_S32PTR_S16PTR_GS* pointer, Game_State* game_state)
{
    Assert(game_state->executable_base_address);
    PROTOTYPE_EFFINST_ENT_STAT_S32PTR_S16PTR_GS_Offset offset = {};
    if(pointer)
    {
        offset = {u64((char*)pointer - game_state->executable_base_address) + 1};
    }
    return offset;
}

SIG _inline PROTOTYPE_EFFINST_ENT_STAT_S32PTR_S16PTR_GS* Pointer(PROTOTYPE_EFFINST_ENT_STAT_S32PTR_S16PTR_GS_Offset offset, Game_State* game_state)
{
    PROTOTYPE_EFFINST_ENT_STAT_S32PTR_S16PTR_GS* pointer = {};
    if(offset.v)
    {
        pointer = (PROTOTYPE_EFFINST_ENT_STAT_S32PTR_S16PTR_GS*)(game_state->executable_base_address + offset.v - 1);
    }
    return pointer;
}
// -------- 

