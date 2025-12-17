

// ===================================
// Copyright (c) 2025 by Valtteri Kois
// All rights reserved.
// ===================================


SIG void Finalize_Entity(Entity* entity, Entity* container, Game_State* game_state)
{
    Set_Level_Based_On_Stats(entity);
    Full_Heal(entity, game_state);
    
    Deep_Insert(entity, container, game_state);
}


SIG Entity* Create_Class_Adventurer(Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);
    entity->name_offset = Offset(STR("Adventurer"), game_state);
    entity->description_offset = Offset(STR("A well rounded and beginer friendly. Has a good stockpile of supplies."), game_state);
    entity->flags |= EFlags::actor;

    s16* stats = entity->_stats;
    stats[Stats::might]     = 5;
    stats[Stats::speed]     = 5;
    stats[Stats::dodge]     = 5;
    stats[Stats::accuracy]  = 5;
    stats[Stats::vitality]  = 5;
    stats[Stats::armor]     = 1;
    stats[Stats::arcane]    = 1;
    stats[Stats::immunity]  = 1;
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
    
    // Create_Ring_Of_Just_Fucking_Crit(entity, game_state);
    // Create_Antidote(entity, game_state);
    // 
    // Create_Healing_Potion(entity, game_state);
    // Create_Healing_Potion(entity, game_state);

    return entity;
}


SIG Entity* Create_Class_Wretched(Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);
    entity->name_offset = Offset(STR("Wretched"), game_state);
    entity->description_offset = Offset(STR("A pathetic and useless class that starts with nothing.\nIt does not get weaker than this."), game_state);
    entity->flags |= EFlags::actor;

    s16* stats = entity->_stats;
    stats[Stats::might]     = 1;
    stats[Stats::speed]     = 1;
    stats[Stats::dodge]     = 1;
    stats[Stats::accuracy]  = 1;
    stats[Stats::vitality]  = 1;
    stats[Stats::armor]     = 1;
    Full_Heal(entity,  game_state);
    Set_Level_Based_On_Stats(entity);
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
    
    s16* stats = entity->_stats;
    stats[Stats::might]     = 5;
    stats[Stats::speed]     = 5;
    stats[Stats::dodge]     = 5;
    stats[Stats::accuracy]  = 5;
    stats[Stats::vitality]  = 5;

    Finalize_Entity(entity, room, game_state);
    
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
    
    s16* stats = entity->_stats;
    stats[Stats::might]     = 7;
    stats[Stats::dodge]     = 4;
    stats[Stats::speed]     = 4;
    stats[Stats::accuracy]  = 3;
    stats[Stats::vitality]  = 3;
    stats[Stats::armor]     = 3;
    
    Finalize_Entity(entity, room, game_state);
    
    Effect_Hash_Key key = EFFECT_KEY;
    
    Effect_Offset effect_offset;
    if(!Retrive_Effect(key, &effect_offset, game_state))
    {
        Effect effect = {};
        effect.name_offset = Offset(STR("Fangs"), game_state);
        effect.critical_success_range = + 2;
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

    Rules_Builder rules = Rules_Builder().Rarity(Comparison::maximum, Rarity::epic).Weight(Comparison::maximum, 3);
    Generate_From_Loot_Table(entity, table, Per_Count_Rolled_Random(5, 30, game_state), rules.Finish(), game_state);

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
    
    entity->bonus_exp_reward = + 100;

    s16* stats = entity->_stats;
    stats[Stats::might]     = 4;
    stats[Stats::dodge]     = 3;
    stats[Stats::speed]     = 3;
    stats[Stats::accuracy]  = 6;
    stats[Stats::vitality]  = 9;
    stats[Stats::armor]     = 1;
    stats[Stats::immunity]  = 10;
    stats[Stats::arcane]    = 5;
    
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
                Attempt_Infection(attacker, defender, Effect_Name(instance, game_state), Get_Devouring_Plague(3, attacker, game_state), game_state);
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

    Rules_Builder rules = Rules_Builder().Rarity(Comparison::maximum, Rarity::epic).Weight(Comparison::maximum, 3);
    Generate_From_Loot_Table(entity, table, Per_Count_Rolled_Random(3, 7, game_state), rules.Finish(), game_state);

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
    entity->bonus_exp_reward = -150;
    
    s16* stats = entity->_stats;
    stats[Stats::might]     = 3;
    stats[Stats::dodge]     = 2;
    stats[Stats::speed]     = 2;
    stats[Stats::accuracy]  = 2;
    stats[Stats::vitality]  = 1;
    stats[Stats::armor]     = 1;
    
    Finalize_Entity(entity, room, game_state);
    
    Effect_Hash_Key key = EFFECT_KEY;
    
    Effect_Offset effect_offset;
    if(!Retrive_Effect(key, &effect_offset, game_state))
    {
        Effect effect = {};
        effect.name_offset = Offset(STR("Pinchers"), game_state);
        Add_Dice(&effect, 1, 4);
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
                    for(u32 i = 0; i < 3; ++i)
                    {
                        if(Roll(Square(i + 2), game_state) == 1)
                        {
                            Entity* ant = Create_Enlarged_Ant(space, game_state);
                            ant->bonus_exp_reward -= (s16)Exp_Reward(ant);
                            String message = Format_Message(game_state, "%s birts an %s.", effect_name.ptr, Name(ant, game_state).ptr);
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
    entity->bonus_exp_reward = + 500;
    
    s16* stats = entity->_stats;
    stats[Stats::might]     = 1;
    stats[Stats::dodge]     = 1;
    stats[Stats::speed]     = 1;
    stats[Stats::accuracy]  = 1;
    stats[Stats::vitality]  = 12;
    stats[Stats::armor]     = 8;
    
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

    Generate_From_Loot_Table(entity, table, 1, Rules_Builder().Rarity(Comparison::minimum, Rarity::magical).Finish(), game_state);
    Generate_From_Loot_Table(entity, table, Roll(3, game_state) - 1, Rules_Builder().Rarity(Comparison::maximum, Rarity::rare).Finish(), game_state);

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
    
    s16* stats = entity->_stats;
    stats[Stats::might]     = 8;
    stats[Stats::dodge]     = 4;
    stats[Stats::speed]     = 4;
    stats[Stats::accuracy]  = 3;
    stats[Stats::vitality]  = 8;
    stats[Stats::armor]     = 2;
    
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
    .Rarity(Comparison::maximum, Rarity::epic)
    .Weight(Comparison::maximum, 5)
    .Finish();
    
    Generate_From_Loot_Table(entity, table, Per_Count_Rolled_Random(5, 30, game_state), rules, game_state);

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
    
    s16* stats = entity->_stats;
    stats[Stats::might]     = 2;
    stats[Stats::dodge]     = 1;
    stats[Stats::speed]     = 1;
    stats[Stats::accuracy]  = 2;
    stats[Stats::vitality]  = 6;
    stats[Stats::armor]     = 7;
    
    Finalize_Entity(entity, room, game_state);
    
    {
        Effect_Hash_Key key = EFFECT_KEY;
        
        Effect_Offset effect_offset;
        if(!Retrive_Effect(key, &effect_offset, game_state))
        {
            Effect effect = {};
            effect.name_offset = Offset(STR("Spike shell"), game_state);
            effect.thorns_damage = 6;
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
    }

    {
        Effect_Hash_Key key = EFFECT_KEY;
        
        Effect_Offset effect_offset;
        if(!Retrive_Effect(key, &effect_offset, game_state))
        {
            Effect effect = {};
            effect.name_offset = Offset(STR("Claws"), game_state);
            Add_Dice(&effect, 1, 4);
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
    }

    Generate_From_Loot_Table
    (
        entity, 
        Basic_Merged_Loot_Table(game_state), 
        Per_Count_Rolled_Random(4, 5, game_state), 
        Rules_Builder().Weight(Comparison::maximum, 5).Finish(), 
        game_state
    );

    return entity;
}


SIG Entity* Create_Training_Dummmy(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Training dummy"), game_state);
    entity->description_offset = Offset(STR("Sturdy human shaped dummy, made for practising the usage of weapons."), game_state);

    entity->weight = 100;
    
    s16* stats = entity->_stats;
    stats[Stats::might]     = 0;
    stats[Stats::dodge]     = 0;
    stats[Stats::speed]     = 0;
    stats[Stats::accuracy]  = 0;
    stats[Stats::vitality]  = 100;
    stats[Stats::armor]     = 5;
    
    Finalize_Entity(entity, room, game_state);
    return entity;
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

    s16* stats = entity->_stats;
    stats[Stats::might]     = 10;
    stats[Stats::dodge]     = 0;
    stats[Stats::speed]     = 0;
    stats[Stats::accuracy]  = 8;
    stats[Stats::vitality]  = 15;
    stats[Stats::armor]     = 12;
    
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
    Generate_From_Loot_Table(entity, table, 1, Rules_Builder().Rarity(Comparison::minimum, Rarity::magical).Finish(), game_state);
    Generate_From_Loot_Table(entity, table, Roll(4, game_state) - 1, Rules_Builder().Rarity(Comparison::maximum, Rarity::magical).Finish(), game_state);

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

        Generate_From_Loot_Table
        (
            entity, 
            Basic_Merged_Loot_Table(game_state), 
            Per_Count_Rolled_Square_Weighted_Random(10, game_state), 
            Rules_Builder().Rarity(Comparison::maximum, Rarity::magical).Finish(), 
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
        Per_Count_Rolled_Random(7, 5, game_state), 
        Rules_Builder().Rarity(Comparison::maximum, Rarity::magical).Finish(), 
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
        Per_Count_Rolled_Random(7, 5, game_state), 
        Rules_Builder().Rarity(Comparison::maximum, Rarity::magical).Finish(), 
        game_state
    );

    return entity;
}


SIG Entity* Create_Rat_Meat(Entity* container, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Rat meat"), game_state);
    entity->description_offset = Offset(STR("Dripping red. Swarming with flies."), game_state);
    entity->weight = 5;
    
    Finalize_Entity(entity, container, game_state);

    return entity;
}


SIG Entity* Create_Rat_Mound(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);
  
    entity->name_offset = Offset(STR("Rat mound"), game_state);
    entity->description_offset = Offset(STR("A pile if soil, gravel and rat feces. There could be treasure inside... Or even rats living in it!"), game_state);
    
    entity->flags = 
        EFlags::actor           | 
        EFlags::hidden_iniative | 
        EFlags::container       | 
        EFlags::burst_container;
    
    entity->burst_message_offset = Offset(STR("bursts open releasing it's contents"), game_state);
    entity->burst_change = 0.3f;
    entity->weight = 1000;
    
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
        {Create_Giant_Rat, total_change * 0.8f},
    };

    table = Merge_Loot_Tables(table, {rats, Array_Length(rats), true}, &game_state->scratch_buffer);

    u64 count = Roll(2, game_state) - 1;
    for(u32 i = 0; i < 5; ++i)
    {
        if(Roll(Square(i + 2), game_state) == 1)
        {
            count += 1;
        }
    }

    Generate_From_Loot_Table(entity, table, count, rules, game_state);

    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Spider(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    struct local
    {
        static void On_Hit_FN(Effect_Instance* instance, Entity* attacker, Entity* defender, Attack_Record* ar, Game_State* game_state)
        {
            f32 apply_poison_change = 0.5f;
            u64 poison_duration = 4;
            
            if(attacker)
            {
                f32 r = Random_F32(game_state);
                if(r <= apply_poison_change)
                {
                    // Apply poison!
                    Effect_Offset poison_effect_offset = Get_Poison_Effect_Offset(game_state);
                    Effect_Instance poison_instance = 
                    {
                        poison_duration, 
                        poison_effect_offset, 
                        Offset(attacker, game_state)
                    };
                    
                    Apply_Effect_Result apply = Apply_Effect(defender, poison_instance, game_state);
                    Push_Generic_Apply_Effect_Message(Effect_Name(instance, game_state), defender, poison_instance, apply, game_state);
                }
            }
        }
    };
    
    entity->name_offset = Offset(STR("Spider"), game_state);
    entity->description_offset = Offset(STR(""), game_state);

    entity->flags = EFlags::actor | EFlags::aggressive;
    entity->faction = Faction::nature;
    entity->weight = 30;
    
    s16* stats = entity->_stats;
    stats[Stats::might]     = 4;
    stats[Stats::speed]     = 10;
    stats[Stats::dodge]     = 10;
    stats[Stats::accuracy]  = 6;
    stats[Stats::vitality]  = 2;
    stats[Stats::armor]     = 1;
    
    Finalize_Entity(entity, room, game_state);
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
    
    s16* stats = entity->_stats;
    stats[Stats::might]     = 7;
    stats[Stats::speed]     = 2;
    stats[Stats::dodge]     = 4;
    stats[Stats::accuracy]  = 8;
    stats[Stats::vitality]  = 10;
    stats[Stats::armor]     = 8;
    
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
    Generate_From_Loot_Table(entity, table, Roll(2, game_state), {Comparison::between, Rarity::rare, Rarity::magical}, game_state);
    Generate_From_Loot_Table(entity, table, 1, {Comparison::minimum, Rarity::epic}, game_state);

    Restore(&game_state->scratch_buffer, snapshot);

    return entity;
}


SIG void Generate_Entrance_Room(Entity* room, Game_State* game_state)
{
    char room_description[] = 
    "The mountainside here is steep. Almost vertical.\n"
    "There is a massive arch carved into the stone.\n"
    "On top of it there is a placard that says \"This is where champions are born and charlatans fall.\"\n"
    "Inside the arch there is a cave entrance.\n"
    "Light does not seem to be able to penetrate the threshold.\n"
    "You can not see inside.";

    room->name_offset = Offset(STR("The Entrance"), game_state);
    room->description_offset = Offset(STR(room_description), game_state);

    LOOP(3) Create_Skull_Cap(room, game_state);
    Create_Great_Club(room, game_state);

    for(u64 i = 0; i < 10; ++i) 
    {
        Entity* e = Create_Healing_Potion(room, game_state);
        if(i % 2)
        {
            e->interactable.uses_count = 5;
        }
    }
}


SIG Loot_Table Caves_Wildlife_Section(Game_State* game_state)
{
    struct local
    {
        static Entity* Supply_Room(Entity* fill_room_if_greater_than_zero, Game_State* game_state)
        {
            Entity* room = Request_Entity(game_state);
            room->rarity = Rarity::epic;
            if(fill_room_if_greater_than_zero)
            {
                room->name_offset = Offset(STR("a supply room"), game_state);
                char room_description[] = 
                "Entrance here was well hidden, behind a heavy rock and through a tight crawlspace, but what a splender?\n"
                "It is a supply room, someone has been colleting and neatly organising weapons, armor and other supplies here.";
                room->description_offset = Offset(STR(room_description), game_state);

                Create_Chest(room, game_state);
                u64 weapon_racks = 1 + Per_Count_Rolled_Square_Weighted_Random(2, game_state);
                LOOP(weapon_racks) Create_Weapon_Rack(room, game_state);

                u64 armor_racks = 1 + Per_Count_Rolled_Square_Weighted_Random(2, game_state);
                LOOP(armor_racks) Create_Armor_Rack(room, game_state);

                Arena_Snapshot snapshot = Snapshot(&game_state->scratch_buffer);
                Generate_From_Loot_Table
                (
                    room, 
                    Basic_Merged_Loot_Table(game_state), 
                    Per_Count_Rolled_Square_Weighted_Random(10, game_state), 
                    Rules_Builder().Rarity(Comparison::equal, Rarity::common).Finish(), 
                    game_state
                );
                Restore(&game_state->scratch_buffer, snapshot);
            }

            return room;
        }


        static Entity* Opening(Entity* fill_room_if_greater_than_zero, Game_State* game_state)
        {
            Entity* room = Request_Entity(game_state);
            if(fill_room_if_greater_than_zero)
            {
                room->name_offset = Offset(STR("a wide opening"), game_state);
                char room_description[] = 
                "The stone walls extend into the unseeable darkness.\n"
                "The ceiling must be very far away.\n" 
                "In the black you can see bright glowing eyes moving towards you.";
                room->description_offset = Offset(STR(room_description), game_state);

                u32 dudes = 1 + (Roll(3, game_state) == 1);
                LOOP(dudes) Create_Giant_Rat(room, game_state);
                if(Roll(3, game_state) == 1) Create_Rat_Mound(room, game_state);
                if(Roll(5, game_state) == 1)
                {
                    Arena_Snapshot snapshot = Snapshot(&game_state->scratch_buffer);
                    Generate_From_Loot_Table
                    (
                        room, 
                        Basic_Merged_Loot_Table(game_state), 
                        Roll(2, game_state), 
                        Rules_Builder().Rarity(Comparison::maximum, Rarity::rare).Finish(), 
                        game_state
                    );
                    Restore(&game_state->scratch_buffer, snapshot);
                }
            }

            return room;
        }


        static Entity* Hallway(Entity* fill_room_if_greater_than_zero, Game_State* game_state)
        {
            Entity* room = Request_Entity(game_state);
            if(fill_room_if_greater_than_zero)
            {
                room->name_offset = Offset(STR("a long hallway"), game_state);
                char room_description[] = 
                "In the dark path ahead you can something moving.\n";
                room->description_offset = Offset(STR(room_description), game_state);
                
                Create_Giant_Rat(room, game_state);
                if(Roll(3, game_state) == 1)
                {
                    Arena_Snapshot snapshot = Snapshot(&game_state->scratch_buffer);
                    Generate_From_Loot_Table
                    (
                        room, 
                        Basic_Merged_Loot_Table(game_state), 
                        Roll(2, game_state), 
                        Rules_Builder().Rarity(Comparison::maximum, Rarity::rare).Finish(), 
                        game_state
                    );
                    Restore(&game_state->scratch_buffer, snapshot);
                }
            }

            return room;
        }


        static Entity* Recent_Battlefield(Entity* fill_room_if_greater_than_zero, Game_State* game_state)
        {
            Entity* room = Request_Entity(game_state);
            if(fill_room_if_greater_than_zero)
            {
                room->name_offset = Offset(STR("a battlefield"), game_state);
                char room_description[] = 
                "It looks like a group goblins and humans recently fought here. The dead were unceremoniously left where they had fallen.";
                room->description_offset = Offset(STR(room_description), game_state);

                Create_Blight_Rat(room, game_state);

                Arena_Snapshot snapshot = Snapshot(&game_state->scratch_buffer);
                Loot_Table table = Basic_Merged_Loot_Table(game_state);
                Generate_From_Loot_Table
                (
                    room, 
                    table, 
                    Roll(2, game_state), 
                    Rules_Builder().Rarity(Comparison::equal, Rarity::common).Finish(), 
                    game_state
                );

                Generate_From_Loot_Table
                (
                    room, 
                    table, 
                    1, 
                    Rules_Builder().Rarity(Comparison::maximum, Rarity::magical).Finish(), 
                    game_state
                );

                Restore(&game_state->scratch_buffer, snapshot);
            
            }

            return room;
        }

        static Entity* Graveyard(Entity* fill_room_if_greater_than_zero, Game_State* game_state)
        {
            Entity* room = Request_Entity(game_state);
            room->rarity = Rarity::epic;
            if(fill_room_if_greater_than_zero)
            {
                room->name_offset = Offset(STR("a mass grave"), game_state);
                char room_description[] = 
                "There are hatches in the cealing. Under them are piles and piles of rotting corpses. The dead appear to be goblins.\n"
                "From upstairs, you can hear the echoes of torture.";
                room->description_offset = Offset(STR(room_description), game_state);

                LOOP(2) Create_Blight_Rat(room, game_state);

                Arena_Snapshot snapshot = Snapshot(&game_state->scratch_buffer);
                Loot_Table table = Basic_Merged_Loot_Table(game_state);
                Generate_From_Loot_Table
                (
                    room, 
                    table, 
                    2, 
                    Rules_Builder().Rarity(Comparison::equal, Rarity::common).Finish(), 
                    game_state
                );

                Generate_From_Loot_Table
                (
                    room, 
                    table, 
                    Roll(3, game_state), 
                    Rules_Builder().Rarity(Comparison::maximum, Rarity::magical).Finish(), 
                    game_state
                );

                Restore(&game_state->scratch_buffer, snapshot);
            
            }

            return room;
        }


        static Entity* Small_Rat_Nest(Entity* fill_room_if_greater_than_zero, Game_State* game_state)
        {
            Entity* room = Request_Entity(game_state);
            if(fill_room_if_greater_than_zero)
            {
                room->name_offset = Offset(STR("a small rat nest"), game_state);
                char room_description[] = 
                "Looks to be a rat colony, but thankfully a small one.";
                room->description_offset = Offset(STR(room_description), game_state);

                if(Roll(4, game_state) == 1)
                {
                    Create_Blight_Rat(room, game_state);
                }
                else
                {
                    Create_Giant_Rat(room, game_state);
                }
                
                u64 mounds = 2 + (Roll(3, game_state) == 1);
                LOOP(mounds) Create_Rat_Mound(room, game_state);
                
                Arena_Snapshot snapshot = Snapshot(&game_state->scratch_buffer);
                Generate_From_Loot_Table
                (
                    room, 
                    Basic_Merged_Loot_Table(game_state), 
                    Per_Count_Rolled_Random(5, 10, game_state), 
                    Rules_Builder().Rarity(Comparison::maximum, Rarity::magical).Finish(), 
                    game_state
                );
                Restore(&game_state->scratch_buffer, snapshot);
            }

            return room;
        }


        static Entity* Carcase(Entity* fill_room_if_greater_than_zero, Game_State* game_state)
        {
            Entity* room = Request_Entity(game_state);
            room->rarity = Rarity::rare;
            if(fill_room_if_greater_than_zero)
            {
                room->name_offset = Offset(STR("a dead-end"), game_state);
                char room_description[] = 
                "You crawl through a crack in the wall, but it led only to small dead end room.\n"
                "In the middle, there is a fresh corpse of a human. A creature is eating it.";
                room->description_offset = Offset(STR(room_description), game_state);

                u64 creature = Roll(10, game_state);
                if(creature < 4)
                {
                    Create_Giant_Rat(room, game_state);
                }
                else if (creature < 8)
                {
                    Create_Mutant_Hedgehog(room, game_state);
                }
                else
                {
                    Create_Blight_Rat(room, game_state);
                }
                
                Entity* bandit = Create_Bandit(room, game_state);
                bandit->_health = 0;

                if(Roll(10, game_state) == 1) Create_Chest(room, game_state);
            }

            return room;
        }


        static Entity* Empty_Cavern(Entity* fill_room_if_greater_than_zero, Game_State* game_state)
        {
            Entity* room = Request_Entity(game_state);
            room->rarity = Rarity::rare;
            if(fill_room_if_greater_than_zero)
            {
                room->name_offset = Offset(STR("a cavern"), game_state);
                char room_description[] = 
                "There doesn't seem to anything of interest here.";
                room->description_offset = Offset(STR(room_description), game_state);
            }

            return room;
        }


        static Entity* Warzone(Entity* fill_room_if_greater_than_zero, Game_State* game_state)
        {
            Entity* room = Request_Entity(game_state);
            room->rarity = Rarity::magical;
            if(fill_room_if_greater_than_zero)
            {
                room->name_offset = Offset(STR("a battlefield"), game_state);
                char room_description[] = 
                "Ants and rats are fighting over a corpse.\n";
                room->description_offset = Offset(STR(room_description), game_state);

                u64 rats = 3 + (Roll(3, game_state) == 1);
                u64 ants = 5 + Roll(8, game_state);

                if(Roll(4, game_state) == 1)
                {
                    Entity* entity = Create_Blight_Rat(room, game_state);
                    entity->faction = Faction::rats;
                }

                LOOP(rats)
                {
                    Entity* entity = Create_Giant_Rat(room, game_state);
                    entity->faction = Faction::rats;
                }

                LOOP(ants)
                {
                    Entity* entity = Create_Enlarged_Ant(room, game_state);
                    entity->faction = Faction::ants;
                }

                Entity* entity = Create_Bear_Cub(room, game_state);
                entity->_health = 0;
            }

            return room;
        }


        static Entity* Ant_Nest(Entity* fill_room_if_greater_than_zero, Game_State* game_state)
        {
            Entity* room = Request_Entity(game_state);
            room->rarity = Rarity::epic;
            if(fill_room_if_greater_than_zero)
            {
                room->name_offset = Offset(STR("an ant nest"), game_state);
                char room_description[] = 
                "The blackess around you is moving. If you focus hard on single spot you realise that,\n"
                "everything from the floor to the ceiling is covered in layers and layers of interleaving ants.";
                room->description_offset = Offset(STR(room_description), game_state);

                Entity* bandit = Create_Enlarged_Ant_Queen(room, game_state);
            }

            return room;
        }


        static Entity* Abandoned_Camp(Entity* fill_room_if_greater_than_zero, Game_State* game_state)
        {
            Entity* room = Request_Entity(game_state);
            if(fill_room_if_greater_than_zero)
            {
                room->name_offset = Offset(STR("an abandoned camp"), game_state);
                char room_description[] = 
                "You can see torn up tents. There is also a firepit, but is has gone cold a long time ago.";
                room->description_offset = Offset(STR(room_description), game_state);

                switch(Roll(3, game_state))
                {
                    case 1:
                    {
                        Create_Mutant_Hedgehog(room, game_state);
                    }break;
                    
                    case 2:
                    {
                        LOOP(6) Create_Enlarged_Ant(room, game_state);
                    }break;
                    
                    case 3:
                    {
                        LOOP(2) Create_Giant_Rat(room, game_state);
                        if(Roll(3, game_state) == 1) Create_Rat_Mound(room, game_state);
                    }break;
                }

                Arena_Snapshot snapshot = Snapshot(&game_state->scratch_buffer);
                Generate_From_Loot_Table
                (
                    room, 
                    Basic_Merged_Loot_Table(game_state), 
                    Per_Count_Rolled_Random(5, 4, game_state), 
                    Rules_Builder().Rarity(Comparison::equal, Rarity::common).Finish(), 
                    game_state
                );

                if(Roll(2, game_state) == 1)
                {
                    Create_Weapon_Rack(room, game_state);
                }
                else
                {
                    Create_Armor_Rack(room, game_state);
                }

                Restore(&game_state->scratch_buffer, snapshot);
            }

            return room;
        }


        static Entity* Beast_Lair(Entity* fill_room_if_greater_than_zero, Game_State* game_state)
        {
            Entity* room = Request_Entity(game_state);
            room->rarity = Rarity::magical;
            if(fill_room_if_greater_than_zero)
            {
                room->name_offset = Offset(STR("a beasts lair"), game_state);
                char room_description[] = 
                "In the middle of the room there is what looks to you to be a \"bed\" of sorts.\n"
                "It's made of tree branches and leaves. Around it there are many half eaten carcasses.\n"
                "Some of them animals, others human... or humanoid. You can not tell.";
                room->description_offset = Offset(STR(room_description), game_state);

                u32 dudes = 1 + (Roll(4, game_state) == 1);
                LOOP(dudes) Create_Bear_Cub(room, game_state);
                if(Roll(10, game_state) == 1) Create_Chest(room, game_state);

                Arena_Snapshot snapshot = Snapshot(&game_state->scratch_buffer);
                Generate_From_Loot_Table
                (
                    room, 
                    Basic_Merged_Loot_Table(game_state), 
                    Per_Count_Rolled_Square_Weighted_Random(10, game_state), 
                    Rules_Builder().Rarity(Comparison::maximum, Rarity::magical).Finish(), 
                    game_state
                );
                Restore(&game_state->scratch_buffer, snapshot);
            }

            return room;
        }
    };


    local_storage Loot_Table_Entry entries[] = 
    {
        {local::Opening},
        {local::Carcase},
        {local::Abandoned_Camp},
        {local::Ant_Nest},
        {local::Warzone},
        {local::Small_Rat_Nest},
        {local::Empty_Cavern},
        {local::Beast_Lair},
        {local::Graveyard},
        {local::Recent_Battlefield},
        {local::Hallway},
        {local::Supply_Room},
    };

    local_storage Loot_Table table = {entries, Array_Length(entries)};
    Fill_Loot_Table_Changes_And_Item_Rarity(&table, game_state);

    return table;
}

SIG Loot_Table Caves_Bandit_Section(Game_State* game_state)
{
    struct local
    {
        static Entity* Camp(Entity* fill_room_if_greater_than_zero, Game_State* game_state)
        {
            Entity* room = Request_Entity(game_state);
            if(fill_room_if_greater_than_zero)
            {
                room->name_offset = Offset(STR("a camp"), game_state);
                #if 0
                char room_description[] = 
                "The stone walls extend into the unseeable darkness.\n"
                "The ceiling must be very far away.\n" 
                "In the black you can see bright glowing eyes moving towards you.";
                room->description_offset = Offset(STR(room_description), game_state);
                #endif

                Create_Bandit(room, game_state);
            }

            return room;
        }
    };


    local_storage Loot_Table_Entry entries[] = 
    {
        {local::Camp},
    };

    local_storage Loot_Table table = {entries, Array_Length(entries)};
    Fill_Loot_Table_Changes_And_Item_Rarity(&table, game_state);

    return table;
}


SIG Loot_Table Caves_Spider_Section(Game_State* game_state)
{
    struct local
    {
        static Entity* Ravine(Entity* fill_room_if_greater_than_zero, Game_State* game_state)
        {
            Entity* room = Request_Entity(game_state);
            if(fill_room_if_greater_than_zero)
            {
                room->name_offset = Offset(STR("a ravine"), game_state);
                
                char room_description[] = 
                "A deep ravine cuts through the path, but there is bridge made of spider web that crosses it.";
                room->description_offset = Offset(STR(room_description), game_state);
                
                Create_Spider(room, game_state);
            }

            return room;
        }
    };


    local_storage Loot_Table_Entry entries[] = 
    {
        {local::Ravine},
    };

    local_storage Loot_Table table = {entries, Array_Length(entries)};
    Fill_Loot_Table_Changes_And_Item_Rarity(&table, game_state);

    return table;
}


SIG Loot_Table Caves_Boss(Game_State* game_state)
{
    struct local
    {
        static Entity* Boss_Chamber(Entity* fill_room_if_greater_than_zero, Game_State* game_state)
        {
            Entity* room = Request_Entity(game_state);
            if(fill_room_if_greater_than_zero)
            {
                room->name_offset = Offset(STR("the Boss chamber!"), game_state);
                
                char room_description[] = 
                "";
                room->description_offset = Offset(STR(room_description), game_state);
                
                Create_Spider(room, game_state);
            }

            return room;
        }
    };


    local_storage Loot_Table_Entry entries[] = 
    {
        {local::Boss_Chamber},
    };

    local_storage Loot_Table table = {entries, Array_Length(entries)};
    Fill_Loot_Table_Changes_And_Item_Rarity(&table, game_state);

    return table;
}


SIG _inline Level_Segments Caves(Game_State* game_state)
{
    local_storage Level_Segment segments[] = 
    {
        {Caves_Wildlife_Section(game_state), 5}, 
        {Caves_Bandit_Section(game_state),   5}, 
        {Caves_Spider_Section(game_state),   5}, 
        {Caves_Boss(game_state), 1}
    };

    Level_Segments level = {segments, Array_Length(segments)};
    return level;
}