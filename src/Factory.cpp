

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


SIG void Add_Dice(Effect* effect, s16 count, s16 faces)
{
    Assert(effect->damage_die.count <= Array_Length(effect->damage_die.unique_die));
    
    Dice* dice = 0;
    for(u16 i = 0; i < effect->damage_die.count; ++i)
    {
        Dice* D = effect->damage_die.unique_die + i;
        
        if(D->faces == faces)
        {
            dice = D;
            break;
        }
    }
    
    if(dice)
    {
        dice->count += count;
    }
    else
    {
        Dice D = {count, faces};
        effect->damage_die.unique_die[effect->damage_die.count] = D;
        effect->damage_die.count += 1;
    }
}


SIG Entity* Create_Class_Adventurer(Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);
    entity->name_offset = Offset(STR("Adventurer"), game_state);
    entity->description_offset = Offset(STR("A well rounded and beginer friendly. Has a good stockpile of supplies."), game_state);
    entity->flags |= EFlags::actor;

    s16* stats = entity->_stats;
    stats[Stats::vitality]      = 7;
    stats[Stats::might]         = 7;
    stats[Stats::dodge]         = 7;
    stats[Stats::accuracy]      = 7;
    stats[Stats::speed]         = 7;
    stats[Stats::perception]    = 7;
    stats[Stats::resistance]    = 1;
    Full_Heal(entity,  game_state);

    entity->known_attack_modifiers |= 
    (
        Attack_Modifier_Mask(Attack_Mod::reckless)  |
        Attack_Modifier_Mask(Attack_Mod::careful)   |
        Attack_Modifier_Mask(Attack_Mod::redirect)   
    );

    Set_Level_Based_On_Stats(entity);
    
    Equip(entity, Create_Dagger(entity, game_state), game_state);
    Equip(entity, Create_Wooden_Shield(entity, game_state), game_state);
    Equip(entity, Create_Backpack(entity, game_state), game_state);
    Equip(entity, Create_Cape_Of_Avoidance(entity, game_state), game_state);
    Equip(entity, Create_Cape_Of_Dashing(entity, game_state), game_state);

    Create_Ring_Of_Just_Fucking_Crit(entity, game_state);

    Create_Antidote(entity, game_state);
    Create_Healing_Potion(entity, game_state);
    Create_Healing_Potion(entity, game_state);
    Create_Healing_Potion(entity, game_state);

    return entity;
}


SIG Entity* Create_Class_Wretched(Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);
    entity->name_offset = Offset(STR("Wretched"), game_state);
    entity->description_offset = Offset(STR("A pathetic and useless class that starts with nothing.\nIt does not get weaker than this."), game_state);
    entity->flags |= EFlags::actor;

    s16* stats = entity->_stats;
    stats[Stats::vitality]      = 1;
    stats[Stats::might]         = 1;
    stats[Stats::dodge]         = 1;
    stats[Stats::accuracy]      = 1;
    stats[Stats::speed]         = 1;
    stats[Stats::perception]    = 1;
    stats[Stats::resistance]    = 1;
    Full_Heal(entity,  game_state);
    Set_Level_Based_On_Stats(entity);
    return entity;
}


SIG Entity* Create_Bandit(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);
    
    entity->name_offset = Offset(STR("Bandit"), game_state);
    entity->description_offset = Offset(STR("A cave dwelling bandit, he looks to be up to no good."), game_state);
    
    entity->flags = EFlags::actor | EFlags::aggressive;
    entity->faction = Faction::bandit;
    entity->weight = 100;
    
    s16* stats = entity->_stats;
    stats[Stats::vitality]      = 5;
    stats[Stats::might]         = 5;
    stats[Stats::dodge]         = 5;
    stats[Stats::accuracy]      = 5;
    stats[Stats::speed]         = 5;
    stats[Stats::perception]    = 5;
    

    Finalize_Entity(entity, room, game_state);

    Equip(entity, Create_Greate_Sword(entity, game_state), game_state, Verbose::no);

    return entity;
}


SIG Entity* Create_Giant_Rat(Entity* room, Game_State* game_state)
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
                        Make_Reference(attacker, game_state)
                    };
                    
                    Apply_Effect_Result apply = Apply_Effect(defender, poison_instance, game_state);
                    Push_Generic_Apply_Effect_Message(instance, defender, poison_instance, apply, game_state);
                }
            }
        }

        static Effect_Offset Get_Blight_Fangs_Effect_Offset(Game_State* game_state)
        {
            EFFECT(&game_state->effects_table.giant_rat_blight_fangs)
            {
                effect.name_offset = Offset(STR("Blight Fangs"), game_state);
                Add_Dice(&effect, 1, 4);
                effect.on_hit_fn_offset = Offset(On_Hit_FN, game_state);

                *target = effect;
            }

            Effect_Offset result = EFFECT_GET_OFFSET_AND_VERIFY_TAG(game_state);

            return result;
        }
    };
    
    entity->name_offset = Offset(STR("Giant rat"), game_state);
    entity->description_offset = Offset(STR("An oversized feral rodent, with murder in its eyes and disease in its fangs."), game_state);

    entity->flags = EFlags::actor | EFlags::aggressive;
    entity->faction = Faction::nature;
    entity->weight = 60;
    
    s16* stats = entity->_stats;
    stats[Stats::vitality]     = 3;
    stats[Stats::might]        = 2;
    stats[Stats::dodge]        = 6;
    stats[Stats::accuracy]     = 6;
    stats[Stats::speed]        = 10;
    stats[Stats::perception]   = 11;
    stats[Stats::resistance]   = 2;
    
    Finalize_Entity(entity, room, game_state);
    
    Effect_Offset effect_offset = local::Get_Blight_Fangs_Effect_Offset(game_state);
    Effect_Instance effect_instance = 
    {
        UNLIMITED_DURATION, 
        effect_offset, 
        Make_Reference(entity, game_state)
    };
    
    Apply_Effect_Result apply = Apply_Effect(entity, effect_instance, game_state);
    Assert(apply == Apply_Effect_Result::success);

    s32 range = 16;
    s32 meat_drop_count = (s32)Roll(range, game_state);
    meat_drop_count = s32(Square_Root(f32(meat_drop_count)) + 0.5f) - 1;
    for(s32 i = 0; i < meat_drop_count; ++i)
    {
        Create_Rat_Meat(entity, game_state);
    }
    

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
    
    Create_Giant_Rat(entity, game_state);
    
    Finalize_Entity(entity, room, game_state);

    return entity;
}


SIG Entity* Create_Spider(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    struct local
    {
        
    };
    
    entity->name_offset = Offset(STR("Spider"), game_state);
    entity->description_offset = Offset(STR(""), game_state);

    entity->flags = EFlags::actor | EFlags::aggressive;
    entity->faction = Faction::nature;
    entity->weight = 30;
    
    s16* stats = entity->_stats;
    stats[Stats::vitality]     = 2;
    stats[Stats::might]        = 4;
    stats[Stats::dodge]        = 10;
    stats[Stats::accuracy]     = 6;
    stats[Stats::speed]        = 10;
    stats[Stats::perception]   = 4;
    stats[Stats::resistance]   = 1;
    
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
    stats[Stats::vitality]     = 10;
    stats[Stats::might]        = 7;
    stats[Stats::dodge]        = 4;
    stats[Stats::accuracy]     = 8;
    stats[Stats::speed]        = 2;
    stats[Stats::perception]   = 0;
    stats[Stats::resistance]   = 8;
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Greate_Sword(Entity* room, Game_State* game_state)
{
    struct local
    {
        static Effect_Offset On_Equip_Effect_Offset(Game_State* game_state)
        {
            EFFECT(&game_state->effects_table.great_sword)
            {
                effect.stat_modifiers[Stats::might] = + 4;
                effect.stat_modifiers[Stats::speed] = - 1;
                
                effect.critical_failure_range += 3;
                
                Add_Dice(&effect, 2, 8);

                *target = effect;
            }

            Effect_Offset result = EFFECT_GET_OFFSET_AND_VERIFY_TAG(game_state);
        
            return result;
        }
    };


    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Great Sword"), game_state);
    entity->description_offset = Offset(STR("A massive sword that requires both hands to wield effectively. A clumsy but destructive weapon."), game_state);
    
    entity->flags = EFlags::equippable;
    
    entity->required_equipment_slots = 
        Equipment_Slots::flag[Equipment_Slots::primary_hand] | 
        Equipment_Slots::flag[Equipment_Slots::secondary_hand];
    
    entity->weight = 5;
    entity->_stats[Stats::vitality] = 3;
    
    entity->on_equip_effect_offset = local::On_Equip_Effect_Offset(game_state);
    
    Finalize_Entity(entity, room, game_state);

    return entity;
}


SIG Entity* Create_Dagger(Entity* room, Game_State* game_state)
{
    // TODO: Dagger should have some sort of effect.

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Dagger"), game_state);
    entity->description_offset = Offset(STR("A small agile blade. Good for sliding through gaps in heavy armor."), game_state);
    
    entity->flags = EFlags::equippable;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::primary_hand];
    
    entity->weight = 2;
    entity->_stats[Stats::vitality] = 4; 
    
    Finalize_Entity(entity, room, game_state);
    
    return entity;
}


SIG Entity* Create_Cape_Of_Avoidance(Entity* room, Game_State* game_state)
{
    struct local
    {
        static Effect_Offset On_Equip_Effect_Offset(Game_State* game_state)
        {
            EFFECT(&game_state->effects_table.cape_of_avoidance)
            {
                effect.stat_modifiers[Stats::dodge]  = + 4;
                *target = effect;
            }
            
            Effect_Offset result = EFFECT_GET_OFFSET_AND_VERIFY_TAG(game_state);
            return result;
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Cape of Avoidance"), game_state);
    entity->description_offset = Offset(STR("A fast flowing cape that blurs the edges of the wearer, making them hard to hit."), game_state);
    
    entity->flags = EFlags::equippable;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::back];
    entity->weight = 1;
    entity->on_equip_effect_offset = local::On_Equip_Effect_Offset(game_state);

    Finalize_Entity(entity, room, game_state);
    
    return entity;
}


SIG Entity* Create_Cape_Of_Dashing(Entity* room, Game_State* game_state)
{
    struct local
    {
        static Effect_Offset On_Equip_Effect_Offset(Game_State* game_state)
        {
            EFFECT(&game_state->effects_table.cape_of_dashing)
            {
                effect.stat_modifiers[Stats::speed]  = + 4;
                *target = effect;
            }
            
            Effect_Offset result = EFFECT_GET_OFFSET_AND_VERIFY_TAG(game_state);
            return result;
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Cape of Dashing"), game_state);
    entity->description_offset = Offset(STR("A short blue triangular cape enchanted with speed enhancing magics."), game_state);
    
    entity->flags = EFlags::equippable;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::back];
    entity->weight = 1;
    entity->on_equip_effect_offset = local::On_Equip_Effect_Offset(game_state);

    Finalize_Entity(entity, room, game_state);
    
    return entity;
}


SIG Entity* Create_Backpack(Entity* room, Game_State* game_state)
{
    struct local
    {
        static Effect_Offset On_Equip_Effect_Offset(Game_State* game_state)
        {
            EFFECT(&game_state->effects_table.backpack)
            {
                effect.stat_modifiers[Stats::speed]     = - 5;
                effect.stat_modifiers[Stats::accuracy]  = - 1;
                effect.carry_capacity_modifier          = + 100;
                *target = effect;
            }
            
            Effect_Offset result = EFFECT_GET_OFFSET_AND_VERIFY_TAG(game_state);
            return result;
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Backpack"), game_state);
    entity->description_offset = Offset(STR("A leather sack with straps to pull our hands through and throw it on your back."), game_state);
    
    entity->flags = EFlags::equippable;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::back];
    
    entity->weight = 5;
    entity->_stats[Stats::vitality] = 2; 
    
    entity->on_equip_effect_offset = local::On_Equip_Effect_Offset(game_state);

    Finalize_Entity(entity, room, game_state);
    
    return entity;
}


SIG Entity* Create_Poison_Dagger(Entity* room, Game_State* game_state)
{
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
                        Make_Reference(attacker, game_state)
                    };

                    Apply_Effect_Result apply = Apply_Effect(defender, poison_instance, game_state);
                    Push_Generic_Apply_Effect_Message(instance, defender, poison_instance, apply, game_state);
                }
            }
            
            // Describe the function here.
            else
            {
                char* str = 
                "%.0f%% change to apply a poison effect. "
                "The poison lasts %llu turns and deals %dd%d damage at the end of affected entities turn.";
                
                Print(str, apply_poison_change * 100, poison_duration, Poison_Damage_Dice().count, Poison_Damage_Dice().faces);
            }
        }
        
        static Effect_Offset On_Equip_Effect_Offset(Game_State* game_state)
        {
            EFFECT(&game_state->effects_table.poison_dagger)
            {
                Add_Dice(&effect, 1, 4);
                effect.stat_modifiers[Stats::might] = + 1;
                effect.stat_modifiers[Stats::speed] = + 1;
                effect.on_hit_fn_offset = Offset(On_Hit_FN, game_state);
                
                *target = effect;
            }
            
            Effect_Offset result = EFFECT_GET_OFFSET_AND_VERIFY_TAG(game_state);
            return result;
        }
    };    

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Poison Dagger"), game_state);
    entity->description_offset = Offset(STR("A tiny blade, that isn't intended for dealing direct damage, but instead to apply a deadly poison."), game_state);
    
    entity->flags = EFlags::equippable;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::primary_hand];
    entity->weight = 2;
    
    entity->on_equip_effect_offset = local::On_Equip_Effect_Offset(game_state);
    
    entity->_stats[Stats::vitality] = 8; 
    
    Finalize_Entity(entity, room, game_state);

    return entity;
}


SIG Entity* Create_Ring_Of_Giants(Entity* room, Game_State* game_state)
{
    struct local
    {
        static Effect_Offset On_Equip_Effect_Offset(Game_State* game_state)
        {
            EFFECT(&game_state->effects_table.ring_of_giants)
            {
                effect.stat_modifiers[Stats::might]    = +10;
                effect.stat_modifiers[Stats::vitality] = +10;
                effect.stat_modifiers[Stats::speed]    = - 5;
                
                *target = effect;
            }

            Effect_Offset result = EFFECT_GET_OFFSET_AND_VERIFY_TAG(game_state);
        
            return result;
        }
    };

    Entity* entity = Request_Entity(game_state);
    
    entity->name_offset = Offset(STR("Ring of Giants"), game_state);
    entity->description_offset = Offset(STR("Grants the wearer the power of giants. This ring is rumored to be forged by the legendary Gill Highant."), game_state);
    
    entity->flags = EFlags::equippable;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::ring_1];
    entity->weight = 50;
    entity->_stats[Stats::vitality] = 50;

    entity->on_equip_effect_offset = local::On_Equip_Effect_Offset(game_state);
    
    Finalize_Entity(entity, room, game_state);

    
    return entity;
}


SIG Entity* Create_Ring_Of_Strange_Fortunes(Entity* room, Game_State* game_state)
{
    struct local
    {
        static Effect_Offset On_Equip_Effect_Offset(Game_State* game_state)
        {
            EFFECT(&game_state->effects_table.ring_of_strange_fortunes)
            {
                effect.critical_success_range = +10;
                effect.critical_failure_range = +10;
                
                *target = effect;
            }

            Effect_Offset result = EFFECT_GET_OFFSET_AND_VERIFY_TAG(game_state);
        
            return result;
        }
    };
    
    Entity* entity = Request_Entity(game_state);
   
    entity->name_offset = Offset(STR("Ring of Strange Fortunes"), game_state);
    entity->description_offset = Offset(STR("A ring that is both cursed and blessed. Who would create such a thing?"), game_state);
    
    entity->flags = EFlags::equippable;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::ring_1];
    entity->weight = 1;

    entity->on_equip_effect_offset = local::On_Equip_Effect_Offset(game_state);
    
    Finalize_Entity(entity, room, game_state);

    return entity;
}


SIG Entity* Create_Ring_Of_Rebirth(Entity* room, Game_State* game_state)
{
    struct local
    {
        static void Rebirth(Effect_Instance* instance, Reference attacker, Entity* defender, Deal_Damage_Result* ddr, Game_State* game_state)
        {
            if(instance)
            {
                Entity* ring = Dereference(instance->source, game_state);
                if(ring && ring->interactable.uses_count && ddr->is_killing_blow)
                {
                    Full_Heal(defender, game_state);
                    String defender_name = Name(defender, game_state);
                    ring->interactable.uses_count -= 1;

                    String description = STR("Once a legendary ring that could bring it's wearer back to life... now devoid of its former magic.");
                    ring->description_offset = Offset(description, game_state);

                    char* format_string = "Ring of Rebirth brings %s back to life consuming it self in the process. What was on the other side the curtain?";
                    String message = Format_Message(game_state, format_string, defender_name.ptr);

                    Push_Message(message, game_state);
                }
            }
            else
            {
                Print("If the wearer dies, energy from the ring is transfared into the wearer consuming the ring and brining the wearer back to life.");
            }
        }

        static Effect_Offset On_Equip_Effect_Offset(Game_State* game_state)
        {
            EFFECT(&game_state->effects_table.ring_of_rebirth)
            {
                effect.on_damage_taken_fn_offset = Offset(Rebirth, game_state);
                *target = effect;
            }

            Effect_Offset result = EFFECT_GET_OFFSET_AND_VERIFY_TAG(game_state);
        
            return result;
        }
    };


    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Ring of Rebirth"), game_state);
    entity->description_offset = Offset(STR("Legendary ring; crafted in a twisted ritual where a Phoenex was brutally sacrificed and its essence molded into a ring."), game_state);
    
    entity->flags = EFlags::equippable;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::ring_1];
   

    entity->weight                      = 30;
    entity->_stats[Stats::vitality]     = 10;
    entity->_stats[Stats::resistance]   = 100;
    entity->interactable.uses_count     = 1;


    entity->on_equip_effect_offset = local::On_Equip_Effect_Offset(game_state);
    
    Finalize_Entity(entity, room, game_state);
    
    return entity;
}


SIG Entity* Create_Ring_Of_Regeneration(Entity* room, Game_State* game_state)
{
    struct local
    {
        static void Regeneration_On_Turn_Start_FN(Effect_Instance* instance, Entity* target, Game_State* game_state)
        {
            s32 healing_amount = 2;
            
            if(target)
            {
                Heal(target, healing_amount, Effect_Name(instance, game_state), Verbose::yes, game_state);
            }
            else
            {
                Print("Heals the wearer %d points of health.", healing_amount);
            }
        }
        

        static Effect_Offset On_Equip_Effect_Offset(Game_State* game_state)
        {
            EFFECT(&game_state->effects_table.ring_of_regenaration)
            {
                effect.on_turn_start_fn_offset = Offset(Regeneration_On_Turn_Start_FN, game_state);
                *target = effect;
            }

            Effect_Offset result = EFFECT_GET_OFFSET_AND_VERIFY_TAG(game_state);
        
            return result;
        }
    };
    
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Ring of Regeneration"), game_state);
    entity->description_offset = Offset(STR("Ring with a warm yellow glow. It has been blessed by a cleric giving it powers of healing."), game_state);
    
    entity->flags = EFlags::equippable;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::ring_1];
    entity->weight = 1;
    
    entity->on_equip_effect_offset = local::On_Equip_Effect_Offset(game_state);
    
    Finalize_Entity(entity, room, game_state);  

    return entity;
}


SIG Entity* Create_Antidote(Entity* container, Game_State* game_state)
{
    struct local
    {
        static void on_use_fn(Entity* entity, Entity* target, Game_State* game_state)
        {
            Effect_Type::T type = Effect_Type::poison;

            if(entity)
            {
                u64 removed_count = Remove_Effects_Of_Type(target, type, game_state, Verbose::yes);
                if(!removed_count)
                {
                    Print("\n%s wasn't under the the effect of any %s.", Name(target, game_state).ptr, Effect_Type::names[type].ptr);
                }
            }
            else
            {
                Print("Removes all effects of type: %s", Effect_Type::names[type].ptr);
            }
        }
    };


    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Antidote"), game_state);
    entity->description_offset = Offset(STR("An amber colored concuction that serves as a remedy to all things poison."), game_state);
    entity->weight = 1;

    entity->flags = EFlags::interactable;

    entity->interactable.on_use_fn_offset = Offset(local::on_use_fn, game_state);
    entity->interactable.on_empty_fn_offset = Offset(Delete_Entity, game_state);
    entity->interactable.uses_count = 1;

    Finalize_Entity(entity, container, game_state);

    return entity;
}


SIG Entity* Create_Healing_Potion(Entity* container, Game_State* game_state)
{
    struct local
    {
        static void on_use_fn(Entity* entity, Entity* target, Game_State* game_state)
        {
            s16 dice_faces = 6;

            if(target)
            {
                s16 base = Level(target);
                Dice dice = {base, dice_faces};
                Arena_Snapshot snapshot = Snapshot(&game_state->scratch_buffer);

                s32* dice_results = Roll_With_Record(dice, game_state);

                s32 potency = base + *dice_results;

                // Healing potion potency is: %d (%d + %dd%d = %d[%d, %d])
                Arena* arena = &game_state->messages_buffer;

                // NOTE: String construction in this language is rough... Would have been a bit easier in Python for instance.
                // Though I think the conditional in there would mean that you'd still need a loop. But you could just apped the string together.
                // This though is fast! No memory allocations really happening here.

                u64 length = 0;
                char* message_base = Push_String(arena, STR("Healing potion potency is: "), &length);
                
                U64_To_String_Memory m;
                Push_String(arena, To_String(u64(potency), &m), &length);
                Push_String(arena, STR(" ("), &length);
                Push_String(arena, To_String(u64(base), &m), &length);
                Push_String(arena, STR(" + "), &length);
                Push_String(arena, To_String(u64(dice.count), &m), &length);
                Push_String(arena, STR("d"), &length);
                Push_String(arena, To_String(u64(dice.faces), &m), &length);
                Push_String(arena, STR(" = "), &length);
                Push_String(arena, To_String(u64(*dice_results), &m), &length);
                if(dice.count > 1)
                {
                    Push_String(arena, STR("["), &length);
                    for(u64 i = 0; i < dice.count; ++i)
                    {
                        if(i > 0)
                        {
                            Push_String(arena, STR(", "), &length);
                        }
                        Push_String(arena, To_String(u64(dice_results[i + 1]), &m), &length);
                    }
                    Push_String(arena, STR("]"), &length);
                }
                Push_String(arena, STR(")"), &length);

                Push(arena, 1); // null terminator!
                String message = {message_base, length};
                
                Assert(Null_Terminated_Length(message_base) == length + 1);
                Restore(&game_state->scratch_buffer, snapshot);
                
                Push_Message(message, game_state);
                String source_name = Name(entity, game_state);
                Heal(target, potency, source_name, Verbose::yes, game_state);
            }
            else
            {
                Print("Heals the user by: (lvl) + (lvl)d%d.", dice_faces);
            }
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Healing Potion"), game_state);
    entity->description_offset = Offset(STR("Before The Fall these were very common, but now the magic that was used to create them is lost. Valued by all."), game_state);
    entity->weight = 1;

    entity->flags = EFlags::interactable;

    entity->interactable.on_use_fn_offset = Offset(local::on_use_fn, game_state);
    entity->interactable.on_empty_fn_offset = Offset(Delete_Entity, game_state);
    entity->interactable.uses_count = 1;

    Finalize_Entity(entity, container, game_state);

    return entity;
}


SIG Entity* Create_Custom_Ring(Entity* room, Game_State* game_state, String name)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(name, game_state);
    entity->description_offset = Offset(STR("A beautiful ring."), game_state);
    
    entity->flags = EFlags::equippable;
    
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::ring_1];
    entity->weight = 1;
    
    s16* stats = entity->_stats;
    
    Finalize_Entity(entity, room, game_state);
    
    return entity;
}


SIG Entity* Create_Gloves_Of_Brutality(Entity* room, Game_State* game_state)
{
    struct local
    {
        static Effect_Offset On_Equip_Effect_Offset(Game_State* game_state)
        {
            EFFECT(&game_state->effects_table.gloves_of_brutality)
            {
                effect.stat_modifiers[Stats::resistance] = + 2;
                Add_Dice(&effect, 2, 6);
                Add_Dice(&effect, 7, 12);
                Add_Dice(&effect, 8, 5);
                Add_Dice(&effect, 4, 20);
                
                *target = effect;
            }

            Effect_Offset result = EFFECT_GET_OFFSET_AND_VERIFY_TAG(game_state);
        
            return result;
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Gloves of Brutality"), game_state);
    entity->description_offset = Offset(STR("Spiked leather gloves with a strange red glow around them."), game_state);
    
    entity->flags = EFlags::equippable;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::gloves];
    entity->weight = 3;

    entity->on_equip_effect_offset = local::On_Equip_Effect_Offset(game_state);
    
    Finalize_Entity(entity, room, game_state);

    return entity;
}


SIG Entity* Create_Wooden_Shield(Entity* room, Game_State* game_state)
{
    struct local
    {
        static Effect_Offset On_Equip_Effect_Offset(Game_State* game_state)
        {
            EFFECT(&game_state->effects_table.wooden_shield)
            {
                effect.stat_modifiers[Stats::resistance] = + 5;
                
                *target = effect;
            }

            Effect_Offset result = EFFECT_GET_OFFSET_AND_VERIFY_TAG(game_state);
        
            return result;
        }
    };
    

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Wooden Shield"), game_state);
    entity->description_offset = Offset(STR("A Shield made out of wooden planks. It does not seem very effective."), game_state);
    
    entity->flags = EFlags::equippable;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::secondary_hand];
    entity->weight = 8;
    entity->_stats[Stats::vitality] = 10;
    
    entity->on_equip_effect_offset = local::On_Equip_Effect_Offset(game_state);
    
    Finalize_Entity(entity, room, game_state);
    
    return entity;
}


SIG Entity* Create_Room(Game_State* game_state)
{
    Entity* room = Request_Entity(game_state);

    room->name_offset = Offset(STR("The World"), game_state);
    room->description_offset = Offset(STR("The container for all things that exist."), game_state);
    
    return room;
}


SIG void Generate_Entrace_Room(Entity* room, Game_State* game_state)
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
}


SIG Room_Generator_Element_Array Caves()
{
    struct local
    {
        static void Wildlife(Entity* room, Game_State* game_state)
        {
            struct local
            {
                static void Opening(Entity* room, Game_State* game_state)
                {
                    room->name_offset = Offset(STR("a wide opening"), game_state);
                    
                    char room_description[] = 
                    "The stone walls extend into the unseeable darkness. "
                    "The ceiling must be very far away. " 
                    "In the black you can see bright glowing eyes moving towards you.";
                    room->description_offset = Offset(STR(room_description), game_state);

                    LOOP(1 + Roll(2, game_state))   Create_Giant_Rat(room, game_state);
                    if(Roll(3, game_state) == 1)    Create_Rat_Mound(room, game_state);
                }

                static void Bear_Nest(Entity* room, Game_State* game_state)
                {
                    room->name_offset = Offset(STR("a foul smelling nest"), game_state);
                    
                    char room_description[] = 
                    "In the middle of the room there is what looks to you to be a \"bed\" of sorts made by a large animal. "
                    "It's made of tree branches and leaves. Around the bed there are many half eaten carcasses. "
                    "Some of animals, others human... or humanoid";
                    room->description_offset = Offset(STR(room_description), game_state);
                    
                    if(Roll(8, game_state) == 1)
                    {

                    }
                    else
                    {
       
                    }

                    
                    Warn("Unimplemented room");
                }

                static void Hallway(Entity* room, Game_State* game_state)
                {
                    room->name_offset = Offset(STR("a hallway"), game_state);
                    
                    char room_description[] = 
                    "It appears to be a long corridor. The ceiling here is held up by pillars.";
                    room->description_offset = Offset(STR(room_description), game_state);

                    
                    Warn("Unimplemented room");
                }

                static void Altar(Entity* room, Game_State* game_state)
                {
                    room->name_offset = Offset(STR("a circular"), game_state);
                    
                    char room_description[] = 
                    "The walls in this room feel un-naturally smooth, perhaps dwarwen make? "
                    "In the center there is what appears to be an altar to God unknown to you. "
                    "You can \"use\" the altar to seek a blessing from this deity.";
                    room->description_offset = Offset(STR(room_description), game_state);

                    
                    Warn("Unimplemented room");
                }

                static void Safe_Room(Entity* room, Game_State* game_state)
                {
                    room->name_offset = Offset(STR("a small side room"), game_state);
                    
                    char room_description[] = 
                    "A small well hidden room a little bit off the main path. "
                    "There is hay pilled up on the floor. It looks like some has slept here.";
                    room->description_offset = Offset(STR(room_description), game_state);

                    
                    Warn("Unimplemented room");
                }

                static void Rat_Nest(Entity* room, Game_State* game_state)
                {
                    room->name_offset = Offset(STR("a rat nest"), game_state);
                    
                    char room_description[] = 
                    "A large room. The walls are covered in rat-sized holes. "
                    "You can see movement every where, eyes flickering and tails slithering. "
                    "The floor is filled with bones of mostly small creatures and rat droppings. "
                    "You get a sensation that this is not a good place to be.";
                    room->description_offset = Offset(STR(room_description), game_state);

                    LOOP(2 + Roll(3, game_state))   Create_Giant_Rat(room, game_state);
                    LOOP(1 + Roll(2, game_state))   Create_Rat_Mound(room, game_state);
                }
            };

            Room_Generator_Element options[] = 
            {
                {local::Opening,        10},
                {local::Hallway,        10},
                {local::Safe_Room,      05},
                {local::Rat_Nest,       03},
                {local::Bear_Nest,      04},
                {local::Altar,          07},
            };
            Pick_Room_Generator({options, Array_Length(options)}, game_state).fn(room, game_state);
        }

        static void Bandits(Entity* room, Game_State* game_state)
        {
            Create_Bandit(room, game_state);
        }

        static void Spiders(Entity* room, Game_State* game_state)
        {
            Create_Spider(room, game_state);
        }

        static void Boss(Entity* room, Game_State* game_state)
        {
            game_state->distance_travelled = -1;
            Create_Boss_Spider(room, game_state);
        }
    };

    local_storage Room_Generator_Element rooms[] = 
    {
        {local::Wildlife,   12},
        {local::Bandits,    8},
        {local::Spiders,    8},
        {local::Boss,       0}
    };

    Room_Generator_Element_Array result = {rooms, Array_Length(rooms)};
    return result;
}


/// DEVELOPPER ITEMS: 
SIG Entity* Create_Ring_Of_Just_Fucking_Crit(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);
   
    entity->name_offset = Offset(STR("Ring of Just Fucking CRIT!"), game_state);
    entity->description_offset = Offset(STR("When you just don't want to leave landing a critical hit up to change."), game_state);
    
    entity->flags = EFlags::equippable;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::ring_1];
    entity->weight = 1;

    Effect* effect = Request_Effect(game_state);
    effect->critical_success_range += S8_MAX;
    entity->on_equip_effect_offset = Offset(effect, game_state);
    
    Finalize_Entity(entity, room, game_state);

    return entity;
}