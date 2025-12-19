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
struct U64_To_String_Memory;                                                                                                                                                                // LINE: 396

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
struct Effect_Offset;                                                                                                                                                                       // LINE: 81
struct Effects_Node_Offset;                                                                                                                                                                 // LINE: 88
struct Entity_Node_Offset;                                                                                                                                                                  // LINE: 100
struct String_Offset;                                                                                                                                                                       // LINE: 106
struct String_Wrapper;                                                                                                                                                                      // LINE: 112
struct String_Table;                                                                                                                                                                        // LINE: 119
struct String_Table_Root;                                                                                                                                                                   // LINE: 127
struct Entity_Offset;                                                                                                                                                                       // LINE: 134
struct Entity_Node;                                                                                                                                                                         // LINE: 141
struct Entity_Root_Node;                                                                                                                                                                    // LINE: 148
struct Dice;                                                                                                                                                                                // LINE: 193
struct Bonus_Dice;                                                                                                                                                                          // LINE: 200
struct Effect_Hash_Key;                                                                                                                                                                     // LINE: 217
struct Effect;                                                                                                                                                                              // LINE: 230
enum class Apply_Effect_Result : u8;                                                                                                                                                        // LINE: 299
enum class Duration_Type : u8;                                                                                                                                                              // LINE: 312
struct Effect_Instance;                                                                                                                                                                     // LINE: 387
struct Effects_Node;                                                                                                                                                                        // LINE: 424
struct Effects_Root;                                                                                                                                                                        // LINE: 435
struct Roll_Result;                                                                                                                                                                         // LINE: 443
struct Initiative;                                                                                                                                                                          // LINE: 453
struct Interactable;                                                                                                                                                                        // LINE: 461
enum class Faction : u8;                                                                                                                                                                    // LINE: 470
struct Entity;                                                                                                                                                                              // LINE: 484
struct Damage_Modifiers_Result;                                                                                                                                                             // LINE: 535
struct Damage_Modifier;                                                                                                                                                                     // LINE: 542
struct Healing_Result;                                                                                                                                                                      // LINE: 554
struct Deal_Damage_Result;                                                                                                                                                                  // LINE: 565
enum class Damage_Type;                                                                                                                                                                     // LINE: 579
struct Critical_Ranges_Result;                                                                                                                                                              // LINE: 586
struct Message_Pipe;                                                                                                                                                                        // LINE: 593
struct Apply_Check_Record;                                                                                                                                                                  // LINE: 600
struct Attack_Record;                                                                                                                                                                       // LINE: 609
struct Entity_Iterator;                                                                                                                                                                     // LINE: 692
struct Backwards_Iterator;                                                                                                                                                                  // LINE: 707
struct Ambush_Creature_Spawner_Offset;                                                                                                                                                      // LINE: 717
struct Ambush_Option_Offset;                                                                                                                                                                // LINE: 723
struct Ambush_Creature_Spawner;                                                                                                                                                             // LINE: 729
struct Ambush_Option;                                                                                                                                                                       // LINE: 738
struct Ambush_Table;                                                                                                                                                                        // LINE: 746
struct Effects_Iterator;                                                                                                                                                                    // LINE: 754
struct Effect_Hash_Table_Entry;                                                                                                                                                             // LINE: 766
struct Effect_Hash_Table;                                                                                                                                                                   // LINE: 773
struct Game_State;                                                                                                                                                                          // LINE: 782
struct Character_Creator;                                                                                                                                                                   // LINE: 837
struct Loot_Table_Entry;                                                                                                                                                                    // LINE: 846
struct Loot_Table_Pick_Result;                                                                                                                                                              // LINE: 856
struct Loot_Table;                                                                                                                                                                          // LINE: 863
struct Pick_From_Table_Rules;                                                                                                                                                               // LINE: 871
struct Rules_Builder;                                                                                                                                                                       // LINE: 884
enum class Comparison : u8;                                                                                                                                                                 // LINE: 926
struct Level_Segment;                                                                                                                                                                       // LINE: 935
struct Level_Segments;                                                                                                                                                                      // LINE: 942
struct Room_Generator_Element;                                                                                                                                                              // LINE: 949
struct Room_Generator_Element_Array;                                                                                                                                                        // LINE: 956
struct Game_Command;                                                                                                                                                                        // LINE: 1045
enum class Call_Style;                                                                                                                                                                      // LINE: 1056
struct Command;                                                                                                                                                                             // LINE: 1064
typedef void PROTOTYPE_ENT_GS(Entity*, Game_State*);;                                                                                                                                       // LINE: 1170
typedef void PROTOTYPE_ENT_ENT_GS(Entity*, Entity*, Game_State*);;                                                                                                                          // LINE: 1171
typedef void PROTOTYPE_EFFINST_ENT_GS(Effect_Instance*, Entity*, Game_State*);;                                                                                                             // LINE: 1172
typedef void PROTOTYPE_EFFINST_ENT_ENT_GS(Effect_Instance*, Entity*, Entity*, Game_State*);;                                                                                                // LINE: 1173
typedef void PROTOTYPE_EFFINST_ENT_ENT_AR_GS(Effect_Instance*, Entity*, Entity*, Attack_Record*, Game_State*);;                                                                             // LINE: 1174
typedef void PROTOTYPE_EFFINST_ENTOFF_ENT_DDR_GS(Effect_Instance*, Entity_Offset, Entity*, Deal_Damage_Result*, Game_State*);;                                                              // LINE: 1175
typedef void PROTOTYPE_EFFINST_ENT_S32PTR_STR_GS(Effect_Instance*, Entity*, s32*, String, Game_State*);;                                                                                    // LINE: 1176
typedef void PROTOTYPE_EFFINST_ENT_STAT_S32PTR_S16PTR_GS(Effect_Instance*, Entity*, Stats::T, s32*, s16*, Game_State*);;                                                                    // LINE: 1177
typedef Entity* GENERATE_ENTITY_FN(Entity*, Game_State*);;                                                                                                                                  // LINE: 1179
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
    enum T : u32;                                                                                                                                                                           // LINE: 173
}

namespace Effect_Flags
{
    enum T : s8;                                                                                                                                                                            // LINE: 209
}

namespace Effect_Type
{
    enum T : u8;                                                                                                                                                                            // LINE: 284
}

namespace Food_Quality
{
    enum T : u8;                                                                                                                                                                            // LINE: 335
}

namespace Class
{
    enum T : u8;                                                                                                                                                                            // LINE: 365
}

namespace Roll_Print_Style
{
    enum T;                                                                                                                                                                                 // LINE: 641
}

namespace Report_Turn_Taken_Status
{
    enum T : u8;                                                                                                                                                                            // LINE: 654
}

namespace Verbose
{
    enum T : u8;                                                                                                                                                                            // LINE: 664
}

namespace Forced
{
    enum T : u8;                                                                                                                                                                            // LINE: 674
}

namespace Assign_Dublicate_Identifier
{
    enum T : u8;                                                                                                                                                                            // LINE: 684
}

namespace Attack_Mod
{
    enum T;                                                                                                                                                                                 // LINE: 1016
}

namespace CMD_Result
{
    enum T : u8;                                                                                                                                                                            // LINE: 1035
}


// FILE: src\Dungeon.cpp:
struct On_Get_Stat_Value_Storage;                                                                                                                                                           // LINE: 2024
struct Leveler;                                                                                                                                                                             // LINE: 2078


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
s16 Inv(s16 v);                                                                                                                                                                             // LINE: 147

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
String To_String(u64 integer, U64_To_String_Memory* output);                                                                                                                                // LINE: 402
String Merge(String A, String B, Arena* arena);                                                                                                                                             // LINE: 443

// FILE: src\LibPrimordial\Arena.cpp:
void Initialize_Arena(Arena* arena, u64 reserve_byte_count = Gigabytes(64), u64 pages_per_commit = 16);                                                                                     // LINE: 36
Arena Create_Arena(u64 reserve_byte_count = Gigabytes(64), u64 pages_per_commit = 16);                                                                                                      // LINE: 54
void Clear(Arena* arena, Zero_Memory zero_memory);                                                                                                                                          // LINE: 63
void* Push(Arena* arena, u64 size);                                                                                                                                                         // LINE: 74
char* Push_String(Arena* arena, String str, u64* out_length);                                                                                                                               // LINE: 118
char* Push_String(Arena* arena, String str);                                                                                                                                                // LINE: 128
Arena_Snapshot Snapshot(Arena* arena);                                                                                                                                                      // LINE: 160
void Restore(Arena* arena, Arena_Snapshot snapshot);                                                                                                                                        // LINE: 167
bool Is_Taken(Arena_Snapshot snapshot);                                                                                                                                                     // LINE: 174
String To_String(Arena* arena);                                                                                                                                                             // LINE: 181

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
Effect_Offset Get_Enraged_Effect_Offset(Game_State* game_state);                                                                                                                            // LINE: 43
Effect_Offset Get_Vampirism_Effect_Offset(Game_State* game_state);                                                                                                                          // LINE: 116
Effect_Instance Get_Poison(u64 duration, Entity* source, Game_State* game_state);                                                                                                           // LINE: 175
Effect_Offset Get_Burning_Effect_Offset(Game_State* game_state);                                                                                                                            // LINE: 215
Effect_Offset Get_Festering_Rash_Effect_Offset(Game_State* game_state);                                                                                                                     // LINE: 250
Effect_Instance Get_Festering_Rash(u64 duration, Entity* source, Game_State* game_state);                                                                                                   // LINE: 277
Effect_Offset Get_Weakening_Blight_Offset(Game_State* game_state);                                                                                                                          // LINE: 288
Effect_Instance Get_Weakening_Blight(u64 duration, Entity* source, Game_State* game_state);                                                                                                 // LINE: 307
Effect_Offset Get_Devouring_Plague_Offset(Game_State* game_state);                                                                                                                          // LINE: 318
Effect_Instance Get_Devouring_Plague(u64 duration, Entity* source, Game_State* game_state);                                                                                                 // LINE: 351
Effect_Offset Get_Weak_Grip_Offset(Game_State* game_state);                                                                                                                                 // LINE: 362
void Stun_Attacker(Effect_Instance* instance, Entity* attacker, Entity* defender, Attack_Record* ar, Game_State* game_state);                                                               // LINE: 415
Effect_Instance Reckless_Attack(Entity* attacker, Game_State* game_state);                                                                                                                  // LINE: 436
Effect_Instance Careful_Attack(Entity* attacker, Game_State* game_state);                                                                                                                   // LINE: 463
Effect_Instance Weakspot_Attack(Entity* attacker, Game_State* game_state);                                                                                                                  // LINE: 493
Effect_Instance Allin_Attack(Entity* attacker, Game_State* game_state);                                                                                                                     // LINE: 520
Effect_Instance Guarding_Attack(Entity* attacker, Game_State* game_state);                                                                                                                  // LINE: 550
Effect_Instance Evasive_Attack(Entity* attacker, Game_State* game_state);                                                                                                                   // LINE: 577
Effect_Instance Execute_Attack(Entity* attacker, Game_State* game_state);                                                                                                                   // LINE: 604
Effect_Instance Disarming_Attack(Entity* attacker, Game_State* game_state);                                                                                                                 // LINE: 669
Effect_Instance Vampiric_Attack(Entity* attacker, Game_State* game_state);                                                                                                                  // LINE: 741
Effect_Instance Blessed_Attack(Entity* attacker, Game_State* game_state);                                                                                                                   // LINE: 798
Effect_Instance Berserking_Attack(Entity* attacker, Game_State* game_state);                                                                                                                // LINE: 872
Effect_Instance Redirect_Attack(Entity* attacker, Game_State* game_state);                                                                                                                  // LINE: 946
Effect_Instance Change_Attack(Entity* attacker, Game_State* game_state);                                                                                                                    // LINE: 998
Effect_Instance Thieving_Attack(Entity* attacker, Game_State* game_state);                                                                                                                  // LINE: 1098
Effect_Instance Stylish_Attack(Entity* attacker, Game_State* game_state);                                                                                                                   // LINE: 1193

// FILE: src\Items.cpp:
Loot_Table Basic_Manuals_Loot_Table(Game_State* game_state);                                                                                                                                // LINE: 24
Loot_Table Basic_Foods_Loot_Table(Game_State* game_state);                                                                                                                                  // LINE: 45
Loot_Table Basic_Consumables_Loot_Table(Game_State* game_state);                                                                                                                            // LINE: 63
Loot_Table Basic_Trinkets_Loot_Table(Game_State* game_state);                                                                                                                               // LINE: 80
Loot_Table Basic_Armors_Loot_Table(Game_State* game_state);                                                                                                                                 // LINE: 102
Loot_Table Basic_Weapons_Loot_Table(Game_State* game_state);                                                                                                                                // LINE: 141
Loot_Table Basic_Merged_Loot_Table(Game_State* game_state);                                                                                                                                 // LINE: 167
Entity* Create_Great_Sword(Entity* room, Game_State* game_state);                                                                                                                           // LINE: 184
Entity* Create_Halberd(Entity* room, Game_State* game_state);                                                                                                                               // LINE: 216
Entity* Create_Long_Spear(Entity* room, Game_State* game_state);                                                                                                                            // LINE: 249
Entity* Create_Great_Club(Entity* room, Game_State* game_state);                                                                                                                            // LINE: 282
Entity* Create_Magma_Hammer(Entity* room, Game_State* game_state);                                                                                                                          // LINE: 315
Entity* Create_War_Pick(Entity* room, Game_State* game_state);                                                                                                                              // LINE: 382
Entity* Create_Straightsword(Entity* room, Game_State* game_state);                                                                                                                         // LINE: 411
Entity* Create_Whip(Entity* room, Game_State* game_state);                                                                                                                                  // LINE: 438
Entity* Create_Mace(Entity* room, Game_State* game_state);                                                                                                                                  // LINE: 468
Entity* Create_Rapier(Entity* room, Game_State* game_state);                                                                                                                                // LINE: 495
Entity* Create_Short_Spear(Entity* room, Game_State* game_state);                                                                                                                           // LINE: 526
Entity* Create_Morning_Star(Entity* room, Game_State* game_state);                                                                                                                          // LINE: 555
Entity* Create_Three_Headed_Flail(Entity* room, Game_State* game_state);                                                                                                                    // LINE: 584
Entity* Create_Dagger(Entity* room, Game_State* game_state);                                                                                                                                // LINE: 614
Entity* Create_Poison_Dagger(Entity* room, Game_State* game_state);                                                                                                                         // LINE: 644
Entity* Create_Cape_Of_Immunity(Entity* room, Game_State* game_state);                                                                                                                      // LINE: 697
Entity* Create_Arcane_Cape(Entity* room, Game_State* game_state);                                                                                                                           // LINE: 723
Entity* Create_Cape_Of_Spite(Entity* room, Game_State* game_state);                                                                                                                         // LINE: 749
Entity* Create_Cape_Of_Avoidance(Entity* room, Game_State* game_state);                                                                                                                     // LINE: 775
Entity* Create_Cape_Of_Dashing(Entity* room, Game_State* game_state);                                                                                                                       // LINE: 801
Entity* Create_Backpack(Entity* room, Game_State* game_state);                                                                                                                              // LINE: 827
Entity* Create_Ring_Of_Giants(Entity* room, Game_State* game_state);                                                                                                                        // LINE: 856
Entity* Create_Ring_Of_Strange_Fortunes(Entity* room, Game_State* game_state);                                                                                                              // LINE: 883
Entity* Create_Ring_Of_Rebirth(Entity* room, Game_State* game_state);                                                                                                                       // LINE: 909
Entity* Create_Ring_Of_Regeneration(Entity* room, Game_State* game_state);                                                                                                                  // LINE: 968
Entity* Create_Gloves_Of_Brutality(Entity* room, Game_State* game_state);                                                                                                                   // LINE: 1024
Entity* Create_Leather_Gloves(Entity* room, Game_State* game_state);                                                                                                                        // LINE: 1051
Entity* Create_Chainmail_Gloves(Entity* room, Game_State* game_state);                                                                                                                      // LINE: 1076
Entity* Create_Plate_Gloves(Entity* room, Game_State* game_state);                                                                                                                          // LINE: 1102
Entity* Create_Wooden_Shield(Entity* room, Game_State* game_state);                                                                                                                         // LINE: 1129
Entity* Create_Buckler(Entity* room, Game_State* game_state);                                                                                                                               // LINE: 1155
Entity* Create_Kite_Shield(Entity* room, Game_State* game_state);                                                                                                                           // LINE: 1181
Entity* Create_Barn_Door_Shield(Entity* room, Game_State* game_state);                                                                                                                      // LINE: 1207
Entity* Create_Tower_Shield(Entity* room, Game_State* game_state);                                                                                                                          // LINE: 1234
Entity* Create_Shearing_Light(Entity* room, Game_State* game_state);                                                                                                                        // LINE: 1262
Entity* Create_Leather_Cuirass(Entity* room, Game_State* game_state);                                                                                                                       // LINE: 1289
Entity* Create_Gambeson(Entity* room, Game_State* game_state);                                                                                                                              // LINE: 1315
Entity* Create_Breastplate(Entity* room, Game_State* game_state);                                                                                                                           // LINE: 1342
Entity* Create_Skull_Cap(Entity* room, Game_State* game_state);                                                                                                                             // LINE: 1372
Entity* Create_Arming_Cap(Entity* room, Game_State* game_state);                                                                                                                            // LINE: 1398
Entity* Create_Chainmail_Hood(Entity* room, Game_State* game_state);                                                                                                                        // LINE: 1423
Entity* Create_Barbute(Entity* room, Game_State* game_state);                                                                                                                               // LINE: 1449
Entity* Create_Plate_Leggings(Entity* room, Game_State* game_state);                                                                                                                        // LINE: 1477
Entity* Create_Leather_Tights(Entity* room, Game_State* game_state);                                                                                                                        // LINE: 1506
Entity* Create_Padded_Pants(Entity* room, Game_State* game_state);                                                                                                                          // LINE: 1531
Entity* Create_Warrior_Kilt(Entity* room, Game_State* game_state);                                                                                                                          // LINE: 1556
Entity* Create_Barbarian_Loing_Cloth(Entity* room, Game_State* game_state);                                                                                                                 // LINE: 1583
Entity* Create_Travel_Boots(Entity* room, Game_State* game_state);                                                                                                                          // LINE: 1610
Entity* Create_Sabatons(Entity* room, Game_State* game_state);                                                                                                                              // LINE: 1637
Entity* Create_Gladiator_Sandals(Entity* room, Game_State* game_state);                                                                                                                     // LINE: 1666
Entity* Create_Leather_Boots(Entity* room, Game_State* game_state);                                                                                                                         // LINE: 1693
Entity* Create_Antidote(Entity* container, Game_State* game_state);                                                                                                                         // LINE: 1718
Entity* Create_Healing_Potion(Entity* container, Game_State* game_state);                                                                                                                   // LINE: 1758
Entity* Create_Jerky(Entity* room, Game_State* game_state);                                                                                                                                 // LINE: 1831
Entity* Create_Bread(Entity* room, Game_State* game_state);                                                                                                                                 // LINE: 1844
Entity* Create_BBQ_Wings(Entity* room, Game_State* game_state);                                                                                                                             // LINE: 1857
Entity* Create_Steak_And_Smashed_Potatoes(Entity* room, Game_State* game_state);                                                                                                            // LINE: 1870
Entity* Create_Mushroom(Entity* room, Game_State* game_state);                                                                                                                              // LINE: 1884
Entity* Create_Manual_Of_Berserking(Entity* container, Game_State* game_state);                                                                                                             // LINE: 1920
Entity* Create_Manual_Of_Blessed(Entity* container, Game_State* game_state);                                                                                                                // LINE: 1957
Entity* Create_Manual_Of_Vampiric(Entity* container, Game_State* game_state);                                                                                                               // LINE: 1994
Entity* Create_Manual_Of_Evasive(Entity* container, Game_State* game_state);                                                                                                                // LINE: 2031
Entity* Create_Manual_Of_Guarding(Entity* container, Game_State* game_state);                                                                                                               // LINE: 2068
Entity* Create_Manual_Of_Disarming(Entity* container, Game_State* game_state);                                                                                                              // LINE: 2105
Entity* Create_Manual_Of_Allin(Entity* container, Game_State* game_state);                                                                                                                  // LINE: 2142
Entity* Create_Manual_Of_Weakspot(Entity* container, Game_State* game_state);                                                                                                               // LINE: 2179
Entity* Create_Manual_Of_Careful(Entity* container, Game_State* game_state);                                                                                                                // LINE: 2216
Entity* Create_Manual_Of_Reckless(Entity* container, Game_State* game_state);                                                                                                               // LINE: 2253
Entity* Create_Manual_Of_Execute(Entity* container, Game_State* game_state);                                                                                                                // LINE: 2291
Entity* Create_Bomb(Entity* container, Game_State* game_state);                                                                                                                             // LINE: 2329
Entity* Create_Fragmentation_Bomb(Entity* container, Game_State* game_state);                                                                                                               // LINE: 2398
Entity* Create_Ring_Of_Just_Fucking_Crit(Entity* room, Game_State* game_state);                                                                                                             // LINE: 2469

// FILE: src\Factory.cpp:
void Finalize_Entity(Entity* entity, Entity* container, Game_State* game_state);                                                                                                            // LINE: 57
Entity* Create_Class_Adventurer(Game_State* game_state);                                                                                                                                    // LINE: 66
Entity* Create_Class_Wretched(Game_State* game_state);                                                                                                                                      // LINE: 109
Entity* Create_Bandit(Entity* room, Game_State* game_state);                                                                                                                                // LINE: 129
Entity* Create_Giant_Rat(Entity* room, Game_State* game_state);                                                                                                                             // LINE: 176
Entity* Create_Blight_Rat(Entity* room, Game_State* game_state);                                                                                                                            // LINE: 236
Entity* Create_Enlarged_Ant(Entity* room, Game_State* game_state);                                                                                                                          // LINE: 356
Entity* Create_Enlarged_Ant_Queen(Entity* room, Game_State* game_state);                                                                                                                    // LINE: 402
Entity* Create_Bear_Cub(Entity* room, Game_State* game_state);                                                                                                                              // LINE: 484
Entity* Create_Mutant_Hedgehog(Entity* room, Game_State* game_state);                                                                                                                       // LINE: 546
Entity* Create_Training_Dummmy(Entity* room, Game_State* game_state);                                                                                                                       // LINE: 633
Entity* Create_Mimic(Entity* room, Game_State* game_state);                                                                                                                                 // LINE: 655
Entity* Create_Chest(Entity* room, Game_State* game_state);                                                                                                                                 // LINE: 750
Entity* Create_Weapon_Rack(Entity* room, Game_State* game_state);                                                                                                                           // LINE: 790
Entity* Create_Armor_Rack(Entity* room, Game_State* game_state);                                                                                                                            // LINE: 823
Entity* Create_Supply_Crate(Entity* room, Game_State* game_state);                                                                                                                          // LINE: 856
Entity* Create_Alchemists_Pouch(Entity* room, Game_State* game_state);                                                                                                                      // LINE: 889
Entity* Create_Rat_Mound(Entity* room, Game_State* game_state);                                                                                                                             // LINE: 923
Entity* Create_Spider(Entity* room, Game_State* game_state);                                                                                                                                // LINE: 984
Entity* Create_Boss_Spider(Entity* room, Game_State* game_state);                                                                                                                           // LINE: 1019
void Generate_Entrance_Room(Entity* room, Game_State* game_state);                                                                                                                          // LINE: 1066
Loot_Table Caves_Wildlife_Section(Game_State* game_state);                                                                                                                                  // LINE: 1083
Loot_Table Caves_Bandit_Section(Game_State* game_state);                                                                                                                                    // LINE: 1590
Loot_Table Caves_Spider_Section(Game_State* game_state);                                                                                                                                    // LINE: 1628
Loot_Table Caves_Boss(Game_State* game_state);                                                                                                                                              // LINE: 1663
_inline Level_Segments Caves(Game_State* game_state);                                                                                                                                       // LINE: 1698

// FILE: src\Dungeon.cpp:
char* Get_Output_Color_CSTR(ANSI_Color_Buffer* buffer, u8 red, u8 green, u8 blue);                                                                                                          // LINE: 58
char* Entity_Color(Entity* entity, Game_State* game_state);                                                                                                                                 // LINE: 68
String Format_Message(Game_State* game_state, char* format_string, ...);                                                                                                                    // LINE: 95
_inline void Flush_Messages(Game_State* game_state);                                                                                                                                        // LINE: 114
_inline void Print_Messages(Game_State* game_state);                                                                                                                                        // LINE: 121
void Push_Message(String message, Game_State* game_state);                                                                                                                                  // LINE: 139
void Wait(f64 seconds, Game_State* game_state);                                                                                                                                             // LINE: 154
String Get_User_Input(Game_State* game_state);                                                                                                                                              // LINE: 163
bool User_Query_Yes_No(Game_State* game_state);                                                                                                                                             // LINE: 182
u64 Base_Alphabet_Digits(u64 v);                                                                                                                                                            // LINE: 216
u64 Encode_Base_Alphabet(u64 identity, char character);                                                                                                                                     // LINE: 236
U64_To_String_Memory Decode_Base_Aplhabet(u64 identity);                                                                                                                                    // LINE: 247
Entity_Offset* Find_Empty_Slot(Entity_Node* node);                                                                                                                                          // LINE: 266
Ambush_Creature_Spawner_Offset Offset(Ambush_Creature_Spawner* pointer, Game_State* game_state);                                                                                            // LINE: 291
Ambush_Creature_Spawner* Pointer(Ambush_Creature_Spawner_Offset offset, Game_State* game_state);                                                                                            // LINE: 303
Ambush_Option_Offset Offset(Ambush_Option* pointer, Game_State* game_state);                                                                                                                // LINE: 315
Ambush_Option* Pointer(Ambush_Option_Offset offset, Game_State* game_state);                                                                                                                // LINE: 327
_inline Entity_Offset Offset(Entity* entity, Game_State* game_state);                                                                                                                       // LINE: 339
_inline Entity* Pointer(Entity_Offset offset, Game_State* game_state);                                                                                                                      // LINE: 351
_inline Effect_Offset Offset(Effect* effect, Game_State* game_state);                                                                                                                       // LINE: 367
_inline Effect* Pointer(Effect_Offset offset, Game_State* game_state);                                                                                                                      // LINE: 380
_inline Entity_Node_Offset Offset(Entity_Node* entity_node, Game_State* game_state);                                                                                                        // LINE: 393
_inline Entity_Node* Pointer(Entity_Node_Offset offset, Game_State* game_state);                                                                                                            // LINE: 405
_inline Effects_Node_Offset Offset(Effects_Node* effects_node, Game_State* game_state);                                                                                                     // LINE: 417
_inline Effects_Node* Pointer(Effects_Node_Offset offset, Game_State* game_state);                                                                                                          // LINE: 429
String Unwrap_String(String_Wrapper* strw, Game_State* game_state);                                                                                                                         // LINE: 441
String_Offset Offset(String str, Game_State* game_state);                                                                                                                                   // LINE: 449
String Get_String(String_Offset offset, Game_State* game_state);                                                                                                                            // LINE: 516
_inline u64 Storage_Offset(void* ptr, Game_State* game_state);                                                                                                                              // LINE: 529
_inline void* Pull_From_Storage_Offset(u64 offset, Game_State* game_state);                                                                                                                 // LINE: 542
Entity_Offset* Find_Entity(Entity* entity, Entity_Root_Node* storage, Game_State* game_state, Entity_Node** out_node = 0);                                                                  // LINE: 555
Entity* Find_Entity_By_Name_Or_Reference_Number(Entity* actor, Entity_Offset space, String name_or_reference_number, Game_State* game_state, Verbose::T verbose = Verbose::T(1));           // LINE: 582
Entity* Find_Entity_By_Name(Entity* actor, Entity* space, String name, Game_State* game_state, Verbose::T verbose = Verbose::T(1));                                                         // LINE: 594
Entity* Find_Entity_By_Name_Or_Reference_Number(Entity* actor, Entity* space, String name_or_reference_number, Game_State* game_state, Verbose::T verbose = Verbose::T(1));                 // LINE: 626
Entity_Iterator Make_Iterator(Entity_Root_Node* root, Game_State* game_state);                                                                                                              // LINE: 667
Entity_Iterator Make_Iterator(Entity* entity, Game_State* game_state);                                                                                                                      // LINE: 685
Effects_Iterator Make_Iterator(Effects_Root* root, Game_State* game_state);                                                                                                                 // LINE: 693
Entity_Offset* Next(Entity_Iterator* iter);                                                                                                                                                 // LINE: 712
Entity* Next_Entity(Entity_Iterator* iter);                                                                                                                                                 // LINE: 742
u64 Count(Entity_Root_Node* root_node, Game_State* game_state);                                                                                                                             // LINE: 756
bool Memory_Snapshot_Save(String file_path, Game_State* game_state);                                                                                                                        // LINE: 769
bool Memory_Snapshot_Restore(String file_path, Game_State* game_state);                                                                                                                     // LINE: 778
Effect_Instance* Next_Effect_Instance(Effects_Iterator* iter);                                                                                                                              // LINE: 810
_inline Effect_Instance* Next(Effects_Iterator* iter);                                                                                                                                      // LINE: 843
Effect* Next_Effect(Effects_Iterator* iter);                                                                                                                                                // LINE: 850
Backwards_Iterator Make_Backwards_Iterator(Entity_Root_Node* root, Game_State* game_state);                                                                                                 // LINE: 864
Entity_Offset* Previous(Backwards_Iterator* back_iter);                                                                                                                                     // LINE: 878
void Add_Dice(Effect* effect, s16 count, s16 faces);                                                                                                                                        // LINE: 922
u64 Per_Count_Rolled_Square_Weighted_Random(u64 count, Game_State* game_state);                                                                                                             // LINE: 951
u64 Per_Count_Rolled_Random(u64 count, u32 change, Game_State* game_state);                                                                                                                 // LINE: 966
u32 Roll(u32 range, Game_State* game_state);                                                                                                                                                // LINE: 981
s32 Roll(Dice dice, Game_State* game_state);                                                                                                                                                // LINE: 993
s32* Roll_With_Record(Dice dice, Game_State* game_state);                                                                                                                                   // LINE: 1009
f32 Random_F32(Game_State* game_state);                                                                                                                                                     // LINE: 1023
Roll_Result Stat_Roll(s32 value, Stats::T stat, Game_State* game_state);                                                                                                                    // LINE: 1033
s32 Value(Roll_Result rr);                                                                                                                                                                  // LINE: 1049
Roll_Result Stat_Roll(Entity* entity, Stats::T stat, Game_State* game_state);                                                                                                               // LINE: 1056
_inline bool Is_Rolled(Roll_Result rr);                                                                                                                                                     // LINE: 1067
void Print_Dice(Dice dice, s32 result);                                                                                                                                                     // LINE: 1074
void Print_Roll_Result(Roll_Result rr);                                                                                                                                                     // LINE: 1080
void Print_Attack_Record(Attack_Record* ar, Game_State* game_state);                                                                                                                        // LINE: 1093
String Name_Without_Color(Entity* entity, Game_State* game_state);                                                                                                                          // LINE: 1356
String Name(Entity* entity, Game_State* game_state);                                                                                                                                        // LINE: 1371
char* Action_Name(AT::T action);                                                                                                                                                            // LINE: 1391
void Print_Required_Equipment_Slots(Entity* item);                                                                                                                                          // LINE: 1418
void Push_Generic_Apply_Effect_Message(String source_name, Entity* target, Effect_Instance new_effect, Apply_Effect_Result apply, Game_State* game_state);                                  // LINE: 1442
void Remove_From_Residence(Entity* entity, Game_State* game_state);                                                                                                                         // LINE: 1498
void Release_Entity_Node(Entity_Root_Node* root, Game_State* game_state);                                                                                                                   // LINE: 1532
Entity_Node* Request_Entity_Node(Game_State* game_state);                                                                                                                                   // LINE: 1554
Effect* Request_Effect(Game_State* game_state);                                                                                                                                             // LINE: 1571
void Release_Effect(Effect* effect, Game_State* game_state);                                                                                                                                // LINE: 1594
Entity* Request_Entity(Game_State* game_state);                                                                                                                                             // LINE: 1608
void Release_Entity(Entity* entity, Game_State* game_state);                                                                                                                                // LINE: 1630
Effects_Node* Request_Effects_Node(Game_State* game_state);                                                                                                                                 // LINE: 1638
void Release_Effects_Node(Effects_Node* node, Game_State* game_state);                                                                                                                      // LINE: 1655
void Insert(Entity* entity, Entity_Root_Node* storage, Game_State* game_state);                                                                                                             // LINE: 1663
void Assign_Dublicate_Name_Identifier(Entity* entity_to_insert, Entity* storage, Game_State* game_state);                                                                                   // LINE: 1700
void Deep_Insert(Entity* entity, Entity* storage_entity, Game_State* game_state, Assign_Dublicate_Identifier::T assign_dublicate_identifier = Assign_Dublicate_Identifier::T(1));           // LINE: 1734
Ambush_Option* Request_Ambush_Option(Game_State* game_state);                                                                                                                               // LINE: 1754
void Release_Ambush_Option(Ambush_Option* ambush_option, Game_State* game_state);                                                                                                           // LINE: 1771
Ambush_Creature_Spawner* Request_Ambush_Creature_Spawner(Game_State* game_state);                                                                                                           // LINE: 1779
void Release_Ambush_Creature_Spawner(Ambush_Creature_Spawner* spawner, Game_State* game_state);                                                                                             // LINE: 1796
Ambush_Option* Create_Ambush_Option(f32 change, Game_State* game_state);                                                                                                                    // LINE: 1804
void Add_Ambush_Creature_Spawner(Ambush_Option* ambush, Ambush_Creature_Spawner spawner, Game_State* game_state);                                                                           // LINE: 1815
void Reset_Ambush_Table(Game_State* game_state);                                                                                                                                            // LINE: 1824
void Set_Ambush_Change(f32 change, Game_State* game_state);                                                                                                                                 // LINE: 1846
bool Trigger_Ambush(Entity* room, Game_State* game_state, Entity*** out_spawned_entities, u64* out_spawned_count);                                                                          // LINE: 1852
bool Is_The_Same(Entity* A, Entity* B, Game_State* game_state);                                                                                                                             // LINE: 1914
void Remove_All_Effects(Entity* entity, Game_State* game_state);                                                                                                                            // LINE: 1944
void Delete_Entity(Entity* entity, Game_State* game_state);                                                                                                                                 // LINE: 2004
bool Has_Content(Entity_Root_Node* root);                                                                                                                                                   // LINE: 2011
bool Is_Empty(Entity_Root_Node* root);                                                                                                                                                      // LINE: 2018
s32 Get_Stat_Value(Entity* entity, Stats::T stat, Game_State* game_state, u64* out_effect_count = 0);                                                                                       // LINE: 2031
void Ding(Entity* actor, Game_State* game_state);                                                                                                                                           // LINE: 2088
s32 Exp_To_Level_Up(s32 _lvl);                                                                                                                                                              // LINE: 2135
_inline s32 Exp_To_Level_Up(Entity* entity);                                                                                                                                                // LINE: 2143
s16 Calculate_Level(Entity* entity);                                                                                                                                                        // LINE: 2150
void Set_Level_Based_On_Stats(Entity* entity);                                                                                                                                              // LINE: 2163
s32 Exp_Reward(Entity* entity);                                                                                                                                                             // LINE: 2170
s16 Level(Entity* entity);                                                                                                                                                                  // LINE: 2183
s32 Max_Health(Entity* entity, Game_State* game_state);                                                                                                                                     // LINE: 2190
f32 Critical_Multiplier(Entity* entity, Game_State* game_state);                                                                                                                            // LINE: 2203
s32 Carry_Capacity(Entity* entity, Game_State* game_state);                                                                                                                                 // LINE: 2210
s32 Carrying_Amount(Entity* entity, Game_State* game_state);                                                                                                                                // LINE: 2230
Critical_Ranges_Result Critical_Ranges(Entity* entity, Game_State* game_state, u32* out_success_effecting_count = 0, u32* out_failure_effecing_count = 0);                                  // LINE: 2243
void Full_Heal(Entity* entity, Game_State* game_state);                                                                                                                                     // LINE: 2285
bool Is_Item(Entity* entity);                                                                                                                                                               // LINE: 2291
bool Is_Visible(Entity* entity, Entity* actor, Game_State* game_state);                                                                                                                     // LINE: 2298
bool Is_Alive(Entity* entity);                                                                                                                                                              // LINE: 2307
bool Is_Hostile_Against(Entity* A, Entity* B);                                                                                                                                              // LINE: 2314
bool Is_Living_Enemy_Of(Entity* actor, Entity* target);                                                                                                                                     // LINE: 2321
bool Is_Living_Active_Enemy_Of(Entity* actor, Entity* target);                                                                                                                              // LINE: 2328
s32 Give_Temporary_Health(Entity* entity, s32 amount, String source_name, Verbose::T verbose, Game_State* game_state);                                                                      // LINE: 2335
Healing_Result Heal(Entity* entity, s32 amount, String source_name, Verbose::T verbose, Game_State* game_state);                                                                            // LINE: 2356
Deal_Damage_Result Deal_Damage(Entity* defender, Entity_Offset attacker_offset, String source_name, s32 dmg, s32 pierce, Damage_Type type, Game_State* game_state, Verbose::T verbose);     // LINE: 2426
_inline Deal_Damage_Result Deal_Damage(Entity* defender, Entity* attacker, String dmg_src_name, s32 dmg, s32 pierce, Damage_Type type, Game_State* game_state, Verbose::T verbose);         // LINE: 2609
void Proc_Effects(u64 offset, Entity* attacker, Entity* defender, Attack_Record* ar, Game_State* game_state);                                                                               // LINE: 2617
void Proc_Effects(u64 offset, Entity* target, Game_State* game_state);                                                                                                                      // LINE: 2634
String Effect_Name(Effect_Instance* instance, Game_State* game_state);                                                                                                                      // LINE: 2650
u64 Count_Effect_Instances(Effects_Root* root, Effect_Instance cmp, Game_State* game_state, Effect_Instance** out_shortest_duration = 0);                                                   // LINE: 2670
void Delete_Effect_Slot(Effects_Root* root, Effects_Node* node, u64 *idx, u64* count, Game_State* game_state);                                                                              // LINE: 2700
Effect_Instance* New_Effect_Slot(Effects_Root* root, Game_State* game_state);                                                                                                               // LINE: 2740
Apply_Check_Record Application_Check(Entity* attacker, Entity* defender, Game_State* game_state);                                                                                           // LINE: 2786
void Attempt_Infection(Entity* attacker, Entity* defender, String source_name, Effect_Instance infectious_effect_instance, Game_State* game_state);                                         // LINE: 2799
Apply_Effect_Result Apply_Effect(Entity* target, Effect_Instance instance, Game_State* game_state, Forced::T forced = Forced::T(0));                                                        // LINE: 2832
void Remove_Effects_From_Source(Entity* actor, Entity* source, Game_State* game_state);                                                                                                     // LINE: 2889
u64 Remove_Effects_Of_Type(Entity* actor, Effect_Type::T type_to_remove, Game_State* game_state, Verbose::T verbose);                                                                       // LINE: 2914
void Print_Equiped_Weapons(Entity* target, bool preamble, Game_State* game_state);                                                                                                          // LINE: 3143
void Inspect(Entity* target, Game_State* game_state);                                                                                                                                       // LINE: 3181
bool Is_Equipped(Entity* actor, Entity* item, Game_State* game_state);                                                                                                                      // LINE: 3232
bool Unequip(Entity* actor, Entity* item, Game_State* game_state);                                                                                                                          // LINE: 3255
bool Unequip(Entity* item, Game_State* game_state);                                                                                                                                         // LINE: 3279
bool Use(Entity* actor, Entity* item, Game_State* game_state, Verbose::T verbose);                                                                                                          // LINE: 3287
bool Equip(Entity* actor, Entity* target, Game_State* game_state, Verbose::T verbose = Verbose::T(0));                                                                                      // LINE: 3327
void Print_Uses(Entity* entity);                                                                                                                                                            // LINE: 3540
void Open(Entity* actor, Game_State* game_state);                                                                                                                                           // LINE: 3560
u64 Longest_Entity_Name_In_Actor_Storage(Entity* actor, Game_State* game_state, u64* out_count = 0);                                                                                        // LINE: 3588
bool Glance(Entity* actor, Game_State* game_state, Report_Turn_Taken_Status::T report_turn_taken_status = Report_Turn_Taken_Status::T(1));                                                  // LINE: 3613
void Remove_Random_Effect(Entity* entity, String source_name, Game_State* game_state);                                                                                                      // LINE: 3695
Damage_Modifiers_Result Damage_Modifier_From_Effects(Entity* attacker, Attack_Record* ar, Game_State* game_state);                                                                          // LINE: 3734
u64 Attack_Modifier_Mask(Attack_Mod::T modifier);                                                                                                                                           // LINE: 3828
u64 Class_Mask(Class::T _class);                                                                                                                                                            // LINE: 3835
bool Can_Use_Attack_Modifier(Entity* entity, Attack_Mod::T modifier);                                                                                                                       // LINE: 3842
void Apply_Or_Describe_Attak_Modifier(Entity** attacker_ptr, Entity** defender_ptr, Attack_Mod::T modifier, Game_State* game_state);                                                        // LINE: 3853
void Proc_Thorns(Entity* attacker, Entity* defender, Game_State* game_state);                                                                                                               // LINE: 4000
void Attack(Entity* attacker, Entity* defender, Game_State* game_state, Attack_Mod::T modifier = Attack_Mod::T(0));                                                                         // LINE: 4023
void Player_Action(Entity* actor, String actor_name, Game_State* game_state);                                                                                                               // LINE: 4100
Entity* Redirected_Target(Entity* actor, String actor_name, Game_State* game_state);                                                                                                        // LINE: 4189
Entity* Random_Entity_That_Matches_Criteria(Entity_Root_Node* storage, bool(*conditional)(Entity* entity, void* user_ptr, Game_State* game_state), void* user_ptr, Game_State* game_state); // LINE: 4227
Entity* Find_Attack_Target(Entity* actor, Game_State* game_state);                                                                                                                          // LINE: 4266
void NPC_Action(Entity* actor, String actor_name, Game_State* game_state);                                                                                                                  // LINE: 4295
void Take_Action(Entity* actor, Game_State* game_state);                                                                                                                                    // LINE: 4373
u64 Hash_From_Key(Effect_Hash_Key key);                                                                                                                                                     // LINE: 4445
bool Retrive_Effect(Effect_Hash_Key key, Effect_Offset* out, Game_State* game_state);                                                                                                       // LINE: 4452
Effect_Offset Insert_Effect(Effect effect, Effect_Hash_Key key, Game_State* game_state);                                                                                                    // LINE: 4490
bool Compare(s64 X, Comparison type, s64 A, s64 B = 0);                                                                                                                                     // LINE: 4528
bool Is_Compliant(Loot_Table_Entry entry, Pick_From_Table_Rules rules);                                                                                                                     // LINE: 4558
Loot_Table_Pick_Result Pick_From_Loot_Table(Loot_Table table, u64 count, Pick_From_Table_Rules rules, Game_State* game_state);                                                              // LINE: 4584
GENERATE_ENTITY_FN* Pick_From_Loot_Table(Loot_Table table, Pick_From_Table_Rules rules, Game_State* game_state);                                                                            // LINE: 4636
void Generate_From_Loot_Table(Entity* storage, Loot_Table table, u64 count, Pick_From_Table_Rules rules, Game_State* game_state);                                                           // LINE: 4643
Loot_Table Merge_Loot_Tables(Loot_Table* tables, u64 count, Arena* arena);                                                                                                                  // LINE: 4653
Loot_Table Merge_Loot_Tables(Loot_Table A, Loot_Table B, Arena* arena);                                                                                                                     // LINE: 4667
Loot_Table Merge_Loot_Tables(Loot_Table A, Loot_Table B, Loot_Table C, Arena* arena);                                                                                                       // LINE: 4678
Loot_Table Merge_Loot_Tables(Loot_Table A, Loot_Table B, Loot_Table C, Loot_Table D, Arena* arena);                                                                                         // LINE: 4685
Loot_Table Merge_Loot_Tables(Loot_Table A, Loot_Table B, Loot_Table C, Loot_Table D, Loot_Table E, Arena* arena);                                                                           // LINE: 4692
Loot_Table Merge_Loot_Tables(Loot_Table A, Loot_Table B, Loot_Table C, Loot_Table D, Loot_Table E, Loot_Table F, Arena* arena);                                                             // LINE: 4699
void Fill_Loot_Table_Changes_And_Item_Rarity(Loot_Table* table, Game_State* game_state);                                                                                                    // LINE: 4706
bool Roll_Initiative(Entity* entity, Game_State* game_state);                                                                                                                               // LINE: 4779
void Sort_Iniative_Order(Entity_Offset* offs, Game_State* game_state);                                                                                                                      // LINE: 4813
void Sort_Space(Entity_Root_Node* space, Game_State* game_state);                                                                                                                           // LINE: 4944
u64 Count_Longest_Round_Effect_Duration(Entity* actor, Game_State* game_state);                                                                                                             // LINE: 5020
void Tick_Down_Effect_Durations(Entity* actor, Duration_Type type, Game_State* game_state);                                                                                                 // LINE: 5035
_inline void Enter_A_Room_Printout(Entity* player, Entity* room, Game_State* game_state);                                                                                                   // LINE: 5109
CMD_Result::T Attempt_To_Execute_Command(Command* commands, u64 count, String user_input, void* user_ptr, Game_State* game_state);                                                          // LINE: 5132
CMD_Result::T Prompt_User_For_Command_And_Attempt_To_Execute(Command* commands, u64 count, void* user_ptr, Game_State* game_state);                                                         // LINE: 5238
void Create_Player_Charater(Game_State* game_state);                                                                                                                                        // LINE: 5246
void Tick_Active_Effects_Down_To_Zero(Entity* actor, Game_State* game_state);                                                                                                               // LINE: 5343
Entity* Next_Room(Level_Segments level, Game_State* game_state);                                                                                                                            // LINE: 5368
void Proceed(Game_State* game_state);                                                                                                                                                       // LINE: 5415
void Prepare_Game_Round(Game_State* game_state);                                                                                                                                            // LINE: 5483
void Excecute_Game_Round(Game_State* game_state);                                                                                                                                           // LINE: 5595
void Exit_Handling(Game_State* game_state);                                                                                                                                                 // LINE: 5633
bool Play_Game(Game_State* game_state);                                                                                                                                                     // LINE: 5665
void Reset_Game_State(Game_State* game_state);                                                                                                                                              // LINE: 5695
Game_State* Create_Game_State();                                                                                                                                                            // LINE: 5750
CMD_Result::T Kill_Command(Entity* actor, String args, Game_State* game_state);                                                                                                             // LINE: 5781
CMD_Result::T Toggle_Dramatic_Pause(Entity* actor, String args, Game_State* game_state);                                                                                                    // LINE: 5808
CMD_Result::T Toggle_Godmode(Entity* actor, String args, Game_State* game_state);                                                                                                           // LINE: 5832
CMD_Result::T Help_Command(Entity* entity, String args, Game_State* game_state);                                                                                                            // LINE: 5851
CMD_Result::T Attacks_Command(Entity* entity, String args, Game_State* game_state);                                                                                                         // LINE: 5891
CMD_Result::T Pickup_Command(Entity* actor, String args, Game_State* game_state);                                                                                                           // LINE: 5944
CMD_Result::T Inventory_Command(Entity* actor, String args, Game_State* game_state);                                                                                                        // LINE: 5993
CMD_Result::T Proceed_Command(Entity* actor, String args, Game_State* game_state);                                                                                                          // LINE: 6164
CMD_Result::T Equipment_Command(Entity* actor, String args, Game_State* game_state);                                                                                                        // LINE: 6261
CMD_Result::T Drop_Command(Entity* actor, String args, Game_State* game_state);                                                                                                             // LINE: 6296
CMD_Result::T Use_Command(Entity* actor, String args, Game_State* game_state);                                                                                                              // LINE: 6326
CMD_Result::T Equip_Command(Entity* actor, String args, Game_State* game_state);                                                                                                            // LINE: 6350
CMD_Result::T Unequip_Command(Entity* actor, String args, Game_State* game_state);                                                                                                          // LINE: 6372
CMD_Result::T Stats_Command(Entity* actor, String args, Game_State* game_state);                                                                                                            // LINE: 6401
CMD_Result::T Camp_Command(Entity* actor, String args, Game_State* game_state);                                                                                                             // LINE: 6516
CMD_Result::T Status_Command(Entity* actor, String args, Game_State* game_state);                                                                                                           // LINE: 6619
CMD_Result::T Inspect_Command(Entity* actor, String args, Game_State* game_state);                                                                                                          // LINE: 6673
CMD_Result::T What_Is_Seed_Command(Entity* entity, String args, Game_State* game_state);                                                                                                    // LINE: 6714
CMD_Result::T Pass_Command(Entity* actor, String args, Game_State* game_state);                                                                                                             // LINE: 6730
CMD_Result::T Glance_Command(Entity* actor, String args, Game_State* game_state);                                                                                                           // LINE: 6746
CMD_Result::T Search_Command(Entity* actor, String args, Game_State* game_state);                                                                                                           // LINE: 6770
CMD_Result::T Restart_Command(Entity* actor, String args, Game_State* game_state);                                                                                                          // LINE: 6818
CMD_Result::T Save_Command(Entity* actor, String args, Game_State* game_state);                                                                                                             // LINE: 6853
CMD_Result::T Load_Command(Entity* actor, String args, Game_State* game_state);                                                                                                             // LINE: 6879
CMD_Result::T Exit_Command(Entity* actor, String args, Game_State* game_state);                                                                                                             // LINE: 6905
CMD_Result::T Loot_Command(Entity* actor, String args, Game_State* game_state);                                                                                                             // LINE: 6943
CMD_Result::T Attack_Command(Entity* actor, String args, Game_State* game_state);                                                                                                           // LINE: 7021
CMD_Result::T Set_Seed_Command(Entity* actor, String args, Game_State* game_state);                                                                                                         // LINE: 7084
void Get_Level_Up_Commands(Command** out_commands, u64* out_count, Game_State* game_state);                                                                                                 // LINE: 7114
void Get_Character_Creator_Commands(Command** out_commands, u64* out_count, Game_State* game_state);                                                                                        // LINE: 7490
