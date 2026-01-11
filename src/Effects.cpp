
// ===================================
// Copyright (c) 2025 by Valtteri Kois
// All rights reserved.
// ===================================


// NOTE: Macro for implicit tagging. And automated Assertions. I know... I know macros bad, but I feel this even though harder to read,
// does prevent making easy copy paste mistakes.
#define EFFECT_KEY Effect_Hash_Key{__LINE__, u32(u64(__FILE__))};


SIG Effect_Offset Get_Critical_Effect_Offset(Game_State* game_state)
{
    Effect_Offset result;
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &result, game_state))
    {
        Effect effect = {};
        effect.name_offset = Offset(STR("Critical"), game_state);
        result = Insert_Effect(effect, key, game_state);
    }

    return result;
}


SIG Effect_Offset Get_Might_Effect_Offset(Game_State* game_state)
{
    Effect_Offset result;
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &result, game_state))
    {
        Effect effect = {};
        effect.name_offset = Offset(STR("Might"), game_state);
        result = Insert_Effect(effect, key, game_state);
    }

    return result;
}


SIG void Pack_Hunt_On_Turn_Start(Effect_Instance* instance, Entity* target, Game_State* game_state)
{
    if(instance)
    {
        u64 pack_members_count = 0;

        String name = Get_String(target->name_offset, game_state);
        Entity_Iterator iter = Make_Iterator(Pointer(target->residence, game_state), game_state);
        while(Entity* entity = Next_Entity(&iter))
        {
            if(entity != target && Is_Alive(entity) && Match_Case_Sensitive(name, Get_String(entity->name_offset, game_state)))
            {
                pack_members_count += 1;
            }
        }

        if(pack_members_count)
        {
            s8 v = (s8)Min(pack_members_count, u64(5));

            Arena_Snapshot snapshot = Snapshot(&game_state->scratch_buffer);

            String pack_hunt_name = {};
            pack_hunt_name.ptr = Push_String(&game_state->scratch_buffer, STR("Pack Hunt x"), &pack_hunt_name.length);
            U64_To_String_Memory m;
            Push_String(&game_state->scratch_buffer, To_String(v, &m), &pack_hunt_name.length);


            Effect* effect = Request_Effect(game_state);
            effect->name_offset = Offset(pack_hunt_name, game_state);
            Restore(&game_state->scratch_buffer, snapshot);

            effect->stat_modifiers[Stats::might]    = + v;
            effect->stat_modifiers[Stats::accuracy] = + v;
            effect->critical_success_range          = + v;
            
            Effect_Instance pack_hunt = {};
            pack_hunt.source = instance->source;
            pack_hunt.effect_offset = Offset(effect, game_state);
            pack_hunt.zero_ticked = true;
            pack_hunt.duration = 1;

            Apply_Effect_Result apply = Apply_Effect(target, pack_hunt, game_state);
            if(apply == Apply_Effect_Result::success)
            {
                Push_Generic_Apply_Effect_Message(Name(target, game_state), target, pack_hunt, apply, game_state);
            }
        }
    }
    else
    {
        Print("Increases accuracy, might, and crit change by the amount of other living entities in the room, with the same name.");
    }
}


SIG void Survival_Instinct_On_Turn_Start(Effect_Instance* instance, Entity* target, Game_State* game_state)
{
    f32 trigger_ratio = 0.2f;
    s16 armor_buff = 20;
    if(instance)
    {
        s32 health = target->_health;
        s32 max_health = Max_Health(target, game_state);
        s32 trigger_health = Round_To_S32(f32(max_health) * trigger_ratio);

        if(health <= trigger_health)
        {
            Effect_Instance effect_instance = 
            {
                1, 
                {}, 
                Offset(target, game_state)
            };
            effect_instance.duration_type = Duration_Type::room;

            Effect_Hash_Key key = EFFECT_KEY;
            if(!Retrive_Effect(key, &effect_instance.effect_offset, game_state))
            {
                Effect effect = {};
                effect.name_offset = Offset(STR("Survival Instinct"), game_state);
                effect.stat_modifiers[Stats::armor] = armor_buff;
                effect_instance.effect_offset = Insert_Effect(effect, key, game_state);
            }

            Apply_Effect_Result apply = Apply_Effect(target, effect_instance, game_state);
            if(apply == Apply_Effect_Result::success)
            {
                Push_Generic_Apply_Effect_Message(Name(target, game_state), target, effect_instance, apply, game_state);
            }
        }

    }
    else
    {
        Print("If health is below %.2f%% increase armor by %d points.", trigger_ratio * 100, armor_buff);
    }
}


SIG void Strength_Of_Earth_Small_On_Turn_Start(Effect_Instance* instance, Entity* target, Game_State* game_state)
{
    f32 trigger_ratio = 0.5f;
    if(instance)
    {
        s32 health = target->_health;
        s32 max_health = Max_Health(target, game_state);
        s32 trigger_health = Round_To_S32(f32(max_health) * trigger_ratio);

        if(health <= trigger_health)
        {
            Print("%s crumbles into 2 smaller golems.", Name(target, game_state).ptr);
            target->_health = 0;
            Entity* room = Pointer(target->residence, game_state);
            LOOP(2) Create_Small_Earth_Golem(room, game_state);

            Wait(1, game_state);
        }
    }
    else
    {
        Print("If health is below %.2f%% split into 2 smaller golems", trigger_ratio * 100);
    }
}


SIG void Strength_Of_Earth_Tiny_On_Turn_Start(Effect_Instance* instance, Entity* target, Game_State* game_state)
{
    f32 trigger_ratio = 0.5f;
    if(instance)
    {
        s32 health = target->_health;
        s32 max_health = Max_Health(target, game_state);
        s32 trigger_health = Round_To_S32(f32(max_health) * trigger_ratio);

        if(health <= trigger_health)
        {
            Print("%s crumbles into 2 smaller golems", Name(target, game_state).ptr);
            target->_health = 0;
            Entity* room = Pointer(target->residence, game_state);
            LOOP(2) Create_Tiny_Earth_Golem(room, game_state);
            
            Wait(1, game_state);
        }
    }
    else
    {
        Print("If health is below %.2f%% split into 2 smaller golems", trigger_ratio * 100);
    }
}


SIG void Dissapate_After_Two_On_Turn_Start(Effect_Instance* instance, Entity* target, Game_State* game_state)
{
    u64 trigger_duration = 2;
    if(instance)
    {
        
        u64 round = game_state->round;
        u64 applied = instance->round_applied;

        if(round > applied + 2)
        {
            Print("%s dissipates.", Name(target, game_state).ptr);
            target->_health = 0;
            target->flags = EFlags::hidden;

            Wait(1, game_state);
        }
    }
    else
    {
        Print("%llu turns after the effect was applied, the afflicted dissipates.", trigger_duration);
    }
}


SIG Effect_Offset Get_Enraged_Effect_Offset(Game_State* game_state)
{
    struct local
    {
        static void Enrage_On_Turn_Start(Effect_Instance* instance, Entity* target, Game_State* game_state)
        {
            if(instance)
            {
                u64 effective_duration = Max(u64(1), game_state->round - instance->round_applied);

                Effect* effect = Request_Effect(game_state);

                String name = {};
                U64_To_String_Memory memory = {};
                
                Arena_Snapshot snapshot = Snapshot(&game_state->scratch_buffer);
                
                name.ptr = Push_String(&game_state->scratch_buffer, STR("Fury x"), &name.length);
                Push_String(&game_state->scratch_buffer, To_String(effective_duration, &memory), &name.length);
                
                effect->name_offset = Offset(name, game_state);
                
                Restore(&game_state->scratch_buffer, snapshot);

                effect->flags |= Effect_Flags::has_damage_multiplier;
                effect->damage_multiplier = 1.f + f32(effective_duration) * 0.1f;
                effect->type = Effect_Type::physical;

                Effect_Instance effect_instance = {};
                effect_instance.effect_offset = Offset(effect, game_state);
                effect_instance.source = instance->source;
                effect_instance.zero_ticked = true;
                effect_instance.duration = 1;

                Apply_Effect_Result apply = Apply_Effect(target, effect_instance, game_state);
                Push_Generic_Apply_Effect_Message(Effect_Name(instance, game_state), target, effect_instance, apply, game_state);
            }
            else
            {
                Print("Increases damage dealt by 10%% for each round enrage has been effective.");
            }
        }

        static void Enrage_On_Hit(Effect_Instance* instance, Entity* attacker, Entity* defender, Attack_Record* ar, Game_State* game_state)
        {
            if(instance)
            {
                instance->zero_ticked = false;
                Push_Message(STR("Enrage refreshed."), game_state);
            }
            else
            {
                Print("Refreshes effect duration.");
            }
        }
    };

    Effect_Offset result;
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &result, game_state))
    {
        Effect effect = {};
        effect.name_offset = Offset(STR("Enraged"), game_state);
        effect.type = Effect_Type::physical;
        effect.on_turn_start_fn_offset = Offset(local::Enrage_On_Turn_Start, game_state);
        effect.on_hit_fn_offset = Offset(local::Enrage_On_Hit, game_state);
        result = Insert_Effect(effect, key, game_state);
    }

    return result;
}


SIG Effect_Instance Get_Enraged(Entity* source, Game_State* game_state)
{
    Effect_Instance instance = {};
    instance.source = Offset(source, game_state);
    instance.duration_type = Duration_Type::round;
    instance.duration = 1;
    instance.effect_offset = Get_Enraged_Effect_Offset(game_state);

    return instance;
}


SIG Effect_Offset Get_Vampirism_Effect_Offset(Game_State* game_state)
{
    struct local
    {
        static void Vampirism_On_Apply_Effect(Effect_Instance* instance, Entity* entity, Game_State* game_state)
        {
            Attack_Mod::T mod = Attack_Mod::vampiric;
            if(entity)
            {
                bool already_knows_it = entity->known_attack_modifiers & Attack_Modifier_Mask(mod);
                if(!already_knows_it)
                {
                    entity->known_attack_modifiers |= Attack_Modifier_Mask(mod);
                    String entity_name = Name(entity, game_state);
                    String message = Format_Message(game_state, "%s learned the %s attack.", entity_name.ptr, Attack_Mod::name[mod].ptr);
                    Push_Message(message, game_state);
                }
            }
            else
            {
                Print("Teaches the %s attack.", Attack_Mod::name[mod].ptr);
            }
        }

        static void Vampirisim_On_Heal_Effect(Effect_Instance* instance, Entity* entity, s32* amount, String source_name, Game_State* game_state)
        {
            if(instance)
            {
                if(!Match_Case_Sensitive(source_name, STR("Vampiric attack")))
                {
                    *amount = 0;
                    String message = Format_Message(game_state, "Vampirism negates healing from %s.", source_name.ptr);
                    Push_Message(message, game_state);
                }
            }
            else
            {
                Print("Negates the healing unless it's source is from the %s attack.", Attack_Mod::name[Attack_Mod::vampiric].ptr);
            }
        }
    };

    Effect_Offset result;
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &result, game_state))
    {
        Effect effect = {};
        effect.name_offset = Offset(STR("Vampirism"), game_state);
        effect.on_heal_fn_offset = Offset(local::Vampirisim_On_Heal_Effect, game_state);
        effect.on_apply_fn_offset = Offset(local::Vampirism_On_Apply_Effect, game_state);
        effect.type = Effect_Type::curse;
        result = Insert_Effect(effect, key, game_state);
    }

    return result;
}


SIG Dice Poison_Damage_Dice(){ return {1, 4}; }
SIG Effect_Instance Get_Poison(u64 duration, Entity* source, Game_State* game_state)
{
    struct local
    {
        static void On_Turn_End(Effect_Instance* instance, Entity* target, Game_State* game_state)
        {
            Dice dice = Poison_Damage_Dice();

            if(target)
            {
                s16 dmg = (s16)Roll(dice, game_state);
                String name = Effect_Name(instance, game_state);
                Deal_Damage(target, instance->source, name, dmg, 0, Damage_Type::magical, game_state, Verbose::yes);
            }
            else
            {
                Print("Deals %dd%d damage.", dice.count, dice.faces);
            }
        }
    };

    Effect_Instance instance = {};
    instance.duration = duration;
    instance.source = Offset(source, game_state);

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &instance.effect_offset, game_state))
    {
        Effect effect = {};
        effect.name_offset = Offset(STR("Poison"), game_state);
        effect.on_turn_end_fn_offset = Offset(local::On_Turn_End, game_state);
        effect.type = Effect_Type::poison;
        instance.effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    return instance;
}


SIG Effect_Offset Get_Burning_Effect_Offset(Game_State* game_state)
{
    struct local
    {
        static void Burning_On_Turn_End(Effect_Instance* instance, Entity* target, Game_State* game_state)
        {
            Dice dice = {2, 4};
            if(instance)
            {
                s16 dmg = (s16)Roll(dice, game_state);
                String name = Effect_Name(instance, game_state);
                Deal_Damage(target, instance->source, name, dmg, 0, Damage_Type::magical, game_state, Verbose::yes);
            }
            else
            {
                Print("Deals %dd%d damage.\n", dice.count, dice.faces);
            }
        }
    };

    Effect_Offset result;
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &result, game_state))
    {
        Effect effect = {};
        effect.name_offset = Offset(STR("Burning"), game_state);
        effect.type = Effect_Type::magic;
        effect.on_turn_end_fn_offset = Offset(local::Burning_On_Turn_End, game_state);
        result = Insert_Effect(effect, key, game_state);
    }

    return result;
}


SIG Effect_Instance Get_Festering_Rash(u64 duration, Entity* source, Game_State* game_state)
{
    Effect_Instance instance = {};
    instance.source = Offset(source, game_state);
    instance.duration_type = Duration_Type::room;
    instance.duration = duration;

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &instance.effect_offset, game_state))
    {
        Effect effect = {};
        effect.name_offset = Offset(STR("Festering rash"), game_state);
        effect.type = Effect_Type::disease;
        effect.stat_modifiers[Stats::might] = - 1;
        effect.stat_modifiers[Stats::dodge] = - 1;
        effect.stat_modifiers[Stats::speed] = - 1;
        effect.stat_modifiers[Stats::arcane] = - 1;
        effect.stat_modifiers[Stats::immunity] = - 1;
        effect.stat_modifiers[Stats::accuracy] = - 1;
        effect.stat_modifiers[Stats::vitality] = - 1;

        effect.critical_success_range = - 1;
        effect.critical_failure_range = + 1;

        instance.effect_offset = Insert_Effect(effect, key, game_state);
    }

    return instance;
}


SIG Effect_Instance Get_Weakening_Blight(u64 duration, Entity* source, Game_State* game_state)
{
    Effect_Instance instance = {};
    instance.source = Offset(source, game_state);
    instance.duration_type = Duration_Type::room;
    instance.duration = duration;

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &instance.effect_offset, game_state))
    {
        Effect effect = {};
        effect.name_offset = Offset(STR("Weakening Blight"), game_state);
        effect.type = Effect_Type::disease;
        effect.stat_modifiers[Stats::might] = - 3;
        effect.carry_capacity_modifier      = - 10;

        instance.effect_offset = Insert_Effect(effect, key, game_state);
    }

    return instance;
}


SIG Effect_Instance Get_Neuro_Toxin(u64 duration, Entity* source, Game_State* game_state)
{
    Effect_Instance instance = {};
    instance.source = Offset(source, game_state);
    instance.duration = duration;

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &instance.effect_offset, game_state))
    {
        Effect effect = {};
        effect.name_offset = Offset(STR("Neuro Toxin"), game_state);
        effect.type = Effect_Type::poison;
        effect.stat_modifiers[Stats::vitality] = - 3;
        effect.stat_modifiers[Stats::arcane]   = - 5;

        instance.effect_offset = Insert_Effect(effect, key, game_state);
    }

    return instance;
}


SIG Effect_Instance Get_Leech(u64 duration, Entity* source, Game_State* game_state)
{
    struct local
    {
        static void On_Apply(Effect_Instance* instance, Entity* target, Game_State* game_state)
        {
            if(instance)
            {
                Entity* leech = Pointer(instance->source, game_state);
                if(leech)
                {
                    leech->_health = 0;
                    leech->flags = EFlags::hidden;
                }
            }
            else
            {
                Print("Leech is removed from active play as it turns into the effect.");
            }
        }

        static void On_Turn_Start(Effect_Instance* instance, Entity* target, Game_State* game_state)
        {
            s32 damage = 1;
            if(instance)
            {
                Deal_Damage(target, instance->source, Effect_Name(instance, game_state), damage, {}, Damage_Type::magical, game_state, Verbose::yes);
            }
            else
            {
                Print("Take %d point%s of damage.", damage, (damage > 1)? "s" : "");
            }
        }
    };

    Effect_Instance instance = {};
    instance.source = Offset(source, game_state);
    instance.duration_type = Duration_Type::round;
    instance.duration = duration;

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &instance.effect_offset, game_state))
    {
        Effect effect = {};
        effect.name_offset = Offset(STR("Leech"), game_state);
        effect.on_apply_fn_offset = Offset(local::On_Apply, game_state);
        effect.on_turn_start_fn_offset = Offset(local::On_Turn_Start, game_state);
        effect.stat_modifiers[Stats::immunity] = - 3;
        effect.type = Effect_Type::bleed;
        instance.effect_offset = Insert_Effect(effect, key, game_state);
    }

    return instance;
}


SIG Effect_Instance Get_Filled_With_Blood(u64 duration, Entity* source, Game_State* game_state)
{
    struct local
    {
        static void On_Turn_End(Effect_Instance* instance, Entity* target, Game_State* game_state)
        {
            s32 healing = 10;
            if(instance)
            {
                Heal(target, healing, Effect_Name(instance, game_state), Verbose::yes, game_state);
            }
            else
            {
                Print("Heals the afflicted %d points.", healing);
            }
        }
    };

    Effect_Instance instance = {};
    instance.source = Offset(source, game_state);
    instance.duration_type = Duration_Type::room;
    instance.duration = duration;

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &instance.effect_offset, game_state))
    {
        Effect effect = {};
        effect.name_offset = Offset(STR("Filled With Blood"), game_state);
        effect.type = Effect_Type::physical;
        effect.stat_modifiers[Stats::speed]     = - 10;
        effect.stat_modifiers[Stats::dodge]     = - 10;
        effect.stat_modifiers[Stats::might]     = + 5;
        effect.stat_modifiers[Stats::vitality]  = + 2;
        effect.on_turn_end_fn_offset = Offset(local::On_Turn_End, game_state);
        Add_Dice(&effect, 1, 5);

        instance.effect_offset = Insert_Effect(effect, key, game_state);
    }

    return instance;
}


SIG Effect_Instance Get_Malaria(u64 duration, Entity* source, Game_State* game_state)
{
    Effect_Instance instance = {};
    instance.source = Offset(source, game_state);
    instance.duration_type = Duration_Type::room;
    instance.duration = duration;

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &instance.effect_offset, game_state))
    {
        Effect effect = {};
        effect.name_offset = Offset(STR("Malaria"), game_state);
        effect.type = Effect_Type::disease;
        effect.stat_modifiers[Stats::speed] = - 4;
        effect.critical_failure_range       = + 4;

        instance.effect_offset = Insert_Effect(effect, key, game_state);
    }

    return instance;
}


SIG Effect_Instance Get_Devouring_Plague(u64 duration, Entity* source, Game_State* game_state)
{
    struct local
    {
        static void On_Turn_End(Effect_Instance* instance, Entity* target, Game_State* game_state)
        {
            s32 damage = 1;
            if(instance)
            {
                Deal_Damage(target, instance->source, Effect_Name(instance, game_state), damage, {}, Damage_Type::magical, game_state, Verbose::yes);
            }
            else
            {
                Print("Deals %d points of damage to the inflicted.", damage);
            }
        }
    };

    Effect_Instance instance = {};
    instance.source = Offset(source, game_state);
    instance.duration_type = Duration_Type::room;
    instance.duration = duration;


    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &instance.effect_offset, game_state))
    {
        Effect effect = {};
        effect.name_offset = Offset(STR("Devouring plague"), game_state);
        effect.type = Effect_Type::disease;
        effect.on_turn_end_fn_offset = Offset(local::On_Turn_End, game_state);
        instance.effect_offset = Insert_Effect(effect, key, game_state);
    }

    return instance;
}


SIG Effect_Instance Get_Entangled(u64 duration, Entity* source, Game_State* game_state)
{
    Effect_Instance instance = {};
    instance.source = Offset(source, game_state);
    instance.duration = duration;

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &instance.effect_offset, game_state))
    {
        Effect effect = {};
        effect.name_offset = Offset(STR("Entangled"), game_state);
        effect.type = Effect_Type::physical;
        
        s16 v = 5;
        effect.stat_modifiers[Stats::dodge] = - v;
        effect.stat_modifiers[Stats::armor] = - v;
        effect.thorns_damage                = 1;

        instance.effect_offset = Insert_Effect(effect, key, game_state);
    }

    return instance;
}


SIG Effect_Offset Get_Seed_Effect_Offset(Game_State* game_state)
{
    struct local
    {
        static void On_Turn_End(Effect_Instance* instance, Entity* target, Game_State* game_state)
        {
            s32 change = 10;
            Dice burst_damage_dice = {1, 6};
            if(instance)
            {
                Entity* room = Pointer(target->residence, game_state);
                if(Contains_An_Active_Hostile(room, target, game_state) && game_state->room_count > instance->room_applied)
                {
                    s32 blossom = Roll(change, game_state);
                    u64 trigger = game_state->round - instance->round_applied + 1;
                    bool result = blossom <= trigger;
                    String message1 = Format_Message
                    (
                        game_state, 
                        "%s attempts to blossom [%s]: 1d%d = %d (Success: <= %llu)",
                        Effect_Name(instance, game_state).ptr,
                        (result)? "success" : "failure",
                        change,
                        blossom,
                        trigger
                    );
                    Push_Message(message1, game_state);

                    if(result)
                    {
                        String effect_name = Effect_Name(instance, game_state);
                        String message2 = Format_Message(game_state, "%s blossoms spawning a vineling!", effect_name.ptr);
                        Push_Message(message2, game_state);
                        Create_Vineling(room, game_state);

                        s32 dmg = Roll(burst_damage_dice, game_state);
                        Deal_Damage(target, instance->source, effect_name, dmg, {}, Damage_Type::magical, game_state, Verbose::yes);

                        instance->duration = 1;
                        instance->zero_ticked = true;
                    }
                }
                else
                {
                    instance->round_applied += 1;
                }
            }
            else
            {
                char* format_string = 
                "Starting from the next room after the effect is applied. If there is an active hostile in the room, rolls a 1d%d.\n"
                "\tOn a result greater than or equal to the amount of turns the seed has been implated, \n"
                "\tthe seed blossoms, spawning a vineling and dealing %dd%d points of damage to the host.";

                Print(format_string, change, burst_damage_dice.count, burst_damage_dice.faces);
            }
        }
    };

    Effect_Offset result;
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &result, game_state))
    {
        Effect effect = {};
        effect.name_offset = Offset(STR("Seed"), game_state);
        effect.type = Effect_Type::magic;
        effect.stat_modifiers[Stats::arcane] = + 3;

        effect.on_turn_end_fn_offset = Offset(local::On_Turn_End, game_state);
        result = Insert_Effect(effect, key, game_state);
    }

    return result;
}


SIG Effect_Instance Get_Seed(Entity* source, Game_State* game_state)
{
    Effect_Instance instance = {};
    instance.source = Offset(source, game_state);
    instance.duration = UNLIMITED_DURATION;
    instance.effect_offset = Get_Seed_Effect_Offset(game_state);
    return instance;
}


void On_Hit_Apply_Seed(Effect_Instance* instance, Entity* attacker, Entity* defender, Attack_Record* ar, Game_State* game_state)
{
    if(attacker)
    {
        Attempt_Infection(attacker, defender, Effect_Name(instance, game_state), Get_Seed(attacker, game_state), game_state);
    }
}


SIG Effect_Offset Get_Weak_Grip_Offset(Game_State* game_state)
{
    struct local
    {
        static void Weak_Grip_On_Get_Stat_Effect(Effect_Instance* instance, Entity* actor, Stats::T stat, s32* bonuses, s16* base, Game_State* game_state)
        {
            if(instance)
            {
                if(stat == Stats::might)
                {
                    Entity_Offset item_equiped_in_primary_hand = actor->equipment[Equipment_Slots::primary_hand];
                    if(Entity* item = Pointer(item_equiped_in_primary_hand, game_state))
                    {
                        if(Effect* effect = Pointer(item->on_equip_effect_offset, game_state))
                        {
                            s16 might = effect->stat_modifiers[Stats::might];
                            if(might > 0)
                            {
                                *bonuses -= might;
                                String actor_name = Name(actor, game_state);
                                String item_name = Name(item, game_state);

                                char* format_string = "Weak Grip on %s negates %d might from %s.";
                                String message = Format_Message(game_state, format_string, actor_name.ptr, might, item_name.ptr);

                                Push_Message(message, game_state);
                            }
                        }
                    }
                }
            }
            else
            {
                Print("Negates might benefits from item equipped in primary hand.");
            }
        }
    };

    Effect_Offset result;
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &result, game_state))
    {
        Effect effect = {};
        effect.name_offset = Offset(STR("Weak Grip"), game_state);
        effect.type = Effect_Type::physical;
        effect.on_get_stat_value_fn_offset = Offset(local::Weak_Grip_On_Get_Stat_Effect, game_state);
        result = Insert_Effect(effect, key, game_state);
    }

    return result;
}


SIG void Stun_Attacker(Effect_Instance* instance, Entity* attacker, Entity* defender, Attack_Record* ar, Game_State* game_state)
{
    u8 duration = 1;
    if(instance)
    {
        attacker->stunned += duration;

        String name = Name(attacker, game_state);
        
        char* format_string = "%s is stunned for %d turn.";
        String message = Format_Message(game_state, format_string, name.ptr, duration);
        
        Push_Message(message, game_state);
    }
    else
    {
        Print("Stuns the attacker for %d round(s).", duration);
    }
}


SIG Effect_Instance Reckless_Attack(Entity* attacker, Game_State* game_state)
{
    Effect_Instance instance = {};
    if(attacker)
    {
        Effect* effect = Request_Effect(game_state);
        effect->name_offset = Offset(STR("Reckless attack"), game_state);
        effect->type = Effect_Type::physical;

        s16 v = Level(attacker);
        effect->raw_damage_modifier             += v;
        effect->stat_modifiers[Stats::armor]    -= v;

        instance.effect_offset = Offset(effect, game_state);
        instance.duration = 1;
        instance.zero_ticked = true;
        instance.source = Offset(attacker, game_state);
    }
    else
    {
        Print("gives a raw damage bonus equal to user level, but until the begining of the next round reduces armor by the same amount.");
    }
    
    return instance;
}


SIG Effect_Instance Careful_Attack(Entity* attacker, Game_State* game_state)
{
    s16 fumple_reduction = 5;
    Effect_Instance instance = {};
    if(attacker)
    {
        Effect* effect = Request_Effect(game_state);
        effect->name_offset = Offset(STR("Careful attack"), game_state);
        effect->type = Effect_Type::physical;

        s16 v = Level(attacker);
        effect->raw_damage_modifier             -= v;
        effect->stat_modifiers[Stats::accuracy] += v;
        effect->critical_failure_range          -= s8(fumple_reduction);
        

        instance.effect_offset = Offset(effect, game_state);
        instance.duration = 1;
        instance.duration_type = Duration_Type::attack;
        instance.source = Offset(attacker, game_state);
    }
    else
    {
        Print("gives bonus accuracy equal to user level and reduces fumple range by %d, but reduces damage done equal to user level.", fumple_reduction);
    }
    
    return instance;
}


SIG Effect_Instance Weakspot_Attack(Entity* attacker, Game_State* game_state)
{
    s16 crit_boost = 5;
    Effect_Instance instance = {};
    if(attacker)
    {
        Effect* effect = Request_Effect(game_state);
        effect->name_offset = Offset(STR("Weakspot attack"), game_state);
        effect->type = Effect_Type::physical;

        effect->stat_modifiers[Stats::accuracy] -= Level(attacker);
        effect->critical_success_range          += s8(crit_boost);

        instance.effect_offset = Offset(effect, game_state);
        instance.duration = 1;
        instance.duration_type = Duration_Type::attack;
        instance.source = Offset(attacker, game_state);
    }
    else
    {
        Print("gives %d bonus crit range, but reduces accuracy equal to user level.", crit_boost);
    }
    
    return instance;
}


SIG Effect_Instance Allin_Attack(Entity* attacker, Game_State* game_state)
{
    s16 crit_boost = 10;
    Effect_Instance instance = {};
    if(attacker)
    {
        Effect* effect = Request_Effect(game_state);
        effect->name_offset = Offset(STR("Allin attack"), game_state);
        effect->type = Effect_Type::physical;

        s16 v = Level(attacker);
        effect->stat_modifiers[Stats::accuracy] += v;
        effect->raw_damage_modifier             += v;
        effect->critical_success_range          += s8(crit_boost);
        effect->on_attack_fn_offset             = Offset(Stun_Attacker, game_state);

        instance.effect_offset = Offset(effect, game_state);
        instance.duration = 1;
        instance.duration_type = Duration_Type::attack;
        instance.source = Offset(attacker, game_state);
    }
    else
    {
        Print("gives %d bonus crit range, accuracy aqual to the users level and the same amount of bonus damage, but user is stunned after the attack.", crit_boost);
    }
    
    return instance;
}


SIG Effect_Instance Guarding_Attack(Entity* attacker, Game_State* game_state)
{
    Effect_Instance instance = {};
    if(attacker)
    {
        Effect* effect = Request_Effect(game_state);
        effect->name_offset = Offset(STR("Guarding attack"), game_state);
        effect->type = Effect_Type::physical;

        s16 v = Level(attacker);
        effect->stat_modifiers[Stats::armor]   += v;
        effect->raw_damage_modifier                 -= v;
        
        instance.effect_offset = Offset(effect, game_state);
        instance.duration = 1;
        instance.zero_ticked = true;
        instance.source = Offset(attacker, game_state);
    }
    else
    {
        Print("gives a bonus to armor equal to user level until the begining of next round, but reduces damage done by the same amount.");
    }
    
    return instance;
}


SIG Effect_Instance Evasive_Attack(Entity* attacker, Game_State* game_state)
{
    Effect_Instance instance = {};
    if(attacker)
    {
        Effect* effect = Request_Effect(game_state);
        effect->name_offset = Offset(STR("Evasive attack"), game_state);
        effect->type = Effect_Type::physical;

        s16 v = Level(attacker);
        effect->stat_modifiers[Stats::armor]   -= v;
        effect->stat_modifiers[Stats::dodge]        += v;
        
        instance.effect_offset = Offset(effect, game_state);
        instance.duration = 1;
        instance.zero_ticked = true;
        instance.source = Offset(attacker, game_state);
    }
    else
    {
        Print("gives a bonus to dodge equal to user level, but until the begining of the next round reduces armor by the same amount.");
    }
    
    return instance;
}


SIG Effect_Instance Execute_Attack(Entity* attacker, Game_State* game_state)
{
    struct local
    {
        static s32 Execute_Miss_Experience_Point_Reduction_Multiplier()
        {
            return 2;
        }

        static void Execute_On_Attack(Effect_Instance* instance, Entity* attacker, Entity* defender, Attack_Record* ar, Game_State* game_state)
        {
            s32 mult = Execute_Miss_Experience_Point_Reduction_Multiplier();

            if(instance)
            {
                String message = {};
                if(ar->deal_damage_result.is_killing_blow)
                {
                    message = STR("Execute attack kills the target. Action is Refunded.");
                    attacker->actions |= AT::normal;
                }
                else
                {
                    s32 exp_drain = Level(attacker) * mult;

                    attacker->exp -= exp_drain;
                    
                    String attacker_name = Name(attacker, game_state);
                    char* format_string = "Execute attack did not kill the target. %s loses %d points of experience.";
                    message = Format_Message(game_state, format_string, attacker_name.ptr, exp_drain);
                }
                
                Push_Message(message, game_state);
            }
            else
            {
                Print("If the attack kills the target, refunds the attack action, if not drains %d times level worth of exp from the user.", mult);
            }
        }
    };

    s32 mult = local::Execute_Miss_Experience_Point_Reduction_Multiplier();
    Effect_Instance instance = {};
    if(attacker)
    {
        Effect* effect = Request_Effect(game_state);
        effect->name_offset = Offset(STR("Execute attack"), game_state);
        effect->type = Effect_Type::physical;

        effect->on_attack_fn_offset = Offset(local::Execute_On_Attack, game_state);

        instance.effect_offset = Offset(effect, game_state);
        instance.duration_type = Duration_Type::attack;
        instance.duration = 1;
        instance.source = Offset(attacker, game_state);
    }
    else
    {
        Print("if the strike kills the target, refunds the action, otherwise lose experience points equal to %d times user level.", mult);
    }
    
    return instance;
}


SIG Effect_Instance Disarming_Attack(Entity* attacker, Game_State* game_state)
{
    struct local
    {
        static void Disarming_Attack_On_Hit(Effect_Instance* instance, Entity* attacker, Entity* defender, Attack_Record* ar, Game_State* game_state)
        {
            if(instance)
            {
                if(ar->is_critical_success)
                {
                    if(Entity* weapon = Pointer(defender->equipment[Equipment_Slots::primary_hand], game_state))
                    {
                        // Internals
                        Entity* room = Pointer(defender->residence, game_state);
                        Assert(room);
                        Deep_Insert(weapon, room, game_state);

                        // Message ---
                        String defender_name = Name(defender, game_state);
                        String weapon_name = Name(weapon, game_state);
                        
                        char* format_string = "%s drops his %s on the ground.";
                        String message = Format_Message(game_state, format_string, defender_name.ptr, weapon_name.ptr);
                        
                        Push_Message(message, game_state);
                    }
                }
                else
                {
                    Effect_Instance weak_grip_instance = {};
                    weak_grip_instance.effect_offset = Get_Weak_Grip_Offset(game_state);
                    weak_grip_instance.duration = 1;
                    weak_grip_instance.source = Offset(attacker, game_state);

                    Apply_Effect_Result apply = Apply_Effect(defender, weak_grip_instance, game_state);
                    Push_Generic_Apply_Effect_Message(Effect_Name(instance, game_state), defender, weak_grip_instance, apply, game_state);
                }
            }
            else
            {
                Print("If attack is a critical success the defender is forced to drop the item equipped in their primary hand, otherwise the Weak Grip effect is applied to the defender for 1 turn.");
            }
        }
    };

    Effect_Instance instance = {};
    if(attacker)
    {
        Effect* effect = Request_Effect(game_state);
        effect->name_offset = Offset(STR("Disarming attack"), game_state);
        effect->type = Effect_Type::physical;

        s16 v = Level(attacker);
        effect->flags |= Effect_Flags::has_damage_multiplier;
        effect->damage_multiplier = 0.5f;
        effect->on_hit_fn_offset = Offset(local::Disarming_Attack_On_Hit, game_state);

        instance.effect_offset = Offset(effect, game_state);
        instance.duration_type = Duration_Type::attack;
        instance.duration = 1;
        instance.source = Offset(attacker, game_state);
    }
    else
    {
        Print("on critical hit the opponent is forced to drop the item in his primary hand or, on a requal hit the debuff \"Weak Grip\" is applied to the target for one round, but this attack deals half damage.");
    }
    
    return instance;
}


// Heals for half damage dealt, but at increased fumble. After used can not heal by any other means.
SIG Effect_Instance Vampiric_Attack(Entity* attacker, Game_State* game_state)
{
    struct local
    {
        static void Vampiric_Attack_On_Attack(Effect_Instance* instance, Entity* attacker, Entity* defender, Attack_Record* ar, Game_State* game_state)
        {
            if(instance)
            {
                if(ar->is_hit)
                {
                    u32 healing = Round_To_S32(f32(ar->deal_damage_result.damage_after_mitigation) / 2.f);
                    String effect_name = Effect_Name(instance, game_state);
                    Heal(attacker, healing, effect_name, Verbose::yes, game_state);
                }

                Effect_Instance vampirism_effect_instance = {};
                vampirism_effect_instance.effect_offset = Get_Vampirism_Effect_Offset(game_state);
                vampirism_effect_instance.source = Offset(attacker, game_state);

                Apply_Effect_Result apply = Apply_Effect(attacker, vampirism_effect_instance, game_state);
                Push_Generic_Apply_Effect_Message(Effect_Name(instance, game_state), attacker, vampirism_effect_instance, apply, game_state);
            }
            else
            {
                Print("");
            }
        }
    };

    s8 fumple_boost = 5;
    Effect_Instance instance = {};
    if(attacker)
    {
        Effect_Hash_Key key = EFFECT_KEY;
        if(!Retrive_Effect(key, &instance.effect_offset, game_state))
        {
            Effect effect = {};
            effect.name_offset = Offset(STR("Vampiric attack"), game_state);
            effect.type = Effect_Type::physical;
            effect.on_attack_fn_offset = Offset(local::Vampiric_Attack_On_Attack, game_state);
            effect.critical_failure_range += fumple_boost;
            instance.effect_offset = Insert_Effect(effect, key, game_state);
        }

        instance.duration_type = Duration_Type::attack;
        instance.duration = 1;
        instance.source = Offset(attacker, game_state);
    }
    else
    {
        Print("Heals for half damage dealt, but fumple is increased by %d. After use receive the curse of vampirism.", fumple_boost);
    }
    
    return instance;
}


SIG Effect_Instance Blessed_Attack(Entity* attacker, Game_State* game_state)
{
    struct local
    {
        static f32 Health_Ratio()
        {
            return 0.2f;
        }

        static void Blessed_Attack_On_Apply(Effect_Instance* instance, Entity* entity, Game_State* game_state)
        {
            if(entity)
            {
                s32 amount = Round_To_S32(f32(Max_Health(entity, game_state)) * Health_Ratio());
                Give_Temporary_Health(entity, amount, Effect_Name(instance, game_state), Verbose::yes, game_state);
            }
            else
            {
                Print("gives temporary health equal to %.2f%% of maximum health.", Health_Ratio() * 100.f);
            }
        }

        static void Blessed_Attack_On_Miss(Effect_Instance* instance, Entity* attacker, Entity* defender, Attack_Record* ar, Game_State* game_state)
        {
            if(instance)
            {
                s32 amount = Round_To_S32(f32(Max_Health(attacker, game_state)) * Health_Ratio() * 2.f);
                Deal_Damage
                (
                    attacker, 
                    Offset(attacker, game_state), 
                    Effect_Name(instance, game_state), 
                    amount,
                    0,
                    Damage_Type::magical, 
                    game_state, 
                    Verbose::yes
                );
            }
            else
            {
                Print("Take damage equal to %.2f%% of maximum health.", Health_Ratio() * 200.f);
            }
        }
    };
    

    Effect_Instance instance = {};
    if(attacker)
    {
        Effect_Hash_Key key = EFFECT_KEY;
        if(!Retrive_Effect(key, &instance.effect_offset, game_state))
        {
            Effect effect = {};
            effect.name_offset = Offset(STR("Blessed attack"), game_state);
            effect.type = Effect_Type::physical;
            effect.on_apply_fn_offset = Offset(local::Blessed_Attack_On_Apply, game_state);
            effect.on_miss_fn_offset = Offset(local::Blessed_Attack_On_Miss, game_state);
            instance.effect_offset = Insert_Effect(effect, key, game_state);
        }

        instance.duration_type = Duration_Type::attack;
        instance.duration = 1;
        instance.source = Offset(attacker, game_state);
    }
    else
    {
        Print("on attack gives temporary health equal to %.2f%% of maximum health, but if the attack misses, take damage equal to twice that.", local::Health_Ratio() * 100.f);
    }
    
    return instance;
}


SIG Effect_Instance Berserking_Attack(Entity* attacker, Game_State* game_state)
{
    struct local
    {
        static f32 Dodge_Reduction()
        {
            return 0.5f;
        }

        static void Berserking_Attack_On_Apply(Effect_Instance* instance, Entity* entity, Game_State* game_state)
        {
            if(instance)
            {
                {
                    Effect* effect = Request_Effect(game_state);
                    effect->name_offset = Offset(STR("Single Minded"), game_state);
                    effect->stat_modifiers[Stats::dodge] = (s16)Round_To_S32(Get_Stat_Value(entity, Stats::dodge, game_state) * Dodge_Reduction()) * -1;

                    Effect_Instance dodge_reduction_instance = {};
                    dodge_reduction_instance.effect_offset = Offset(effect, game_state);
                    dodge_reduction_instance.source = instance->source;
                    dodge_reduction_instance.duration = 1;
                    dodge_reduction_instance.zero_ticked = true;

                    Apply_Effect_Result apply = Apply_Effect(entity, dodge_reduction_instance, game_state);
                    Push_Generic_Apply_Effect_Message(Effect_Name(instance, game_state), entity, dodge_reduction_instance, apply, game_state);
                }

                {
                    Effect_Instance enraged = {};
                    enraged.effect_offset = Get_Enraged_Effect_Offset(game_state);
                    enraged.source = instance->source;
                    enraged.zero_ticked = true;
                    enraged.duration = 1;

                    Apply_Effect_Result apply = Apply_Effect(entity, enraged, game_state);
                    Push_Generic_Apply_Effect_Message(Effect_Name(instance, game_state), entity, enraged, apply, game_state);
                }
            }
            else
            {
                Print("applies \"Enraged\" and \"Single Minded\" effects to your self.");
            }
        }
    };
    

    Effect_Instance instance = {};
    if(attacker)
    {
        Effect_Hash_Key key = EFFECT_KEY;
        if(!Retrive_Effect(key, &instance.effect_offset, game_state))
        {
            Effect effect = {};
            effect.name_offset = Offset(STR("Berserking attack"), game_state);
            effect.type = Effect_Type::physical;
            effect.on_apply_fn_offset = Offset(local::Berserking_Attack_On_Apply, game_state);
            instance.effect_offset = Insert_Effect(effect, key, game_state);
        }

        instance.duration_type = Duration_Type::attack;
        instance.duration = 1;
        instance.source = Offset(attacker, game_state);
    }
    else
    {
        Print("apply the \"Enraged\" effect to your self, but reduces dodge by %2.f%%.", local::Dodge_Reduction() * 100.f);
    }
    
    return instance;
}


SIG Effect_Instance Redirect_Attack(Entity* attacker, Game_State* game_state)
{
    struct local
    {
        static void Redirect_Attack_On_Hit(Effect_Instance* instance, Entity* attacker, Entity* defender, Attack_Record* ar, Game_State* game_state)
        {
            if(instance)
            {
                defender->flags |= EFlags::redirected;

                String message = Format_Message(game_state, "%s is redirected.", Name(defender, game_state).ptr);
                Push_Message(message, game_state);
            }
            else
            {
                Print("forces the defender to attack one of its allies (if able) on its next turn.");
            }
        }
    };
    

    Effect_Instance instance = {};
    if(attacker)
    {
        Effect_Hash_Key key = EFFECT_KEY;
        if(!Retrive_Effect(key, &instance.effect_offset, game_state))
        {
            Effect effect = {};
            effect.name_offset = Offset(STR("Redirect attack"), game_state);
            effect.type = Effect_Type::physical;
            effect.flags = Effect_Flags::has_damage_multiplier;
            effect.on_hit_fn_offset = Offset(local::Redirect_Attack_On_Hit, game_state);
            instance.effect_offset = Insert_Effect(effect, key, game_state);
        }

        instance.duration_type = Duration_Type::attack;
        instance.duration = 1;
        instance.source = Offset(attacker, game_state);

        attacker->flags |= EFlags::goes_last;
        String message = Format_Message(game_state, "%s goes last on next initiative.", Name(attacker, game_state).ptr);
        Push_Message(message, game_state);
    }
    else
    {
        Print("Forces the target to attack one of it's allies (if able), but deals no damage and user will go last on next initiative.");
    }
    
    return instance;
}


SIG Effect_Instance Change_Attack(Entity* attacker, Game_State* game_state)
{
    struct local
    {
        static s8 Fumple_Boost()
        {
            return 8;
        }

        static u32 Burn_Duration()
        {
            return 2;
        }

        static void Change_Attack_Apply_Burn_On_Attack(Effect_Instance* instance, Entity* attacker, Entity* defender, Attack_Record* ar, Game_State* game_state)
        {
            if(instance)
            {
                Effect_Instance burning = {};
                burning.source = instance->source;
                burning.effect_offset = Get_Burning_Effect_Offset(game_state);
                burning.duration = Burn_Duration();

                Attempt_Infection(attacker, defender, Effect_Name(instance, game_state), burning, game_state);
            }
            else
            {
                Print("Attemps to set the taget on fire.");
            }
        }
    };
    

    Effect_Instance instance = {};
    if(attacker)
    {
        switch(Roll(3, game_state))
        {
            case 1:
            {
                s32 temp_health_amount = Level(attacker);
                Give_Temporary_Health(attacker, temp_health_amount, STR("Change attack"), Verbose::yes, game_state);
            }break;

            case 2:
            {
                Effect_Hash_Key key = EFFECT_KEY;
                if(!Retrive_Effect(key, &instance.effect_offset, game_state))
                {
                    Effect effect = {};
                    effect.name_offset = Offset(STR("Change attack"), game_state);
                    effect.type = Effect_Type::physical;
                    effect.on_attack_fn_offset = Offset(local::Change_Attack_Apply_Burn_On_Attack, game_state);
                    instance.effect_offset = Insert_Effect(effect, key, game_state);
                }

                instance.source = Offset(attacker, game_state);
                instance.duration_type = Duration_Type::attack;
                instance.duration = 1;
            }break;

            case 3:
            {
                Effect_Hash_Key key = EFFECT_KEY;
                if(!Retrive_Effect(key, &instance.effect_offset, game_state))
                {
                    Effect effect = {};
                    effect.name_offset = Offset(STR("Change attack"), game_state);
                    effect.type = Effect_Type::physical;
                    effect.critical_failure_range += local::Fumple_Boost();
                    instance.effect_offset = Insert_Effect(effect, key, game_state);
                }

                instance.source = Offset(attacker, game_state);
                instance.duration_type = Duration_Type::attack;
                instance.duration = 1;
            }break;

            default:
            {
                Terminate("Unreachable code!");
            }
        }

    }
    else
    {
        Print("does one of 3 differenct effects: A) Resive temporary health equal to user level, B) Give the target the \"burning\" effect for %d turns, C) Increased fumple range of this attack by %d.", local::Burn_Duration(), local::Fumple_Boost());
    }
    
    return instance;
}


SIG Effect_Instance Thieving_Attack(Entity* attacker, Game_State* game_state)
{
    struct local
    {
        static void Thieving_Attack_On_Hit(Effect_Instance* instance, Entity* attacker, Entity* defender, Attack_Record* ar, Game_State* game_state)
        {
            if(instance)
            {
                struct local
                {
                    static bool Can_Be_Stolen(Entity* item, void* user_ptr, Game_State* game_state)
                    {
                        bool result = !Is_Equipped((Entity*)user_ptr, item, game_state);
                        return result;
                    }
                };

                if(Entity* item = Random_Entity_That_Matches_Criteria(&defender->inventory, local::Can_Be_Stolen, defender, game_state))
                {
                    Deep_Insert(item, attacker, game_state);
                    
                    String message = Format_Message
                    (
                        game_state,
                        "%s manages to steal %s from %s.",
                        Name(attacker, game_state).ptr,
                        Name(item, game_state).ptr,
                        Name(defender, game_state).ptr
                    );
                    Push_Message(message, game_state);
                }
                else
                {
                    String message = Format_Message
                    (
                        game_state,
                        "%s cant find anything stealable on %s.", 
                        Name(attacker, game_state).ptr, 
                        Name(defender, game_state).ptr
                    );
                    Push_Message(message, game_state);
                }
            }
            else
            {
                Print("takes a random unequipped item from the targets inventory and places it in the users inventory.");
            }
        }

        static void Thieving_Attack_On_Get_Stat(Effect_Instance* instance, Entity* actor, Stats::T stat, s32* bonuses, s16* base, Game_State* game_state)
        {
            if(instance)
            {
                if(stat == Stats::dodge)
                {
                    *base = 1;
                    *bonuses = 0;
                }
            }
            else
            {
                Print("sets dodge to one.");
            }
        }
    };
    

    Effect_Instance instance = {};
    if(attacker)
    {
        Effect_Hash_Key key = EFFECT_KEY;
        if(!Retrive_Effect(key, &instance.effect_offset, game_state))
        {
            Effect effect = {};
            effect.name_offset = Offset(STR("Thieving attack"), game_state);
            effect.type = Effect_Type::physical;
            effect.flags = Effect_Flags::has_damage_multiplier;
            effect.on_get_stat_value_fn_offset = Offset(local::Thieving_Attack_On_Get_Stat, game_state);
            effect.on_hit_fn_offset = Offset(local::Thieving_Attack_On_Hit, game_state);
            instance.effect_offset = Insert_Effect(effect, key, game_state);
        }

        instance.zero_ticked = true;
        instance.duration = 1;
        instance.source = Offset(attacker, game_state);
    }
    else
    {
        Print("On hit steals one unequipped item from the target, but this attack deals no damage and sets the users dodge to 1 until the start of his next round.");
    }
    
    return instance;
}

//  on crit convert random a lower level enenemy on your side, but on miss enrages all enemies in the room.
SIG Effect_Instance Stylish_Attack(Entity* attacker, Game_State* game_state)
{
    struct local
    {
        static void Stylish_Attack_On_Miss(Effect_Instance* instance, Entity* attacker, Entity* defender, Attack_Record* ar, Game_State* game_state)
        {
            if(instance)
            {
                char* format_string = "The infuriating incompetence of %s causes all his enemies to become enraged!";
                String message = Format_Message(game_state, format_string, Name(attacker, game_state).ptr);
                Push_Message(message, game_state);

                Effect_Instance enraged_instance = {};
                enraged_instance.source = instance->source;
                enraged_instance.effect_offset = Get_Enraged_Effect_Offset(game_state);
                enraged_instance.duration = 1;

                Entity* room = Pointer(attacker->residence, game_state);
                Entity_Iterator iter = Make_Iterator(room, game_state);
                while(Entity* entity = Next_Entity(&iter))
                {
                    if(Is_Living_Enemy_Of(entity, attacker))
                    {
                        Apply_Effect_Result apply = Apply_Effect(entity, enraged_instance, game_state);
                        Push_Generic_Apply_Effect_Message(Effect_Name(instance, game_state), entity, enraged_instance, apply, game_state);
                    }
                }
            }
            else
            {
                Print("applies \"enraged\" to all the users enemies.");
            }
        }

        static void Stylish_Attack_On_Hit(Effect_Instance* instance, Entity* attacker, Entity* defender, Attack_Record* ar, Game_State* game_state)
        {
            struct Package
            {
                Entity* attacker;
                Entity* defender;
            };

            struct local
            {
                static bool Conditional(Entity* entity, void* user_ptr, Game_State* game_state)
                {
                    Package* p = (Package*)user_ptr;
                    bool result = entity != p->defender && Is_Living_Enemy_Of(entity, p->attacker) && Level(entity) < Level(p->attacker);
                    return result;
                }
            };

            if(instance)
            {
                if(ar->is_critical_success)
                {
                    Package p = {attacker, defender};

                    Entity* room = Pointer(attacker->residence, game_state);
                    if(Entity* target = Random_Entity_That_Matches_Criteria(&room->inventory, local::Conditional, &p, game_state))
                    {
                        String message = Format_Message
                        (
                            game_state, 
                            "The power of %s is so convinsing that %s converts to %ss side.",
                            Effect_Name(instance, game_state).ptr,
                            Name(target, game_state).ptr,
                            Name(attacker, game_state).ptr
                        );
                        Push_Message(message, game_state);

                        target->faction = attacker->faction;
                    }
                }
            }
            else
            {
                Print("Converts one random enemy other than the target, that is lower level than the user, to the users faction.");
            }
        }
    };
    

    Effect_Instance instance = {};
    if(attacker)
    {
        Effect_Hash_Key key = EFFECT_KEY;
        if(!Retrive_Effect(key, &instance.effect_offset, game_state))
        {
            Effect effect = {};
            effect.name_offset = Offset(STR("Stylish attack"), game_state);
            effect.type = Effect_Type::physical;
            effect.on_miss_fn_offset = Offset(local::Stylish_Attack_On_Miss, game_state);
            effect.on_hit_fn_offset = Offset(local::Stylish_Attack_On_Hit, game_state);
            instance.effect_offset = Insert_Effect(effect, key, game_state);
        }

        instance.duration_type = Duration_Type::attack;
        instance.duration = 1;
        instance.source = Offset(attacker, game_state);
    }
    else
    {
        Print("on a critical hit converts one random enemy other than the target, that is lower level than the user, to the users faction, but on a miss apply the \"enrage\" effect on all hostiles in the room.");
    }
    
    return instance;
}