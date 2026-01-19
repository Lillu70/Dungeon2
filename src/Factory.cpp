

// ===================================
// Copyright (c) 2025 by Valtteri Kois
// All rights reserved.
// ===================================


// - Enemies

// Pyrocroc (slow, apply searing heat, avg hp/armor, consitant dmg like maces, no dodge)
// Bat (sonic attak) change to pass a turn for a quarenteed critical strike on the next one.


// Mutant Antlion (speed and dodge bad, if attacked applies sandpit that prevents escape and on turn end deals 1 damage per turn it has been active) Good loot in the room
// Medusa, attacking it reduces speed, if this effect would bring your speed down to zero, you die!

// Troll, has the great club, no dodge, no armor, a good bit of HP and a regen effect, that only works if the troll dosn't have status effects.

// - Rooms:
// snakepit (snakes)
// ashlake (pyrocroc)
// Beehive (has some containers, and a beehive that deals 1 damage per turn)


// - Status effects:
// Unbearable cold, on turn start reduce speed by 1 for every turn the effect has been active, if the effect would reduce your seep down to zero, you die.
// Searing heat, on turn start reduce carrying capacity by 5 per turn for every turn this effect has been active, lasts 2 rooms, if this effect would reduce your carrying capacity down to zero, you die.


// Grove altar( signing flower: 5% crit )
// blood sacrifice thing.
// healing shrine with offerings give food item
// altar to gods
// - 
// Fake clones, that you have to inspect.
// Hydra mechanic, if you kill a second head; two heads spawn.


SIG Entity* Create_Class_Adventurer(Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);
    entity->name_offset = Offset(STR("Adventurer"), game_state);
    entity->description_offset = Offset(STR("A well rounded and beginer friendly. Has a good stockpile of supplies."), game_state);
    entity->flags |= EFlags::actor;

    {
        s16* stats = entity->_stats;
        stats[Stats::vitality]  = 5;
        stats[Stats::might]     = 5;
        stats[Stats::dodge]     = 5;
        stats[Stats::accuracy]  = 5;
    }

    Full_Heal(entity,  game_state);

    entity->known_attack_modifiers |= 
    (
        Attack_Modifier_Mask(Attack_Mod::reckless)  |
        Attack_Modifier_Mask(Attack_Mod::careful)   |
        Attack_Modifier_Mask(Attack_Mod::redirect)   
    );

    Set_Level_Based_On_Stats(entity);
    
    Equip(entity, Create_Straightsword(entity, game_state), game_state);
    Equip(entity, Create_Wooden_Shield(entity, game_state), game_state);

    Equip(entity, Create_Leather_Cuirass(entity, game_state), game_state);
    Equip(entity, Create_Arming_Cap(entity, game_state), game_state);
    
    LOOP(3) Create_Healing_Potion(entity, game_state);
    LOOP(2) Create_Bomb(entity, game_state);
    LOOP(3) Create_Jerky(entity, game_state);
    LOOP(3) Create_Bread(entity, game_state);
    Create_Steak_And_Smashed_Potatoes(entity, game_state);

    //Equip(entity, Create_Ring_Of_False_Hope(entity, game_state), game_state);

    // Create_Ring_Of_Just_Fucking_Crit(entity, game_state);
    
    return entity;
}


SIG Entity* Create_Class_Mountaineer(Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);
    entity->name_offset = Offset(STR("Mountaineer"), game_state);
    entity->description_offset = Offset(STR("A glasscannon with limited supplies."), game_state);
    entity->flags |= EFlags::actor;

    {
        s16* stats = entity->_stats;
        stats[Stats::vitality]  = 4;
        stats[Stats::might]     = 6;
        stats[Stats::dodge]     = 5;
        stats[Stats::accuracy]  = 6;
    }

    Full_Heal(entity,  game_state);

    entity->known_attack_modifiers |= 
    (
        Attack_Modifier_Mask(Attack_Mod::execute) | 
        Attack_Modifier_Mask(Attack_Mod::berserking)
    );

    Set_Level_Based_On_Stats(entity);
    
    Equip(entity, Create_Great_Axe(entity, game_state), game_state);
    
    Equip(entity, Create_Leather_Tights(entity, game_state), game_state);
    
    LOOP(1) Create_Healing_Potion(entity, game_state);
    LOOP(2) Create_Jerky(entity, game_state);
    
    return entity;
}


SIG Entity* Create_Class_Wretched(Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);
    entity->name_offset = Offset(STR("Wretched"), game_state);
    entity->description_offset = Offset(STR("A pathetic and useless class that starts with nothing.\nIt does not get weaker than this."), game_state);
    entity->flags |= EFlags::actor;

    {
        s16* stats = entity->_stats;
        stats[Stats::vitality]  = 1;
        stats[Stats::might]     = 1;
        stats[Stats::dodge]     = 1;
        stats[Stats::accuracy]  = 1;
    }
    
    Full_Heal(entity,  game_state);
    Set_Level_Based_On_Stats(entity);
    
    return entity;
}


SIG Entity* Create_Goblin(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);
    
    entity->name_offset = Offset(STR("Goblin"), game_state);
    entity->description_offset = Offset(STR("Green filthy creature native to places dark and damp."), game_state);
    
    entity->flags = EFlags::actor | EFlags::aggressive | EFlags::can_be_stolen_from;
    entity->faction = Faction::goblin;
    entity->weight = 70;
    
    {
        s16* stats = entity->_stats;
        stats[Stats::vitality]  = 5;
        stats[Stats::might]     = 7;
        stats[Stats::dodge]     = 5;
        stats[Stats::accuracy]  = 6;
        stats[Stats::speed]     = 9;
        stats[Stats::arcane]    = 1;
        stats[Stats::immunity]  = 16;
        stats[Stats::armor]     = 7;
    }

    Finalize_Entity(entity, room, game_state);
    
    Effect_Instance effect_instance = 
    {
        UNLIMITED_DURATION, 
        {}, 
        Offset(entity, game_state)
    };

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &effect_instance.effect_offset, game_state))
    {
        struct local
        {
            static void On_Damage_Taken(Effect_Instance* instance, Entity_Offset attaker_offset, Entity* defender, Deal_Damage_Result* ddr, Game_State* game_state)
            {
                if(instance)
                {
                    Effect* effect = Request_Effect(game_state);
                    effect->stat_modifiers[Stats::dodge] = Level(defender);
                    effect->name_offset = Offset(STR("Evasive"), game_state);

                    Effect_Instance evasive = {};
                    evasive.duration = 1;
                    evasive.effect_offset = Offset(effect, game_state);
                    evasive.source = instance->source;

                    Apply_Effect_Result apply = Apply_Effect(defender, evasive, game_state);
                    Push_Generic_Apply_Effect_Message(Effect_Name(instance, game_state), defender, evasive, apply, game_state);
                }
                else
                {
                    Print("resieves the evasive buff, giving dodge equal to user level.");
                }
            }
        };

        Effect effect = {};
        effect.name_offset = Offset(STR("Scurry"), game_state);
        effect.on_damage_taken_fn_offset = Offset(local::On_Damage_Taken, game_state);
        effect.type = Effect_Type::physical;
        effect_instance.effect_offset = Insert_Effect(effect, key, game_state);
    }


    Apply_Effect_Result apply = Apply_Effect(entity, effect_instance, game_state, Forced::yes);
    Assert(apply == Apply_Effect_Result::success);

    {
        Rules_Builder rules = Rules_Builder().Rarity(Comparison::equal, Rarity::common).Weight(Comparison::maximum, 6);
        
        if(GENERATE_ENTITY_FN* weapon_gen_fn = Pick_From_Loot_Table(Basic_Weapons_Loot_Table(game_state), rules.Finish(), game_state))
        {
            Entity* weapon = weapon_gen_fn(entity, game_state);
            Equip(entity, weapon, game_state);

            bool is_1h_weapon = weapon->required_equipment_slots == Equipment_Slots::flag[Equipment_Slots::primary_hand];
            u32 roll = Roll(5, game_state);

            if(is_1h_weapon && roll >= 3)
            {
                u32 offhand_slot = Equipment_Slots::flag[Equipment_Slots::secondary_hand];
                rules.Slot_Filters(&offhand_slot, 1);

                if(GENERATE_ENTITY_FN* offhand_gen_fn = Pick_From_Loot_Table(Basic_Armors_Loot_Table(game_state), rules.Finish(), game_state))
                {
                    Entity* offhand = offhand_gen_fn(entity, game_state);
                    Equip(entity, offhand, game_state);
                }
            }
        }
    }

    Generate_From_Loot_Table
    (
        entity, 
        Basic_Merged_Loot_Table(game_state), 
        Per_Count_Rolled_Random(3, 6, game_state), 
        Rules_Builder().Rarity(Comparison::maximum, Rarity::rare).Finish(), 
        game_state
    );

    return entity;
}


SIG Entity* Create_Orc(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);
    
    entity->name_offset = Offset(STR("Orc"), game_state);
    entity->description_offset = Offset(STR("Humanoid creature of pure evil. Rumors say they are bread somewhere deep underground."), game_state);
    
    entity->flags = EFlags::actor | EFlags::aggressive | EFlags::can_be_stolen_from;
    entity->faction = Faction::goblin;
    entity->weight = 120;
    
    {
        s16* stats = entity->_stats;
        stats[Stats::vitality]  = 7;
        stats[Stats::might]     = 5;
        stats[Stats::dodge]     = 4;
        stats[Stats::accuracy]  = 6;
        stats[Stats::speed]     = 7;
        stats[Stats::arcane]    = 1;
        stats[Stats::immunity]  = 10;
        stats[Stats::armor]     = 5;
    }

    Finalize_Entity(entity, room, game_state);
    
    Effect_Instance effect_instance = 
    {
        UNLIMITED_DURATION, 
        {}, 
        Offset(entity, game_state)
    };

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &effect_instance.effect_offset, game_state))
    {
        struct local
        {
            static void On_Damage_Taken(Effect_Instance* instance, Entity_Offset attaker_offset, Entity* defender, Deal_Damage_Result* ddr, Game_State* game_state)
            {
                s32 damage_threshold = 5;
                if(instance)
                {
                    if(ddr->damage_after_mitigation > damage_threshold)
                    {
                        Effect_Instance enraged = Get_Enraged(defender, game_state);
                        Apply_Effect_Result apply = Apply_Effect(defender, enraged, game_state);
                        Push_Generic_Apply_Effect_Message(Effect_Name(instance, game_state), defender, enraged, apply, game_state);
                    }
                }
                else
                {
                    Print("If damage from single source exceeds %d, the effected reseives the \"Enraged\" buff.", damage_threshold);
                }
            }
        };

        Effect effect = {};
        effect.name_offset = Offset(STR("Wrath"), game_state);
        effect.on_damage_taken_fn_offset = Offset(local::On_Damage_Taken, game_state);
        effect.type = Effect_Type::physical;
        effect_instance.effect_offset = Insert_Effect(effect, key, game_state);
    }


    Apply_Effect_Result apply = Apply_Effect(entity, effect_instance, game_state, Forced::yes);
    Assert(apply == Apply_Effect_Result::success);

    {
        Rules_Builder rules = Rules_Builder().Rarity(Comparison::maximum, Rarity::uncommon);
        
        if(GENERATE_ENTITY_FN* weapon_gen_fn = Pick_From_Loot_Table(Basic_Weapons_Loot_Table(game_state), rules.Finish(), game_state))
        {
            Entity* weapon = weapon_gen_fn(entity, game_state);
            Equip(entity, weapon, game_state);

            bool is_1h_weapon = weapon->required_equipment_slots == Equipment_Slots::flag[Equipment_Slots::primary_hand];
            u32 roll = Roll(5, game_state);

            if(is_1h_weapon && roll >= 3)
            {
                u32 offhand_slot = Equipment_Slots::flag[Equipment_Slots::secondary_hand];
                rules.Slot_Filters(&offhand_slot, 1);

                if(GENERATE_ENTITY_FN* offhand_gen_fn = Pick_From_Loot_Table(Basic_Armors_Loot_Table(game_state), rules.Finish(), game_state))
                {
                    Entity* offhand = offhand_gen_fn(entity, game_state);
                    Equip(entity, offhand, game_state);
                }
            }
        }
    }

    Generate_From_Loot_Table
    (
        entity, 
        Basic_Merged_Loot_Table(game_state), 
        Per_Count_Rolled_Random(3, 4, game_state), 
        Rules_Builder().Rarity(Comparison::maximum, Rarity::rare).Finish(), 
        game_state
    );

    return entity;
}


SIG Entity* Create_Bandit(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);
    
    entity->name_offset = Offset(STR("Bandit"), game_state);
    entity->description_offset = Offset(STR("A cave dwelling bandit, he looks to be up to no good."), game_state);
    
    entity->flags = EFlags::actor | EFlags::aggressive | EFlags::can_be_stolen_from;
    entity->faction = Faction::bandit;
    entity->weight = 100;
    
    {
        s16* stats = entity->_stats;
        stats[Stats::vitality]  = 6;
        stats[Stats::might]     = 6;
        stats[Stats::dodge]     = 6;
        stats[Stats::accuracy]  = 6;
        stats[Stats::speed]     = 10;
        stats[Stats::arcane]    = 5;
        stats[Stats::immunity]  = 5;
        stats[Stats::armor]     = 5;
    }

    Finalize_Entity(entity, room, game_state);
    
    {
        Rules_Builder rules = Rules_Builder().Rarity(Comparison::maximum, Rarity::uncommon);
        
        if(GENERATE_ENTITY_FN* weapon_gen_fn = Pick_From_Loot_Table(Basic_Weapons_Loot_Table(game_state), rules.Finish(), game_state))
        {
            Entity* weapon = weapon_gen_fn(entity, game_state);
            Equip(entity, weapon, game_state);

            bool is_1h_weapon = weapon->required_equipment_slots == Equipment_Slots::flag[Equipment_Slots::primary_hand];
            u32 roll = Roll(5, game_state);

            if(is_1h_weapon && roll >= 3)
            {
                u32 offhand_slot = Equipment_Slots::flag[Equipment_Slots::secondary_hand];
                rules.Slot_Filters(&offhand_slot, 1);

                if(GENERATE_ENTITY_FN* offhand_gen_fn = Pick_From_Loot_Table(Basic_Armors_Loot_Table(game_state), rules.Finish(), game_state))
                {
                    Entity* offhand = offhand_gen_fn(entity, game_state);
                    Equip(entity, offhand, game_state);
                }
            }
        }
    }

    {
        Pick_From_Table_Rules rules = Rules_Builder()
        .Excluded_Slots(Equipment_Slots::flag[Equipment_Slots::secondary_hand])
        .Rarity(Comparison::maximum, Rarity::rare)
        .Finish();
        
        u64 count = Per_Count_Rolled_Square_Weighted_Random(5, game_state);
        for(u64 i = 0; i < count; ++i)
        {
            if(GENERATE_ENTITY_FN* armor_gen_fn = Pick_From_Loot_Table(Basic_Armors_Loot_Table(game_state), rules, game_state))
            {
                Entity* armor = armor_gen_fn(entity, game_state);
                Equip(entity, armor, game_state);

                rules.excluded_slots |= armor->required_equipment_slots;
            }
        }
    }

    Generate_From_Loot_Table
    (
        entity, 
        Basic_Merged_Loot_Table(game_state), 
        Per_Count_Rolled_Random(3, 8, game_state), 
        Rules_Builder().Rarity(Comparison::maximum, Rarity::rare).Finish(), 
        game_state
    );

    return entity;
}


SIG Entity* Create_Skeleton(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);
    
    entity->name_offset = Offset(STR("Skeleton"), game_state);
    entity->description_offset = Offset(STR("An animated skeleton. Necromantic energies are keeping it operational."), game_state);
    
    entity->flags = EFlags::actor | EFlags::aggressive | EFlags::can_be_stolen_from;
    entity->faction = Faction::undead;
    entity->weight = 100;
    
    {
        s16* stats = entity->_stats;
        stats[Stats::vitality]  = 8;
        stats[Stats::might]     = 8;
        stats[Stats::dodge]     = 8;
        stats[Stats::accuracy]  = 8;
        stats[Stats::speed]     = 10;
        stats[Stats::arcane]    = 5;
        stats[Stats::immunity]  = 5;
        stats[Stats::armor]     = 7;
    }

    Finalize_Entity(entity, room, game_state);
    
    {
        Rules_Builder rules = Rules_Builder().Rarity(Comparison::maximum, Rarity::uncommon);
        
        if(GENERATE_ENTITY_FN* weapon_gen_fn = Pick_From_Loot_Table(Basic_Weapons_Loot_Table(game_state), rules.Finish(), game_state))
        {
            Entity* weapon = weapon_gen_fn(entity, game_state);
            Equip(entity, weapon, game_state);

            bool is_1h_weapon = weapon->required_equipment_slots == Equipment_Slots::flag[Equipment_Slots::primary_hand];
            u32 roll = Roll(5, game_state);

            if(is_1h_weapon && roll >= 3)
            {
                u32 offhand_slot = Equipment_Slots::flag[Equipment_Slots::secondary_hand];
                rules.Slot_Filters(&offhand_slot, 1);

                if(GENERATE_ENTITY_FN* offhand_gen_fn = Pick_From_Loot_Table(Basic_Armors_Loot_Table(game_state), rules.Finish(), game_state))
                {
                    Entity* offhand = offhand_gen_fn(entity, game_state);
                    Equip(entity, offhand, game_state);
                }
            }
        }
    }

    {
        Pick_From_Table_Rules rules = Rules_Builder()
        .Excluded_Slots(Equipment_Slots::flag[Equipment_Slots::secondary_hand])
        .Rarity(Comparison::maximum, Rarity::rare)
        .Finish();
        
        u64 count = Per_Count_Rolled_Square_Weighted_Random(5, game_state);
        for(u64 i = 0; i < count; ++i)
        {
            if(GENERATE_ENTITY_FN* armor_gen_fn = Pick_From_Loot_Table(Basic_Armors_Loot_Table(game_state), rules, game_state))
            {
                Entity* armor = armor_gen_fn(entity, game_state);
                Equip(entity, armor, game_state);

                rules.excluded_slots |= armor->required_equipment_slots;
            }
        }
    }

    Generate_From_Loot_Table
    (
        entity, 
        Basic_Merged_Loot_Table(game_state), 
        Per_Count_Rolled_Random(3, 8, game_state), 
        Rules_Builder().Rarity(Comparison::maximum, Rarity::rare).Finish(), 
        game_state
    );

    return entity;
}


SIG Entity* Create_Bandit_Leader(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);
    
    entity->name_offset = Offset(STR("Bandit Leader"), game_state);
    entity->description_offset = Offset(STR("A cave dwelling bandit, he has an aura of unquestionable authority."), game_state);
    
    entity->flags = EFlags::actor | EFlags::aggressive | EFlags::can_be_stolen_from;
    entity->faction = Faction::bandit;
    entity->weight = 100;
    
    {
        s16* stats = entity->_stats;
        stats[Stats::vitality]  = 10;
        stats[Stats::might]     = 9;
        stats[Stats::dodge]     = 8;
        stats[Stats::accuracy]  = 8;
        stats[Stats::speed]     = 10;
        stats[Stats::arcane]    = 5;
        stats[Stats::immunity]  = 5;
        stats[Stats::armor]     = 5;
    }

    Finalize_Entity(entity, room, game_state);
    
    {
        Rules_Builder rules = Rules_Builder().Rarity(Comparison::maximum, Rarity::rare);
        
        if(GENERATE_ENTITY_FN* weapon_gen_fn = Pick_From_Loot_Table(Basic_Weapons_Loot_Table(game_state), rules.Finish(), game_state))
        {
            Entity* weapon = weapon_gen_fn(entity, game_state);
            Equip(entity, weapon, game_state);

            bool is_1h_weapon = weapon->required_equipment_slots == Equipment_Slots::flag[Equipment_Slots::primary_hand];
            u32 roll = Roll(5, game_state);

            if(is_1h_weapon && roll >= 3)
            {
                u32 offhand_slot = Equipment_Slots::flag[Equipment_Slots::secondary_hand];
                rules.Slot_Filters(&offhand_slot, 1);

                if(GENERATE_ENTITY_FN* offhand_gen_fn = Pick_From_Loot_Table(Basic_Armors_Loot_Table(game_state), rules.Finish(), game_state))
                {
                    Entity* offhand = offhand_gen_fn(entity, game_state);
                    Equip(entity, offhand, game_state);
                }
            }
        }
    }

    {
        Pick_From_Table_Rules rules = Rules_Builder()
        .Excluded_Slots(Equipment_Slots::flag[Equipment_Slots::secondary_hand])
        .Rarity(Comparison::between, Rarity::uncommon, Rarity::epic)
        .Finish();
        
        u64 count = Per_Count_Rolled_Square_Weighted_Random(5, game_state);
        for(u64 i = 0; i < count; ++i)
        {
            if(GENERATE_ENTITY_FN* armor_gen_fn = Pick_From_Loot_Table(Basic_Armors_Loot_Table(game_state), rules, game_state))
            {
                Entity* armor = armor_gen_fn(entity, game_state);
                Equip(entity, armor, game_state);

                rules.excluded_slots |= armor->required_equipment_slots;
            }
        }
    }

    Generate_From_Loot_Table
    (
        entity, 
        Basic_Merged_Loot_Table(game_state), 
        Per_Count_Rolled_Random(4, 3, game_state), 
        Rules_Builder().Rarity(Comparison::maximum, Rarity::epic).Finish(), 
        game_state
    );

    return entity;
}


SIG Entity* Create_Assassin(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);
    
    entity->name_offset = Offset(STR("Assassin"), game_state);
    entity->description_offset = Offset(STR("A shadowy figure, crouching in the darkness."), game_state);
    
    entity->flags = EFlags::actor | EFlags::aggressive | EFlags::can_be_stolen_from;
    entity->faction = Faction::bandit;
    entity->weight = 100;
    
    {
        s16* stats = entity->_stats;
        stats[Stats::vitality]  = 6;
        stats[Stats::might]     = 5;
        stats[Stats::dodge]     = 7;
        stats[Stats::accuracy]  = 6;
        stats[Stats::speed]     = 13;
        stats[Stats::arcane]    = 5;
        stats[Stats::immunity]  = 5;
        stats[Stats::armor]     = 5;
    }

    Finalize_Entity(entity, room, game_state);
    
    Loot_Table_Entry weapons[] =
    {
        {Create_Assassins_Claws},
        //{Create_Cestus},
        {Create_Dagger},
        {Create_Poison_Dagger},
        {Create_Straightsword},
        {Create_Short_Spear},
        {Create_Whip},
    };

    Loot_Table weapons_table = {weapons, Array_Length(weapons)};
    Fill_Loot_Table_Changes_And_Item_Rarity(&weapons_table, game_state);

    if(GENERATE_ENTITY_FN* weapon_gen_fn = Pick_From_Loot_Table(weapons_table, {}, game_state))
    {
        Entity* weapon = weapon_gen_fn(entity, game_state);
        Equip(entity, weapon, game_state);
    }

    Pick_From_Table_Rules rules = Rules_Builder()
    .Excluded_Slots(Equipment_Slots::flag[Equipment_Slots::secondary_hand])
    .Weight(Comparison::maximum, 5)
    .Rarity(Comparison::maximum, Rarity::rare)
    .Finish();
    
    u64 count = Per_Count_Rolled_Random(5, 7, game_state);
    for(u64 i = 0; i < count; ++i)
    {
        if(GENERATE_ENTITY_FN* armor_gen_fn = Pick_From_Loot_Table(Basic_Armors_Loot_Table(game_state), rules, game_state))
        {
            Entity* armor = armor_gen_fn(entity, game_state);
            Equip(entity, armor, game_state);

            rules.excluded_slots |= armor->required_equipment_slots;
        }
    }

    Generate_From_Loot_Table
    (
        entity, 
        Basic_Merged_Loot_Table(game_state), 
        Per_Count_Rolled_Square_Weighted_Random(3, game_state), 
        Rules_Builder().Rarity(Comparison::maximum, Rarity::rare).Finish(), 
        game_state
    );

    return entity;
}


SIG Entity* Create_Bandit_King(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);
    
    entity->name_offset = Offset(STR("Bandit King"), game_state);
    entity->description_offset = Offset(STR("Ruler of the undergound bandits. The rumors of this mans cruelty have spread even up on the surface."), game_state);

    entity->flags = EFlags::actor | EFlags::aggressive | EFlags::can_be_stolen_from;
    entity->faction = Faction::bandit;
    entity->weight = 140;
    
    {
        s16* stats = entity->_stats;
        stats[Stats::vitality]  = 13;
        stats[Stats::might]     = 5;
        stats[Stats::dodge]     = 8;
        stats[Stats::accuracy]  = 8;
        stats[Stats::speed]     = 10;
        stats[Stats::arcane]    = 5;
        stats[Stats::immunity]  = 5;
        stats[Stats::armor]     = 11;
    }
    
    Finalize_Entity(entity, room, game_state);

    Equip(entity, Create_Great_Sword(entity, game_state), game_state);


    Loot_Table table = Basic_Merged_Loot_Table(game_state);
    Generate_From_Loot_Table
    (
        entity, 
        table, 
        Per_Count_Rolled_Random(5, 3, game_state), 
        Rules_Builder().Rarity(Comparison::maximum, Rarity::rare).Finish(), 
        game_state
    );

    Generate_From_Loot_Table
    (
        entity, 
        table, 
        1, 
        Rules_Builder().Rarity(Comparison::minimum, Rarity::rare).Finish(), 
        game_state
    );
    
    return entity;
}


SIG Entity* Create_Concubine(Entity* room, Game_State* game_state)
{
    struct local
    {
        static bool Could_Be_Master(Entity* entity, void* user_ptr, Game_State* game_state)
        {
            Entity_Offset weapon = entity->equipment[Equipment_Slots::primary_hand];

            Entity* concubine = (Entity*)user_ptr;
            bool result = Is_Alive(entity) && entity->faction == concubine->faction && (entity->flags & EFlags::aggressive) && Pointer(weapon, game_state);
            return result;
        }


        static s32 Temp_Health_Amount()
        {
            return 5;
        }

        static void On_Turn_Start(Effect_Instance* instance, Entity* target, Game_State* game_state)
        {
            s32 temp_health_amount = Temp_Health_Amount();
            s16 might_boost = 1;
            if(instance)
            {
                Effect* effect = Request_Effect(game_state);
                effect->stat_modifiers[Stats::might] += might_boost;
                effect->name_offset = Offset(STR("Worshiped"), game_state);
                effect->type = Effect_Type::physical;

                Effect_Instance worship = {};
                worship.effect_offset = Offset(effect, game_state);
                worship.source = instance->source;
                worship.duration = 1;

                Entity* residence = Pointer(target->residence, game_state);

                if(Entity* master = Random_Entity_That_Matches_Criteria(&residence->inventory, Could_Be_Master, target, game_state))
                {
                    String source_name = Name(target, game_state);

                    Apply_Effect_Result apply = Apply_Effect(master, worship, game_state);
                    Push_Generic_Apply_Effect_Message(source_name, master, worship, apply, game_state);
                    Give_Temporary_Health(master, Temp_Health_Amount(), source_name, Verbose::yes, game_state);
                }
            }
            else
            {
                Print
                (
                    "Gives the Master the \"Worshiped\" buff, increasing his might by %d point%s and giving him %d point%s of temporary health.",
                    might_boost,
                    (might_boost > 1)? "s" : "",
                    temp_health_amount,
                    (temp_health_amount > 1)? "s" : ""
                );
            }
        }
    };

    Entity* entity = Request_Entity(game_state);
    
    entity->name_offset = Offset(STR("Concubine"), game_state);
    entity->description_offset = Offset(STR("Subjucated worshiper of her master."), game_state);
    
    entity->flags = EFlags::actor;
    entity->faction = Faction::bandit;
    entity->weight = 60;
    
    {
        s16* stats = entity->_stats;
        stats[Stats::vitality]  = 4;
        stats[Stats::might]     = 2;
        stats[Stats::dodge]     = 1;
        stats[Stats::accuracy]  = 1;
        stats[Stats::speed]     = 5;
        stats[Stats::arcane]    = 1;
        stats[Stats::immunity]  = 5;
        stats[Stats::armor]     = 1;
    }

    Effect_Instance effect_instance = 
    {
        UNLIMITED_DURATION, 
        {}, 
        Offset(entity, game_state)
    };

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &effect_instance.effect_offset, game_state))
    {
        Effect effect = {};
        effect.type = Effect_Type::magic;
        effect.name_offset = Offset(STR("Subjucation"), game_state);
        effect.on_turn_start_fn_offset = Offset(local::On_Turn_Start, game_state);
        effect_instance.effect_offset = Insert_Effect(effect, key, game_state);
    }

    Apply_Effect_Result apply = Apply_Effect(entity, effect_instance, game_state, Forced::yes);
    Assert(apply == Apply_Effect_Result::success);

    Finalize_Entity(entity, room, game_state);
    
    return entity;
}


SIG Entity* Create_Giant_Honey_Badger(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Giant honey badger"), game_state);
    entity->description_offset = Offset(STR("An extrimely resiliant creature."), game_state);

    entity->flags = EFlags::actor | EFlags::aggressive;
    entity->faction = Faction::nature;
    entity->weight = 80;

    {
        s16* stats = entity->_stats;
        stats[Stats::vitality]  = 7;
        stats[Stats::might]     = 5;
        stats[Stats::dodge]     = 4;
        stats[Stats::accuracy]  = 4;
        stats[Stats::speed]     = 8;
        stats[Stats::arcane]    = 5;
        stats[Stats::immunity]  = 10;
        stats[Stats::armor]     = 0;
    }
    
    {
        Effect_Instance effect_instance = 
        {
            UNLIMITED_DURATION, 
            {}, 
            Offset(entity, game_state)
        };

        Effect_Hash_Key key = EFFECT_KEY;
        if(!Retrive_Effect(key, &effect_instance.effect_offset, game_state))
        {
            Effect effect = {};
            effect.name_offset = Offset(STR("Claws"), game_state);
            effect.critical_failure_range = + 1;
            effect.on_turn_start_fn_offset = Offset(Survival_Instinct_On_Turn_Start, game_state);
            Add_Dice(&effect, 1, 5);
            effect_instance.effect_offset = Insert_Effect(effect, key, game_state);
        }

        Apply_Effect_Result apply = Apply_Effect(entity, effect_instance, game_state, Forced::yes);
        Assert(apply == Apply_Effect_Result::success);
    }

    {
        Effect_Instance effect_instance = 
        {
            UNLIMITED_DURATION, 
            {}, 
            Offset(entity, game_state)
        };

        Effect_Hash_Key key = EFFECT_KEY;
        if(!Retrive_Effect(key, &effect_instance.effect_offset, game_state))
        {
            Effect effect = {};
            effect.name_offset = Offset(STR("Survivor"), game_state);
            effect.on_turn_start_fn_offset = Offset(Survival_Instinct_On_Turn_Start, game_state);
            effect.type = Effect_Type::physical;
            effect_instance.effect_offset = Insert_Effect(effect, key, game_state);
        }

        Apply_Effect_Result apply = Apply_Effect(entity, effect_instance, game_state, Forced::yes);
        Assert(apply == Apply_Effect_Result::success);
    }

    Generate_From_Loot_Table
    (
        entity, 
        Basic_Merged_Loot_Table(game_state), 
        1 + Per_Count_Rolled_Random(2, 5, game_state), 
        Rules_Builder().Rarity(Comparison::maximum, Rarity::rare).Finish(), 
        game_state
    );

    if(Roll(100, game_state) == 1)
    {
        Create_Ring_Of_Survival_Instinct(entity, game_state);
    }

    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Living_Vine(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Living vine"), game_state);
    entity->description_offset = Offset(STR("A shambling mess of thorny vines."), game_state);

    entity->flags = EFlags::actor | EFlags::aggressive;
    entity->faction = Faction::nature;
    entity->weight = 180;

    {
        s16* stats = entity->_stats;
        stats[Stats::vitality]  = 7;
        stats[Stats::might]     = 6;
        stats[Stats::dodge]     = 5;
        stats[Stats::accuracy]  = 6;
        stats[Stats::speed]     = 10;
        stats[Stats::arcane]    = 8;
        stats[Stats::immunity]  = 5;
        stats[Stats::armor]     = 1;
    }
        
    Effect_Instance effect_instance = 
    {
        UNLIMITED_DURATION, 
        {}, 
        Offset(entity, game_state)
    };

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &effect_instance.effect_offset, game_state))
    {
        Effect effect = {};
        effect.name_offset = Offset(STR("Thorny vine"), game_state);
        effect.thorns_damage = 2;
        effect.on_hit_fn_offset = Offset(On_Hit_Apply_Seed, game_state);
        Add_Dice(&effect, 2, 6);
        effect_instance.effect_offset = Insert_Effect(effect, key, game_state);
    }

    Apply_Effect_Result apply = Apply_Effect(entity, effect_instance, game_state, Forced::yes);
    Assert(apply == Apply_Effect_Result::success);

    Generate_From_Loot_Table
    (
        entity, 
        Basic_Merged_Loot_Table(game_state), 
        Per_Count_Rolled_Random(3, 10, game_state), 
        Rules_Builder().Weight(Comparison::maximum, 10).Finish(), 
        game_state
    );

    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Vineling(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Vineling"), game_state);
    entity->description_offset = Offset(STR("A rapidly growing entangling vine."), game_state);

    entity->flags = EFlags::actor;
    entity->faction = Faction::player;
    entity->weight = 1;

    {
        s16* stats = entity->_stats;
        stats[Stats::vitality]  = 5;
        stats[Stats::might]     = 6;
        stats[Stats::dodge]     = 9;
        stats[Stats::accuracy]  = 1;
        stats[Stats::speed]     = 1;
        stats[Stats::arcane]    = 5;
        stats[Stats::immunity]  = 5;
        stats[Stats::armor]     = 1;
    }
        
    Effect_Instance effect_instance = 
    {
        UNLIMITED_DURATION, 
        {}, 
        Offset(entity, game_state)
    };

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &effect_instance.effect_offset, game_state))
    {
        struct local
        {
            static void On_Turn_Start(Effect_Instance* instance, Entity* target, Game_State* game_state)
            {
                if(instance)
                {
                    String effect_name = Effect_Name(instance, game_state);

                    Entity_Iterator iter = Make_Iterator(Pointer(target->residence, game_state), game_state);
                    while(Entity* entity = Next_Entity(&iter))
                    {
                        if(entity != target && Is_Alive(entity))
                        {
                            Effect_Instance inst = Get_Entangled(1, target, game_state);
                            Apply_Effect_Result apply = Apply_Effect(entity, inst, game_state);
                            Push_Generic_Apply_Effect_Message(effect_name, entity, inst, apply, game_state);
                        }
                    }
                }
            }
        };

        Effect effect = {};
        effect.name_offset = Offset(STR("Entangling vine"), game_state);
        effect.on_turn_start_fn_offset = Offset(local::On_Turn_Start, game_state);
        effect.thorns_damage = 1;
        effect_instance.effect_offset = Insert_Effect(effect, key, game_state);
    }

    Apply_Effect_Result apply = Apply_Effect(entity, effect_instance, game_state, Forced::yes);
    Assert(apply == Apply_Effect_Result::success);


    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Leech(Entity* room, Game_State* game_state)
{
    struct local
    {
        static void On_Hit(Effect_Instance* instance, Entity* attacker, Entity* defender, Attack_Record* ar, Game_State* game_state)
        {
            if(attacker)
            {
                Attempt_Infection(attacker, defender, Effect_Name(instance, game_state), Get_Leech(7, attacker, game_state), game_state);
            }
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Leech"), game_state);
    entity->description_offset = Offset(STR("A black worm-like vampire creature."), game_state);

    entity->flags = EFlags::actor | EFlags::aggressive;
    entity->faction = Faction::nature;
    entity->weight = 2;

    {
        s16* stats = entity->_stats;
        stats[Stats::vitality]  = 2;
        stats[Stats::might]     = 2;
        stats[Stats::dodge]     = 2;
        stats[Stats::accuracy]  = 2;
        stats[Stats::speed]     = 12;
        stats[Stats::arcane]    = 7;
        stats[Stats::immunity]  = 7;
        stats[Stats::armor]     = 2;
    }
        
    Effect_Instance effect_instance = 
    {
        UNLIMITED_DURATION, 
        {}, 
        Offset(entity, game_state)
    };
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &effect_instance.effect_offset, game_state))
    {
        Effect effect = {};
        effect.on_hit_fn_offset = Offset(local::On_Hit, game_state);
        Add_Dice(&effect, 1, 4);
        effect_instance.effect_offset = Insert_Effect(effect, key, game_state);
    }

    Apply_Effect_Result apply = Apply_Effect(entity, effect_instance, game_state, Forced::yes);
    Assert(apply == Apply_Effect_Result::success);

    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Giant_Toad(Entity* room, Game_State* game_state)
{
    struct local
    {
        static void On_Hit(Effect_Instance* instance, Entity* attacker, Entity* defender, Attack_Record* ar, Game_State* game_state)
        {
            if(attacker)
            {
                Attempt_Infection(attacker, defender, Effect_Name(instance, game_state), Get_Poison(5, attacker, game_state), game_state);
            }
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Giant Toad"), game_state);
    entity->description_offset = Offset(STR("Its bright colors suggest danger."), game_state);

    entity->flags = EFlags::actor | EFlags::aggressive;
    entity->faction = Faction::nature;
    entity->weight = 30;

    {
        s16* stats = entity->_stats;
        stats[Stats::vitality]  = 6;
        stats[Stats::might]     = 7;
        stats[Stats::dodge]     = 2;
        stats[Stats::accuracy]  = 8;
        stats[Stats::speed]     = 15;
        stats[Stats::arcane]    = 13;
        stats[Stats::immunity]  = 15;
        stats[Stats::armor]     = 1;
    }
        
    Effect_Instance effect_instance = 
    {
        UNLIMITED_DURATION, 
        {}, 
        Offset(entity, game_state)
    };
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &effect_instance.effect_offset, game_state))
    {
        Effect effect = {};
        effect.on_hit_fn_offset = Offset(local::On_Hit, game_state);
        Add_Dice(&effect, 1, 4);
        effect_instance.effect_offset = Insert_Effect(effect, key, game_state);
    }

    Apply_Effect_Result apply = Apply_Effect(entity, effect_instance, game_state, Forced::yes);
    Assert(apply == Apply_Effect_Result::success);

    Rules_Builder rules = Rules_Builder().Rarity(Comparison::maximum, Rarity::rare);
    Generate_From_Loot_Table(entity, Basic_Merged_Loot_Table(game_state), Per_Count_Rolled_Random(3, 5, game_state), rules.Finish(), game_state);

    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Mosquito(Entity* room, Game_State* game_state)
{
    struct local
    {
        static void On_Hit(Effect_Instance* instance, Entity* attacker, Entity* defender, Attack_Record* ar, Game_State* game_state)
        {
            if(attacker)
            {
                Attempt_Infection(attacker, defender, Effect_Name(instance, game_state), Get_Malaria(2, attacker, game_state), game_state);

                Effect_Instance filled = Get_Filled_With_Blood(UNLIMITED_DURATION, attacker, game_state);
                Apply_Effect_Result apply = Apply_Effect(attacker, filled, game_state, Forced::yes);

                Push_Generic_Apply_Effect_Message(Effect_Name(instance, game_state), attacker, filled, apply, game_state);
            }
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Mosquito"), game_state);
    entity->description_offset = Offset(STR("A blood sucking demon bug."), game_state);

    entity->flags = EFlags::actor | EFlags::aggressive;
    entity->faction = Faction::nature;
    entity->weight = 1;
    

    {
        s16* stats = entity->_stats;
        stats[Stats::vitality]  = 1;
        stats[Stats::might]     = 1;
        stats[Stats::dodge]     = 15;
        stats[Stats::accuracy]  = 5;
        stats[Stats::speed]     = 20;
        stats[Stats::arcane]    = 8;
        stats[Stats::immunity]  = 5;
        stats[Stats::armor]     = 0;
    }
    
    Effect_Instance effect_instance = 
    {
        UNLIMITED_DURATION, 
        {}, 
        Offset(entity, game_state)
    };

    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &effect_instance.effect_offset, game_state))
    {
        Effect effect = {};
        effect.on_hit_fn_offset = Offset(local::On_Hit, game_state);
        effect_instance.effect_offset = Insert_Effect(effect, key, game_state);
    }

    Apply_Effect_Result apply = Apply_Effect(entity, effect_instance, game_state, Forced::yes);
    Assert(apply == Apply_Effect_Result::success);

    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Wolf(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Wolf"), game_state);
    entity->description_offset = Offset(STR("Ferocious pack hunting canine."), game_state);

    entity->flags = EFlags::actor | EFlags::aggressive;
    entity->faction = Faction::nature;
    entity->weight = 80;

    {
        s16* stats = entity->_stats;
        stats[Stats::vitality]  = 4;
        stats[Stats::might]     = 4;
        stats[Stats::dodge]     = 3;
        stats[Stats::accuracy]  = 3;
        stats[Stats::speed]     = 8;
        stats[Stats::arcane]    = 5;
        stats[Stats::immunity]  = 5;
        stats[Stats::armor]     = 3;
    }
    
    Effect_Instance effect_instance = 
    {
        UNLIMITED_DURATION, 
        {}, 
        Offset(entity, game_state)
    };

    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &effect_instance.effect_offset, game_state))
    {
        Effect effect = {};
        effect.name_offset = Offset(STR("Jaws"), game_state);
        effect.critical_failure_range = + 1;
        effect.on_turn_start_fn_offset = Offset(Pack_Hunt_On_Turn_Start, game_state);
        Add_Dice(&effect, 1, 8);
        effect_instance.effect_offset = Insert_Effect(effect, key, game_state);
    }

    Apply_Effect_Result apply = Apply_Effect(entity, effect_instance, game_state, Forced::yes);
    Assert(apply == Apply_Effect_Result::success);


    Loot_Table table = Merge_Loot_Tables
    (
        Basic_Armors_Loot_Table(game_state), 
        Basic_Trinkets_Loot_Table(game_state), 
        Basic_Consumables_Loot_Table(game_state), 
        &game_state->scratch_buffer
    );

    Rules_Builder rules = Rules_Builder().Rarity(Comparison::maximum, Rarity::rare);
    Generate_From_Loot_Table(entity, table, Per_Count_Rolled_Random(3, 6, game_state), rules.Finish(), game_state);

    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Hound(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Hound"), game_state);
    entity->description_offset = Offset(STR("A large dog trained to kill on command."), game_state);

    entity->flags = EFlags::actor | EFlags::aggressive;
    entity->faction = Faction::bandit;
    entity->weight = 80;

    {
        s16* stats = entity->_stats;
        stats[Stats::vitality]  = 6;
        stats[Stats::might]     = 7;
        stats[Stats::dodge]     = 6;
        stats[Stats::accuracy]  = 7;
        stats[Stats::speed]     = 12;
        stats[Stats::arcane]    = 5;
        stats[Stats::immunity]  = 5;
        stats[Stats::armor]     = 8;
    }
    
    Effect_Instance effect_instance = 
    {
        UNLIMITED_DURATION, 
        {}, 
        Offset(entity, game_state)
    };

    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &effect_instance.effect_offset, game_state))
    {
        Effect effect = {};
        effect.name_offset = Offset(STR("Jaws"), game_state);
        effect.critical_failure_range = + 1;
        effect.on_turn_start_fn_offset = Offset(Pack_Hunt_On_Turn_Start, game_state);
        Add_Dice(&effect, 2, 6);
        effect_instance.effect_offset = Insert_Effect(effect, key, game_state);
    }

    Apply_Effect_Result apply = Apply_Effect(entity, effect_instance, game_state, Forced::yes);
    Assert(apply == Apply_Effect_Result::success);


    Loot_Table table = Merge_Loot_Tables
    (
        Basic_Armors_Loot_Table(game_state), 
        Basic_Trinkets_Loot_Table(game_state), 
        Basic_Consumables_Loot_Table(game_state), 
        &game_state->scratch_buffer
    );

    Rules_Builder rules = Rules_Builder().Rarity(Comparison::maximum, Rarity::rare);
    Generate_From_Loot_Table(entity, table, Per_Count_Rolled_Random(2, 6, game_state), rules.Finish(), game_state);

    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Fae_Flayer(Entity* room, Game_State* game_state)
{
    struct local
    {
        static void On_Hit(Effect_Instance* instance, Entity* attacker, Entity* defender, Attack_Record* ar, Game_State* game_state)
        {
            Dice dice = {2, 4};
            if(instance)
            {
                String source_name = Effect_Name(instance, game_state);
                s32 potency = Potency(source_name, {}, dice, game_state);
                Deal_Damage(defender, attacker, source_name, potency, {}, Damage_Type::magical, game_state, Verbose::yes);
            }
            else
            {
                Print("Deals %dd%d points of magic damage to the victim.", dice.count, dice.faces);
            }
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Fae Flayer"), game_state);
    entity->description_offset = Offset(STR("About a meter tall, winged gray humanoid creature. It's eyes are black and it's fingers end in large immaterial claws."), game_state);

    entity->flags = EFlags::actor | EFlags::aggressive;
    entity->faction = Faction::fae;
    entity->weight = 10;

    {
        s16* stats = entity->_stats;
        stats[Stats::vitality]  = 5;
        stats[Stats::might]     = 1;
        stats[Stats::dodge]     = 7;
        stats[Stats::accuracy]  = 6;
        stats[Stats::speed]     = 15;
        stats[Stats::arcane]    = 8;
        stats[Stats::immunity]  = 15;
        stats[Stats::armor]     = 6;
    }
    
    Effect_Instance effect_instance = 
    {
        UNLIMITED_DURATION, 
        {}, 
        Offset(entity, game_state)
    };
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &effect_instance.effect_offset, game_state))
    {
        Effect effect = {};
        effect.name_offset = Offset(STR("Immaterial Claws"), game_state);
        effect.on_hit_fn_offset = Offset(local::On_Hit, game_state);
        effect_instance.effect_offset = Insert_Effect(effect, key, game_state);
    }

    Apply_Effect_Result apply = Apply_Effect(entity, effect_instance, game_state, Forced::yes);
    Assert(apply == Apply_Effect_Result::success);

    Rules_Builder rules = Rules_Builder().Rarity(Comparison::maximum, Rarity::rare);
    Generate_From_Loot_Table(entity, Basic_Merged_Loot_Table(game_state), Per_Count_Rolled_Random(3, 5, game_state), rules.Finish(), game_state);

    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Salamander(Entity* room, Game_State* game_state)
{
    struct local
    {
        static void On_Hit(Effect_Instance* instance, Entity* attacker, Entity* defender, Attack_Record* ar, Game_State* game_state)
        {
            if(instance)
            {
                Attempt_Infection(attacker, defender, Effect_Name(instance, game_state), Get_Burning(2, attacker, game_state), game_state);
            }
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Salamander"), game_state);
    entity->description_offset = Offset(STR("A burning fire breathing lizard like creature."), game_state);

    entity->flags = EFlags::actor | EFlags::aggressive;
    entity->faction = Faction::nature;
    entity->weight = 50;

    {
        s16* stats = entity->_stats;
        stats[Stats::vitality]  = 14;
        stats[Stats::might]     = 6;
        stats[Stats::dodge]     = 6;
        stats[Stats::accuracy]  = 5;
        stats[Stats::speed]     = 12;
        stats[Stats::arcane]    = 6;
        stats[Stats::immunity]  = 5;
        stats[Stats::armor]     = 1;
    }
    
    Effect_Instance effect_instance = 
    {
        UNLIMITED_DURATION, 
        {}, 
        Offset(entity, game_state)
    };
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &effect_instance.effect_offset, game_state))
    {
        Effect effect = {};
        effect.name_offset = Offset(STR("Fire breath"), game_state);
        effect.on_hit_fn_offset = Offset(local::On_Hit, game_state);
        Add_Dice(&effect, 1, 10);
        effect_instance.effect_offset = Insert_Effect(effect, key, game_state);
    }

    Apply_Effect_Result apply = Apply_Effect(entity, effect_instance, game_state, Forced::yes);
    Assert(apply == Apply_Effect_Result::success);

    Rules_Builder rules = Rules_Builder().Rarity(Comparison::maximum, Rarity::rare);
    Generate_From_Loot_Table(entity, Basic_Merged_Loot_Table(game_state), Per_Count_Rolled_Random(3, 5, game_state), rules.Finish(), game_state);

    Finalize_Entity(entity, room, game_state);
    return entity;
}


// Earth golem, high armor, high might, slow, no dodge, low hp. On turn start if health is less than 50% die... and spawn 2 small earth golems.
// Small earth golem at 25% spawn 2 inty cute tiny earth golem
// Tiny earth golem after 2 turns they dissapete.
SIG Entity* Create_Earth_Golem(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Earth golem"), game_state);
    entity->description_offset = Offset(STR("A large stone construct."), game_state);

    entity->flags = EFlags::actor | EFlags::aggressive;
    entity->faction = Faction::nature;
    entity->weight = 200;
    
    {
        s16* stats = entity->_stats;
        stats[Stats::vitality]  = 6;
        stats[Stats::might]     = 10;
        stats[Stats::dodge]     = 1;
        stats[Stats::accuracy]  = 4;
        stats[Stats::speed]     = 1;
        stats[Stats::arcane]    = 1;
        stats[Stats::immunity]  = 15;
        stats[Stats::armor]     = 8;
    }

    Effect_Instance effect_instance = 
    {
        UNLIMITED_DURATION, 
        {}, 
        Offset(entity, game_state)
    };

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &effect_instance.effect_offset, game_state))
    {
        Effect effect = {};
        effect.name_offset = Offset(STR("Strength of Earth"), game_state);
        effect.on_turn_start_fn_offset = Offset(Strength_Of_Earth_Small_On_Turn_Start, game_state);
        effect.type = Effect_Type::physical;
        Add_Dice(&effect, 1, 2);
        effect_instance.effect_offset = Insert_Effect(effect, key, game_state);
    }

    Apply_Effect_Result apply = Apply_Effect(entity, effect_instance, game_state, Forced::yes);
    Assert(apply == Apply_Effect_Result::success);


    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Small_Earth_Golem(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Small earth golem"), game_state);
    entity->description_offset = Offset(STR("A stone construct."), game_state);

    entity->flags = EFlags::actor | EFlags::aggressive;
    entity->faction = Faction::nature;
    entity->weight = 100;

    {
        s16* stats = entity->_stats;
        stats[Stats::vitality]  = 3;
        stats[Stats::might]     = 5;
        stats[Stats::dodge]     = 1;
        stats[Stats::accuracy]  = 4;
        stats[Stats::speed]     = 1;
        stats[Stats::arcane]    = 1;
        stats[Stats::immunity]  = 15;
        stats[Stats::armor]     = 8;
    }

    Effect_Instance effect_instance = 
    {
        UNLIMITED_DURATION, 
        {}, 
        Offset(entity, game_state)
    };

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &effect_instance.effect_offset, game_state))
    {
        Effect effect = {};
        effect.name_offset = Offset(STR("Strength of Earth"), game_state);
        effect.on_turn_start_fn_offset = Offset(Strength_Of_Earth_Tiny_On_Turn_Start, game_state);
        effect.type = Effect_Type::physical;
        Add_Dice(&effect, 1, 2);
        effect_instance.effect_offset = Insert_Effect(effect, key, game_state);
    }

    Apply_Effect_Result apply = Apply_Effect(entity, effect_instance, game_state, Forced::yes);
    Assert(apply == Apply_Effect_Result::success);


    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Tiny_Earth_Golem(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Tiny earth golem"), game_state);
    entity->description_offset = Offset(STR("A cute stone construct."), game_state);

    entity->flags = EFlags::actor | EFlags::aggressive;
    entity->faction = Faction::nature;
    entity->weight = 10;

    {
        s16* stats = entity->_stats;
        stats[Stats::vitality]  = 1;
        stats[Stats::might]     = 2;
        stats[Stats::dodge]     = 1;
        stats[Stats::accuracy]  = 4;
        stats[Stats::speed]     = 1;
        stats[Stats::arcane]    = 1;
        stats[Stats::immunity]  = 15;
        stats[Stats::armor]     = 8;
    }

    Effect_Instance effect_instance = 
    {
        UNLIMITED_DURATION, 
        {}, 
        Offset(entity, game_state)
    };

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &effect_instance.effect_offset, game_state))
    {
        Effect effect = {};
        effect.name_offset = Offset(STR("Frailty of Earth"), game_state);
        effect.on_turn_start_fn_offset = Offset(Dissapate_After_Two_On_Turn_Start, game_state);
        effect.type = Effect_Type::physical;
        Add_Dice(&effect, 1, 2);
        effect_instance.effect_offset = Insert_Effect(effect, key, game_state);
    }

    Apply_Effect_Result apply = Apply_Effect(entity, effect_instance, game_state, Forced::yes);
    Assert(apply == Apply_Effect_Result::success);


    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Giant_Rat(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Giant rat"), game_state);
    entity->description_offset = Offset(STR("An oversized feral rodent. It must have devoured many a traveler to become so large."), game_state);

    entity->flags = EFlags::actor | EFlags::aggressive;
    entity->faction = Faction::nature;
    entity->weight = 60;
    
    {
        s16* stats = entity->_stats;
        stats[Stats::vitality]  = 3;
        stats[Stats::might]     = 6;
        stats[Stats::dodge]     = 4;
        stats[Stats::accuracy]  = 3;
        stats[Stats::speed]     = 8;
        stats[Stats::arcane]    = 5;
        stats[Stats::immunity]  = 5;
        stats[Stats::armor]     = 3;
    }

    Finalize_Entity(entity, room, game_state);
    
    Effect_Hash_Key key = EFFECT_KEY;
    
    Effect_Offset effect_offset;
    if(!Retrive_Effect(key, &effect_offset, game_state))
    {
        Effect effect = {};
        effect.name_offset = Offset(STR("Fangs"), game_state);
        effect.critical_success_range = + 1;
        effect.critical_failure_range = + 2;
        Add_Dice(&effect, 1, 5);
        effect_offset = Insert_Effect(effect, key, game_state);
    }

    Effect_Instance effect_instance = 
    {
        UNLIMITED_DURATION, 
        effect_offset, 
        Offset(entity, game_state)
    };
    
    Apply_Effect_Result apply = Apply_Effect(entity, effect_instance, game_state);
    Assert(apply == Apply_Effect_Result::success);


    Loot_Table table = Merge_Loot_Tables
    (
        Basic_Armors_Loot_Table(game_state), 
        Basic_Trinkets_Loot_Table(game_state), 
        Basic_Consumables_Loot_Table(game_state), 
        &game_state->scratch_buffer
    );

    Rules_Builder rules = Rules_Builder().Rarity(Comparison::maximum, Rarity::uncommon);
    Generate_From_Loot_Table(entity, table, Per_Count_Rolled_Random(3, 9, game_state), rules.Finish(), game_state);

    return entity;
}


SIG Entity* Create_Blight_Rat(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Blight rat"), game_state);
    entity->description_offset = Offset(STR("An oversized feral rodent. Its skin is full of pulsating pus-filled boils."), game_state);

    entity->flags = EFlags::actor | EFlags::aggressive;
    entity->faction = Faction::nature;
    entity->weight = 80;
    
    {
        s16* stats = entity->_stats;
        stats[Stats::vitality]  = 7;
        stats[Stats::might]     = 4;
        stats[Stats::dodge]     = 3;
        stats[Stats::accuracy]  = 6;
        stats[Stats::speed]     = 6;
        stats[Stats::arcane]    = 8;
        stats[Stats::immunity]  = 15;
        stats[Stats::armor]     = 1;
    }

    Finalize_Entity(entity, room, game_state);
    
    u32 weapon = Roll(3, game_state);

    Effect_Instance effect_instance = 
    {
        UNLIMITED_DURATION, 
        {}, 
        Offset(entity, game_state)
    };


    struct local
    {
        static void On_Hit_Festering_Rash(Effect_Instance* instance, Entity* attacker, Entity* defender, Attack_Record* ar, Game_State* game_state)
        {
            if(instance)
            {
                Attempt_Infection(attacker, defender, Effect_Name(instance, game_state), Get_Festering_Rash(3, attacker, game_state), game_state);
            }
        }

        static void On_Hit_Weakening_Blight(Effect_Instance* instance, Entity* attacker, Entity* defender, Attack_Record* ar, Game_State* game_state)
        {
            if(instance)
            {
                Attempt_Infection(attacker, defender, Effect_Name(instance, game_state), Get_Weakening_Blight(3, attacker, game_state), game_state);
            }
        }

        static void On_Hit_Devouring_Plague(Effect_Instance* instance, Entity* attacker, Entity* defender, Attack_Record* ar, Game_State* game_state)
        {
            if(instance)
            {
                Attempt_Infection(attacker, defender, Effect_Name(instance, game_state), Get_Devouring_Plague(2, attacker, game_state), game_state);
            }
        }

        static Effect Blight_Fangs(PROTOTYPE_EFFINST_ENT_ENT_AR_GS* on_hit_fn, Game_State* game_state)
        {
            Effect effect = {};
            effect.name_offset = Offset(STR("Blight fangs"), game_state);
            effect.on_hit_fn_offset = Offset(on_hit_fn, game_state);
            Add_Dice(&effect, 1, 6);
            return effect;
        }
    };

    switch(weapon)
    {
        case 1:
        {
            Effect_Hash_Key key = EFFECT_KEY;
            if(!Retrive_Effect(key, &effect_instance.effect_offset, game_state))
            {
                effect_instance.effect_offset = Insert_Effect(local::Blight_Fangs(local::On_Hit_Festering_Rash, game_state), key, game_state);
            }
        }break;
        
        case 2:
        {
            Effect_Hash_Key key = EFFECT_KEY;
            if(!Retrive_Effect(key, &effect_instance.effect_offset, game_state))
            {
                effect_instance.effect_offset = Insert_Effect(local::Blight_Fangs(local::On_Hit_Weakening_Blight, game_state), key, game_state);
            }
        }break;

        case 3:
        {
            Effect_Hash_Key key = EFFECT_KEY;
            if(!Retrive_Effect(key, &effect_instance.effect_offset, game_state))
            {
                effect_instance.effect_offset = Insert_Effect(local::Blight_Fangs(local::On_Hit_Devouring_Plague, game_state), key, game_state);
            }

        }break;

        default:{ Terminate("Invalid code path!"); }
    }
    
    Apply_Effect_Result apply = Apply_Effect(entity, effect_instance, game_state);
    Assert(apply == Apply_Effect_Result::success);

    Loot_Table table = Merge_Loot_Tables
    (
        Basic_Armors_Loot_Table(game_state), 
        Basic_Trinkets_Loot_Table(game_state), 
        Basic_Consumables_Loot_Table(game_state), 
        &game_state->scratch_buffer
    );

    Rules_Builder rules = Rules_Builder().Rarity(Comparison::maximum, Rarity::rare);
    Generate_From_Loot_Table(entity, table, Per_Count_Rolled_Random(3, 2, game_state), rules.Finish(), game_state);

    return entity;
}


SIG Entity* Create_Enlarged_Ant(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Enlarged ant"), game_state);
    entity->description_offset = Offset(STR("It's snapping its pinchers at you."), game_state);

    entity->flags = EFlags::actor | EFlags::aggressive;
    entity->faction = Faction::nature;
    entity->weight = 10;
    
    {
        s16* stats = entity->_stats;
        stats[Stats::vitality]  = 1;
        stats[Stats::might]     = 3;
        stats[Stats::dodge]     = 2;
        stats[Stats::accuracy]  = 2;
        stats[Stats::speed]     = 5;
        stats[Stats::arcane]    = 1;
        stats[Stats::immunity]  = 1;
        stats[Stats::armor]     = 1;
    }

    Finalize_Entity(entity, room, game_state);
    
    Effect_Hash_Key key = EFFECT_KEY;
    
    Effect_Offset effect_offset;
    if(!Retrive_Effect(key, &effect_offset, game_state))
    {
        Effect effect = {};
        effect.name_offset = Offset(STR("Pinchers"), game_state);
        Add_Dice(&effect, 2, 4);
        effect_offset = Insert_Effect(effect, key, game_state);
    }

    Effect_Instance effect_instance = 
    {
        UNLIMITED_DURATION, 
        effect_offset, 
        Offset(entity, game_state)
    };
    
    Apply_Effect_Result apply = Apply_Effect(entity, effect_instance, game_state);
    Assert(apply == Apply_Effect_Result::success);

    return entity;
}


SIG Entity* Create_Enlarged_Ant_Queen(Entity* room, Game_State* game_state)
{
    struct local
    {
        static void On_Turn_Start(Effect_Instance* instance, Entity* target, Game_State* game_state)
        {
            if(instance)
            {
                if(Entity* space = Pointer(target->residence, game_state))
                {
                    String effect_name = Effect_Name(instance, game_state);
                    for(u32 i = 0; i < 5; ++i)
                    {
                        if(Roll(Square(i + 2), game_state) == 1)
                        {
                            Entity* ant = Create_Enlarged_Ant(space, game_state);
                            ant->bonus_exp_reward -= (s16)Exp_Reward(ant);
                            
                            String message = Format_Message(game_state, "%s births an %s.", effect_name.ptr, Name(ant, game_state).ptr);
                            Push_Message(message, game_state);
                        }
                    }
                }
            }
        }
    };


    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Enlarged ant queen"), game_state);
    entity->description_offset = Offset(STR("Its abdomen is so large that it can not move."), game_state);

    entity->flags = EFlags::actor;
    entity->faction = Faction::nature;
    entity->weight = 300;
    entity->bonus_exp_reward = + 5;
    
    {
        s16* stats = entity->_stats;
        stats[Stats::vitality]  = 12;
        stats[Stats::might]     = 1;
        stats[Stats::dodge]     = 1;
        stats[Stats::accuracy]  = 1;
        stats[Stats::speed]     = 1;
        stats[Stats::arcane]    = 1;
        stats[Stats::immunity]  = 1;
        stats[Stats::armor]     = 8;
    }

    Finalize_Entity(entity, room, game_state);
    
    Effect_Hash_Key key = EFFECT_KEY;
    
    Effect_Offset effect_offset;
    if(!Retrive_Effect(key, &effect_offset, game_state))
    {
        Effect effect = {};
        effect.on_turn_start_fn_offset = Offset(local::On_Turn_Start, game_state);
        effect_offset = Insert_Effect(effect, key, game_state);
    }

    Effect_Instance effect_instance = 
    {
        UNLIMITED_DURATION, 
        effect_offset, 
        Offset(entity, game_state)
    };
    
    Apply_Effect_Result apply = Apply_Effect(entity, effect_instance, game_state);
    Assert(apply == Apply_Effect_Result::success);

    Loot_Table table = Basic_Merged_Loot_Table(game_state);

    Generate_From_Loot_Table(entity, table, 1, Rules_Builder().Rarity(Comparison::minimum, Rarity::rare).Finish(), game_state);
    Generate_From_Loot_Table(entity, table, Roll(3, game_state) - 1, Rules_Builder().Rarity(Comparison::maximum, Rarity::uncommon).Finish(), game_state);

    return entity;
}


SIG Entity* Create_Bear_Cub(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Bear cub"), game_state);
    entity->description_offset = Offset(STR("Small for a bear, but still quite formitable. Its mother is propably near by."), game_state);

    entity->flags = EFlags::actor | EFlags::aggressive;
    entity->faction = Faction::nature;
    entity->weight = 80;
    
    {
        s16* stats = entity->_stats;
        stats[Stats::vitality]  = 8;
        stats[Stats::might]     = 8;
        stats[Stats::dodge]     = 4;
        stats[Stats::accuracy]  = 3;
        stats[Stats::speed]     = 8;
        stats[Stats::arcane]    = 5;
        stats[Stats::immunity]  = 5;
        stats[Stats::armor]     = 2;
    }
    
    Finalize_Entity(entity, room, game_state);
    
    Effect_Hash_Key key = EFFECT_KEY;
    
    Effect_Offset effect_offset;
    if(!Retrive_Effect(key, &effect_offset, game_state))
    {
        Effect effect = {};
        effect.name_offset = Offset(STR("Claws"), game_state);
        Add_Dice(&effect, 1, 6);
        effect_offset = Insert_Effect(effect, key, game_state);
    }

    Effect_Instance effect_instance = 
    {
        UNLIMITED_DURATION, 
        effect_offset, 
        Offset(entity, game_state)
    };
    
    Apply_Effect_Result apply = Apply_Effect(entity, effect_instance, game_state);
    Assert(apply == Apply_Effect_Result::success);


    Loot_Table table = Merge_Loot_Tables
    (
        Basic_Armors_Loot_Table(game_state), 
        Basic_Trinkets_Loot_Table(game_state), 
        Basic_Consumables_Loot_Table(game_state), 
        &game_state->scratch_buffer
    );

    Pick_From_Table_Rules rules = Rules_Builder()
    .Rarity(Comparison::maximum, Rarity::uncommon)
    .Finish();
    
    Generate_From_Loot_Table(entity, table, Per_Count_Rolled_Random(5, 30, game_state), rules, game_state);

    return entity;
}


SIG Entity* Create_Cave_Bear(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Cave Bear"), game_state);
    entity->description_offset = Offset(STR("A hulking bear!"), game_state);

    entity->flags = EFlags::actor | EFlags::aggressive;
    entity->faction = Faction::nature;
    entity->weight = 200;
    
    {
        s16* stats = entity->_stats;
        stats[Stats::vitality]  = 12;
        stats[Stats::might]     = 14;
        stats[Stats::dodge]     = 5;
        stats[Stats::accuracy]  = 9;
        stats[Stats::speed]     = 13;
        stats[Stats::arcane]    = 5;
        stats[Stats::immunity]  = 10;
        stats[Stats::armor]     = 7;
    }


    Finalize_Entity(entity, room, game_state);
    
    Effect_Hash_Key key = EFFECT_KEY;
    
    Effect_Offset effect_offset;
    if(!Retrive_Effect(key, &effect_offset, game_state))
    {
        Effect effect = {};
        effect.name_offset = Offset(STR("Claws"), game_state);
        effect.critical_success_range = 4;
        Add_Dice(&effect, 2, 8);
        effect_offset = Insert_Effect(effect, key, game_state);
    }

    Effect_Instance effect_instance = 
    {
        UNLIMITED_DURATION, 
        effect_offset, 
        Offset(entity, game_state)
    };
    
    Apply_Effect_Result apply = Apply_Effect(entity, effect_instance, game_state);
    Assert(apply == Apply_Effect_Result::success);


    Loot_Table table = Merge_Loot_Tables
    (
        Basic_Armors_Loot_Table(game_state), 
        Basic_Trinkets_Loot_Table(game_state), 
        Basic_Consumables_Loot_Table(game_state), 
        &game_state->scratch_buffer
    );

    Pick_From_Table_Rules rules = Rules_Builder()
    .Rarity(Comparison::maximum, Rarity::epic)
    .Finish();
    
    Generate_From_Loot_Table(entity, table, 2 + Per_Count_Rolled_Random(4, 5, game_state), rules, game_state);

    return entity;
}


SIG Entity* Create_Mutant_Hedgehog(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Mutant hedgehog"), game_state);

    char description[] = 
    "Curled up in a ball of spikes, it only opens to strike at its pray.\n"
    "Stuck in it's spikes you can see something that glimmers.\n"
    "Likely from one of it's previous assailants.";

    entity->description_offset = Offset(STR(description), game_state);

    entity->flags = EFlags::actor | EFlags::aggressive;
    entity->faction = Faction::nature;
    entity->weight = 60;
    
    {
        s16* stats = entity->_stats;
        stats[Stats::vitality]  = 6;
        stats[Stats::might]     = 2;
        stats[Stats::dodge]     = 1;
        stats[Stats::accuracy]  = 2;
        stats[Stats::speed]     = 3;
        stats[Stats::arcane]    = 5;
        stats[Stats::immunity]  = 1;
        stats[Stats::armor]     = 7;
    }

    Finalize_Entity(entity, room, game_state);
    
    {
        Effect_Instance effect_instance = 
        {
            UNLIMITED_DURATION, 
            {}, 
            Offset(entity, game_state)
        };

        Effect_Hash_Key key = EFFECT_KEY;
        if(!Retrive_Effect(key, &effect_instance.effect_offset, game_state))
        {
            Effect effect = {};
            effect.name_offset = Offset(STR("Spike shell"), game_state);
            effect.thorns_damage = 6;
            effect_instance.effect_offset = Insert_Effect(effect, key, game_state);
        }

        Apply_Effect_Result apply = Apply_Effect(entity, effect_instance, game_state);
        Assert(apply == Apply_Effect_Result::success);
    }

    {
        Effect_Instance effect_instance = 
        {
            UNLIMITED_DURATION, 
            {}, 
            Offset(entity, game_state)
        };

        Effect_Hash_Key key = EFFECT_KEY;
        if(!Retrive_Effect(key, &effect_instance.effect_offset, game_state))
        {
            Effect effect = {};
            effect.name_offset = Offset(STR("Claws"), game_state);
            Add_Dice(&effect, 1, 4);
            effect_instance.effect_offset = Insert_Effect(effect, key, game_state);
        }
        
        Apply_Effect_Result apply = Apply_Effect(entity, effect_instance, game_state);
        Assert(apply == Apply_Effect_Result::success);
    }

    Generate_From_Loot_Table
    (
        entity, 
        Basic_Merged_Loot_Table(game_state), 
        1 + Per_Count_Rolled_Random(3, 5, game_state), 
        Rules_Builder().Rarity(Comparison::maximum, Rarity::rare).Finish(), 
        game_state
    );

    return entity;
}


SIG Entity* Create_Clear_Ambush_Table_Dummy_Entity(Entity* room, Game_State* game_state)
{
    // NOTE: This is a strange hack to clear the ambush table, it can be used as an ambush entity create function!
    // Doing so
    Reset_Ambush_Table(game_state);
    return 0;
}


SIG Entity* Create_Mimic(Entity* room, Game_State* game_state)
{
    struct local
    {
        static void Reveal_Mimic(Entity* mimic, Game_State* game_state)
        {
            mimic->flags = EFlags::actor | EFlags::aggressive;
            mimic->name_offset = Offset(STR("Mimic"), game_state);
            
            char description[] = 
            "It now has thousands of tiny spider like legs and under the cover was revealed a gaping maw of teeth and tongues.";
            mimic->description_offset = Offset(STR(description), game_state);
            
            Assign_Dublicate_Name_Identifier(mimic, Pointer(mimic->residence, game_state), game_state);
        }

        static void On_Damage_Taken(Effect_Instance* instance, Entity_Offset attaker_offset, Entity* defender, Deal_Damage_Result* ddr, Game_State* game_state)
        {
            if(instance)
            {
                String pre_name = Name(defender, game_state);
                Reveal_Mimic(defender, game_state);
                
                String post_name = Name(defender, game_state);
                String message = Format_Message(game_state, "Upon taking damage, the %s reveals itself to be a %s!", pre_name.ptr, post_name.ptr);
                Push_Message(message, game_state);
            }
            else
            {
                // ...
            }
        }

        static void On_Loot(Effect_Instance* instance, Entity* looted, Entity* looter, Game_State* game_state)
        {
            if(instance)
            {
                String pre_name = Name(looted, game_state);
                Reveal_Mimic(looted, game_state);
                
                String post_name = Name(looted, game_state);
                String message = Format_Message(game_state, "Upon being looted, the %s reveals itself to be a %s!", pre_name.ptr, post_name.ptr);
                Push_Message(message, game_state);
            }
            else
            {
                // ...
            }
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Chest"), game_state);
    entity->description_offset = Offset(STR("Maybe you should look inside?"), game_state);
    entity->weight = 201;
    entity->faction = Faction::mimic;

    {
        s16* stats = entity->_stats;
        stats[Stats::vitality]  = 15;
        stats[Stats::might]     = 10;
        stats[Stats::dodge]     = 0;
        stats[Stats::accuracy]  = 8;
        stats[Stats::speed]     = 0;
        stats[Stats::arcane]    = 5;
        stats[Stats::immunity]  = 5;
        stats[Stats::armor]     = 12;
    }

    Effect_Instance mimic_effect = {};
    mimic_effect.duration = UNLIMITED_DURATION;
    mimic_effect.source = Offset(entity, game_state);

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &mimic_effect.effect_offset, game_state))
    {
        Effect effect = {};
        effect.name_offset = Offset(STR("Maw"), game_state);
        Add_Dice(&effect, 2, 8);
        effect.on_damage_taken_fn_offset = Offset(local::On_Damage_Taken, game_state);
        effect.on_loot_attempt_fn_offset = Offset(local::On_Loot, game_state);
        mimic_effect.effect_offset = Insert_Effect(effect, key, game_state);
    }

    Apply_Effect_Result apply = Apply_Effect(entity, mimic_effect, game_state, Forced::yes);
    Assert(apply == Apply_Effect_Result::success);

    Loot_Table table = Basic_Merged_Loot_Table(game_state);
    Generate_From_Loot_Table(entity, table, Roll(2, game_state), Rules_Builder().Rarity(Comparison::equal, Rarity::common).Finish(), game_state);
    Generate_From_Loot_Table(entity, table, 1, Rules_Builder().Rarity(Comparison::minimum, Rarity::rare).Finish(), game_state);
    Generate_From_Loot_Table(entity, table, Roll(4, game_state) - 1, Rules_Builder().Rarity(Comparison::maximum, Rarity::rare).Finish(), game_state);

    Finalize_Entity(entity, room, game_state);

    return entity;
}


SIG Entity* Create_Chest(Entity* room, Game_State* game_state)
{
    Entity* entity;
    if(Roll(100, game_state) > 1)
    {
        entity = Request_Entity(game_state);

        entity->name_offset = Offset(STR("Chest"), game_state);
        entity->description_offset = Offset(STR("Maybe you should look inside?"), game_state);
        entity->flags |= EFlags::container;
        entity->weight = 200;
        
        s16* stats = entity->_stats;
        stats[Stats::might]     = 0;
        stats[Stats::dodge]     = 0;
        stats[Stats::speed]     = 0;
        stats[Stats::accuracy]  = 0;
        stats[Stats::vitality]  = 10;
        stats[Stats::armor]     = 5;
        
        Finalize_Entity(entity, room, game_state);

        Loot_Table table = Basic_Merged_Loot_Table(game_state); // NOTE: a copy so you can fuck with it.
        for(Loot_Table_Entry* entry = table.array; entry < table.array + table.count; ++entry)
        {
            if(entry->rarity > Rarity::common)
            {
                entry->change *= 3;
            }
        }

        Generate_From_Loot_Table
        (
            entity, 
            Basic_Merged_Loot_Table(game_state), 
            1 + Per_Count_Rolled_Random(5, 4, game_state), 
            {}, 
            game_state
        );
    }
    else
    {
        entity = Create_Mimic(room, game_state);
    }

    return entity;
}


SIG Entity* Create_Weapon_Rack(Entity* room, Game_State* game_state)
{
    Entity* entity;
    
    entity = Request_Entity(game_state);
    entity->name_offset = Offset(STR("Weapon rack"), game_state);
    entity->description_offset = Offset(STR("Used for efficient storage of weapons."), game_state);
    entity->flags |= EFlags::container;
    entity->weight = 100;
    
    s16* stats = entity->_stats;
    stats[Stats::might]     = 0;
    stats[Stats::dodge]     = 0;
    stats[Stats::speed]     = 0;
    stats[Stats::accuracy]  = 0;
    stats[Stats::vitality]  = 10;
    stats[Stats::armor]     = 5;
    
    Finalize_Entity(entity, room, game_state);

    Generate_From_Loot_Table
    (
        entity, 
        Basic_Weapons_Loot_Table(game_state), 
        (Roll(3, game_state) > 1) + Per_Count_Rolled_Random(5, 5, game_state), 
        {}, 
        game_state
    );

    return entity;
}


SIG Entity* Create_Armor_Rack(Entity* room, Game_State* game_state)
{
    Entity* entity;
    
    entity = Request_Entity(game_state);
    entity->name_offset = Offset(STR("Armor rack"), game_state);
    entity->description_offset = Offset(STR("Used for efficient storage of armors."), game_state);
    entity->flags |= EFlags::container;
    entity->weight = 100;
    
    s16* stats = entity->_stats;
    stats[Stats::might]     = 0;
    stats[Stats::dodge]     = 0;
    stats[Stats::speed]     = 0;
    stats[Stats::accuracy]  = 0;
    stats[Stats::vitality]  = 10;
    stats[Stats::armor]     = 5;
    
    Finalize_Entity(entity, room, game_state);

    Generate_From_Loot_Table
    (
        entity, 
        Basic_Armors_Loot_Table(game_state), 
        (Roll(3, game_state) > 1) + Per_Count_Rolled_Random(5, 5, game_state), 
        {}, 
        game_state
    );

    return entity;
}


SIG Entity* Create_Bookshelf(Entity* room, Game_State* game_state)
{
    Entity* entity;
    
    entity = Request_Entity(game_state);
    entity->name_offset = Offset(STR("Book shelf"), game_state);
    entity->description_offset = Offset(STR("Used for efficient storage of books."), game_state);
    entity->flags |= EFlags::container;
    entity->weight = 130;
    
    s16* stats = entity->_stats;
    stats[Stats::might]     = 0;
    stats[Stats::dodge]     = 0;
    stats[Stats::speed]     = 0;
    stats[Stats::accuracy]  = 0;
    stats[Stats::vitality]  = 10;
    stats[Stats::armor]     = 5;
    
    Finalize_Entity(entity, room, game_state);

    Generate_From_Loot_Table
    (
        entity, 
        Skill_Books_Loot_Table(game_state), 
        1, 
        {}, 
        game_state
    );

    return entity;
}


SIG Entity* Create_Supply_Crate(Entity* room, Game_State* game_state)
{
    Entity* entity;
    
    entity = Request_Entity(game_state);
    entity->name_offset = Offset(STR("Supply crate"), game_state);
    entity->description_offset = Offset(STR("Used for efficient storage of foods."), game_state);
    entity->flags |= EFlags::actor | EFlags::hidden_iniative | EFlags::burst_container | EFlags::container;
    entity->weight = 10;
    entity->burst_change = 0.2f;
    entity->burst_message_offset = Offset(STR("Opens"), game_state);

    s16* stats = entity->_stats;
    stats[Stats::might]     = 0;
    stats[Stats::dodge]     = 0;
    stats[Stats::speed]     = 0;
    stats[Stats::accuracy]  = 0;
    stats[Stats::vitality]  = 10;
    stats[Stats::armor]     = 5;
    
    Finalize_Entity(entity, room, game_state);
    entity->bonus_exp_reward = (s16)Exp_Reward(entity) * -1;

    Loot_Table_Entry entries[] = 
    {
        {Create_Scorpion},
        {Create_Snake},
    };
    Loot_Table fuck_you_creature = {entries, Array_Length(entries)};
    Fill_Loot_Table_Changes_And_Item_Rarity(&fuck_you_creature, game_state);

    Loot_Table table = Merge_Loot_Tables(Basic_Foods_Loot_Table(game_state), fuck_you_creature, &game_state->scratch_buffer);

    Generate_From_Loot_Table
    (
        entity, 
        table,
        Per_Count_Rolled_Random(4, 2, game_state), 
        {}, 
        game_state
    );

    return entity;
}


SIG Entity* Create_Alchemists_Pouch(Entity* room, Game_State* game_state)
{
    Entity* entity;
    
    entity = Request_Entity(game_state);
    entity->name_offset = Offset(STR("Alchemists Pouch"), game_state);
    entity->description_offset = Offset(STR("Used for efficient storage of consumables."), game_state);
    entity->flags |= EFlags::container;
    entity->weight = 3;
    
    s16* stats = entity->_stats;
    stats[Stats::might]     = 0;
    stats[Stats::dodge]     = 0;
    stats[Stats::speed]     = 0;
    stats[Stats::accuracy]  = 0;
    stats[Stats::vitality]  = 1;
    stats[Stats::armor]     = 5;
    
    Finalize_Entity(entity, room, game_state);

    Generate_From_Loot_Table
    (
        entity, 
        Basic_Consumables_Loot_Table(game_state), 
        (Roll(3, game_state) > 1) + Per_Count_Rolled_Random(3, 4, game_state), 
        {}, 
        game_state
    );

    return entity;
}



SIG Entity* Create_Rat_Mound(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);
  
    entity->name_offset = Offset(STR("Rat mound"), game_state);
    entity->description_offset = Offset(STR("A pile if soil, gravel and rat feces. There could be treasure inside... Or even rats living in it!"), game_state);
    
    entity->flags = 
        EFlags::actor                       | 
        EFlags::hidden_iniative             | 
        EFlags::container                   | 
        EFlags::item                        |
        EFlags::destroy_inventory_on_death  |
        EFlags::burst_container;
    

    entity->burst_message_offset = Offset(STR("bursts open releasing it's contents"), game_state);
    entity->burst_change = 0.3f;
    entity->weight = 1000;
    
    entity->_stats[Stats::vitality] = 30;
    entity->_stats[Stats::armor] = 10;

    Loot_Table table = Merge_Loot_Tables
    (
        Basic_Armors_Loot_Table(game_state), 
        Basic_Trinkets_Loot_Table(game_state), 
        Basic_Weapons_Loot_Table(game_state),
        Basic_Consumables_Loot_Table(game_state), 
        &game_state->scratch_buffer
    );

    Pick_From_Table_Rules rules = Rules_Builder().Rarity(Comparison::maximum, Rarity::epic).Finish();

    f32 total_change = 0;
    for(u64 i = 0; i < table.count; ++i)
    {
        Loot_Table_Entry entry = table.array[i];
        if(Is_Compliant(entry, rules))
        {
            total_change += entry.change;
        }
    }

    Loot_Table_Entry rats[] =
    {
        {Create_Random_Rat, total_change * 0.6f},
    };

    table = Merge_Loot_Tables_Internal(table, {rats, Array_Length(rats), true}, &game_state->scratch_buffer);

    u64 count = Roll(2, game_state) + Per_Count_Rolled_Square_Weighted_Random(10, game_state) - 1;
    
    Generate_From_Loot_Table(entity, table, count, rules, game_state);

    Finalize_Entity(entity, room, game_state);
    entity->bonus_exp_reward = (s16)Exp_Reward(entity) * -1;
    return entity;
}


SIG Entity* Create_Spider_Egg(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);
  
    entity->name_offset = Offset(STR("Spider Egg"), game_state);
    entity->description_offset = Offset(STR("A large egg. It looks be about ready to hacth!"), game_state);
    
    entity->flags = 
        EFlags::actor                       | 
        EFlags::hidden_iniative             | 
        EFlags::container                   | 
        EFlags::item                        |
        EFlags::destroy_inventory_on_death  |
        EFlags::burst_container;
    
    entity->burst_message_offset = Offset(STR("hatches open releasing it's contents"), game_state);
    entity->burst_change = 0.2f;
    entity->weight = 50;
    
    entity->_stats[Stats::vitality] = 10;
    entity->_stats[Stats::armor] = 0;

    u64 cmax = 5;
    Entity*(*create_fn)(Entity*, Game_State*) = 0;
    switch(Roll(3, game_state))
    {
        case 1:
        {
            create_fn = Create_Toxic_Lurker;
        }break;

        case 2:
        {
            create_fn = Create_Hunter_Arachnid;
        }break;

        case 3:
        {
            create_fn = Create_Spiderling;
            cmax = 20;
        }break;
    }

    u64 count = Per_Count_Rolled_Square_Weighted_Random(cmax, game_state);
    LOOP(count) create_fn(entity, game_state);

    Finalize_Entity(entity, room, game_state);
    entity->bonus_exp_reward = (s16)Exp_Reward(entity) * -1;
    return entity;
}


SIG Entity* Create_Snake(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    struct local
    {
        static void On_Hit(Effect_Instance* instance, Entity* attacker, Entity* defender, Attack_Record* ar, Game_State* game_state)
        {
            if(attacker)
            {
                Attempt_Infection(attacker, defender, Effect_Name(instance, game_state), Get_Poison(4, attacker, game_state), game_state);
            }
        }
    };
    
    entity->name_offset = Offset(STR("Snake"), game_state);
    entity->description_offset = Offset(STR("A slithering venomous creature."), game_state);
    entity->rarity = Rarity::rare;

    entity->flags = EFlags::actor | EFlags::aggressive;
    entity->faction = Faction::nature;
    entity->weight = 5;  
    entity->bonus_exp_reward = - 3;
    
    {
        s16* stats = entity->_stats;
        stats[Stats::vitality]  = 1;
        stats[Stats::might]     = 1;
        stats[Stats::dodge]     = 9;
        stats[Stats::accuracy]  = 5;
        stats[Stats::speed]     = 14;
        stats[Stats::arcane]    = 13;
        stats[Stats::immunity]  = 5;
        stats[Stats::armor]     = 1;
    }

    Effect_Instance effect_instance = 
    {
        UNLIMITED_DURATION, 
        {}, 
        Offset(entity, game_state)
    };

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &effect_instance.effect_offset, game_state))
    {
        Effect effect = {};
        effect.name_offset = Offset(STR("Venomous Bite"), game_state);
        effect.on_hit_fn_offset = Offset(local::On_Hit, game_state);
        effect_instance.effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Apply_Effect_Result apply = Apply_Effect(entity, effect_instance, game_state, Forced::yes);
    Assert(apply == Apply_Effect_Result::success);

    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Scorpion(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    struct local
    {
        static void On_Hit(Effect_Instance* instance, Entity* attacker, Entity* defender, Attack_Record* ar, Game_State* game_state)
        {
            if(attacker)
            {
                Attempt_Infection(attacker, defender, Effect_Name(instance, game_state), Get_Neuro_Toxin(4, attacker, game_state), game_state);
            }
        }
    };
    
    entity->name_offset = Offset(STR("Scorpion"), game_state);
    entity->description_offset = Offset(STR("An armored toxic creature."), game_state);
    entity->rarity = Rarity::epic;

    entity->flags = EFlags::actor | EFlags::aggressive;
    entity->faction = Faction::nature;
    entity->weight = 5;
    entity->bonus_exp_reward = - 5;
    
    {
        s16* stats = entity->_stats;
        stats[Stats::vitality]  = 1;
        stats[Stats::might]     = 1;
        stats[Stats::dodge]     = 1;
        stats[Stats::accuracy]  = 5;
        stats[Stats::speed]     = 14;
        stats[Stats::arcane]    = 13;
        stats[Stats::immunity]  = 5;
        stats[Stats::armor]     = 12;
    }

    Effect_Instance effect_instance = 
    {
        UNLIMITED_DURATION, 
        {}, 
        Offset(entity, game_state)
    };

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &effect_instance.effect_offset, game_state))
    {
        Effect effect = {};
        effect.name_offset = Offset(STR("Toxic Sting"), game_state);
        effect.on_hit_fn_offset = Offset(local::On_Hit, game_state);
        effect_instance.effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Apply_Effect_Result apply = Apply_Effect(entity, effect_instance, game_state, Forced::yes);
    Assert(apply == Apply_Effect_Result::success);

    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Spiderling(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);
    
    entity->name_offset = Offset(STR("Spiderling"), game_state);
    entity->description_offset = Offset(STR("Small for a giant spider, but still.. quite sizable compared to a regular one."), game_state);

    entity->flags = EFlags::actor | EFlags::aggressive;
    entity->faction = Faction::aracnid;
    entity->weight = 40;
    
    {
        s16* stats = entity->_stats;
        stats[Stats::vitality]  = 4;
        stats[Stats::might]     = 7;
        stats[Stats::dodge]     = 5;
        stats[Stats::accuracy]  = 5;
        stats[Stats::speed]     = 17;
        stats[Stats::arcane]    = 10;
        stats[Stats::immunity]  = 5;
        stats[Stats::armor]     = 5;
    }

    Effect_Instance effect_instance = 
    {
        UNLIMITED_DURATION, 
        {}, 
        Offset(entity, game_state)
    };

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &effect_instance.effect_offset, game_state))
    {
        Effect effect = {};
        effect.name_offset = Offset(STR("Chelicera"), game_state);
        effect.pierce = + 1;
        Add_Dice(&effect, 2, 6);
        effect_instance.effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Apply_Effect_Result apply = Apply_Effect(entity, effect_instance, game_state, Forced::yes);
    Assert(apply == Apply_Effect_Result::success);

    {
        Pick_From_Table_Rules rules = Rules_Builder().Rarity(Comparison::maximum, Rarity::uncommon).Finish();
        u64 count = Per_Count_Rolled_Random(1, 5, game_state);
        Generate_From_Loot_Table(entity, Basic_Merged_Loot_Table(game_state), count, rules, game_state);
    }

    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Toxic_Lurker(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    struct local
    {
        static void On_Hit(Effect_Instance* instance, Entity* attacker, Entity* defender, Attack_Record* ar, Game_State* game_state)
        {
            if(instance)
            {
                Attempt_Infection(attacker, defender, Effect_Name(instance, game_state), Get_Poison(4, attacker, game_state), game_state);
            }
        }
    };
    
    entity->name_offset = Offset(STR("Toxic Lurker"), game_state);
    entity->description_offset = Offset(STR("A gigantic spider. It's enourmous chelicera are dripping green toxic goo."), game_state);

    entity->flags = EFlags::actor | EFlags::aggressive;
    entity->faction = Faction::aracnid;
    entity->weight = 120;
    
    {
        s16* stats = entity->_stats;
        stats[Stats::vitality]  = 11;
        stats[Stats::might]     = 7;
        stats[Stats::dodge]     = 8;
        stats[Stats::accuracy]  = 8;
        stats[Stats::speed]     = 12;
        stats[Stats::arcane]    = 10;
        stats[Stats::immunity]  = 6;
        stats[Stats::armor]     = 7;
    }

    Effect_Instance effect_instance = 
    {
        UNLIMITED_DURATION, 
        {}, 
        Offset(entity, game_state)
    };

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &effect_instance.effect_offset, game_state))
    {
        Effect effect = {};
        effect.name_offset = Offset(STR("Chelicera"), game_state);
        effect.on_hit_fn_offset = Offset(local::On_Hit, game_state);
        effect.pierce = + 2;
        Add_Dice(&effect, 1, 6);
        Add_Dice(&effect, 1, 8);
        effect_instance.effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Apply_Effect_Result apply = Apply_Effect(entity, effect_instance, game_state, Forced::yes);
    Assert(apply == Apply_Effect_Result::success);

    {
        Pick_From_Table_Rules rules = Rules_Builder().Rarity(Comparison::maximum, Rarity::rare).Finish();
        u64 count = Per_Count_Rolled_Random(3, 4, game_state);
        Generate_From_Loot_Table(entity, Basic_Merged_Loot_Table(game_state), count, rules, game_state);
    }

    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Hunter_Arachnid(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    struct local
    {
        static void On_Hit(Effect_Instance* instance, Entity* attacker, Entity* defender, Attack_Record* ar, Game_State* game_state)
        {
            if(instance)
            {
                Attempt_Infection(attacker, defender, Effect_Name(instance, game_state), Get_Enwebbed(1, attacker, game_state), game_state);
            }
        }
    };
    
    entity->name_offset = Offset(STR("Hunter Arachnid"), game_state);
    entity->description_offset = Offset(STR("A web spinning spider."), game_state);

    entity->flags = EFlags::actor | EFlags::aggressive;
    entity->faction = Faction::aracnid;
    entity->weight = 120;
    
    {
        s16* stats = entity->_stats;
        stats[Stats::vitality]  = 10;
        stats[Stats::might]     = 9;
        stats[Stats::dodge]     = 7;
        stats[Stats::accuracy]  = 7;
        stats[Stats::speed]     = 15;
        stats[Stats::arcane]    = 10;
        stats[Stats::immunity]  = 6;
        stats[Stats::armor]     = 5;
    }

    Effect_Instance effect_instance = 
    {
        UNLIMITED_DURATION, 
        {}, 
        Offset(entity, game_state)
    };

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &effect_instance.effect_offset, game_state))
    {
        Effect effect = {};
        effect.name_offset = Offset(STR("Chelicera"), game_state);
        effect.on_hit_fn_offset = Offset(local::On_Hit, game_state);
        effect.pierce                   = + 2;
        effect.critical_success_range   = + 4;
        Add_Dice(&effect, 1, 14);
        effect_instance.effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Apply_Effect_Result apply = Apply_Effect(entity, effect_instance, game_state, Forced::yes);
    Assert(apply == Apply_Effect_Result::success);

    {
        Pick_From_Table_Rules rules = Rules_Builder().Rarity(Comparison::maximum, Rarity::rare).Finish();
        u64 count = Per_Count_Rolled_Random(3, 4, game_state);
        Generate_From_Loot_Table(entity, Basic_Merged_Loot_Table(game_state), count, rules, game_state);
    }

    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Bladedance_Spider(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    struct local
    {
        static void On_Hit(Effect_Instance* instance, Entity* attacker, Entity* defender, Attack_Record* ar, Game_State* game_state)
        {
            if(instance)
            {
                Attempt_Infection(attacker, defender, Effect_Name(instance, game_state), Get_Deep_Wound(1, attacker, game_state), game_state);
            }
        }
    };
    
    entity->name_offset = Offset(STR("Blade-dance Spider"), game_state);
    entity->description_offset = Offset(STR("A giant spider, but it's legs have been replaced by steel blades. Creation of the Dark Dwarfs."), game_state);

    entity->flags = EFlags::actor | EFlags::aggressive;
    entity->faction = Faction::aracnid;
    entity->weight = 120;
    
    {
        s16* stats = entity->_stats;
        stats[Stats::vitality]  = 8;
        stats[Stats::might]     = 7;
        stats[Stats::dodge]     = 7;
        stats[Stats::accuracy]  = 7;
        stats[Stats::speed]     = 15;
        stats[Stats::arcane]    = 10;
        stats[Stats::immunity]  = 6;
        stats[Stats::armor]     = 14;
    }

    Effect_Instance effect_instance = 
    {
        UNLIMITED_DURATION, 
        {}, 
        Offset(entity, game_state)
    };

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &effect_instance.effect_offset, game_state))
    {
        Effect effect = {};
        effect.name_offset = Offset(STR("Blade-leg"), game_state);
        effect.on_hit_fn_offset = Offset(local::On_Hit, game_state);
        effect.pierce = + 3;
        Add_Dice(&effect, 3, 4);
        effect_instance.effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Apply_Effect_Result apply = Apply_Effect(entity, effect_instance, game_state, Forced::yes);
    Assert(apply == Apply_Effect_Result::success);

    {
        Pick_From_Table_Rules rules = Rules_Builder().Rarity(Comparison::maximum, Rarity::rare).Finish();
        u64 count = Per_Count_Rolled_Random(3, 4, game_state);
        Generate_From_Loot_Table(entity, Basic_Merged_Loot_Table(game_state), count, rules, game_state);
    }

    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Random_Spider(Entity* room, Game_State* game_state)
{
    Entity* entity = 0;
    s32 r = Roll(3, game_state);
    switch(r)
    {
        case 1:
        {
            entity = Create_Toxic_Lurker(room, game_state);
        }break;
            
        case 2:
        {
            entity = Create_Hunter_Arachnid(room, game_state);
        }break;

        case 3:
        {
            entity = Create_Bladedance_Spider(room, game_state);
        }break;
    }

    return entity;
}


SIG Entity* Create_Random_Rat(Entity* room, Game_State* game_state)
{
    Entity* entity = 0;
    s32 r = Roll(10, game_state);
    if(r <= 7)
    {
        entity = Create_Giant_Rat(room, game_state);
    }
    else
    {
        entity = Create_Blight_Rat(room, game_state);
    }

    return entity;
}


SIG Entity* Create_Boss_Spider(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    struct local
    {
        
    };
    
    entity->name_offset = Offset(STR("Spider Queen"), game_state);
    entity->description_offset = Offset(STR(""), game_state);

    entity->flags = EFlags::actor | EFlags::aggressive;
    entity->faction = Faction::nature;
    entity->weight = 1000;
    
     {
        s16* stats = entity->_stats;
        stats[Stats::vitality]  = 5;
        stats[Stats::might]     = 5;
        stats[Stats::dodge]     = 5;
        stats[Stats::accuracy]  = 5;
        stats[Stats::speed]     = 10;
        stats[Stats::arcane]    = 5;
        stats[Stats::immunity]  = 5;
        stats[Stats::armor]     = 1;
    }
    
    Finalize_Entity(entity, room, game_state);


    Arena_Snapshot snapshot = Snapshot(&game_state->scratch_buffer);
    Loot_Table table = Merge_Loot_Tables
    (
        Basic_Armors_Loot_Table(game_state), 
        Basic_Weapons_Loot_Table(game_state), 
        Basic_Trinkets_Loot_Table(game_state), 
        Basic_Consumables_Loot_Table(game_state), 
        &game_state->scratch_buffer
    );
    
    Generate_From_Loot_Table(entity, table, Roll(3, game_state), {Comparison::equal}, game_state);
    Generate_From_Loot_Table(entity, table, Roll(2, game_state), {Comparison::between, Rarity::uncommon, Rarity::rare}, game_state);
    Generate_From_Loot_Table(entity, table, 1, {Comparison::minimum, Rarity::epic}, game_state);

    Restore(&game_state->scratch_buffer, snapshot);

    return entity;
}


SIG void Generate_Standard_Random_Loot(Entity* container, Game_State* game_state)
{
    if(Roll(6, game_state) == 1) Create_Alchemists_Pouch(container, game_state);

    if(Roll(6, game_state) == 1) Create_Supply_Crate(container, game_state);

    if(Roll(10, game_state) == 1)
    {
        s32 v = Roll(10, game_state);
        if(v < 4)
        {
            Create_Mushroom(container, game_state);
        }
        else if(v < 8)
        {
            Create_Herbal_Remedy(container, game_state);
        }
        else
        {
            Create_Healing_Potion(container, game_state);
        }
    }

    u64 count = 0;
    if(Roll(3, game_state) > 1)
    {
        u64 max = 5 + Per_Count_Rolled_Random(8, 5, game_state);
        count = 1 + Per_Count_Rolled_Square_Weighted_Random(max, game_state);
    }

    if(count)
    {
        Rarity::T rarity = Rarity::uncommon;
        u32 r = Roll(32, game_state);
        if(r < 4)
        {
            rarity = Rarity::rare;
        }
        else if(r < 1)
        {
            rarity = Rarity::epic;
        }

        Arena_Snapshot snapshot = Snapshot(&game_state->scratch_buffer);
        Generate_From_Loot_Table
        (
            container, 
            Basic_Merged_Loot_Table(game_state), 
            count, 
            Rules_Builder().Rarity(Comparison::maximum, rarity).Finish(), 
            game_state
        );
        Restore(&game_state->scratch_buffer, snapshot);
    }
}