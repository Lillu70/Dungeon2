
// ===================================
// Copyright (c) 2025 by Valtteri Kois
// All rights reserved.
// ===================================

// REMEMBER TO UPDATE DAMAGE VALUES FROM THE SPREAD SHEET!

// Nyxm ring idea: Ring of Unstable Combustion
// H.M. : What's not to love, I either live to explode another day or i can explode twice.
// Deals damage to everything in the room 6 charges, roll a 1d(charges) == 1 Damage is also applied to you.
// Damage: 10 + [arcane]
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
        {Create_Cure},
        {Create_Bandage},
        {Create_Dispeller},
        {Create_Herbal_Remedy},
        {Create_Healing_Potion},
        {Create_Restoration_Potion},
        {Create_Bomb},
        {Create_Fragmentation_Bomb},
        {Create_Dodge_Elixir},
        {Create_Might_Elixir},
        {Create_Vitality_Elixir},
        {Create_Accuracy_Elixir},
        {Create_Speed_Elixir},
        {Create_Immunity_Elixir},
        {Create_Arcane_Elixir},
        {Create_Acid_Flask},
        {Create_Sticky_Goo},
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
        {Create_Ring_Of_Life},
        {Create_Ring_Of_Wrath},
        {Create_Ring_Of_Avoidance},
        {Create_Ring_Of_Precision},
        {Create_Ring_Of_Protection},
        {Create_Ring_Of_Quickening},
        {Create_Ring_Of_Mending},
        {Create_Huntsmans_Ring},
        {Create_Ring_Of_The_Reliable_Worker},
        {Create_Ring_Of_Penetration},
        {Create_Avengers_Rings},
        {Create_Cowards_Ring},
        {Create_Demon_Brand},
        {Create_Ring_Of_Bloodshield},
        {Create_Ring_Of_Clumsy_Regeneration},
        {Create_Ring_Of_False_Hope},
        {Create_Bauble_Of_Bomb_Craft},
        {Create_Bauble_Of_Potion_Craft},

        // Should capes be here?
        {Create_Cape_Of_Dashing},
        {Create_Cape_Of_Avoidance},
        {Create_Cape_Of_Immunity},
        {Create_Arcane_Cape},
        {Create_Cape_Of_Spite},
        {Create_Healers_Cape},
        {Create_Backpack}
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
        {Create_Wicker_Shield},
        {Create_Hide_Shield},
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
        {Create_Barbarian_Loincloth},
        {Create_Travel_Boots},
        {Create_Sabatons},
        {Create_Gladiator_Sandals},
        {Create_Leather_Boots},
        {Create_Gloves_Of_Brutality},
        {Create_Leather_Gloves},
        {Create_Chainmail_Gloves},
        {Create_Plate_Gloves},
        {Create_Belt},
        {Create_Strong_Man_Belt},
        {Create_Belt_Of_Atlas},
        {Create_Plate_Codpiece},
        {Create_Chastity_Belt},
        {Create_Field_Medics_Gloves},
        {Create_Mountaineer_Boots},
        {Create_Knights_Plate_Boots},
        {Create_Huntsmans_Gambeson},
        {Create_Warrior_Poncho},
        {Create_Assassins_Corset},
        {Create_Crusaders_Breastplate},
        {Create_Knights_Breastplate},
        {Create_Gloves_Of_Careful_Attacking},
        {Create_Bucket},
        {Create_Sack},
        {Create_Hide_Helmet},
        {Create_Wooden_Helmet},
        {Create_Trueshot_Goggles},
        {Create_Thiefs_Mask},
        {Create_Barbarian_Head_Ornamet},
        {Create_Nobles_Helm},
        {Create_Alchemists_Cap},
        {Create_Crown_Of_Thorns},
        {Create_Hood_Of_The_Golden_Order},
        {Create_Penmans_Visor},
        {Create_Plaguedoctos_Visor},
        {Create_Putrid_Flesh_Head_Mould},
        {Create_Monks_Headband},
        {Create_Damaged_Tiara_Of_Divine_Protection},
        {Create_Horny_Headband},
        {Create_Monocle_Of_Thunderstrike},
        {Create_Nobles_Armored_Garb},
        {Create_Vest_Of_Evasion},
        {Create_Hedgehog_Skin_Vest},
        {Create_Precise_Jerkin},
        {Create_Strong_Jerkin},
        {Create_Hauberk},
        {Create_Chestguard_Of_The_Silver_Blossoms_Scout},
        {Create_Treebark_Jacket},
        {Create_Robes_Of_The_Magi},
        {Create_Kamikaze_Shirt},
        {Create_Harness_Of_Enslavement},
        {Create_Myconian_Chestcover},
        {Create_Lightforged_Iron_Chestguard},
        {Create_Emergency_Vest},
        {Create_Field_Medics_Jerkin},
        {Create_Restorers_Battle_Armor},
        {Create_Workers_Trousers},
        {Create_Junk_Metal_Leg_Guards},
        {Create_Burglars_Leggings},
        {Create_Historians_Skirt},
        {Create_Berserkers_Leggings},
        {Create_Pants_Of_The_Jack},
        {Create_Trousers_Of_The_Doomwalker},
        {Create_Feralhearth_Pants},
        {Create_Pants_Of_Holy_Avoidance},
        {Create_Battle_Medics_Trousers},
        {Create_Legguards_Of_Magical_Grounding},
        {Create_Bulwark_Legplates},
        {Create_Leggings_Of_Furious_Recovery},
        
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
        {Create_Short_Spear},
        {Create_Whip},
        {Create_Gardening_Scythe},
        {Create_War_Scythe},
        {Create_Cestus},
        {Create_Staff},
        {Create_War_Staff},
        {Create_Ram_Shield},
        {Create_Assassins_Claws},
        {Create_Battle_Axe},
        {Create_Great_Axe},
        {Create_Rapier},
        {Create_Club},
    };

    local_storage Loot_Table table = {entries, Array_Length(entries)};
    Fill_Loot_Table_Changes_And_Item_Rarity(&table, game_state);

    return table;
}


SIG void Spawn_All_Items_In_Loot_Table(Loot_Table table, Entity* room, Game_State* game_state)
{
    for(u64 i = 0; i < table.count; ++i)
    {
        table.array[i].fn(room, game_state);
    }
}


SIG Loot_Table Basic_Merged_Loot_Table(Game_State* game_state)
{
    // CONSIDER: It seems like there is serious need for caching, but it's not clear how to do that; Without storing pointers in permanent storage.
    // Another arena? ..just for this ? 
    // Static storage with a game_id  ?

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
        effect.stat_modifiers[Stats::speed] = - 4;
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
        effect.pierce                       = + 3;
        effect.stat_modifiers[Stats::might] = + 6;
        effect.stat_modifiers[Stats::speed] = + 6;
        effect.critical_failure_range       = + 3;
        Add_Dice(&effect, 1, 12);
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
        effect.pierce                       = + 6;
        effect.stat_modifiers[Stats::might] = + 5;
        effect.stat_modifiers[Stats::speed] = + 6;
        effect.critical_success_range       = + 4;
        Add_Dice(&effect, 1, 6);
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Cestus(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Cestus"), game_state);
    entity->description_offset = Offset(STR("A studded attack glove."), game_state);
    
    entity->flags = EFlags::equippable | EFlags::item;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::primary_hand];
    entity->weight = 1;
    entity->_stats[Stats::vitality] = 3;
    

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};        
        effect.stat_modifiers[Stats::might] = + 1;
        effect.stat_modifiers[Stats::dodge] = + 3;
        effect.stat_modifiers[Stats::speed] = + 1;
        Add_Dice(&effect, 2, 2);
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_War_Staff(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("War Staff"), game_state);
    entity->description_offset = Offset(STR("A long wooden staff with runes encraved on it."), game_state);
    
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
        effect.stat_modifiers[Stats::might]     = + 5;
        effect.stat_modifiers[Stats::arcane]    = + 6;
        effect.critical_failure_range           = + 3;
        Add_Dice(&effect, 2, 6);
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Assassins_Claws(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Assassins claws"), game_state);
    entity->description_offset = Offset(STR("Five long claws that attach to both hands."), game_state);
    entity->rarity = Rarity::uncommon;

    entity->flags = EFlags::equippable | EFlags::item;
    
    entity->required_equipment_slots = 
        Equipment_Slots::flag[Equipment_Slots::primary_hand] | 
        Equipment_Slots::flag[Equipment_Slots::secondary_hand];
    
    entity->weight = 5;
    entity->_stats[Stats::vitality] = 3;

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};        
        effect.stat_modifiers[Stats::might] = + 3;
        effect.stat_modifiers[Stats::dodge] = + 3;
        effect.stat_modifiers[Stats::speed] = + 2;
        effect.critical_success_range       = + 7;
        effect.pierce                       = + 4;
        Add_Dice(&effect, 1, 16);
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Staff(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Staff"), game_state);
    entity->description_offset = Offset(STR("A short wooden staff with runes encraved on it."), game_state);
    
    entity->flags = EFlags::equippable | EFlags::item;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::primary_hand];
    entity->weight = 4;
    entity->_stats[Stats::vitality] = 3;
    

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};        
        effect.stat_modifiers[Stats::might]     = + 3;
        effect.stat_modifiers[Stats::arcane]    = + 3;
        Add_Dice(&effect, 2, 3);
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Ram_Shield(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Ram shield"), game_state);
    entity->description_offset = Offset(STR("A strange combination of a shield and a mace."), game_state);
    entity->rarity = Rarity::uncommon;

    entity->flags = EFlags::equippable | EFlags::item;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::primary_hand];
    
    entity->weight = 11;
    entity->_stats[Stats::vitality] = 10;

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};        
        effect.stat_modifiers[Stats::might] = + 5;
        effect.stat_modifiers[Stats::armor] = + 3;
        effect.stat_modifiers[Stats::speed] = - 1;
        Add_Dice(&effect, 1, 6);
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Battle_Axe(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Battle axe"), game_state);
    entity->description_offset = Offset(STR("A twin bladed axe made."), game_state);
    
    entity->flags = EFlags::equippable | EFlags::item;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::primary_hand];
    
    entity->weight = 5;
    entity->_stats[Stats::vitality] = 3;

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};        
        effect.stat_modifiers[Stats::might] = + 3;
        Add_Dice(&effect, 4, 2);
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Great_Axe(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Great axe"), game_state);
    entity->description_offset = Offset(STR("A massive twin bladed axe"), game_state);
    
    entity->flags = EFlags::equippable | EFlags::item;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::primary_hand];
    
    entity->required_equipment_slots = 
        Equipment_Slots::flag[Equipment_Slots::primary_hand] | 
        Equipment_Slots::flag[Equipment_Slots::secondary_hand];
    
    entity->weight = 10;
    entity->_stats[Stats::vitality] = 3;

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};        
        effect.stat_modifiers[Stats::might] = + 5;
        effect.critical_failure_range       = + 4;
        effect.stat_modifiers[Stats::speed] = - 4;
        Add_Dice(&effect, 4, 4);
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Gardening_Scythe(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Gardening Scythe"), game_state);
    entity->description_offset = Offset(STR("A curved blade used for cutting down wheat."), game_state);
    
    entity->flags = EFlags::equippable | EFlags::item;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::primary_hand];
    
    entity->weight = 4;
    entity->_stats[Stats::vitality] = 3;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};        
        effect.stat_modifiers[Stats::might] = + 1;
        effect.stat_modifiers[Stats::armor] = + 1;
        effect.critical_success_range       = + 4;
        effect.critical_failure_range       = + 5;
        Add_Dice(&effect, 1, 10);
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_War_Scythe(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("War Scythe"), game_state);
    entity->description_offset = Offset(STR("A curved blade used for cutting down heads."), game_state);
    
    entity->flags = EFlags::equippable | EFlags::item;
    
    entity->required_equipment_slots = 
        Equipment_Slots::flag[Equipment_Slots::primary_hand] | 
        Equipment_Slots::flag[Equipment_Slots::secondary_hand];
    
    entity->weight = 8;
    entity->_stats[Stats::vitality] = 3;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};        
        effect.stat_modifiers[Stats::might] = + 4;
        effect.stat_modifiers[Stats::armor] = + 2;
        effect.stat_modifiers[Stats::speed] = - 3;
        effect.critical_success_range       = + 6;
        effect.critical_failure_range       = + 5;
        Add_Dice(&effect, 1, 10);
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
    
    entity->weight = 15;
    entity->_stats[Stats::vitality] = 20;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::might]     = + 14;
        effect.stat_modifiers[Stats::speed]     = - 8;
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
    
    entity->weight = 17;
    entity->_stats[Stats::vitality] = 100;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::might]     = + 7;
        effect.stat_modifiers[Stats::speed]     = - 3;
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
    entity->rarity = Rarity::uncommon;

    entity->flags = EFlags::equippable | EFlags::item;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::primary_hand];
    
    entity->weight = 5;
    entity->_stats[Stats::vitality] = 5;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.pierce                        = + 5;
        effect.stat_modifiers[Stats::might]  = + 5;
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


SIG Entity* Create_Club(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Club"), game_state);
    entity->description_offset = Offset(STR("A wooden stick used for bashing."), game_state);
    
    entity->flags = EFlags::equippable | EFlags::item;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::primary_hand];
    
    entity->weight = 4;
    entity->_stats[Stats::vitality] = 3;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::might] = + 4;
        Add_Dice(&effect, 1, 2);
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
    
    entity->weight = 6;
    entity->_stats[Stats::vitality] = 3;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::might] = + 8;
        effect.stat_modifiers[Stats::speed] = - 2;
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
    entity->rarity = Rarity::uncommon;

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
        effect.stat_modifiers[Stats::speed]    = + 1;
        effect.critical_success_range          = + 6;
        effect.critical_failure_range          = + 2;
        Add_Dice(&effect, 2, 6);
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
        effect.stat_modifiers[Stats::speed] = + 4;
        effect.stat_modifiers[Stats::might] = + 3;
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
    entity->rarity = Rarity::uncommon;

    entity->flags = EFlags::equippable | EFlags::item;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::primary_hand];
    
    entity->weight = 7;
    entity->_stats[Stats::vitality] = 2;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.pierce                       = + 2;
        effect.stat_modifiers[Stats::might] = + 9;
        effect.stat_modifiers[Stats::speed] = - 2;
        Add_Dice(&effect, 1, 5);
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
        effect.stat_modifiers[Stats::speed] = - 2;
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
        effect.stat_modifiers[Stats::speed]  = + 2;
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
    entity->rarity = Rarity::uncommon;

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
        effect.stat_modifiers[Stats::speed]  = + 2;
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
    entity->rarity = Rarity::uncommon;
    
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


SIG Entity* Create_Healers_Cape(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Healers cape"), game_state);
    entity->description_offset = Offset(STR("Golden cape of the Lights Order."), game_state);
    entity->rarity = Rarity::uncommon;
    
    entity->flags = EFlags::equippable | EFlags::item;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::back];
    entity->weight = 3;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.healing_power = 4;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }

    Finalize_Entity(entity, room, game_state);
    
    return entity;
}


SIG Entity* Create_Arcane_Cape(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Arcane cape"), game_state);
    entity->description_offset = Offset(STR("Draws the user closer to the source it self."), game_state);
    entity->rarity = Rarity::uncommon;
    
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


SIG Entity* Create_Belt(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Belt"), game_state);
    entity->description_offset = Offset(STR("Made of leather. It has fasteners for attaching items on it."), game_state);
    entity->rarity = Rarity::common;
    
    entity->flags = EFlags::equippable | EFlags::item;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::belt];
    entity->weight = 2;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.carry_capacity_modifier = + 10;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }

    Finalize_Entity(entity, room, game_state);
    
    return entity;
}


SIG Entity* Create_Plate_Codpiece(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Plate Codpiece"), game_state);
    entity->description_offset = Offset(STR("Steel covering for the valuables."), game_state);
    entity->rarity = Rarity::uncommon;
    
    entity->flags = EFlags::equippable | EFlags::item;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::belt];
    entity->weight = 3;
    
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


SIG Entity* Create_Chastity_Belt(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Chastity Belt"), game_state);
    entity->description_offset = Offset(STR("It's a thing.. prevents the other thing."), game_state);
    entity->rarity = Rarity::rare;
    
    entity->flags = EFlags::equippable | EFlags::item;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::belt];
    entity->weight = 1;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::arcane] = + 2;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }

    Finalize_Entity(entity, room, game_state);
    
    return entity;
}


SIG Entity* Create_Strong_Man_Belt(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Strong Man Belt"), game_state);
    entity->description_offset = Offset(STR("A tall belt that provied support when lifting things."), game_state);
    entity->rarity = Rarity::uncommon;
    
    entity->flags = EFlags::equippable | EFlags::item;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::belt];
    entity->weight = 3;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::might] = + 1;
        effect.carry_capacity_modifier      = + 20;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }

    Finalize_Entity(entity, room, game_state);
    
    return entity;
}


SIG Entity* Create_Belt_Of_Atlas(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Belt Of Atlas"), game_state);
    entity->description_offset = Offset(STR("The buckle looks like a man holding the Heavens."), game_state);
    entity->rarity = Rarity::epic;
    
    entity->flags = EFlags::equippable | EFlags::item;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::belt];
    entity->weight = 3;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::might]     = + 2;
        effect.stat_modifiers[Stats::vitality]  = + 2;
        effect.carry_capacity_modifier          = + 100;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }

    Finalize_Entity(entity, room, game_state);
    
    return entity;
}


SIG Entity* Create_Cape_Of_Spite(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Cape of Spite"), game_state);
    entity->description_offset = Offset(STR("Made of living metal. When its wearer is hurt, it forms into a spike and thrusts it self into the attacker."), game_state);
    entity->rarity = Rarity::rare;
    
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
    entity->rarity = Rarity::uncommon;
    
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
    entity->rarity = Rarity::uncommon;

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
    entity->rarity = Rarity::common;

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
    entity->weight = 20;
    entity->_stats[Stats::vitality] = 50;

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::might]    = + 10;
        effect.stat_modifiers[Stats::vitality] = + 10;
        effect.carry_capacity_modifier         = + 10;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }

    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Ring_Of_Bloodshield(Entity* room, Game_State* game_state)
{
    struct local
    {
        static void On_Hit(Effect_Instance* instance, Entity* attacker, Entity* defender, Attack_Record* ar, Game_State* game_state)
        {
            if(instance)
            {
                if(ar->is_critical_success)
                {
                    s32 dmg = ar->deal_damage_result.damage_after_mitigation;
                    Give_Temporary_Health(attacker, dmg, Effect_Name(instance, game_state), Verbose::yes, game_state);
                }
            }
            else
            {
                Print("If the attack is a critical success, provides temporary health equal to damage done.");
            }
        }
    };

    Entity* entity = Request_Entity(game_state);
    
    entity->name_offset = Offset(STR("Ring of Bloodshield"), game_state);
    entity->description_offset = Offset(STR("A favorite amongst the assassins, as it ensures a safe get a way."), game_state);
    entity->rarity = Rarity::uncommon;

    entity->flags = EFlags::equippable | EFlags::item;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::ring_1];
    entity->weight = 1;

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.on_hit_fn_offset = Offset(local::On_Hit, game_state);
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }

    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Ring_Of_Clumsy_Regeneration(Entity* room, Game_State* game_state)
{
    struct local
    {
        static void On_Miss(Effect_Instance* instance, Entity* attacker, Entity* defender, Attack_Record* ar, Game_State* game_state)
        {
            s32 healing_amount = 1;
            if(instance)
            {
                if(Is_Living_Active_Enemy_Of(defender, attacker))
                {
                    Heal(attacker, healing_amount, Effect_Name(instance, game_state), Verbose::yes, game_state);
                }
            }
            else
            {
                Print("Heals the user %d point%s of health.", healing_amount, (healing_amount > 1)? "s" : "");
            }
        }
    };

    Entity* entity = Request_Entity(game_state);
    
    entity->name_offset = Offset(STR("Ring of Clumsy Regeneration"), game_state);
    entity->description_offset = Offset(STR("A legend tells of a boy who never hit his target, but somehow still survived all his battles."), game_state);
    entity->rarity = Rarity::uncommon;

    entity->flags = EFlags::equippable | EFlags::item;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::ring_1];
    entity->weight = 1;

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.on_miss_fn_offset = Offset(local::On_Miss, game_state);
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }

    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Ring_Of_Survival_Instinct(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);
    
    entity->name_offset = Offset(STR("Ring of Survival Instinct"), game_state);
    entity->description_offset = Offset(STR("Set with a large blue tearstone. It embodies unbreakable will to live."), game_state);
    entity->rarity = Rarity::epic;

    entity->flags = EFlags::equippable | EFlags::item;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::ring_1];
    entity->weight = 1;

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.on_turn_start_fn_offset = Offset(Survival_Instinct_On_Turn_Start, game_state);
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }

    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Avengers_Rings(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);
    
    entity->name_offset = Offset(STR("Avengers Ring"), game_state);
    entity->description_offset = Offset(STR("Black and formless."), game_state);
    entity->rarity = Rarity::common;

    entity->flags = EFlags::equippable | EFlags::item;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::ring_1];
    entity->weight = 1;

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.thorns_damage = 1;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }

    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Cowards_Ring(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);
    
    entity->name_offset = Offset(STR("Cowards Ring"), game_state);
    entity->description_offset = Offset(STR("Worn by a man who was too afraid to try anything."), game_state);
    entity->rarity = Rarity::uncommon;

    entity->flags = EFlags::equippable | EFlags::item;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::ring_1];
    entity->weight = 1;

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor] = + 5;
        effect.critical_failure_range       = + 5;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }

    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Demon_Brand(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);
    
    entity->name_offset = Offset(STR("Demon Brand"), game_state);
    entity->description_offset = Offset(STR("A circle of fire."), game_state);
    entity->rarity = Rarity::rare;

    entity->flags = EFlags::equippable | EFlags::item;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::ring_1];
    entity->weight = 1;

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::might]     = + 2;
        effect.stat_modifiers[Stats::vitality]  = + 2;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }

    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Ring_Of_Quickening(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);
    
    entity->name_offset = Offset(STR("Ring of Quickening"), game_state);
    entity->description_offset = Offset(STR("Order of the Silver Blossom equips their messangers with these."), game_state);
    entity->rarity = Rarity::common;

    entity->flags = EFlags::equippable | EFlags::item;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::ring_1];
    entity->weight = 1;

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::speed] = + 1;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }

    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Ring_Of_Protection(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);
    
    entity->name_offset = Offset(STR("Ring of Protection"), game_state);
    entity->description_offset = Offset(STR("Blessed by a cleric from the Knights order of Silver Blossom."), game_state);
    entity->rarity = Rarity::common;

    entity->flags = EFlags::equippable | EFlags::item;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::ring_1];
    entity->weight = 1;

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


SIG Entity* Create_Ring_Of_Precision(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);
    
    entity->name_offset = Offset(STR("Ring of Precision"), game_state);
    entity->description_offset = Offset(STR("Especially valued by hunters and marksmen."), game_state);
    entity->rarity = Rarity::common;

    entity->flags = EFlags::equippable | EFlags::item;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::ring_1];
    entity->weight = 1;

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::accuracy] = + 1;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }

    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Ring_Of_Avoidance(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);
    
    entity->name_offset = Offset(STR("Ring of Avoidance"), game_state);
    entity->description_offset = Offset(STR("Hand crafted and freely given out by the Battle Monks."), game_state);
    entity->rarity = Rarity::common;

    entity->flags = EFlags::equippable | EFlags::item;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::ring_1];
    entity->weight = 1;

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::dodge] = + 1;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }

    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Ring_Of_Wrath(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);
    
    entity->name_offset = Offset(STR("Ring of Wrath"), game_state);
    entity->description_offset = Offset(STR("Worn by the mountainmen during raids into the civilized lands."), game_state);
    entity->rarity = Rarity::common;

    entity->flags = EFlags::equippable | EFlags::item;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::ring_1];
    entity->weight = 1;

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::might] = + 1;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }

    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Ring_Of_Life(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);
    
    entity->name_offset = Offset(STR("Ring of Life"), game_state);
    entity->description_offset = Offset(STR("A simple wooden ring."), game_state);
    entity->rarity = Rarity::common;

    entity->flags = EFlags::equippable | EFlags::item;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::ring_1];
    entity->weight = 1;

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::vitality] = + 1;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }

    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Ring_Of_Penetration(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);
    
    entity->name_offset = Offset(STR("Ring of Penetration"), game_state);
    entity->description_offset = Offset(STR("A common enchantment for both war and murder."), game_state);
    entity->rarity = Rarity::common;

    entity->flags = EFlags::equippable | EFlags::item;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::ring_1];
    entity->weight = 1;

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.name_offset = Offset(STR("Penetration"), game_state);
        effect.pierce = 2;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }

    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Ring_Of_Mending(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);
    
    entity->name_offset = Offset(STR("Ring of Mending"), game_state);
    entity->description_offset = Offset(STR("On it there is a glowing green gem."), game_state);
    entity->rarity = Rarity::common;

    entity->flags = EFlags::equippable | EFlags::item;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::ring_1];
    entity->weight = 1;

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.healing_power = + 2;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }

    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Huntsmans_Ring(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);
    
    entity->name_offset = Offset(STR("Huntsmans Ring"), game_state);
    entity->description_offset = Offset(STR("Carved from antler bone."), game_state);
    entity->rarity = Rarity::uncommon;

    entity->flags = EFlags::equippable | EFlags::item;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::ring_1];
    entity->weight = 1;

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.critical_success_range += 1;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }

    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Ring_Of_The_Reliable_Worker(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);
    
    entity->name_offset = Offset(STR("Ring Of The Reliable Worker"), game_state);
    entity->description_offset = Offset(STR("Given to those, whose work is too important for anything to go wrong."), game_state);
    entity->rarity = Rarity::uncommon;

    entity->flags = EFlags::equippable | EFlags::item;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::ring_1];
    entity->weight = 1;

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.critical_failure_range -= 1;
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
    entity->rarity = Rarity::rare;

    entity->flags = EFlags::equippable | EFlags::item;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::ring_1];
    entity->weight = 1;

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.critical_success_range = + 10;
        effect.critical_failure_range = + 10;
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
                    ddr->is_killing_blow = false;
                    
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


SIG Entity* Create_Ring_Of_False_Hope(Entity* room, Game_State* game_state)
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
                    ddr->is_killing_blow = false;
                    
                    defender->_health = 1;

                    String defender_name = Name(defender, game_state);
                    ring->interactable.uses_count -= 1;

                    String description = STR("Devoid of magic.");
                    ring->description_offset = Offset(description, game_state);

                    char* format_string = "Ring of False Hope brings %s back to life consuming it self in the process. What was on the other side the curtain?";
                    String message = Format_Message(game_state, format_string, defender_name.ptr);

                    Push_Message(message, game_state);
                }
            }
            else
            {
                Print("If the wearer dies, energy from the ring is transfared into the wearer consuming the ring and brining the wearer back to life, but with only 1 health.");
            }
        }
    };


    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Ring of False Hope"), game_state);
    entity->description_offset = Offset(STR("What's the worst thing that can happen? I die twice?!"), game_state);
    entity->rarity = Rarity::epic;

    entity->flags = EFlags::equippable | EFlags::item;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::ring_1];
   
    entity->weight = 1;
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
                if(Residence_Contains_An_Active_Hostile(target, game_state))
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
    entity->rarity = Rarity::rare;

    entity->flags = EFlags::equippable | EFlags::item;
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::ring_1];
    entity->weight = 1;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.name_offset = Offset(STR("Restoration"), game_state);
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


SIG Entity* Create_Gloves_Of_Careful_Attacking(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Gloves Of Careful Attacking"), game_state);
    entity->description_offset = Offset(STR("Probably not actually blessed, but thinking they are is effective in it self."), game_state);

    entity->flags = EFlags::equippable | EFlags::item;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::gloves];
    entity->weight = 2;

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.critical_failure_range = - 1;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Field_Medics_Gloves(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Field Medics gloves"), game_state);
    entity->description_offset = Offset(STR("Being a Field Medic a dangerous role indeed, as the forces of evil hate seeing their hard work undone."), game_state);
    entity->rarity = Rarity::uncommon;

    entity->flags = EFlags::equippable | EFlags::item;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::gloves];
    entity->weight = 2;

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.healing_power = + 3;
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
    entity->rarity = Rarity::uncommon;

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
    entity->rarity = Rarity::uncommon;

    entity->flags = EFlags::equippable | EFlags::item;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::gloves];
    entity->weight = 4;

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor]     = + 3;
        effect.stat_modifiers[Stats::speed]     = - 1;
        effect.stat_modifiers[Stats::arcane]    = - 1;
        effect.critical_failure_range           = + 1;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Wooden_Shield(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Wooden Shield"), game_state);
    entity->description_offset = Offset(STR("A Shield made out of wooden planks. Common and therefore cheap protection."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::secondary_hand];
    entity->weight = 5;
    entity->_stats[Stats::vitality] = 10;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor] = + 2;
        effect.stat_modifiers[Stats::speed] = - 1;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Wicker_Shield(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Wicker Shield"), game_state);
    entity->description_offset = Offset(STR("It does not seem very effective."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::secondary_hand];
    entity->weight = 2;
    entity->_stats[Stats::vitality] = 5;
    
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


SIG Entity* Create_Hide_Shield(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Hide Shield"), game_state);
    entity->description_offset = Offset(STR("Tanned hide streched over a wooden frame to create a relatively effective shield."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::secondary_hand];
    entity->weight = 7;
    entity->_stats[Stats::vitality] = 5;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor] = + 3;
        effect.stat_modifiers[Stats::speed] = - 1;
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
    entity->rarity = Rarity::common;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::secondary_hand];
    entity->weight = 3;
    entity->_stats[Stats::vitality] = 5;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::dodge] = + 2;
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
    entity->rarity = Rarity::uncommon;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::secondary_hand];
    entity->weight = 10;
    entity->_stats[Stats::vitality] = 15;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor] = + 4;
        effect.stat_modifiers[Stats::speed] = - 1;
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
    entity->weight = 14;
    entity->_stats[Stats::vitality] = 80;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor] = + 5;
        effect.stat_modifiers[Stats::dodge] = - 5;
        effect.stat_modifiers[Stats::speed] = - 7;
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
    entity->rarity = Rarity::uncommon;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::secondary_hand];
    entity->weight = 15;
    entity->_stats[Stats::vitality] = 100;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor] = + 7;
        effect.stat_modifiers[Stats::dodge] = - 8;
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
    entity->weight = 6;
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


SIG Entity* Create_Hauberk(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Hauberk"), game_state);
    entity->description_offset = Offset(STR("Tunic of chain mail that covers the torso."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::uncommon;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::chest];
    entity->weight = 5;
    entity->_stats[Stats::vitality] = 8;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor] = + 6;
        effect.stat_modifiers[Stats::speed] = - 1;
        
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Nobles_Armored_Garb(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Noble's armored garb"), game_state);
    entity->description_offset = Offset(STR("On a rare occasion, a prince of a noble family decents down into the Dungeon to prove their worth."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::uncommon;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::chest];
    entity->weight = 4;
    entity->_stats[Stats::vitality] = 8;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::accuracy]  = + 1;
        effect.stat_modifiers[Stats::vitality]  = + 2;
        effect.stat_modifiers[Stats::armor]     = + 2;
        effect.stat_modifiers[Stats::dodge]     = + 2;
        
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Vest_Of_Evasion(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Vest of Evasion"), game_state);
    entity->description_offset = Offset(STR("A blue leather vest, strange thing thing to look at. Perhaps that is why it's harder hit someone wearing it?"), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::uncommon;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::chest];
    entity->weight = 3;
    entity->_stats[Stats::vitality] = 8;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor] = + 1;
        effect.stat_modifiers[Stats::dodge] = + 5;
        
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Hedgehog_Skin_Vest(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Hedgehog skin vest"), game_state);
    entity->description_offset = Offset(STR("A very spikey vest."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::uncommon;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::chest];
    entity->weight = 6;
    entity->_stats[Stats::vitality] = 8;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor] = + 2;
        effect.thorns_damage = 4;
        
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Precise_Jerkin(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Precise Jerkin"), game_state);
    entity->description_offset = Offset(STR("Medium light armor with an accuracy enchantment."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::uncommon;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::chest];
    entity->weight = 4;
    entity->_stats[Stats::vitality] = 8;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor]     = + 3;
        effect.stat_modifiers[Stats::accuracy]  = + 4;
        
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Strong_Jerkin(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Strong Jerkin"), game_state);
    entity->description_offset = Offset(STR("Medium light armor with a strength enchantment."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::uncommon;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::chest];
    entity->weight = 4;
    entity->_stats[Stats::vitality] = 8;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor] = + 3;
        effect.stat_modifiers[Stats::might] = + 4;
        
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Chestguard_Of_The_Silver_Blossoms_Scout(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Chestguard of the Silver Blossoms scout"), game_state);
    entity->description_offset = Offset(STR("Order of the Silver Blossom is the militant arm of the church of Golden Order."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::uncommon;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::chest];
    entity->weight = 4;
    entity->_stats[Stats::vitality] = 8;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor] = + 4;
        effect.stat_modifiers[Stats::speed] = + 4;
        effect.stat_modifiers[Stats::dodge] = + 1;
        
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Treebark_Jacket(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Tree-bark Jacket"), game_state);
    entity->description_offset = Offset(STR("Made from Oak bark. The tree dwelling people of Zondal wear these as camouflage."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::uncommon;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::chest];
    entity->weight = 2;
    entity->_stats[Stats::vitality] = 8;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor]     = + 1;
        effect.stat_modifiers[Stats::speed]     = + 1;
        effect.stat_modifiers[Stats::dodge]     = + 2;
        effect.stat_modifiers[Stats::immunity]  = + 7;
        
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Robes_Of_The_Magi(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Robes of The Magi"), game_state);
    entity->description_offset = Offset(STR("Robes enchanted with magic enhancing magical enchantments."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::uncommon;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::chest];
    entity->weight = 2;
    entity->_stats[Stats::vitality] = 8;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor]  = + 1;
        effect.stat_modifiers[Stats::arcane] = + 6;
        
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Kamikaze_Shirt(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Kamikaze shirt"), game_state);
    entity->description_offset = Offset(STR("A tornup shirt worn by Tom the villager. He went insane and started cutting down his own townsflok."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::uncommon;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::chest];
    entity->weight = 1;
    entity->_stats[Stats::vitality] = 8;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor] = - 5;
        effect.stat_modifiers[Stats::might] = + 8;
        effect.stat_modifiers[Stats::speed] = + 3;
        Add_Dice(&effect, 1, 6);
        
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Harness_Of_Enslavement(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Harness of Enslavement"), game_state);
    entity->description_offset = Offset(STR("A cruel device intended to be forced upon slaves. Makes them hardier, but more sensitive to pain."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::uncommon;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::chest];
    entity->weight = 1;
    entity->_stats[Stats::vitality] = 8;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor]     = - 2;
        effect.stat_modifiers[Stats::vitality]  = + 3;
        effect.stat_modifiers[Stats::immunity]  = + 11;
        effect.carry_capacity_modifier          = + 50;

        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Myconian_Chestcover(Entity* room, Game_State* game_state)
{
    struct local
    {
        static void On_Miss(Effect_Instance* instance, Entity* attacker, Entity* defender, Attack_Record* ar, Game_State* game_state)
        {
            if(instance)
            {
                if(ar->is_critical_failure)
                {
                    Entity* space = Pointer(attacker->residence, game_state);
                    Entity* mushroom = Create_Mushroom(space, game_state);
                    mushroom->flags |= EFlags::visible;

                    String shrooms_name = Name(mushroom, game_state);
                    String effect_name = Effect_Name(instance, game_state);

                    String message = Format_Message(game_state, "%s sprouts a %s.", effect_name.ptr, shrooms_name.ptr);
                    Push_Message(message, game_state);
                }
            }
            else
            {
                Print("On a fumple sprouts a mushroom.");
            }
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Myconian Chestcover"), game_state);
    entity->description_offset = Offset(STR("A chest armor made from living soil. It's coverd in mushrooms, undergorowth and worms."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::uncommon;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::chest];
    entity->weight = 7;
    entity->_stats[Stats::vitality] = 8;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor] = + 3;
        effect.on_miss_fn_offset = Offset(local::On_Miss, game_state);
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Lightforged_Iron_Chestguard(Entity* room, Game_State* game_state)
{
    struct local
    {
        static void On_Turn_Start(Effect_Instance* instance, Entity* target, Game_State* game_state)
        {
            s32 temp_health_amount = 1;
            if(instance)
            {
                if(game_state->visible_initiative_count > 1)
                {
                    String effect_name = Effect_Name(instance, game_state);

                    s32 roll = Roll(2, game_state);
                    u64 trigger = 2;
                    bool result = roll == trigger;
                    String message = Format_Message
                    (
                        game_state, 
                        "%s attempts to shield %s [%s]: 1d%d = %d (Success: = %llu)",
                        effect_name.ptr,
                        Name(target, game_state).ptr,
                        (result)? "success" : "failure",
                        2,
                        roll,
                        trigger
                    );
                    Push_Message(message, game_state);
                    
                    if(result)
                    {
                        Give_Temporary_Health(target, temp_health_amount, effect_name, Verbose::yes, game_state);
                    }
                }
            }
            else
            {
                Print("Rolls a 1d2, if the result is 2 the user resives %d temporary health.", temp_health_amount);
            }
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Lightforged Iron Chestguard"), game_state);
    entity->description_offset = Offset(STR("Lightforging is a special crafting technique only known to the Order of the Bright Forge. It is where they get their name."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::uncommon;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::chest];
    entity->weight = 7;
    entity->_stats[Stats::vitality] = 8;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor] = + 5;
        effect.stat_modifiers[Stats::dodge] = - 1;
        effect.stat_modifiers[Stats::speed] = - 3;
        effect.critical_failure_range = + 1;

        effect.on_turn_start_fn_offset = Offset(local::On_Turn_Start, game_state);
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Emergency_Vest(Entity* room, Game_State* game_state)
{
    struct local
    {
        static void On_Be_Attacked(Effect_Instance* instance, Entity* defender, Entity* attacker, Attack_Record* ar, Game_State* game_state)
        {
            s32 healing_amount = 10;
            if(instance)
            {
                if(ar->is_critical_success)
                {
                    Entity_Iterator iter = Make_Iterator(Pointer(defender->residence, game_state), game_state);
                    while(Entity* entity = Next_Entity(&iter))
                    {
                        Heal(entity, healing_amount, Effect_Name(instance, game_state), Verbose::yes, game_state);
                    }
                }
            }
            else
            {
                Print("If the attack is a critical hit. Heals all the entities in the room by %d.", healing_amount);
            }
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Emergency Vest"), game_state);
    entity->description_offset = Offset(STR("Triggers at the time of need, but at such moment there is no time for discrimination."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::uncommon;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::chest];
    entity->weight = 4;
    entity->_stats[Stats::vitality] = 8;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor] = + 3;

        effect.on_be_attacked_fn_offset = Offset(local::On_Be_Attacked, game_state);
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Field_Medics_Jerkin(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Field Medics Jerkin"), game_state);
    entity->description_offset = Offset(STR("Stained with blood of the wounded."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::uncommon;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::chest];
    entity->weight = 4;
    entity->_stats[Stats::vitality] = 8;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor] = + 3;
        effect.healing_power                = + 5;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Restorers_Battle_Armor(Entity* room, Game_State* game_state)
{
    struct local
    {
        static void on_use_fn(Entity* item, Entity* target, Game_State* game_state)
        {
            Dice dice = {1, 8};
            if(item)
            {
                String source_name = Name(item, game_state);
                s32 potency = Potency(source_name, 0, dice, game_state);
                Heal(target, potency, source_name, Verbose::yes, game_state);
            }
            else
            {
                Print("Heals the wearer for %dd%d points of health", dice.count, dice.faces);
            }
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Restorers Battle Armor"), game_state);
    entity->description_offset = Offset(STR("Bright green veins run through the surface. It's made of some very light metal."), game_state);
    entity->flags = EFlags::equippable | EFlags::item | EFlags::interactable;
    entity->rarity = Rarity::uncommon;    
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::chest];
    entity->weight = 6;
    entity->_stats[Stats::vitality] = 5;

    entity->interactable.on_use_fn_offset = Offset(local::on_use_fn, game_state);
    entity->interactable.uses_count = UNLIMITED_USES;
    entity->interactable.cd_type = Cooldown_Type::rooms;
    entity->interactable.cd = 3;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor] = + 4;
        effect.stat_modifiers[Stats::might] = + 1;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }

    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Huntsmans_Gambeson(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Huntsmans Gambeson"), game_state);
    entity->description_offset = Offset(STR("The armor has been through a lot."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::uncommon;    
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::chest];
    entity->weight = 6;
    entity->_stats[Stats::vitality] = 8;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor]     = + 4;
        effect.stat_modifiers[Stats::accuracy]  = + 2;
        effect.critical_failure_range           = - 1;

        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Warrior_Poncho(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Warrior Poncho"), game_state);
    entity->description_offset = Offset(STR("On the fabric there are depictions of many a battle."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::uncommon;    
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::chest];
    entity->weight = 2;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::might] = + 5;
        effect.stat_modifiers[Stats::dodge] = + 2;
        effect.critical_success_range       = + 2;
        
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
    entity->rarity = Rarity::uncommon;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::chest];
    entity->weight = 14;
    entity->_stats[Stats::vitality] = 10;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor]     = + 7;
        effect.stat_modifiers[Stats::speed]     = - 4;
        effect.stat_modifiers[Stats::dodge]     = - 2;
        effect.stat_modifiers[Stats::arcane]    = - 2;
        effect.critical_failure_range           = + 2;
        
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Assassins_Corset(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Assassins corset"), game_state);
    entity->description_offset = Offset(STR("Most famous of the guilds that offer assissinations is called the \"Last Chapter\"."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::rare;    
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::chest];
    entity->weight = 3;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.critical_success_range           = + 2;
        effect.stat_modifiers[Stats::arcane]    = + 3;
        effect.stat_modifiers[Stats::armor]     = + 3;
        effect.stat_modifiers[Stats::dodge]     = + 3;
        
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Knights_Breastplate(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Knights Breastplate"), game_state);
    entity->description_offset = Offset(STR("Depicting a large silver flower on the chest."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::rare;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::chest];
    entity->weight = 14;
    entity->_stats[Stats::vitality] = 10;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor]     = + 8;
        effect.stat_modifiers[Stats::speed]     = - 4;
        effect.stat_modifiers[Stats::arcane]    = - 2;
        effect.stat_modifiers[Stats::immunity]  = + 2;
        effect.critical_failure_range           = + 2;
        
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Crusaders_Breastplate(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Crusaders Breastplate"), game_state);
    entity->description_offset = Offset(STR("Crusaders are knights trained and equipped to hunt down heretics."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::epic;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::chest];
    entity->weight = 15;
    entity->_stats[Stats::vitality] = 10;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::immunity]  = + 5;
        effect.stat_modifiers[Stats::vitality]  = + 1; 
        effect.stat_modifiers[Stats::armor]     = + 9;
        effect.stat_modifiers[Stats::might]     = + 2;
        effect.stat_modifiers[Stats::arcane]    = - 1;
        effect.stat_modifiers[Stats::speed]     = - 4;
        effect.critical_failure_range           = + 1;
        effect.healing_power                    = + 2;
        
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


SIG Entity* Create_Trueshot_Goggles(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("True-shot Goggles"), game_state);
    entity->description_offset = Offset(STR("These goggles have an echantment that highlights vital organs."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::uncommon;    
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::head];
    entity->weight = 1;
    entity->_stats[Stats::vitality] = 5;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor]     = + 1;
        effect.stat_modifiers[Stats::accuracy]  = + 1;
        effect.critical_success_range           = + 2;
        
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Thiefs_Mask(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Thief's mask"), game_state);
    entity->description_offset = Offset(STR("Event the thieves guild employs devious clericks to empower their equipment with blessings."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::uncommon;    
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::head];
    entity->weight = 1;
    entity->_stats[Stats::vitality] = 5;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor] = + 2;
        effect.stat_modifiers[Stats::dodge] = + 1;
        effect.stat_modifiers[Stats::speed] = + 1;
        
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Barbarian_Head_Ornamet(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Barbarian head ornament"), game_state);
    entity->description_offset = Offset(STR("Made branches and leather. Offets minimal protection, but boosts aggression."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::uncommon;    
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::head];
    entity->weight = 1;
    entity->_stats[Stats::vitality] = 5;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor] = + 1;
        effect.stat_modifiers[Stats::might] = + 3;
        
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Nobles_Helm(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Noble's Helm"), game_state);
    entity->description_offset = Offset(STR("The Kingdom of Vash is ruled by eight noble houses. The kingship is rotated between each house."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::uncommon;    
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::head];
    entity->weight = 3;
    entity->_stats[Stats::vitality] = 5;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor] = + 2;
        effect.stat_modifiers[Stats::dodge] = + 2;
        
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Alchemists_Cap(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Alchemist's Cap"), game_state);
    entity->description_offset = Offset(STR("There are countless schools of alchemy, most specialize in creating one concoction."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::uncommon;    
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::head];
    entity->weight = 2;
    entity->_stats[Stats::vitality] = 5;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::arcane]    = + 3;
        effect.stat_modifiers[Stats::immunity]  = + 1;
        effect.stat_modifiers[Stats::dodge]     = + 1;
        
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Crown_Of_Thorns(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Crown of Thorns"), game_state);
    entity->description_offset = Offset(STR("A band of thorny vine."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::uncommon;    
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::head];
    entity->weight = 1;
    entity->_stats[Stats::vitality] = 5;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor] = + 1;
        effect.thorns_damage                = + 3;

        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Hood_Of_The_Golden_Order(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Hood of the Golden Order"), game_state);
    entity->description_offset = Offset(STR("Though there are many religions, the Golden Order has the most followers."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::uncommon;    
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::head];
    entity->weight = 1;
    entity->_stats[Stats::vitality] = 5;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor] = + 1;
        effect.healing_power                = + 3;

        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Penmans_Visor(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Penman's visor"), game_state);
    entity->description_offset = Offset(STR("Copying books is a job where precision of utmost importance. A mistake could cost hundreds of hours of work and waste expensive parchment."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::uncommon;    
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::head];
    entity->weight = 3;
    entity->_stats[Stats::vitality] = 5;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::immunity]  = + 1;
        effect.critical_failure_range           = - 3;

        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Plaguedoctos_Visor(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Plaguedoctor's visor"), game_state);
    entity->description_offset = Offset(STR("Like clockwork, every hundread years a plague appears and kills of many.. many people. It always happens, but the deadliness varies."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::uncommon;    
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::head];
    entity->weight = 3;
    entity->_stats[Stats::vitality] = 5;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::immunity] = + 5;

        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Putrid_Flesh_Head_Mould(Entity* room, Game_State* game_state)
{
    struct local
    {
        static void On_Turn_Start(Effect_Instance* instance, Entity* target, Game_State* game_state)
        {
            s32 damage = 1;
            if(instance)
            {
                if(target->_health % 2)
                {
                    Deal_Damage(target, instance->source, Effect_Name(instance, game_state), damage, {}, Damage_Type::magical, game_state, Verbose::yes);
                }
            }
            else
            {
                Print("if the users health is an odd number, deals %d damage to the user.", damage);
            }
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Putrid flesh head mould"), game_state);
    entity->description_offset = Offset(STR("A pulsating lumb of flesh and organs formed into a shape of a helmet."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::uncommon;    
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::head];
    entity->weight = 5;
    entity->_stats[Stats::vitality] = 5;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.max_health_modifier              = + 7;
        effect.stat_modifiers[Stats::arcane]    = + 5;
        effect.stat_modifiers[Stats::immunity]  = - 8;
        effect.on_turn_start_fn_offset = Offset(local::On_Turn_Start, game_state);
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Monks_Headband(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Monks headband"), game_state);
    entity->description_offset = Offset(STR("a simple headband with an echantment."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::uncommon;    
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::head];
    entity->weight = 1;
    entity->_stats[Stats::vitality] = 5;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::dodge] = + 1;
        effect.stat_modifiers[Stats::speed] = + 5;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Damaged_Tiara_Of_Divine_Protection(Entity* room, Game_State* game_state)
{
    struct local
    {
        static void On_Damage_Taken(Effect_Instance* instance, Entity_Offset attacker_offset, Entity* defender, Deal_Damage_Result* ddr, Game_State* game_state)
        {
            s32 threshold = 1;
            if(instance)
            {
                Entity* item = Pointer(instance->source, game_state);
                if(ddr->damage_after_mitigation > threshold && item && item->interactable.uses_count)
                {
                    item->interactable.uses_count -= 1;
                    Give_Temporary_Health(defender, Level(defender), Effect_Name(instance, game_state), Verbose::yes, game_state);
                    if(item->interactable.uses_count == 0)
                    {
                        String message = Format_Message(game_state, "The gem on the %s shatters.. its enchantment is no longer effective.", Name(item, game_state).ptr);
                        Push_Message(message, game_state);
                    }
                }
            }
            else
            {
                Print("if the damage taken exceed %d, resive temporary health equal to user level.", threshold);
            }         
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Damaged Tiara of Divine Protection"), game_state);
    entity->description_offset = Offset(STR("The gem on it is fractured. Everytime the user receives Godly intervesion the fracture deepens."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::uncommon;    
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::head];
    entity->weight = 2;
    entity->_stats[Stats::vitality] = 5;
    entity->interactable.uses_count = 25;

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor] = + 1;
        effect.on_damage_taken_fn_offset = Offset(local::On_Damage_Taken, game_state);
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Horny_Headband(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Horny headband"), game_state);
    entity->description_offset = Offset(STR("A horn of some creature is attached to a headband"), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::uncommon;    
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::head];
    entity->weight = 4;
    entity->_stats[Stats::vitality] = 5;

    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        Add_Dice(&effect, 1, 4);
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Monocle_Of_Thunderstrike(Entity* room, Game_State* game_state)
{
    struct local
    {
        static void On_Hit(Effect_Instance* instance, Entity* attacker, Entity* defender, Attack_Record* ar, Game_State* game_state)
        {
            Dice dice = {2, 6};
            if(instance)
            {
                String source_name = Effect_Name(instance, game_state);
                s32 dmg = Potency(source_name, 0, dice, game_state);
                Deal_Damage(defender, attacker, source_name, dmg, {}, Damage_Type::magical, game_state, Verbose::yes);
            }
            else
            {
                Print("Deals %dd%d extra magical damage.", dice.count, dice.faces);
            }
        }

        static void on_use_fn(Entity* item, Entity* target, Game_State* game_state)
        {
            s16 dice_count = 2;
            s16 dice_faces = 6;
            if(item)
            {
                Effect_Instance thunderstride = {};

                Effect_Hash_Key key = EFFECT_KEY;
                if(!Retrive_Effect(key, &thunderstride.effect_offset, game_state))
                {
                    Effect effect = {};
                    effect.type = Effect_Type::magic;
                    effect.name_offset = Offset(STR("Thunderstrike"), game_state);
                    effect.on_hit_fn_offset = Offset(On_Hit, game_state);
                    thunderstride.effect_offset = Insert_Effect(effect, key, game_state);
                }

                thunderstride.duration = 1;
                thunderstride.duration_type = Duration_Type::attack;
                thunderstride.source = Offset(item, game_state);

                Apply_Effect_Result apply = Apply_Effect(target, thunderstride, game_state);
                Push_Generic_Apply_Effect_Message(Name(item, game_state), target, thunderstride, apply, game_state);
            }
            else
            {
                Print("Next attack deals %dd%d extra damage.", dice_count, dice_faces);
            }
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Monocle of Thunderstrike"), game_state);
    entity->description_offset = Offset(STR("Press the button on the side to active."), game_state);
    entity->flags = EFlags::equippable | EFlags::item | EFlags::interactable;
    entity->rarity = Rarity::uncommon;    
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::head];
    entity->weight = 1;
    entity->_stats[Stats::vitality] = 5;

    entity->interactable.on_use_fn_offset = Offset(local::on_use_fn, game_state);
    entity->interactable.uses_count = UNLIMITED_USES;
    entity->interactable.cd_type = Cooldown_Type::rooms;
    entity->interactable.cd = 1;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor] = + 1;
        effect.stat_modifiers[Stats::might] = + 1;
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


SIG Entity* Create_Hide_Helmet(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Hide helmet"), game_state);
    entity->description_offset = Offset(STR("Hardened tanned hide crafted into a helmet."), game_state);
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


SIG Entity* Create_Wooden_Helmet(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Wooden Helmet"), game_state);
    entity->description_offset = Offset(STR("A finely carved helmet. It has an opening for the eyes. This might be great helmet if the material was sturdier!"), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::head];
    entity->weight = 4;
    entity->_stats[Stats::vitality] = 2;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor] = + 2;
        effect.stat_modifiers[Stats::speed] = - 1;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Bucket(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Bucket"), game_state);
    entity->description_offset = Offset(STR("A wooden bucket. Commonly used for carrying water. You could use it as an improviced helmet, but it's kinda hard to see from underneath it."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::head];
    entity->weight = 2;
    entity->_stats[Stats::vitality] = 2;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor]     = + 3;
        effect.stat_modifiers[Stats::accuracy]  = - 7;
        effect.critical_failure_range           = + 5;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Sack(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Sack"), game_state);
    entity->description_offset = Offset(STR("You could hide from the reality of your sitution by putting your head in it."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::head];
    entity->weight = 1;
    entity->_stats[Stats::vitality] = 2;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::immunity]  = + 10;
        effect.stat_modifiers[Stats::accuracy]  = - 5;
        effect.critical_failure_range           = + 5;
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
    entity->rarity = Rarity::uncommon;
    
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
    entity->rarity = Rarity::uncommon;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::head];
    entity->weight = 5;
    entity->_stats[Stats::vitality] = 10;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor]     = + 5;
        effect.stat_modifiers[Stats::accuracy]  = - 2;
        effect.stat_modifiers[Stats::arcane]    = - 1;
        effect.stat_modifiers[Stats::speed]     = - 1;
        effect.critical_failure_range           = + 1;
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


SIG Entity* Create_Workers_Trousers(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Workers Trousers"), game_state);
    entity->description_offset = Offset(STR("Durable, but certainly not intended for battle."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::legs];
    entity->weight = 2;
    entity->_stats[Stats::vitality] = 10;
    
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


SIG Entity* Create_Junk_Metal_Leg_Guards(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Junk metal legguards"), game_state);
    entity->description_offset = Offset(STR("Used pots, pans, spades and other metal instruments knotted onto a set of pants. Perhaps to play or pretend to be a knight?"), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::legs];
    entity->weight = 17;
    entity->_stats[Stats::vitality] = 3;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor]     = + 4;
        effect.stat_modifiers[Stats::speed]     = - 5;
        effect.stat_modifiers[Stats::dodge]     = - 3;
        effect.stat_modifiers[Stats::arcane]    = - 1;
        effect.critical_failure_range           = + 3;
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
    entity->rarity = Rarity::uncommon;
    
    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::legs];
    entity->weight = 12;
    entity->_stats[Stats::vitality] = 10;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor]     = + 5;
        effect.stat_modifiers[Stats::speed]     = - 3;
        effect.stat_modifiers[Stats::arcane]    = - 2;
        effect.stat_modifiers[Stats::dodge]     = - 2;
        effect.critical_failure_range           = + 1;
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
    entity->rarity = Rarity::uncommon;

    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::legs];
    entity->weight = 3;
    entity->_stats[Stats::vitality] = 3;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::might]     = + 4;
        effect.stat_modifiers[Stats::armor]     = + 2;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Burglars_Leggings(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Burglars leggings"), game_state);
    entity->description_offset = Offset(STR("The punishment for theft in the Kingdom of Vash is a month in the \"pit\". No food or water is given. The perpetrator might survive if it rains enough."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::uncommon;

    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::legs];
    entity->weight = 4;
    entity->_stats[Stats::vitality] = 3;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor] = + 2;
        effect.stat_modifiers[Stats::speed] = + 7;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Historians_Skirt(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Historian's skirt"), game_state);
    entity->description_offset = Offset(STR("Colorful imagery depicting past events runs along the cloth, the timeline is chronological but it then smoothly wraps around. Pehaps there is deep meaning in this."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::uncommon;

    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::legs];
    entity->weight = 2;
    entity->_stats[Stats::vitality] = 3;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor] = + 1;
        effect.stat_modifiers[Stats::arcane] = + 4;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Berserkers_Leggings(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Berserker's leggings"), game_state);
    entity->description_offset = Offset(STR("Pants torn to shreads, there is almost nothing left, but still.. there is are faint traices of magics within."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::uncommon;

    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::legs];
    entity->weight = 2;
    entity->_stats[Stats::vitality] = 3;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor] = - 1;
        effect.critical_success_range = 4;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Pants_Of_The_Jack(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Pants of The Jack"), game_state);
    entity->description_offset = Offset(STR("Legend tells of The Middling Jack, he was good at everything, but didn't like to chalenge him self, and so he never because great at anything. Let this be a warning to you!"), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::uncommon;

    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::legs];
    entity->weight = 4;
    entity->_stats[Stats::vitality] = 3;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::vitality]  = + 1;
        effect.stat_modifiers[Stats::might]     = + 1;
        effect.stat_modifiers[Stats::dodge]     = + 1;
        effect.stat_modifiers[Stats::accuracy]  = + 1;
        
        effect.stat_modifiers[Stats::arcane]    = + 1;
        effect.stat_modifiers[Stats::immunity]  = + 1;
        effect.stat_modifiers[Stats::speed]     = + 1;
        effect.stat_modifiers[Stats::armor]     = + 1;
        effect.critical_success_range           = + 1;
        effect.critical_failure_range           = + 1;

        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Trousers_Of_The_Doomwalker(Entity* room, Game_State* game_state)
{
    struct local
    {
        static void On_Turn_End(Effect_Instance* instance, Entity* target, Game_State* game_state)
        {
            s8 fumple_boost = 5;
            if(instance)
            {
                Effect_Instance aura_of_depression = {};
                aura_of_depression.source = instance->source;
                aura_of_depression.duration = 1;

                Effect_Hash_Key key = EFFECT_KEY;
                if(!Retrive_Effect(key, &aura_of_depression.effect_offset, game_state))
                {
                    Effect effect = {};
                    effect.name_offset = Offset(STR("Aura of Depression"), game_state);
                    effect.type = Effect_Type::magic;
                    effect.critical_failure_range = + 5;
                    aura_of_depression.effect_offset = Insert_Effect(effect, key, game_state);
                }

                Entity_Iterator iter = Make_Iterator(Pointer(target->residence, game_state), game_state);
                while(Entity* entity = Next_Entity(&iter))
                {
                    if(Is_Living_Active_Enemy_Of(entity, target))
                    {
                        Apply_Effect_Result apply = Apply_Effect(entity, aura_of_depression, game_state);
                        Push_Generic_Apply_Effect_Message(Effect_Name(instance, game_state), entity, aura_of_depression, apply, game_state);
                    }
                }
            }
            else
            {
                Print("Sends out a wave of depressing energies that increases the fumple change of all active hostiles by %d points.", fumple_boost);
            }
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Trousers of The Doomwalker"), game_state);
    entity->description_offset = Offset(STR("The Doomwalkers are a hated cult, that worships Borgoth; the God of Incompetance and Failure."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::uncommon;

    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::legs];
    entity->weight = 8;
    entity->_stats[Stats::vitality] = 3;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor] = + 3;
        effect.critical_failure_range       = + 7;

        effect.on_turn_end_fn_offset = Offset(local::On_Turn_End, game_state);
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Feralhearth_Pants(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Feralhearth pants"), game_state);
    entity->description_offset = Offset(STR("Leather pants, but woven into them are pulsating bloodveins."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::uncommon;

    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::legs];
    entity->weight = 6;
    entity->_stats[Stats::vitality] = 3;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor]     = + 1;
        effect.stat_modifiers[Stats::might]     = + 2;
        effect.max_health_modifier              = + 5;

        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Pants_Of_Holy_Avoidance(Entity* room, Game_State* game_state)
{
    struct local
    {
        static void On_Dodge(Effect_Instance* instance, Entity* defender, Entity* attacker, Attack_Record* ar, Game_State* game_state)
        {
            s16 healing_power = 5;
            u64 duration = 1;
            if(instance)
            {
                Effect_Instance mending = {};
                mending.source = instance->source;
                mending.duration = duration;

                Effect_Hash_Key key = EFFECT_KEY;
                if(!Retrive_Effect(key, &mending.effect_offset, game_state))
                {
                    Effect effect = {};
                    effect.name_offset = Offset(STR("Battle Mending"), game_state);
                    effect.type = Effect_Type::magic;
                    effect.healing_power  = + healing_power;

                    mending.effect_offset = Insert_Effect(effect, key, game_state);
                }

                Apply_Effect_Result apply = Apply_Effect(defender, mending, game_state);
                Push_Generic_Apply_Effect_Message(Effect_Name(instance, game_state), defender, mending, apply, game_state);
            }
            else
            {
                Print("Increases the users healing power by %d point%s for %llu round%s.", healing_power, (healing_power > 1)? "s" : "", duration, (duration > 1)? "s" : "");
            }
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Pants of Holy Avoidance"), game_state);
    entity->description_offset = Offset(STR("These are common on monks."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::uncommon;

    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::legs];
    entity->weight = 4;
    entity->_stats[Stats::vitality] = 3;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::dodge] = + 2;
        effect.stat_modifiers[Stats::armor] = + 2;
        effect.on_dodge_fn_offset = Offset(local::On_Dodge, game_state);

        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Battle_Medics_Trousers(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Battle medics trousers"), game_state);
    entity->description_offset = Offset(STR("Even the barbaric mountainmen train field medics, but they call them selfs battle medics."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::uncommon;

    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::legs];
    entity->weight = 4;
    entity->_stats[Stats::vitality] = 3;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor] = + 2;
        effect.stat_modifiers[Stats::might] = + 2;
        effect.healing_power                = + 3;

        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Legguards_Of_Magical_Grounding(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Legguards of magical grounding"), game_state);
    entity->description_offset = Offset(STR("Crafted by a wizard who was afraid of magic."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::uncommon;

    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::legs];
    entity->weight = 6;
    entity->_stats[Stats::vitality] = 3;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor]     = + 3;
        effect.stat_modifiers[Stats::immunity]  = + 7;
        effect.stat_modifiers[Stats::arcane]    = - 7;

        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Bulwark_Legplates(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Bulwark Legplates"), game_state);
    entity->description_offset = Offset(STR("Extremely heavy armor."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::uncommon;

    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::legs];
    entity->weight = 16;
    entity->_stats[Stats::vitality] = 3;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor]     = + 6;
        effect.stat_modifiers[Stats::immunity]  = + 4;
        
        effect.stat_modifiers[Stats::arcane]    = - 3;
        effect.stat_modifiers[Stats::might]     = - 2;
        effect.stat_modifiers[Stats::speed]     = - 5;
        effect.critical_failure_range           = - 2;

        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Leggings_Of_Furious_Recovery(Entity* room, Game_State* game_state)
{
    struct local
    {
        static void On_Hit(Effect_Instance* instance, Entity* attacker, Entity* defender, Attack_Record* ar, Game_State* game_state)
        {
            s32 threshold = 15;
            if(instance)
            {
                s32 d = ar->deal_damage_result.damage_after_mitigation;
                if(d > threshold)
                {
                    d -= threshold;
                    Heal(attacker, d, Effect_Name(instance, game_state), Verbose::yes, game_state);
                }
            }
            else
            {
                Print("If damage after mitigation exceeds %d then heals the user by the amount of damage over the threshold.", threshold);
            }
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Leggings of Furious Recovery"), game_state);
    entity->description_offset = Offset(STR(""), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::uncommon;

    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::legs];
    entity->weight = 6;
    entity->_stats[Stats::vitality] = 3;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor] = + 3;
        effect.stat_modifiers[Stats::might] = + 1;
        effect.on_hit_fn_offset = Offset(local::On_Hit, game_state);

        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Barbarian_Loincloth(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Barbarian loincloth"), game_state);
    entity->description_offset = Offset(STR("Crafted and enchated by a tribal shaman."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::rare;

    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::legs];
    entity->weight = 3;
    entity->_stats[Stats::vitality] = 3;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::might] = + 5;
        effect.stat_modifiers[Stats::armor] = + 2;
        effect.stat_modifiers[Stats::speed] = + 2;
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
    entity->rarity = Rarity::uncommon;

    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::boots];
    entity->weight = 2;
    entity->_stats[Stats::vitality] = 2;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor] = + 1;
        effect.stat_modifiers[Stats::speed] = + 1;
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
    entity->rarity = Rarity::uncommon;

    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::boots];
    entity->weight = 5;
    entity->_stats[Stats::vitality] = 5;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor]     = + 4;
        effect.stat_modifiers[Stats::speed]     = - 1;
        effect.stat_modifiers[Stats::dodge]     = - 1;
        effect.stat_modifiers[Stats::arcane]    = - 1;
        effect.critical_failure_range           = + 1;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Knights_Plate_Boots(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Knights Plate Boots"), game_state);
    entity->description_offset = Offset(STR("On the steel there are outlines of flowers made of embedded silver."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::rare;

    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::boots];
    entity->weight = 5;
    entity->_stats[Stats::vitality] = 5;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::armor]     = + 5;
        effect.stat_modifiers[Stats::immunity]  = + 2;
        effect.stat_modifiers[Stats::speed]     = - 1;
        effect.stat_modifiers[Stats::arcane]    = - 1;
        effect.critical_failure_range           = + 1;
        entity->on_equip_effect_offset = Insert_Effect(effect, key, game_state);
    }
    
    Finalize_Entity(entity, room, game_state);
    return entity;
}


SIG Entity* Create_Mountaineer_Boots(Entity* room, Game_State* game_state)
{
    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Mountaineer Boots"), game_state);
    entity->description_offset = Offset(STR("The Mountainmen is a generic term for the barbarian tribes living on the Casper mountains. They often decent up the civilized lands to raid for coin and women."), game_state);
    entity->flags = EFlags::equippable | EFlags::item;
    entity->rarity = Rarity::uncommon;

    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::boots];
    entity->weight = 3;
    entity->_stats[Stats::vitality] = 5;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::speed] = + 3;
        effect.stat_modifiers[Stats::armor] = + 2;
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
    entity->rarity = Rarity::uncommon;

    entity->required_equipment_slots = Equipment_Slots::flag[Equipment_Slots::boots];
    entity->weight = 2;
    entity->_stats[Stats::vitality] = 5;
    
    Effect_Hash_Key key = EFFECT_KEY;
    if(!Retrive_Effect(key, &entity->on_equip_effect_offset, game_state))
    {
        Effect effect = {};
        effect.stat_modifiers[Stats::might] = + 2;
        effect.stat_modifiers[Stats::armor] = + 1;
        effect.stat_modifiers[Stats::dodge] = + 1;
        effect.stat_modifiers[Stats::speed] = + 3;
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
    entity->description_offset = Offset(STR("An amber colored concoction that serves as a remedy to all things poison."), game_state);
    entity->flags = EFlags::interactable | EFlags::item;
    entity->rarity = Rarity::common;

    entity->weight = 1;
    entity->interactable.on_use_fn_offset = Offset(local::on_use_fn, game_state);
    entity->interactable.on_empty_fn_offset = Offset(Delete_Entity, game_state);
    entity->interactable.uses_count = 1;

    Finalize_Entity(entity, container, game_state);
    return entity;
}


SIG Entity* Create_Cure(Entity* container, Game_State* game_state)
{
    struct local
    {
        static void on_use_fn(Entity* item, Entity* user, Game_State* game_state)
        {
            Effect_Type::T type = Effect_Type::disease;

            if(item)
            {
                u64 removed_count = Remove_Effects_Of_Type(user, type, game_state, Verbose::yes);
                if(!removed_count)
                {
                    Print("\n%s wasn't under the the effect of any %s.", Name(user, game_state).ptr, Effect_Type::names[type].ptr);
                }
            }
            else
            {
                Print("Removes all effects of type: %s", Effect_Type::names[type].ptr);
            }
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Cure"), game_state);
    entity->description_offset = Offset(STR("A vial of green viscous fluid. Hopefully it tastes better than it smells."), game_state);
    entity->flags = EFlags::interactable | EFlags::item;
    entity->rarity = Rarity::common;

    entity->weight = 1;
    entity->interactable.on_use_fn_offset = Offset(local::on_use_fn, game_state);
    entity->interactable.on_empty_fn_offset = Offset(Delete_Entity, game_state);
    entity->interactable.uses_count = 1;

    Finalize_Entity(entity, container, game_state);
    return entity;
}


SIG Entity* Create_Bandage(Entity* container, Game_State* game_state)
{
    struct local
    {
        static void on_use_fn(Entity* item, Entity* user, Game_State* game_state)
        {
            Effect_Type::T type = Effect_Type::bleed;

            if(item)
            {
                u64 removed_count = Remove_Effects_Of_Type(user, type, game_state, Verbose::yes);
                if(!removed_count)
                {
                    Print("\n%s wasn't under the the effect of any %s.", Name(user, game_state).ptr, Effect_Type::names[type].ptr);
                }
            }
            else
            {
                Print("Removes all effects of type: %s", Effect_Type::names[type].ptr);
            }
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Bandage"), game_state);
    entity->description_offset = Offset(STR("A clean bandage used for treating open wounds."), game_state);
    entity->flags = EFlags::interactable | EFlags::item;
    entity->rarity = Rarity::common;

    entity->weight = 1;
    entity->interactable.on_use_fn_offset = Offset(local::on_use_fn, game_state);
    entity->interactable.on_empty_fn_offset = Offset(Delete_Entity, game_state);
    entity->interactable.uses_count = 1;

    Finalize_Entity(entity, container, game_state);
    return entity;
}


SIG Entity* Create_Dispeller(Entity* container, Game_State* game_state)
{
    struct local
    {
        static void on_use_fn(Entity* item, Entity* user, Game_State* game_state)
        {
            Effect_Type::T type = Effect_Type::magic;

            if(item)
            {
                u64 removed_count = Remove_Effects_Of_Type(user, type, game_state, Verbose::yes);
                if(!removed_count)
                {
                    Print("\n%s wasn't under the the effect of any %s.", Name(user, game_state).ptr, Effect_Type::names[type].ptr);
                }
            }
            else
            {
                Print("Removes all effects of type: %s", Effect_Type::names[type].ptr);
            }
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Dispeller"), game_state);
    entity->description_offset = Offset(STR("Its shape is a regular tetrahedron. How do you even use this thing?"), game_state);
    entity->flags = EFlags::interactable | EFlags::item;
    entity->rarity = Rarity::common;

    entity->weight = 1;
    entity->interactable.on_use_fn_offset = Offset(local::on_use_fn, game_state);
    entity->interactable.on_empty_fn_offset = Offset(Delete_Entity, game_state);
    entity->interactable.uses_count = 1;

    Finalize_Entity(entity, container, game_state);
    return entity;
}


SIG Entity* Create_Speed_Elixir(Entity* container, Game_State* game_state)
{
    struct local
    {
        static void on_use_fn(Entity* item, Entity* user, Game_State* game_state)
        {
            Dice duration_dice = {1, 4};
            if(item)
            {
                Effect* effect = Request_Effect(game_state);
                effect->stat_modifiers[Stats::speed] = (s16)Get_Stat_Value(user, Stats::arcane, game_state);
                effect->type = Effect_Type::magic;
                effect->name_offset = item->name_offset;
                
                Effect_Instance instance = {};
                instance.source = Offset(item, game_state);
                instance.effect_offset = Offset(effect, game_state);
                instance.duration = Roll(duration_dice, game_state);
                instance.zero_ticked = true;

                Apply_Effect_Result apply = Apply_Effect(user, instance, game_state);
                Push_Generic_Apply_Effect_Message(Name(item, game_state), user, instance, apply, game_state);
            }
            else
            {
                Print("Increases [speed] by [arcane] for %dd%d turn(s).", duration_dice.count, duration_dice.faces);
            }
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Speed Elixir"), game_state);
    entity->description_offset = Offset(STR("A concution that enhances mind and body, making the user much faster."), game_state);
    entity->flags = EFlags::interactable | EFlags::item;
    entity->rarity = Rarity::common;

    entity->weight = 1;
    entity->interactable.on_use_fn_offset = Offset(local::on_use_fn, game_state);
    entity->interactable.on_empty_fn_offset = Offset(Delete_Entity, game_state);
    entity->interactable.uses_count = 1;

    Finalize_Entity(entity, container, game_state);
    return entity;
}


SIG Entity* Create_Might_Elixir(Entity* container, Game_State* game_state)
{
    struct local
    {
        static void on_use_fn(Entity* item, Entity* user, Game_State* game_state)
        {
            Dice duration_dice = {1, 4};
            if(item)
            {
                Effect* effect = Request_Effect(game_state);
                effect->stat_modifiers[Stats::might] = (s16)Get_Stat_Value(user, Stats::arcane, game_state);
                effect->type = Effect_Type::magic;
                effect->name_offset = item->name_offset;
                
                Effect_Instance instance = {};
                instance.source = Offset(item, game_state);
                instance.effect_offset = Offset(effect, game_state);
                instance.duration = Roll(duration_dice, game_state);
                instance.zero_ticked = true;

                Apply_Effect_Result apply = Apply_Effect(user, instance, game_state);
                Push_Generic_Apply_Effect_Message(Name(item, game_state), user, instance, apply, game_state);
            }
            else
            {
                Print("Increases [might] by [arcane] for %dd%d turn(s).", duration_dice.count, duration_dice.faces);
            }
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Might Elixir"), game_state);
    entity->description_offset = Offset(STR("Used by executioners to ensure a clean kill."), game_state);
    entity->flags = EFlags::interactable | EFlags::item;
    entity->rarity = Rarity::common;

    entity->weight = 1;
    entity->interactable.on_use_fn_offset = Offset(local::on_use_fn, game_state);
    entity->interactable.on_empty_fn_offset = Offset(Delete_Entity, game_state);
    entity->interactable.uses_count = 1;

    Finalize_Entity(entity, container, game_state);
    return entity;
}


SIG Entity* Create_Accuracy_Elixir(Entity* container, Game_State* game_state)
{
    struct local
    {
        static void on_use_fn(Entity* item, Entity* user, Game_State* game_state)
        {
            Dice duration_dice = {1, 4};
            if(item)
            {
                Effect* effect = Request_Effect(game_state);
                effect->stat_modifiers[Stats::accuracy] = (s16)Get_Stat_Value(user, Stats::arcane, game_state);
                effect->type = Effect_Type::magic;
                effect->name_offset = item->name_offset;
                
                Effect_Instance instance = {};
                instance.source = Offset(item, game_state);
                instance.effect_offset = Offset(effect, game_state);
                instance.duration = Roll(duration_dice, game_state);
                instance.zero_ticked = true;

                Apply_Effect_Result apply = Apply_Effect(user, instance, game_state);
                Push_Generic_Apply_Effect_Message(Name(item, game_state), user, instance, apply, game_state);
            }
            else
            {
                Print("Increases [accuracy] by [arcane] for %dd%d turn(s).", duration_dice.count, duration_dice.faces);
            }
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Accuracy Elixir"), game_state);
    entity->description_offset = Offset(STR("Enhances accuracy."), game_state);
    entity->flags = EFlags::interactable | EFlags::item;
    entity->rarity = Rarity::common;

    entity->weight = 1;
    entity->interactable.on_use_fn_offset = Offset(local::on_use_fn, game_state);
    entity->interactable.on_empty_fn_offset = Offset(Delete_Entity, game_state);
    entity->interactable.uses_count = 1;

    Finalize_Entity(entity, container, game_state);
    return entity;
}


SIG Entity* Create_Dodge_Elixir(Entity* container, Game_State* game_state)
{
    struct local
    {
        static void on_use_fn(Entity* item, Entity* user, Game_State* game_state)
        {
            Dice duration_dice = {1, 4};
            if(item)
            {
                Effect* effect = Request_Effect(game_state);
                effect->stat_modifiers[Stats::dodge] = (s16)Get_Stat_Value(user, Stats::arcane, game_state);
                effect->type = Effect_Type::magic;
                effect->name_offset = item->name_offset;
                
                Effect_Instance instance = {};
                instance.source = Offset(item, game_state);
                instance.effect_offset = Offset(effect, game_state);
                instance.duration = Roll(duration_dice, game_state);
                instance.zero_ticked = true;

                Apply_Effect_Result apply = Apply_Effect(user, instance, game_state);
                Push_Generic_Apply_Effect_Message(Name(item, game_state), user, instance, apply, game_state);
            }
            else
            {
                Print("Increases [dodge] by [arcane] for %dd%d turn(s).", duration_dice.count, duration_dice.faces);
            }
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Dodge Elixir"), game_state);
    entity->description_offset = Offset(STR("Produced by the Alchemist Monks of the Order Enchantux."), game_state);
    entity->flags = EFlags::interactable | EFlags::item;
    entity->rarity = Rarity::common;

    entity->weight = 1;
    entity->interactable.on_use_fn_offset = Offset(local::on_use_fn, game_state);
    entity->interactable.on_empty_fn_offset = Offset(Delete_Entity, game_state);
    entity->interactable.uses_count = 1;

    Finalize_Entity(entity, container, game_state);
    return entity;
}


SIG Entity* Create_Vitality_Elixir(Entity* container, Game_State* game_state)
{
    struct local
    {
        static void on_use_fn(Entity* item, Entity* user, Game_State* game_state)
        {
            Dice duration_dice = {1, 4};
            if(item)
            {
                Effect* effect = Request_Effect(game_state);
                effect->stat_modifiers[Stats::vitality] = (s16)Get_Stat_Value(user, Stats::arcane, game_state);
                effect->type = Effect_Type::magic;
                effect->name_offset = item->name_offset;
                
                Effect_Instance instance = {};
                instance.source = Offset(item, game_state);
                instance.effect_offset = Offset(effect, game_state);
                instance.duration = Roll(duration_dice, game_state);
                instance.zero_ticked = true;

                Apply_Effect_Result apply = Apply_Effect(user, instance, game_state);
                Push_Generic_Apply_Effect_Message(Name(item, game_state), user, instance, apply, game_state);
            }
            else
            {
                Print("Increases [vitality] by [arcane] for %dd%d turn(s).", duration_dice.count, duration_dice.faces);
            }
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Vitality Elixir"), game_state);
    entity->description_offset = Offset(STR("A key ingredient is blood of the virgin. On of the many reasons the mountainmen raid in civilized lands."), game_state);
    entity->flags = EFlags::interactable | EFlags::item;
    entity->rarity = Rarity::common;

    entity->weight = 1;
    entity->interactable.on_use_fn_offset = Offset(local::on_use_fn, game_state);
    entity->interactable.on_empty_fn_offset = Offset(Delete_Entity, game_state);
    entity->interactable.uses_count = 1;

    Finalize_Entity(entity, container, game_state);
    return entity;
}


SIG Entity* Create_Immunity_Elixir(Entity* container, Game_State* game_state)
{
    struct local
    {
        static void on_use_fn(Entity* item, Entity* user, Game_State* game_state)
        {
            Dice duration_dice = {1, 4};
            if(item)
            {
                Effect* effect = Request_Effect(game_state);
                effect->stat_modifiers[Stats::immunity] = (s16)Get_Stat_Value(user, Stats::arcane, game_state);
                effect->type = Effect_Type::magic;
                effect->name_offset = item->name_offset;
                
                Effect_Instance instance = {};
                instance.source = Offset(item, game_state);
                instance.effect_offset = Offset(effect, game_state);
                instance.duration = Roll(duration_dice, game_state);
                instance.zero_ticked = true;

                Apply_Effect_Result apply = Apply_Effect(user, instance, game_state);
                Push_Generic_Apply_Effect_Message(Name(item, game_state), user, instance, apply, game_state);
            }
            else
            {
                Print("Increases [immunity] by [arcane] for %dd%d turn(s).", duration_dice.count, duration_dice.faces);
            }
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Immunity Elixir"), game_state);
    entity->description_offset = Offset(STR("According to myth these work by introducing weak variants of toxins and diseases to boost immunity."), game_state);
    entity->flags = EFlags::interactable | EFlags::item;
    entity->rarity = Rarity::common;

    entity->weight = 1;
    entity->interactable.on_use_fn_offset = Offset(local::on_use_fn, game_state);
    entity->interactable.on_empty_fn_offset = Offset(Delete_Entity, game_state);
    entity->interactable.uses_count = 1;

    Finalize_Entity(entity, container, game_state);
    return entity;
}


SIG Entity* Create_Arcane_Elixir(Entity* container, Game_State* game_state)
{
    struct local
    {
        static void on_use_fn(Entity* item, Entity* user, Game_State* game_state)
        {
            Dice duration_dice = {1, 4};
            if(item)
            {
                Effect* effect = Request_Effect(game_state);
                effect->stat_modifiers[Stats::arcane] = (s16)Get_Stat_Value(user, Stats::arcane, game_state);
                effect->type = Effect_Type::magic;
                effect->name_offset = item->name_offset;
                
                Effect_Instance instance = {};
                instance.source = Offset(item, game_state);
                instance.effect_offset = Offset(effect, game_state);
                instance.duration = Roll(duration_dice, game_state);
                instance.zero_ticked = true;

                Apply_Effect_Result apply = Apply_Effect(user, instance, game_state);
                Push_Generic_Apply_Effect_Message(Name(item, game_state), user, instance, apply, game_state);
            }
            else
            {
                Print("Increases [arcane] by [arcane] for %dd%d turn(s).", duration_dice.count, duration_dice.faces);
            }
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Arcane Elixir"), game_state);
    entity->description_offset = Offset(STR("The label says \"Always use before any other elixir. - Sold by Enchantux\"."), game_state);
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
        static void on_use_fn(Entity* item, Entity* user, Game_State* game_state)
        {
            s16 dice_faces = 6;

            if(item)
            {
                s16 level = Level(user);
                Dice dice = {1, level};
                String source_name = Name(item, game_state);
                s32 potency = Potency(source_name, level, dice, game_state);
                Heal(user, potency, source_name, Verbose::yes, game_state);
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
    entity->rarity = Rarity::uncommon;

    entity->weight = 1;
    entity->interactable.on_use_fn_offset = Offset(local::on_use_fn, game_state);
    entity->interactable.on_empty_fn_offset = Offset(Delete_Entity, game_state);
    entity->interactable.uses_count = 1;

    Finalize_Entity(entity, container, game_state);
    return entity;
}


SIG Entity* Create_Acid_Flask(Entity* container, Game_State* game_state)
{
    struct local
    {
        static void on_use_fn(Entity* item, Entity* user, Game_State* game_state)
        {
            f32 armor_reduction = 0.5f;
            Dice duration_dice = {2, 4};
            if(item)
            {
                String effect_name = STR("Melt armor");

                s16 potency = (s16)Round_To_S32(Get_Stat_Value(user, Stats::armor, game_state) * armor_reduction);
                
                Effect* effect = Request_Effect(game_state);
                effect->name_offset = Offset(effect_name, game_state);
                effect->type = Effect_Type::magic;
                effect->stat_modifiers[Stats::armor] = -potency;

                Effect_Instance instance = {};
                instance.effect_offset = Offset(effect, game_state);
                instance.source = Offset(item, game_state);
                instance.duration = Roll(duration_dice, game_state);

                String message = String_Builder(&game_state->scratch_buffer).Next(effect_name).Next(STR(" potency is: ")).Next(potency).Finish();
                Push_Message(message, game_state);

                Apply_Effect_Result apply = Apply_Effect(user, instance, game_state);
                Push_Generic_Apply_Effect_Message(Name(item, game_state), user, instance, apply, game_state);
            }
            else
            {
                Print("Reduces the targets armor by %.2f%% for %dd%d rounds.", armor_reduction * 100, duration_dice.count, duration_dice.faces);
            }
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Acid Flask"), game_state);
    entity->description_offset = Offset(STR("Flask of bubbling accid, only the Alchemists of the Eridth school have the know how to make these."), game_state);
    entity->flags = EFlags::interactable | EFlags::item;
    entity->rarity = Rarity::uncommon;

    entity->weight = 2;
    entity->interactable.on_use_fn_offset = Offset(local::on_use_fn, game_state);
    entity->interactable.on_empty_fn_offset = Offset(Delete_Entity, game_state);
    entity->interactable.uses_count = 1;

    Finalize_Entity(entity, container, game_state);
    return entity;
}


SIG Entity* Create_Sticky_Goo(Entity* container, Game_State* game_state)
{
    struct local
    {
        static void on_use_fn(Entity* item, Entity* user, Game_State* game_state)
        {
            f32 dodge_reduction = 0.5f;
            Dice duration_dice = {2, 4};
            if(item)
            {
                String effect_name = STR("Stuck");

                s16 potency = (s16)Round_To_S32(Get_Stat_Value(user, Stats::dodge, game_state) * dodge_reduction);
                
                Effect* effect = Request_Effect(game_state);
                effect->name_offset = Offset(effect_name, game_state);
                effect->type = Effect_Type::magic;
                effect->stat_modifiers[Stats::dodge] = -potency;

                Effect_Instance instance = {};
                instance.effect_offset = Offset(effect, game_state);
                instance.source = Offset(item, game_state);
                instance.duration = Roll(duration_dice, game_state);

                String message = String_Builder(&game_state->scratch_buffer).Next(effect_name).Next(STR(" potency is: ")).Next(potency).Finish();
                Push_Message(message, game_state);

                Apply_Effect_Result apply = Apply_Effect(user, instance, game_state);
                Push_Generic_Apply_Effect_Message(Name(item, game_state), user, instance, apply, game_state);
            }
            else
            {
                Print("Reduces the targets dodge by %.2f%% for %dd%d rounds.", dodge_reduction * 100, duration_dice.count, duration_dice.faces);
            }
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Sticky Goo"), game_state);
    entity->description_offset = Offset(STR("Bundle of really sticky goo, it grows on trees in some tropical land."), game_state);
    entity->flags = EFlags::interactable | EFlags::item;
    entity->rarity = Rarity::uncommon;

    entity->weight = 2;
    entity->interactable.on_use_fn_offset = Offset(local::on_use_fn, game_state);
    entity->interactable.on_empty_fn_offset = Offset(Delete_Entity, game_state);
    entity->interactable.uses_count = 1;

    Finalize_Entity(entity, container, game_state);
    return entity;
}


SIG Entity* Create_Bauble_Of_Bomb_Craft(Entity* container, Game_State* game_state)
{
    struct local
    {
        static void on_use_fn(Entity* item, Entity* user, Game_State* game_state)
        {
            if(item)
            {
                Entity* creation = Create_Bomb(0, game_state);
                creation->flags |= EFlags::visible;
                s32 cap = Carry_Capacity(user, game_state);
                s32 cur = Carrying_Amount(user, game_state);
                
                bool can_carry;
                if(cap - cur >= creation->weight)
                {
                    can_carry = true;
                    Deep_Insert(creation, user, game_state);
                }
                else
                {
                    can_carry = false;
                    Deep_Insert(creation, Pointer(user->residence, game_state), game_state);
                }

                String carry_state = can_carry? STR(".") : STR(", but it was too heavy and had to be dropped on the ground.");
                String message = Format_Message(game_state, "%s creates a %s%s", Name(item, game_state).ptr, Name(creation, game_state).ptr, carry_state.ptr);
                Push_Message(message, game_state);
            }
            else
            {
                Print("Creates a Bomb.");
            }
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Bauble of bomb craft"), game_state);
    entity->description_offset = Offset(STR("Strange and intricate device, that produced explosives."), game_state);
    entity->flags = EFlags::interactable | EFlags::item;
    entity->rarity = Rarity::rare;

    entity->weight = 10;
    entity->interactable.on_use_fn_offset = Offset(local::on_use_fn, game_state);
    entity->interactable.uses_count = UNLIMITED_USES;
    entity->interactable.cd_type = Cooldown_Type::rooms;
    entity->interactable.cd = 4;

    Finalize_Entity(entity, container, game_state);
    return entity;
}


SIG Entity* Create_Bauble_Of_Potion_Craft(Entity* container, Game_State* game_state)
{
    struct local
    {
        static void on_use_fn(Entity* item, Entity* user, Game_State* game_state)
        {
            if(item)
            {
                Entity* creation = Create_Healing_Potion(0, game_state);
                creation->flags |= EFlags::visible;
                s32 cap = Carry_Capacity(user, game_state);
                s32 cur = Carrying_Amount(user, game_state);
                
                bool can_carry;
                if(cap - cur >= creation->weight)
                {
                    can_carry = true;
                    Deep_Insert(creation, user, game_state);
                }
                else
                {
                    can_carry = false;
                    Deep_Insert(creation, Pointer(user->residence, game_state), game_state);
                }

                String carry_state = can_carry? STR(".") : STR(", but it was too heavy and had to be dropped on the ground.");
                String message = Format_Message(game_state, "%s creates a %s%s", Name(item, game_state).ptr, Name(creation, game_state).ptr, carry_state.ptr);
                Push_Message(message, game_state);
            }
            else
            {
                Print("Creates a Healing Potion.");
            }
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Bauble of potion craft"), game_state);
    entity->description_offset = Offset(STR("Strange and intricate device, that produced healing potions."), game_state);
    entity->flags = EFlags::interactable | EFlags::item;
    entity->rarity = Rarity::rare;

    entity->weight = 12;
    entity->interactable.on_use_fn_offset = Offset(local::on_use_fn, game_state);
    entity->interactable.uses_count = UNLIMITED_USES;
    entity->interactable.cd_type = Cooldown_Type::rooms;
    entity->interactable.cd = 5;

    Finalize_Entity(entity, container, game_state);
    return entity;
}


SIG Entity* Create_Restoration_Potion(Entity* container, Game_State* game_state)
{
    struct local
    {
        static s32 Healing_Amount()
        {
            return 1;
        }

        static void On_Turn_Start(Effect_Instance* instance, Entity* target, Game_State* game_state)
        {
            s32 amount = Healing_Amount();
            if(instance)
            {
                Heal(target, amount, Effect_Name(instance, game_state), Verbose::yes, game_state);
            }
            else
            {
                Print("Heals the afflicted by %d point%s.", amount, (amount > 1)? "s" : "");
            }
        }

        static void on_use_fn(Entity* item, Entity* user, Game_State* game_state)
        {
            s32 duration = 5;
            if(item)
            {
                Effect_Instance instance = {};
                instance.source = Offset(item, game_state);
                instance.duration = duration;

                Effect_Hash_Key key = EFFECT_KEY;
                if(!Retrive_Effect(key, &instance.effect_offset, game_state))
                {
                    Effect effect = {};
                    effect.name_offset = Offset(STR("Restoration"), game_state);
                    effect.type = Effect_Type::magic;
                    effect.on_turn_start_fn_offset = Offset(local::On_Turn_Start, game_state);
                    instance.effect_offset = Insert_Effect(effect, key, game_state);
                }

                Apply_Effect_Result apply = Apply_Effect(user, instance, game_state);
                Push_Generic_Apply_Effect_Message(Name(item, game_state), user, instance, apply, game_state);
            }
            else
            {
                Print("Heals %d point%s for %d turn%s.", Healing_Amount(), (Healing_Amount() > 1)? "s" : "", duration, (duration > 1)? "s" : "");
            }
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Restoration Potion"), game_state);
    entity->description_offset = Offset(STR("Gives a warm feeling at the back of the throat."), game_state);
    entity->flags = EFlags::interactable | EFlags::item;
    entity->rarity = Rarity::common;

    entity->weight = 1;
    entity->interactable.on_use_fn_offset = Offset(local::on_use_fn, game_state);
    entity->interactable.on_empty_fn_offset = Offset(Delete_Entity, game_state);
    entity->interactable.uses_count = 1;

    Finalize_Entity(entity, container, game_state);
    return entity;
}


SIG Entity* Create_Herbal_Remedy(Entity* container, Game_State* game_state)
{
    struct local
    {
        static void on_use_fn(Entity* item, Entity* user, Game_State* game_state)
        {
            if(item)
            {
                String source_name = Name(item, game_state);
                s32 potency = Potency(source_name, Level(user), game_state);
                Heal(user, potency, source_name, Verbose::yes, game_state);
            }
            else
            {
                Print("Heals the user by amount equal to level.");
            }
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Herbal remedy"), game_state);
    entity->description_offset = Offset(STR("Crafted from common herbs."), game_state);
    entity->flags = EFlags::interactable | EFlags::item;
    entity->rarity = Rarity::common;

    entity->weight = 1;
    entity->interactable.on_use_fn_offset = Offset(local::on_use_fn, game_state);
    entity->interactable.on_empty_fn_offset = Offset(Delete_Entity, game_state);
    entity->interactable.uses_count = 1;

    Finalize_Entity(entity, container, game_state);
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
                String source_name = Name(item, game_state);
                s32 damage = Potency(source_name, base, dice, game_state);

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
                String source_name = Name(item, game_state);
                String message = String_Builder(&game_state->messages_buffer, source_name)
                .Next(STR(" potency is: "))
                .Next(damage)
                .Next(STR(" (["))
                .Next(Stats::name[Stats::arcane])
                .Next(STR("]:"))
                .Next(base)
                .Next(STR(" + "))
                .Next(dice.count)
                .Next(STR("d"))
                .Next(dice.faces)
                .Next(STR(" = "))
                .Next(dice_result)
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
    entity->rarity = Rarity::uncommon;

    entity->weight = 4;
    entity->interactable.on_use_fn_offset = Offset(local::on_use_fn, game_state);
    entity->interactable.on_empty_fn_offset = Offset(Delete_Entity, game_state);
    entity->interactable.uses_count = 1;

    Finalize_Entity(entity, container, game_state);
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
    entity->rarity = Rarity::rare;
    entity->name_offset = Offset(STR("Steak & mashed potatoes"), game_state);
    entity->description_offset = Offset(STR("Medium rare."), game_state);
    entity->food_quality = Food_Quality::meal;
    entity->weight = 2;

    Finalize_Entity(entity, room, game_state);
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