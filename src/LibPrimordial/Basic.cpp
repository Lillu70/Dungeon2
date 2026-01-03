

// ===================================
// Copyright (c) 2025 by Valtteri Kois
// All rights reserved.
// ===================================

#include "Basic_Generated.cpp"


SIG constexpr u64 Kilobytes(u64 v)
{
    u64 result = v * 1024;
    return result;
}


SIG constexpr u64 Megabytes(u64 v)
{
    u64 k = Kilobytes(1);
    u64 result = v * (k * k);
    return result;
}


SIG constexpr u64 Gigabytes(u64 v)
{
    u64 k = Kilobytes(1);
    u64 result = v * (k * k * k);
    return result;
}


SIG void Mem_Zero(void* ptr, u64 count)
{
    u8* begin = (u8*)ptr;
    u8* end = begin + count;
    
    for(u8* p = begin; p < end; ++p)
    {
        *p = 0;
    }
}


SIG void Mem_Copy(void* dest, void* src, u64 count)
{
    for(char* a = (char*)dest, *b = (char*)src; a < (char*)dest + count; ++a, ++b)
    {
        *a = *b;
    }
}


SIG u64 Weld(u32 a, u32 b)
{
    u64 result = (u64(a) << 32) | (b);
    return result;
}