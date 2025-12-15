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
struct U64_To_String_Memory;                                                                                                                                                                // LINE: 392

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
struct PROTOTYPE_EFFINST_ENTOFF_ENT_DDR_GS_Offset;                                                                                                                                          // LINE: 35
struct PROTOTYPE_EFFINST_ENT_S32PTR_STR_GS_Offset;                                                                                                                                          // LINE: 40
struct PROTOTYPE_EFFINST_ENT_STAT_S32PTR_S16PTR_GS_Offset;                                                                                                                                  // LINE: 45

// FILE: src\Stats.cpp:
namespace Stats
{
    enum T;                                                                                                                                                                                 // LINE: 20
}


// FILE: src\Dungeon.h:
union Color;                                                                                                                                                                                // LINE: 23
struct ANSI_Color_Buffer;                                                                                                                                                                   // LINE: 38
struct Effect_Offset;                                                                                                                                                                       // LINE: 96
struct Effects_Node_Offset;                                                                                                                                                                 // LINE: 103
struct Entity_Node_Offset;                                                                                                                                                                  // LINE: 115
struct String_Offset;                                                                                                                                                                       // LINE: 121
struct String_Wrapper;                                                                                                                                                                      // LINE: 127
struct String_Table;                                                                                                                                                                        // LINE: 134
struct String_Table_Root;                                                                                                                                                                   // LINE: 142
struct Entity_Offset;                                                                                                                                                                       // LINE: 149
struct Entity_Node;                                                                                                                                                                         // LINE: 156
struct Entity_Root_Node;                                                                                                                                                                    // LINE: 163
struct Dice;                                                                                                                                                                                // LINE: 208
struct Bonus_Dice;                                                                                                                                                                          // LINE: 215
struct Effect_Hash_Key;                                                                                                                                                                     // LINE: 232
struct Effect;                                                                                                                                                                              // LINE: 245
enum class Apply_Effect_Result : u8;                                                                                                                                                        // LINE: 314
enum class Duration_Type : u8;                                                                                                                                                              // LINE: 327
struct Effect_Instance;                                                                                                                                                                     // LINE: 373
struct Effects_Node;                                                                                                                                                                        // LINE: 410
struct Effects_Root;                                                                                                                                                                        // LINE: 421
struct Roll_Result;                                                                                                                                                                         // LINE: 429
struct Initiative;                                                                                                                                                                          // LINE: 439
struct Interactable;                                                                                                                                                                        // LINE: 447
enum class Faction : u8;                                                                                                                                                                    // LINE: 455
struct Entity;                                                                                                                                                                              // LINE: 466
struct Damage_Modifiers_Result;                                                                                                                                                             // LINE: 515
struct Damage_Modifier;                                                                                                                                                                     // LINE: 522
struct Healing_Result;                                                                                                                                                                      // LINE: 534
struct Deal_Damage_Result;                                                                                                                                                                  // LINE: 545
enum class Damage_Type;                                                                                                                                                                     // LINE: 559
struct Critical_Ranges_Result;                                                                                                                                                              // LINE: 566
struct Message_Pipe;                                                                                                                                                                        // LINE: 573
struct Attack_Record;                                                                                                                                                                       // LINE: 580
struct Entity_Iterator;                                                                                                                                                                     // LINE: 653
struct Backwards_Iterator;                                                                                                                                                                  // LINE: 668
struct Effects_Iterator;                                                                                                                                                                    // LINE: 678
struct Effect_Hash_Table_Entry;                                                                                                                                                             // LINE: 690
struct Effect_Hash_Table;                                                                                                                                                                   // LINE: 697
struct Game_State;                                                                                                                                                                          // LINE: 706
struct Character_Creator;                                                                                                                                                                   // LINE: 757
struct Loot_Table_Entry;                                                                                                                                                                    // LINE: 767
struct Loot_Table_Pick_Result;                                                                                                                                                              // LINE: 777
struct Loot_Table;                                                                                                                                                                          // LINE: 784
struct Pick_From_Table_Rules;                                                                                                                                                               // LINE: 792
struct Rules_Builder;                                                                                                                                                                       // LINE: 805
enum class Comparison : u8;                                                                                                                                                                 // LINE: 847
struct Level_Segment;                                                                                                                                                                       // LINE: 856
struct Level_Segments;                                                                                                                                                                      // LINE: 863
struct Room_Generator_Element;                                                                                                                                                              // LINE: 870
struct Room_Generator_Element_Array;                                                                                                                                                        // LINE: 877
struct Game_Command;                                                                                                                                                                        // LINE: 966
enum class Call_Style;                                                                                                                                                                      // LINE: 977
struct Command;                                                                                                                                                                             // LINE: 985
typedef void PROTOTYPE_ENT_GS(Entity*, Game_State*);;                                                                                                                                       // LINE: 1091
typedef void PROTOTYPE_ENT_ENT_GS(Entity*, Entity*, Game_State*);;                                                                                                                          // LINE: 1092
typedef void PROTOTYPE_EFFINST_ENT_GS(Effect_Instance*, Entity*, Game_State*);;                                                                                                             // LINE: 1093
typedef void PROTOTYPE_EFFINST_ENT_ENT_AR_GS(Effect_Instance*, Entity*, Entity*, Attack_Record*, Game_State*);;                                                                             // LINE: 1094
typedef void PROTOTYPE_EFFINST_ENTOFF_ENT_DDR_GS(Effect_Instance*, Entity_Offset, Entity*, Deal_Damage_Result*, Game_State*);;                                                              // LINE: 1095
typedef void PROTOTYPE_EFFINST_ENT_S32PTR_STR_GS(Effect_Instance*, Entity*, s32*, String, Game_State*);;                                                                                    // LINE: 1096
typedef void PROTOTYPE_EFFINST_ENT_STAT_S32PTR_S16PTR_GS(Effect_Instance*, Entity*, Stats::T, s32*, s16*, Game_State*);;                                                                    // LINE: 1097
typedef Entity* GENERATE_ENTITY_FN(Entity*, Game_State*);;                                                                                                                                  // LINE: 1099
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
    enum T : u32;                                                                                                                                                                           // LINE: 188
}

namespace Effect_Flags
{
    enum T : s8;                                                                                                                                                                            // LINE: 224
}

namespace Effect_Type
{
    enum T : u8;                                                                                                                                                                            // LINE: 299
}

namespace Class
{
    enum T : u8;                                                                                                                                                                            // LINE: 351
}

namespace Roll_Print_Style
{
    enum T;                                                                                                                                                                                 // LINE: 612
}

namespace Report_Turn_Taken_Status
{
    enum T : u8;                                                                                                                                                                            // LINE: 625
}

namespace Verbose
{
    enum T : u8;                                                                                                                                                                            // LINE: 635
}

namespace Forced
{
    enum T : u8;                                                                                                                                                                            // LINE: 645
}

namespace Attack_Mod
{
    enum T;                                                                                                                                                                                 // LINE: 937
}

namespace CMD_Result
{
    enum T : u8;                                                                                                                                                                            // LINE: 956
}


// FILE: src\Dungeon.cpp:
struct On_Get_Stat_Value_Storage;                                                                                                                                                           // LINE: 1786


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
bool Match_Case_Sensitive(String str, String comp);                                                                                                                                         // LINE: 262
bool Match_Beginning_Case_Insensitive(String str, String comp);                                                                                                                             // LINE: 290
bool Match_Beginning_Case_Sensitive(String str, String comp);                                                                                                                               // LINE: 318
u64 To_U64(String str);                                                                                                                                                                     // LINE: 370
String To_String(u64 integer, U64_To_String_Memory* output);                                                                                                                                // LINE: 398
String Merge(String A, String B, Arena* arena);                                                                                                                                             // LINE: 439

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
_inline PROTOTYPE_EFFINST_ENTOFF_ENT_DDR_GS_Offset Offset(PROTOTYPE_EFFINST_ENTOFF_ENT_DDR_GS* pointer, Game_State* game_state);                                                            // LINE: 126
_inline PROTOTYPE_EFFINST_ENTOFF_ENT_DDR_GS* Pointer(PROTOTYPE_EFFINST_ENTOFF_ENT_DDR_GS_Offset offset, Game_State* game_state);                                                            // LINE: 137
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
Loot_Table Basic_Consumables_Loot_Table(Game_State* game_state);                                                                                                                            // LINE: 24
Loot_Table Basic_Trinkets_Loot_Table(Game_State* game_state);                                                                                                                               // LINE: 39
Loot_Table Basic_Armors_Loot_Table(Game_State* game_state);                                                                                                                                 // LINE: 58
Loot_Table Basic_Weapons_Loot_Table(Game_State* game_state);                                                                                                                                // LINE: 93
Entity* Create_Greate_Sword(Entity* room, Game_State* game_state);                                                                                                                          // LINE: 119
Entity* Create_Halberd(Entity* room, Game_State* game_state);                                                                                                                               // LINE: 151
Entity* Create_Long_Spear(Entity* room, Game_State* game_state);                                                                                                                            // LINE: 184
Entity* Create_Greate_Club(Entity* room, Game_State* game_state);                                                                                                                           // LINE: 217
Entity* Create_Magma_Hammer(Entity* room, Game_State* game_state);                                                                                                                          // LINE: 250
Entity* Create_War_Pick(Entity* room, Game_State* game_state);                                                                                                                              // LINE: 315
Entity* Create_Straightsword(Entity* room, Game_State* game_state);                                                                                                                         // LINE: 344
Entity* Create_Whip(Entity* room, Game_State* game_state);                                                                                                                                  // LINE: 371
Entity* Create_Mace(Entity* room, Game_State* game_state);                                                                                                                                  // LINE: 401
Entity* Create_Rapier(Entity* room, Game_State* game_state);                                                                                                                                // LINE: 428
Entity* Create_Short_Spear(Entity* room, Game_State* game_state);                                                                                                                           // LINE: 460
Entity* Create_Morning_Star(Entity* room, Game_State* game_state);                                                                                                                          // LINE: 488
Entity* Create_Three_Headed_Flail(Entity* room, Game_State* game_state);                                                                                                                    // LINE: 517
Entity* Create_Dagger(Entity* room, Game_State* game_state);                                                                                                                                // LINE: 547
Entity* Create_Poison_Dagger(Entity* room, Game_State* game_state);                                                                                                                         // LINE: 577
Entity* Create_Cape_Of_Avoidance(Entity* room, Game_State* game_state);                                                                                                                     // LINE: 646
Entity* Create_Cape_Of_Dashing(Entity* room, Game_State* game_state);                                                                                                                       // LINE: 672
Entity* Create_Backpack(Entity* room, Game_State* game_state);                                                                                                                              // LINE: 698
Entity* Create_Ring_Of_Giants(Entity* room, Game_State* game_state);                                                                                                                        // LINE: 727
Entity* Create_Ring_Of_Strange_Fortunes(Entity* room, Game_State* game_state);                                                                                                              // LINE: 754
Entity* Create_Ring_Of_Rebirth(Entity* room, Game_State* game_state);                                                                                                                       // LINE: 780
Entity* Create_Ring_Of_Regeneration(Entity* room, Game_State* game_state);                                                                                                                  // LINE: 839
Entity* Create_Gloves_Of_Brutality(Entity* room, Game_State* game_state);                                                                                                                   // LINE: 881
Entity* Create_Wooden_Shield(Entity* room, Game_State* game_state);                                                                                                                         // LINE: 908
Entity* Create_Buckler(Entity* room, Game_State* game_state);                                                                                                                               // LINE: 934
Entity* Create_Kite_Shield(Entity* room, Game_State* game_state);                                                                                                                           // LINE: 960
Entity* Create_Barn_Door_Shield(Entity* room, Game_State* game_state);                                                                                                                      // LINE: 986
Entity* Create_Tower_Shield(Entity* room, Game_State* game_state);                                                                                                                          // LINE: 1013
Entity* Create_Shearing_Light(Entity* room, Game_State* game_state);                                                                                                                        // LINE: 1041
Entity* Create_Leather_Cuirass(Entity* room, Game_State* game_state);                                                                                                                       // LINE: 1068
Entity* Create_Gambeson(Entity* room, Game_State* game_state);                                                                                                                              // LINE: 1094
Entity* Create_Breastplate(Entity* room, Game_State* game_state);                                                                                                                           // LINE: 1121
Entity* Create_Skull_Cap(Entity* room, Game_State* game_state);                                                                                                                             // LINE: 1151
Entity* Create_Arming_Cap(Entity* room, Game_State* game_state);                                                                                                                            // LINE: 1177
Entity* Create_Chainmail_Hood(Entity* room, Game_State* game_state);                                                                                                                        // LINE: 1202
Entity* Create_Barbute(Entity* room, Game_State* game_state);                                                                                                                               // LINE: 1228
Entity* Create_Plate_Leggings(Entity* room, Game_State* game_state);                                                                                                                        // LINE: 1256
Entity* Create_Leather_Tights(Entity* room, Game_State* game_state);                                                                                                                        // LINE: 1285
Entity* Create_Padded_Pants(Entity* room, Game_State* game_state);                                                                                                                          // LINE: 1310
Entity* Create_Warrior_Kilt(Entity* room, Game_State* game_state);                                                                                                                          // LINE: 1335
Entity* Create_Barbarian_Loing_Cloth(Entity* room, Game_State* game_state);                                                                                                                 // LINE: 1362
Entity* Create_Travel_Boots(Entity* room, Game_State* game_state);                                                                                                                          // LINE: 1389
Entity* Create_Sabatons(Entity* room, Game_State* game_state);                                                                                                                              // LINE: 1416
Entity* Create_Gladiator_Sandals(Entity* room, Game_State* game_state);                                                                                                                     // LINE: 1445
Entity* Create_Leather_Boots(Entity* room, Game_State* game_state);                                                                                                                         // LINE: 1472
Entity* Create_Antidote(Entity* container, Game_State* game_state);                                                                                                                         // LINE: 1497
Entity* Create_Healing_Potion(Entity* container, Game_State* game_state);                                                                                                                   // LINE: 1537
Entity* Create_Ring_Of_Just_Fucking_Crit(Entity* room, Game_State* game_state);                                                                                                             // LINE: 1626

// FILE: src\Factory.cpp:
void Finalize_Entity(Entity* entity, Entity* container, Game_State* game_state);                                                                                                            // LINE: 9
Entity* Create_Class_Adventurer(Game_State* game_state);                                                                                                                                    // LINE: 18
Entity* Create_Class_Wretched(Game_State* game_state);                                                                                                                                      // LINE: 64
Entity* Create_Bandit(Entity* room, Game_State* game_state);                                                                                                                                // LINE: 84
Entity* Create_Giant_Rat(Entity* room, Game_State* game_state);                                                                                                                             // LINE: 131
Entity* Create_Enlarged_Ant(Entity* room, Game_State* game_state);                                                                                                                          // LINE: 191
Entity* Create_Enlarged_Ant_Queen(Entity* room, Game_State* game_state);                                                                                                                    // LINE: 238
Entity* Create_Bear_Cub(Entity* room, Game_State* game_state);                                                                                                                              // LINE: 325
Entity* Create_Mutant_Hedgehog(Entity* room, Game_State* game_state);                                                                                                                       // LINE: 389
Entity* Create_Training_Dummmy(Entity* room, Game_State* game_state);                                                                                                                       // LINE: 481
Entity* Create_Rat_Meat(Entity* container, Game_State* game_state);                                                                                                                         // LINE: 503
Entity* Create_Rat_Mound(Entity* room, Game_State* game_state);                                                                                                                             // LINE: 517
Entity* Create_Spider(Entity* room, Game_State* game_state);                                                                                                                                // LINE: 578
Entity* Create_Boss_Spider(Entity* room, Game_State* game_state);                                                                                                                           // LINE: 630
void Generate_Entrance_Room(Entity* room, Game_State* game_state);                                                                                                                          // LINE: 677
Loot_Table Caves_Wildlife_Section(Game_State* game_state);                                                                                                                                  // LINE: 708
Loot_Table Caves_Bandit_Section(Game_State* game_state);                                                                                                                                    // LINE: 763
Loot_Table Caves_Spider_Section(Game_State* game_state);                                                                                                                                    // LINE: 801
Loot_Table Caves_Boss(Game_State* game_state);                                                                                                                                              // LINE: 836
_inline Level_Segments Caves(Game_State* game_state);                                                                                                                                       // LINE: 871

// FILE: src\Dungeon.cpp:
char* Get_Output_Color_CSTR(ANSI_Color_Buffer* buffer, u8 red, u8 green, u8 blue);                                                                                                          // LINE: 58
char* Get_Output_Color_CSTR(ANSI_Color_Buffer* buffer, Color color);                                                                                                                        // LINE: 68
void Set_Output_Color(u8 red, u8 green, u8 blue);                                                                                                                                           // LINE: 75
void Set_Output_Color(Color color);                                                                                                                                                         // LINE: 83
char* Entity_Color(Entity* entity, Game_State* game_state);                                                                                                                                 // LINE: 89
String Format_Message(Game_State* game_state, char* format_string, ...);                                                                                                                    // LINE: 116
_inline void Flush_Messages(Game_State* game_state);                                                                                                                                        // LINE: 135
_inline void Print_Messages(Game_State* game_state);                                                                                                                                        // LINE: 142
void Push_Message(String message, Game_State* game_state);                                                                                                                                  // LINE: 160
void Wait(f64 seconds, Game_State* game_state);                                                                                                                                             // LINE: 175
String Get_User_Input(Game_State* game_state);                                                                                                                                              // LINE: 184
bool User_Query_Yes_No(Game_State* game_state);                                                                                                                                             // LINE: 203
u64 Base_Alphabet_Digits(u64 v);                                                                                                                                                            // LINE: 237
u64 Encode_Base_Alphabet(u64 identity, char character);                                                                                                                                     // LINE: 257
U64_To_String_Memory Decode_Base_Aplhabet(u64 identity);                                                                                                                                    // LINE: 268
Entity_Offset* Find_Empty_Slot(Entity_Node* node);                                                                                                                                          // LINE: 287
_inline Entity_Offset Offset(Entity* entity, Game_State* game_state);                                                                                                                       // LINE: 349
_inline Entity* Pointer(Entity_Offset offset, Game_State* game_state);                                                                                                                      // LINE: 361
_inline Effect_Offset Offset(Effect* effect, Game_State* game_state);                                                                                                                       // LINE: 377
_inline Effect* Pointer(Effect_Offset offset, Game_State* game_state);                                                                                                                      // LINE: 390
_inline Entity_Node_Offset Offset(Entity_Node* entity_node, Game_State* game_state);                                                                                                        // LINE: 403
_inline Entity_Node* Pointer(Entity_Node_Offset offset, Game_State* game_state);                                                                                                            // LINE: 415
_inline Effects_Node_Offset Offset(Effects_Node* effects_node, Game_State* game_state);                                                                                                     // LINE: 427
_inline Effects_Node* Pointer(Effects_Node_Offset offset, Game_State* game_state);                                                                                                          // LINE: 439
String Unwrap_String(String_Wrapper* strw, Game_State* game_state);                                                                                                                         // LINE: 451
String_Offset Offset(String str, Game_State* game_state);                                                                                                                                   // LINE: 459
String Get_String(String_Offset offset, Game_State* game_state);                                                                                                                            // LINE: 526
_inline u64 Storage_Offset(void* ptr, Game_State* game_state);                                                                                                                              // LINE: 539
_inline void* Pull_From_Storage_Offset(u64 offset, Game_State* game_state);                                                                                                                 // LINE: 552
Entity_Offset* Find_Entity(Entity* entity, Entity_Root_Node* storage, Game_State* game_state, Entity_Node** out_node = 0);                                                                  // LINE: 565
Entity* Find_Entity_By_Name_Or_Reference_Number(Entity* actor, Entity_Offset space, String name_or_reference_number, Game_State* game_state, Verbose::T verbose = Verbose::T(1));           // LINE: 592
Entity* Find_Entity_By_Name(Entity* actor, Entity* space, String name, Game_State* game_state, Verbose::T verbose = Verbose::T(1));                                                         // LINE: 604
Entity* Find_Entity_By_Name_Or_Reference_Number(Entity* actor, Entity* space, String name_or_reference_number, Game_State* game_state, Verbose::T verbose = Verbose::T(1));                 // LINE: 635
Entity_Iterator Make_Iterator(Entity_Root_Node* root, Game_State* game_state);                                                                                                              // LINE: 681
Entity_Iterator Make_Iterator(Entity* entity, Game_State* game_state);                                                                                                                      // LINE: 699
Effects_Iterator Make_Iterator(Effects_Root* root, Game_State* game_state);                                                                                                                 // LINE: 707
Entity_Offset* Next(Entity_Iterator* iter);                                                                                                                                                 // LINE: 726
Entity* Next_Entity(Entity_Iterator* iter);                                                                                                                                                 // LINE: 756
u64 Count(Entity_Root_Node* root_node, Game_State* game_state);                                                                                                                             // LINE: 770
bool Memory_Snapshot_Save(String file_path, Game_State* game_state);                                                                                                                        // LINE: 783
bool Memory_Snapshot_Restore(String file_path, Game_State* game_state);                                                                                                                     // LINE: 792
Effect_Instance* Next_Effect_Instance(Effects_Iterator* iter);                                                                                                                              // LINE: 824
_inline Effect_Instance* Next(Effects_Iterator* iter);                                                                                                                                      // LINE: 857
Effect* Next_Effect(Effects_Iterator* iter);                                                                                                                                                // LINE: 864
Backwards_Iterator Make_Backwards_Iterator(Entity_Root_Node* root, Game_State* game_state);                                                                                                 // LINE: 878
Entity_Offset* Previous(Backwards_Iterator* back_iter);                                                                                                                                     // LINE: 892
void Add_Dice(Effect* effect, s16 count, s16 faces);                                                                                                                                        // LINE: 936
u32 Roll(u32 range, Game_State* game_state);                                                                                                                                                // LINE: 965
s32 Roll(Dice dice, Game_State* game_state);                                                                                                                                                // LINE: 977
s32* Roll_With_Record(Dice dice, Game_State* game_state);                                                                                                                                   // LINE: 993
f32 Random_F32(Game_State* game_state);                                                                                                                                                     // LINE: 1007
Roll_Result Stat_Roll(s32 value, Stats::T stat, Game_State* game_state);                                                                                                                    // LINE: 1017
s32 Value(Roll_Result rr);                                                                                                                                                                  // LINE: 1033
Roll_Result Stat_Roll(Entity* entity, Stats::T stat, Game_State* game_state);                                                                                                               // LINE: 1040
_inline bool Is_Rolled(Roll_Result rr);                                                                                                                                                     // LINE: 1051
void Print_Dice(Dice dice, s32 result);                                                                                                                                                     // LINE: 1058
void Print_Roll_Result(Roll_Result rr);                                                                                                                                                     // LINE: 1064
void Print_Attack_Record(Attack_Record* ar, Game_State* game_state);                                                                                                                        // LINE: 1077
String Name_Without_Color(Entity* entity, Game_State* game_state);                                                                                                                          // LINE: 1312
String Name(Entity* entity, Game_State* game_state);                                                                                                                                        // LINE: 1327
char* Action_Name(AT::T action);                                                                                                                                                            // LINE: 1347
void Print_Required_Equipment_Slots(Entity* item);                                                                                                                                          // LINE: 1374
void Push_Generic_Apply_Effect_Message(Effect_Instance* source_effect, Entity* target, Effect_Instance new_effect, Apply_Effect_Result apply, Game_State* game_state);                      // LINE: 1398
void Remove_From_Residence(Entity* entity, Game_State* game_state);                                                                                                                         // LINE: 1455
void Release_Entity_Node(Entity_Root_Node* root, Game_State* game_state);                                                                                                                   // LINE: 1489
Entity_Node* Request_Entity_Node(Game_State* game_state);                                                                                                                                   // LINE: 1511
Effect* Request_Effect(Game_State* game_state);                                                                                                                                             // LINE: 1528
void Release_Effect(Effect* effect, Game_State* game_state);                                                                                                                                // LINE: 1551
Entity* Request_Entity(Game_State* game_state);                                                                                                                                             // LINE: 1565
void Release_Entity(Entity* entity, Game_State* game_state);                                                                                                                                // LINE: 1587
Effects_Node* Request_Effects_Node(Game_State* game_state);                                                                                                                                 // LINE: 1595
void Release_Effects_Node(Effects_Node* node, Game_State* game_state);                                                                                                                      // LINE: 1612
void Insert(Entity* entity, Entity_Root_Node* storage, Game_State* game_state);                                                                                                             // LINE: 1620
void Assign_Dublicate_Name_Identifier(Entity* entity_to_insert, Entity* storage, Game_State* game_state);                                                                                   // LINE: 1657
void Deep_Insert(Entity* entity, Entity* storage_entity, Game_State* game_state);                                                                                                           // LINE: 1691
void Remove_All_Effects(Entity* entity, Game_State* game_state);                                                                                                                            // LINE: 1706
void Delete_Entity(Entity* entity, Game_State* game_state);                                                                                                                                 // LINE: 1766
bool Has_Content(Entity_Root_Node* root);                                                                                                                                                   // LINE: 1773
bool Is_Empty(Entity_Root_Node* root);                                                                                                                                                      // LINE: 1780
s32 Get_Stat_Value(Entity* entity, Stats::T stat, Game_State* game_state, u64* out_effect_count = 0);                                                                                       // LINE: 1793
s32 Exp_To_Level_Up(s32 _lvl);                                                                                                                                                              // LINE: 1840
_inline s32 Exp_To_Level_Up(Entity* entity);                                                                                                                                                // LINE: 1848
s16 Calculate_Level(Entity* entity);                                                                                                                                                        // LINE: 1855
void Set_Level_Based_On_Stats(Entity* entity);                                                                                                                                              // LINE: 1868
s16 Level(Entity* entity);                                                                                                                                                                  // LINE: 1875
s32 Max_Health(Entity* entity, Game_State* game_state);                                                                                                                                     // LINE: 1882
f32 Critical_Multiplier(Entity* entity, Game_State* game_state);                                                                                                                            // LINE: 1895
s32 Carry_Capacity(Entity* entity, Game_State* game_state);                                                                                                                                 // LINE: 1902
s32 Exp_Reward(Entity* entity);                                                                                                                                                             // LINE: 1922
s32 Carrying_Amount(Entity* entity, Game_State* game_state);                                                                                                                                // LINE: 1935
Critical_Ranges_Result Critical_Ranges(Entity* entity, Game_State* game_state, u32* out_success_effecting_count = 0, u32* out_failure_effecing_count = 0);                                  // LINE: 1948
void Full_Heal(Entity* entity, Game_State* game_state);                                                                                                                                     // LINE: 1990
bool Is_Item(Entity* entity);                                                                                                                                                               // LINE: 1996
bool Is_Visible(Entity* entity);                                                                                                                                                            // LINE: 2003
bool Is_Alive(Entity* entity);                                                                                                                                                              // LINE: 2010
bool Is_Hostile_Against(Entity* A, Entity* B);                                                                                                                                              // LINE: 2017
bool Is_Living_Enemy_Of(Entity* actor, Entity* target);                                                                                                                                     // LINE: 2024
s32 Give_Temporary_Health(Entity* entity, s32 amount, String source_name, Verbose::T verbose, Game_State* game_state);                                                                      // LINE: 2031
Healing_Result Heal(Entity* entity, s32 amount, String source_name, Verbose::T verbose, Game_State* game_state);                                                                            // LINE: 2052
Deal_Damage_Result Deal_Damage(Entity* defender, Entity_Offset attacker_offset, String source_name, s32 dmg, s32 pierce, Damage_Type type, Game_State* game_state, Verbose::T verbose);     // LINE: 2122
_inline Deal_Damage_Result Deal_Damage(Entity* defender, Entity* attacker, String dmg_src_name, s32 dmg, s32 pierce, Damage_Type type, Game_State* game_state, Verbose::T verbose);         // LINE: 2296
void Proc_Effects(u64 offset, Entity* attacker, Entity* defender, Attack_Record* ar, Game_State* game_state);                                                                               // LINE: 2304
void Proc_Effects(u64 offset, Entity* target, Game_State* game_state);                                                                                                                      // LINE: 2321
String Effect_Name(Effect_Instance* instance, Game_State* game_state);                                                                                                                      // LINE: 2337
u64 Count_Effect_Instances(Effects_Root* root, Effect_Instance cmp, Game_State* game_state, Effect_Instance** out_shortest_duration = 0);                                                   // LINE: 2357
void Delete_Effect_Slot(Effects_Root* root, Effects_Node* node, u64 *idx, u64* count, Game_State* game_state);                                                                              // LINE: 2387
Effect_Instance* New_Effect_Slot(Effects_Root* root, Game_State* game_state);                                                                                                               // LINE: 2427
Apply_Effect_Result Apply_Effect(Entity* target, Effect_Instance instance, Game_State* game_state);                                                                                         // LINE: 2473
void Remove_Effects_From_Source(Entity* actor, Entity* source, Game_State* game_state);                                                                                                     // LINE: 2530
u64 Remove_Effects_Of_Type(Entity* actor, Effect_Type::T type_to_remove, Game_State* game_state, Verbose::T verbose);                                                                       // LINE: 2555
void Print_Equiped_Weapons(Entity* target, bool preamble, Game_State* game_state);                                                                                                          // LINE: 2778
void Inspect(Entity* target, Game_State* game_state);                                                                                                                                       // LINE: 2816
bool Is_Equipped(Entity* actor, Entity* item, Game_State* game_state);                                                                                                                      // LINE: 2862
bool Unequip(Entity* actor, Entity* item, Game_State* game_state);                                                                                                                          // LINE: 2885
bool Unequip(Entity* item, Game_State* game_state);                                                                                                                                         // LINE: 2909
bool Use(Entity* actor, Entity* item, Game_State* game_state, Verbose::T verbose);                                                                                                          // LINE: 2917
bool Equip(Entity* actor, Entity* target, Game_State* game_state, Verbose::T verbose = Verbose::T(0));                                                                                      // LINE: 2957
void Print_Uses(Entity* entity);                                                                                                                                                            // LINE: 3170
void Open(Entity* actor, Game_State* game_state);                                                                                                                                           // LINE: 3190
u64 Longest_Entity_Name_In_Actor_Storage(Entity* actor, Game_State* game_state, u64* out_count = 0);                                                                                        // LINE: 3217
u64 Longest_Entity_Name_In_Actor_Inventory(Entity* actor, Game_State* game_state, u64* out_count = 0, s16* out_heaviest_weight = 0);                                                        // LINE: 3242
bool Glance(Entity* actor, Game_State* game_state, Report_Turn_Taken_Status::T report_turn_taken_status = Report_Turn_Taken_Status::T(1));                                                  // LINE: 3269
void Remove_Random_Effect(Entity* entity, String source_name, Game_State* game_state);                                                                                                      // LINE: 3349
Damage_Modifiers_Result Damage_Modifier_From_Effects(Entity* attacker, Attack_Record* ar, Game_State* game_state);                                                                          // LINE: 3388
u64 Attack_Modifier_Mask(Attack_Mod::T modifier);                                                                                                                                           // LINE: 3482
u64 Class_Mask(Class::T _class);                                                                                                                                                            // LINE: 3489
bool Can_Use_Attack_Modifier(Entity* entity, Attack_Mod::T modifier);                                                                                                                       // LINE: 3496
void Apply_Or_Describe_Attak_Modifier(Entity** attacker_ptr, Entity** defender_ptr, Attack_Mod::T modifier, Game_State* game_state);                                                        // LINE: 3507
void Proc_Thorns(Entity* attacker, Entity* defender, Game_State* game_state);                                                                                                               // LINE: 3654
void Attack(Entity* attacker, Entity* defender, Game_State* game_state, Attack_Mod::T modifier = Attack_Mod::T(0));                                                                         // LINE: 3677
void Player_Action(Entity* actor, String actor_name, Game_State* game_state);                                                                                                               // LINE: 3754
Entity* Redirected_Target(Entity* actor, String actor_name, Game_State* game_state);                                                                                                        // LINE: 3841
Entity* Random_Entity_That_Matches_Criteria(Entity_Root_Node* storage, bool(*conditional)(Entity* entity, void* user_ptr, Game_State* game_state), void* user_ptr, Game_State* game_state); // LINE: 3879
Entity* Find_Attack_Target(Entity* actor, Game_State* game_state);                                                                                                                          // LINE: 3918
void NPC_Action(Entity* actor, String actor_name, Game_State* game_state);                                                                                                                  // LINE: 3947
void Take_Action(Entity* actor, Game_State* game_state);                                                                                                                                    // LINE: 4025
u64 Hash_From_Key(Effect_Hash_Key key);                                                                                                                                                     // LINE: 4097
bool Retrive_Effect(Effect_Hash_Key key, Effect_Offset* out, Game_State* game_state);                                                                                                       // LINE: 4104
Effect_Offset Insert_Effect(Effect effect, Effect_Hash_Key key, Game_State* game_state);                                                                                                    // LINE: 4142
bool Compare(s64 X, Comparison type, s64 A, s64 B = 0);                                                                                                                                     // LINE: 4180
bool Is_Compliant(Loot_Table_Entry entry, Pick_From_Table_Rules rules);                                                                                                                     // LINE: 4210
Loot_Table_Pick_Result Pick_From_Loot_Table(Loot_Table table, u64 count, Pick_From_Table_Rules rules, Game_State* game_state);                                                              // LINE: 4236
GENERATE_ENTITY_FN* Pick_From_Loot_Table(Loot_Table table, Pick_From_Table_Rules rules, Game_State* game_state);                                                                            // LINE: 4288
void Generate_From_Loot_Table(Entity* storage, Loot_Table table, u64 count, Pick_From_Table_Rules rules, Game_State* game_state);                                                           // LINE: 4295
Loot_Table Merge_Loot_Tables(Loot_Table* tables, u64 count, Arena* arena);                                                                                                                  // LINE: 4305
Loot_Table Merge_Loot_Tables(Loot_Table A, Loot_Table B, Arena* arena);                                                                                                                     // LINE: 4319
Loot_Table Merge_Loot_Tables(Loot_Table A, Loot_Table B, Loot_Table C, Arena* arena);                                                                                                       // LINE: 4330
Loot_Table Merge_Loot_Tables(Loot_Table A, Loot_Table B, Loot_Table C, Loot_Table D, Arena* arena);                                                                                         // LINE: 4337
Loot_Table Merge_Loot_Tables(Loot_Table A, Loot_Table B, Loot_Table C, Loot_Table D, Loot_Table E, Arena* arena);                                                                           // LINE: 4344
Loot_Table Merge_Loot_Tables(Loot_Table A, Loot_Table B, Loot_Table C, Loot_Table D, Loot_Table E, Loot_Table F, Arena* arena);                                                             // LINE: 4351
void Fill_Loot_Table_Changes_And_Item_Rarity(Loot_Table* table, Game_State* game_state);                                                                                                    // LINE: 4358
bool Roll_Initiative(Entity* entity, Game_State* game_state);                                                                                                                               // LINE: 4431
void Sort_Iniative_Order(Entity_Offset* offs, Game_State* game_state);                                                                                                                      // LINE: 4465
void Sort_Space(Entity_Root_Node* space, Game_State* game_state);                                                                                                                           // LINE: 4596
u64 Count_Longest_Round_Effect_Duration(Entity* actor, Game_State* game_state);                                                                                                             // LINE: 4672
void Tick_Down_Effect_Durations(Entity* actor, Duration_Type type, Game_State* game_state);                                                                                                 // LINE: 4687
_inline void Enter_A_Room_Printout(Entity* player, Entity* room, Game_State* game_state);                                                                                                   // LINE: 4761
Room_Generator_Element Pick_Room_Generator(Room_Generator_Element_Array array, u32 selector, Game_State* game_state);                                                                       // LINE: 4784
Room_Generator_Element Pick_Room_Generator(Room_Generator_Element_Array array, Game_State* game_state);                                                                                     // LINE: 4805
void Prompt_User_For_Command_And_Attempt_To_Execute(Command* commands, u64 count, void* user_ptr, Game_State* game_state);                                                                  // LINE: 4819
void Create_Player_Charater(Game_State* game_state);                                                                                                                                        // LINE: 4913
void Tick_Active_Effects_Down_To_Zero(Entity* actor, Game_State* game_state);                                                                                                               // LINE: 5004
Entity* Next_Room(Level_Segments level, Game_State* game_state);                                                                                                                            // LINE: 5029
void Proceed(Game_State* game_state);                                                                                                                                                       // LINE: 5076
void Prepare_Game_Round(Game_State* game_state);                                                                                                                                            // LINE: 5142
void Excecute_Game_Round(Game_State* game_state);                                                                                                                                           // LINE: 5254
void Exit_Handling(Game_State* game_state);                                                                                                                                                 // LINE: 5292
bool Play_Game(Game_State* game_state);                                                                                                                                                     // LINE: 5324
void Reset_Game_State(Game_State* game_state);                                                                                                                                              // LINE: 5355
Game_State* Create_Game_State();                                                                                                                                                            // LINE: 5410
CMD_Result::T Kill_Command(Entity* actor, String args, Game_State* game_state);                                                                                                             // LINE: 5441
CMD_Result::T Toggle_Dramatic_Pause(Entity* actor, String args, Game_State* game_state);                                                                                                    // LINE: 5468
CMD_Result::T Toggle_Godmode(Entity* actor, String args, Game_State* game_state);                                                                                                           // LINE: 5492
CMD_Result::T Help_Command(Entity* entity, String args, Game_State* game_state);                                                                                                            // LINE: 5511
CMD_Result::T Attacks_Command(Entity* entity, String args, Game_State* game_state);                                                                                                         // LINE: 5551
CMD_Result::T Pickup_Command(Entity* actor, String args, Game_State* game_state);                                                                                                           // LINE: 5604
CMD_Result::T Inventory_Command(Entity* actor, String args, Game_State* game_state);                                                                                                        // LINE: 5653
CMD_Result::T Proceed_Command(Entity* actor, String args, Game_State* game_state);                                                                                                          // LINE: 5732
CMD_Result::T Equipment_Command(Entity* actor, String args, Game_State* game_state);                                                                                                        // LINE: 5829
CMD_Result::T Drop_Command(Entity* actor, String args, Game_State* game_state);                                                                                                             // LINE: 5864
CMD_Result::T Use_Command(Entity* actor, String args, Game_State* game_state);                                                                                                              // LINE: 5894
CMD_Result::T Equip_Command(Entity* actor, String args, Game_State* game_state);                                                                                                            // LINE: 5918
CMD_Result::T Unequip_Command(Entity* actor, String args, Game_State* game_state);                                                                                                          // LINE: 5940
CMD_Result::T Stats_Command(Entity* actor, String args, Game_State* game_state);                                                                                                            // LINE: 5969
CMD_Result::T Status_Command(Entity* actor, String args, Game_State* game_state);                                                                                                           // LINE: 6084
CMD_Result::T Inspect_Command(Entity* actor, String args, Game_State* game_state);                                                                                                          // LINE: 6138
CMD_Result::T What_Is_Seed_Command(Entity* entity, String args, Game_State* game_state);                                                                                                    // LINE: 6179
CMD_Result::T Pass_Command(Entity* actor, String args, Game_State* game_state);                                                                                                             // LINE: 6195
CMD_Result::T Glance_Command(Entity* actor, String args, Game_State* game_state);                                                                                                           // LINE: 6211
CMD_Result::T Search_Command(Entity* actor, String args, Game_State* game_state);                                                                                                           // LINE: 6235
CMD_Result::T Restart_Command(Entity* actor, String args, Game_State* game_state);                                                                                                          // LINE: 6278
CMD_Result::T Save_Command(Entity* actor, String args, Game_State* game_state);                                                                                                             // LINE: 6313
CMD_Result::T Load_Command(Entity* actor, String args, Game_State* game_state);                                                                                                             // LINE: 6339
CMD_Result::T Exit_Command(Entity* actor, String args, Game_State* game_state);                                                                                                             // LINE: 6365
CMD_Result::T Loot_Command(Entity* actor, String args, Game_State* game_state);                                                                                                             // LINE: 6403
CMD_Result::T Attack_Command(Entity* actor, String args, Game_State* game_state);                                                                                                           // LINE: 6459
CMD_Result::T Set_Seed_Command(Entity* actor, String args, Game_State* game_state);                                                                                                         // LINE: 6522
void Get_Character_Creator_Commands(Game_State* game_state, Command** out_commands, u64* out_count);                                                                                        // LINE: 6552
