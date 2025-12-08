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
struct PROTOTYPE_ENT_GS_Offset;                                                                                                                                                             // LINE: 10
struct PROTOTYPE_ENT_ENT_GS_Offset;                                                                                                                                                         // LINE: 15
struct PROTOTYPE_EFFINST_ENT_GS_Offset;                                                                                                                                                     // LINE: 20
struct PROTOTYPE_EFFINST_ENT_ENT_AR_GS_Offset;                                                                                                                                              // LINE: 25
struct PROTOTYPE_EFFINST_REF_ENT_DDR_GS_Offset;                                                                                                                                             // LINE: 30
struct PROTOTYPE_EFFINST_ENT_S32PTR_STR_GS_Offset;                                                                                                                                          // LINE: 35
struct PROTOTYPE_EFFINST_ENT_STAT_S32PTR_S16PTR_GS_Offset;                                                                                                                                  // LINE: 40

// FILE: src\Stats.cpp:
namespace Stats
{
    enum T;                                                                                                                                                                                 // LINE: 18
}


// FILE: src\Dungeon.h:
union Color;                                                                                                                                                                                // LINE: 23
struct Entity_Offset;                                                                                                                                                                       // LINE: 74
struct Effect_Offset;                                                                                                                                                                       // LINE: 80
struct Effects_Node_Offset;                                                                                                                                                                 // LINE: 87
struct Entity_Node_Offset;                                                                                                                                                                  // LINE: 100
struct String_Offset;                                                                                                                                                                       // LINE: 106
struct String_Wrapper;                                                                                                                                                                      // LINE: 112
struct String_Table;                                                                                                                                                                        // LINE: 119
struct String_Table_Root;                                                                                                                                                                   // LINE: 127
struct Reference;                                                                                                                                                                           // LINE: 134
struct Entity_Node;                                                                                                                                                                         // LINE: 141
struct Entity_Root_Node;                                                                                                                                                                    // LINE: 148
struct Dice;                                                                                                                                                                                // LINE: 192
struct Bonus_Dice;                                                                                                                                                                          // LINE: 199
struct Effect;                                                                                                                                                                              // LINE: 216
enum class Apply_Effect_Result : u8;                                                                                                                                                        // LINE: 277
enum class Duration_Type : u8;                                                                                                                                                              // LINE: 290
struct Effect_Instance;                                                                                                                                                                     // LINE: 336
struct Effects_Node;                                                                                                                                                                        // LINE: 373
struct Effects_Root;                                                                                                                                                                        // LINE: 384
struct Roll_Result;                                                                                                                                                                         // LINE: 392
struct Initiative;                                                                                                                                                                          // LINE: 402
struct Interactable;                                                                                                                                                                        // LINE: 410
enum class Faction : u8;                                                                                                                                                                    // LINE: 418
struct Entity;                                                                                                                                                                              // LINE: 428
struct Damage_Modifier;                                                                                                                                                                     // LINE: 474
struct Healing_Result;                                                                                                                                                                      // LINE: 485
struct Deal_Damage_Result;                                                                                                                                                                  // LINE: 496
enum class Damage_Type;                                                                                                                                                                     // LINE: 508
struct Critical_Ranges_Result;                                                                                                                                                              // LINE: 515
struct Message_Pipe;                                                                                                                                                                        // LINE: 522
struct Attack_Record;                                                                                                                                                                       // LINE: 529
struct Entity_Iterator;                                                                                                                                                                     // LINE: 608
struct Backwards_Iterator;                                                                                                                                                                  // LINE: 623
struct Effects_Iterator;                                                                                                                                                                    // LINE: 633
struct Permanent_Effects_Table;                                                                                                                                                             // LINE: 645
struct Game_State;                                                                                                                                                                          // LINE: 677
struct Character_Creator;                                                                                                                                                                   // LINE: 725
struct Room_Generator_Element;                                                                                                                                                              // LINE: 735
struct Room_Generator_Element_Array;                                                                                                                                                        // LINE: 742
struct Game_Command;                                                                                                                                                                        // LINE: 831
enum class Call_Style;                                                                                                                                                                      // LINE: 842
struct Command;                                                                                                                                                                             // LINE: 850
typedef void PROTOTYPE_ENT_GS(Entity*, Game_State*);;                                                                                                                                       // LINE: 943
typedef void PROTOTYPE_ENT_ENT_GS(Entity*, Entity*, Game_State*);;                                                                                                                          // LINE: 944
typedef void PROTOTYPE_EFFINST_ENT_GS(Effect_Instance*, Entity*, Game_State*);;                                                                                                             // LINE: 945
typedef void PROTOTYPE_EFFINST_ENT_ENT_AR_GS(Effect_Instance*, Entity*, Entity*, Attack_Record*, Game_State*);;                                                                             // LINE: 946
typedef void PROTOTYPE_EFFINST_REF_ENT_DDR_GS(Effect_Instance*, Reference, Entity*, Deal_Damage_Result*, Game_State*);;                                                                     // LINE: 947
typedef void PROTOTYPE_EFFINST_ENT_S32PTR_STR_GS(Effect_Instance*, Entity*, s32*, String, Game_State*);;                                                                                    // LINE: 948
typedef void PROTOTYPE_EFFINST_ENT_STAT_S32PTR_S16PTR_GS(Effect_Instance*, Entity*, Stats::T, s32*, s16*, Game_State*);;                                                                    // LINE: 949
namespace AT
{
    enum T : u8;                                                                                                                                                                            // LINE: 40
}

namespace EFlags
{
    enum T : u64;                                                                                                                                                                           // LINE: 53
}

namespace Equipment_Slots
{
    enum T : u32;                                                                                                                                                                           // LINE: 172
}

namespace Effect_Flags
{
    enum T : s8;                                                                                                                                                                            // LINE: 208
}

namespace Effect_Type
{
    enum T : u8;                                                                                                                                                                            // LINE: 262
}

namespace Class
{
    enum T : u8;                                                                                                                                                                            // LINE: 314
}

namespace Roll_Print_Style
{
    enum T;                                                                                                                                                                                 // LINE: 567
}

namespace Report_Turn_Taken_Status
{
    enum T : u8;                                                                                                                                                                            // LINE: 580
}

namespace Verbose
{
    enum T : u8;                                                                                                                                                                            // LINE: 590
}

namespace Forced
{
    enum T : u8;                                                                                                                                                                            // LINE: 600
}

namespace Attack_Mod
{
    enum T;                                                                                                                                                                                 // LINE: 802
}

namespace CMD_Result
{
    enum T : u8;                                                                                                                                                                            // LINE: 821
}


// FILE: src\Dungeon.cpp:
struct On_Get_Stat_Value_Storage;                                                                                                                                                           // LINE: 1516


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
f32 Square_Root(f32 v);                                                                                                                                                                     // LINE: 30
u32 Random_PCG(u32 seed);                                                                                                                                                                   // LINE: 43
u32 Random_PCG(u32* pcg_state);                                                                                                                                                             // LINE: 51
s32 Round_To_S32(f32 v);                                                                                                                                                                    // LINE: 63
f32 Round(f32 v);                                                                                                                                                                           // LINE: 72

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
char* Push_String(Arena* arena, String str, u64* out_length);                                                                                                                               // LINE: 117
char* Push_String(Arena* arena, String str);                                                                                                                                                // LINE: 127
Arena_Snapshot Snapshot(Arena* arena);                                                                                                                                                      // LINE: 136
void Restore(Arena* arena, Arena_Snapshot snapshot);                                                                                                                                        // LINE: 143
bool Is_Taken(Arena_Snapshot snapshot);                                                                                                                                                     // LINE: 150
String To_String(Arena* arena);                                                                                                                                                             // LINE: 157

// FILE: src\LibPrimordial\Win32.cpp:
f64 OS_Time();                                                                                                                                                                              // LINE: 17
void OS_Sleep(f64 seconds);                                                                                                                                                                 // LINE: 27
String OS_Read_File(String path, Arena* arena);                                                                                                                                             // LINE: 37
bool OS_Write_File(String buffer, String path, Arena* arena);                                                                                                                               // LINE: 111
void* OS_Get_Executable_Base_Address();                                                                                                                                                     // LINE: 173

// FILE: src\Generated_Offsets.cpp:
_inline PROTOTYPE_ENT_GS_Offset Offset(PROTOTYPE_ENT_GS* pointer, Game_State* game_state);                                                                                                  // LINE: 11
_inline PROTOTYPE_ENT_GS* Pointer(PROTOTYPE_ENT_GS_Offset offset, Game_State* game_state);                                                                                                  // LINE: 22
_inline PROTOTYPE_ENT_ENT_GS_Offset Offset(PROTOTYPE_ENT_ENT_GS* pointer, Game_State* game_state);                                                                                          // LINE: 34
_inline PROTOTYPE_ENT_ENT_GS* Pointer(PROTOTYPE_ENT_ENT_GS_Offset offset, Game_State* game_state);                                                                                          // LINE: 45
_inline PROTOTYPE_EFFINST_ENT_GS_Offset Offset(PROTOTYPE_EFFINST_ENT_GS* pointer, Game_State* game_state);                                                                                  // LINE: 57
_inline PROTOTYPE_EFFINST_ENT_GS* Pointer(PROTOTYPE_EFFINST_ENT_GS_Offset offset, Game_State* game_state);                                                                                  // LINE: 68
_inline PROTOTYPE_EFFINST_ENT_ENT_AR_GS_Offset Offset(PROTOTYPE_EFFINST_ENT_ENT_AR_GS* pointer, Game_State* game_state);                                                                    // LINE: 80
_inline PROTOTYPE_EFFINST_ENT_ENT_AR_GS* Pointer(PROTOTYPE_EFFINST_ENT_ENT_AR_GS_Offset offset, Game_State* game_state);                                                                    // LINE: 91
_inline PROTOTYPE_EFFINST_REF_ENT_DDR_GS_Offset Offset(PROTOTYPE_EFFINST_REF_ENT_DDR_GS* pointer, Game_State* game_state);                                                                  // LINE: 103
_inline PROTOTYPE_EFFINST_REF_ENT_DDR_GS* Pointer(PROTOTYPE_EFFINST_REF_ENT_DDR_GS_Offset offset, Game_State* game_state);                                                                  // LINE: 114
_inline PROTOTYPE_EFFINST_ENT_S32PTR_STR_GS_Offset Offset(PROTOTYPE_EFFINST_ENT_S32PTR_STR_GS* pointer, Game_State* game_state);                                                            // LINE: 126
_inline PROTOTYPE_EFFINST_ENT_S32PTR_STR_GS* Pointer(PROTOTYPE_EFFINST_ENT_S32PTR_STR_GS_Offset offset, Game_State* game_state);                                                            // LINE: 137
_inline PROTOTYPE_EFFINST_ENT_STAT_S32PTR_S16PTR_GS_Offset Offset(PROTOTYPE_EFFINST_ENT_STAT_S32PTR_S16PTR_GS* pointer, Game_State* game_state);                                            // LINE: 149
_inline PROTOTYPE_EFFINST_ENT_STAT_S32PTR_S16PTR_GS* Pointer(PROTOTYPE_EFFINST_ENT_STAT_S32PTR_S16PTR_GS_Offset offset, Game_State* game_state);                                            // LINE: 160

// FILE: src\Effects.cpp:
Effect_Offset Get_Critical_Effect_Offset(Game_State* game_state);                                                                                                                           // LINE: 15
Effect_Offset Get_Might_Effect_Offset(Game_State* game_state);                                                                                                                              // LINE: 30
Effect_Offset Get_Enraged_Effect_Offset(Game_State* game_state);                                                                                                                            // LINE: 45
Effect_Offset Get_Vampirism_Effect_Offset(Game_State* game_state);                                                                                                                          // LINE: 117
Dice Poison_Damage_Dice();                                                                                                                                                                  // LINE: 174
void Poison_On_Turn_End_FN(Effect_Instance* instance, Entity* target, Game_State* game_state);                                                                                              // LINE: 181
Effect_Offset Get_Poison_Effect_Offset(Game_State* game_state);                                                                                                                             // LINE: 198
Effect_Offset Get_Burning_Effect_Offset(Game_State* game_state);                                                                                                                            // LINE: 214
Effect_Offset Get_Weak_Grip_Offset(Game_State* game_state);                                                                                                                                 // LINE: 248
void Stun_Attacker(Effect_Instance* instance, Entity* attacker, Entity* defender, Attack_Record* ar, Game_State* game_state);                                                               // LINE: 301
Effect_Instance Reckless_Attack(Entity* attacker, Game_State* game_state);                                                                                                                  // LINE: 322
Effect_Instance Careful_Attack(Entity* attacker, Game_State* game_state);                                                                                                                   // LINE: 349
Effect_Instance Weakspot_Attack(Entity* attacker, Game_State* game_state);                                                                                                                  // LINE: 379
Effect_Instance Allin_Attack(Entity* attacker, Game_State* game_state);                                                                                                                     // LINE: 406
Effect_Instance Guarding_Attack(Entity* attacker, Game_State* game_state);                                                                                                                  // LINE: 436
Effect_Instance Evasive_Attack(Entity* attacker, Game_State* game_state);                                                                                                                   // LINE: 463
Effect_Instance Execute_Attack(Entity* attacker, Game_State* game_state);                                                                                                                   // LINE: 490
Effect_Instance Disarming_Attack(Entity* attacker, Game_State* game_state);                                                                                                                 // LINE: 555
Effect_Instance Vampiric_Attack(Entity* attacker, Game_State* game_state);                                                                                                                  // LINE: 627
Effect_Instance Blessed_Attack(Entity* attacker, Game_State* game_state);                                                                                                                   // LINE: 684
Effect_Instance Berserking_Attack(Entity* attacker, Game_State* game_state);                                                                                                                // LINE: 757
Effect_Instance Redirect_Attack(Entity* attacker, Game_State* game_state);                                                                                                                  // LINE: 829
Effect_Instance Change_Attack(Entity* attacker, Game_State* game_state);                                                                                                                    // LINE: 881
Effect_Instance Thieving_Attack(Entity* attacker, Game_State* game_state);                                                                                                                  // LINE: 979
Effect_Instance Stylish_Attack(Entity* attacker, Game_State* game_state);                                                                                                                   // LINE: 1073

// FILE: src\Factory.cpp:
void Finalize_Entity(Entity* entity, Entity* container, Game_State* game_state);                                                                                                            // LINE: 9
void Add_Dice(Effect* effect, s16 count, s16 faces);                                                                                                                                        // LINE: 18
Entity* Create_Class_Adventurer(Game_State* game_state);                                                                                                                                    // LINE: 47
Entity* Create_Class_Wretched(Game_State* game_state);                                                                                                                                      // LINE: 84
Entity* Create_Bandit(Entity* room, Game_State* game_state);                                                                                                                                // LINE: 104
Entity* Create_Giant_Rat(Entity* room, Game_State* game_state);                                                                                                                             // LINE: 132
Entity* Create_Rat_Meat(Entity* container, Game_State* game_state);                                                                                                                         // LINE: 222
Entity* Create_Rat_Mound(Entity* room, Game_State* game_state);                                                                                                                             // LINE: 236
Entity* Create_Spider(Entity* room, Game_State* game_state);                                                                                                                                // LINE: 262
Entity* Create_Boss_Spider(Entity* room, Game_State* game_state);                                                                                                                           // LINE: 292
Entity* Create_Greate_Sword(Entity* room, Game_State* game_state);                                                                                                                          // LINE: 322
Entity* Create_Dagger(Entity* room, Game_State* game_state);                                                                                                                                // LINE: 369
Entity* Create_Poison_Dagger(Entity* room, Game_State* game_state);                                                                                                                         // LINE: 390
Entity* Create_Ring_Of_Giants(Entity* room, Game_State* game_state);                                                                                                                        // LINE: 466
Entity* Create_Ring_Of_Strange_Fortunes(Entity* room, Game_State* game_state);                                                                                                              // LINE: 506
Entity* Create_Ring_Of_Rebirth(Entity* room, Game_State* game_state);                                                                                                                       // LINE: 543
Entity* Create_Ring_Of_Regeneration(Entity* room, Game_State* game_state);                                                                                                                  // LINE: 611
Entity* Create_Antidote(Entity* container, Game_State* game_state);                                                                                                                         // LINE: 661
Entity* Create_Healing_Potion(Entity* container, Game_State* game_state);                                                                                                                   // LINE: 703
Entity* Create_Custom_Ring(Entity* room, Game_State* game_state, String name);                                                                                                              // LINE: 791
Entity* Create_Gloves_Of_Brutality(Entity* room, Game_State* game_state);                                                                                                                   // LINE: 812
Entity* Create_Wooden_Shield(Entity* room, Game_State* game_state);                                                                                                                         // LINE: 853
Entity* Create_Room(Game_State* game_state);                                                                                                                                                // LINE: 892
void Generate_Entrace_Room(Entity* room, Game_State* game_state);                                                                                                                           // LINE: 903
Room_Generator_Element_Array Caves();                                                                                                                                                       // LINE: 918
Entity* Create_Ring_Of_Just_Fucking_Crit(Entity* room, Game_State* game_state);                                                                                                             // LINE: 1061

// FILE: src\Dungeon.cpp:
void Set_Output_Color(u8 red, u8 green, u8 blue);                                                                                                                                           // LINE: 58
void Set_Output_Color(Color color);                                                                                                                                                         // LINE: 65
String Format_Message(Game_State* game_state, char* format_string, ...);                                                                                                                    // LINE: 71
_inline void Flush_Messages(Game_State* game_state);                                                                                                                                        // LINE: 90
_inline void Print_Messages(Game_State* game_state);                                                                                                                                        // LINE: 97
void Push_Message(String message, Game_State* game_state);                                                                                                                                  // LINE: 115
void Wait(f64 seconds, Game_State* game_state);                                                                                                                                             // LINE: 130
String Get_User_Input(Game_State* game_state);                                                                                                                                              // LINE: 139
bool User_Query_Yes_No(Game_State* game_state);                                                                                                                                             // LINE: 158
Reference* Find_Empty_Slot(Entity_Node* node);                                                                                                                                              // LINE: 192
_inline Entity_Offset Offset(Entity* entity, Game_State* game_state);                                                                                                                       // LINE: 214
_inline Entity* Pointer(Entity_Offset offset, Game_State* game_state);                                                                                                                      // LINE: 226
_inline Effect_Offset Offset(Effect* effect, Game_State* game_state);                                                                                                                       // LINE: 238
_inline Effect* Pointer(Effect_Offset offset, Game_State* game_state);                                                                                                                      // LINE: 251
_inline Entity_Node_Offset Offset(Entity_Node* entity_node, Game_State* game_state);                                                                                                        // LINE: 264
_inline Entity_Node* Pointer(Entity_Node_Offset offset, Game_State* game_state);                                                                                                            // LINE: 276
_inline Effects_Node_Offset Offset(Effects_Node* effects_node, Game_State* game_state);                                                                                                     // LINE: 288
_inline Effects_Node* Pointer(Effects_Node_Offset offset, Game_State* game_state);                                                                                                          // LINE: 300
String Unwrap_String(String_Wrapper* strw, Game_State* game_state);                                                                                                                         // LINE: 312
String_Offset Offset(String str, Game_State* game_state);                                                                                                                                   // LINE: 320
String Get_String(String_Offset offset, Game_State* game_state);                                                                                                                            // LINE: 387
_inline u64 Storage_Offset(void* ptr, Game_State* game_state);                                                                                                                              // LINE: 400
_inline void* Pull_From_Storage_Offset(u64 offset, Game_State* game_state);                                                                                                                 // LINE: 413
Reference* Find_Entity(Entity* entity, Entity_Root_Node* storage, Game_State* game_state, Entity_Node** out_node = 0);                                                                      // LINE: 426
Entity* Find_Entity_By_Name_Or_Reference_Number(Entity* actor, Reference space, String name_or_reference_number, Game_State* game_state, Verbose::T verbose = Verbose::T(1));               // LINE: 452
Entity* Find_Entity_By_Name(Entity* actor, Entity* space, String name, Game_State* game_state, Verbose::T verbose = Verbose::T(1));                                                         // LINE: 464
Entity* Find_Entity_By_Name_Or_Reference_Number(Entity* actor, Entity* space, String name_or_reference_number, Game_State* game_state, Verbose::T verbose = Verbose::T(1));                 // LINE: 488
Reference Make_Reference(Entity* entity, Game_State* game_state);                                                                                                                           // LINE: 538
Entity* Dereference(Reference* reference, Game_State* game_state);                                                                                                                          // LINE: 547
Entity* Dereference(Reference reference, Game_State* game_state);                                                                                                                           // LINE: 567
Entity_Iterator Make_Iterator(Entity_Root_Node* root, Game_State* game_state);                                                                                                              // LINE: 574
Entity_Iterator Make_Iterator(Entity* entity, Game_State* game_state);                                                                                                                      // LINE: 597
Effects_Iterator Make_Iterator(Effects_Root* root, Game_State* game_state);                                                                                                                 // LINE: 605
Reference* Next(Entity_Iterator* iter);                                                                                                                                                     // LINE: 624
Entity* Next_Entity(Entity_Iterator* iter);                                                                                                                                                 // LINE: 654
u64 Count(Entity_Root_Node* root_node, Game_State* game_state);                                                                                                                             // LINE: 668
bool Memory_Snapshot_Save(String file_path, Game_State* game_state);                                                                                                                        // LINE: 681
bool Memory_Snapshot_Restore(String file_path, Game_State* game_state);                                                                                                                     // LINE: 690
Effect_Instance* Next_Effect_Instance(Effects_Iterator* iter);                                                                                                                              // LINE: 722
_inline Effect_Instance* Next(Effects_Iterator* iter);                                                                                                                                      // LINE: 755
Effect* Next_Effect(Effects_Iterator* iter);                                                                                                                                                // LINE: 762
Backwards_Iterator Make_Backwards_Iterator(Entity_Root_Node* root, Game_State* game_state);                                                                                                 // LINE: 776
Reference* Previous(Backwards_Iterator* back_iter);                                                                                                                                         // LINE: 790
u32 Roll(u32 range, Game_State* game_state);                                                                                                                                                // LINE: 835
s32 Roll(Dice dice, Game_State* game_state);                                                                                                                                                // LINE: 847
s32* Roll_With_Record(Dice dice, Game_State* game_state);                                                                                                                                   // LINE: 863
f32 Random_F32(Game_State* game_state);                                                                                                                                                     // LINE: 877
Roll_Result Stat_Roll(s32 value, Stats::T stat, Game_State* game_state);                                                                                                                    // LINE: 887
s32 Value(Roll_Result rr);                                                                                                                                                                  // LINE: 903
Roll_Result Stat_Roll(Entity* entity, Stats::T stat, Game_State* game_state);                                                                                                               // LINE: 910
_inline bool Is_Rolled(Roll_Result rr);                                                                                                                                                     // LINE: 921
void Print_Dice(Dice dice, s32 result);                                                                                                                                                     // LINE: 928
void Print_Roll_Result(Roll_Result rr);                                                                                                                                                     // LINE: 934
void Print_Attack_Record(Attack_Record* ar, Game_State* game_state);                                                                                                                        // LINE: 947
_inline String Name(Entity* entity, Game_State* game_state);                                                                                                                                // LINE: 1112
char* Action_Name(AT::T action);                                                                                                                                                            // LINE: 1119
void Print_Required_Equipment_Slots(Entity* item);                                                                                                                                          // LINE: 1146
void Push_Generic_Apply_Effect_Message(Effect_Instance* source_effect, Entity* target, Effect_Instance new_effect, Apply_Effect_Result apply, Game_State* game_state);                      // LINE: 1170
void Remove_From_Residence(Entity* entity, Game_State* game_state);                                                                                                                         // LINE: 1227
void Release_Entity_Node(Entity_Root_Node* root, Game_State* game_state);                                                                                                                   // LINE: 1260
Entity_Node* Request_Entity_Node(Game_State* game_state);                                                                                                                                   // LINE: 1282
Effect* _Request_Effect(Game_State* game_state, u64 tag);                                                                                                                                   // LINE: 1299
void Release_Effect(Effect* effect, Game_State* game_state);                                                                                                                                // LINE: 1322
Entity* Request_Entity(Game_State* game_state);                                                                                                                                             // LINE: 1336
void Release_Entity(Entity* entity, Game_State* game_state);                                                                                                                                // LINE: 1358
Effects_Node* Request_Effects_Node(Game_State* game_state);                                                                                                                                 // LINE: 1366
void Release_Effects_Node(Effects_Node* node, Game_State* game_state);                                                                                                                      // LINE: 1383
void Insert(Entity* entity, Entity_Root_Node* storage, Game_State* game_state);                                                                                                             // LINE: 1391
void Deep_Insert(Entity* entity, Entity* storage_entity, Game_State* game_state);                                                                                                           // LINE: 1428
void Remove_All_Effects(Entity* entity, Game_State* game_state);                                                                                                                            // LINE: 1438
void Delete_Entity(Entity* entity, Game_State* game_state);                                                                                                                                 // LINE: 1496
bool Has_Content(Entity_Root_Node* root);                                                                                                                                                   // LINE: 1503
bool Is_Empty(Entity_Root_Node* root);                                                                                                                                                      // LINE: 1510
s32 Get_Stat_Value(Entity* entity, Stats::T stat, Game_State* game_state, u64* out_effect_count = 0);                                                                                       // LINE: 1523
s32 Exp_To_Level_Up(s32 _lvl);                                                                                                                                                              // LINE: 1570
_inline s32 Exp_To_Level_Up(Entity* entity);                                                                                                                                                // LINE: 1578
s16 Calculate_Level(Entity* entity);                                                                                                                                                        // LINE: 1585
void Set_Level_Based_On_Stats(Entity* entity);                                                                                                                                              // LINE: 1599
s16 Level(Entity* entity);                                                                                                                                                                  // LINE: 1606
s32 Max_Health(Entity* entity, Game_State* game_state);                                                                                                                                     // LINE: 1613
f32 Critical_Multiplier(Entity* entity, Game_State* game_state);                                                                                                                            // LINE: 1626
s32 Carry_Capacity(Entity* entity, Game_State* game_state);                                                                                                                                 // LINE: 1633
s32 Exp_Reward(Entity* entity);                                                                                                                                                             // LINE: 1646
s32 Carrying_Amount(Entity* entity, Game_State* game_state);                                                                                                                                // LINE: 1659
Critical_Ranges_Result Critical_Ranges(Entity* entity, Game_State* game_state, u32* out_success_effecting_count = 0, u32* out_failure_effecing_count = 0);                                  // LINE: 1672
void Full_Heal(Entity* entity, Game_State* game_state);                                                                                                                                     // LINE: 1714
bool Is_Item(Entity* entity);                                                                                                                                                               // LINE: 1720
bool Is_Alive(Entity* entity);                                                                                                                                                              // LINE: 1727
bool Is_Hostile_Against(Entity* A, Entity* B);                                                                                                                                              // LINE: 1734
bool Is_Living_Enemy_Of(Entity* actor, Entity* target);                                                                                                                                     // LINE: 1741
s32 Give_Temporary_Health(Entity* entity, s32 amount, String source_name, Verbose::T verbose, Game_State* game_state);                                                                      // LINE: 1748
Healing_Result Heal(Entity* entity, s32 amount, String source_name, Verbose::T verbose, Game_State* game_state);                                                                            // LINE: 1769
Deal_Damage_Result Deal_Damage(Entity* defender, Reference attacker, String source_name, s32 dmg, Damage_Type type, Game_State* game_state, Verbose::T verbose);                            // LINE: 1839
_inline Deal_Damage_Result Deal_Damage(Entity* defender, Entity* attacker, String dmg_src_name, s32 dmg, Damage_Type type, Game_State* game_state, Verbose::T verbose);                     // LINE: 1983
void Proc_Effects(u64 offset, Entity* attacker, Entity* defender, Attack_Record* ar, Game_State* game_state);                                                                               // LINE: 1991
void Proc_Effects(u64 offset, Entity* target, Game_State* game_state);                                                                                                                      // LINE: 2008
String Effect_Name(Effect_Instance* instance, Game_State* game_state);                                                                                                                      // LINE: 2024
u64 Count_Effect_Instances(Effects_Root* root, Effect_Instance cmp, Game_State* game_state, Effect_Instance** out_shortest_duration = 0);                                                   // LINE: 2044
void Delete_Effect_Slot(Effects_Root* root, Effects_Node* node, u64 *idx, u64* count, Game_State* game_state);                                                                              // LINE: 2074
Effect_Instance* New_Effect_Slot(Effects_Root* root, Game_State* game_state);                                                                                                               // LINE: 2114
Apply_Effect_Result Apply_Effect(Entity* target, Effect_Instance instance, Game_State* game_state);                                                                                         // LINE: 2160
void Remove_Effects_From_Source(Entity* actor, Entity* source, Game_State* game_state);                                                                                                     // LINE: 2217
u64 Remove_Effects_Of_Type(Entity* actor, Effect_Type::T type_to_remove, Game_State* game_state, Verbose::T verbose);                                                                       // LINE: 2242
void Inspect(Entity* target, Game_State* game_state);                                                                                                                                       // LINE: 2421
bool Is_Equipped(Entity* actor, Entity* item, Game_State* game_state);                                                                                                                      // LINE: 2460
bool Unequip(Entity* actor, Entity* item, Game_State* game_state);                                                                                                                          // LINE: 2483
bool Unequip(Entity* item, Game_State* game_state);                                                                                                                                         // LINE: 2507
bool Use(Entity* actor, Entity* item, Game_State* game_state, Verbose::T verbose);                                                                                                          // LINE: 2515
bool Equip(Entity* actor, Entity* target, Game_State* game_state, Verbose::T verbose = Verbose::T(0));                                                                                      // LINE: 2555
void Print_Uses(Entity* entity);                                                                                                                                                            // LINE: 2776
void Open(Entity* actor, Game_State* game_state);                                                                                                                                           // LINE: 2796
bool Glance(Entity* actor, Game_State* game_state, Report_Turn_Taken_Status::T report_turn_taken_status = Report_Turn_Taken_Status::T(1));                                                  // LINE: 2822
void Remove_Random_Effect(Entity* entity, String source_name, Game_State* game_state);                                                                                                      // LINE: 2898
s32 Damage_Modifier_From_Effects(Entity* attacker, Attack_Record* ar, Game_State* game_state);                                                                                              // LINE: 2937
u64 Attack_Modifier_Mask(Attack_Mod::T modifier);                                                                                                                                           // LINE: 3028
u64 Class_Mask(Class::T _class);                                                                                                                                                            // LINE: 3035
bool Can_Use_Attack_Modifier(Entity* entity, Attack_Mod::T modifier);                                                                                                                       // LINE: 3042
void Apply_Or_Describe_Attak_Modifier(Entity** attacker_ptr, Entity** defender_ptr, Attack_Mod::T modifier, Game_State* game_state);                                                        // LINE: 3058
void Attack(Entity* attacker, Entity* defender, Game_State* game_state, Attack_Mod::T modifier = Attack_Mod::T(0));                                                                         // LINE: 3200
void Player_Action(Entity* actor, String actor_name, Game_State* game_state);                                                                                                               // LINE: 3275
Entity* Redirected_Target(Entity* actor, String actor_name, Game_State* game_state);                                                                                                        // LINE: 3360
Entity* Random_Entity_That_Matches_Criteria(Entity_Root_Node* storage, bool(*conditional)(Entity* entity, void* user_ptr, Game_State* game_state), void* user_ptr, Game_State* game_state); // LINE: 3398
Entity* Find_Attack_Target(Entity* actor, Game_State* game_state);                                                                                                                          // LINE: 3437
void NPC_Action(Entity* actor, String actor_name, Game_State* game_state);                                                                                                                  // LINE: 3466
void Take_Action(Entity* actor, Game_State* game_state);                                                                                                                                    // LINE: 3526
bool Roll_Initiative(Entity* entity, Game_State* game_state);                                                                                                                               // LINE: 3598
void Sort_Iniative_Order(Reference* refs, Game_State* game_state);                                                                                                                          // LINE: 3632
void Sort_Space(Entity_Root_Node* space, Game_State* game_state);                                                                                                                           // LINE: 3764
u64 Count_Longest_Round_Effect_Duration(Entity* actor, Game_State* game_state);                                                                                                             // LINE: 3840
void Tick_Down_Effect_Durations(Entity* actor, Duration_Type type, Game_State* game_state);                                                                                                 // LINE: 3855
_inline void Enter_A_Room_Printout(Entity* player, Entity* room, Game_State* game_state);                                                                                                   // LINE: 3929
Room_Generator_Element Pick_Room_Generator(Room_Generator_Element_Array array, u32 selector, Game_State* game_state);                                                                       // LINE: 3952
Room_Generator_Element Pick_Room_Generator(Room_Generator_Element_Array array, Game_State* game_state);                                                                                     // LINE: 3973
void Prompt_User_For_Command_And_Attempt_To_Execute(Command* commands, u64 count, void* user_ptr, Game_State* game_state);                                                                  // LINE: 3987
void Create_Player_Charater(Game_State* game_state);                                                                                                                                        // LINE: 4081
void Tick_Active_Effects_Down_To_Zero(Entity* actor, Game_State* game_state);                                                                                                               // LINE: 4172
Entity* Proceed_To_Next_Room(Game_State* game_state);                                                                                                                                       // LINE: 4197
void Prepare_Game_Round(Game_State* game_state);                                                                                                                                            // LINE: 4267
void Excecute_Game_Round(Game_State* game_state);                                                                                                                                           // LINE: 4361
void Exit_Handling(Game_State* game_state);                                                                                                                                                 // LINE: 4399
bool Play_Game(Game_State* game_state);                                                                                                                                                     // LINE: 4431
void Reset_Game_State(Game_State* game_state);                                                                                                                                              // LINE: 4462
Game_State* Create_Game_State();                                                                                                                                                            // LINE: 4510
CMD_Result::T Kill_Command(Entity* actor, String args, Game_State* game_state);                                                                                                             // LINE: 4541
CMD_Result::T Toggle_Dramatic_Pause(Entity* actor, String args, Game_State* game_state);                                                                                                    // LINE: 4568
CMD_Result::T Toggle_Godmode(Entity* actor, String args, Game_State* game_state);                                                                                                           // LINE: 4592
CMD_Result::T Help_Command(Entity* entity, String args, Game_State* game_state);                                                                                                            // LINE: 4611
CMD_Result::T Pickup_Command(Entity* actor, String args, Game_State* game_state);                                                                                                           // LINE: 4651
CMD_Result::T Inventory_Command(Entity* actor, String args, Game_State* game_state);                                                                                                        // LINE: 4700
CMD_Result::T Proceed_Command(Entity* actor, String args, Game_State* game_state);                                                                                                          // LINE: 4764
CMD_Result::T Equipment_Command(Entity* actor, String args, Game_State* game_state);                                                                                                        // LINE: 4861
CMD_Result::T Drop_Command(Entity* actor, String args, Game_State* game_state);                                                                                                             // LINE: 4889
CMD_Result::T Use_Command(Entity* actor, String args, Game_State* game_state);                                                                                                              // LINE: 4919
CMD_Result::T Equip_Command(Entity* actor, String args, Game_State* game_state);                                                                                                            // LINE: 4943
CMD_Result::T Unequip_Command(Entity* actor, String args, Game_State* game_state);                                                                                                          // LINE: 4966
CMD_Result::T Stats_Command(Entity* actor, String args, Game_State* game_state);                                                                                                            // LINE: 4995
CMD_Result::T Status_Command(Entity* actor, String args, Game_State* game_state);                                                                                                           // LINE: 5079
CMD_Result::T Inspect_Command(Entity* actor, String args, Game_State* game_state);                                                                                                          // LINE: 5141
CMD_Result::T Pass_Command(Entity* actor, String args, Game_State* game_state);                                                                                                             // LINE: 5183
CMD_Result::T Glance_Command(Entity* actor, String args, Game_State* game_state);                                                                                                           // LINE: 5199
CMD_Result::T Restart_Command(Entity* actor, String args, Game_State* game_state);                                                                                                          // LINE: 5223
CMD_Result::T Save_Command(Entity* actor, String args, Game_State* game_state);                                                                                                             // LINE: 5258
CMD_Result::T Load_Command(Entity* actor, String args, Game_State* game_state);                                                                                                             // LINE: 5284
CMD_Result::T Exit_Command(Entity* actor, String args, Game_State* game_state);                                                                                                             // LINE: 5310
CMD_Result::T Loot_Command(Entity* actor, String args, Game_State* game_state);                                                                                                             // LINE: 5348
CMD_Result::T Attack_Command(Entity* actor, String args, Game_State* game_state);                                                                                                           // LINE: 5404
CMD_Result::T Set_Seed_Command(Entity* actor, String args, Game_State* game_state);                                                                                                         // LINE: 5467
void Get_Character_Creator_Commands(Game_State* game_state, Command** out_commands, u64* out_count);                                                                                        // LINE: 5497
