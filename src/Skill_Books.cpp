
// ===================================
// Copyright (c) 2025 by Valtteri Kois
// All rights reserved.
// ===================================

// --- This is a generated file. Do not edit manually! ---


SIG Entity* Manual_Of_Reckless_Attack(Entity* container, Game_State* game_state)
{
    struct local 
    {
        static void on_use_fn(Entity* item, Entity* user, Game_State* game_state)
        {
            Attack_Mod::T mod = Attack_Mod::reckless;
            String attack_name = Attack_Mod::name[mod];

            if(item)
            {
                Print("\nYou have learned how use the %s attack.", attack_name.ptr);
                user->known_attack_modifiers |= Attack_Modifier_Mask(mod); 
            }
            else
            {
                Print("Teaches the user the %s attack modifier.", attack_name.ptr);
            } 
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Manual of reckless attack"), game_state);
    entity->description_offset = Offset(STR("A skill book."), game_state);
    entity->flags = EFlags::interactable | EFlags::item;
    entity->rarity = Rarity::rare;

    entity->weight = 1;
    entity->interactable.on_use_fn_offset = Offset(local::on_use_fn, game_state);
    entity->interactable.on_empty_fn_offset = Offset(Delete_Entity, game_state);
    entity->interactable.uses_count = 1;

    Finalize_Entity(entity, container, game_state);
    return entity;
}


SIG Entity* Manual_Of_Careful_Attack(Entity* container, Game_State* game_state)
{
    struct local 
    {
        static void on_use_fn(Entity* item, Entity* user, Game_State* game_state)
        {
            Attack_Mod::T mod = Attack_Mod::careful;
            String attack_name = Attack_Mod::name[mod];

            if(item)
            {
                Print("\nYou have learned how use the %s attack.", attack_name.ptr);
                user->known_attack_modifiers |= Attack_Modifier_Mask(mod); 
            }
            else
            {
                Print("Teaches the user the %s attack modifier.", attack_name.ptr);
            } 
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Manual of careful attack"), game_state);
    entity->description_offset = Offset(STR("A skill book."), game_state);
    entity->flags = EFlags::interactable | EFlags::item;
    entity->rarity = Rarity::rare;

    entity->weight = 1;
    entity->interactable.on_use_fn_offset = Offset(local::on_use_fn, game_state);
    entity->interactable.on_empty_fn_offset = Offset(Delete_Entity, game_state);
    entity->interactable.uses_count = 1;

    Finalize_Entity(entity, container, game_state);
    return entity;
}


SIG Entity* Manual_Of_Weakspot_Attack(Entity* container, Game_State* game_state)
{
    struct local 
    {
        static void on_use_fn(Entity* item, Entity* user, Game_State* game_state)
        {
            Attack_Mod::T mod = Attack_Mod::weakspot;
            String attack_name = Attack_Mod::name[mod];

            if(item)
            {
                Print("\nYou have learned how use the %s attack.", attack_name.ptr);
                user->known_attack_modifiers |= Attack_Modifier_Mask(mod); 
            }
            else
            {
                Print("Teaches the user the %s attack modifier.", attack_name.ptr);
            } 
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Manual of weakspot attack"), game_state);
    entity->description_offset = Offset(STR("A skill book."), game_state);
    entity->flags = EFlags::interactable | EFlags::item;
    entity->rarity = Rarity::rare;

    entity->weight = 1;
    entity->interactable.on_use_fn_offset = Offset(local::on_use_fn, game_state);
    entity->interactable.on_empty_fn_offset = Offset(Delete_Entity, game_state);
    entity->interactable.uses_count = 1;

    Finalize_Entity(entity, container, game_state);
    return entity;
}


SIG Entity* Manual_Of_Allin_Attack(Entity* container, Game_State* game_state)
{
    struct local 
    {
        static void on_use_fn(Entity* item, Entity* user, Game_State* game_state)
        {
            Attack_Mod::T mod = Attack_Mod::allin;
            String attack_name = Attack_Mod::name[mod];

            if(item)
            {
                Print("\nYou have learned how use the %s attack.", attack_name.ptr);
                user->known_attack_modifiers |= Attack_Modifier_Mask(mod); 
            }
            else
            {
                Print("Teaches the user the %s attack modifier.", attack_name.ptr);
            } 
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Manual of allin attack"), game_state);
    entity->description_offset = Offset(STR("A skill book."), game_state);
    entity->flags = EFlags::interactable | EFlags::item;
    entity->rarity = Rarity::rare;

    entity->weight = 1;
    entity->interactable.on_use_fn_offset = Offset(local::on_use_fn, game_state);
    entity->interactable.on_empty_fn_offset = Offset(Delete_Entity, game_state);
    entity->interactable.uses_count = 1;

    Finalize_Entity(entity, container, game_state);
    return entity;
}


SIG Entity* Manual_Of_Disarming_Attack(Entity* container, Game_State* game_state)
{
    struct local 
    {
        static void on_use_fn(Entity* item, Entity* user, Game_State* game_state)
        {
            Attack_Mod::T mod = Attack_Mod::disarming;
            String attack_name = Attack_Mod::name[mod];

            if(item)
            {
                Print("\nYou have learned how use the %s attack.", attack_name.ptr);
                user->known_attack_modifiers |= Attack_Modifier_Mask(mod); 
            }
            else
            {
                Print("Teaches the user the %s attack modifier.", attack_name.ptr);
            } 
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Manual of disarming attack"), game_state);
    entity->description_offset = Offset(STR("A skill book."), game_state);
    entity->flags = EFlags::interactable | EFlags::item;
    entity->rarity = Rarity::rare;

    entity->weight = 1;
    entity->interactable.on_use_fn_offset = Offset(local::on_use_fn, game_state);
    entity->interactable.on_empty_fn_offset = Offset(Delete_Entity, game_state);
    entity->interactable.uses_count = 1;

    Finalize_Entity(entity, container, game_state);
    return entity;
}


SIG Entity* Manual_Of_Guarding_Attack(Entity* container, Game_State* game_state)
{
    struct local 
    {
        static void on_use_fn(Entity* item, Entity* user, Game_State* game_state)
        {
            Attack_Mod::T mod = Attack_Mod::guarding;
            String attack_name = Attack_Mod::name[mod];

            if(item)
            {
                Print("\nYou have learned how use the %s attack.", attack_name.ptr);
                user->known_attack_modifiers |= Attack_Modifier_Mask(mod); 
            }
            else
            {
                Print("Teaches the user the %s attack modifier.", attack_name.ptr);
            } 
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Manual of guarding attack"), game_state);
    entity->description_offset = Offset(STR("A skill book."), game_state);
    entity->flags = EFlags::interactable | EFlags::item;
    entity->rarity = Rarity::rare;

    entity->weight = 1;
    entity->interactable.on_use_fn_offset = Offset(local::on_use_fn, game_state);
    entity->interactable.on_empty_fn_offset = Offset(Delete_Entity, game_state);
    entity->interactable.uses_count = 1;

    Finalize_Entity(entity, container, game_state);
    return entity;
}


SIG Entity* Manual_Of_Evasive_Attack(Entity* container, Game_State* game_state)
{
    struct local 
    {
        static void on_use_fn(Entity* item, Entity* user, Game_State* game_state)
        {
            Attack_Mod::T mod = Attack_Mod::evasive;
            String attack_name = Attack_Mod::name[mod];

            if(item)
            {
                Print("\nYou have learned how use the %s attack.", attack_name.ptr);
                user->known_attack_modifiers |= Attack_Modifier_Mask(mod); 
            }
            else
            {
                Print("Teaches the user the %s attack modifier.", attack_name.ptr);
            } 
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Manual of evasive attack"), game_state);
    entity->description_offset = Offset(STR("A skill book."), game_state);
    entity->flags = EFlags::interactable | EFlags::item;
    entity->rarity = Rarity::rare;

    entity->weight = 1;
    entity->interactable.on_use_fn_offset = Offset(local::on_use_fn, game_state);
    entity->interactable.on_empty_fn_offset = Offset(Delete_Entity, game_state);
    entity->interactable.uses_count = 1;

    Finalize_Entity(entity, container, game_state);
    return entity;
}


SIG Entity* Manual_Of_Vampiric_Attack(Entity* container, Game_State* game_state)
{
    struct local 
    {
        static void on_use_fn(Entity* item, Entity* user, Game_State* game_state)
        {
            Attack_Mod::T mod = Attack_Mod::vampiric;
            String attack_name = Attack_Mod::name[mod];

            if(item)
            {
                Print("\nYou have learned how use the %s attack.", attack_name.ptr);
                user->known_attack_modifiers |= Attack_Modifier_Mask(mod); 
            }
            else
            {
                Print("Teaches the user the %s attack modifier.", attack_name.ptr);
            } 
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Manual of vampiric attack"), game_state);
    entity->description_offset = Offset(STR("A skill book."), game_state);
    entity->flags = EFlags::interactable | EFlags::item;
    entity->rarity = Rarity::rare;

    entity->weight = 1;
    entity->interactable.on_use_fn_offset = Offset(local::on_use_fn, game_state);
    entity->interactable.on_empty_fn_offset = Offset(Delete_Entity, game_state);
    entity->interactable.uses_count = 1;

    Finalize_Entity(entity, container, game_state);
    return entity;
}


SIG Entity* Manual_Of_Blessed_Attack(Entity* container, Game_State* game_state)
{
    struct local 
    {
        static void on_use_fn(Entity* item, Entity* user, Game_State* game_state)
        {
            Attack_Mod::T mod = Attack_Mod::blessed;
            String attack_name = Attack_Mod::name[mod];

            if(item)
            {
                Print("\nYou have learned how use the %s attack.", attack_name.ptr);
                user->known_attack_modifiers |= Attack_Modifier_Mask(mod); 
            }
            else
            {
                Print("Teaches the user the %s attack modifier.", attack_name.ptr);
            } 
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Manual of blessed attack"), game_state);
    entity->description_offset = Offset(STR("A skill book."), game_state);
    entity->flags = EFlags::interactable | EFlags::item;
    entity->rarity = Rarity::rare;

    entity->weight = 1;
    entity->interactable.on_use_fn_offset = Offset(local::on_use_fn, game_state);
    entity->interactable.on_empty_fn_offset = Offset(Delete_Entity, game_state);
    entity->interactable.uses_count = 1;

    Finalize_Entity(entity, container, game_state);
    return entity;
}


SIG Entity* Manual_Of_Berserking_Attack(Entity* container, Game_State* game_state)
{
    struct local 
    {
        static void on_use_fn(Entity* item, Entity* user, Game_State* game_state)
        {
            Attack_Mod::T mod = Attack_Mod::berserking;
            String attack_name = Attack_Mod::name[mod];

            if(item)
            {
                Print("\nYou have learned how use the %s attack.", attack_name.ptr);
                user->known_attack_modifiers |= Attack_Modifier_Mask(mod); 
            }
            else
            {
                Print("Teaches the user the %s attack modifier.", attack_name.ptr);
            } 
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Manual of berserking attack"), game_state);
    entity->description_offset = Offset(STR("A skill book."), game_state);
    entity->flags = EFlags::interactable | EFlags::item;
    entity->rarity = Rarity::rare;

    entity->weight = 1;
    entity->interactable.on_use_fn_offset = Offset(local::on_use_fn, game_state);
    entity->interactable.on_empty_fn_offset = Offset(Delete_Entity, game_state);
    entity->interactable.uses_count = 1;

    Finalize_Entity(entity, container, game_state);
    return entity;
}


SIG Entity* Manual_Of_Execute_Attack(Entity* container, Game_State* game_state)
{
    struct local 
    {
        static void on_use_fn(Entity* item, Entity* user, Game_State* game_state)
        {
            Attack_Mod::T mod = Attack_Mod::execute;
            String attack_name = Attack_Mod::name[mod];

            if(item)
            {
                Print("\nYou have learned how use the %s attack.", attack_name.ptr);
                user->known_attack_modifiers |= Attack_Modifier_Mask(mod); 
            }
            else
            {
                Print("Teaches the user the %s attack modifier.", attack_name.ptr);
            } 
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Manual of execute attack"), game_state);
    entity->description_offset = Offset(STR("A skill book."), game_state);
    entity->flags = EFlags::interactable | EFlags::item;
    entity->rarity = Rarity::rare;

    entity->weight = 1;
    entity->interactable.on_use_fn_offset = Offset(local::on_use_fn, game_state);
    entity->interactable.on_empty_fn_offset = Offset(Delete_Entity, game_state);
    entity->interactable.uses_count = 1;

    Finalize_Entity(entity, container, game_state);
    return entity;
}


SIG Entity* Manual_Of_Redirect_Attack(Entity* container, Game_State* game_state)
{
    struct local 
    {
        static void on_use_fn(Entity* item, Entity* user, Game_State* game_state)
        {
            Attack_Mod::T mod = Attack_Mod::redirect;
            String attack_name = Attack_Mod::name[mod];

            if(item)
            {
                Print("\nYou have learned how use the %s attack.", attack_name.ptr);
                user->known_attack_modifiers |= Attack_Modifier_Mask(mod); 
            }
            else
            {
                Print("Teaches the user the %s attack modifier.", attack_name.ptr);
            } 
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Manual of redirect attack"), game_state);
    entity->description_offset = Offset(STR("A skill book."), game_state);
    entity->flags = EFlags::interactable | EFlags::item;
    entity->rarity = Rarity::rare;

    entity->weight = 1;
    entity->interactable.on_use_fn_offset = Offset(local::on_use_fn, game_state);
    entity->interactable.on_empty_fn_offset = Offset(Delete_Entity, game_state);
    entity->interactable.uses_count = 1;

    Finalize_Entity(entity, container, game_state);
    return entity;
}


SIG Entity* Manual_Of_Change_Attack(Entity* container, Game_State* game_state)
{
    struct local 
    {
        static void on_use_fn(Entity* item, Entity* user, Game_State* game_state)
        {
            Attack_Mod::T mod = Attack_Mod::change;
            String attack_name = Attack_Mod::name[mod];

            if(item)
            {
                Print("\nYou have learned how use the %s attack.", attack_name.ptr);
                user->known_attack_modifiers |= Attack_Modifier_Mask(mod); 
            }
            else
            {
                Print("Teaches the user the %s attack modifier.", attack_name.ptr);
            } 
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Manual of change attack"), game_state);
    entity->description_offset = Offset(STR("A skill book."), game_state);
    entity->flags = EFlags::interactable | EFlags::item;
    entity->rarity = Rarity::rare;

    entity->weight = 1;
    entity->interactable.on_use_fn_offset = Offset(local::on_use_fn, game_state);
    entity->interactable.on_empty_fn_offset = Offset(Delete_Entity, game_state);
    entity->interactable.uses_count = 1;

    Finalize_Entity(entity, container, game_state);
    return entity;
}


SIG Entity* Manual_Of_Cleansing_Attack(Entity* container, Game_State* game_state)
{
    struct local 
    {
        static void on_use_fn(Entity* item, Entity* user, Game_State* game_state)
        {
            Attack_Mod::T mod = Attack_Mod::cleansing;
            String attack_name = Attack_Mod::name[mod];

            if(item)
            {
                Print("\nYou have learned how use the %s attack.", attack_name.ptr);
                user->known_attack_modifiers |= Attack_Modifier_Mask(mod); 
            }
            else
            {
                Print("Teaches the user the %s attack modifier.", attack_name.ptr);
            } 
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Manual of cleansing attack"), game_state);
    entity->description_offset = Offset(STR("A skill book."), game_state);
    entity->flags = EFlags::interactable | EFlags::item;
    entity->rarity = Rarity::rare;

    entity->weight = 1;
    entity->interactable.on_use_fn_offset = Offset(local::on_use_fn, game_state);
    entity->interactable.on_empty_fn_offset = Offset(Delete_Entity, game_state);
    entity->interactable.uses_count = 1;

    Finalize_Entity(entity, container, game_state);
    return entity;
}


SIG Entity* Manual_Of_Thieving_Attack(Entity* container, Game_State* game_state)
{
    struct local 
    {
        static void on_use_fn(Entity* item, Entity* user, Game_State* game_state)
        {
            Attack_Mod::T mod = Attack_Mod::thieving;
            String attack_name = Attack_Mod::name[mod];

            if(item)
            {
                Print("\nYou have learned how use the %s attack.", attack_name.ptr);
                user->known_attack_modifiers |= Attack_Modifier_Mask(mod); 
            }
            else
            {
                Print("Teaches the user the %s attack modifier.", attack_name.ptr);
            } 
        }
    };

    Entity* entity = Request_Entity(game_state);

    entity->name_offset = Offset(STR("Manual of thieving attack"), game_state);
    entity->description_offset = Offset(STR("A skill book."), game_state);
    entity->flags = EFlags::interactable | EFlags::item;
    entity->rarity = Rarity::rare;

    entity->weight = 1;
    entity->interactable.on_use_fn_offset = Offset(local::on_use_fn, game_state);
    entity->interactable.on_empty_fn_offset = Offset(Delete_Entity, game_state);
    entity->interactable.uses_count = 1;

    Finalize_Entity(entity, container, game_state);
    return entity;
}


SIG Loot_Table Skill_Books_Loot_Table(Game_State* game_state)
{
    local_storage Loot_Table_Entry entries[] =
    {
        {Manual_Of_Reckless_Attack},
        {Manual_Of_Careful_Attack},
        {Manual_Of_Weakspot_Attack},
        {Manual_Of_Allin_Attack},
        {Manual_Of_Disarming_Attack},
        {Manual_Of_Guarding_Attack},
        {Manual_Of_Evasive_Attack},
        {Manual_Of_Vampiric_Attack},
        {Manual_Of_Blessed_Attack},
        {Manual_Of_Berserking_Attack},
        {Manual_Of_Execute_Attack},
        {Manual_Of_Redirect_Attack},
        {Manual_Of_Change_Attack},
        {Manual_Of_Cleansing_Attack},
        {Manual_Of_Thieving_Attack},
    };

    local_storage Loot_Table table = {entries, Array_Length(entries)};
    Fill_Loot_Table_Changes_And_Item_Rarity(&table, game_state);
    return table;
}
