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
struct U64_To_String_Memory;                                                                                                                                                                // LINE: 413

// FILE: src\LibPrimordial\Arena.cpp:
struct Arena;                                                                                                                                                                               // LINE: 9
struct Arena_Snapshot;                                                                                                                                                                      // LINE: 19
enum class Zero_Memory : u8;                                                                                                                                                                // LINE: 25
struct String_Builder;                                                                                                                                                                      // LINE: 137

// FILE: src\Generated_Offsets.h:
struct GENERATE_ENTITY_FN_Offset;                                                                                                                                                           // LINE: 10
struct PROTOTYPE_ENT_GS_Offset;                                                                                                                                                             // LINE: 15
struct PROTOTYPE_ENT_ENT_GS_Offset;                                                                                                                                                         // LINE: 20
struct PROTOTYPE_EFFINST_ENT_GS_Offset;                                                                                                                                                     // LINE: 25
struct PROTOTYPE_EFFINST_ENT_ENT_GS_Offset;                                                                                                                                                 // LINE: 30
struct PROTOTYPE_EFFINST_ENT_ENT_AR_GS_Offset;                                                                                                                                              // LINE: 35
struct PROTOTYPE_EFFINST_ENTOFF_ENT_DDR_GS_Offset;                                                                                                                                          // LINE: 40
struct PROTOTYPE_EFFINST_ENT_S32PTR_STR_GS_Offset;                                                                                                                                          // LINE: 45
struct PROTOTYPE_EFFINST_ENT_STAT_S32PTR_S16PTR_GS_Offset;                                                                                                                                  // LINE: 50

// FILE: src\Stats.cpp:
namespace Stats
{
    enum T;                                                                                                                                                                                 // LINE: 20
}


// FILE: src\Dungeon.h:
struct ANSI_Color_Buffer;                                                                                                                                                                   // LINE: 23
struct Effect_Offset;                                                                                                                                                                       // LINE: 82
struct Effects_Node_Offset;                                                                                                                                                                 // LINE: 89
struct Entity_Node_Offset;                                                                                                                                                                  // LINE: 101
enum class Storage : u8;                                                                                                                                                                    // LINE: 107
struct String_Offset;                                                                                                                                                                       // LINE: 114
struct String_Wrapper;                                                                                                                                                                      // LINE: 130
struct String_Table;                                                                                                                                                                        // LINE: 137
struct String_Table_Root;                                                                                                                                                                   // LINE: 145
struct Entity_Offset;                                                                                                                                                                       // LINE: 152
struct Entity_Node;                                                                                                                                                                         // LINE: 159
struct Entity_Root_Node;                                                                                                                                                                    // LINE: 166
struct Dice;                                                                                                                                                                                // LINE: 211
struct Bonus_Dice;                                                                                                                                                                          // LINE: 218
struct Effect_Hash_Key;                                                                                                                                                                     // LINE: 235
struct Effect;                                                                                                                                                                              // LINE: 248
enum class Apply_Effect_Result : u8;                                                                                                                                                        // LINE: 319
enum class Duration_Type : u8;                                                                                                                                                              // LINE: 332
struct Effect_Instance;                                                                                                                                                                     // LINE: 405
struct Effects_Node;                                                                                                                                                                        // LINE: 447
struct Effects_Root;                                                                                                                                                                        // LINE: 458
struct Roll_Result;                                                                                                                                                                         // LINE: 466
struct Initiative;                                                                                                                                                                          // LINE: 476
enum class Cooldown_Type : u8;                                                                                                                                                              // LINE: 484
struct Interactable;                                                                                                                                                                        // LINE: 492
enum class Faction : u8;                                                                                                                                                                    // LINE: 506
struct Entity;                                                                                                                                                                              // LINE: 523
struct Leveler;                                                                                                                                                                             // LINE: 575
struct Damage_Modifiers_Result;                                                                                                                                                             // LINE: 585
struct Damage_Modifier;                                                                                                                                                                     // LINE: 592
struct Healing_Result;                                                                                                                                                                      // LINE: 604
struct Deal_Damage_Result;                                                                                                                                                                  // LINE: 617
enum class Damage_Type;                                                                                                                                                                     // LINE: 631
struct Critical_Ranges_Result;                                                                                                                                                              // LINE: 638
struct Message_Pipe;                                                                                                                                                                        // LINE: 645
struct Apply_Check_Record;                                                                                                                                                                  // LINE: 652
struct Attack_Record;                                                                                                                                                                       // LINE: 661
struct Entity_Iterator;                                                                                                                                                                     // LINE: 744
struct Backwards_Iterator;                                                                                                                                                                  // LINE: 759
struct Ambush_Creature_Spawner_Offset;                                                                                                                                                      // LINE: 769
struct Ambush_Option_Offset;                                                                                                                                                                // LINE: 775
struct Ambush_Creature_Spawner;                                                                                                                                                             // LINE: 781
struct Ambush_Option;                                                                                                                                                                       // LINE: 790
struct Ambush_Table;                                                                                                                                                                        // LINE: 798
struct Effects_Iterator;                                                                                                                                                                    // LINE: 806
struct Effect_Hash_Table_Entry;                                                                                                                                                             // LINE: 818
struct Effect_Hash_Table;                                                                                                                                                                   // LINE: 825
struct Game_State;                                                                                                                                                                          // LINE: 834
struct Character_Creator;                                                                                                                                                                   // LINE: 895
struct Loot_Table_Entry;                                                                                                                                                                    // LINE: 904
struct Loot_Table_Pick_Result;                                                                                                                                                              // LINE: 915
struct Loot_Table;                                                                                                                                                                          // LINE: 922
struct Pick_From_Table_Rules;                                                                                                                                                               // LINE: 931
struct Rules_Builder;                                                                                                                                                                       // LINE: 945
enum class Comparison : u8;                                                                                                                                                                 // LINE: 994
struct Level_Segment;                                                                                                                                                                       // LINE: 1003
struct Level_Segments;                                                                                                                                                                      // LINE: 1010
struct Room_Generator_Element;                                                                                                                                                              // LINE: 1017
struct Room_Generator_Element_Array;                                                                                                                                                        // LINE: 1024
struct Game_Command;                                                                                                                                                                        // LINE: 1113
enum class Call_Style;                                                                                                                                                                      // LINE: 1124
struct Command;                                                                                                                                                                             // LINE: 1132
typedef void PROTOTYPE_ENT_GS(Entity*, Game_State*);;                                                                                                                                       // LINE: 1245
typedef void PROTOTYPE_ENT_ENT_GS(Entity*, Entity*, Game_State*);;                                                                                                                          // LINE: 1246
typedef void PROTOTYPE_EFFINST_ENT_GS(Effect_Instance*, Entity*, Game_State*);;                                                                                                             // LINE: 1247
typedef void PROTOTYPE_EFFINST_ENT_ENT_GS(Effect_Instance*, Entity*, Entity*, Game_State*);;                                                                                                // LINE: 1248
typedef void PROTOTYPE_EFFINST_ENT_ENT_AR_GS(Effect_Instance*, Entity*, Entity*, Attack_Record*, Game_State*);;                                                                             // LINE: 1249
typedef void PROTOTYPE_EFFINST_ENTOFF_ENT_DDR_GS(Effect_Instance*, Entity_Offset, Entity*, Deal_Damage_Result*, Game_State*);;                                                              // LINE: 1250
typedef void PROTOTYPE_EFFINST_ENT_S32PTR_STR_GS(Effect_Instance*, Entity*, s32*, String, Game_State*);;                                                                                    // LINE: 1251
typedef void PROTOTYPE_EFFINST_ENT_STAT_S32PTR_S16PTR_GS(Effect_Instance*, Entity*, Stats::T, s32*, s16*, Game_State*);;                                                                    // LINE: 1252
typedef Entity* GENERATE_ENTITY_FN(Entity*, Game_State*);;                                                                                                                                  // LINE: 1254
namespace AT
{
    enum T : u8;                                                                                                                                                                            // LINE: 31
}

namespace Rarity
{
    enum T : u8;                                                                                                                                                                            // LINE: 44
}

namespace EFlags
{
    enum T : u64;                                                                                                                                                                           // LINE: 58
}

namespace Equipment_Slots
{
    enum T : u32;                                                                                                                                                                           // LINE: 191
}

namespace Effect_Flags
{
    enum T : s8;                                                                                                                                                                            // LINE: 227
}

namespace Effect_Type
{
    enum T : u8;                                                                                                                                                                            // LINE: 304
}

namespace Food_Quality
{
    enum T : u8;                                                                                                                                                                            // LINE: 355
}

namespace Class
{
    enum T : u8;                                                                                                                                                                            // LINE: 383
}

namespace Roll_Print_Style
{
    enum T;                                                                                                                                                                                 // LINE: 693
}

namespace Report_Turn_Taken_Status
{
    enum T : u8;                                                                                                                                                                            // LINE: 706
}

namespace Verbose
{
    enum T : u8;                                                                                                                                                                            // LINE: 716
}

namespace Forced
{
    enum T : u8;                                                                                                                                                                            // LINE: 726
}

namespace Assign_Dublicate_Identifier
{
    enum T : u8;                                                                                                                                                                            // LINE: 736
}

namespace Attack_Mod
{
    enum T;                                                                                                                                                                                 // LINE: 1084
}

namespace CMD_Result
{
    enum T : u8;                                                                                                                                                                            // LINE: 1103
}


// FILE: src\Dungeon.cpp:
enum class Custom_Start;                                                                                                                                                                    // LINE: 32
struct On_Get_Stat_Value_Storage;                                                                                                                                                           // LINE: 2282


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
constexpr u64 Kilobytes(u64 v);                                                                                                                                                             // LINE: 11
constexpr u64 Megabytes(u64 v);                                                                                                                                                             // LINE: 18
constexpr u64 Gigabytes(u64 v);                                                                                                                                                             // LINE: 26
void Mem_Zero(void* ptr, u64 count);                                                                                                                                                        // LINE: 34
void Mem_Copy(void* dest, void* src, u64 count);                                                                                                                                            // LINE: 46
u64 Weld(u32 a, u32 b);                                                                                                                                                                     // LINE: 55

// FILE: src\LibPrimordial\Maths.cpp:
f32 Square_Root(f32 v);                                                                                                                                                                     // LINE: 32
u32 Random_PCG(u32 seed);                                                                                                                                                                   // LINE: 69
u32 Random_PCG(u32* pcg_state);                                                                                                                                                             // LINE: 77
f32 Fraction(f32 v);                                                                                                                                                                        // LINE: 88
s32 Round_To_S32(f32 v);                                                                                                                                                                    // LINE: 97
f32 Round(f32 v);                                                                                                                                                                           // LINE: 107
f32 Round_Up(f32 v);                                                                                                                                                                        // LINE: 115
s32 Digits(s32 v, s32 base = 10);                                                                                                                                                           // LINE: 128
s16 Inv(s16 v);                                                                                                                                                                             // LINE: 147

// FILE: src\LibPrimordial\String.cpp:
u64 Null_Terminated_Length(char* buffer);                                                                                                                                                   // LINE: 17
String To_String(char* cstr);                                                                                                                                                               // LINE: 26
char Last(String str);                                                                                                                                                                      // LINE: 34
char First(String str);                                                                                                                                                                     // LINE: 41
char At(String str, u64 idx);                                                                                                                                                               // LINE: 48
bool Is_Uppercase_Letter(char c);                                                                                                                                                           // LINE: 60
bool Is_Lowercase_Letter(char c);                                                                                                                                                           // LINE: 66
char To_Lowercase(char c);                                                                                                                                                                  // LINE: 73
char To_Uppercase(char c);                                                                                                                                                                  // LINE: 84
bool Is_Whitespace(char c);                                                                                                                                                                 // LINE: 95
bool Seek(String str, char c, u64* output);                                                                                                                                                 // LINE: 119
bool Seek(String str, bool(*check_fn)(char), u64* output);                                                                                                                                  // LINE: 140
u64 Line_Length(String str);                                                                                                                                                                // LINE: 162
String Forward(String str, u64 step);                                                                                                                                                       // LINE: 170
String Forward(String str, String step);                                                                                                                                                    // LINE: 179
bool Is_Integer(char c);                                                                                                                                                                    // LINE: 186
bool Not_Integer(char c);                                                                                                                                                                   // LINE: 193
String Skip_Zeroes(String str);                                                                                                                                                             // LINE: 200
bool Is_Positive_Integer(String str);                                                                                                                                                       // LINE: 209
String Skip_While_True(String str, bool(*compare_fn)(char c));                                                                                                                              // LINE: 225
String Skip_Whitespace(String str);                                                                                                                                                         // LINE: 234
String Skip_Spaces_And_Tabs(String str);                                                                                                                                                    // LINE: 243
bool Match_Case_Insensitive(String str, String comp);                                                                                                                                       // LINE: 252
bool Match_Case_Sensitive(String str, String comp);                                                                                                                                         // LINE: 279
bool Match_Beginning_Case_Insensitive(String str, String comp);                                                                                                                             // LINE: 307
bool Match_Beginning_Case_Sensitive(String str, String comp);                                                                                                                               // LINE: 335
u64 To_U64(String str);                                                                                                                                                                     // LINE: 387
String To_String(u64 integer, U64_To_String_Memory* output);                                                                                                                                // LINE: 419

// FILE: src\LibPrimordial\Arena.cpp:
void Initialize_Arena(Arena* arena, u64 reserve_byte_count = Gigabytes(64), u64 pages_per_commit = 16);                                                                                     // LINE: 36
Arena Create_Arena(u64 reserve_byte_count = Gigabytes(64), u64 pages_per_commit = 16);                                                                                                      // LINE: 54
void Clear(Arena* arena, Zero_Memory zero_memory);                                                                                                                                          // LINE: 63
void* Push(Arena* arena, u64 size);                                                                                                                                                         // LINE: 74
char* Push_String(Arena* arena, String str, u64* out_length);                                                                                                                               // LINE: 118
char* Push_String(Arena* arena, String str);                                                                                                                                                // LINE: 128
Arena_Snapshot Snapshot(Arena* arena);                                                                                                                                                      // LINE: 172
void Restore(Arena* arena, Arena_Snapshot snapshot);                                                                                                                                        // LINE: 179
bool Is_Taken(Arena_Snapshot snapshot);                                                                                                                                                     // LINE: 186
String To_String(Arena* arena);                                                                                                                                                             // LINE: 193
String Merge(String A, String B, Arena* arena);                                                                                                                                             // LINE: 200

// FILE: src\LibPrimordial\Win32.cpp:
f64 OS_Time();                                                                                                                                                                              // LINE: 17
void OS_Sleep(f64 seconds);                                                                                                                                                                 // LINE: 27
String OS_Read_File(String path, Arena* arena);                                                                                                                                             // LINE: 37
bool OS_Write_File(String buffer, String path, Arena* arena);                                                                                                                               // LINE: 111
void* OS_Get_Executable_Base_Address();                                                                                                                                                     // LINE: 173
u64 OS_Get_Executable_Size();                                                                                                                                                               // LINE: 180

// FILE: src\Generated_Offsets.cpp:
_inline GENERATE_ENTITY_FN_Offset Offset(GENERATE_ENTITY_FN* pointer, Game_State* game_state);                                                                                              // LINE: 11
_inline GENERATE_ENTITY_FN* Pointer(GENERATE_ENTITY_FN_Offset offset, Game_State* game_state);                                                                                              // LINE: 22
_inline PROTOTYPE_ENT_GS_Offset Offset(PROTOTYPE_ENT_GS* pointer, Game_State* game_state);                                                                                                  // LINE: 34
_inline PROTOTYPE_ENT_GS* Pointer(PROTOTYPE_ENT_GS_Offset offset, Game_State* game_state);                                                                                                  // LINE: 45
_inline PROTOTYPE_ENT_ENT_GS_Offset Offset(PROTOTYPE_ENT_ENT_GS* pointer, Game_State* game_state);                                                                                          // LINE: 57
_inline PROTOTYPE_ENT_ENT_GS* Pointer(PROTOTYPE_ENT_ENT_GS_Offset offset, Game_State* game_state);                                                                                          // LINE: 68
_inline PROTOTYPE_EFFINST_ENT_GS_Offset Offset(PROTOTYPE_EFFINST_ENT_GS* pointer, Game_State* game_state);                                                                                  // LINE: 80
_inline PROTOTYPE_EFFINST_ENT_GS* Pointer(PROTOTYPE_EFFINST_ENT_GS_Offset offset, Game_State* game_state);                                                                                  // LINE: 91
_inline PROTOTYPE_EFFINST_ENT_ENT_GS_Offset Offset(PROTOTYPE_EFFINST_ENT_ENT_GS* pointer, Game_State* game_state);                                                                          // LINE: 103
_inline PROTOTYPE_EFFINST_ENT_ENT_GS* Pointer(PROTOTYPE_EFFINST_ENT_ENT_GS_Offset offset, Game_State* game_state);                                                                          // LINE: 114
_inline PROTOTYPE_EFFINST_ENT_ENT_AR_GS_Offset Offset(PROTOTYPE_EFFINST_ENT_ENT_AR_GS* pointer, Game_State* game_state);                                                                    // LINE: 126
_inline PROTOTYPE_EFFINST_ENT_ENT_AR_GS* Pointer(PROTOTYPE_EFFINST_ENT_ENT_AR_GS_Offset offset, Game_State* game_state);                                                                    // LINE: 137
_inline PROTOTYPE_EFFINST_ENTOFF_ENT_DDR_GS_Offset Offset(PROTOTYPE_EFFINST_ENTOFF_ENT_DDR_GS* pointer, Game_State* game_state);                                                            // LINE: 149
_inline PROTOTYPE_EFFINST_ENTOFF_ENT_DDR_GS* Pointer(PROTOTYPE_EFFINST_ENTOFF_ENT_DDR_GS_Offset offset, Game_State* game_state);                                                            // LINE: 160
_inline PROTOTYPE_EFFINST_ENT_S32PTR_STR_GS_Offset Offset(PROTOTYPE_EFFINST_ENT_S32PTR_STR_GS* pointer, Game_State* game_state);                                                            // LINE: 172
_inline PROTOTYPE_EFFINST_ENT_S32PTR_STR_GS* Pointer(PROTOTYPE_EFFINST_ENT_S32PTR_STR_GS_Offset offset, Game_State* game_state);                                                            // LINE: 183
_inline PROTOTYPE_EFFINST_ENT_STAT_S32PTR_S16PTR_GS_Offset Offset(PROTOTYPE_EFFINST_ENT_STAT_S32PTR_S16PTR_GS* pointer, Game_State* game_state);                                            // LINE: 195
_inline PROTOTYPE_EFFINST_ENT_STAT_S32PTR_S16PTR_GS* Pointer(PROTOTYPE_EFFINST_ENT_STAT_S32PTR_S16PTR_GS_Offset offset, Game_State* game_state);                                            // LINE: 206

// FILE: src\Effects.cpp:
Effect_Offset Get_Critical_Effect_Offset(Game_State* game_state);                                                                                                                           // LINE: 13
Effect_Offset Get_Might_Effect_Offset(Game_State* game_state);                                                                                                                              // LINE: 28
void Pack_Hunt_On_Turn_Start(Effect_Instance* instance, Entity* target, Game_State* game_state);                                                                                            // LINE: 43
void Survival_Instinct_On_Turn_Start(Effect_Instance* instance, Entity* target, Game_State* game_state);                                                                                    // LINE: 99
void Strength_Of_Earth_Small_On_Turn_Start(Effect_Instance* instance, Entity* target, Game_State* game_state);                                                                              // LINE: 143
void Strength_Of_Earth_Tiny_On_Turn_Start(Effect_Instance* instance, Entity* target, Game_State* game_state);                                                                               // LINE: 169
void Dissapate_After_Two_On_Turn_Start(Effect_Instance* instance, Entity* target, Game_State* game_state);                                                                                  // LINE: 195
Effect_Offset Get_Enraged_Effect_Offset(Game_State* game_state);                                                                                                                            // LINE: 220
Effect_Instance Get_Enraged(Entity* source, Game_State* game_state);                                                                                                                        // LINE: 293
Effect_Offset Get_Vampirism_Effect_Offset(Game_State* game_state);                                                                                                                          // LINE: 305
Effect_Instance Get_Poison(u64 duration, Entity* source, Game_State* game_state);                                                                                                           // LINE: 364
Effect_Offset Get_Burning_Effect_Offset(Game_State* game_state);                                                                                                                            // LINE: 403
Effect_Instance Get_Festering_Rash(u64 duration, Entity* source, Game_State* game_state);                                                                                                   // LINE: 438
Effect_Instance Get_Weakening_Blight(u64 duration, Entity* source, Game_State* game_state);                                                                                                 // LINE: 469
Effect_Instance Get_Neuro_Toxin(u64 duration, Entity* source, Game_State* game_state);                                                                                                      // LINE: 492
Effect_Instance Get_Leech(u64 duration, Entity* source, Game_State* game_state);                                                                                                            // LINE: 514
Effect_Instance Get_Filled_With_Blood(u64 duration, Entity* source, Game_State* game_state);                                                                                                // LINE: 570
Effect_Instance Get_Malaria(u64 duration, Entity* source, Game_State* game_state);                                                                                                          // LINE: 613
Effect_Instance Get_Devouring_Plague(u64 duration, Entity* source, Game_State* game_state);                                                                                                 // LINE: 636
Effect_Instance Get_Entangled(u64 duration, Entity* source, Game_State* game_state);                                                                                                        // LINE: 674
Effect_Offset Get_Seed_Effect_Offset(Game_State* game_state);                                                                                                                               // LINE: 699
Effect_Instance Get_Seed(Entity* source, Game_State* game_state);                                                                                                                           // LINE: 775
Effect_Offset Get_Weak_Grip_Offset(Game_State* game_state);                                                                                                                                 // LINE: 794
void Stun_Attacker(Effect_Instance* instance, Entity* attacker, Entity* defender, Attack_Record* ar, Game_State* game_state);                                                               // LINE: 847
Effect_Instance Reckless_Attack(Entity* attacker, Game_State* game_state);                                                                                                                  // LINE: 868
Effect_Instance Careful_Attack(Entity* attacker, Game_State* game_state);                                                                                                                   // LINE: 895
Effect_Instance Weakspot_Attack(Entity* attacker, Game_State* game_state);                                                                                                                  // LINE: 925
Effect_Instance Allin_Attack(Entity* attacker, Game_State* game_state);                                                                                                                     // LINE: 952
Effect_Instance Guarding_Attack(Entity* attacker, Game_State* game_state);                                                                                                                  // LINE: 982
Effect_Instance Evasive_Attack(Entity* attacker, Game_State* game_state);                                                                                                                   // LINE: 1009
Effect_Instance Execute_Attack(Entity* attacker, Game_State* game_state);                                                                                                                   // LINE: 1036
Effect_Instance Disarming_Attack(Entity* attacker, Game_State* game_state);                                                                                                                 // LINE: 1101
Effect_Instance Vampiric_Attack(Entity* attacker, Game_State* game_state);                                                                                                                  // LINE: 1173
Effect_Instance Blessed_Attack(Entity* attacker, Game_State* game_state);                                                                                                                   // LINE: 1230
Effect_Instance Berserking_Attack(Entity* attacker, Game_State* game_state);                                                                                                                // LINE: 1304
Effect_Instance Redirect_Attack(Entity* attacker, Game_State* game_state);                                                                                                                  // LINE: 1377
Effect_Instance Change_Attack(Entity* attacker, Game_State* game_state);                                                                                                                    // LINE: 1429
Effect_Instance Thieving_Attack(Entity* attacker, Game_State* game_state);                                                                                                                  // LINE: 1523
Effect_Instance Stylish_Attack(Entity* attacker, Game_State* game_state);                                                                                                                   // LINE: 1618

// FILE: src\Skill_Books.cpp:
Entity* Manual_Of_Reckless_Attack(Entity* container, Game_State* game_state);                                                                                                               // LINE: 10
Entity* Manual_Of_Careful_Attack(Entity* container, Game_State* game_state);                                                                                                                // LINE: 48
Entity* Manual_Of_Weakspot_Attack(Entity* container, Game_State* game_state);                                                                                                               // LINE: 86
Entity* Manual_Of_Allin_Attack(Entity* container, Game_State* game_state);                                                                                                                  // LINE: 124
Entity* Manual_Of_Disarming_Attack(Entity* container, Game_State* game_state);                                                                                                              // LINE: 162
Entity* Manual_Of_Guarding_Attack(Entity* container, Game_State* game_state);                                                                                                               // LINE: 200
Entity* Manual_Of_Evasive_Attack(Entity* container, Game_State* game_state);                                                                                                                // LINE: 238
Entity* Manual_Of_Vampiric_Attack(Entity* container, Game_State* game_state);                                                                                                               // LINE: 276
Entity* Manual_Of_Blessed_Attack(Entity* container, Game_State* game_state);                                                                                                                // LINE: 314
Entity* Manual_Of_Berserking_Attack(Entity* container, Game_State* game_state);                                                                                                             // LINE: 352
Entity* Manual_Of_Execute_Attack(Entity* container, Game_State* game_state);                                                                                                                // LINE: 390
Entity* Manual_Of_Redirect_Attack(Entity* container, Game_State* game_state);                                                                                                               // LINE: 428
Entity* Manual_Of_Change_Attack(Entity* container, Game_State* game_state);                                                                                                                 // LINE: 466
Entity* Manual_Of_Cleansing_Attack(Entity* container, Game_State* game_state);                                                                                                              // LINE: 504
Entity* Manual_Of_Thieving_Attack(Entity* container, Game_State* game_state);                                                                                                               // LINE: 542
Loot_Table Skill_Books_Loot_Table(Game_State* game_state);                                                                                                                                  // LINE: 580

// FILE: src\Items.cpp:
Loot_Table Basic_Foods_Loot_Table(Game_State* game_state);                                                                                                                                  // LINE: 22
Loot_Table Basic_Consumables_Loot_Table(Game_State* game_state);                                                                                                                            // LINE: 40
Loot_Table Basic_Trinkets_Loot_Table(Game_State* game_state);                                                                                                                               // LINE: 70
Loot_Table Basic_Armors_Loot_Table(Game_State* game_state);                                                                                                                                 // LINE: 112
Loot_Table Basic_Weapons_Loot_Table(Game_State* game_state);                                                                                                                                // LINE: 202
void Spawn_All_Items_In_Loot_Table(Loot_Table table, Entity* room, Game_State* game_state);                                                                                                 // LINE: 240
Loot_Table Basic_Merged_Loot_Table(Game_State* game_state);                                                                                                                                 // LINE: 249
Entity* Create_Great_Sword(Entity* room, Game_State* game_state);                                                                                                                           // LINE: 270
Entity* Create_Halberd(Entity* room, Game_State* game_state);                                                                                                                               // LINE: 302
Entity* Create_Long_Spear(Entity* room, Game_State* game_state);                                                                                                                            // LINE: 335
Entity* Create_Cestus(Entity* room, Game_State* game_state);                                                                                                                                // LINE: 368
Entity* Create_War_Staff(Entity* room, Game_State* game_state);                                                                                                                             // LINE: 398
Entity* Create_Assassins_Claws(Entity* room, Game_State* game_state);                                                                                                                       // LINE: 431
Entity* Create_Staff(Entity* room, Game_State* game_state);                                                                                                                                 // LINE: 466
Entity* Create_Ram_Shield(Entity* room, Game_State* game_state);                                                                                                                            // LINE: 495
Entity* Create_Battle_Axe(Entity* room, Game_State* game_state);                                                                                                                            // LINE: 526
Entity* Create_Great_Axe(Entity* room, Game_State* game_state);                                                                                                                             // LINE: 554
Entity* Create_Gardening_Scythe(Entity* room, Game_State* game_state);                                                                                                                      // LINE: 588
Entity* Create_War_Scythe(Entity* room, Game_State* game_state);                                                                                                                            // LINE: 619
Entity* Create_Great_Club(Entity* room, Game_State* game_state);                                                                                                                            // LINE: 655
Entity* Create_Magma_Hammer(Entity* room, Game_State* game_state);                                                                                                                          // LINE: 688
Entity* Create_War_Pick(Entity* room, Game_State* game_state);                                                                                                                              // LINE: 756
Entity* Create_Straightsword(Entity* room, Game_State* game_state);                                                                                                                         // LINE: 785
Entity* Create_Whip(Entity* room, Game_State* game_state);                                                                                                                                  // LINE: 812
Entity* Create_Club(Entity* room, Game_State* game_state);                                                                                                                                  // LINE: 842
Entity* Create_Mace(Entity* room, Game_State* game_state);                                                                                                                                  // LINE: 869
Entity* Create_Rapier(Entity* room, Game_State* game_state);                                                                                                                                // LINE: 897
Entity* Create_Short_Spear(Entity* room, Game_State* game_state);                                                                                                                           // LINE: 929
Entity* Create_Morning_Star(Entity* room, Game_State* game_state);                                                                                                                          // LINE: 958
Entity* Create_Three_Headed_Flail(Entity* room, Game_State* game_state);                                                                                                                    // LINE: 988
Entity* Create_Dagger(Entity* room, Game_State* game_state);                                                                                                                                // LINE: 1019
Entity* Create_Poison_Dagger(Entity* room, Game_State* game_state);                                                                                                                         // LINE: 1049
Entity* Create_Cape_Of_Immunity(Entity* room, Game_State* game_state);                                                                                                                      // LINE: 1102
Entity* Create_Healers_Cape(Entity* room, Game_State* game_state);                                                                                                                          // LINE: 1128
Entity* Create_Arcane_Cape(Entity* room, Game_State* game_state);                                                                                                                           // LINE: 1154
Entity* Create_Belt(Entity* room, Game_State* game_state);                                                                                                                                  // LINE: 1180
Entity* Create_Plate_Codpiece(Entity* room, Game_State* game_state);                                                                                                                        // LINE: 1206
Entity* Create_Chastity_Belt(Entity* room, Game_State* game_state);                                                                                                                         // LINE: 1232
Entity* Create_Strong_Man_Belt(Entity* room, Game_State* game_state);                                                                                                                       // LINE: 1258
Entity* Create_Belt_Of_Atlas(Entity* room, Game_State* game_state);                                                                                                                         // LINE: 1285
Entity* Create_Cape_Of_Spite(Entity* room, Game_State* game_state);                                                                                                                         // LINE: 1313
Entity* Create_Cape_Of_Avoidance(Entity* room, Game_State* game_state);                                                                                                                     // LINE: 1339
Entity* Create_Cape_Of_Dashing(Entity* room, Game_State* game_state);                                                                                                                       // LINE: 1365
Entity* Create_Backpack(Entity* room, Game_State* game_state);                                                                                                                              // LINE: 1391
Entity* Create_Ring_Of_Giants(Entity* room, Game_State* game_state);                                                                                                                        // LINE: 1420
Entity* Create_Ring_Of_Bloodshield(Entity* room, Game_State* game_state);                                                                                                                   // LINE: 1448
Entity* Create_Ring_Of_Clumsy_Regeneration(Entity* room, Game_State* game_state);                                                                                                           // LINE: 1492
Entity* Create_Ring_Of_Survival_Instinct(Entity* room, Game_State* game_state);                                                                                                             // LINE: 1536
Entity* Create_Avengers_Rings(Entity* room, Game_State* game_state);                                                                                                                        // LINE: 1561
Entity* Create_Cowards_Ring(Entity* room, Game_State* game_state);                                                                                                                          // LINE: 1586
Entity* Create_Demon_Brand(Entity* room, Game_State* game_state);                                                                                                                           // LINE: 1612
Entity* Create_Ring_Of_Quickening(Entity* room, Game_State* game_state);                                                                                                                    // LINE: 1638
Entity* Create_Ring_Of_Protection(Entity* room, Game_State* game_state);                                                                                                                    // LINE: 1663
Entity* Create_Ring_Of_Precision(Entity* room, Game_State* game_state);                                                                                                                     // LINE: 1688
Entity* Create_Ring_Of_Avoidance(Entity* room, Game_State* game_state);                                                                                                                     // LINE: 1713
Entity* Create_Ring_Of_Wrath(Entity* room, Game_State* game_state);                                                                                                                         // LINE: 1738
Entity* Create_Ring_Of_Life(Entity* room, Game_State* game_state);                                                                                                                          // LINE: 1763
Entity* Create_Ring_Of_Penetration(Entity* room, Game_State* game_state);                                                                                                                   // LINE: 1788
Entity* Create_Ring_Of_Mending(Entity* room, Game_State* game_state);                                                                                                                       // LINE: 1814
Entity* Create_Huntsmans_Ring(Entity* room, Game_State* game_state);                                                                                                                        // LINE: 1839
Entity* Create_Ring_Of_The_Reliable_Worker(Entity* room, Game_State* game_state);                                                                                                           // LINE: 1864
Entity* Create_Ring_Of_Strange_Fortunes(Entity* room, Game_State* game_state);                                                                                                              // LINE: 1889
Entity* Create_Ring_Of_Rebirth(Entity* room, Game_State* game_state);                                                                                                                       // LINE: 1915
Entity* Create_Ring_Of_False_Hope(Entity* room, Game_State* game_state);                                                                                                                    // LINE: 1976
Entity* Create_Ring_Of_Regeneration(Entity* room, Game_State* game_state);                                                                                                                  // LINE: 2036
Entity* Create_Gloves_Of_Brutality(Entity* room, Game_State* game_state);                                                                                                                   // LINE: 2082
Entity* Create_Leather_Gloves(Entity* room, Game_State* game_state);                                                                                                                        // LINE: 2109
Entity* Create_Gloves_Of_Careful_Attacking(Entity* room, Game_State* game_state);                                                                                                           // LINE: 2134
Entity* Create_Field_Medics_Gloves(Entity* room, Game_State* game_state);                                                                                                                   // LINE: 2159
Entity* Create_Chainmail_Gloves(Entity* room, Game_State* game_state);                                                                                                                      // LINE: 2186
Entity* Create_Plate_Gloves(Entity* room, Game_State* game_state);                                                                                                                          // LINE: 2212
Entity* Create_Wooden_Shield(Entity* room, Game_State* game_state);                                                                                                                         // LINE: 2241
Entity* Create_Wicker_Shield(Entity* room, Game_State* game_state);                                                                                                                         // LINE: 2268
Entity* Create_Hide_Shield(Entity* room, Game_State* game_state);                                                                                                                           // LINE: 2294
Entity* Create_Buckler(Entity* room, Game_State* game_state);                                                                                                                               // LINE: 2321
Entity* Create_Kite_Shield(Entity* room, Game_State* game_state);                                                                                                                           // LINE: 2347
Entity* Create_Barn_Door_Shield(Entity* room, Game_State* game_state);                                                                                                                      // LINE: 2374
Entity* Create_Tower_Shield(Entity* room, Game_State* game_state);                                                                                                                          // LINE: 2401
Entity* Create_Shearing_Light(Entity* room, Game_State* game_state);                                                                                                                        // LINE: 2429
Entity* Create_Leather_Cuirass(Entity* room, Game_State* game_state);                                                                                                                       // LINE: 2456
Entity* Create_Gambeson(Entity* room, Game_State* game_state);                                                                                                                              // LINE: 2482
Entity* Create_Hauberk(Entity* room, Game_State* game_state);                                                                                                                               // LINE: 2509
Entity* Create_Nobles_Armored_Garb(Entity* room, Game_State* game_state);                                                                                                                   // LINE: 2537
Entity* Create_Vest_Of_Evasion(Entity* room, Game_State* game_state);                                                                                                                       // LINE: 2567
Entity* Create_Hedgehog_Skin_Vest(Entity* room, Game_State* game_state);                                                                                                                    // LINE: 2595
Entity* Create_Precise_Jerkin(Entity* room, Game_State* game_state);                                                                                                                        // LINE: 2623
Entity* Create_Strong_Jerkin(Entity* room, Game_State* game_state);                                                                                                                         // LINE: 2651
Entity* Create_Chestguard_Of_The_Silver_Blossoms_Scout(Entity* room, Game_State* game_state);                                                                                               // LINE: 2679
Entity* Create_Treebark_Jacket(Entity* room, Game_State* game_state);                                                                                                                       // LINE: 2708
Entity* Create_Robes_Of_The_Magi(Entity* room, Game_State* game_state);                                                                                                                     // LINE: 2738
Entity* Create_Kamikaze_Shirt(Entity* room, Game_State* game_state);                                                                                                                        // LINE: 2766
Entity* Create_Harness_Of_Enslavement(Entity* room, Game_State* game_state);                                                                                                                // LINE: 2796
Entity* Create_Myconian_Chestcover(Entity* room, Game_State* game_state);                                                                                                                   // LINE: 2826
Entity* Create_Lightforged_Iron_Chestguard(Entity* room, Game_State* game_state);                                                                                                           // LINE: 2879
Entity* Create_Emergency_Vest(Entity* room, Game_State* game_state);                                                                                                                        // LINE: 2950
Entity* Create_Field_Medics_Jerkin(Entity* room, Game_State* game_state);                                                                                                                   // LINE: 3001
Entity* Create_Restorers_Battle_Armor(Entity* room, Game_State* game_state);                                                                                                                // LINE: 3028
Entity* Create_Huntsmans_Gambeson(Entity* room, Game_State* game_state);                                                                                                                    // LINE: 3077
Entity* Create_Warrior_Poncho(Entity* room, Game_State* game_state);                                                                                                                        // LINE: 3106
Entity* Create_Assassins_Corset(Entity* room, Game_State* game_state);                                                                                                                      // LINE: 3134
Entity* Create_Breastplate(Entity* room, Game_State* game_state);                                                                                                                           // LINE: 3163
Entity* Create_Knights_Breastplate(Entity* room, Game_State* game_state);                                                                                                                   // LINE: 3194
Entity* Create_Crusaders_Breastplate(Entity* room, Game_State* game_state);                                                                                                                 // LINE: 3225
Entity* Create_Skull_Cap(Entity* room, Game_State* game_state);                                                                                                                             // LINE: 3259
Entity* Create_Trueshot_Goggles(Entity* room, Game_State* game_state);                                                                                                                      // LINE: 3285
Entity* Create_Thiefs_Mask(Entity* room, Game_State* game_state);                                                                                                                           // LINE: 3314
Entity* Create_Barbarian_Head_Ornamet(Entity* room, Game_State* game_state);                                                                                                                // LINE: 3343
Entity* Create_Nobles_Helm(Entity* room, Game_State* game_state);                                                                                                                           // LINE: 3371
Entity* Create_Alchemists_Cap(Entity* room, Game_State* game_state);                                                                                                                        // LINE: 3399
Entity* Create_Crown_Of_Thorns(Entity* room, Game_State* game_state);                                                                                                                       // LINE: 3428
Entity* Create_Hood_Of_The_Golden_Order(Entity* room, Game_State* game_state);                                                                                                              // LINE: 3456
Entity* Create_Penmans_Visor(Entity* room, Game_State* game_state);                                                                                                                         // LINE: 3484
Entity* Create_Plaguedoctos_Visor(Entity* room, Game_State* game_state);                                                                                                                    // LINE: 3512
Entity* Create_Putrid_Flesh_Head_Mould(Entity* room, Game_State* game_state);                                                                                                               // LINE: 3539
Entity* Create_Monks_Headband(Entity* room, Game_State* game_state);                                                                                                                        // LINE: 3587
Entity* Create_Damaged_Tiara_Of_Divine_Protection(Entity* room, Game_State* game_state);                                                                                                    // LINE: 3614
Entity* Create_Horny_Headband(Entity* room, Game_State* game_state);                                                                                                                        // LINE: 3668
Entity* Create_Monocle_Of_Thunderstrike(Entity* room, Game_State* game_state);                                                                                                              // LINE: 3694
Entity* Create_Arming_Cap(Entity* room, Game_State* game_state);                                                                                                                            // LINE: 3775
Entity* Create_Hide_Helmet(Entity* room, Game_State* game_state);                                                                                                                           // LINE: 3800
Entity* Create_Wooden_Helmet(Entity* room, Game_State* game_state);                                                                                                                         // LINE: 3825
Entity* Create_Bucket(Entity* room, Game_State* game_state);                                                                                                                                // LINE: 3851
Entity* Create_Sack(Entity* room, Game_State* game_state);                                                                                                                                  // LINE: 3878
Entity* Create_Chainmail_Hood(Entity* room, Game_State* game_state);                                                                                                                        // LINE: 3905
Entity* Create_Barbute(Entity* room, Game_State* game_state);                                                                                                                               // LINE: 3931
Entity* Create_Plate_Leggings(Entity* room, Game_State* game_state);                                                                                                                        // LINE: 3961
Entity* Create_Leather_Tights(Entity* room, Game_State* game_state);                                                                                                                        // LINE: 3991
Entity* Create_Padded_Pants(Entity* room, Game_State* game_state);                                                                                                                          // LINE: 4016
Entity* Create_Warrior_Kilt(Entity* room, Game_State* game_state);                                                                                                                          // LINE: 4041
Entity* Create_Barbarian_Loincloth(Entity* room, Game_State* game_state);                                                                                                                   // LINE: 4069
Entity* Create_Travel_Boots(Entity* room, Game_State* game_state);                                                                                                                          // LINE: 4097
Entity* Create_Sabatons(Entity* room, Game_State* game_state);                                                                                                                              // LINE: 4125
Entity* Create_Knights_Plate_Boots(Entity* room, Game_State* game_state);                                                                                                                   // LINE: 4155
Entity* Create_Mountaineer_Boots(Entity* room, Game_State* game_state);                                                                                                                     // LINE: 4185
Entity* Create_Gladiator_Sandals(Entity* room, Game_State* game_state);                                                                                                                     // LINE: 4212
Entity* Create_Leather_Boots(Entity* room, Game_State* game_state);                                                                                                                         // LINE: 4241
Entity* Create_Antidote(Entity* container, Game_State* game_state);                                                                                                                         // LINE: 4266
Entity* Create_Cure(Entity* container, Game_State* game_state);                                                                                                                             // LINE: 4306
Entity* Create_Bandage(Entity* container, Game_State* game_state);                                                                                                                          // LINE: 4346
Entity* Create_Dispeller(Entity* container, Game_State* game_state);                                                                                                                        // LINE: 4386
Entity* Create_Speed_Elixir(Entity* container, Game_State* game_state);                                                                                                                     // LINE: 4426
Entity* Create_Might_Elixir(Entity* container, Game_State* game_state);                                                                                                                     // LINE: 4473
Entity* Create_Accuracy_Elixir(Entity* container, Game_State* game_state);                                                                                                                  // LINE: 4520
Entity* Create_Dodge_Elixir(Entity* container, Game_State* game_state);                                                                                                                     // LINE: 4567
Entity* Create_Vitality_Elixir(Entity* container, Game_State* game_state);                                                                                                                  // LINE: 4614
Entity* Create_Immunity_Elixir(Entity* container, Game_State* game_state);                                                                                                                  // LINE: 4661
Entity* Create_Arcane_Elixir(Entity* container, Game_State* game_state);                                                                                                                    // LINE: 4708
Entity* Create_Healing_Potion(Entity* container, Game_State* game_state);                                                                                                                   // LINE: 4755
Entity* Create_Acid_Flask(Entity* container, Game_State* game_state);                                                                                                                       // LINE: 4795
Entity* Create_Restoration_Potion(Entity* container, Game_State* game_state);                                                                                                               // LINE: 4849
Entity* Create_Herbal_Remedy(Entity* container, Game_State* game_state);                                                                                                                    // LINE: 4917
Entity* Create_Bomb(Entity* container, Game_State* game_state);                                                                                                                             // LINE: 4953
Entity* Create_Fragmentation_Bomb(Entity* container, Game_State* game_state);                                                                                                               // LINE: 4999
Entity* Create_Mushroom(Entity* room, Game_State* game_state);                                                                                                                              // LINE: 5068
Entity* Create_Jerky(Entity* room, Game_State* game_state);                                                                                                                                 // LINE: 5081
Entity* Create_Bread(Entity* room, Game_State* game_state);                                                                                                                                 // LINE: 5094
Entity* Create_BBQ_Wings(Entity* room, Game_State* game_state);                                                                                                                             // LINE: 5107
Entity* Create_Steak_And_Smashed_Potatoes(Entity* room, Game_State* game_state);                                                                                                            // LINE: 5120
Entity* Create_Ring_Of_Just_Fucking_Crit(Entity* room, Game_State* game_state);                                                                                                             // LINE: 5135

// FILE: src\Factory.cpp:
void Finalize_Entity(Entity* entity, Entity* container, Game_State* game_state);                                                                                                            // LINE: 41
Entity* Create_Class_Adventurer(Game_State* game_state);                                                                                                                                    // LINE: 50
Entity* Create_Class_Mountaineer(Game_State* game_state);                                                                                                                                   // LINE: 96
Entity* Create_Class_Wretched(Game_State* game_state);                                                                                                                                      // LINE: 132
Entity* Create_Goblin(Entity* room, Game_State* game_state);                                                                                                                                // LINE: 154
Entity* Create_Orc(Entity* room, Game_State* game_state);                                                                                                                                   // LINE: 263
Entity* Create_Bandit(Entity* room, Game_State* game_state);                                                                                                                                // LINE: 368
Entity* Create_Bandit_Leader(Entity* room, Game_State* game_state);                                                                                                                         // LINE: 450
Entity* Create_Assassin(Entity* room, Game_State* game_state);                                                                                                                              // LINE: 532
Entity* Create_Giant_Honey_Badger(Entity* room, Game_State* game_state);                                                                                                                    // LINE: 610
Entity* Create_Living_Vine(Entity* room, Game_State* game_state);                                                                                                                           // LINE: 696
Entity* Create_Vineling(Entity* room, Game_State* game_state);                                                                                                                              // LINE: 754
Entity* Create_Leech(Entity* room, Game_State* game_state);                                                                                                                                 // LINE: 825
Entity* Create_Giant_Toad(Entity* room, Game_State* game_state);                                                                                                                            // LINE: 883
Entity* Create_Mosquito(Entity* room, Game_State* game_state);                                                                                                                              // LINE: 944
Entity* Create_Wolf(Entity* room, Game_State* game_state);                                                                                                                                  // LINE: 1008
Entity* Create_Hound(Entity* room, Game_State* game_state);                                                                                                                                 // LINE: 1070
Entity* Create_Earth_Golem(Entity* room, Game_State* game_state);                                                                                                                           // LINE: 1136
Entity* Create_Small_Earth_Golem(Entity* room, Game_State* game_state);                                                                                                                     // LINE: 1186
Entity* Create_Tiny_Earth_Golem(Entity* room, Game_State* game_state);                                                                                                                      // LINE: 1236
Entity* Create_Giant_Rat(Entity* room, Game_State* game_state);                                                                                                                             // LINE: 1286
Entity* Create_Blight_Rat(Entity* room, Game_State* game_state);                                                                                                                            // LINE: 1350
Entity* Create_Enlarged_Ant(Entity* room, Game_State* game_state);                                                                                                                          // LINE: 1472
Entity* Create_Enlarged_Ant_Queen(Entity* room, Game_State* game_state);                                                                                                                    // LINE: 1522
Entity* Create_Bear_Cub(Entity* room, Game_State* game_state);                                                                                                                              // LINE: 1608
Entity* Create_Cave_Bear(Entity* room, Game_State* game_state);                                                                                                                             // LINE: 1673
Entity* Create_Mutant_Hedgehog(Entity* room, Game_State* game_state);                                                                                                                       // LINE: 1740
Entity* Create_Clear_Ambush_Table_Dummy_Entity(Entity* room, Game_State* game_state);                                                                                                       // LINE: 1826
Entity* Create_Mimic(Entity* room, Game_State* game_state);                                                                                                                                 // LINE: 1835
Entity* Create_Chest(Entity* room, Game_State* game_state);                                                                                                                                 // LINE: 1934
Entity* Create_Weapon_Rack(Entity* room, Game_State* game_state);                                                                                                                           // LINE: 1983
Entity* Create_Armor_Rack(Entity* room, Game_State* game_state);                                                                                                                            // LINE: 2016
Entity* Create_Bookshelf(Entity* room, Game_State* game_state);                                                                                                                             // LINE: 2049
Entity* Create_Supply_Crate(Entity* room, Game_State* game_state);                                                                                                                          // LINE: 2082
Entity* Create_Alchemists_Pouch(Entity* room, Game_State* game_state);                                                                                                                      // LINE: 2128
Entity* Create_Rat_Mound(Entity* room, Game_State* game_state);                                                                                                                             // LINE: 2162
Entity* Create_Snake(Entity* room, Game_State* game_state);                                                                                                                                 // LINE: 2220
Entity* Create_Scorpion(Entity* room, Game_State* game_state);                                                                                                                              // LINE: 2280
Entity* Create_Spider(Entity* room, Game_State* game_state);                                                                                                                                // LINE: 2340
Entity* Create_Boss_Spider(Entity* room, Game_State* game_state);                                                                                                                           // LINE: 2380
void Generate_Standard_Random_Loot(Entity* container, Game_State* game_state);                                                                                                              // LINE: 2431

// FILE: src\Caves.cpp:
void Generate_Entrance_Room(Entity* room, Game_State* game_state);                                                                                                                          // LINE: 9
Loot_Table Caves_Wildlife_Section(Game_State* game_state);                                                                                                                                  // LINE: 87
Loot_Table Caves_Bandit_Section(Game_State* game_state);                                                                                                                                    // LINE: 955
Loot_Table Caves_Spider_Section(Game_State* game_state);                                                                                                                                    // LINE: 1261
Loot_Table Caves_Boss(Game_State* game_state);                                                                                                                                              // LINE: 1296
_inline Level_Segments Caves(Game_State* game_state);                                                                                                                                       // LINE: 1331

// FILE: src\Dungeon.cpp:
char* Get_Output_Color_CSTR(ANSI_Color_Buffer* buffer, u8 red, u8 green, u8 blue);                                                                                                          // LINE: 82
char* Entity_Color(Entity* entity, Game_State* game_state);                                                                                                                                 // LINE: 92
String Format_Message(Game_State* game_state, char* format_string, ...);                                                                                                                    // LINE: 119
_inline void Flush_Messages(Game_State* game_state);                                                                                                                                        // LINE: 138
_inline void Print_Messages(Game_State* game_state);                                                                                                                                        // LINE: 145
void Push_Message(String message, Game_State* game_state);                                                                                                                                  // LINE: 165
void Wait(f64 seconds, Game_State* game_state, Forced::T forced = Forced::T(0));                                                                                                            // LINE: 180
String Get_User_Input(Game_State* game_state);                                                                                                                                              // LINE: 189
bool User_Query_Yes_No(Game_State* game_state);                                                                                                                                             // LINE: 208
u64 Base_Alphabet_Digits(u64 v);                                                                                                                                                            // LINE: 242
u64 Encode_Base_Alphabet(u64 identity, char character);                                                                                                                                     // LINE: 262
U64_To_String_Memory Decode_Base_Aplhabet(u64 identity);                                                                                                                                    // LINE: 273
Entity_Offset* Find_Empty_Slot(Entity_Node* node);                                                                                                                                          // LINE: 292
Ambush_Creature_Spawner_Offset Offset(Ambush_Creature_Spawner* pointer, Game_State* game_state);                                                                                            // LINE: 317
Ambush_Creature_Spawner* Pointer(Ambush_Creature_Spawner_Offset offset, Game_State* game_state);                                                                                            // LINE: 329
Ambush_Option_Offset Offset(Ambush_Option* pointer, Game_State* game_state);                                                                                                                // LINE: 341
Ambush_Option* Pointer(Ambush_Option_Offset offset, Game_State* game_state);                                                                                                                // LINE: 353
_inline Entity_Offset Offset(Entity* entity, Game_State* game_state);                                                                                                                       // LINE: 365
_inline Entity* Pointer(Entity_Offset offset, Game_State* game_state);                                                                                                                      // LINE: 377
_inline Effect_Offset Offset(Effect* effect, Game_State* game_state);                                                                                                                       // LINE: 393
_inline Effect* Pointer(Effect_Offset offset, Game_State* game_state);                                                                                                                      // LINE: 406
_inline Entity_Node_Offset Offset(Entity_Node* entity_node, Game_State* game_state);                                                                                                        // LINE: 419
_inline Entity_Node* Pointer(Entity_Node_Offset offset, Game_State* game_state);                                                                                                            // LINE: 431
_inline Effects_Node_Offset Offset(Effects_Node* effects_node, Game_State* game_state);                                                                                                     // LINE: 443
_inline Effects_Node* Pointer(Effects_Node_Offset offset, Game_State* game_state);                                                                                                          // LINE: 455
String Unwrap_String(String_Wrapper* strw, Game_State* game_state);                                                                                                                         // LINE: 467
String_Offset Offset(String str, Game_State* game_state);                                                                                                                                   // LINE: 475
String Get_String(String_Offset offset, Game_State* game_state);                                                                                                                            // LINE: 559
_inline u64 Storage_Offset(void* ptr, Game_State* game_state);                                                                                                                              // LINE: 585
_inline void* Pull_From_Storage_Offset(u64 offset, Game_State* game_state);                                                                                                                 // LINE: 598
Entity_Offset* Find_Entity(Entity* entity, Entity_Root_Node* storage, Game_State* game_state, Entity_Node** out_node = 0);                                                                  // LINE: 611
Entity* Find_Entity_By_Name_Or_Reference_Number(Entity* actor, Entity_Offset space, String name_or_reference_number, Game_State* game_state, Verbose::T verbose = Verbose::T(1));           // LINE: 638
Entity* Find_Entity_By_Name(Entity* actor, Entity* space, String name, Game_State* game_state, Verbose::T verbose = Verbose::T(1));                                                         // LINE: 650
Entity* Find_Entity_By_Name_Or_Reference_Number(Entity* actor, Entity* space, String name_or_reference_number, Game_State* game_state, Verbose::T verbose = Verbose::T(1));                 // LINE: 682
Entity* Find_Entity_By_Name_Or_Reference_Number2(Entity* actor, Entity* space, String* in_out_args, Game_State* game_state, Verbose::T verbose);                                            // LINE: 723
Entity_Iterator Make_Iterator(Entity_Root_Node* root, Game_State* game_state);                                                                                                              // LINE: 809
Entity_Iterator Make_Iterator(Entity* entity, Game_State* game_state);                                                                                                                      // LINE: 827
Effects_Iterator Make_Iterator(Effects_Root* root, Game_State* game_state);                                                                                                                 // LINE: 835
Entity_Offset* Next(Entity_Iterator* iter);                                                                                                                                                 // LINE: 854
Entity* Next_Entity(Entity_Iterator* iter);                                                                                                                                                 // LINE: 884
u64 Count(Entity_Root_Node* root_node, Game_State* game_state);                                                                                                                             // LINE: 898
bool Memory_Snapshot_Save(String file_path, Game_State* game_state);                                                                                                                        // LINE: 911
bool Memory_Snapshot_Restore(String file_path, Game_State* game_state);                                                                                                                     // LINE: 920
Effect_Instance* Next_Effect_Instance(Effects_Iterator* iter);                                                                                                                              // LINE: 952
_inline Effect_Instance* Next(Effects_Iterator* iter);                                                                                                                                      // LINE: 985
Effect* Next_Effect(Effects_Iterator* iter);                                                                                                                                                // LINE: 992
Backwards_Iterator Make_Backwards_Iterator(Entity_Root_Node* root, Game_State* game_state);                                                                                                 // LINE: 1006
Entity_Offset* Previous(Backwards_Iterator* back_iter);                                                                                                                                     // LINE: 1020
void Add_Dice(Effect* effect, s16 count, s16 faces);                                                                                                                                        // LINE: 1064
u64 Per_Count_Rolled_Square_Weighted_Random(u64 count, Game_State* game_state);                                                                                                             // LINE: 1093
u64 Per_Count_Rolled_Random(u64 count, u32 change, Game_State* game_state);                                                                                                                 // LINE: 1108
u32 Roll(u32 range, Game_State* game_state);                                                                                                                                                // LINE: 1123
s32 Roll(Dice dice, Game_State* game_state);                                                                                                                                                // LINE: 1135
s32* Roll_With_Record(Dice dice, Game_State* game_state);                                                                                                                                   // LINE: 1151
f32 Random_F32(Game_State* game_state);                                                                                                                                                     // LINE: 1165
Roll_Result Stat_Roll(s32 value, Stats::T stat, Game_State* game_state);                                                                                                                    // LINE: 1175
s32 Value(Roll_Result rr);                                                                                                                                                                  // LINE: 1191
Roll_Result Stat_Roll(Entity* entity, Stats::T stat, Game_State* game_state);                                                                                                               // LINE: 1198
_inline bool Is_Rolled(Roll_Result rr);                                                                                                                                                     // LINE: 1209
void Print_Dice(Dice dice, s32 result);                                                                                                                                                     // LINE: 1216
void Print_Roll_Result(Roll_Result rr);                                                                                                                                                     // LINE: 1222
void Print_Attack_Record(Attack_Record* ar, Game_State* game_state);                                                                                                                        // LINE: 1235
String Name_Without_Color(Entity* entity, Game_State* game_state);                                                                                                                          // LINE: 1499
String Name(Entity* entity, Game_State* game_state);                                                                                                                                        // LINE: 1514
char* Action_Name(AT::T action);                                                                                                                                                            // LINE: 1534
void Print_Required_Equipment_Slots(Entity* item);                                                                                                                                          // LINE: 1561
s32 Potency(String name, s32 base, Game_State* game_state);                                                                                                                                 // LINE: 1585
s32 Potency(String name, s32 base, Dice dice, Game_State* game_state);                                                                                                                      // LINE: 1598
void Push_Generic_Apply_Effect_Message(String source_name, Entity* target, Effect_Instance new_effect, Apply_Effect_Result apply, Game_State* game_state);                                  // LINE: 1667
void Remove_From_Residence(Entity* entity, Game_State* game_state);                                                                                                                         // LINE: 1723
void Release_Entity_Node(Entity_Root_Node* root, Game_State* game_state);                                                                                                                   // LINE: 1757
Entity_Node* Request_Entity_Node(Game_State* game_state);                                                                                                                                   // LINE: 1779
Effect* Request_Effect(Game_State* game_state);                                                                                                                                             // LINE: 1796
void Release_Effect(Effect* effect, Game_State* game_state);                                                                                                                                // LINE: 1819
Entity* Request_Entity(Game_State* game_state);                                                                                                                                             // LINE: 1833
void Release_Entity(Entity* entity, Game_State* game_state);                                                                                                                                // LINE: 1855
Effects_Node* Request_Effects_Node(Game_State* game_state);                                                                                                                                 // LINE: 1863
void Release_Effects_Node(Effects_Node* node, Game_State* game_state);                                                                                                                      // LINE: 1880
void Insert(Entity* entity, Entity_Root_Node* storage, Game_State* game_state);                                                                                                             // LINE: 1888
void Assign_Dublicate_Name_Identifier(Entity* entity_to_insert, Entity* storage, Game_State* game_state);                                                                                   // LINE: 1925
void Deep_Insert(Entity* entity, Entity* storage_entity, Game_State* game_state, Assign_Dublicate_Identifier::T assign_dublicate_identifier = Assign_Dublicate_Identifier::T(1));           // LINE: 1959
bool Contains_An_Active_Hostile(Entity* room, Entity* actor, Game_State* game_state);                                                                                                       // LINE: 1981
bool Residence_Contains_An_Active_Hostile(Entity* actor, Game_State* game_state);                                                                                                           // LINE: 1998
Ambush_Option* Request_Ambush_Option(Game_State* game_state);                                                                                                                               // LINE: 2008
void Release_Ambush_Option(Ambush_Option* ambush_option, Game_State* game_state);                                                                                                           // LINE: 2025
Ambush_Creature_Spawner* Request_Ambush_Creature_Spawner(Game_State* game_state);                                                                                                           // LINE: 2033
void Release_Ambush_Creature_Spawner(Ambush_Creature_Spawner* spawner, Game_State* game_state);                                                                                             // LINE: 2050
Ambush_Option* Create_Ambush_Option(f32 change, Game_State* game_state);                                                                                                                    // LINE: 2058
void Add_Ambush_Creature_Spawner(Ambush_Option* ambush, Ambush_Creature_Spawner spawner, Game_State* game_state);                                                                           // LINE: 2069
void Reset_Ambush_Table(Game_State* game_state);                                                                                                                                            // LINE: 2078
void Set_Ambush_Change(f32 change, Game_State* game_state);                                                                                                                                 // LINE: 2100
bool Trigger_Ambush(Entity* room, Game_State* game_state, Entity*** out_spawned_entities, u64* out_spawned_count);                                                                          // LINE: 2106
bool Is_The_Same(Entity* A, Entity* B, Game_State* game_state);                                                                                                                             // LINE: 2171
void Remove_All_Effects(Entity* entity, Game_State* game_state);                                                                                                                            // LINE: 2202
void Delete_Entity(Entity* entity, Game_State* game_state);                                                                                                                                 // LINE: 2262
bool Has_Content(Entity_Root_Node* root);                                                                                                                                                   // LINE: 2269
bool Is_Empty(Entity_Root_Node* root);                                                                                                                                                      // LINE: 2276
s32 Get_Stat_Value(Entity* entity, Stats::T stat, Game_State* game_state, u64* out_effect_count = 0);                                                                                       // LINE: 2289
void Ding(Entity* actor, Game_State* game_state);                                                                                                                                           // LINE: 2336
s32 Exp_To_Level_Up(s32 _lvl);                                                                                                                                                              // LINE: 2383
_inline s32 Exp_To_Level_Up(Entity* entity);                                                                                                                                                // LINE: 2391
s16 Calculate_Level(Entity* entity);                                                                                                                                                        // LINE: 2398
void Set_Level_Based_On_Stats(Entity* entity);                                                                                                                                              // LINE: 2413
s32 Exp_Reward(Entity* entity);                                                                                                                                                             // LINE: 2420
s16 Level(Entity* entity);                                                                                                                                                                  // LINE: 2434
s32 Max_Health(Entity* entity, Game_State* game_state);                                                                                                                                     // LINE: 2441
f32 Critical_Multiplier(Entity* entity, Game_State* game_state);                                                                                                                            // LINE: 2476
s32 Carry_Capacity(Entity* entity, Game_State* game_state);                                                                                                                                 // LINE: 2483
s32 Carrying_Amount(Entity* entity, Game_State* game_state);                                                                                                                                // LINE: 2503
f32 Threat(Entity* entity);                                                                                                                                                                 // LINE: 2516
Critical_Ranges_Result Critical_Ranges(Entity* entity, Game_State* game_state, u32* out_success_effecting_count = 0, u32* out_failure_effecing_count = 0);                                  // LINE: 2523
void Full_Heal(Entity* entity, Game_State* game_state);                                                                                                                                     // LINE: 2565
bool Is_Item(Entity* entity);                                                                                                                                                               // LINE: 2571
bool Is_Visible(Entity* entity, Entity* actor, Game_State* game_state);                                                                                                                     // LINE: 2578
bool Is_Alive(Entity* entity);                                                                                                                                                              // LINE: 2587
bool Is_Hostile_Against(Entity* A, Entity* B);                                                                                                                                              // LINE: 2594
bool Is_Living_Enemy_Of(Entity* actor, Entity* target);                                                                                                                                     // LINE: 2605
bool Is_Living_Active_Enemy_Of(Entity* actor, Entity* target);                                                                                                                              // LINE: 2612
s32 Give_Temporary_Health(Entity* entity, s32 amount, String source_name, Verbose::T verbose, Game_State* game_state);                                                                      // LINE: 2619
Healing_Result Heal(Entity* entity, s32 amount, String source_name, Verbose::T verbose, Game_State* game_state);                                                                            // LINE: 2652
Deal_Damage_Result Deal_Damage(Entity* defender, Entity_Offset attacker_offset, String source_name, s32 dmg, s32 pierce, Damage_Type type, Game_State* game_state, Verbose::T verbose);     // LINE: 2747
_inline Deal_Damage_Result Deal_Damage(Entity* defender, Entity* attacker, String dmg_src_name, s32 dmg, s32 pierce, Damage_Type type, Game_State* game_state, Verbose::T verbose);         // LINE: 2937
void Proc_Effects(u64 offset, Entity* attacker, Entity* defender, Attack_Record* ar, Game_State* game_state);                                                                               // LINE: 2945
void Proc_Effects(u64 offset, Entity* target, Game_State* game_state);                                                                                                                      // LINE: 2962
String Effect_Name(Effect_Instance* instance, Game_State* game_state);                                                                                                                      // LINE: 2978
u64 Count_Effect_Instances(Effects_Root* root, Effect_Instance cmp, Game_State* game_state, Effect_Instance** out_shortest_duration = 0);                                                   // LINE: 2998
void Delete_Effect_Slot(Entity* actor, Effects_Root* root, Effects_Node* node, u64 *idx, u64* count, Game_State* game_state);                                                               // LINE: 3028
Effect_Instance* New_Effect_Slot(Effects_Root* root, Game_State* game_state);                                                                                                               // LINE: 3070
Apply_Check_Record Application_Check(Entity* attacker, Entity* defender, Game_State* game_state);                                                                                           // LINE: 3116
void Attempt_Infection(Entity* attacker, Entity* defender, String source_name, Effect_Instance infectious_effect_instance, Game_State* game_state);                                         // LINE: 3129
Apply_Effect_Result Apply_Effect(Entity* target, Effect_Instance instance, Game_State* game_state, Forced::T forced = Forced::T(0));                                                        // LINE: 3162
void Remove_Effects_From_Source(Entity* actor, Entity* source, Game_State* game_state);                                                                                                     // LINE: 3237
u64 Remove_Effects_Of_Type(Entity* actor, Effect_Type::T type_to_remove, Game_State* game_state, Verbose::T verbose);                                                                       // LINE: 3262
void Print_Equiped_Weapons(Entity* target, bool preamble, Game_State* game_state);                                                                                                          // LINE: 3540
void Inspect(Entity* target, Game_State* game_state);                                                                                                                                       // LINE: 3578
bool Is_Equipped(Entity* actor, Entity* item, Game_State* game_state);                                                                                                                      // LINE: 3663
bool Unequip(Entity* actor, Entity* item, Game_State* game_state);                                                                                                                          // LINE: 3686
bool Unequip(Entity* item, Game_State* game_state);                                                                                                                                         // LINE: 3710
bool Is_On_CD(Interactable* inter, Game_State* game_state, u64* out_cd = 0);                                                                                                                // LINE: 3718
bool Use(Entity* actor, Entity* item, Game_State* game_state, Verbose::T verbose);                                                                                                          // LINE: 3759
void Inventory(Entity* actor, Game_State* game_state);                                                                                                                                      // LINE: 3820
void List_Active_Effects(Entity* actor, Game_State* game_state);                                                                                                                            // LINE: 3994
bool Equip(Entity* actor, Entity* target, Game_State* game_state, Verbose::T verbose = Verbose::T(0));                                                                                      // LINE: 4032
void Print_Uses(Entity* entity);                                                                                                                                                            // LINE: 4259
void Open(Entity* actor, Game_State* game_state);                                                                                                                                           // LINE: 4279
u64 Longest_Visible_Entity_Name_In_Actor_Storage(Entity* actor, Game_State* game_state, u64* out_count = 0);                                                                                // LINE: 4307
bool Glance(Entity* actor, Game_State* game_state, Report_Turn_Taken_Status::T report_turn_taken_status = Report_Turn_Taken_Status::T(1));                                                  // LINE: 4332
void Remove_Random_Effect(Entity* entity, String source_name, Game_State* game_state);                                                                                                      // LINE: 4425
Damage_Modifiers_Result Damage_Modifier_From_Effects(Entity* attacker, Attack_Record* ar, Game_State* game_state);                                                                          // LINE: 4464
u64 Attack_Modifier_Mask(Attack_Mod::T modifier);                                                                                                                                           // LINE: 4572
u64 Class_Mask(Class::T _class);                                                                                                                                                            // LINE: 4579
bool Can_Use_Attack_Modifier(Entity* entity, Attack_Mod::T modifier);                                                                                                                       // LINE: 4586
void Apply_Or_Describe_Attak_Modifier(Entity** attacker_ptr, Entity** defender_ptr, Attack_Mod::T modifier, Game_State* game_state);                                                        // LINE: 4597
void Proc_Thorns(Entity* attacker, Entity* defender, Game_State* game_state);                                                                                                               // LINE: 4744
void Attack(Entity* attacker, Entity* defender, Game_State* game_state, Attack_Mod::T modifier = Attack_Mod::T(0));                                                                         // LINE: 4767
void Player_Action(Entity* actor, String actor_name, Game_State* game_state);                                                                                                               // LINE: 4850
Entity* Redirected_Target(Entity* actor, String actor_name, Game_State* game_state);                                                                                                        // LINE: 4939
Entity* Random_Entity_That_Matches_Criteria(Entity_Root_Node* storage, bool(*conditional)(Entity* entity, void* user_ptr, Game_State* game_state), void* user_ptr, Game_State* game_state); // LINE: 4977
Entity* Find_Attack_Target(Entity* actor, Game_State* game_state);                                                                                                                          // LINE: 5016
void NPC_Action(Entity* actor, String actor_name, Game_State* game_state);                                                                                                                  // LINE: 5074
void Take_Action(Entity* actor, Game_State* game_state);                                                                                                                                    // LINE: 5152
u64 Hash_From_Key(Effect_Hash_Key key);                                                                                                                                                     // LINE: 5224
bool Retrive_Effect(Effect_Hash_Key key, Effect_Offset* out, Game_State* game_state);                                                                                                       // LINE: 5231
Effect_Offset Insert_Effect(Effect effect, Effect_Hash_Key key, Game_State* game_state);                                                                                                    // LINE: 5269
bool Compare(s64 X, Comparison type, s64 A, s64 B = 0);                                                                                                                                     // LINE: 5307
bool Is_Compliant(Loot_Table_Entry entry, Pick_From_Table_Rules rules);                                                                                                                     // LINE: 5337
Loot_Table_Pick_Result Pick_From_Loot_Table(Loot_Table table, u64 count, Pick_From_Table_Rules rules, Game_State* game_state);                                                              // LINE: 5366
GENERATE_ENTITY_FN* Pick_From_Loot_Table(Loot_Table table, Pick_From_Table_Rules rules, Game_State* game_state);                                                                            // LINE: 5418
void Generate_From_Loot_Table(Entity* storage, Loot_Table table, u64 count, Pick_From_Table_Rules rules, Game_State* game_state);                                                           // LINE: 5425
Loot_Table Merge_Loot_Tables(Loot_Table* tables, u64 count, Arena* arena);                                                                                                                  // LINE: 5435
_inline Loot_Table Merge_Loot_Tables_Internal(Loot_Table A, Loot_Table B, Arena* arena);                                                                                                    // LINE: 5449
Loot_Table Merge_Loot_Tables(Loot_Table A, Loot_Table B, Arena* arena);                                                                                                                     // LINE: 5466
Loot_Table Merge_Loot_Tables(Loot_Table A, Loot_Table B, Loot_Table C, Arena* arena);                                                                                                       // LINE: 5474
Loot_Table Merge_Loot_Tables(Loot_Table A, Loot_Table B, Loot_Table C, Loot_Table D, Arena* arena);                                                                                         // LINE: 5482
Loot_Table Merge_Loot_Tables(Loot_Table A, Loot_Table B, Loot_Table C, Loot_Table D, Loot_Table E, Arena* arena);                                                                           // LINE: 5490
Loot_Table Merge_Loot_Tables(Loot_Table A, Loot_Table B, Loot_Table C, Loot_Table D, Loot_Table E, Loot_Table F, Arena* arena);                                                             // LINE: 5498
void Normalize_Loot_Table_Changes(Loot_Table* table);                                                                                                                                       // LINE: 5506
void Fill_Loot_Table_Changes_And_Item_Rarity(Loot_Table* table, Game_State* game_state);                                                                                                    // LINE: 5516
bool Roll_Initiative(Entity* entity, Game_State* game_state);                                                                                                                               // LINE: 5598
void Sort_Iniative_Order(Entity_Offset* offs, Game_State* game_state);                                                                                                                      // LINE: 5632
void Sort_Space(Entity_Root_Node* space, Game_State* game_state);                                                                                                                           // LINE: 5763
u64 Count_Longest_Round_Effect_Duration(Entity* actor, Game_State* game_state);                                                                                                             // LINE: 5839
void Tick_Down_Effect_Durations(Entity* actor, Duration_Type type, Game_State* game_state);                                                                                                 // LINE: 5854
_inline void Enter_A_Room_Printout(Entity* player, Entity* room, Game_State* game_state);                                                                                                   // LINE: 5928
CMD_Result::T Attempt_To_Execute_Command(Command* commands, u64 count, String user_input, void* user_ptr, Game_State* game_state);                                                          // LINE: 5951
CMD_Result::T Prompt_User_For_Command_And_Attempt_To_Execute(Command* commands, u64 count, void* user_ptr, Game_State* game_state);                                                         // LINE: 6057
void Create_Player_Charater(Game_State* game_state);                                                                                                                                        // LINE: 6065
void Tick_Active_Effects_Down_To_Zero(Entity* actor, Game_State* game_state);                                                                                                               // LINE: 6253
Entity* Next_Room(Level_Segments level, Game_State* game_state);                                                                                                                            // LINE: 6278
void Proceed(Game_State* game_state);                                                                                                                                                       // LINE: 6325
void Prepare_Game_Round(Game_State* game_state);                                                                                                                                            // LINE: 6394
void Excecute_Game_Round(Game_State* game_state);                                                                                                                                           // LINE: 6507
void Exit_Handling(Game_State* game_state);                                                                                                                                                 // LINE: 6545
bool Play_Game(Game_State* game_state);                                                                                                                                                     // LINE: 6577
void Reset_Game_State(Game_State* game_state);                                                                                                                                              // LINE: 6607
Game_State* Create_Game_State();                                                                                                                                                            // LINE: 6663
CMD_Result::T Kill_Command(Entity* actor, String args, Game_State* game_state);                                                                                                             // LINE: 6694
CMD_Result::T Toggle_Dramatic_Pause(Entity* actor, String args, Game_State* game_state);                                                                                                    // LINE: 6721
CMD_Result::T Toggle_Godmode(Entity* actor, String args, Game_State* game_state);                                                                                                           // LINE: 6745
CMD_Result::T Help_Command(Entity* entity, String args, Game_State* game_state);                                                                                                            // LINE: 6764
CMD_Result::T Attacks_Command(Entity* entity, String args, Game_State* game_state);                                                                                                         // LINE: 6804
CMD_Result::T Pickup_Command(Entity* actor, String args, Game_State* game_state);                                                                                                           // LINE: 6857
CMD_Result::T Inventory_Command(Entity* actor, String args, Game_State* game_state);                                                                                                        // LINE: 6906
CMD_Result::T Proceed_Command(Entity* actor, String args, Game_State* game_state);                                                                                                          // LINE: 6933
CMD_Result::T Equipment_Command(Entity* actor, String args, Game_State* game_state);                                                                                                        // LINE: 7030
CMD_Result::T Drop_Command(Entity* actor, String args, Game_State* game_state);                                                                                                             // LINE: 7065
CMD_Result::T Use_Command(Entity* actor, String args, Game_State* game_state);                                                                                                              // LINE: 7100
CMD_Result::T Equip_Command(Entity* actor, String args, Game_State* game_state);                                                                                                            // LINE: 7137
CMD_Result::T Unequip_Command(Entity* actor, String args, Game_State* game_state);                                                                                                          // LINE: 7159
CMD_Result::T Stats_Command(Entity* actor, String args, Game_State* game_state);                                                                                                            // LINE: 7188
CMD_Result::T Camp_Command(Entity* actor, String args, Game_State* game_state);                                                                                                             // LINE: 7303
CMD_Result::T Status_Command(Entity* actor, String args, Game_State* game_state);                                                                                                           // LINE: 7406
CMD_Result::T Inspect_Command(Entity* actor, String args, Game_State* game_state);                                                                                                          // LINE: 7478
CMD_Result::T What_Is_Seed_Command(Entity* entity, String args, Game_State* game_state);                                                                                                    // LINE: 7519
CMD_Result::T Pass_Command(Entity* actor, String args, Game_State* game_state);                                                                                                             // LINE: 7535
CMD_Result::T Glance_Command(Entity* actor, String args, Game_State* game_state);                                                                                                           // LINE: 7551
CMD_Result::T Search_Command(Entity* actor, String args, Game_State* game_state);                                                                                                           // LINE: 7575
CMD_Result::T Restart_Command(Entity* actor, String args, Game_State* game_state);                                                                                                          // LINE: 7623
CMD_Result::T Save_Command(Entity* actor, String args, Game_State* game_state);                                                                                                             // LINE: 7658
CMD_Result::T Load_Command(Entity* actor, String args, Game_State* game_state);                                                                                                             // LINE: 7684
CMD_Result::T Exit_Command(Entity* actor, String args, Game_State* game_state);                                                                                                             // LINE: 7710
CMD_Result::T Loot_Command(Entity* actor, String args, Game_State* game_state);                                                                                                             // LINE: 7748
CMD_Result::T Attack_Command(Entity* actor, String args, Game_State* game_state);                                                                                                           // LINE: 7826
CMD_Result::T Set_Seed_Command(Entity* actor, String args, Game_State* game_state);                                                                                                         // LINE: 7889
CMD_Result::T Get_Exp_Command(Entity* actor, String args, Game_State* game_state);                                                                                                          // LINE: 7919
void Get_Level_Up_Commands(Command** out_commands, u64* out_count, Game_State* game_state);                                                                                                 // LINE: 7947
void Get_Character_Creator_Commands(Command** out_commands, u64* out_count, Game_State* game_state);                                                                                        // LINE: 8321
