

// ===================================
// Copyright (c) 2025 by Valtteri Kois
// All rights reserved.
// ===================================

#include "../../src/LibPrimordial/Primitives.h"
#include "../../src/LibPrimordial/Basic.cpp"
#include "../../src/LibPrimordial/String.cpp"
#include "../../src/LibPrimordial/Arena.cpp"

char* banner = 
"\n"
"// ===================================\n"
"// Copyright (c) %d by Valtteri Kois\n"
"// All rights reserved.\n"
"// ===================================\n";

char* warning = 
"\n// --- This is a generated file. Do not edit manually! ---\n\n\n";
   
char* code =
"SIG Entity* Manual_Of_%s_Attack(Entity* container, Game_State* game_state)\n"
"{\n"
"    struct local \n"
"    {\n"
"        static void on_use_fn(Entity* item, Entity* user, Game_State* game_state)\n"
"        {\n"
"            Attack_Mod::T mod = Attack_Mod::%s;\n"
"            String attack_name = Attack_Mod::name[mod];\n"
"\n"
"            if(item)\n"
"            {\n"
"                Print(\"\\nYou have learned how use the %%s attack.\", attack_name.ptr);\n"
"                user->known_attack_modifiers |= Attack_Modifier_Mask(mod); \n"
"            }\n"
"            else\n"
"            {\n"
"                Print(\"Teaches the user the %%s attack modifier.\", attack_name.ptr);\n"
"            } \n"
"        }\n"
"    };\n"
"\n"
"    Entity* entity = Request_Entity(game_state);\n"
"\n"
"    entity->name_offset = Offset(STR(\"Manual of %s attack\"), game_state);\n"
"    entity->description_offset = Offset(STR(\"A skill book.\"), game_state);\n"
"    entity->flags = EFlags::interactable | EFlags::item;\n"
"    entity->rarity = Rarity::rare;\n"
"\n"
"    entity->weight = 1;\n"
"    entity->interactable.on_use_fn_offset = Offset(local::on_use_fn, game_state);\n"
"    entity->interactable.on_empty_fn_offset = Offset(Delete_Entity, game_state);\n"
"    entity->interactable.uses_count = 1;\n"
"\n"
"    Finalize_Entity(entity, container, game_state);\n"
"    return entity;\n"
"}\n\n\n";

#include <stdio.h>


void gen(String name_string, Arena* arena)
{
    Clear(arena, Zero_Memory::no);

    String capital_name_string = {};
    capital_name_string.ptr = Push_String(arena, name_string, &capital_name_string.length);
    Push(arena, 1); // null terminator!
    capital_name_string.ptr[0] = To_Uppercase(First(capital_name_string));

    char* name = name_string.ptr;
    char* capital_name = capital_name_string.ptr;
    printf(code, capital_name, name, name);
}

void loot_table(String* attacks, u64 count, Arena* arena)
{
    char* header =
    "SIG Loot_Table Skill_Books_Loot_Table(Game_State* game_state)\n"
    "{\n"
    "    local_storage Loot_Table_Entry entries[] =\n"
    "    {\n";
    printf(header);
    for(u64 i = 0; i < count; ++i)
    {
        Clear(arena, Zero_Memory::no);

        String capital_name_string = {};
        capital_name_string.ptr = Push_String(arena, attacks[i], &capital_name_string.length);
        Push(arena, 1); // null terminator!
        capital_name_string.ptr[0] = To_Uppercase(First(capital_name_string));

        printf("        {Manual_Of_%s_Attack},\n", capital_name_string.ptr);
    }
    char* footer =
    "    };\n"
    "\n"
    "    local_storage Loot_Table table = {entries, Array_Length(entries)};\n"
    "    Fill_Loot_Table_Changes_And_Item_Rarity(&table, game_state);"
    "\n"
    "    return table;\n"
    "}\n";
    printf(footer);
}



int main(int argc, char** argv)
{
    String attacks[] = 
    {
        STR("reckless"),
        STR("careful"),
        STR("weakspot"),
        STR("allin"),
        STR("disarming"),
        STR("guarding"),
        STR("evasive"),
        STR("vampiric"),
        STR("blessed"),
        STR("berserking"),
        STR("execute"),
        STR("redirect"),
        STR("change"),
        STR("cleansing"),
        STR("thieving"),
    };

    printf(banner, 2025);
    printf(warning);

    Arena arena = Create_Arena(Kilobytes(4), 1);

    for(u64 i = 0; i < Array_Length(attacks); ++i)
    {
	   gen(attacks[i], &arena);
    }

    loot_table(attacks, Array_Length(attacks), &arena);
}