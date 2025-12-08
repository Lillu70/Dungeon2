
// ===================================
// Copyright (c) 2025 by Valtteri Kois
// All rights reserved.
// ===================================

namespace Stats
{
    #define STATS(X)    \
    X(might),           \
    X(accuracy),        \
    X(dodge),           \
    X(vitality),        \
    X(speed),           \
    X(perception),      \
    X(resistance),      \
    
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

    constexpr s16 starting_value = 5;
    constexpr s16 points_per_lvl = 10;
};