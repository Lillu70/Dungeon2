// --- WARNING! ---
// THIS IS A GENERATED FILE; DO NOT EDIT MANUALLY!
// ----------------


// Data types:

// FILE: src\LibPrimordial\Azewin.h:
struct WSecurityAttributes;                                                                                                                                                                 // LINE: 69
struct WSystemInfo;                                                                                                                                                                         // LINE: 78
struct WRect;                                                                                                                                                                               // LINE: 102
struct WPoint;                                                                                                                                                                              // LINE: 112
struct WMessage;                                                                                                                                                                            // LINE: 120
struct WWindowClass;                                                                                                                                                                        // LINE: 133
struct WPixel_Format_Descriptor;                                                                                                                                                            // LINE: 149
struct WMonitorInfo;                                                                                                                                                                        // LINE: 180
struct WWindowPlacement;                                                                                                                                                                    // LINE: 189
struct WRGBQuad;                                                                                                                                                                            // LINE: 202
struct WBitMapInfoHeader;                                                                                                                                                                   // LINE: 212
struct WBitmapInfo;                                                                                                                                                                         // LINE: 229
struct WProcess_Memory_Counters_EX;                                                                                                                                                         // LINE: 237
struct XInputGamepad;                                                                                                                                                                       // LINE: 1590
struct XInputState;                                                                                                                                                                         // LINE: 1604
enum WDSSCL;                                                                                                                                                                                // LINE: 1637
enum WDSBCAPS;                                                                                                                                                                              // LINE: 1646
enum WDSBPLAY;                                                                                                                                                                              // LINE: 1668
struct WDirectSoundCapabilities;                                                                                                                                                            // LINE: 1685
struct WGUID;                                                                                                                                                                               // LINE: 1697
struct WWaveFormatEx;                                                                                                                                                                       // LINE: 1709
struct WDirectSoundBufferDescription;                                                                                                                                                       // LINE: 1722
struct DirectSoundCapabilities;                                                                                                                                                             // LINE: 1735
struct WDirectSound;                                                                                                                                                                        // LINE: 1765
struct WCOMObjectDirectSound;                                                                                                                                                               // LINE: 1794
struct WDirectSoundBuffer;                                                                                                                                                                  // LINE: 1801
struct WCOMObjectDirectSoundBuffer;                                                                                                                                                         // LINE: 1850
enum WError : u32;                                                                                                                                                                          // LINE: 1880
enum WPeekMessageRemove: u32;                                                                                                                                                               // LINE: 1888
enum WWindowMessage : s64;                                                                                                                                                                  // LINE: 1896
enum WWindowStyle : u32;                                                                                                                                                                    // LINE: 1929
enum WClassStyle : u32;                                                                                                                                                                     // LINE: 1964
enum WProcessorArchitecture : u16;                                                                                                                                                          // LINE: 1981
enum WIDC : u16;                                                                                                                                                                            // LINE: 1993
enum WGL_Context : s32;                                                                                                                                                                     // LINE: 2023
enum WMem;                                                                                                                                                                                  // LINE: 2050
enum WPage;                                                                                                                                                                                 // LINE: 2066
enum WVK;                                                                                                                                                                                   // LINE: 2082
enum WGMEM;                                                                                                                                                                                 // LINE: 2225
enum WCF;                                                                                                                                                                                   // LINE: 2236
enum WFileAcces : u32;                                                                                                                                                                      // LINE: 2276
enum WFileOpenMode;                                                                                                                                                                         // LINE: 2285
enum WFileAttribute;                                                                                                                                                                        // LINE: 2295
enum WPixel_Formats : u32;                                                                                                                                                                  // LINE: 2322
enum WSWP;                                                                                                                                                                                  // LINE: 2353
enum WGWL;                                                                                                                                                                                  // LINE: 2369
enum WMONITOR;                                                                                                                                                                              // LINE: 2380
enum WSRC : u32;                                                                                                                                                                            // LINE: 2388
enum WAccessRights;                                                                                                                                                                         // LINE: 2409

// FILE: src\LibPrimordial\Maths.cpp:
union __declspec(intrin_type) __declspec(align(16)) __m128;                                                                                                                                 // LINE: 12

// FILE: src\LibPrimordial\String.cpp:
struct String;                                                                                                                                                                              // LINE: 8
struct U64_To_String_Memory;                                                                                                                                                                // LINE: 380

// FILE: src\LibPrimordial\Arena.cpp:
struct Arena;                                                                                                                                                                               // LINE: 9
struct Arena_Snapshot;                                                                                                                                                                      // LINE: 19
enum class Zero_Memory : u8;                                                                                                                                                                // LINE: 25

// FILE: src\Generated_Offsets.h:
struct GENERATE_ENTITY_FN_Offset;                                                                                                                                                           // LINE: 10
struct PROTOTYPE_ENT_GS_Offset;                                                                                                                                                             // LINE: 15
struct PROTOTYPE_ENT_ENT_GS_Offset;                                                                                                                                                         // LINE: 20
struct PROTOTYPE_EFFINST_ENT_GS_Offset;                                                                                                                                                     // LINE: 25
struct PROTOTYPE_EFFINST_ENT_ENT_AR_GS_Offset;                                                                                                                                              // LINE: 30
struct PROTOTYPE_EFFINST_REF_ENT_DDR_GS_Offset;                                                                                                                                             // LINE: 35
struct PROTOTYPE_EFFINST_ENT_S32PTR_STR_GS_Offset;                                                                                                                                          // LINE: 40
struct PROTOTYPE_EFFINST_ENT_STAT_S32PTR_S16PTR_GS_Offset;                                                                                                                                  // LINE: 45

// FILE: src\Stats.cpp:
namespace Stats
{
    enum T;                                                                                                                                                                                 // LINE: 17
}


// FILE: src\Dungeon.h:
union Color;                                                                                                                                                                                // LINE: 23
struct ANSI_Color_Buffer;                                                                                                                                                                   // LINE: 38
struct Entity_Offset;                                                                                                                                                                       // LINE: 94
struct Effect_Offset;                                                                                                                                                                       // LINE: 100
struct Effects_Node_Offset;                                                                                                                                                                 // LINE: 107
struct Entity_Node_Offset;                                                                                                                                                                  // LINE: 119
struct String_Offset;                                                                                                                                                                       // LINE: 125
struct String_Wrapper;                                                                                                                                                                      // LINE: 131
struct String_Table;                                                                                                                                                                        // LINE: 138
struct String_Table_Root;                                                                                                                                                                   // LINE: 146
struct Reference;                                                                                                                                                                           // LINE: 153
struct Entity_Node;                                                                                                                                                                         // LINE: 160
struct Entity_Root_Node;                                                                                                                                                                    // LINE: 167
struct Dice;                                                                                                                                                                                // LINE: 212
struct Bonus_Dice;                                                                                                                                                                          // LINE: 219
struct Effect_Hash_Key;                                                                                                                                                                     // LINE: 236
struct Effect;                                                                                                                                                                              // LINE: 249
enum class Apply_Effect_Result : u8;                                                                                                                                                        // LINE: 318
enum class Duration_Type : u8;                                                                                                                                                              // LINE: 331
struct Effect_Instance;                                                                                                                                                                     // LINE: 377
struct Effects_Node;                                                                                                                                                                        // LINE: 414
struct Effects_Root;                                                                                                                                                                        // LINE: 425
struct Roll_Result;                                                                                                                                                                         // LINE: 433
struct Initiative;                                                                                                                                                                          // LINE: 443
struct Interactable;                                                                                                                                                                        // LINE: 451
enum class Faction : u8;                                                                                                                                                                    // LINE: 459
struct Entity;                                                                                                                                                                              // LINE: 470
struct Damage_Modifiers_Result;                                                                                                                                                             // LINE: 519
struct Damage_Modifier;                                                                                                                                                                     // LINE: 526
struct Healing_Result;                                                                                                                                                                      // LINE: 538
struct Deal_Damage_Result;                                                                                                                                                                  // LINE: 549
enum class Damage_Type;                                                                                                                                                                     // LINE: 563
struct Critical_Ranges_Result;                                                                                                                                                              // LINE: 570
struct Message_Pipe;                                                                                                                                                                        // LINE: 577
struct Attack_Record;                                                                                                                                                                       // LINE: 584
struct Entity_Iterator;                                                                                                                                                                     // LINE: 657
struct Backwards_Iterator;                                                                                                                                                                  // LINE: 672
struct Effects_Iterator;                                                                                                                                                                    // LINE: 682
struct Effect_Hash_Table_Entry;                                                                                                                                                             // LINE: 694
struct Effect_Hash_Table;                                                                                                                                                                   // LINE: 701
struct Game_State;                                                                                                                                                                          // LINE: 710
struct Character_Creator;                                                                                                                                                                   // LINE: 761
struct Loot_Table_Entry;                                                                                                                                                                    // LINE: 771
struct Loot_Table;                                                                                                                                                                          // LINE: 779
enum class Rarity_Mode;                                                                                                                                                                     // LINE: 787
struct Room_Generator_Element;                                                                                                                                                              // LINE: 796
struct Room_Generator_Element_Array;                                                                                                                                                        // LINE: 803
struct Game_Command;                                                                                                                                                                        // LINE: 892
enum class Call_Style;                                                                                                                                                                      // LINE: 903
struct Command;                                                                                                                                                                             // LINE: 911
typedef void PROTOTYPE_ENT_GS(Entity*, Game_State*);;                                                                                                                                       // LINE: 1012
typedef void PROTOTYPE_ENT_ENT_GS(Entity*, Entity*, Game_State*);;                                                                                                                          // LINE: 1013
typedef void PROTOTYPE_EFFINST_ENT_GS(Effect_Instance*, Entity*, Game_State*);;                                                                                                             // LINE: 1014
typedef void PROTOTYPE_EFFINST_ENT_ENT_AR_GS(Effect_Instance*, Entity*, Entity*, Attack_Record*, Game_State*);;                                                                             // LINE: 1015
typedef void PROTOTYPE_EFFINST_REF_ENT_DDR_GS(Effect_Instance*, Reference, Entity*, Deal_Damage_Result*, Game_State*);;                                                                     // LINE: 1016
typedef void PROTOTYPE_EFFINST_ENT_S32PTR_STR_GS(Effect_Instance*, Entity*, s32*, String, Game_State*);;                                                                                    // LINE: 1017
typedef void PROTOTYPE_EFFINST_ENT_STAT_S32PTR_S16PTR_GS(Effect_Instance*, Entity*, Stats::T, s32*, s16*, Game_State*);;                                                                    // LINE: 1018
typedef Entity* GENERATE_ENTITY_FN(Entity*, Game_State*);;                                                                                                                                  // LINE: 1020
namespace AT
{
    enum T : u8;                                                                                                                                                                            // LINE: 46
}

namespace Rarity
{
    enum T : u8;                                                                                                                                                                            // LINE: 59
}

namespace EFlags
{
    enum T : u64;                                                                                                                                                                           // LINE: 73
}

namespace Equipment_Slots
{
    enum T : u32;                                                                                                                                                                           // LINE: 192
}

namespace Effect_Flags
{
    enum T : s8;                                                                                                                                                                            // LINE: 228
}

namespace Effect_Type
{
    enum T : u8;                                                                                                                                                                            // LINE: 303
}

namespace Class
{
    enum T : u8;                                                                                                                                                                            // LINE: 355
}

namespace Roll_Print_Style
{
    enum T;                                                                                                                                                                                 // LINE: 616
}

namespace Report_Turn_Taken_Status
{
    enum T : u8;                                                                                                                                                                            // LINE: 629
}

namespace Verbose
{
    enum T : u8;                                                                                                                                                                            // LINE: 639
}

namespace Forced
{
    enum T : u8;                                                                                                                                                                            // LINE: 649
}

namespace Attack_Mod
{
    enum T;                                                                                                                                                                                 // LINE: 863
}

namespace CMD_Result
{
    enum T : u8;                                                                                                                                                                            // LINE: 882
}


// FILE: src\Dungeon.cpp:
struct On_Get_Stat_Value_Storage;                                                                                                                                                           // LINE: 1808


// Functions:

// FILE: src\LibPrimordial\Basic_Generated.cpp:
f64 Max(f64 a, f64 b);                                                                                                                                                                      // LINE: 8
f64 Min(f64 a, f64 b);                                                                                                                                                                      // LINE: 15
f64 Abs(f64 value);                                                                                                                                                                         // LINE: 22
f32 Max(f32 a, f32 b);                                                                                                                                                                      // LINE: 29
f32 Min(f32 a, f32 b);                                                                                                                                                                      // LINE: 36
f32 Abs(f32 value);                                                                                                                                                                         // LINE: 43
s64 Max(s64 a, s64 b);                                                                                                                                                                      // LINE: 50
s64 Min(s64 a, s64 b);                                                                                                                                                                      // LINE: 57
s64 Abs(s64 value);                                                                                                                                                                         // LINE: 64
s32 Max(s32 a, s32 b);                                                                                                                                                                      // LINE: 71
s32 Min(s32 a, s32 b);                                                                                                                                                                      // LINE: 78
s32 Abs(s32 value);                                                                                                                                                                         // LINE: 85
s16 Max(s16 a, s16 b);                                                                                                                                                                      // LINE: 92
s16 Min(s16 a, s16 b);                                                                                                                                                                      // LINE: 99
s16 Abs(s16 value);                                                                                                                                                                         // LINE: 106
s8 Max(s8 a, s8 b);                                                                                                                                                                         // LINE: 113
s8 Min(s8 a, s8 b);                                                                                                                                                                         // LINE: 120
s8 Abs(s8 value);                                                                                                                                                                           // LINE: 127
u64 Max(u64 a, u64 b);                                                                                                                                                                      // LINE: 134
u64 Min(u64 a, u64 b);                                                                                                                                                                      // LINE: 141
u32 Max(u32 a, u32 b);                                                                                                                                                                      // LINE: 148
u32 Min(u32 a, u32 b);                                                                                                                                                                      // LINE: 155
u16 Max(u16 a, u16 b);                                                                                                                                                                      // LINE: 162
u16 Min(u16 a, u16 b);                                                                                                                                                                      // LINE: 169
u8 Max(u8 a, u8 b);                                                                                                                                                                         // LINE: 176
u8 Min(u8 a, u8 b);                                                                                                                                                                         // LINE: 183
f64 Square(f64 v);                                                                                                                                                                          // LINE: 190
f64 Cube(f64 v);                                                                                                                                                                            // LINE: 197
f32 Square(f32 v);                                                                                                                                                                          // LINE: 204
f32 Cube(f32 v);                                                                                                                                                                            // LINE: 211
s64 Square(s64 v);                                                                                                                                                                          // LINE: 218
s64 Cube(s64 v);                                                                                                                                                                            // LINE: 225
s32 Square(s32 v);                                                                                                                                                                          // LINE: 232
s32 Cube(s32 v);                                                                                                                                                                            // LINE: 239
s16 Square(s16 v);                                                                                                                                                                          // LINE: 246
s16 Cube(s16 v);                                                                                                                                                                            // LINE: 253
s8 Square(s8 v);                                                                                                                                                                            // LINE: 260
s8 Cube(s8 v);                                                                                                                                                                              // LINE: 267
u64 Square(u64 v);                                                                                                                                                                          // LINE: 274
u64 Cube(u64 v);                                                                                                                                                                            // LINE: 281
u32 Square(u32 v);                                                                                                                                                                          // LINE: 288
u32 Cube(u32 v);                                                                                                                                                                            // LINE: 295
u16 Square(u16 v);                                                                                                                                                                          // LINE: 302
u16 Cube(u16 v);                                                                                                                                                                            // LINE: 309
u8 Square(u8 v);                                                                                                                                                                            // LINE: 316
u8 Cube(u8 v);                                                                                                                                                                              // LINE: 323

// FILE: src\LibPrimordial\Basic.cpp:
u64 Kilobytes(u64 v);                                                                                                                                                                       // LINE: 11
u64 Megabytes(u64 v);                                                                                                                                                                       // LINE: 18
u64 Gigabytes(u64 v);                                                                                                                                                                       // LINE: 25
void Mem_Zero(void* ptr, u64 count);                                                                                                                                                        // LINE: 32
void Mem_Copy(void* dest, void* src, u64 count);                                                                                                                                            // LINE: 44
u64 Weld(u32 a, u32 b);                                                                                                                                                                     // LINE: 53

// FILE: src\LibPrimordial\Maths.cpp:
f32 Square_Root(f32 v);                                                                                                                                                                     // LINE: 32
u32 Random_PCG(u32 seed);                                                                                                                                                                   // LINE: 69
u32 Random_PCG(u32* pcg_state);                                                                                                                                                             // LINE: 77
f32 Fraction(f32 v);                                                                                                                                                                        // LINE: 88
s32 Round_To_S32(f32 v);                                                                                                                                                                    // LINE: 97
f32 Round(f32 v);                                                                                                                                                                           // LINE: 107
f32 Round_Up(f32 v);                                                                                                                                                                        // LINE: 115
s32 Digits(s32 v, s32 base = 10);                                                                                                                                                           // LINE: 128

// FILE: src\LibPrimordial\String.cpp:
u64 Null_Terminated_Length(char* buffer);                                                                                                                                                   // LINE: 17
String To_String(char* cstr);                                                                                                                                                               // LINE: 26
char Last(String str);                                                                                                                                                                      // LINE: 34
char First(String str);                                                                                                                                                                     // LINE: 41
char At(String str, u64 idx);                                                                                                                                                               // LINE: 48
bool Is_Capital_Letter(char c);                                                                                                                                                             // LINE: 60
char To_Lowercase(char c);                                                                                                                                                                  // LINE: 67
bool Is_Whitespace(char c);                                                                                                                                                                 // LINE: 78
bool Seek(String str, char c, u64* output);                                                                                                                                                 // LINE: 102
bool Seek(String str, bool(*check_fn)(char), u64* output);                                                                                                                                  // LINE: 123
u64 Line_Length(String str);                                                                                                                                                                // LINE: 145
String Forward(String str, u64 step);                                                                                                                                                       // LINE: 153
String Forward(String str, String step);                                                                                                                                                    // LINE: 162
bool Is_Integer(char c);                                                                                                                                                                    // LINE: 169
bool Not_Integer(char c);                                                                                                                                                                   // LINE: 176
String Skip_Zeroes(String str);                                                                                                                                                             // LINE: 183
bool Is_Positive_Integer(String str);                                                                                                                                                       // LINE: 192
String Skip_While_True(String str, bool(*compare_fn)(char c));                                                                                                                              // LINE: 208
String Skip_Whitespace(String str);                                                                                                                                                         // LINE: 217
String Skip_Spaces_And_Tabs(String str);                                                                                                                                                    // LINE: 226
bool Match_Case_Insensitive(String str, String comp);                                                                                                                                       // LINE: 235
bool Match_Case_Sensitive(String str, String comp);                                                                                                                                         // LINE: 259
bool Match_Beginning_Case_Insensitive(String str, String comp);                                                                                                                             // LINE: 284
bool Match_Beginning_Case_Sensitive(String str, String comp);                                                                                                                               // LINE: 309
u64 To_U64(String str);                                                                                                                                                                     // LINE: 358
String To_String(u64 integer, U64_To_String_Memory* output);                                                                                                                                // LINE: 386
String Merge(String A, String B, Arena* arena);                                                                                                                                             // LINE: 427

// FILE: src\LibPrimordial\Arena.cpp:
void Initialize_Arena(Arena* arena, u64 reserve_byte_count = Gigabytes(64), u64 pages_per_commit = 16);                                                                                     // LINE: 36
Arena Create_Arena(u64 reserve_byte_count = Gigabytes(64), u64 pages_per_commit = 16);                                                                                                      // LINE: 54
void Clear(Arena* arena, Zero_Memory zero_memory);                                                                                                                                          // LINE: 63
void* Push(Arena* arena, u64 size);                                                                                                                                                         // LINE: 74
char* Push_String(Arena* arena, String str, u64* out_length);                                                                                                                               // LINE: 118
char* Push_String(Arena* arena, String str);                                                                                                                                                // LINE: 128
Arena_Snapshot Snapshot(Arena* arena);                                                                                                                                                      // LINE: 137
void Restore(Arena* arena, Arena_Snapshot snapshot);                                                                                                                                        // LINE: 144
bool Is_Taken(Arena_Snapshot snapshot);                                                                                                                                                     // LINE: 151
String To_String(Arena* arena);                                                                                                                                                             // LINE: 158

// FILE: src\LibPrimordial\Win32.cpp:
f64 OS_Time();                                                                                                                                                                              // LINE: 17
void OS_Sleep(f64 seconds);                                                                                                                                                                 // LINE: 27
String OS_Read_File(String path, Arena* arena);                                                                                                                                             // LINE: 37
bool OS_Write_File(String buffer, String path, Arena* arena);                                                                                                                               // LINE: 111
void* OS_Get_Executable_Base_Address();                                                                                                                                                     // LINE: 173

// FILE: src\Generated_Offsets.cpp:
_inline GENERATE_ENTITY_FN_Offset Offset(GENERATE_ENTITY_FN* pointer, Game_State* game_state);                                                                                              // LINE: 11
_inline GENERATE_ENTITY_FN* Pointer(GENERATE_ENTITY_FN_Offset offset, Game_State* game_state);                                                                                              // LINE: 22
_inline PROTOTYPE_ENT_GS_Offset Offset(PROTOTYPE_ENT_GS* pointer, Game_State* game_state);                                                                                                  // LINE: 34
_inline PROTOTYPE_ENT_GS* Pointer(PROTOTYPE_ENT_GS_Offset offset, Game_State* game_state);                                                                                                  // LINE: 45
_inline PROTOTYPE_ENT_ENT_GS_Offset Offset(PROTOTYPE_ENT_ENT_GS* pointer, Game_State* game_state);                                                                                          // LINE: 57
_inline PROTOTYPE_ENT_ENT_GS* Pointer(PROTOTYPE_ENT_ENT_GS_Offset offset, Game_State* game_state);                                                                                          // LINE: 68
_inline PROTOTYPE_EFFINST_ENT_GS_Offset Offset(PROTOTYPE_EFFINST_ENT_GS* pointer, Game_State* game_state);                                                                                  // LINE: 80
_inline PROTOTYPE_EFFINST_ENT_GS* Pointer(PROTOTYPE_EFFINST_ENT_GS_Offset offset, Game_State* game_state);                                                                                  // LINE: 91
_inline PROTOTYPE_EFFINST_ENT_ENT_AR_GS_Offset Offset(PROTOTYPE_EFFINST_ENT_ENT_AR_GS* pointer, Game_State* game_state);                                                                    // LINE: 103
_inline PROTOTYPE_EFFINST_ENT_ENT_AR_GS* Pointer(PROTOTYPE_EFFINST_ENT_ENT_AR_GS_Offset offset, Game_State* game_state);                                                                    // LINE: 114
_inline PROTOTYPE_EFFINST_REF_ENT_DDR_GS_Offset Offset(PROTOTYPE_EFFINST_REF_ENT_DDR_GS* pointer, Game_State* game_state);                                                                  // LINE: 126
_inline PROTOTYPE_EFFINST_REF_ENT_DDR_GS* Pointer(PROTOTYPE_EFFINST_REF_ENT_DDR_GS_Offset offset, Game_State* game_state);                                                                  // LINE: 137
_inline PROTOTYPE_EFFINST_ENT_S32PTR_STR_GS_Offset Offset(PROTOTYPE_EFFINST_ENT_S32PTR_STR_GS* pointer, Game_State* game_state);                                                            // LINE: 149
_inline PROTOTYPE_EFFINST_ENT_S32PTR_STR_GS* Pointer(PROTOTYPE_EFFINST_ENT_S32PTR_STR_GS_Offset offset, Game_State* game_state);                                                            // LINE: 160
_inline PROTOTYPE_EFFINST_ENT_STAT_S32PTR_S16PTR_GS_Offset Offset(PROTOTYPE_EFFINST_ENT_STAT_S32PTR_S16PTR_GS* pointer, Game_State* game_state);                                            // LINE: 172
_inline PROTOTYPE_EFFINST_ENT_STAT_S32PTR_S16PTR_GS* Pointer(PROTOTYPE_EFFINST_ENT_STAT_S32PTR_S16PTR_GS_Offset offset, Game_State* game_state);                                            // LINE: 183

// FILE: src\Effects.cpp:
Effect_Offset Get_Critical_Effect_Offset(Game_State* game_state);                                                                                                                           // LINE: 13
Effect_Offset Get_Might_Effect_Offset(Game_State* game_state);                                                                                                                              // LINE: 28
Effect_Offset Get_Enraged_Effect_Offset(Game_State* game_state);                                                                                                                            // LINE: 43
Effect_Offset Get_Vampirism_Effect_Offset(Game_State* game_state);                                                                                                                          // LINE: 116
Dice Poison_Damage_Dice();                                                                                                                                                                  // LINE: 174
void Poison_On_Turn_End_FN(Effect_Instance* instance, Entity* target, Game_State* game_state);                                                                                              // LINE: 181
Effect_Offset Get_Poison_Effect_Offset(Game_State* game_state);                                                                                                                             // LINE: 198
Effect_Offset Get_Burning_Effect_Offset(Game_State* game_state);                                                                                                                            // LINE: 215
Effect_Offset Get_Weak_Grip_Offset(Game_State* game_state);                                                                                                                                 // LINE: 250
void Stun_Attacker(Effect_Instance* instance, Entity* attacker, Entity* defender, Attack_Record* ar, Game_State* game_state);                                                               // LINE: 303
Effect_Instance Reckless_Attack(Entity* attacker, Game_State* game_state);                                                                                                                  // LINE: 324
Effect_Instance Careful_Attack(Entity* attacker, Game_State* game_state);                                                                                                                   // LINE: 351
Effect_Instance Weakspot_Attack(Entity* attacker, Game_State* game_state);                                                                                                                  // LINE: 381
Effect_Instance Allin_Attack(Entity* attacker, Game_State* game_state);                                                                                                                     // LINE: 408
Effect_Instance Guarding_Attack(Entity* attacker, Game_State* game_state);                                                                                                                  // LINE: 438
Effect_Instance Evasive_Attack(Entity* attacker, Game_State* game_state);                                                                                                                   // LINE: 465
Effect_Instance Execute_Attack(Entity* attacker, Game_State* game_state);                                                                                                                   // LINE: 492
Effect_Instance Disarming_Attack(Entity* attacker, Game_State* game_state);                                                                                                                 // LINE: 557
Effect_Instance Vampiric_Attack(Entity* attacker, Game_State* game_state);                                                                                                                  // LINE: 629
Effect_Instance Blessed_Attack(Entity* attacker, Game_State* game_state);                                                                                                                   // LINE: 686
Effect_Instance Berserking_Attack(Entity* attacker, Game_State* game_state);                                                                                                                // LINE: 760
Effect_Instance Redirect_Attack(Entity* attacker, Game_State* game_state);                                                                                                                  // LINE: 834
Effect_Instance Change_Attack(Entity* attacker, Game_State* game_state);                                                                                                                    // LINE: 886
Effect_Instance Thieving_Attack(Entity* attacker, Game_State* game_state);                                                                                                                  // LINE: 986
Effect_Instance Stylish_Attack(Entity* attacker, Game_State* game_state);                                                                                                                   // LINE: 1081

// FILE: src\Items.cpp:
Loot_Table Basic_Consumables_Loot_Table(Game_State* game_state);                                                                                                                            // LINE: 7
Loot_Table Basic_Trinkets_Loot_Table(Game_State* game_state);                                                                                                                               // LINE: 22
Loot_Table Basic_Armors_Loot_Table(Game_State* game_state);                                                                                                                                 // LINE: 41
Loot_Table Basic_Weapons_Loot_Table(Game_State* game_state);                                                                                                                                // LINE: 76
Entity* Create_Greate_Sword(Entity* room, Game_State* game_state);                                                                                                                          // LINE: 100
Entity* Create_Halberd(Entity* room, Game_State* game_state);                                                                                                                               // LINE: 132
Entity* Create_Greate_Club(Entity* room, Game_State* game_state);                                                                                                                           // LINE: 165
Entity* Create_Magma_Hammer(Entity* room, Game_State* game_state);                                                                                                                          // LINE: 198
Entity* Create_War_Pick(Entity* room, Game_State* game_state);                                                                                                                              // LINE: 263
Entity* Create_Straightsword(Entity* room, Game_State* game_state);                                                                                                                         // LINE: 291
Entity* Create_Mace(Entity* room, Game_State* game_state);                                                                                                                                  // LINE: 318
Entity* Create_Rapier(Entity* room, Game_State* game_state);                                                                                                                                // LINE: 345
Entity* Create_Short_Spear(Entity* room, Game_State* game_state);                                                                                                                           // LINE: 375
Entity* Create_Morning_Star(Entity* room, Game_State* game_state);                                                                                                                          // LINE: 403
Entity* Create_Three_Headed_Flail(Entity* room, Game_State* game_state);                                                                                                                    // LINE: 432
Entity* Create_Dagger(Entity* room, Game_State* game_state);                                                                                                                                // LINE: 462
Entity* Create_Poison_Dagger(Entity* room, Game_State* game_state);                                                                                                                         // LINE: 492
Entity* Create_Cape_Of_Avoidance(Entity* room, Game_State* game_state);                                                                                                                     // LINE: 561
Entity* Create_Cape_Of_Dashing(Entity* room, Game_State* game_state);                                                                                                                       // LINE: 587
Entity* Create_Backpack(Entity* room, Game_State* game_state);                                                                                                                              // LINE: 613
Entity* Create_Ring_Of_Giants(Entity* room, Game_State* game_state);                                                                                                                        // LINE: 642
Entity* Create_Ring_Of_Strange_Fortunes(Entity* room, Game_State* game_state);                                                                                                              // LINE: 670
Entity* Create_Ring_Of_Rebirth(Entity* room, Game_State* game_state);                                                                                                                       // LINE: 696
Entity* Create_Ring_Of_Regeneration(Entity* room, Game_State* game_state);                                                                                                                  // LINE: 755
Entity* Create_Gloves_Of_Brutality(Entity* room, Game_State* game_state);                                                                                                                   // LINE: 797
Entity* Create_Wooden_Shield(Entity* room, Game_State* game_state);                                                                                                                         // LINE: 824
Entity* Create_Buckler(Entity* room, Game_State* game_state);                                                                                                                               // LINE: 850
Entity* Create_Kite_Shield(Entity* room, Game_State* game_state);                                                                                                                           // LINE: 876
Entity* Create_Barn_Door_Shield(Entity* room, Game_State* game_state);                                                                                                                      // LINE: 902
Entity* Create_Tower_Shield(Entity* room, Game_State* game_state);                                                                                                                          // LINE: 929
Entity* Create_Shearing_Light(Entity* room, Game_State* game_state);                                                                                                                        // LINE: 957
Entity* Create_Leather_Cuirass(Entity* room, Game_State* game_state);                                                                                                                       // LINE: 984
Entity* Create_Gambeson(Entity* room, Game_State* game_state);                                                                                                                              // LINE: 1010
Entity* Create_Breastplate(Entity* room, Game_State* game_state);                                                                                                                           // LINE: 1037
Entity* Create_Skull_Cap(Entity* room, Game_State* game_state);                                                                                                                             // LINE: 1067
Entity* Create_Arming_Cap(Entity* room, Game_State* game_state);                                                                                                                            // LINE: 1093
Entity* Create_Chainmail_Hood(Entity* room, Game_State* game_state);                                                                                                                        // LINE: 1118
Entity* Create_Barbute(Entity* room, Game_State* game_state);                                                                                                                               // LINE: 1144
Entity* Create_Plate_Leggings(Entity* room, Game_State* game_state);                                                                                                                        // LINE: 1172
Entity* Create_Leather_Tights(Entity* room, Game_State* game_state);                                                                                                                        // LINE: 1201
Entity* Create_Padded_Pants(Entity* room, Game_State* game_state);                                                                                                                          // LINE: 1226
Entity* Create_Warrior_Kilt(Entity* room, Game_State* game_state);                                                                                                                          // LINE: 1251
Entity* Create_Barbarian_Loing_Cloth(Entity* room, Game_State* game_state);                                                                                                                 // LINE: 1278
Entity* Create_Travel_Boots(Entity* room, Game_State* game_state);                                                                                                                          // LINE: 1305
Entity* Create_Sabatons(Entity* room, Game_State* game_state);                                                                                                                              // LINE: 1331
Entity* Create_Gladiator_Sandals(Entity* room, Game_State* game_state);                                                                                                                     // LINE: 1360
Entity* Create_Leather_Boots(Entity* room, Game_State* game_state);                                                                                                                         // LINE: 1387
Entity* Create_Antidote(Entity* container, Game_State* game_state);                                                                                                                         // LINE: 1412
Entity* Create_Healing_Potion(Entity* container, Game_State* game_state);                                                                                                                   // LINE: 1452
Entity* Create_Ring_Of_Just_Fucking_Crit(Entity* room, Game_State* game_state);                                                                                                             // LINE: 1540

// FILE: src\Factory.cpp:
void Finalize_Entity(Entity* entity, Entity* container, Game_State* game_state);                                                                                                            // LINE: 9
Entity* Create_Class_Adventurer(Game_State* game_state);                                                                                                                                    // LINE: 18
Entity* Create_Class_Wretched(Game_State* game_state);                                                                                                                                      // LINE: 64
Entity* Create_Bandit(Entity* room, Game_State* game_state);                                                                                                                                // LINE: 84
Entity* Create_Giant_Rat(Entity* room, Game_State* game_state);                                                                                                                             // LINE: 111
Entity* Create_Rat_Meat(Entity* container, Game_State* game_state);                                                                                                                         // LINE: 185
Entity* Create_Rat_Mound(Entity* room, Game_State* game_state);                                                                                                                             // LINE: 199
Entity* Create_Spider(Entity* room, Game_State* game_state);                                                                                                                                // LINE: 225
Entity* Create_Boss_Spider(Entity* room, Game_State* game_state);                                                                                                                           // LINE: 254
void Generate_Entrance_Room(Entity* room, Game_State* game_state);                                                                                                                          // LINE: 302
Room_Generator_Element_Array Caves();                                                                                                                                                       // LINE: 322

// FILE: src\Dungeon.cpp:
char* Get_Output_Color_CSTR(ANSI_Color_Buffer* buffer, u8 red, u8 green, u8 blue);                                                                                                          // LINE: 62
char* Get_Output_Color_CSTR(ANSI_Color_Buffer* buffer, Color color);                                                                                                                        // LINE: 72
void Set_Output_Color(u8 red, u8 green, u8 blue);                                                                                                                                           // LINE: 79
void Set_Output_Color(Color color);                                                                                                                                                         // LINE: 87
char* Entity_Color(Entity* entity, Game_State* game_state);                                                                                                                                 // LINE: 93
String Format_Message(Game_State* game_state, char* format_string, ...);                                                                                                                    // LINE: 120
_inline void Flush_Messages(Game_State* game_state);                                                                                                                                        // LINE: 139
_inline void Print_Messages(Game_State* game_state);                                                                                                                                        // LINE: 146
void Push_Message(String message, Game_State* game_state);                                                                                                                                  // LINE: 164
void Wait(f64 seconds, Game_State* game_state);                                                                                                                                             // LINE: 179
String Get_User_Input(Game_State* game_state);                                                                                                                                              // LINE: 188
bool User_Query_Yes_No(Game_State* game_state);                                                                                                                                             // LINE: 207
u64 Base_Alphabet_Digits(u64 v);                                                                                                                                                            // LINE: 241
u64 Encode_Base_Alphabet(u64 identity, char character);                                                                                                                                     // LINE: 261
U64_To_String_Memory Decode_Base_Aplhabet(u64 identity);                                                                                                                                    // LINE: 272
Reference* Find_Empty_Slot(Entity_Node* node);                                                                                                                                              // LINE: 291
_inline Entity_Offset Offset(Entity* entity, Game_State* game_state);                                                                                                                       // LINE: 313
_inline Entity* Pointer(Entity_Offset offset, Game_State* game_state);                                                                                                                      // LINE: 325
_inline Effect_Offset Offset(Effect* effect, Game_State* game_state);                                                                                                                       // LINE: 337
_inline Effect* Pointer(Effect_Offset offset, Game_State* game_state);                                                                                                                      // LINE: 350
_inline Entity_Node_Offset Offset(Entity_Node* entity_node, Game_State* game_state);                                                                                                        // LINE: 363
_inline Entity_Node* Pointer(Entity_Node_Offset offset, Game_State* game_state);                                                                                                            // LINE: 375
_inline Effects_Node_Offset Offset(Effects_Node* effects_node, Game_State* game_state);                                                                                                     // LINE: 387
_inline Effects_Node* Pointer(Effects_Node_Offset offset, Game_State* game_state);                                                                                                          // LINE: 399
String Unwrap_String(String_Wrapper* strw, Game_State* game_state);                                                                                                                         // LINE: 411
String_Offset Offset(String str, Game_State* game_state);                                                                                                                                   // LINE: 419
String Get_String(String_Offset offset, Game_State* game_state);                                                                                                                            // LINE: 486
_inline u64 Storage_Offset(void* ptr, Game_State* game_state);                                                                                                                              // LINE: 499
_inline void* Pull_From_Storage_Offset(u64 offset, Game_State* game_state);                                                                                                                 // LINE: 512
Reference* Find_Entity(Entity* entity, Entity_Root_Node* storage, Game_State* game_state, Entity_Node** out_node = 0);                                                                      // LINE: 525
Entity* Find_Entity_By_Name_Or_Reference_Number(Entity* actor, Reference space, String name_or_reference_number, Game_State* game_state, Verbose::T verbose = Verbose::T(1));               // LINE: 551
Entity* Find_Entity_By_Name(Entity* actor, Entity* space, String name, Game_State* game_state, Verbose::T verbose = Verbose::T(1));                                                         // LINE: 563
Entity* Find_Entity_By_Name_Or_Reference_Number(Entity* actor, Entity* space, String name_or_reference_number, Game_State* game_state, Verbose::T verbose = Verbose::T(1));                 // LINE: 594
Reference Make_Reference(Entity* entity, Game_State* game_state);                                                                                                                           // LINE: 644
Entity* Dereference(Reference* reference, Game_State* game_state);                                                                                                                          // LINE: 653
Entity* Dereference(Reference reference, Game_State* game_state);                                                                                                                           // LINE: 673
Entity_Iterator Make_Iterator(Entity_Root_Node* root, Game_State* game_state);                                                                                                              // LINE: 680
Entity_Iterator Make_Iterator(Entity* entity, Game_State* game_state);                                                                                                                      // LINE: 703
Effects_Iterator Make_Iterator(Effects_Root* root, Game_State* game_state);                                                                                                                 // LINE: 711
Reference* Next(Entity_Iterator* iter);                                                                                                                                                     // LINE: 730
Entity* Next_Entity(Entity_Iterator* iter);                                                                                                                                                 // LINE: 760
u64 Count(Entity_Root_Node* root_node, Game_State* game_state);                                                                                                                             // LINE: 774
bool Memory_Snapshot_Save(String file_path, Game_State* game_state);                                                                                                                        // LINE: 787
bool Memory_Snapshot_Restore(String file_path, Game_State* game_state);                                                                                                                     // LINE: 796
Effect_Instance* Next_Effect_Instance(Effects_Iterator* iter);                                                                                                                              // LINE: 828
_inline Effect_Instance* Next(Effects_Iterator* iter);                                                                                                                                      // LINE: 861
Effect* Next_Effect(Effects_Iterator* iter);                                                                                                                                                // LINE: 868
Backwards_Iterator Make_Backwards_Iterator(Entity_Root_Node* root, Game_State* game_state);                                                                                                 // LINE: 882
Reference* Previous(Backwards_Iterator* back_iter);                                                                                                                                         // LINE: 896
void Add_Dice(Effect* effect, s16 count, s16 faces);                                                                                                                                        // LINE: 940
u32 Roll(u32 range, Game_State* game_state);                                                                                                                                                // LINE: 969
s32 Roll(Dice dice, Game_State* game_state);                                                                                                                                                // LINE: 981
s32* Roll_With_Record(Dice dice, Game_State* game_state);                                                                                                                                   // LINE: 997
f32 Random_F32(Game_State* game_state);                                                                                                                                                     // LINE: 1011
Roll_Result Stat_Roll(s32 value, Stats::T stat, Game_State* game_state);                                                                                                                    // LINE: 1021
s32 Value(Roll_Result rr);                                                                                                                                                                  // LINE: 1037
Roll_Result Stat_Roll(Entity* entity, Stats::T stat, Game_State* game_state);                                                                                                               // LINE: 1044
_inline bool Is_Rolled(Roll_Result rr);                                                                                                                                                     // LINE: 1055
void Print_Dice(Dice dice, s32 result);                                                                                                                                                     // LINE: 1062
void Print_Roll_Result(Roll_Result rr);                                                                                                                                                     // LINE: 1068
void Print_Attack_Record(Attack_Record* ar, Game_State* game_state);                                                                                                                        // LINE: 1081
_inline String Name_(Entity* entity, Game_State* game_state);                                                                                                                               // LINE: 1317
String Name(Entity* entity, Game_State* game_state);                                                                                                                                        // LINE: 1324
String Colored_Name(Entity* entity, Game_State* game_state);                                                                                                                                // LINE: 1338
char* Action_Name(AT::T action);                                                                                                                                                            // LINE: 1349
void Print_Required_Equipment_Slots(Entity* item);                                                                                                                                          // LINE: 1376
void Push_Generic_Apply_Effect_Message(Effect_Instance* source_effect, Entity* target, Effect_Instance new_effect, Apply_Effect_Result apply, Game_State* game_state);                      // LINE: 1400
void Remove_From_Residence(Entity* entity, Game_State* game_state);                                                                                                                         // LINE: 1457
void Release_Entity_Node(Entity_Root_Node* root, Game_State* game_state);                                                                                                                   // LINE: 1491
Entity_Node* Request_Entity_Node(Game_State* game_state);                                                                                                                                   // LINE: 1513
Effect* Request_Effect(Game_State* game_state);                                                                                                                                             // LINE: 1530
void Release_Effect(Effect* effect, Game_State* game_state);                                                                                                                                // LINE: 1553
Entity* Request_Entity(Game_State* game_state);                                                                                                                                             // LINE: 1567
void Release_Entity(Entity* entity, Game_State* game_state);                                                                                                                                // LINE: 1589
Effects_Node* Request_Effects_Node(Game_State* game_state);                                                                                                                                 // LINE: 1597
void Release_Effects_Node(Effects_Node* node, Game_State* game_state);                                                                                                                      // LINE: 1614
void Insert(Entity* entity, Entity_Root_Node* storage, Game_State* game_state);                                                                                                             // LINE: 1622
void Assign_Dublicate_Name_Identifier(Entity* entity_to_insert, Entity* storage, Game_State* game_state);                                                                                   // LINE: 1659
void Deep_Insert(Entity* entity, Entity* storage_entity, Game_State* game_state);                                                                                                           // LINE: 1715
void Remove_All_Effects(Entity* entity, Game_State* game_state);                                                                                                                            // LINE: 1730
void Delete_Entity(Entity* entity, Game_State* game_state);                                                                                                                                 // LINE: 1788
bool Has_Content(Entity_Root_Node* root);                                                                                                                                                   // LINE: 1795
bool Is_Empty(Entity_Root_Node* root);                                                                                                                                                      // LINE: 1802
s32 Get_Stat_Value(Entity* entity, Stats::T stat, Game_State* game_state, u64* out_effect_count = 0);                                                                                       // LINE: 1815
s32 Exp_To_Level_Up(s32 _lvl);                                                                                                                                                              // LINE: 1862
_inline s32 Exp_To_Level_Up(Entity* entity);                                                                                                                                                // LINE: 1870
s16 Calculate_Level(Entity* entity);                                                                                                                                                        // LINE: 1877
void Set_Level_Based_On_Stats(Entity* entity);                                                                                                                                              // LINE: 1890
s16 Level(Entity* entity);                                                                                                                                                                  // LINE: 1897
s32 Max_Health(Entity* entity, Game_State* game_state);                                                                                                                                     // LINE: 1904
f32 Critical_Multiplier(Entity* entity, Game_State* game_state);                                                                                                                            // LINE: 1917
s32 Carry_Capacity(Entity* entity, Game_State* game_state);                                                                                                                                 // LINE: 1924
s32 Exp_Reward(Entity* entity);                                                                                                                                                             // LINE: 1944
s32 Carrying_Amount(Entity* entity, Game_State* game_state);                                                                                                                                // LINE: 1957
Critical_Ranges_Result Critical_Ranges(Entity* entity, Game_State* game_state, u32* out_success_effecting_count = 0, u32* out_failure_effecing_count = 0);                                  // LINE: 1970
void Full_Heal(Entity* entity, Game_State* game_state);                                                                                                                                     // LINE: 2012
bool Is_Item(Entity* entity);                                                                                                                                                               // LINE: 2018
bool Is_Alive(Entity* entity);                                                                                                                                                              // LINE: 2025
bool Is_Hostile_Against(Entity* A, Entity* B);                                                                                                                                              // LINE: 2032
bool Is_Living_Enemy_Of(Entity* actor, Entity* target);                                                                                                                                     // LINE: 2039
s32 Give_Temporary_Health(Entity* entity, s32 amount, String source_name, Verbose::T verbose, Game_State* game_state);                                                                      // LINE: 2046
Healing_Result Heal(Entity* entity, s32 amount, String source_name, Verbose::T verbose, Game_State* game_state);                                                                            // LINE: 2067
Deal_Damage_Result Deal_Damage(Entity* defender, Reference attacker, String source_name, s32 dmg, s32 pierce, Damage_Type type, Game_State* game_state, Verbose::T verbose);                // LINE: 2137
_inline Deal_Damage_Result Deal_Damage(Entity* defender, Entity* attacker, String dmg_src_name, s32 dmg, s32 pierce, Damage_Type type, Game_State* game_state, Verbose::T verbose);         // LINE: 2309
void Proc_Effects(u64 offset, Entity* attacker, Entity* defender, Attack_Record* ar, Game_State* game_state);                                                                               // LINE: 2317
void Proc_Effects(u64 offset, Entity* target, Game_State* game_state);                                                                                                                      // LINE: 2334
String Effect_Name(Effect_Instance* instance, Game_State* game_state);                                                                                                                      // LINE: 2350
u64 Count_Effect_Instances(Effects_Root* root, Effect_Instance cmp, Game_State* game_state, Effect_Instance** out_shortest_duration = 0);                                                   // LINE: 2370
void Delete_Effect_Slot(Effects_Root* root, Effects_Node* node, u64 *idx, u64* count, Game_State* game_state);                                                                              // LINE: 2400
Effect_Instance* New_Effect_Slot(Effects_Root* root, Game_State* game_state);                                                                                                               // LINE: 2440
Apply_Effect_Result Apply_Effect(Entity* target, Effect_Instance instance, Game_State* game_state);                                                                                         // LINE: 2486
void Remove_Effects_From_Source(Entity* actor, Entity* source, Game_State* game_state);                                                                                                     // LINE: 2543
u64 Remove_Effects_Of_Type(Entity* actor, Effect_Type::T type_to_remove, Game_State* game_state, Verbose::T verbose);                                                                       // LINE: 2568
void Inspect(Entity* target, Game_State* game_state);                                                                                                                                       // LINE: 2791
bool Is_Equipped(Entity* actor, Entity* item, Game_State* game_state);                                                                                                                      // LINE: 2835
bool Unequip(Entity* actor, Entity* item, Game_State* game_state);                                                                                                                          // LINE: 2858
bool Unequip(Entity* item, Game_State* game_state);                                                                                                                                         // LINE: 2882
bool Use(Entity* actor, Entity* item, Game_State* game_state, Verbose::T verbose);                                                                                                          // LINE: 2890
bool Equip(Entity* actor, Entity* target, Game_State* game_state, Verbose::T verbose = Verbose::T(0));                                                                                      // LINE: 2930
void Print_Uses(Entity* entity);                                                                                                                                                            // LINE: 3148
void Open(Entity* actor, Game_State* game_state);                                                                                                                                           // LINE: 3168
u64 Longest_Entity_Name_In_Actor_Storage(Entity* actor, Game_State* game_state, u64* out_count = 0);                                                                                        // LINE: 3194
u64 Longest_Entity_Name_In_Actor_Inventory(Entity* actor, Game_State* game_state, u64* out_count = 0, s16* out_heaviest_weight = 0);                                                        // LINE: 3219
bool Glance(Entity* actor, Game_State* game_state, Report_Turn_Taken_Status::T report_turn_taken_status = Report_Turn_Taken_Status::T(1));                                                  // LINE: 3246
void Remove_Random_Effect(Entity* entity, String source_name, Game_State* game_state);                                                                                                      // LINE: 3324
Damage_Modifiers_Result Damage_Modifier_From_Effects(Entity* attacker, Attack_Record* ar, Game_State* game_state);                                                                          // LINE: 3363
u64 Attack_Modifier_Mask(Attack_Mod::T modifier);                                                                                                                                           // LINE: 3457
u64 Class_Mask(Class::T _class);                                                                                                                                                            // LINE: 3464
bool Can_Use_Attack_Modifier(Entity* entity, Attack_Mod::T modifier);                                                                                                                       // LINE: 3471
void Apply_Or_Describe_Attak_Modifier(Entity** attacker_ptr, Entity** defender_ptr, Attack_Mod::T modifier, Game_State* game_state);                                                        // LINE: 3482
void Proc_Thorns(Entity* attacker, Entity* defender, Game_State* game_state);                                                                                                               // LINE: 3624
void Attack(Entity* attacker, Entity* defender, Game_State* game_state, Attack_Mod::T modifier = Attack_Mod::T(0));                                                                         // LINE: 3647
void Player_Action(Entity* actor, String actor_name, Game_State* game_state);                                                                                                               // LINE: 3724
Entity* Redirected_Target(Entity* actor, String actor_name, Game_State* game_state);                                                                                                        // LINE: 3809
Entity* Random_Entity_That_Matches_Criteria(Entity_Root_Node* storage, bool(*conditional)(Entity* entity, void* user_ptr, Game_State* game_state), void* user_ptr, Game_State* game_state); // LINE: 3847
Entity* Find_Attack_Target(Entity* actor, Game_State* game_state);                                                                                                                          // LINE: 3886
void NPC_Action(Entity* actor, String actor_name, Game_State* game_state);                                                                                                                  // LINE: 3915
void Take_Action(Entity* actor, Game_State* game_state);                                                                                                                                    // LINE: 3975
u64 Hash_From_Key(Effect_Hash_Key key);                                                                                                                                                     // LINE: 4047
bool Retrive_Effect(Effect_Hash_Key key, Effect_Offset* out, Game_State* game_state);                                                                                                       // LINE: 4054
Effect_Offset Insert_Effect(Effect effect, Effect_Hash_Key key, Game_State* game_state);                                                                                                    // LINE: 4092
void Generate_From_Loot_Table(Entity* storage, Loot_Table table, u64 count, Rarity_Mode mode, Rarity::T target_rarity_A, Rarity::T target_rarity_B, Game_State* game_state);                // LINE: 4130
Loot_Table Merge_Loot_Tables(Loot_Table A, Loot_Table B, Arena* arena);                                                                                                                     // LINE: 4202
Loot_Table Merge_Loot_Tables(Loot_Table A, Loot_Table B, Loot_Table C, Arena* arena);                                                                                                       // LINE: 4213
Loot_Table Merge_Loot_Tables(Loot_Table A, Loot_Table B, Loot_Table C, Loot_Table D, Arena* arena);                                                                                         // LINE: 4220
Loot_Table Merge_Loot_Tables(Loot_Table A, Loot_Table B, Loot_Table C, Loot_Table D, Loot_Table E, Arena* arena);                                                                           // LINE: 4227
Loot_Table Merge_Loot_Tables(Loot_Table A, Loot_Table B, Loot_Table C, Loot_Table D, Loot_Table E, Loot_Table F, Arena* arena);                                                             // LINE: 4234
void Fill_Loot_Table_Changes_And_Item_Rarity(Loot_Table* table, Game_State* game_state);                                                                                                    // LINE: 4241
bool Roll_Initiative(Entity* entity, Game_State* game_state);                                                                                                                               // LINE: 4315
void Sort_Iniative_Order(Reference* refs, Game_State* game_state);                                                                                                                          // LINE: 4349
void Sort_Space(Entity_Root_Node* space, Game_State* game_state);                                                                                                                           // LINE: 4481
u64 Count_Longest_Round_Effect_Duration(Entity* actor, Game_State* game_state);                                                                                                             // LINE: 4557
void Tick_Down_Effect_Durations(Entity* actor, Duration_Type type, Game_State* game_state);                                                                                                 // LINE: 4572
_inline void Enter_A_Room_Printout(Entity* player, Entity* room, Game_State* game_state);                                                                                                   // LINE: 4646
Room_Generator_Element Pick_Room_Generator(Room_Generator_Element_Array array, u32 selector, Game_State* game_state);                                                                       // LINE: 4669
Room_Generator_Element Pick_Room_Generator(Room_Generator_Element_Array array, Game_State* game_state);                                                                                     // LINE: 4690
void Prompt_User_For_Command_And_Attempt_To_Execute(Command* commands, u64 count, void* user_ptr, Game_State* game_state);                                                                  // LINE: 4704
void Create_Player_Charater(Game_State* game_state);                                                                                                                                        // LINE: 4798
void Tick_Active_Effects_Down_To_Zero(Entity* actor, Game_State* game_state);                                                                                                               // LINE: 4889
Entity* Proceed_To_Next_Room(Game_State* game_state);                                                                                                                                       // LINE: 4914
void Prepare_Game_Round(Game_State* game_state);                                                                                                                                            // LINE: 4984
void Excecute_Game_Round(Game_State* game_state);                                                                                                                                           // LINE: 5098
void Exit_Handling(Game_State* game_state);                                                                                                                                                 // LINE: 5136
bool Play_Game(Game_State* game_state);                                                                                                                                                     // LINE: 5168
void Reset_Game_State(Game_State* game_state);                                                                                                                                              // LINE: 5199
Game_State* Create_Game_State();                                                                                                                                                            // LINE: 5254
CMD_Result::T Kill_Command(Entity* actor, String args, Game_State* game_state);                                                                                                             // LINE: 5285
CMD_Result::T Toggle_Dramatic_Pause(Entity* actor, String args, Game_State* game_state);                                                                                                    // LINE: 5312
CMD_Result::T Toggle_Godmode(Entity* actor, String args, Game_State* game_state);                                                                                                           // LINE: 5336
CMD_Result::T Help_Command(Entity* entity, String args, Game_State* game_state);                                                                                                            // LINE: 5355
CMD_Result::T Attacks_Command(Entity* entity, String args, Game_State* game_state);                                                                                                         // LINE: 5395
CMD_Result::T Pickup_Command(Entity* actor, String args, Game_State* game_state);                                                                                                           // LINE: 5448
CMD_Result::T Inventory_Command(Entity* actor, String args, Game_State* game_state);                                                                                                        // LINE: 5497
CMD_Result::T Proceed_Command(Entity* actor, String args, Game_State* game_state);                                                                                                          // LINE: 5576
CMD_Result::T Equipment_Command(Entity* actor, String args, Game_State* game_state);                                                                                                        // LINE: 5673
CMD_Result::T Drop_Command(Entity* actor, String args, Game_State* game_state);                                                                                                             // LINE: 5708
CMD_Result::T Use_Command(Entity* actor, String args, Game_State* game_state);                                                                                                              // LINE: 5738
CMD_Result::T Equip_Command(Entity* actor, String args, Game_State* game_state);                                                                                                            // LINE: 5762
CMD_Result::T Unequip_Command(Entity* actor, String args, Game_State* game_state);                                                                                                          // LINE: 5785
CMD_Result::T Stats_Command(Entity* actor, String args, Game_State* game_state);                                                                                                            // LINE: 5814
CMD_Result::T Status_Command(Entity* actor, String args, Game_State* game_state);                                                                                                           // LINE: 5929
CMD_Result::T Inspect_Command(Entity* actor, String args, Game_State* game_state);                                                                                                          // LINE: 5983
CMD_Result::T Pass_Command(Entity* actor, String args, Game_State* game_state);                                                                                                             // LINE: 6025
CMD_Result::T Glance_Command(Entity* actor, String args, Game_State* game_state);                                                                                                           // LINE: 6041
CMD_Result::T Restart_Command(Entity* actor, String args, Game_State* game_state);                                                                                                          // LINE: 6065
CMD_Result::T Save_Command(Entity* actor, String args, Game_State* game_state);                                                                                                             // LINE: 6100
CMD_Result::T Load_Command(Entity* actor, String args, Game_State* game_state);                                                                                                             // LINE: 6126
CMD_Result::T Exit_Command(Entity* actor, String args, Game_State* game_state);                                                                                                             // LINE: 6152
CMD_Result::T Loot_Command(Entity* actor, String args, Game_State* game_state);                                                                                                             // LINE: 6190
CMD_Result::T Attack_Command(Entity* actor, String args, Game_State* game_state);                                                                                                           // LINE: 6246
CMD_Result::T Set_Seed_Command(Entity* actor, String args, Game_State* game_state);                                                                                                         // LINE: 6309
void Get_Character_Creator_Commands(Game_State* game_state, Command** out_commands, u64* out_count);                                                                                        // LINE: 6339
