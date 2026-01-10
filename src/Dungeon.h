
// ===================================
// Copyright (c) 2025 by Valtteri Kois
// All rights reserved.
// ===================================

#define PASTE_AS_STRING(X) STR(PASTE_AS_CSTRING(X))
#define SWITCH_ABC_A(A, B, C) A
#define SWITCH_ABC_B(A, B, C) B
#define SWITCH_ABC_C(A, B, C) C
#define SWITCH_AB_A(A, B) A
#define SWITCH_AB_B(A, B) B

#define CRITICAL_DICE_RANGE 100

#include "Generated_Offsets.h" // NOTE: Generated file!

// NOTE: Why? Well... Headache does not output namespaces in the order they appear in code, 
// and in the generated forward declartion file Stats::T has to be above PROTOTYPE_EFFINST_ENT_STAT_S32_GS.
// Using a deeper include is a hack to ensures that... \o/
#include "Stats.cpp" 

struct ANSI_Color_Buffer
{
    char data[sizeof("\x1b[38;2;255;255;255um")];
};


namespace AT
{
    enum T : u8
    {
        free    = 0,
        normal  = 1 << 1,
        bonus   = 1 << 2,
    };
};
constexpr u8 Full_Action = AT::normal | AT::bonus;
constexpr s16 Base_Dice = 10;


namespace Rarity
{
    enum T : u8
    {
        common = 0,
        uncommon,
        rare,
        epic,
        legendary,
        COUNT
    };  
}


namespace EFlags
{
    enum T : u64
    {
        actor               = u64(1) << 0,
        aggressive          = u64(1) << 1,
        item                = u64(1) << 2,
        equippable          = u64(1) << 3,
        interactable        = u64(1) << 4,
        hidden_iniative     = u64(1) << 5,
        container           = u64(1) << 6, // do I need this?
        burst_container     = u64(1) << 7,
        is_open             = u64(1) << 8,
        goes_last           = u64(1) << 9,
        redirected          = u64(1) << 10,
        can_be_stolen_from  = u64(1) << 11,
        visible             = u64(1) << 12,
        hidden              = u64(1) << 13,

        started_turn        = u64(1) << 49,
        player_controlled   = u64(1) << 50,
        godmode             = u64(1) << 63, // Devmode thingy
    };
};


struct Effect_Offset
{
    u64 v;
    u64 ID;
};


struct Effects_Node_Offset
{
    u64 v;
    
    bool operator == (Effects_Node_Offset& other)
    {
        bool result = v == other.v;
        return result;
    }
};


struct Entity_Node_Offset
{
    u64 v;
};


enum class Storage : u8
{
    dynamic,
    _static,
};


struct String_Offset
{
    u64 v; // Used as an offset to a String_Wrapper.
    union
    {
        u64 length;
        struct
        {
            char padding[7];
            Storage storage;
        };
    };
};
static_assert(sizeof(String_Offset) == 16);


struct String_Wrapper
{
    u64 offset;
    u64 length;
};


struct String_Table
{
    String_Wrapper entries[64];
    
    u64 next_offset;
};


struct String_Table_Root
{
    u64 table_offset;
    u64 count;
};


struct Entity_Offset
{
    u64 v;
    u64 ID;
};


struct Entity_Node
{
    Entity_Offset entities[16];
    Entity_Node_Offset next;
};


struct Entity_Root_Node
{
    Entity_Node_Offset node_offset;
    u64 count;
};


namespace Equipment_Slots
{
    #define EQUIPMENT_SLOTS(X, S)                                   \
    X(S(primary_hand,      Primary Hand,      (u32(1) << 0))),      \
    X(S(secondary_hand,    Secondary Hand,    (u32(1) << 1))),      \
    X(S(head,              Head,              (u32(1) << 2))),      \
    X(S(back,              Back,              (u32(1) << 3))),      \
    X(S(chest,             Chest,             (u32(1) << 4))),      \
    X(S(belt,              Belt,              (u32(1) << 5))),      \
    X(S(legs,              Legs,              (u32(1) << 6))),      \
    X(S(boots,             Boots,             (u32(1) << 7))),      \
    X(S(gloves,            Gloves,            (u32(1) << 8))),      \
    X(S(ring_1,            Ring,              (u32(1) << 9))),      \
    X(S(ring_2,            Ring,              (u32(1) << 9))),      \
    X(S(ring_3,            Ring,              (u32(1) << 9))),      \
    X(S(ring_4,            Ring,              (u32(1) << 9))),      \
    
    
    enum T : u32
    {
        EQUIPMENT_SLOTS(PASTE, SWITCH_ABC_A)
        COUNT
    };
    
    String name[] = 
    {
        EQUIPMENT_SLOTS(PASTE_AS_STRING, SWITCH_ABC_B)
    };
    
    u32 flag[] =
    {
        EQUIPMENT_SLOTS(PASTE, SWITCH_ABC_C)
    };
    
    #undef EQUIPMENT_SLOTS
};


struct Dice
{
    s16 count;
    s16 faces;
};


struct Bonus_Dice
{
    Dice unique_die[4];
    s16  count;
};


namespace Effect_Flags
{
    enum T : s8
    {
        can_be_released = 1 << 0,
        has_damage_multiplier = 1 << 1,
    };
}


struct Effect_Hash_Key
{
    u32 line;
    u32 file;

    bool operator == (Effect_Hash_Key& other)
    {
        bool result = line == other.line && file == other.file;
        return result;
    }
};


struct Effect
{
    Effect_Type::T type;

    String_Offset name_offset;
    
    f32 damage_multiplier;
    s16 stat_modifiers[Stats::COUNT];
    s16 carry_capacity_modifier;
    s16 max_health_modifier;
    s16 raw_damage_modifier;
    s16 thorns_damage;
    s16 pierce;
    s16 healing_power;
    
    u8 bonus_stacks; // NOTE: Denotes how many times this effect can stack. Default is 1 and this is added on top (ZII).
    s8 critical_success_range;
    s8 critical_failure_range;
    s8 flags;

    Bonus_Dice damage_die;

    PROTOTYPE_EFFINST_ENT_GS_Offset /*-------------------*/ on_apply_fn_offset;
    PROTOTYPE_EFFINST_ENT_GS_Offset /*-------------------*/ on_turn_end_fn_offset;
    PROTOTYPE_EFFINST_ENT_GS_Offset /*-------------------*/ on_turn_start_fn_offset;
    PROTOTYPE_EFFINST_ENT_ENT_GS_Offset /*---------------*/ on_loot_attempt_fn_offset;
    PROTOTYPE_EFFINST_ENT_ENT_AR_GS_Offset /*------------*/ on_attack_fn_offset;
    PROTOTYPE_EFFINST_ENT_ENT_AR_GS_Offset /*------------*/ on_be_attacked_fn_offset;
    PROTOTYPE_EFFINST_ENT_ENT_AR_GS_Offset /*------------*/ on_miss_fn_offset;
    PROTOTYPE_EFFINST_ENT_ENT_AR_GS_Offset /*------------*/ on_hit_fn_offset;
    PROTOTYPE_EFFINST_ENT_ENT_AR_GS_Offset /*------------*/ on_dodge_fn_offset;
    PROTOTYPE_EFFINST_ENTOFF_ENT_DDR_GS_Offset /*--------*/ on_damage_taken_fn_offset;
    PROTOTYPE_EFFINST_ENT_S32PTR_STR_GS_Offset /*--------*/ on_heal_fn_offset;
    PROTOTYPE_EFFINST_ENT_STAT_S32PTR_S16PTR_GS_Offset /**/ on_get_stat_value_fn_offset;

    Effect_Offset next;
    
    union
    {
        Effect_Hash_Key key;
        u64 ID;
    };
};


namespace Effect_Type
{
    #define EFFECT_TYPES(X) \
    X(none),                \
    X(disease),             \
    X(poison),              \
    X(magic),               \
    X(curse),               \
    X(bleed),               \
    X(physical),            \

    enum T : u8
    {
        EFFECT_TYPES(PASTE)
        COUNT
    };

    String names[] = 
    {
        EFFECT_TYPES(PASTE_AS_STRING)
    };

    #undef EFFECT_TYPES
};


enum class Apply_Effect_Result : u8
{
    failed = 0,
    success,
    refresh,
};


#define DURATION_TYPES(X)  \
X(round),                  \
X(attack),                 \
X(room),

enum class Duration_Type : u8
{
    DURATION_TYPES(PASTE)
    COUNT
};

String duration_type_names[] = 
{
    DURATION_TYPES(PASTE_AS_STRING)
};

#undef DURATION_TYPES


namespace Food_Quality
{
    #define FOOD_QUALITIES(X, F)    \
    X(F(none,        0.00f)),       \
    X(F(snack,       0.25f)),       \
    X(F(appetizer,   0.50f)),       \
    X(F(lunch,       0.75f)),       \
    X(F(meal,        1.00f)),

    enum T : u8
    {
        FOOD_QUALITIES(PASTE, SWITCH_AB_A)
        COUNT
    };

    String name[] = 
    {
        FOOD_QUALITIES(PASTE_AS_STRING, SWITCH_AB_A)
    };

    f32 healing[] = 
    {
        FOOD_QUALITIES(PASTE, SWITCH_AB_B)
    };

    #undef FOOD_QUALITIES
}


namespace Class
{
    #define CLASSES(X, F)                               \
    X(F(adventurer,         Create_Class_Adventurer)),  \
    X(F(mountaineer,        Create_Class_Mountaineer)), \
    X(F(wretched,   Create_Class_Wretched)),            \
    

    enum T : u8
    {
        CLASSES(PASTE, SWITCH_AB_A)
        COUNT
    };

    String name[] =
    {
        CLASSES(PASTE_AS_STRING, SWITCH_AB_A)
    };

    Entity*(*create_fn[])(Game_State* game_state) =
    {
        CLASSES(PASTE, SWITCH_AB_B)
    };

    #undef CLASSES
};


#define UNLIMITED_USES U32_MAX
#define UNLIMITED_DURATION 0
struct Effect_Instance
{
    // CONSIDER: Make the numbers in here a smaller type. 
    // Duration could be a u8.. nothing will last more than 200 turns.
    // Room and round applied is more complicated, but they could be at least 32 bit... or even 16.. not like the game will last for more than 60k rounds.

    u64 duration;
    Effect_Offset effect_offset;
    Entity_Offset source;

    u64 room_applied;
    u64 round_applied;
    Duration_Type duration_type;
    bool zero_ticked;
    /*
        NOTE: Effects have to ticked down on start of the entities turn.
        This allows for Effects that are in play until the start of your next round, but *NOT* during your next round.
        Perhaps a bit niche, but maybe for example increased all stats until the start of your next turn.
        This effect would affect the attack and being attacked during the time between your next round.
        If effects are ticked down on turn end, and this effect has a duration of one, 
        it would be ticked down to zero and removed. As such it would not be effective in the time between the rounds.
        On the otherhand if the effect has duration of two it would also be effective on your next turn.
        So... effects have to be ticked down on turn start, but this causes a different issue.
        All durations are sort of reduced by one. If a Giant Rat applies a poison on you; it reports a duration,
        but then on your turn you check the status of that effect and,
        it has already been ticked by one even though it has not done anything yet. 
        One solution would be to always report the duration to be one higher and only remove the effect after it goes bellow zero
        (obvously change duration to signed).
        But then all code that reports a duration of an effect would have to be aware of these internals, so instead
        I'm accepting some padding in this struct to have an invisible and cotrollable extra tick.
        By default if you don't set the bool on effect creation, the effect will have an extra tick.
        But this is a "round trip" effect (untill your next turn start), you would have a duration of one and set the zero ticked to already be true.
    */
    #if SLOW
    // NOTE: This is for checking the delete during iteration code functions properly.
    // NOTE: If any more bools are added make it flag field instead. Right now the other bool is dev mode only, so not worth it yet, but...
    // should the need arise for more bools.
    bool update_ticked;
    #endif
};


struct Effects_Node
{
    Effect_Instance instances[8];
    Effects_Node_Offset next;
    Effects_Node_Offset prev;
};


// NOTE: Effects are stored in a doubly linked bucket array, where new elements are stored at the end.
// This is because it enables insertion during iteration.
// And effects can trigger new effects to be applied, so this capability is very important.
struct Effects_Root
{
    Effects_Node_Offset root_offset;
    Effects_Node_Offset head_offset;
    u64 head_count;
};


struct Roll_Result
{
    Stats::T stat;
    s32 stat_value;
    Dice dice;
    s32 dice_result;
    s32 total_result;
};


struct Initiative
{
    Entity_Offset offset;
    Roll_Result value;
    bool visible;
};


enum class Cooldown_Type : u8
{
    none,
    rounds,
    rooms,
};


struct Interactable
{
    PROTOTYPE_ENT_ENT_GS_Offset on_use_fn_offset;
    PROTOTYPE_ENT_GS_Offset on_empty_fn_offset;
    
    s32 uses_count;
    Cooldown_Type cd_type;
    u64 cd;

    u64 last_used_round;
    u64 last_used_room;
};


enum class Faction : u8
{
    none = 0,
    player,
    bandit,
    nature,
    rats,
    ants,
    undead,
    mimic,
    goblin,

    general_hostility,
    COUNT
};


struct Entity
{
    u64 flags;
    u64 ID;
    
    union
    {
        struct
        {
            String_Offset name_offset;
            String_Offset description_offset;
            String_Offset burst_message_offset;
            
            Entity_Offset residence;
            Entity_Offset equipment[Equipment_Slots::COUNT];
            
            Entity_Root_Node inventory;
            Effects_Root active_effects;
            
            Effect_Offset on_equip_effect_offset;
            u64 known_attack_modifiers;

            Interactable interactable;
            Initiative initiative;
            
            u64 refnum;
            u64 dublicate_identifier;
            s32 _temp_health;
            s32 _health;
            s32 exp;
            f32 _threat;

            f32 burst_change;
            u32 required_equipment_slots;
            
            u8 actions;
            u8 stunned;
            Rarity::T rarity;
            Food_Quality::T food_quality;
            Faction faction;

            s16 _stats[Stats::COUNT];
            s16 _lvl;
            s16 weight;
            s16 bonus_exp_reward;
        };
        
        Entity_Offset next;
    };
};


struct Leveler
{
    Entity* actor;
    s16 points;
    s16 assigned[Stats::PRIMARY_STAT_END];
    bool summarize;
    bool running;
};


struct Damage_Modifiers_Result
{
    s32 damage;
    s32 pierce;
};


struct Damage_Modifier
{
    Bonus_Dice damage_die;
    s32** results_control_block;
    s32 raw_damage_modifier;
    f32 damage_multiplier;
    s32 pierce;
    bool has_damage_multiplier;
    Effect_Instance* source;
};


struct Healing_Result
{
    s32 raw_amount;
    s32 power_bonus;
    s32 total_amount;
    s32 max_health;
    s32 health_snapshot;
    s32 healing_done;
    s32 overhealing;
    f32 overhealing_percentage;
};


struct Deal_Damage_Result
{
    Roll_Result resistance_roll;
    s32 pierce;
    s32 true_mitigation;
    s32 mitigation_after_pierce;
    s32 damage_after_mitigation;
    s32 damage_to_true_health;
    s32 damage_to_temp_health;
    s32 exp_reward;
    bool is_killing_blow;
};


enum class Damage_Type
{
    physical,
    magical,
};


struct Critical_Ranges_Result
{
    s32 success;
    s32 failure;
};


struct Message_Pipe
{
    String* ctrl_block;
    u64 count;
};


struct Apply_Check_Record
{
    Roll_Result arcane_roll;
    Roll_Result immunity_roll;

    bool application_was_successfull;
};


struct Attack_Record
{
    Entity* attacker;
    Entity* defender;
    
    Attack_Mod::T attack_modifier;    

    Roll_Result accuracy_roll;
    Roll_Result dodge_roll;
    Roll_Result might_roll;

    Damage_Modifier* damage_modifiers;
    u64 damage_modifier_count;
    
    Deal_Damage_Result deal_damage_result;

    s32 target_pre_attack_health;

    Critical_Ranges_Result crit_ranges;
    s8 crit_dice_result;

    bool is_hit;
    bool is_critical_success;
    bool is_critical_failure;

    // CONSIDER: Collapse down to flags? Do I care? These aren't stored... it's just build by Attack() and consumed by Print_Attack().
    // But.. "better" \o/
};


namespace Roll_Print_Style
{
    enum T
    {
        disabled = 0,
        full,
        simple,
        result_and_stat_name,
        result,
    };
};


namespace Report_Turn_Taken_Status
{
    enum T : u8
    {
        no,
        yes
    };
};


namespace Verbose
{
    enum T : u8
    {
        no,
        yes
    };
};


namespace Forced
{
    enum T : u8
    {
        no,
        yes
    };
};


namespace Assign_Dublicate_Identifier
{
    enum T : u8
    {
        no = 0,
        yes
    };  
}


struct Entity_Iterator
{
    u64 idx;
    u64 count;
    Entity_Node* node;
    
    Game_State* game_state;

    #if 1
    Entity_Root_Node* root;
    u64 count_snapshot;
    #endif
};


struct Backwards_Iterator
{
    Entity_Root_Node* root;
    Entity_Node* node;
    u64 index;

    Game_State* game_state;
};


struct Ambush_Creature_Spawner_Offset
{
    u64 v;
};


struct Ambush_Option_Offset
{
    u64 v;
};


struct Ambush_Creature_Spawner
{
    GENERATE_ENTITY_FN_Offset gen_fn_offset;
    u32 min;
    u32 max;
    Ambush_Creature_Spawner_Offset next;
};


struct Ambush_Option
{
    f32 change;
    Ambush_Creature_Spawner_Offset head;
    Ambush_Option_Offset next;
};


struct Ambush_Table
{
    f32 change;
    f32 options_total_change;
    Ambush_Option_Offset head;
};


struct Effects_Iterator
{
    u64 idx;
    u64 count;
    u64 head_count;
    Effects_Node* last_node;
    Effects_Node* current_node;

    Game_State* game_state;
};


struct Effect_Hash_Table_Entry
{
    Effect_Offset first_offset;
    u64 chain_length;
};


struct Effect_Hash_Table
{
    Effect_Hash_Table_Entry entries[64];
    u64 unique_collision_count;
    u64 collision_count;
    u64 insertions;
};


struct Game_State
{
    Arena permanent_storage;
    Arena scratch_buffer;
    Arena messages_buffer;
    
    char* executable_base_address; // NOTE: Pointers are not allowed, but this one does not count!
    u64 executable_size;
    

    String_Table_Root string_table;
    
    Entity_Offset free_entity_offset;
    Entity_Node_Offset free_node_offset;
    Effect_Offset free_effect_offset;
    Effects_Node_Offset free_effects_offset;
    
    Ambush_Table _ambush_table;
    Ambush_Option_Offset free_ambush_option_offset;
    Ambush_Creature_Spawner_Offset free_ambush_creature_spawner_offset;

    Effect_Hash_Table permanent_effects;

    u64 round; // TODO: Rename to round_count!
    u64 room_count;
    u32 level;
    s32 distance_travelled;

    u64 visible_initiative_count;
    u64 initiative_count;
    u64 active_initiative_index;
    Entity_Root_Node initiative_order;

    PROTOTYPE_ENT_GS_Offset room_generation_override_fn_offset;
    u32 initial_seed;
    u32 random_state;
    u64 prev_entity_ID;

    Entity_Offset player;

    Message_Pipe messages;

    ANSI_Color_Buffer default_color;
    ANSI_Color_Buffer ally_color;
    ANSI_Color_Buffer enemy_color;
    ANSI_Color_Buffer damage_color;
    ANSI_Color_Buffer temp_health_color;
    ANSI_Color_Buffer exp_color;
    ANSI_Color_Buffer rarity_colors[Rarity::COUNT];

    // CONSIDER: Change to flags... "better", but is it worth it for something like this? that is only stored once.
    // There is only the one game_state.
    bool enable_dramatic_pausing;
    bool loaded;
    bool running;
    bool restart;
    bool next_room;
    bool internal_error;
};


struct Character_Creator
{
    Entity** class_templates;
    u64 template_count;
    u64 selected_idx;
    bool running;
};


struct Loot_Table_Entry
{
    GENERATE_ENTITY_FN* fn;
    f32 change;
    f32 _og_change;
    Rarity::T rarity;
    u32 required_slots;
    s16 weight;
};


struct Loot_Table_Pick_Result
{
    GENERATE_ENTITY_FN** fns;
    u64 count;
};


struct Loot_Table
{
    Loot_Table_Entry* array;
    u64 count;
    bool filled;
    u64 counts[Rarity::COUNT] = {};
};


struct Pick_From_Table_Rules
{
    Comparison rarity_comparison;
    Rarity::T target_rarity_A;
    Rarity::T target_rarity_B;
    u32* equipment_slot_filters;
    u64 equipment_slot_filter_count;
    u64 excluded_slots;
    Comparison weight_comparison;
    s16 target_weight_A;
    s16 target_weight_B;
};


struct Rules_Builder
{
    Pick_From_Table_Rules rules;

    Rules_Builder()
    {
        rules = {};
    }

    Rules_Builder Rarity(Comparison comp, Rarity::T A, Rarity::T B = Rarity::T(0))
    {
        rules.rarity_comparison = comp;
        rules.target_rarity_A = A;
        rules.target_rarity_B = B;

        return *this;
    }

    Rules_Builder Slot_Filters(u32* slot_filters, u64 count)
    {
        rules.equipment_slot_filters = slot_filters;
        rules.equipment_slot_filter_count = count;

        return *this;
    }

    Rules_Builder Excluded_Slots(u64 mask)
    {
        rules.excluded_slots = mask;
        return *this;
    }


    Rules_Builder Weight(Comparison comp, s16 A, s16 B = s32(0))
    {
        rules.weight_comparison = comp;
        rules.target_weight_A = A;
        rules.target_weight_B = B;

        return *this;
    }

    Pick_From_Table_Rules Finish()
    {
        return rules;
    }
};


enum class Comparison : u8
{
    minimum,
    maximum,
    between,
    equal,
};


struct Level_Segment
{
    Loot_Table rooms;
    s32 size;
};


struct Level_Segments
{
    Level_Segment* segments;
    u64 segment_count;
};


struct Room_Generator_Element
{
    void(*fn)(Entity*, Game_State*);
    u32 size;
};


struct Room_Generator_Element_Array
{
    Room_Generator_Element* array;
    u64 count;
};


// [X] Reckless attack; bonus damage at a detriment of dodge.
// [X] Careful attack; bonus accuracy and reduced fumple range at a detriment of damage.
// [X] Weakspot attack; bonus crit change at detriment of accuracy.
// [X] Allin attack; bonus damage, accuracy and crit change, but lose next round.
// [X] Disarming attack; deals reduced damage. On normal hit, the target resives a Weak Grip Deduff that reduces damage dealt, on a critical hit the target drops his weapon on the ground. 
// [X] Guarding attack; deals reduced damage, but increases resistance.
// [X] Evasive attack; reduced resistance, but increased dodge.
// [X] Vampiric attack; heals for half damage dealt, but at increased fumble. After used can not heal by any other means.
// [X] Blessed attack; gives temperarry health, but lose real health on a miss.
// [X] Berserking attack; deal damage to self, but gain a buff for 3 turns that increases damage dealt.
// [X] Targeted attack; attack at a specified item equiped on the target.. instead of the target.
// [X] Execute attack; if the strike kills the target, refunds the action, otherwise lose experience points.
// [X] Redirect attack; it the attack lands, the target will choose another enemy (if able) as it's next target, deals no damage and on the next initiative you go last.
// [X] Change attack; does one of 3 differenct effects: A) Resive temporary health, B) Set the enemy of fire, C) Increased change to fumple on this attack.
// [X] Cleansing attack; removes 1 random effect from the attacker.
// [X] Thieving attack; deals no damage, but will steal a random unequipped item from the targets inventory, but your dodge is set to one until your next turn.
// [X] Stylish attack; on crit convert random a lower level enenemy on your side, but on miss enrages all enemies in the room.
// [ ] Push attack; on hit reduces the targets initiative on the next round, but the enemy resives bonus dodge on the next turn.
// [ ] Rushed attack; reduced change to hit, but increased initiative on the next round.
// [ ] Bunker attack; deals no damage, but gives a massive boost to resistance for two rounds.
// [ ] Delayed attack; ends the turn, but gives a massive bonus to accuracry for the next round.
// [ ] Bane attack; stoppes healing resived by the target for one turn, but also stopes you from healing on this and next round.
// [ ] Plague attack; on hit applies Plague (Halfs the target maximum health for current and next room) on the target. On the start of the targets turn the plague spreads to random actor in the room (including the player!).
// [ ] Mimick attack; on hit copies the targets stats for the duration of the room.

namespace Attack_Mod
{
    #define ATTACK_MODIFIERS(X) \
    X(standard),                \
    X(reckless),                \
    X(careful),                 \
    X(weakspot),                \
    X(allin),                   \
    X(disarming),               \
    X(guarding),                \
    X(evasive),                 \
    X(vampiric),                \
    X(blessed),                 \
    X(berserking),              \
    X(targeted),                \
    X(execute),                 \
    X(redirect),                \
    X(change),                  \
    X(cleansing),               \
    X(thieving),                \
    X(stylish),                 \
    X(push),                    \
    X(bunker),                  \
    X(delayed),                 \
    X(bane),                    \
    X(plague),                  \
    X(mimic),                   \

    enum T
    {
        ATTACK_MODIFIERS(PASTE)
        COUNT
    };

    String name[] = 
    {
        ATTACK_MODIFIERS(PASTE_AS_STRING)
    };
    
    #undef ATTACK_MODIFIERS

    static_assert(COUNT < 64);
};


namespace CMD_Result
{
    enum T : u8
    {
        success,
        abort,
        invalid_args,
        none,
    };
};


struct Game_Command
{
    CMD_Result::T (*fn)(Entity* entity, String args, Game_State*);
    AT::T action_type;
    bool ends_turn;
    String name;
    char* description;
    char* arguments;
};


enum class Call_Style
{
    name,
    describe,
    execute,
};


struct Command
{
    CMD_Result::T (*fn)(Call_Style ccs, void* user_ptr, String args, Game_State* game_state);
};


constexpr char* yes_or_no = "\"yes\"/\"no\"";
constexpr char* target_args = 
"Name of the target, or a reference number.\n"
"Use the \"glance\" command to see the reference numbers.";
constexpr char* no_args = "Takes no arguments.";
constexpr char* help_command_description = "Lists all available commands, or describes a specific command if given as an argument.";
constexpr char* help_command_arguments = "Can be used with no arguments or a name of a command.";
constexpr char* inventory_target_args = 
"From the inventory; a name of the target, or a reference number\n"
"Use the \"inventory\" command to see the reference numbers.";

constexpr char* no_args_or_bangoverride = "Takes no arguments, or the character \"!\" to skip confirmation.";

constexpr char* glance_command_description = 
"Have a quick glance around the room to see what is around you.\n"
"Lists visible entities.\n\tThe number before an entity name can be used as a quick reference by other abilites such as attack.\n"
"For example: instead of writing attack giant rat you can use attack 1\n"
"(and that attacks the entity that was listed first by \"glance\"";

constexpr char* inspect_command_description     = 
"Gives a description of the target.\n"
"The target has to be in the same space as the player,\n"
"unless the \"inventory\" specifier is used as a first argument.\n"
"Then the target has to be inside the players inventory.";

constexpr char* inspect_command_args = 
"An optional \"inventory\" specifier followed by the name, or a reference number of the target.\n"
"Use \"glance\" command to see the available targets in the room space,\n"
"or the \"inventory\" command for available targets inside players inventory.";

constexpr char* proceed_command_description = 
"Attempt to leave this room and delwe deeper into the Dungeon.\n"
"This can be done freely if there are no hostiles in the room,\n"
"but otherwise a speed check is rolled against all of the hostiles in the room.\n"
"If any of them roll better than you, they prevent you from fleeing.";

constexpr char* attacks_command_description = 
"When used without arguments lists all known attack modifiers,\n"
"or if a name of an attack modifier is provided as the argument,\n"
"provides a detailed description of said attack modifeir.";


constexpr char* camp_command_description =
"Attempt to rest and recuperate. A food item must be provided as an argument, that item is comsumed.\n"
"The user will go to sleep, during that sleep there is a change for an ambush! Said change dependens on the current room.\n"
"some rooms are more dangerous than other. If no abmush occurs then the user will recover health depeding on the quality of the food item used.\n"
"At this point a if the user has enough experience points he can also level up.";


constexpr char* search_command_description      = "Thoroughly search through the space for anything of interest.";
constexpr char* attack_command_description      = "Make an attempt to strike at a target.";
constexpr char* loot_command_description        = "Everything inside the target will be moved into the room space.";
constexpr char* pickup_command_description      = "Take the target and put in your inventory";
constexpr char* drop_command_description        = "Take the target from your inventory and drop it.";
constexpr char* inventory_command_description   = "Lists everything you are carrying in your inventory.";
constexpr char* equipment_command_description   = "Lists everything currently equipped.";
constexpr char* equip_command_description       = "Equips the targeted item from the inventory";
constexpr char* unequip_command_description     = "Unequips the targeted item. The item has to be equiped.";
constexpr char* status_command_description      = "Shows current health, experience points and active effects.";
constexpr char* use_command_description         = "Use an item from your inventory or interact with an object in the room.";
constexpr char* attacks_command_args            = "No arguments, or a name of an attack modifier.";

/*
    NOTE!
    It is possible and legal to have multiple commands that have the same begining part, but! the longer command must be listed first.
    Example equip and equipment.
    Equipment needs to be listed first.
*/
Game_Command Player_Actions[] = 
{
    { Help_Command,         AT::free,   0, STR("help"),         help_command_description,           help_command_arguments},
    { Proceed_Command,      AT::normal, 0, STR("proceed"),      proceed_command_description,        no_args},
    { Camp_Command,         AT::normal, 0, STR("camp"),         camp_command_description,           inventory_target_args},
    { Search_Command,       AT::normal, 0, STR("search"),       search_command_description,         no_args},
    { Inspect_Command,      AT::free,   0, STR("inspect"),      inspect_command_description,        inspect_command_args},
    { Glance_Command,       AT::free,   0, STR("glance"),       glance_command_description,         no_args},
    { Attacks_Command,      AT::free,   0, STR("attacks"),      attacks_command_description,        attacks_command_args},
    { Attack_Command,       AT::normal, 0, STR("attack"),       attack_command_description,         target_args},
    { Pass_Command,         AT::free,   1, STR("pass"),         "Ends your turn.",                  no_args},
    { Pickup_Command,       AT::normal, 0, STR("pickup"),       pickup_command_description,         target_args},
    { Loot_Command,         AT::normal, 0, STR("loot"),         loot_command_description,           target_args},
    { Drop_Command,         AT::normal, 0, STR("drop"),         drop_command_description,           inventory_target_args},
    { Stats_Command,        AT::free,   0, STR("stats"),        "Lists stat values.",               no_args},
    { Status_Command,       AT::free,   0, STR("status"),       status_command_description,         no_args},
    { Equipment_Command,    AT::free,   0, STR("equipment"),    equipment_command_description,      no_args},
    { Inventory_Command,    AT::free,   0, STR("inventory"),    inventory_command_description,      no_args},
    { Equip_Command,        AT::normal, 0, STR("equip"),        equip_command_description,          inventory_target_args},
    { Use_Command,          AT::bonus,  0, STR("use"),          use_command_description,            inventory_target_args},
    { Unequip_Command,      AT::free,   0, STR("unequip"),      unequip_command_description,        inventory_target_args},
    { Restart_Command,      AT::free,   1, STR("restart"),      "Restart the game.",                no_args_or_bangoverride},
    { Exit_Command,         AT::free,   1, STR("exit"),         "Quit the game.",                   no_args_or_bangoverride},
    { Toggle_Dramatic_Pause,AT::free,   0, STR("dramatic pause"),"Toggles dramatic pausing.",       no_args},
    
    
    #if DEVMODE
    { Save_Command,         AT::free,   0, STR("save"),         "Saves the game.",                  no_args},
    { Load_Command,         AT::free,   1, STR("load"),         "Loads the game.",                  no_args},
    { Toggle_Godmode,       AT::free,   0, STR("godmode"),      "Toggles godmode.",                 no_args},
    { Kill_Command,         AT::free,   0, STR("kill"),         "Kills the target.",                target_args},
    { What_Is_Seed_Command, AT::free,   0, STR("what is seed?"),"Reveals the seed.",                target_args},
    { Set_Seed_Command,     AT::free,   0, STR("set seed"),     "Sets the random number generator seed.", "takes the new seed as the argument."},
    { Get_Exp_Command,      AT::free,   0, STR("get exp"),      "Gives the user exp.",              "takes the the amount as the argument."},
    #endif
};


// NOTE: Kinda wanted to just burry these down here xD
HEADACHE(typedef void PROTOTYPE_ENT_GS(Entity*, Game_State*);)
HEADACHE(typedef void PROTOTYPE_ENT_ENT_GS(Entity*, Entity*, Game_State*);)
HEADACHE(typedef void PROTOTYPE_EFFINST_ENT_GS(Effect_Instance*, Entity*, Game_State*);)
HEADACHE(typedef void PROTOTYPE_EFFINST_ENT_ENT_GS(Effect_Instance*, Entity*, Entity*, Game_State*);)
HEADACHE(typedef void PROTOTYPE_EFFINST_ENT_ENT_AR_GS(Effect_Instance*, Entity*, Entity*, Attack_Record*, Game_State*);)
HEADACHE(typedef void PROTOTYPE_EFFINST_ENTOFF_ENT_DDR_GS(Effect_Instance*, Entity_Offset, Entity*, Deal_Damage_Result*, Game_State*);)
HEADACHE(typedef void PROTOTYPE_EFFINST_ENT_S32PTR_STR_GS(Effect_Instance*, Entity*, s32*, String, Game_State*);)
HEADACHE(typedef void PROTOTYPE_EFFINST_ENT_STAT_S32PTR_S16PTR_GS(Effect_Instance*, Entity*, Stats::T, s32*, s16*, Game_State*);)

HEADACHE(typedef Entity* GENERATE_ENTITY_FN(Entity*, Game_State*);)
