
// ===================================
// Copyright (c) 2025 by Valtteri Kois
// All rights reserved.
// ===================================

namespace Stats
{
    #define STATS(X)    \
    X(vitality),        \
    X(might),           \
    X(dodge),           \
    X(accuracy),        \
    X(speed),           \
    X(immunity),        \
    X(arcane),          \
    X(armor),           \


    enum T
    {
        STATS(PASTE)
        COUNT
    };
    
    
    String name[] = 
    {
        STATS(PASTE_AS_STRING)
    };
    
    #undef STATS

    constexpr s16 points_per_lvl = 5;
    constexpr u64 PRIMARY_STAT_END = speed;
};