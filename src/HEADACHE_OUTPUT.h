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
struct Effect_Offset;                                                                                                                                                                       // LINE: 83
struct Effects_Node_Offset;                                                                                                                                                                 // LINE: 90
struct Entity_Node_Offset;                                                                                                                                                                  // LINE: 102
enum class Storage : u8;                                                                                                                                                                    // LINE: 108
struct String_Offset;                                                                                                                                                                       // LINE: 115
struct String_Wrapper;                                                                                                                                                                      // LINE: 131
struct String_Table;                                                                                                                                                                        // LINE: 138
struct String_Table_Root;                                                                                                                                                                   // LINE: 146
struct Entity_Offset;                                                                                                                                                                       // LINE: 153
struct Entity_Node;                                                                                                                                                                         // LINE: 160
struct Entity_Root_Node;                                                                                                                                                                    // LINE: 167
struct Dice;                                                                                                                                                                                // LINE: 212
struct Bonus_Dice;                                                                                                                                                                          // LINE: 219
struct Effect_Hash_Key;                                                                                                                                                                     // LINE: 236
struct Effect;                                                                                                                                                                              // LINE: 249
enum class Apply_Effect_Result : u8;                                                                                                                                                        // LINE: 320
enum class Duration_Type : u8;                                                                                                                                                              // LINE: 333
struct Effect_Instance;                                                                                                                                                                     // LINE: 406
struct Effects_Node;                                                                                                                                                                        // LINE: 448
struct Effects_Root;                                                                                                                                                                        // LINE: 459
struct Roll_Result;                                                                                                                                                                         // LINE: 467
struct Initiative;                                                                                                                                                                          // LINE: 477
enum class Cooldown_Type : u8;                                                                                                                                                              // LINE: 485
struct Interactable;                                                                                                                                                                        // LINE: 493
enum class Faction : u8;                                                                                                                                                                    // LINE: 507
struct Entity;                                                                                                                                                                              // LINE: 526
struct Leveler;                                                                                                                                                                             // LINE: 579
struct Damage_Modifiers_Result;                                                                                                                                                             // LINE: 589
struct Damage_Modifier;                                                                                                                                                                     // LINE: 596
struct Healing_Result;                                                                                                                                                                      // LINE: 608
struct Deal_Damage_Result;                                                                                                                                                                  // LINE: 621
enum class Damage_Type;                                                                                                                                                                     // LINE: 635
struct Critical_Ranges_Result;                                                                                                                                                              // LINE: 642
struct Message_Pipe;                                                                                                                                                                        // LINE: 649
struct Apply_Check_Record;                                                                                                                                                                  // LINE: 656
struct Attack_Record;                                                                                                                                                                       // LINE: 665
struct Entity_Iterator;                                                                                                                                                                     // LINE: 748
struct Backwards_Iterator;                                                                                                                                                                  // LINE: 763
struct Ambush_Creature_Spawner_Offset;                                                                                                                                                      // LINE: 773
struct Ambush_Option_Offset;                                                                                                                                                                // LINE: 779
struct Ambush_Creature_Spawner;                                                                                                                                                             // LINE: 785
struct Ambush_Option;                                                                                                                                                                       // LINE: 794
struct Ambush_Table;                                                                                                                                                                        // LINE: 802
struct Effects_Iterator;                                                                                                                                                                    // LINE: 810
struct Effect_Hash_Table_Entry;                                                                                                                                                             // LINE: 822
struct Effect_Hash_Table;                                                                                                                                                                   // LINE: 829
struct Game_State;                                                                                                                                                                          // LINE: 838
struct Character_Creator;                                                                                                                                                                   // LINE: 899
struct Loot_Table_Entry;                                                                                                                                                                    // LINE: 908
struct Loot_Table_Pick_Result;                                                                                                                                                              // LINE: 919
struct Loot_Table;                                                                                                                                                                          // LINE: 926
struct Pick_From_Table_Rules;                                                                                                                                                               // LINE: 935
struct Rules_Builder;                                                                                                                                                                       // LINE: 949
enum class Comparison : u8;                                                                                                                                                                 // LINE: 998
struct Level_Segment;                                                                                                                                                                       // LINE: 1007
struct Level_Segments;                                                                                                                                                                      // LINE: 1014
struct Room_Generator_Element;                                                                                                                                                              // LINE: 1021
struct Room_Generator_Element_Array;                                                                                                                                                        // LINE: 1028
struct Game_Command;                                                                                                                                                                        // LINE: 1117
enum class Call_Style;                                                                                                                                                                      // LINE: 1128
struct Command;                                                                                                                                                                             // LINE: 1136
typedef void PROTOTYPE_ENT_GS(Entity*, Game_State*);;                                                                                                                                       // LINE: 1249
typedef void PROTOTYPE_ENT_ENT_GS(Entity*, Entity*, Game_State*);;                                                                                                                          // LINE: 1250
typedef void PROTOTYPE_EFFINST_ENT_GS(Effect_Instance*, Entity*, Game_State*);;                                                                                                             // LINE: 1251
typedef void PROTOTYPE_EFFINST_ENT_ENT_GS(Effect_Instance*, Entity*, Entity*, Game_State*);;                                                                                                // LINE: 1252
typedef void PROTOTYPE_EFFINST_ENT_ENT_AR_GS(Effect_Instance*, Entity*, Entity*, Attack_Record*, Game_State*);;                                                                             // LINE: 1253
typedef void PROTOTYPE_EFFINST_ENTOFF_ENT_DDR_GS(Effect_Instance*, Entity_Offset, Entity*, Deal_Damage_Result*, Game_State*);;                                                              // LINE: 1254
typedef void PROTOTYPE_EFFINST_ENT_S32PTR_STR_GS(Effect_Instance*, Entity*, s32*, String, Game_State*);;                                                                                    // LINE: 1255
typedef void PROTOTYPE_EFFINST_ENT_STAT_S32PTR_S16PTR_GS(Effect_Instance*, Entity*, Stats::T, s32*, s16*, Game_State*);;                                                                    // LINE: 1256
typedef Entity* GENERATE_ENTITY_FN(Entity*, Game_State*);;                                                                                                                                  // LINE: 1258
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
    enum T : u32;                                                                                                                                                                           // LINE: 192
}

namespace Effect_Flags
{
    enum T : s8;                                                                                                                                                                            // LINE: 228
}

namespace Effect_Type
{
    enum T : u8;                                                                                                                                                                            // LINE: 305
}

namespace Food_Quality
{
    enum T : u8;                                                                                                                                                                            // LINE: 356
}

namespace Class
{
    enum T : u8;                                                                                                                                                                            // LINE: 384
}

namespace Roll_Print_Style
{
    enum T;                                                                                                                                                                                 // LINE: 697
}

namespace Report_Turn_Taken_Status
{
    enum T : u8;                                                                                                                                                                            // LINE: 710
}

namespace Verbose
{
    enum T : u8;                                                                                                                                                                            // LINE: 720
}

namespace Forced
{
    enum T : u8;                                                                                                                                                                            // LINE: 730
}

namespace Assign_Dublicate_Identifier
{
    enum T : u8;                                                                                                                                                                            // LINE: 740
}

namespace Attack_Mod
{
    enum T;                                                                                                                                                                                 // LINE: 1088
}

namespace CMD_Result
{
    enum T : u8;                                                                                                                                                                            // LINE: 1107
}


// FILE: src\Dungeon.cpp:
enum class Custom_Start;                                                                                                                                                                    // LINE: 36
struct On_Get_Stat_Value_Storage;                                                                                                                                                           // LINE: 2306


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
void Strength_Of_Earth_Small_On_Turn_Start(Effect_Instance* instance, Entity* target, Game_State* game_state);                                                                              // LINE: 144
void Strength_Of_Earth_Tiny_On_Turn_Start(Effect_Instance* instance, Entity* target, Game_State* game_state);                                                                               // LINE: 170
void Dissapate_After_Two_On_Turn_Start(Effect_Instance* instance, Entity* target, Game_State* game_state);                                                                                  // LINE: 196
Effect_Offset Get_Enraged_Effect_Offset(Game_State* game_state);                                                                                                                            // LINE: 221
Effect_Instance Get_Enraged(Entity* source, Game_State* game_state);                                                                                                                        // LINE: 294
Effect_Offset Get_Vampirism_Effect_Offset(Game_State* game_state);                                                                                                                          // LINE: 306
Effect_Instance Get_Poison(u64 duration, Entity* source, Game_State* game_state);                                                                                                           // LINE: 365
Effect_Offset Get_Burning_Effect_Offset(Game_State* game_state);                                                                                                                            // LINE: 404
Effect_Instance Get_Burning(u64 duration, Entity* source, Game_State* game_state);                                                                                                          // LINE: 439
Effect_Instance Get_Festering_Rash(u64 duration, Entity* source, Game_State* game_state);                                                                                                   // LINE: 450
Effect_Instance Get_Weakening_Blight(u64 duration, Entity* source, Game_State* game_state);                                                                                                 // LINE: 481
Effect_Instance Get_Neuro_Toxin(u64 duration, Entity* source, Game_State* game_state);                                                                                                      // LINE: 504
Effect_Instance Get_Enwebbed(u64 duration, Entity* source, Game_State* game_state);                                                                                                         // LINE: 526
Effect_Instance Get_Deep_Wound(u64 duration, Entity* source, Game_State* game_state);                                                                                                       // LINE: 551
Effect_Instance Get_Leech(u64 duration, Entity* source, Game_State* game_state);                                                                                                            // LINE: 591
Effect_Instance Get_Filled_With_Blood(u64 duration, Entity* source, Game_State* game_state);                                                                                                // LINE: 647
Effect_Instance Get_Malaria(u64 duration, Entity* source, Game_State* game_state);                                                                                                          // LINE: 690
Effect_Instance Get_Devouring_Plague(u64 duration, Entity* source, Game_State* game_state);                                                                                                 // LINE: 713
Effect_Instance Get_Entangled(u64 duration, Entity* source, Game_State* game_state);                                                                                                        // LINE: 751
Effect_Offset Get_Seed_Effect_Offset(Game_State* game_state);                                                                                                                               // LINE: 776
Effect_Instance Get_Seed(Entity* source, Game_State* game_state);                                                                                                                           // LINE: 852
Effect_Offset Get_Weak_Grip_Offset(Game_State* game_state);                                                                                                                                 // LINE: 871
void Stun_Attacker(Effect_Instance* instance, Entity* attacker, Entity* defender, Attack_Record* ar, Game_State* game_state);                                                               // LINE: 924
Effect_Instance Reckless_Attack(Entity* attacker, Game_State* game_state);                                                                                                                  // LINE: 945
Effect_Instance Careful_Attack(Entity* attacker, Game_State* game_state);                                                                                                                   // LINE: 972
Effect_Instance Weakspot_Attack(Entity* attacker, Game_State* game_state);                                                                                                                  // LINE: 1002
Effect_Instance Allin_Attack(Entity* attacker, Game_State* game_state);                                                                                                                     // LINE: 1029
Effect_Instance Guarding_Attack(Entity* attacker, Game_State* game_state);                                                                                                                  // LINE: 1059
Effect_Instance Evasive_Attack(Entity* attacker, Game_State* game_state);                                                                                                                   // LINE: 1086
Effect_Instance Execute_Attack(Entity* attacker, Game_State* game_state);                                                                                                                   // LINE: 1113
Effect_Instance Disarming_Attack(Entity* attacker, Game_State* game_state);                                                                                                                 // LINE: 1178
Effect_Instance Vampiric_Attack(Entity* attacker, Game_State* game_state);                                                                                                                  // LINE: 1250
Effect_Instance Blessed_Attack(Entity* attacker, Game_State* game_state);                                                                                                                   // LINE: 1307
Effect_Instance Berserking_Attack(Entity* attacker, Game_State* game_state);                                                                                                                // LINE: 1381
Effect_Instance Redirect_Attack(Entity* attacker, Game_State* game_state);                                                                                                                  // LINE: 1454
Effect_Instance Change_Attack(Entity* attacker, Game_State* game_state);                                                                                                                    // LINE: 1506
Effect_Instance Thieving_Attack(Entity* attacker, Game_State* game_state);                                                                                                                  // LINE: 1600
Effect_Instance Stylish_Attack(Entity* attacker, Game_State* game_state);                                                                                                                   // LINE: 1695

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
Loot_Table Basic_Trinkets_Loot_Table(Game_State* game_state);                                                                                                                               // LINE: 71
Loot_Table Basic_Armors_Loot_Table(Game_State* game_state);                                                                                                                                 // LINE: 115
Loot_Table Basic_Weapons_Loot_Table(Game_State* game_state);                                                                                                                                // LINE: 218
void Spawn_All_Items_In_Loot_Table(Loot_Table table, Entity* room, Game_State* game_state);                                                                                                 // LINE: 256
Loot_Table Basic_Merged_Loot_Table(Game_State* game_state);                                                                                                                                 // LINE: 265
Entity* Create_Great_Sword(Entity* room, Game_State* game_state);                                                                                                                           // LINE: 286
Entity* Create_Halberd(Entity* room, Game_State* game_state);                                                                                                                               // LINE: 318
Entity* Create_Long_Spear(Entity* room, Game_State* game_state);                                                                                                                            // LINE: 351
Entity* Create_Cestus(Entity* room, Game_State* game_state);                                                                                                                                // LINE: 384
Entity* Create_War_Staff(Entity* room, Game_State* game_state);                                                                                                                             // LINE: 414
Entity* Create_Assassins_Claws(Entity* room, Game_State* game_state);                                                                                                                       // LINE: 447
Entity* Create_Staff(Entity* room, Game_State* game_state);                                                                                                                                 // LINE: 482
Entity* Create_Ram_Shield(Entity* room, Game_State* game_state);                                                                                                                            // LINE: 511
Entity* Create_Battle_Axe(Entity* room, Game_State* game_state);                                                                                                                            // LINE: 542
Entity* Create_Great_Axe(Entity* room, Game_State* game_state);                                                                                                                             // LINE: 570
Entity* Create_Gardening_Scythe(Entity* room, Game_State* game_state);                                                                                                                      // LINE: 604
Entity* Create_War_Scythe(Entity* room, Game_State* game_state);                                                                                                                            // LINE: 635
Entity* Create_Great_Club(Entity* room, Game_State* game_state);                                                                                                                            // LINE: 671
Entity* Create_Magma_Hammer(Entity* room, Game_State* game_state);                                                                                                                          // LINE: 704
Entity* Create_War_Pick(Entity* room, Game_State* game_state);                                                                                                                              // LINE: 772
Entity* Create_Straightsword(Entity* room, Game_State* game_state);                                                                                                                         // LINE: 801
Entity* Create_Whip(Entity* room, Game_State* game_state);                                                                                                                                  // LINE: 828
Entity* Create_Club(Entity* room, Game_State* game_state);                                                                                                                                  // LINE: 858
Entity* Create_Mace(Entity* room, Game_State* game_state);                                                                                                                                  // LINE: 885
Entity* Create_Rapier(Entity* room, Game_State* game_state);                                                                                                                                // LINE: 913
Entity* Create_Short_Spear(Entity* room, Game_State* game_state);                                                                                                                           // LINE: 945
Entity* Create_Morning_Star(Entity* room, Game_State* game_state);                                                                                                                          // LINE: 974
Entity* Create_Three_Headed_Flail(Entity* room, Game_State* game_state);                                                                                                                    // LINE: 1004
Entity* Create_Dagger(Entity* room, Game_State* game_state);                                                                                                                                // LINE: 1035
Entity* Create_Poison_Dagger(Entity* room, Game_State* game_state);                                                                                                                         // LINE: 1065
Entity* Create_Cape_Of_Immunity(Entity* room, Game_State* game_state);                                                                                                                      // LINE: 1118
Entity* Create_Healers_Cape(Entity* room, Game_State* game_state);                                                                                                                          // LINE: 1144
Entity* Create_Arcane_Cape(Entity* room, Game_State* game_state);                                                                                                                           // LINE: 1170
Entity* Create_Belt(Entity* room, Game_State* game_state);                                                                                                                                  // LINE: 1196
Entity* Create_Plate_Codpiece(Entity* room, Game_State* game_state);                                                                                                                        // LINE: 1222
Entity* Create_Chastity_Belt(Entity* room, Game_State* game_state);                                                                                                                         // LINE: 1248
Entity* Create_Strong_Man_Belt(Entity* room, Game_State* game_state);                                                                                                                       // LINE: 1274
Entity* Create_Belt_Of_Atlas(Entity* room, Game_State* game_state);                                                                                                                         // LINE: 1301
Entity* Create_Cape_Of_Spite(Entity* room, Game_State* game_state);                                                                                                                         // LINE: 1329
Entity* Create_Cape_Of_Avoidance(Entity* room, Game_State* game_state);                                                                                                                     // LINE: 1355
Entity* Create_Cape_Of_Dashing(Entity* room, Game_State* game_state);                                                                                                                       // LINE: 1381
Entity* Create_Backpack(Entity* room, Game_State* game_state);                                                                                                                              // LINE: 1407
Entity* Create_Ring_Of_Giants(Entity* room, Game_State* game_state);                                                                                                                        // LINE: 1436
Entity* Create_Ring_Of_Bloodshield(Entity* room, Game_State* game_state);                                                                                                                   // LINE: 1464
Entity* Create_Ring_Of_Clumsy_Regeneration(Entity* room, Game_State* game_state);                                                                                                           // LINE: 1508
Entity* Create_Ring_Of_Survival_Instinct(Entity* room, Game_State* game_state);                                                                                                             // LINE: 1552
Entity* Create_Avengers_Rings(Entity* room, Game_State* game_state);                                                                                                                        // LINE: 1577
Entity* Create_Cowards_Ring(Entity* room, Game_State* game_state);                                                                                                                          // LINE: 1602
Entity* Create_Demon_Brand(Entity* room, Game_State* game_state);                                                                                                                           // LINE: 1630
Entity* Create_Ring_Of_Quickening(Entity* room, Game_State* game_state);                                                                                                                    // LINE: 1656
Entity* Create_Ring_Of_Protection(Entity* room, Game_State* game_state);                                                                                                                    // LINE: 1681
Entity* Create_Ring_Of_Precision(Entity* room, Game_State* game_state);                                                                                                                     // LINE: 1706
Entity* Create_Ring_Of_Avoidance(Entity* room, Game_State* game_state);                                                                                                                     // LINE: 1731
Entity* Create_Ring_Of_Wrath(Entity* room, Game_State* game_state);                                                                                                                         // LINE: 1756
Entity* Create_Ring_Of_Life(Entity* room, Game_State* game_state);                                                                                                                          // LINE: 1781
Entity* Create_Ring_Of_Penetration(Entity* room, Game_State* game_state);                                                                                                                   // LINE: 1806
Entity* Create_Ring_Of_Mending(Entity* room, Game_State* game_state);                                                                                                                       // LINE: 1832
Entity* Create_Huntsmans_Ring(Entity* room, Game_State* game_state);                                                                                                                        // LINE: 1857
Entity* Create_Ring_Of_The_Reliable_Worker(Entity* room, Game_State* game_state);                                                                                                           // LINE: 1882
Entity* Create_Ring_Of_Strange_Fortunes(Entity* room, Game_State* game_state);                                                                                                              // LINE: 1907
Entity* Create_Ring_Of_Rebirth(Entity* room, Game_State* game_state);                                                                                                                       // LINE: 1933
Entity* Create_Ring_Of_False_Hope(Entity* room, Game_State* game_state);                                                                                                                    // LINE: 1994
Entity* Create_Ring_Of_Regeneration(Entity* room, Game_State* game_state);                                                                                                                  // LINE: 2054
Entity* Create_Gloves_Of_Brutality(Entity* room, Game_State* game_state);                                                                                                                   // LINE: 2100
Entity* Create_Leather_Gloves(Entity* room, Game_State* game_state);                                                                                                                        // LINE: 2127
Entity* Create_Gloves_Of_Careful_Attacking(Entity* room, Game_State* game_state);                                                                                                           // LINE: 2152
Entity* Create_Field_Medics_Gloves(Entity* room, Game_State* game_state);                                                                                                                   // LINE: 2177
Entity* Create_Chainmail_Gloves(Entity* room, Game_State* game_state);                                                                                                                      // LINE: 2204
Entity* Create_Plate_Gloves(Entity* room, Game_State* game_state);                                                                                                                          // LINE: 2230
Entity* Create_Wooden_Shield(Entity* room, Game_State* game_state);                                                                                                                         // LINE: 2259
Entity* Create_Wicker_Shield(Entity* room, Game_State* game_state);                                                                                                                         // LINE: 2286
Entity* Create_Hide_Shield(Entity* room, Game_State* game_state);                                                                                                                           // LINE: 2312
Entity* Create_Buckler(Entity* room, Game_State* game_state);                                                                                                                               // LINE: 2339
Entity* Create_Kite_Shield(Entity* room, Game_State* game_state);                                                                                                                           // LINE: 2365
Entity* Create_Barn_Door_Shield(Entity* room, Game_State* game_state);                                                                                                                      // LINE: 2392
Entity* Create_Tower_Shield(Entity* room, Game_State* game_state);                                                                                                                          // LINE: 2419
Entity* Create_Shearing_Light(Entity* room, Game_State* game_state);                                                                                                                        // LINE: 2447
Entity* Create_Leather_Cuirass(Entity* room, Game_State* game_state);                                                                                                                       // LINE: 2474
Entity* Create_Gambeson(Entity* room, Game_State* game_state);                                                                                                                              // LINE: 2500
Entity* Create_Hauberk(Entity* room, Game_State* game_state);                                                                                                                               // LINE: 2527
Entity* Create_Nobles_Armored_Garb(Entity* room, Game_State* game_state);                                                                                                                   // LINE: 2555
Entity* Create_Vest_Of_Evasion(Entity* room, Game_State* game_state);                                                                                                                       // LINE: 2585
Entity* Create_Hedgehog_Skin_Vest(Entity* room, Game_State* game_state);                                                                                                                    // LINE: 2613
Entity* Create_Precise_Jerkin(Entity* room, Game_State* game_state);                                                                                                                        // LINE: 2641
Entity* Create_Strong_Jerkin(Entity* room, Game_State* game_state);                                                                                                                         // LINE: 2669
Entity* Create_Chestguard_Of_The_Silver_Blossoms_Scout(Entity* room, Game_State* game_state);                                                                                               // LINE: 2697
Entity* Create_Treebark_Jacket(Entity* room, Game_State* game_state);                                                                                                                       // LINE: 2726
Entity* Create_Robes_Of_The_Magi(Entity* room, Game_State* game_state);                                                                                                                     // LINE: 2756
Entity* Create_Kamikaze_Shirt(Entity* room, Game_State* game_state);                                                                                                                        // LINE: 2784
Entity* Create_Harness_Of_Enslavement(Entity* room, Game_State* game_state);                                                                                                                // LINE: 2814
Entity* Create_Myconian_Chestcover(Entity* room, Game_State* game_state);                                                                                                                   // LINE: 2844
Entity* Create_Lightforged_Iron_Chestguard(Entity* room, Game_State* game_state);                                                                                                           // LINE: 2897
Entity* Create_Emergency_Vest(Entity* room, Game_State* game_state);                                                                                                                        // LINE: 2968
Entity* Create_Field_Medics_Jerkin(Entity* room, Game_State* game_state);                                                                                                                   // LINE: 3019
Entity* Create_Restorers_Battle_Armor(Entity* room, Game_State* game_state);                                                                                                                // LINE: 3046
Entity* Create_Huntsmans_Gambeson(Entity* room, Game_State* game_state);                                                                                                                    // LINE: 3096
Entity* Create_Warrior_Poncho(Entity* room, Game_State* game_state);                                                                                                                        // LINE: 3125
Entity* Create_Breastplate(Entity* room, Game_State* game_state);                                                                                                                           // LINE: 3153
Entity* Create_Assassins_Corset(Entity* room, Game_State* game_state);                                                                                                                      // LINE: 3184
Entity* Create_Knights_Breastplate(Entity* room, Game_State* game_state);                                                                                                                   // LINE: 3213
Entity* Create_Crusaders_Breastplate(Entity* room, Game_State* game_state);                                                                                                                 // LINE: 3244
Entity* Create_Skull_Cap(Entity* room, Game_State* game_state);                                                                                                                             // LINE: 3278
Entity* Create_Trueshot_Goggles(Entity* room, Game_State* game_state);                                                                                                                      // LINE: 3304
Entity* Create_Thiefs_Mask(Entity* room, Game_State* game_state);                                                                                                                           // LINE: 3333
Entity* Create_Barbarian_Head_Ornamet(Entity* room, Game_State* game_state);                                                                                                                // LINE: 3362
Entity* Create_Nobles_Helm(Entity* room, Game_State* game_state);                                                                                                                           // LINE: 3390
Entity* Create_Alchemists_Cap(Entity* room, Game_State* game_state);                                                                                                                        // LINE: 3418
Entity* Create_Crown_Of_Thorns(Entity* room, Game_State* game_state);                                                                                                                       // LINE: 3447
Entity* Create_Hood_Of_The_Golden_Order(Entity* room, Game_State* game_state);                                                                                                              // LINE: 3475
Entity* Create_Penmans_Visor(Entity* room, Game_State* game_state);                                                                                                                         // LINE: 3503
Entity* Create_Plaguedoctos_Visor(Entity* room, Game_State* game_state);                                                                                                                    // LINE: 3531
Entity* Create_Putrid_Flesh_Head_Mould(Entity* room, Game_State* game_state);                                                                                                               // LINE: 3558
Entity* Create_Monks_Headband(Entity* room, Game_State* game_state);                                                                                                                        // LINE: 3606
Entity* Create_Damaged_Tiara_Of_Divine_Protection(Entity* room, Game_State* game_state);                                                                                                    // LINE: 3633
Entity* Create_Horny_Headband(Entity* room, Game_State* game_state);                                                                                                                        // LINE: 3687
Entity* Create_Monocle_Of_Thunderstrike(Entity* room, Game_State* game_state);                                                                                                              // LINE: 3713
Entity* Create_Arming_Cap(Entity* room, Game_State* game_state);                                                                                                                            // LINE: 3794
Entity* Create_Hide_Helmet(Entity* room, Game_State* game_state);                                                                                                                           // LINE: 3819
Entity* Create_Wooden_Helmet(Entity* room, Game_State* game_state);                                                                                                                         // LINE: 3844
Entity* Create_Bucket(Entity* room, Game_State* game_state);                                                                                                                                // LINE: 3870
Entity* Create_Sack(Entity* room, Game_State* game_state);                                                                                                                                  // LINE: 3898
Entity* Create_Chainmail_Hood(Entity* room, Game_State* game_state);                                                                                                                        // LINE: 3925
Entity* Create_Barbute(Entity* room, Game_State* game_state);                                                                                                                               // LINE: 3951
Entity* Create_Leather_Tights(Entity* room, Game_State* game_state);                                                                                                                        // LINE: 3981
Entity* Create_Padded_Pants(Entity* room, Game_State* game_state);                                                                                                                          // LINE: 4006
Entity* Create_Workers_Trousers(Entity* room, Game_State* game_state);                                                                                                                      // LINE: 4031
Entity* Create_Junk_Metal_Leg_Guards(Entity* room, Game_State* game_state);                                                                                                                 // LINE: 4056
Entity* Create_Plate_Leggings(Entity* room, Game_State* game_state);                                                                                                                        // LINE: 4086
Entity* Create_Warrior_Kilt(Entity* room, Game_State* game_state);                                                                                                                          // LINE: 4116
Entity* Create_Burglars_Leggings(Entity* room, Game_State* game_state);                                                                                                                     // LINE: 4143
Entity* Create_Historians_Skirt(Entity* room, Game_State* game_state);                                                                                                                      // LINE: 4170
Entity* Create_Berserkers_Leggings(Entity* room, Game_State* game_state);                                                                                                                   // LINE: 4197
Entity* Create_Pants_Of_The_Jack(Entity* room, Game_State* game_state);                                                                                                                     // LINE: 4224
Entity* Create_Trousers_Of_The_Doomwalker(Entity* room, Game_State* game_state);                                                                                                            // LINE: 4261
Entity* Create_Feralhearth_Pants(Entity* room, Game_State* game_state);                                                                                                                     // LINE: 4328
Entity* Create_Pants_Of_Holy_Avoidance(Entity* room, Game_State* game_state);                                                                                                               // LINE: 4357
Entity* Create_Battle_Medics_Trousers(Entity* room, Game_State* game_state);                                                                                                                // LINE: 4419
Entity* Create_Legguards_Of_Magical_Grounding(Entity* room, Game_State* game_state);                                                                                                        // LINE: 4448
Entity* Create_Bulwark_Legplates(Entity* room, Game_State* game_state);                                                                                                                     // LINE: 4477
Entity* Create_Leggings_Of_Furious_Recovery(Entity* room, Game_State* game_state);                                                                                                          // LINE: 4510
Entity* Create_Barbarian_Loincloth(Entity* room, Game_State* game_state);                                                                                                                   // LINE: 4560
Entity* Create_Travel_Boots(Entity* room, Game_State* game_state);                                                                                                                          // LINE: 4589
Entity* Create_Sabatons(Entity* room, Game_State* game_state);                                                                                                                              // LINE: 4617
Entity* Create_Knights_Plate_Boots(Entity* room, Game_State* game_state);                                                                                                                   // LINE: 4647
Entity* Create_Mountaineer_Boots(Entity* room, Game_State* game_state);                                                                                                                     // LINE: 4677
Entity* Create_Gladiator_Sandals(Entity* room, Game_State* game_state);                                                                                                                     // LINE: 4704
Entity* Create_Leather_Boots(Entity* room, Game_State* game_state);                                                                                                                         // LINE: 4733
Entity* Create_Antidote(Entity* container, Game_State* game_state);                                                                                                                         // LINE: 4758
Entity* Create_Cure(Entity* container, Game_State* game_state);                                                                                                                             // LINE: 4798
Entity* Create_Bandage(Entity* container, Game_State* game_state);                                                                                                                          // LINE: 4838
Entity* Create_Dispeller(Entity* container, Game_State* game_state);                                                                                                                        // LINE: 4878
Entity* Create_Speed_Elixir(Entity* container, Game_State* game_state);                                                                                                                     // LINE: 4918
Entity* Create_Might_Elixir(Entity* container, Game_State* game_state);                                                                                                                     // LINE: 4965
Entity* Create_Accuracy_Elixir(Entity* container, Game_State* game_state);                                                                                                                  // LINE: 5012
Entity* Create_Dodge_Elixir(Entity* container, Game_State* game_state);                                                                                                                     // LINE: 5059
Entity* Create_Vitality_Elixir(Entity* container, Game_State* game_state);                                                                                                                  // LINE: 5106
Entity* Create_Immunity_Elixir(Entity* container, Game_State* game_state);                                                                                                                  // LINE: 5153
Entity* Create_Arcane_Elixir(Entity* container, Game_State* game_state);                                                                                                                    // LINE: 5200
Entity* Create_Healing_Potion(Entity* container, Game_State* game_state);                                                                                                                   // LINE: 5247
Entity* Create_Acid_Flask(Entity* container, Game_State* game_state);                                                                                                                       // LINE: 5288
Entity* Create_Sticky_Goo(Entity* container, Game_State* game_state);                                                                                                                       // LINE: 5342
Entity* Create_Bauble_Of_Bomb_Craft(Entity* container, Game_State* game_state);                                                                                                             // LINE: 5396
Entity* Create_Bauble_Of_Potion_Craft(Entity* container, Game_State* game_state);                                                                                                           // LINE: 5450
Entity* Create_Restoration_Potion(Entity* container, Game_State* game_state);                                                                                                               // LINE: 5504
Entity* Create_Herbal_Remedy(Entity* container, Game_State* game_state);                                                                                                                    // LINE: 5573
Entity* Create_Bomb(Entity* container, Game_State* game_state);                                                                                                                             // LINE: 5610
Entity* Create_Fragmentation_Bomb(Entity* container, Game_State* game_state);                                                                                                               // LINE: 5656
Entity* Create_Mushroom(Entity* room, Game_State* game_state);                                                                                                                              // LINE: 5725
Entity* Create_Jerky(Entity* room, Game_State* game_state);                                                                                                                                 // LINE: 5738
Entity* Create_Bread(Entity* room, Game_State* game_state);                                                                                                                                 // LINE: 5751
Entity* Create_BBQ_Wings(Entity* room, Game_State* game_state);                                                                                                                             // LINE: 5764
Entity* Create_Steak_And_Smashed_Potatoes(Entity* room, Game_State* game_state);                                                                                                            // LINE: 5777
Entity* Create_Ring_Of_Just_Fucking_Crit(Entity* room, Game_State* game_state);                                                                                                             // LINE: 5792

// FILE: src\Factory.cpp:
Entity* Create_Class_Adventurer(Game_State* game_state);                                                                                                                                    // LINE: 40
Entity* Create_Class_Mountaineer(Game_State* game_state);                                                                                                                                   // LINE: 86
Entity* Create_Class_Wretched(Game_State* game_state);                                                                                                                                      // LINE: 122
Entity* Create_Goblin(Entity* room, Game_State* game_state);                                                                                                                                // LINE: 144
Entity* Create_Orc(Entity* room, Game_State* game_state);                                                                                                                                   // LINE: 253
Entity* Create_Bandit(Entity* room, Game_State* game_state);                                                                                                                                // LINE: 358
Entity* Create_Skeleton(Entity* room, Game_State* game_state);                                                                                                                              // LINE: 440
Entity* Create_Bandit_Leader(Entity* room, Game_State* game_state);                                                                                                                         // LINE: 522
Entity* Create_Assassin(Entity* room, Game_State* game_state);                                                                                                                              // LINE: 604
Entity* Create_Bandit_King(Entity* room, Game_State* game_state);                                                                                                                           // LINE: 680
Entity* Create_Concubine(Entity* room, Game_State* game_state);                                                                                                                             // LINE: 731
Entity* Create_Giant_Honey_Badger(Entity* room, Game_State* game_state);                                                                                                                    // LINE: 838
Entity* Create_Living_Vine(Entity* room, Game_State* game_state);                                                                                                                           // LINE: 925
Entity* Create_Vineling(Entity* room, Game_State* game_state);                                                                                                                              // LINE: 983
Entity* Create_Leech(Entity* room, Game_State* game_state);                                                                                                                                 // LINE: 1054
Entity* Create_Giant_Toad(Entity* room, Game_State* game_state);                                                                                                                            // LINE: 1112
Entity* Create_Mosquito(Entity* room, Game_State* game_state);                                                                                                                              // LINE: 1173
Entity* Create_Wolf(Entity* room, Game_State* game_state);                                                                                                                                  // LINE: 1237
Entity* Create_Hound(Entity* room, Game_State* game_state);                                                                                                                                 // LINE: 1299
Entity* Create_Fae_Flayer(Entity* room, Game_State* game_state);                                                                                                                            // LINE: 1361
Entity* Create_Salamander(Entity* room, Game_State* game_state);                                                                                                                            // LINE: 1429
Entity* Create_Earth_Golem(Entity* room, Game_State* game_state);                                                                                                                           // LINE: 1494
Entity* Create_Small_Earth_Golem(Entity* room, Game_State* game_state);                                                                                                                     // LINE: 1544
Entity* Create_Tiny_Earth_Golem(Entity* room, Game_State* game_state);                                                                                                                      // LINE: 1594
Entity* Create_Giant_Rat(Entity* room, Game_State* game_state);                                                                                                                             // LINE: 1644
Entity* Create_Blight_Rat(Entity* room, Game_State* game_state);                                                                                                                            // LINE: 1708
Entity* Create_Enlarged_Ant(Entity* room, Game_State* game_state);                                                                                                                          // LINE: 1830
Entity* Create_Enlarged_Ant_Queen(Entity* room, Game_State* game_state);                                                                                                                    // LINE: 1880
Entity* Create_Bear_Cub(Entity* room, Game_State* game_state);                                                                                                                              // LINE: 1961
Entity* Create_Cave_Bear(Entity* room, Game_State* game_state);                                                                                                                             // LINE: 2026
Entity* Create_Mutant_Hedgehog(Entity* room, Game_State* game_state);                                                                                                                       // LINE: 2093
Entity* Create_Clear_Ambush_Table_Dummy_Entity(Entity* room, Game_State* game_state);                                                                                                       // LINE: 2179
Entity* Create_Mimic(Entity* room, Game_State* game_state);                                                                                                                                 // LINE: 2188
Entity* Create_Chest(Entity* room, Game_State* game_state);                                                                                                                                 // LINE: 2287
Entity* Create_Weapon_Rack(Entity* room, Game_State* game_state);                                                                                                                           // LINE: 2336
Entity* Create_Armor_Rack(Entity* room, Game_State* game_state);                                                                                                                            // LINE: 2369
Entity* Create_Bookshelf(Entity* room, Game_State* game_state);                                                                                                                             // LINE: 2402
Entity* Create_Supply_Crate(Entity* room, Game_State* game_state);                                                                                                                          // LINE: 2435
Entity* Create_Alchemists_Pouch(Entity* room, Game_State* game_state);                                                                                                                      // LINE: 2481
Entity* Create_Rat_Mound(Entity* room, Game_State* game_state);                                                                                                                             // LINE: 2515
Entity* Create_Spider_Egg(Entity* room, Game_State* game_state);                                                                                                                            // LINE: 2576
Entity* Create_Snake(Entity* room, Game_State* game_state);                                                                                                                                 // LINE: 2628
Entity* Create_Scorpion(Entity* room, Game_State* game_state);                                                                                                                              // LINE: 2688
Entity* Create_Spiderling(Entity* room, Game_State* game_state);                                                                                                                            // LINE: 2748
Entity* Create_Toxic_Lurker(Entity* room, Game_State* game_state);                                                                                                                          // LINE: 2802
Entity* Create_Hunter_Arachnid(Entity* room, Game_State* game_state);                                                                                                                       // LINE: 2869
Entity* Create_Bladedance_Spider(Entity* room, Game_State* game_state);                                                                                                                     // LINE: 2936
Entity* Create_Random_Spider(Entity* room, Game_State* game_state);                                                                                                                         // LINE: 3002
Entity* Create_Random_Rat(Entity* room, Game_State* game_state);                                                                                                                            // LINE: 3028
Entity* Create_Boss_Spider(Entity* room, Game_State* game_state);                                                                                                                           // LINE: 3045
void Generate_Standard_Random_Loot(Entity* container, Game_State* game_state);                                                                                                              // LINE: 3096

// FILE: src\Caves.cpp:
void Generate_Entrance_Room(Entity* room, Game_State* game_state);                                                                                                                          // LINE: 9
Loot_Table Caves_Wildlife_Section(Game_State* game_state);                                                                                                                                  // LINE: 89
Loot_Table Caves_Bandit_Section(Game_State* game_state);                                                                                                                                    // LINE: 967
Loot_Table Caves_Spider_Section(Game_State* game_state);                                                                                                                                    // LINE: 1471
Loot_Table Caves_Boss(Game_State* game_state);                                                                                                                                              // LINE: 1765
_inline Level_Segments Caves(Game_State* game_state);                                                                                                                                       // LINE: 1800

// FILE: src\Dungeon.cpp:
char* Get_Output_Color_CSTR(ANSI_Color_Buffer* buffer, u8 red, u8 green, u8 blue);                                                                                                          // LINE: 88
char* Entity_Color(Entity* entity, Game_State* game_state);                                                                                                                                 // LINE: 98
String Format_Message(Game_State* game_state, char* format_string, ...);                                                                                                                    // LINE: 125
_inline void Flush_Messages(Game_State* game_state);                                                                                                                                        // LINE: 144
_inline void Print_Messages(Game_State* game_state);                                                                                                                                        // LINE: 151
void Push_Message(String message, Game_State* game_state);                                                                                                                                  // LINE: 171
void Wait(f64 seconds, Game_State* game_state, Forced::T forced = Forced::T(0));                                                                                                            // LINE: 186
String Get_User_Input(Game_State* game_state);                                                                                                                                              // LINE: 195
bool User_Query_Yes_No(Game_State* game_state);                                                                                                                                             // LINE: 214
u64 Base_Alphabet_Digits(u64 v);                                                                                                                                                            // LINE: 248
u64 Encode_Base_Alphabet(u64 identity, char character);                                                                                                                                     // LINE: 268
U64_To_String_Memory Decode_Base_Aplhabet(u64 identity);                                                                                                                                    // LINE: 279
Entity_Offset* Find_Empty_Slot(Entity_Node* node);                                                                                                                                          // LINE: 298
Ambush_Creature_Spawner_Offset Offset(Ambush_Creature_Spawner* pointer, Game_State* game_state);                                                                                            // LINE: 323
Ambush_Creature_Spawner* Pointer(Ambush_Creature_Spawner_Offset offset, Game_State* game_state);                                                                                            // LINE: 335
Ambush_Option_Offset Offset(Ambush_Option* pointer, Game_State* game_state);                                                                                                                // LINE: 347
Ambush_Option* Pointer(Ambush_Option_Offset offset, Game_State* game_state);                                                                                                                // LINE: 359
_inline Entity_Offset Offset(Entity* entity, Game_State* game_state);                                                                                                                       // LINE: 371
_inline Entity* Pointer(Entity_Offset offset, Game_State* game_state);                                                                                                                      // LINE: 383
_inline Effect_Offset Offset(Effect* effect, Game_State* game_state);                                                                                                                       // LINE: 399
_inline Effect* Pointer(Effect_Offset offset, Game_State* game_state);                                                                                                                      // LINE: 412
_inline Entity_Node_Offset Offset(Entity_Node* entity_node, Game_State* game_state);                                                                                                        // LINE: 425
_inline Entity_Node* Pointer(Entity_Node_Offset offset, Game_State* game_state);                                                                                                            // LINE: 437
_inline Effects_Node_Offset Offset(Effects_Node* effects_node, Game_State* game_state);                                                                                                     // LINE: 449
_inline Effects_Node* Pointer(Effects_Node_Offset offset, Game_State* game_state);                                                                                                          // LINE: 461
String Unwrap_String(String_Wrapper* strw, Game_State* game_state);                                                                                                                         // LINE: 473
String_Offset Offset(String str, Game_State* game_state);                                                                                                                                   // LINE: 481
String Get_String(String_Offset offset, Game_State* game_state);                                                                                                                            // LINE: 565
_inline u64 Storage_Offset(void* ptr, Game_State* game_state);                                                                                                                              // LINE: 591
_inline void* Pull_From_Storage_Offset(u64 offset, Game_State* game_state);                                                                                                                 // LINE: 604
Entity_Offset* Find_Entity(Entity* entity, Entity_Root_Node* storage, Game_State* game_state, Entity_Node** out_node = 0);                                                                  // LINE: 617
Entity* Find_Entity_By_Name_Or_Reference_Number(Entity* actor, Entity_Offset space, String name_or_reference_number, Game_State* game_state, Verbose::T verbose = Verbose::T(1));           // LINE: 644
Entity* Find_Entity_By_Name(Entity* actor, Entity* space, String name, Game_State* game_state, Verbose::T verbose = Verbose::T(1));                                                         // LINE: 656
Entity* Find_Entity_By_Name_Or_Reference_Number(Entity* actor, Entity* space, String name_or_reference_number, Game_State* game_state, Verbose::T verbose = Verbose::T(1));                 // LINE: 688
Entity* Find_Entity_By_Name_Or_Reference_Number2(Entity* actor, Entity* space, String* in_out_args, Game_State* game_state, Verbose::T verbose);                                            // LINE: 729
Entity_Iterator Make_Iterator(Entity_Root_Node* root, Game_State* game_state);                                                                                                              // LINE: 815
Entity_Iterator Make_Iterator(Entity* entity, Game_State* game_state);                                                                                                                      // LINE: 833
Effects_Iterator Make_Iterator(Effects_Root* root, Game_State* game_state);                                                                                                                 // LINE: 841
Entity_Offset* Next(Entity_Iterator* iter);                                                                                                                                                 // LINE: 860
Entity* Next_Entity(Entity_Iterator* iter);                                                                                                                                                 // LINE: 890
u64 Count(Entity_Root_Node* root_node, Game_State* game_state);                                                                                                                             // LINE: 904
bool Memory_Snapshot_Save(String file_path, Game_State* game_state);                                                                                                                        // LINE: 917
bool Memory_Snapshot_Restore(String file_path, Game_State* game_state);                                                                                                                     // LINE: 926
Effect_Instance* Next_Effect_Instance(Effects_Iterator* iter);                                                                                                                              // LINE: 958
_inline Effect_Instance* Next(Effects_Iterator* iter);                                                                                                                                      // LINE: 991
Effect* Next_Effect(Effects_Iterator* iter);                                                                                                                                                // LINE: 998
Backwards_Iterator Make_Backwards_Iterator(Entity_Root_Node* root, Game_State* game_state);                                                                                                 // LINE: 1012
Entity_Offset* Previous(Backwards_Iterator* back_iter);                                                                                                                                     // LINE: 1026
void Add_Dice(Effect* effect, s16 count, s16 faces);                                                                                                                                        // LINE: 1070
u64 Per_Count_Rolled_Square_Weighted_Random(u64 count, Game_State* game_state);                                                                                                             // LINE: 1099
u64 Per_Count_Rolled_Random(u64 count, u32 change, Game_State* game_state);                                                                                                                 // LINE: 1114
u32 Roll(u32 range, Game_State* game_state);                                                                                                                                                // LINE: 1129
s32 Roll(Dice dice, Game_State* game_state);                                                                                                                                                // LINE: 1141
s32* Roll_With_Record(Dice dice, Game_State* game_state);                                                                                                                                   // LINE: 1157
f32 Random_F32(Game_State* game_state);                                                                                                                                                     // LINE: 1171
Roll_Result Stat_Roll(s32 value, Stats::T stat, Game_State* game_state);                                                                                                                    // LINE: 1181
s32 Value(Roll_Result rr);                                                                                                                                                                  // LINE: 1197
Roll_Result Stat_Roll(Entity* entity, Stats::T stat, Game_State* game_state);                                                                                                               // LINE: 1204
_inline bool Is_Rolled(Roll_Result rr);                                                                                                                                                     // LINE: 1215
void Print_Dice(Dice dice, s32 result);                                                                                                                                                     // LINE: 1222
void Print_Roll_Result(Roll_Result rr);                                                                                                                                                     // LINE: 1228
void Print_Attack_Record(Attack_Record* ar, Game_State* game_state);                                                                                                                        // LINE: 1241
String Name_Without_Color(Entity* entity, Game_State* game_state);                                                                                                                          // LINE: 1505
String Name(Entity* entity, Game_State* game_state);                                                                                                                                        // LINE: 1520
char* Action_Name(AT::T action);                                                                                                                                                            // LINE: 1540
void Print_Required_Equipment_Slots(Entity* item);                                                                                                                                          // LINE: 1567
s32 Potency(String name, s32 base, Game_State* game_state);                                                                                                                                 // LINE: 1591
s32 Potency(String name, s32 base, Dice dice, Game_State* game_state);                                                                                                                      // LINE: 1604
void Push_Generic_Apply_Effect_Message(String source_name, Entity* target, Effect_Instance new_effect, Apply_Effect_Result apply, Game_State* game_state);                                  // LINE: 1673
void Remove_From_Residence(Entity* entity, Game_State* game_state);                                                                                                                         // LINE: 1729
void Release_Entity_Node(Entity_Root_Node* root, Game_State* game_state);                                                                                                                   // LINE: 1763
Entity_Node* Request_Entity_Node(Game_State* game_state);                                                                                                                                   // LINE: 1785
Effect* Request_Effect(Game_State* game_state);                                                                                                                                             // LINE: 1802
void Release_Effect(Effect* effect, Game_State* game_state);                                                                                                                                // LINE: 1825
Entity* Request_Entity(Game_State* game_state);                                                                                                                                             // LINE: 1839
void Release_Entity(Entity* entity, Game_State* game_state);                                                                                                                                // LINE: 1861
Effects_Node* Request_Effects_Node(Game_State* game_state);                                                                                                                                 // LINE: 1869
void Release_Effects_Node(Effects_Node* node, Game_State* game_state);                                                                                                                      // LINE: 1886
void Insert(Entity* entity, Entity_Root_Node* storage, Game_State* game_state);                                                                                                             // LINE: 1894
void Assign_Dublicate_Name_Identifier(Entity* entity_to_insert, Entity* storage, Game_State* game_state);                                                                                   // LINE: 1931
void Finalize_Entity(Entity* entity, Entity* container, Game_State* game_state);                                                                                                            // LINE: 1965
void Deep_Insert(Entity* entity, Entity* storage_entity, Game_State* game_state, Assign_Dublicate_Identifier::T assign_dublicate_identifier = Assign_Dublicate_Identifier::T(1));           // LINE: 1977
bool Contains_An_Active_Hostile(Entity* room, Entity* actor, Game_State* game_state);                                                                                                       // LINE: 2005
bool Residence_Contains_An_Active_Hostile(Entity* actor, Game_State* game_state);                                                                                                           // LINE: 2022
Ambush_Option* Request_Ambush_Option(Game_State* game_state);                                                                                                                               // LINE: 2032
void Release_Ambush_Option(Ambush_Option* ambush_option, Game_State* game_state);                                                                                                           // LINE: 2049
Ambush_Creature_Spawner* Request_Ambush_Creature_Spawner(Game_State* game_state);                                                                                                           // LINE: 2057
void Release_Ambush_Creature_Spawner(Ambush_Creature_Spawner* spawner, Game_State* game_state);                                                                                             // LINE: 2074
Ambush_Option* Create_Ambush_Option(f32 change, Game_State* game_state);                                                                                                                    // LINE: 2082
void Add_Ambush_Creature_Spawner(Ambush_Option* ambush, Ambush_Creature_Spawner spawner, Game_State* game_state);                                                                           // LINE: 2093
void Reset_Ambush_Table(Game_State* game_state);                                                                                                                                            // LINE: 2102
void Set_Ambush_Change(f32 change, Game_State* game_state);                                                                                                                                 // LINE: 2124
bool Trigger_Ambush(Entity* room, Game_State* game_state, Entity*** out_spawned_entities, u64* out_spawned_count);                                                                          // LINE: 2130
bool Is_The_Same(Entity* A, Entity* B, Game_State* game_state);                                                                                                                             // LINE: 2195
void Remove_All_Effects(Entity* entity, Game_State* game_state);                                                                                                                            // LINE: 2226
void Delete_Entity(Entity* entity, Game_State* game_state);                                                                                                                                 // LINE: 2286
bool Has_Content(Entity_Root_Node* root);                                                                                                                                                   // LINE: 2293
bool Is_Empty(Entity_Root_Node* root);                                                                                                                                                      // LINE: 2300
s32 Get_Stat_Value(Entity* entity, Stats::T stat, Game_State* game_state, u64* out_effect_count = 0);                                                                                       // LINE: 2313
void Ding(Entity* actor, Game_State* game_state);                                                                                                                                           // LINE: 2360
s32 Exp_To_Level_Up(s32 _lvl);                                                                                                                                                              // LINE: 2407
_inline s32 Exp_To_Level_Up(Entity* entity);                                                                                                                                                // LINE: 2415
s16 Calculate_Level(Entity* entity);                                                                                                                                                        // LINE: 2422
void Set_Level_Based_On_Stats(Entity* entity);                                                                                                                                              // LINE: 2437
s32 Exp_Reward(Entity* entity);                                                                                                                                                             // LINE: 2444
s16 Level(Entity* entity);                                                                                                                                                                  // LINE: 2458
s32 Max_Health(Entity* entity, Game_State* game_state);                                                                                                                                     // LINE: 2465
f32 Critical_Multiplier(Entity* entity, Game_State* game_state);                                                                                                                            // LINE: 2500
s32 Carry_Capacity(Entity* entity, Game_State* game_state);                                                                                                                                 // LINE: 2507
s32 Carrying_Amount(Entity* entity, Game_State* game_state);                                                                                                                                // LINE: 2527
f32 Threat(Entity* entity);                                                                                                                                                                 // LINE: 2540
Critical_Ranges_Result Critical_Ranges(Entity* entity, Game_State* game_state, u32* out_success_effecting_count = 0, u32* out_failure_effecing_count = 0);                                  // LINE: 2547
void Full_Heal(Entity* entity, Game_State* game_state);                                                                                                                                     // LINE: 2589
bool Is_Item(Entity* entity);                                                                                                                                                               // LINE: 2595
bool Is_Visible(Entity* entity, Entity* actor, Game_State* game_state);                                                                                                                     // LINE: 2602
bool Is_Alive(Entity* entity);                                                                                                                                                              // LINE: 2611
bool Is_Hostile_Against(Entity* A, Entity* B);                                                                                                                                              // LINE: 2618
bool Is_Living_Enemy_Of(Entity* actor, Entity* target);                                                                                                                                     // LINE: 2629
bool Is_Living_Active_Enemy_Of(Entity* actor, Entity* target);                                                                                                                              // LINE: 2636
s32 Give_Temporary_Health(Entity* entity, s32 amount, String source_name, Verbose::T verbose, Game_State* game_state);                                                                      // LINE: 2643
Healing_Result Heal(Entity* entity, s32 amount, String source_name, Verbose::T verbose, Game_State* game_state);                                                                            // LINE: 2676
Deal_Damage_Result Deal_Damage(Entity* defender, Entity_Offset attacker_offset, String source_name, s32 dmg, s32 pierce, Damage_Type type, Game_State* game_state, Verbose::T verbose);     // LINE: 2771
_inline Deal_Damage_Result Deal_Damage(Entity* defender, Entity* attacker, String dmg_src_name, s32 dmg, s32 pierce, Damage_Type type, Game_State* game_state, Verbose::T verbose);         // LINE: 2980
void Proc_Effects(u64 offset, Entity* attacker, Entity* defender, Attack_Record* ar, Game_State* game_state);                                                                               // LINE: 2988
void Proc_Effects(u64 offset, Entity* target, Game_State* game_state);                                                                                                                      // LINE: 3005
String Effect_Name(Effect_Instance* instance, Game_State* game_state);                                                                                                                      // LINE: 3021
u64 Count_Effect_Instances(Effects_Root* root, Effect_Instance cmp, Game_State* game_state, Effect_Instance** out_shortest_duration = 0);                                                   // LINE: 3041
void Delete_Effect_Slot(Entity* actor, Effects_Root* root, Effects_Node* node, u64 *idx, u64* count, Game_State* game_state);                                                               // LINE: 3071
Effect_Instance* New_Effect_Slot(Effects_Root* root, Game_State* game_state);                                                                                                               // LINE: 3113
Apply_Check_Record Application_Check(Entity* attacker, Entity* defender, Game_State* game_state);                                                                                           // LINE: 3159
void Attempt_Infection(Entity* attacker, Entity* defender, String source_name, Effect_Instance infectious_effect_instance, Game_State* game_state);                                         // LINE: 3172
Apply_Effect_Result Apply_Effect(Entity* target, Effect_Instance instance, Game_State* game_state, Forced::T forced = Forced::T(0));                                                        // LINE: 3205
void Remove_Effects_From_Source(Entity* actor, Entity* source, Game_State* game_state);                                                                                                     // LINE: 3280
u64 Remove_Effects_Of_Type(Entity* actor, Effect_Type::T type_to_remove, Game_State* game_state, Verbose::T verbose);                                                                       // LINE: 3305
void Print_Equiped_Weapons(Entity* target, bool preamble, Game_State* game_state);                                                                                                          // LINE: 3583
void Inspect(Entity* target, Game_State* game_state);                                                                                                                                       // LINE: 3621
bool Is_Equipped(Entity* actor, Entity* item, Game_State* game_state);                                                                                                                      // LINE: 3706
bool Unequip(Entity* actor, Entity* item, Game_State* game_state);                                                                                                                          // LINE: 3729
bool Unequip(Entity* item, Game_State* game_state);                                                                                                                                         // LINE: 3753
bool Is_On_CD(Interactable* inter, Game_State* game_state, u64* out_cd = 0);                                                                                                                // LINE: 3761
bool Use(Entity* actor, Entity* item, Game_State* game_state, Verbose::T verbose);                                                                                                          // LINE: 3802
void Inventory(Entity* actor, Game_State* game_state);                                                                                                                                      // LINE: 3863
void List_Active_Effects(Entity* actor, Game_State* game_state);                                                                                                                            // LINE: 4037
bool Equip(Entity* actor, Entity* target, Game_State* game_state, Verbose::T verbose = Verbose::T(0));                                                                                      // LINE: 4075
void Print_Uses(Entity* entity);                                                                                                                                                            // LINE: 4302
void Open(Entity* actor, Game_State* game_state);                                                                                                                                           // LINE: 4322
u64 Longest_Visible_Entity_Name_In_Actor_Storage(Entity* actor, Game_State* game_state, u64* out_count = 0);                                                                                // LINE: 4350
bool Glance(Entity* actor, Game_State* game_state, Report_Turn_Taken_Status::T report_turn_taken_status = Report_Turn_Taken_Status::T(1));                                                  // LINE: 4375
void Remove_Random_Effect(Entity* entity, String source_name, Game_State* game_state);                                                                                                      // LINE: 4468
Damage_Modifiers_Result Damage_Modifier_From_Effects(Entity* attacker, Attack_Record* ar, Game_State* game_state);                                                                          // LINE: 4507
u64 Attack_Modifier_Mask(Attack_Mod::T modifier);                                                                                                                                           // LINE: 4615
u64 Class_Mask(Class::T _class);                                                                                                                                                            // LINE: 4622
bool Can_Use_Attack_Modifier(Entity* entity, Attack_Mod::T modifier);                                                                                                                       // LINE: 4629
void Apply_Or_Describe_Attak_Modifier(Entity** attacker_ptr, Entity** defender_ptr, Attack_Mod::T modifier, Game_State* game_state);                                                        // LINE: 4640
void Proc_Thorns(Entity* attacker, Entity* defender, Game_State* game_state);                                                                                                               // LINE: 4787
void Attack(Entity* attacker, Entity* defender, Game_State* game_state, Attack_Mod::T modifier = Attack_Mod::T(0));                                                                         // LINE: 4810
void Player_Action(Entity* actor, String actor_name, Game_State* game_state);                                                                                                               // LINE: 4893
Entity* Redirected_Target(Entity* actor, String actor_name, Game_State* game_state);                                                                                                        // LINE: 4982
Entity* Random_Entity_That_Matches_Criteria(Entity_Root_Node* storage, bool(*conditional)(Entity* entity, void* user_ptr, Game_State* game_state), void* user_ptr, Game_State* game_state); // LINE: 5020
Entity* Find_Attack_Target(Entity* actor, Game_State* game_state);                                                                                                                          // LINE: 5059
void NPC_Action(Entity* actor, String actor_name, Game_State* game_state);                                                                                                                  // LINE: 5117
void Take_Action(Entity* actor, Game_State* game_state);                                                                                                                                    // LINE: 5195
u64 Hash_From_Key(Effect_Hash_Key key);                                                                                                                                                     // LINE: 5267
bool Retrive_Effect(Effect_Hash_Key key, Effect_Offset* out, Game_State* game_state);                                                                                                       // LINE: 5274
Effect_Offset Insert_Effect(Effect effect, Effect_Hash_Key key, Game_State* game_state);                                                                                                    // LINE: 5312
bool Compare(s64 X, Comparison type, s64 A, s64 B = 0);                                                                                                                                     // LINE: 5350
bool Is_Compliant(Loot_Table_Entry entry, Pick_From_Table_Rules rules);                                                                                                                     // LINE: 5380
Loot_Table_Pick_Result Pick_From_Loot_Table(Loot_Table table, u64 count, Pick_From_Table_Rules rules, Game_State* game_state);                                                              // LINE: 5409
GENERATE_ENTITY_FN* Pick_From_Loot_Table(Loot_Table table, Pick_From_Table_Rules rules, Game_State* game_state);                                                                            // LINE: 5461
void Generate_From_Loot_Table(Entity* storage, Loot_Table table, u64 count, Pick_From_Table_Rules rules, Game_State* game_state);                                                           // LINE: 5468
Loot_Table Merge_Loot_Tables(Loot_Table* tables, u64 count, Arena* arena);                                                                                                                  // LINE: 5478
_inline Loot_Table Merge_Loot_Tables_Internal(Loot_Table A, Loot_Table B, Arena* arena);                                                                                                    // LINE: 5492
Loot_Table Merge_Loot_Tables(Loot_Table A, Loot_Table B, Arena* arena);                                                                                                                     // LINE: 5509
Loot_Table Merge_Loot_Tables(Loot_Table A, Loot_Table B, Loot_Table C, Arena* arena);                                                                                                       // LINE: 5517
Loot_Table Merge_Loot_Tables(Loot_Table A, Loot_Table B, Loot_Table C, Loot_Table D, Arena* arena);                                                                                         // LINE: 5525
Loot_Table Merge_Loot_Tables(Loot_Table A, Loot_Table B, Loot_Table C, Loot_Table D, Loot_Table E, Arena* arena);                                                                           // LINE: 5533
Loot_Table Merge_Loot_Tables(Loot_Table A, Loot_Table B, Loot_Table C, Loot_Table D, Loot_Table E, Loot_Table F, Arena* arena);                                                             // LINE: 5541
void Normalize_Loot_Table_Changes(Loot_Table* table);                                                                                                                                       // LINE: 5549
f32 Standard_Drop_Change_Based_On_Rarity(Rarity::T rarity);                                                                                                                                 // LINE: 5559
void Fill_Loot_Table_Changes_And_Item_Rarity(Loot_Table* table, Game_State* game_state);                                                                                                    // LINE: 5604
bool Roll_Initiative(Entity* entity, Game_State* game_state);                                                                                                                               // LINE: 5646
void Sort_Iniative_Order(Entity_Offset* offs, Game_State* game_state);                                                                                                                      // LINE: 5680
void Sort_Space(Entity_Root_Node* space, Game_State* game_state);                                                                                                                           // LINE: 5811
u64 Count_Longest_Round_Effect_Duration(Entity* actor, Game_State* game_state);                                                                                                             // LINE: 5887
void Tick_Down_Effect_Durations(Entity* actor, Duration_Type type, Game_State* game_state);                                                                                                 // LINE: 5902
_inline void Enter_A_Room_Printout(Entity* player, Entity* room, Game_State* game_state);                                                                                                   // LINE: 5976
CMD_Result::T Attempt_To_Execute_Command(Command* commands, u64 count, String user_input, void* user_ptr, Game_State* game_state);                                                          // LINE: 5999
CMD_Result::T Prompt_User_For_Command_And_Attempt_To_Execute(Command* commands, u64 count, void* user_ptr, Game_State* game_state);                                                         // LINE: 6105
void Create_Player_Charater(Game_State* game_state);                                                                                                                                        // LINE: 6113
void Tick_Active_Effects_Down_To_Zero(Entity* actor, Game_State* game_state);                                                                                                               // LINE: 6331
Entity* Next_Room(Level_Segments level, Game_State* game_state);                                                                                                                            // LINE: 6356
void Proceed(Game_State* game_state);                                                                                                                                                       // LINE: 6403
void Prepare_Game_Round(Game_State* game_state);                                                                                                                                            // LINE: 6472
void Excecute_Game_Round(Game_State* game_state);                                                                                                                                           // LINE: 6585
void Exit_Handling(Game_State* game_state);                                                                                                                                                 // LINE: 6623
bool Play_Game(Game_State* game_state);                                                                                                                                                     // LINE: 6655
void Reset_Game_State(Game_State* game_state);                                                                                                                                              // LINE: 6685
Game_State* Create_Game_State();                                                                                                                                                            // LINE: 6741
CMD_Result::T Kill_Command(Entity* actor, String args, Game_State* game_state);                                                                                                             // LINE: 6772
CMD_Result::T Toggle_Dramatic_Pause(Entity* actor, String args, Game_State* game_state);                                                                                                    // LINE: 6799
CMD_Result::T Toggle_Godmode(Entity* actor, String args, Game_State* game_state);                                                                                                           // LINE: 6823
CMD_Result::T Help_Command(Entity* entity, String args, Game_State* game_state);                                                                                                            // LINE: 6842
CMD_Result::T Attacks_Command(Entity* entity, String args, Game_State* game_state);                                                                                                         // LINE: 6882
CMD_Result::T Pickup_Command(Entity* actor, String args, Game_State* game_state);                                                                                                           // LINE: 6935
CMD_Result::T Inventory_Command(Entity* actor, String args, Game_State* game_state);                                                                                                        // LINE: 6987
CMD_Result::T Proceed_Command(Entity* actor, String args, Game_State* game_state);                                                                                                          // LINE: 7014
CMD_Result::T Equipment_Command(Entity* actor, String args, Game_State* game_state);                                                                                                        // LINE: 7111
CMD_Result::T Drop_Command(Entity* actor, String args, Game_State* game_state);                                                                                                             // LINE: 7146
CMD_Result::T Use_Command(Entity* actor, String args, Game_State* game_state);                                                                                                              // LINE: 7175
CMD_Result::T Equip_Command(Entity* actor, String args, Game_State* game_state);                                                                                                            // LINE: 7212
CMD_Result::T Unequip_Command(Entity* actor, String args, Game_State* game_state);                                                                                                          // LINE: 7234
CMD_Result::T Stats_Command(Entity* actor, String args, Game_State* game_state);                                                                                                            // LINE: 7263
CMD_Result::T Camp_Command(Entity* actor, String args, Game_State* game_state);                                                                                                             // LINE: 7378
CMD_Result::T Status_Command(Entity* actor, String args, Game_State* game_state);                                                                                                           // LINE: 7481
CMD_Result::T Inspect_Command(Entity* actor, String args, Game_State* game_state);                                                                                                          // LINE: 7553
CMD_Result::T What_Is_Seed_Command(Entity* entity, String args, Game_State* game_state);                                                                                                    // LINE: 7594
CMD_Result::T Pass_Command(Entity* actor, String args, Game_State* game_state);                                                                                                             // LINE: 7610
CMD_Result::T Glance_Command(Entity* actor, String args, Game_State* game_state);                                                                                                           // LINE: 7626
CMD_Result::T Search_Command(Entity* actor, String args, Game_State* game_state);                                                                                                           // LINE: 7650
CMD_Result::T Restart_Command(Entity* actor, String args, Game_State* game_state);                                                                                                          // LINE: 7698
CMD_Result::T Save_Command(Entity* actor, String args, Game_State* game_state);                                                                                                             // LINE: 7733
CMD_Result::T Load_Command(Entity* actor, String args, Game_State* game_state);                                                                                                             // LINE: 7759
CMD_Result::T Exit_Command(Entity* actor, String args, Game_State* game_state);                                                                                                             // LINE: 7785
CMD_Result::T Loot_Command(Entity* actor, String args, Game_State* game_state);                                                                                                             // LINE: 7823
CMD_Result::T Attack_Command(Entity* actor, String args, Game_State* game_state);                                                                                                           // LINE: 7901
CMD_Result::T Set_Seed_Command(Entity* actor, String args, Game_State* game_state);                                                                                                         // LINE: 7964
CMD_Result::T Get_Exp_Command(Entity* actor, String args, Game_State* game_state);                                                                                                          // LINE: 7994
void Get_Level_Up_Commands(Command** out_commands, u64* out_count, Game_State* game_state);                                                                                                 // LINE: 8022
void Get_Character_Creator_Commands(Command** out_commands, u64* out_count, Game_State* game_state);                                                                                        // LINE: 8396
