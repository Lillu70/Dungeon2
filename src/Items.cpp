
// ===================================
// Copyright (c) 2025 by Valtteri Kois
// All rights reserved.
// ===================================

// REMEMBER TO UPDATE DAMAGE VALUES FROM THE SPREAD SHEET!

// Nyxm ring idea: Ring of Unstable Combustion
// H.M. : What's not to love, I either live to explode another day or i can explode twice.
// Deals damage to everything in the room 6 charges, roll a 1d(chareges) == 1 Damage is also applied to you.
// Damage: 15 + [arcane]
// Rarity: epic

// Ring of False Hope
// 1 charges, resurect at 1d(HP) health.
// What's the worst thing that can happen? I die twice?!
// Rarity: epic


// Effect idea: On turn end stun a random entity in the room.


#include "Skill_Books.cpp" // NOTE: Generated file!


SIG Loot_Table Basic_Foods_Loot_Table(Game_State* game_state)
{
    local_storage Loot_Table_Entry entries[] =
    {
        {Create_Mushroom},
        {Create_Bread},
        {Create_Jerky},
        {Create_BBQ_Wings},
        {Create_Steak_And_Smashed_Potatoes},
    };

    local_storage Loot_Table table = {entries, Array_Length(entries)};
    Fill_Loot_Table_Changes_And_Item_Rarity(&table, game_state);

    return table;
}


SIG Loot_Table Basic_Consumables_Loot_Table(Game_State* game_state)
{
    local_storage Loot_Table_Entry entries[] =
    {
        {Create_Antidote},
        {Create_Healing_Potion},
        {Create_Bomb},
        {Create_Fragmentation_Bomb},
    };

    local_storage Loot_Table table = {entries, Array_Length(entries)};
    Fill_Loot_Table_Changes_And_Item_Rarity(&table, game_state);

    return table;
}


SIG Loot_Table Basic_Trinkets_Loot_Table(Game_State* game_state)
{
    local_storage Loot_Table_Entry entries[] =
    {
        {Create_Ring_Of_Giants},
        {Create_Ring_Of_Rebirth},
        {Create_Ring_Of_Regeneration},
        {Create_Ring_Of_Strange_Fortunes},
        {Create_Cape_Of_Dashing},
        {Create_Cape_Of_Avoidance},
        {Create_Cape_Of_Immunity},
        {Create_Arcane_Cape},
        {Create_Cape_Of_Spite},
    };

    local_storage Loot_Table table = {entries, Array_Length(entries)};
    Fill_Loot_Table_Changes_And_Item_Rarity(&table, game_state);

    return table;
}


SIG Loot_Table Basic_Armors_Loot_Table(Game_State* game_state)
{
    local_storage Loot_Table_Entry entries[] =
    {
        {Create_Wooden_Shield},
        {Create_Buckler},
        {Create_Kite_Shield},
        {Create_Shearing_Light},
        {Create_Barn_Door_Shield},
        {Create_Tower_Shield},
        {Create_Leather_Cuirass},
        {Create_Gambeson},
        {Create_Breastplate},
        {Create_Skull_Cap},
        {Create_Arming_Cap},
        {Create_Chainmail_Hood},
        {Create_Barbute},
        {Create_Plate_Leggings},
        {Create_Leather_Tights},
        {Create_Padded_Pants},
        {Create_Warrior_Kilt},
        {Create_Barbarian_Loing_Cloth},
        {Create_Travel_Boots},
        {Create_Sabatons},
        {Create_Gladiator_Sandals},
        {Create_Leather_Boots},
        {Create_Gloves_Of_Brutality},
        {Create_Leather_Gloves},
        {Create_Chainmail_Gloves},
        {Create_Plate_Gloves},
    };

    local_storage Loot_Table table = {entries, Array_Length(entries)};
    Fill_Loot_Table_Changes_And_Item_Rarity(&table, game_state);

    return table;
}


SIG Loot_Table Basic_Weapons_Loot_Table(Game_State* game_state)
{
    local_storage Loot_Table_Entry entries[] =
    {
        {Create_Great_Sword},
        {Create_Halberd},
        {Create_Great_Club},
        {Create_Magma_Hammer},
        {Create_Dagger},
        {Create_Poison_Dagger},
        {Create_War_Pick},
        {Create_Mace},
        {Create_Morning_Star},
        {Create_Three_Headed_Flail},
        {Create_Straightsword},
        {Create_Long_Spear},
        {Create_Whip},
    };

    local_storage Loot_Table table = {entries, Array_Length(entries)};
    Fill_Loot_Table_Changes_And_Item_Rarity(&table, game_state);

    return table;
}


SIG Loot_Table Basic_Merged_Loot_Table(Game_State* game_state)
{
    Loot_Table result = Merge_Loot_Tables
    (
        Basic_Weapons_Loot_Table(game_state),
        Basic_Armors_Loot_Table(game_state),
        Basic_Trinkets_Loot_Table(game_state),
        Basic_Consumables_Loot_Table(game_state),
        Basic_Foods_Loot_Table(game_state),
        Skill_Books_Loot_Table(game_state),
        &game_state->scratch_buffer
    );

    return result;
}


SIG Entity* Create_Great_Sword(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Great Sword"), game_state);
    entity->description_offset = Offset(STR("A massive sword that requires both hands to wield. A clumsy but destructive weapon."), game_state);
    
    entity->flags = EFlags::equippable | EFlags::item;
    
    entity->required_equipment_slots = 
        Equipment_Slots::flag[Equipment_Slots::primary_hand] | 
        Equipment_Slots::flag[Equipment_Slots::secondary_hand];
    
    entity->weight = 7;
    entity->_stats[Stats::vitality] = 3;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::might] = + 6;
        effect.stat_modifiers[Stats::speed] = - 1;
        effect.critical_failure_range       = + 3;
        Add_Dice(&effect, 2, 8);
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Halberd(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Halberd"), game_state);
    entity->description_offset = Offset(STR("A polearm featuring both a spide end and an axe head."), game_state);
    
    entity->flags = EFlags::equippable | EFlags::item;
    
    entity->required_equipment_slots = 
        Equipment_Slots::flag[Equipment_Slots::primary_hand] | 
        Equipment_Slots::flag[Equipment_Slots::secondary_hand];
    
    entity->weight = 9;
    entity->_stats[Stats::vitality] = 3;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.pierce                       = + 4;
        effect.stat_modifiers[Stats::might] = + 6;
        effect.stat_modifiers[Stats::speed] = + 2;
        effect.critical_failure_range       = + 2;
        Add_Dice(&effect, 1, 16);
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Long_Spear(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Long spear"), game_state);
    entity->description_offset = Offset(STR("A long stick with a sharp metal end."), game_state);
    
    entity->flags = EFlags::equippable | EFlags::item;
    
    entity->required_equipment_slots = 
        Equipment_Slots::flag[Equipment_Slots::primary_hand] | 
        Equipment_Slots::flag[Equipment_Slots::secondary_hand];
    
    entity->weight = 6;
    entity->_stats[Stats::vitality] = 3;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.pierce                       = + 14;
        effect.stat_modifiers[Stats::might] = + 5;
        effect.stat_modifiers[Stats::speed] = + 5;
        effect.critical_success_range       = + 4;
        Add_Dice(&effect, 1, 6);
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Great_Club(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Great club"), game_state);
    entity->description_offset = Offset(STR("Basicly a tree with its branches cut off."), game_state);
    
    entity->flags = EFlags::equippable | EFlags::item;
    
    entity->required_equipment_slots = 
        Equipment_Slots::flag[Equipment_Slots::primary_hand] | 
        Equipment_Slots::flag[Equipment_Slots::secondary_hand];
    
    entity->weight = 20;
    entity->_stats[Stats::vitality] = 20;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::might]     = + 16;
        effect.stat_modifiers[Stats::speed]     = - 3;
        effect.stat_modifiers[Stats::accuracy]  = + 2;
        effect.critical_failure_range           = + 8;
        Add_Dice(&effect, 1, 3);
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Magma_Hammer(Entity* room, Game_State* game_state)
{
    struct local
    {
        void static On_Hit(Effect_Instance* instance, Entity* attacker, Entity* defender, Attack_Record* ar, Game_State* game_state)
        {
            s32 splash_damage = 3;
            s32 burning_duration = 3;
            if(instance)
            {
                String effect_name = Effect_Name(instance, game_state);

                Effect_Instance burning = {};
                burning.effect_offset = Get_Burning_Effect_Offset(game_state);
                burning.duration = burning_duration;
                burning.source = Offset(attacker, game_state);

                Apply_Effect_Result apply = Apply_Effect(defender, burning, game_state);
                Push_Generic_Apply_Effect_Message(effect_name, defender, burning, apply, game_state);

                Entity_Iterator iter = Make_Iterator(Pointer(defender->residence, game_state), game_state);
                while(Entity* entity = Next_Entity(&iter))
                {
                    if(entity != defender && Is_Living_Enemy_Of(entity, attacker))
                    {
                        Deal_Damage(entity, attacker, effect_name, splash_damage, 0, Damage_Type::magical, game_state, Verbose::yes);
                    }
                }
            }
            else
            {
                Print("Sets the target on fire for %d turns and deals %d points of splash damage to every other hostile in the room.", burning_duration, splash_damage);
            }
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Magma Hammer"), game_state);
    entity->description_offset = Offset(STR("Forged from abyssal steel. This hammer never cools down and the weight still looks molten."), game_state);
    entity->rarity = Rarity::epic;

    entity->flags = EFlags::equippable | EFlags::item;
    
    entity->required_equipment_slots = 
        Equipment_Slots::flag[Equipment_Slots::primary_hand] | 
        Equipment_Slots::flag[Equipment_Slots::secondary_hand];
    
    entity->weight = 25;
    entity->_stats[Stats::vitality] = 100;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::might]     = + 7;
        effect.critical_failure_range           = + 3;
        Add_Dice(&effect, 2, 10);
        effect.on_hit_fn_offset = Offset(local::On_Hit, game_state);
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_War_Pick(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("War pick"), game_state);
    entity->description_offset = Offset(STR("Basically; a giant spike strapped on to the end of a stick. Effective against heavily armored targets."), game_state);
    entity->rarity = Rarity::rare;

    entity->flags = EFlags::equippable | EFlags::item;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::primary_hand];
    
    entity->weight = 5;
    entity->_stats[Stats::vitality] = 5;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.pierce                        = + 6;
        effect.stat_modifiers[Stats::might]  = + 4;
        Add_Dice(&effect, 1, 6);
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }

    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Straightsword(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Straightsword"), game_state);
    entity->description_offset = Offset(STR("A medium sized sword intended for warfare."), game_state);
    
    entity->flags = EFlags::equippable | EFlags::item;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::primary_hand];
    
    entity->weight = 4;
    entity->_stats[Stats::vitality] = 3;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::might]  = + 4;
        Add_Dice(&effect, 1, 8);
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }

    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Whip(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Whip"), game_state);
    entity->description_offset = Offset(STR("Good for horses, questionable for fighting, but excpetialy motivating."), game_state);
    
    entity->flags = EFlags::equippable | EFlags::item;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::primary_hand];
    
    entity->weight = 2;
    entity->_stats[Stats::vitality] = 3;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::might] = + 2;
        effect.stat_modifiers[Stats::dodge] = + 4;
        effect.stat_modifiers[Stats::speed] = + 7;
        effect.critical_failure_range       = + 6;
        Add_Dice(&effect, 2, 4);
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }

    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Mace(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Mace"), game_state);
    entity->description_offset = Offset(STR("A tool for bludgeoning."), game_state);
    
    entity->flags = EFlags::equippable | EFlags::item;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::primary_hand];
    
    entity->weight = 10;
    entity->_stats[Stats::vitality] = 3;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::might]  = + 8;
        Add_Dice(&effect, 1, 2);
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }

    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Rapier(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Rapier"), game_state);
    entity->description_offset = Offset(STR("A very thing blade. Only the tip is sharp."), game_state);
    entity->rarity = Rarity::rare;

    entity->flags = EFlags::equippable | EFlags::item;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::primary_hand];
    
    entity->weight = 4;
    entity->_stats[Stats::vitality] = 2;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::accuracy] = + 3;
        effect.stat_modifiers[Stats::might]    = + 4;
        effect.critical_success_range          = + 6;
        effect.critical_failure_range          = + 2;
        Add_Dice(&effect, 1, 6);
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }

    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Short_Spear(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Short spear"), game_state);
    entity->description_offset = Offset(STR("Short enough to be used with one hand."), game_state);

    entity->flags = EFlags::equippable | EFlags::item;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::primary_hand];
    
    entity->weight = 5;
    entity->_stats[Stats::vitality] = 2;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::speed] = + 5;
        effect.stat_modifiers[Stats::might] = + 4;
        effect.pierce                       = + 4;
        Add_Dice(&effect, 1, 6);
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }

    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Morning_Star(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Morning star"), game_state);
    entity->description_offset = Offset(STR("A heavy spiked ball attached to a shaft."), game_state);
    entity->rarity = Rarity::rare;

    entity->flags = EFlags::equippable | EFlags::item;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::primary_hand];
    
    entity->weight = 14;
    entity->_stats[Stats::vitality] = 2;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.pierce                       = + 3;
        effect.stat_modifiers[Stats::might] = + 9;
        Add_Dice(&effect, 1, 2);
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }

    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Three_Headed_Flail(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Three headed flail"), game_state);
    entity->description_offset = Offset(STR("It's a flail, but with more balls! And the balls are spikey."), game_state);
    entity->rarity = Rarity::epic;

    entity->flags = EFlags::equippable | EFlags::item;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::primary_hand];
    
    entity->weight = 10;
    entity->_stats[Stats::vitality] = 2;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.pierce                       = + 5;
        effect.stat_modifiers[Stats::might] = + 5;
        Add_Dice(&effect, 3, 5);
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }

    Finalize_Entity(entity, room, game_state);
    return entity;
}



SIG Entity* Create_Dagger(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Dagger"), game_state);
    entity->description_offset = Offset(STR("A small agile blade. Good for sliding through gaps in heavy armor."), game_state);
    
    entity->flags = EFlags::equippable | EFlags::item;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::primary_hand];
    
    entity->weight = 2;
    entity->_stats[Stats::vitality] = 4; 
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.critical_success_range        = + 2;
        effect.stat_modifiers[Stats::might]  = + 3;
        effect.stat_modifiers[Stats::speed]  = + 1;
        effect.pierce                        = 2;
        Add_Dice(&effect, 1, 4);
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }

    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Poison_Dagger(Entity* room, Game_State* game_state)
{
    struct local
    {
        static void On_Hit(Effect_Instance* instance, Entity* attacker, Entity* defender, Attack_Record* ar, Game_State* game_state)
        {
            u64 poison_duration = 4;
            
            if(attacker)
            {
                Attempt_Infection(attacker, defender, Effect_Name(instance, game_state), Get_Poison(poison_duration, attacker, game_state), game_state);
            }
            else
            {
                char* format_string = 
                "Attempt to apply poison target.\n"
                "The poison lasts %llu turns and deals %dd%d damage at the end of affected entities turn.";
                
                Print(format_string, poison_duration, Poison_Damage_Dice().count, Poison_Damage_Dice().faces);
            }
        }
    };    

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Poison Dagger"), game_state);
    entity->description_offset = Offset(STR("A tiny blade, that isn't intended for dealing direct damage, but instead to apply a deadly poison."), game_state);
    entity->rarity = Rarity::magical;

    entity->flags = EFlags::equippable | EFlags::item;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::primary_hand];
    entity->weight = 2;
    entity->_stats[Stats::vitality] = 8; 
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.critical_success_range        = + 2;
        effect.stat_modifiers[Stats::might]  = + 3;
        effect.stat_modifiers[Stats::speed]  = + 1;
        effect.pierce                        = 2;
        Add_Dice(&effect, 1, 4);
        effect.on_hit_fn_offset = Offset(local::On_Hit, game_state);
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Cape_Of_Immunity(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Cape of Immunity"), game_state);
    entity->description_offset = Offset(STR("Pray you have one when the plague hits."), game_state);
    entity->rarity = Rarity::magical;
    
    entity->flags = EFlags::equippable | EFlags::item;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::back];
    entity->weight = 3;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::immunity]  = + 4;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }

    Finalize_Entity(entity, room, game_state);
    
    return entity;
}


SIG Entity* Create_Arcane_Cape(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Arcane cape"), game_state);
    entity->description_offset = Offset(STR("Draw the user closer to the souce it self."), game_state);
    entity->rarity = Rarity::magical;
    
    entity->flags = EFlags::equippable | EFlags::item;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::back];
    entity->weight = 3;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::arcane]  = + 4;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }

    Finalize_Entity(entity, room, game_state);
    
    return entity;
}


SIG Entity* Create_Cape_Of_Spite(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Cape of Spite"), game_state);
    entity->description_offset = Offset(STR("Made of living metal. When its wearer is hurt it forms into a spike and thrusts it self into the attacker."), game_state);
    entity->rarity = Rarity::epic;
    
    entity->flags = EFlags::equippable | EFlags::item;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::back];
    entity->weight = 3;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.thorns_damage = + 4;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }

    Finalize_Entity(entity, room, game_state);
    
    return entity;
}


SIG Entity* Create_Cape_Of_Avoidance(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Cape of Avoidance"), game_state);
    entity->description_offset = Offset(STR("A fast flowing cape that blurs the edges of the wearer, making them hard to hit."), game_state);
    entity->rarity = Rarity::magical;
    
    entity->flags = EFlags::equippable | EFlags::item;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::back];
    entity->weight = 3;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::dodge]  = + 4;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }

    Finalize_Entity(entity, room, game_state);
    
    return entity;
}


SIG Entity* Create_Cape_Of_Dashing(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Cape of Dashing"), game_state);
    entity->description_offset = Offset(STR("A short blue triangular cape enchanted with speed enhancing magics."), game_state);
    entity->rarity = Rarity::magical;

    entity->flags = EFlags::equippable | EFlags::item;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::back];
    entity->weight = 3;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::speed]  = + 4;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }

    Finalize_Entity(entity, room, game_state);
    
    return entity;
}


SIG Entity* Create_Backpack(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Backpack"), game_state);
    entity->description_offset = Offset(STR("A leather sack with straps to pull our hands through and throw it on your back."), game_state);
    entity->rarity = Rarity::rare;

    entity->flags = EFlags::equippable | EFlags::item;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::back];
    
    entity->weight = 5;
    entity->_stats[Stats::vitality] = 2; 
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::speed]     = - 5;
        effect.stat_modifiers[Stats::accuracy]  = - 1;
        effect.carry_capacity_modifier          = + 100;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }

    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Ring_Of_Giants(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);
    
    entity->name_offset = Offset(STR("Ring of Giants"), game_state);
    entity->description_offset = Offset(STR("Grants the wearer the power of giants. This ring is rumored to be forged by the legendary Gill Highant."), game_state);
    entity->rarity = Rarity::legendary;

    entity->flags = EFlags::equippable | EFlags::item;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::ring_1];
    entity->weight = 30;
    entity->_stats[Stats::vitality] = 50;

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::might]    = +10;
        effect.stat_modifiers[Stats::vitality] = +10;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }

    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Ring_Of_Strange_Fortunes(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);
   
    entity->name_offset = Offset(STR("Ring of Strange Fortunes"), game_state);
    entity->description_offset = Offset(STR("A ring that is both cursed and blessed. Who would create such a thing?"), game_state);
    entity->rarity = Rarity::magical;

    entity->flags = EFlags::equippable | EFlags::item;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::ring_1];
    entity->weight = 1;

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.critical_success_range = +10;
        effect.critical_failure_range = +10;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Ring_Of_Rebirth(Entity* room, Game_State* game_state)
{
    struct local
    {
        static void Rebirth(Effect_Instance* instance, Entity_Offset attacker_offset, Entity* defender, Deal_Damage_Result* ddr, Game_State* game_state)
        {
            if(instance)
            {
                Entity* ring = Pointer(instance->source, game_state);
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
    };


    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Ring of Rebirth"), game_state);
    entity->description_offset = Offset(STR("Crafted in a twisted ritual where a Phoenex was sacrificed and its essence molded into a ring."), game_state);
    entity->rarity = Rarity::legendary;

    entity->flags = EFlags::equippable | EFlags::item;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::ring_1];
   
    entity->weight                  = 1;
    entity->_stats[Stats::vitality] = 10;
    entity->_stats[Stats::armor]    = 100;
    entity->interactable.uses_count = 1;

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.on_damage_taken_fn_offset = Offset(local::Rebirth, game_state);
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
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
                bool room_contains_an_acitve_hostile = false;
                Entity_Iterator iter = Make_Iterator(Pointer(target->residence, game_state), game_state);
                while(Entity* entity = Next_Entity(&iter))
                {
                    if(Is_Living_Active_Enemy_Of(entity, target))
                    {
                        room_contains_an_acitve_hostile = true;
                        break;
                    }
                }
                
                if(room_contains_an_acitve_hostile)
                {
                    Heal(target, healing_amount, Effect_Name(instance, game_state), Verbose::yes, game_state);
                }
            }
            else
            {
                Print("If it sences a hostile presence, heals the wearer %d points of health.", healing_amount);
            }
        }
    };
    
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Ring of Regeneration"), game_state);
    entity->description_offset = Offset(STR("Ring with a warm yellow glow. It has been blessed by a cleric giving it powers of healing."), game_state);
    entity->rarity = Rarity::magical;

    entity->flags = EFlags::equippable | EFlags::item;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::ring_1];
    entity->weight = 1;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.on_turn_start_fn_offset = Offset(local::Regeneration_On_Turn_Start_FN, game_state);
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Gloves_Of_Brutality(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Gloves of Brutality"), game_state);
    entity->description_offset = Offset(STR("Spiked leather gloves with a strange red glow around them."), game_state);
    entity->rarity = Rarity::epic;

    entity->flags = EFlags::equippable | EFlags::item;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::gloves];
    entity->weight = 3;

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor] = + 2;
        Add_Dice(&effect, 1, 6);
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Leather_Gloves(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Leather gloves"), game_state);
    entity->description_offset = Offset(STR("Basic hand protection."), game_state);

    entity->flags = EFlags::equippable | EFlags::item;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::gloves];
    entity->weight = 2;

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor] = + 1;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Chainmail_Gloves(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Chainmail gloves"), game_state);
    entity->description_offset = Offset(STR("Effective hand protection."), game_state);
    entity->rarity = Rarity::rare;

    entity->flags = EFlags::equippable | EFlags::item;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::gloves];
    entity->weight = 3;

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor] = + 2;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Plate_Gloves(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Plate gloves"), game_state);
    entity->description_offset = Offset(STR("Heavy hand protection."), game_state);
    entity->rarity = Rarity::rare;

    entity->flags = EFlags::equippable | EFlags::item;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::gloves];
    entity->weight = 4;

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor] = + 3;
        effect.critical_failure_range       = + 1;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Wooden_Shield(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Wooden Shield"), game_state);
    entity->description_offset = Offset(STR("A Shield made out of wooden planks. It does not seem very effective."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::secondary_hand];
    entity->weight = 7;
    entity->_stats[Stats::vitality] = 10;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor] = + 2;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Buckler(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Buckler"), game_state);
    entity->description_offset = Offset(STR("A small round metal shield used for deflecting attacks."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::rare;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::secondary_hand];
    entity->weight = 3;
    entity->_stats[Stats::vitality] = 5;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::dodge] = + 3;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Kite_Shield(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Kite shield"), game_state);
    entity->description_offset = Offset(STR("A metal shield with a crest depicting an upside down chalice."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::rare;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::secondary_hand];
    entity->weight = 10;
    entity->_stats[Stats::vitality] = 15;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor] = + 4;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Barn_Door_Shield(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Barn door"), game_state);
    entity->description_offset = Offset(STR("It is a large door. But you could use it as shield?"), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::secondary_hand];
    entity->weight = 20;
    entity->_stats[Stats::vitality] = 80;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor] = + 5;
        effect.stat_modifiers[Stats::dodge] = - 5;
        effect.stat_modifiers[Stats::speed] = - 5;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Tower_Shield(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Tower Shield"), game_state);
    entity->description_offset = Offset(STR("A massive shield. It's as tall as man."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::rare;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::secondary_hand];
    entity->weight = 30;
    entity->_stats[Stats::vitality] = 100;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor] = + 10;
        effect.stat_modifiers[Stats::dodge] = - 10;
        effect.stat_modifiers[Stats::speed] = - 10;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Shearing_Light(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Shearing Light"), game_state);
    entity->description_offset = Offset(STR("On orb, that when held turns into a golden shield of light that burns attackers."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::legendary;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::secondary_hand];
    entity->weight = 1;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor] = + 5;
        effect.stat_modifiers[Stats::dodge] = + 5;
        effect.thorns_damage                = + 11;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Leather_Cuirass(Entity* room, Game_State* game_state)
{    
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Leather cuirass"), game_state);
    entity->description_offset = Offset(STR("Mostly a fashion statement as simple leather does not provide mutch protection."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;


    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::chest];
    entity->weight = 5;
    entity->_stats[Stats::vitality] = 3;

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor] = + 2;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }

    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Gambeson(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Gambeson"), game_state);
    entity->description_offset = Offset(STR("Cheap and effective armor made of wool."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::chest];
    entity->weight = 7;
    entity->_stats[Stats::vitality] = 8;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor] = + 4;
        
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Breastplate(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Breastplate"), game_state);
    entity->description_offset = Offset(STR("Heavy, but incredibly effective armor made of steel."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::rare;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::chest];
    entity->weight = 15;
    entity->_stats[Stats::vitality] = 10;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor] = + 7;
        effect.stat_modifiers[Stats::speed] = - 2;
        effect.stat_modifiers[Stats::dodge] = - 2;
        effect.critical_failure_range       = + 1;
        
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Skull_Cap(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Skull cap"), game_state);
    entity->description_offset = Offset(STR("Simple metal helmet. Nothing more, nothing less."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::head];
    entity->weight = 3;
    entity->_stats[Stats::vitality] = 5;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor] = + 2;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Arming_Cap(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Arming cap"), game_state);
    entity->description_offset = Offset(STR("A padded cloth hood."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::head];
    entity->weight = 1;
    entity->_stats[Stats::vitality] = 2;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor] = + 1;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Chainmail_Hood(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Chainmail hood"), game_state);
    entity->description_offset = Offset(STR("Covers the head and neck, providing good protection considering how light it is."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::rare;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::head];
    entity->weight = 2;
    entity->_stats[Stats::vitality] = 8;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor] = + 3;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Barbute(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Barbute"), game_state);
    entity->description_offset = Offset(STR("Thick steel helmet with the only opening a slim gap for the eyes."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::rare;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::head];
    entity->weight = 5;
    entity->_stats[Stats::vitality] = 10;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor]    = + 5;
        effect.stat_modifiers[Stats::accuracy] = - 2;
        effect.critical_failure_range          = + 1;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Plate_Leggings(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Plate leggings"), game_state);
    entity->description_offset = Offset(STR("Leg armor made from interleaving steel plates."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::rare;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::legs];
    entity->weight = 12;
    entity->_stats[Stats::vitality] = 10;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor] = + 6;
        effect.stat_modifiers[Stats::speed] = - 2;
        effect.stat_modifiers[Stats::dodge] = - 2;
        effect.critical_failure_range       = + 1;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Leather_Tights(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Leather tights"), game_state);
    entity->description_offset = Offset(STR("Pants for the brave and the bold."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::legs];
    entity->weight = 4;
    entity->_stats[Stats::vitality] = 3;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor] = + 2;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Padded_Pants(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Padded pants"), game_state);
    entity->description_offset = Offset(STR("Pants with simple wool padding."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::legs];
    entity->weight = 3;
    entity->_stats[Stats::vitality] = 3;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor] = + 3;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Warrior_Kilt(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Warrior kilt"), game_state);
    entity->description_offset = Offset(STR("A red kilt that emanates furious energies."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::rare;

    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::legs];
    entity->weight = 3;
    entity->_stats[Stats::vitality] = 3;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::might] = + 2;
        effect.stat_modifiers[Stats::armor] = + 2;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Barbarian_Loing_Cloth(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Barbarian loing cloth"), game_state);
    entity->description_offset = Offset(STR("Crafted and enchated by a tribal shaman."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::magical;

    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::legs];
    entity->weight = 3;
    entity->_stats[Stats::vitality] = 3;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::might] = + 3;
        effect.critical_success_range       = + 3;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Travel_Boots(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Travel boots"), game_state);
    entity->description_offset = Offset(STR("Finely crafted and especially made for long distance walking."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::rare;

    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::boots];
    entity->weight = 2;
    entity->_stats[Stats::vitality] = 2;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor] = + 1;
        effect.carry_capacity_modifier = + 10;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Sabatons(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Sabatons"), game_state);
    entity->description_offset = Offset(STR("Heavy plate boots."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::rare;

    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::boots];
    entity->weight = 5;
    entity->_stats[Stats::vitality] = 5;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor] = + 4;
        effect.stat_modifiers[Stats::speed] = - 1;
        effect.stat_modifiers[Stats::dodge] = - 1;
        effect.critical_failure_range       = + 1;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Gladiator_Sandals(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Gladiator sandals"), game_state);
    entity->description_offset = Offset(STR("Permanently stained with blood."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::magical;

    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::boots];
    entity->weight = 2;
    entity->_stats[Stats::vitality] = 5;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::might] = + 2;
        effect.stat_modifiers[Stats::speed] = + 1;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Leather_Boots(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Leather boots"), game_state);
    entity->description_offset = Offset(STR("Standard issue leather boots."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;

    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::boots];
    entity->weight = 2;
    entity->_stats[Stats::vitality] = 2;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor] = + 1;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
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
    entity->flags = EFlags::interactable | EFlags::item;
    entity->rarity = Rarity::rare;

    entity->weight = 1;
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

            if(entity)
            {
                s16 level = Level(target);
                Dice dice = {1, level};
                Arena_Snapshot snapshot = Snapshot(&game_state->scratch_buffer);

                s32* dice_results = Roll_With_Record(dice, game_state);

                s32 potency = level + *dice_results;

                // Healing potion potency is: %d (%d + 1d%d = %d[%d, %d])
                Arena* arena = &game_state->messages_buffer;

                // NOTE: String construction in this language is rough... Would have been a bit easier in Python for instance.
                // Though I think the conditional in there would mean that you'd still need a loop. But you could just apped the string together.
                // This though is fast! No memory allocations really happening here.

                u64 length = 0;
                char* message_base = Push_String(arena, Name(entity, game_state), &length);
                
                U64_To_String_Memory m;
                Push_String(arena, STR(" potency is: "), &length);
                Push_String(arena, To_String(u64(potency), &m), &length);
                Push_String(arena, STR(" ("), &length);
                Push_String(arena, To_String(u64(level), &m), &length);
                Push_String(arena, STR(" + 1d"), &length);
                Push_String(arena, To_String(u64(dice.faces), &m), &length);
                Push_String(arena, STR(" = "), &length);
                Push_String(arena, To_String(u64(*dice_results), &m), &length);
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
                Print("Heals the user by: (lvl) + 1d(lvl).");
            }
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Healing Potion"), game_state);
    entity->description_offset = Offset(STR("Produced in great numbers by the clergy, especially when preparing for war."), game_state);
    entity->flags = EFlags::interactable | EFlags::item;
    entity->rarity = Rarity::rare;

    entity->weight = 1;
    entity->interactable.on_use_fn_offset = Offset(local::on_use_fn, game_state);
    entity->interactable.on_empty_fn_offset = Offset(Delete_Entity, game_state);
    entity->interactable.uses_count = 1;

    Finalize_Entity(entity, container, game_state);
    return entity;
}


SIG Entity* Create_Jerky(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);
    entity->name_offset = Offset(STR("Jerky"), game_state);
    entity->description_offset = Offset(STR("Dried and salted meat."), game_state);
    entity->food_quality = Food_Quality::appetizer;
    entity->weight = 1;

    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Bread(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);
    entity->name_offset = Offset(STR("Bread"), game_state);
    entity->description_offset = Offset(STR("A bread loaf."), game_state);
    entity->food_quality = Food_Quality::snack;
    entity->weight = 1;

    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_BBQ_Wings(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);
    entity->name_offset = Offset(STR("Barbequed wings"), game_state);
    entity->description_offset = Offset(STR("Chicken wings with a spicy sause."), game_state);
    entity->food_quality = Food_Quality::lunch;
    entity->weight = 1;

    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Steak_And_Smashed_Potatoes(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);
    entity->rarity = Rarity::magical;
    entity->name_offset = Offset(STR("Steak & mashed potatoes"), game_state);
    entity->description_offset = Offset(STR("Medium rare."), game_state);
    entity->food_quality = Food_Quality::meal;
    entity->weight = 2;

    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Mushroom(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);
    entity->name_offset = Offset(STR("Mushroom"), game_state);
    entity->description_offset = Offset(STR("Looks edible, but with mushrooms... who knows?"), game_state);
    entity->food_quality = Food_Quality::snack;
    entity->weight = 1;

    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Bomb(Entity* container, Game_State* game_state)
{
    struct local
    {
        static void on_use_fn(Entity* item, Entity* user, Game_State* game_state)
        {
            Dice dice = {1, 6};
            if(item)
            {
                s32 base = Get_Stat_Value(user, Stats::arcane, game_state);

                s32 dice_result = (s32)Roll(dice, game_state);
                s32 damage = base + dice_result;
                u64 length = 0;
                
                // Bomb potency is: %d ([acrane]:%d + %dd%d = %d)
                U64_To_String_Memory m;
                String source_name = Name(item, game_state);
                String message = String_Builder(&game_state->messages_buffer, source_name)
                .Next(STR(" potency is: "))
                .Next(To_String(damage, &m))
                .Next(STR(" (["))
                .Next(Stats::name[Stats::arcane])
                .Next(STR("]:"))
                .Next(To_String(base, &m))
                .Next(STR(" + "))
                .Next(To_String(dice.count, &m))
                .Next(STR("d"))
                .Next(To_String(dice.faces, &m))
                .Next(STR(" = "))
                .Next(To_String(dice_result, &m))
                .Next(STR(")"))
                .Finish();
                
                Push_Message(message, game_state);

                Entity_Iterator iter = Make_Iterator(Pointer(user->residence, game_state), game_state);
                while(Entity* entity = Next_Entity(&iter))
                {
                    if(Is_Living_Active_Enemy_Of(entity, user))
                    {
                        Deal_Damage(entity, Offset(user, game_state), source_name, damage, {}, Damage_Type::physical, game_state, Verbose::yes);
                    }
                }
            }
            else
            {
                Print("Deals [%s] + %dd%d physical damage to all hostiles in the room.", Stats::name[Stats::arcane].ptr, dice.count, dice.faces);
            }
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Bomb"), game_state);
    entity->description_offset = Offset(STR("An explosive device created by a talented alchemist."), game_state);
    entity->flags = EFlags::interactable | EFlags::item;
    entity->rarity = Rarity::common;

    entity->weight = 3;
    entity->interactable.on_use_fn_offset = Offset(local::on_use_fn, game_state);
    entity->interactable.on_empty_fn_offset = Offset(Delete_Entity, game_state);
    entity->interactable.uses_count = 1;

    Finalize_Entity(entity, container, game_state);
    return entity;
}


SIG Entity* Create_Fragmentation_Bomb(Entity* container, Game_State* game_state)
{
    struct local
    {
        static void on_use_fn(Entity* item, Entity* user, Game_State* game_state)
        {
            Dice dice = {1, 6};
            s32 pierce = 5;
            if(item)
            {
                s32 base = Get_Stat_Value(user, Stats::arcane, game_state);

                s32 dice_result = (s32)Roll(dice, game_state);
                s32 damage = base + dice_result;
                u64 length = 0;
                
                // Bomb potency is: %d ([acrane]:%d + %dd%d = %d)
                U64_To_String_Memory m;
                String source_name = Name(item, game_state);
                String message = String_Builder(&game_state->messages_buffer, source_name)
                .Next(STR(" potency is: "))
                .Next(To_String(damage, &m))
                .Next(STR(" (["))
                .Next(Stats::name[Stats::arcane])
                .Next(STR("]:"))
                .Next(To_String(base, &m))
                .Next(STR(" + "))
                .Next(To_String(dice.count, &m))
                .Next(STR("d"))
                .Next(To_String(dice.faces, &m))
                .Next(STR(" = "))
                .Next(To_String(dice_result, &m))
                .Next(STR(")"))
                .Finish();
                
                Push_Message(message, game_state);

                Entity_Iterator iter = Make_Iterator(Pointer(user->residence, game_state), game_state);
                while(Entity* entity = Next_Entity(&iter))
                {
                    if(Is_Living_Active_Enemy_Of(entity, user))
                    {
                        Deal_Damage(entity, Offset(user, game_state), source_name, damage, pierce, Damage_Type::physical, game_state, Verbose::yes);
                    }
                }
            }
            else
            {
                Print("Deals [%s] + %dd%d + %d pierce physical damage to all hostiles in the room.", Stats::name[Stats::arcane].ptr, dice.count, dice.faces, pierce);
            }
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Fragmentation Bomb"), game_state);
    entity->description_offset = Offset(STR("An explosive device packed inside a jar of nails. Created by a devious alchemist."), game_state);
    entity->flags = EFlags::interactable | EFlags::item;
    entity->rarity = Rarity::rare;

    entity->weight = 4;
    entity->interactable.on_use_fn_offset = Offset(local::on_use_fn, game_state);
    entity->interactable.on_empty_fn_offset = Offset(Delete_Entity, game_state);
    entity->interactable.uses_count = 1;

    Finalize_Entity(entity, container, game_state);
    return entity;
}


// DEVELOPPER ITEMS: 
SIG Entity* Create_Ring_Of_Just_Fucking_Crit(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);
   
    entity->name_offset = Offset(STR("Ring of Just Fucking CRIT!"), game_state);
    entity->description_offset = Offset(STR("When you just don't want to leave landing a critical hit up to change."), game_state);
    entity->rarity = Rarity::legendary;

    entity->flags = EFlags::equippable | EFlags::item;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::ring_1];
    entity->weight = 1;

    Effect* effect = Request_Effect(game_state);
    effect->critical_success_range += S8_MAX;
    entity->on_equip_effect_offset = Offset(effect, game_state);
    
    Finalize_Entity(entity, room, game_state);

    return entity;
}