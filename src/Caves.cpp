

// ===================================
// Copyright (c) 2025 by Valtteri Kois
// All rights reserved.
// ===================================


SIG void Generate_Entrance_Room(Entity* room, Game_State* game_state)
{
    char room_description[] = 
    "The mountainside here is steep. Almost vertical. There is a massive arch carved into the stone.\n"
    "On top of it, there is a placard that says \"This is where champions are born and charlatans fall.\"\n"
    "Inside the arch there is a cave entrance. Light does not seem to be able to penetrate the threshold.\n"
    "You can not see inside.";

    room->name_offset = Offset(STR("The Entrance"), game_state);
    room->description_offset = Offset(STR(room_description), game_state);

    //Spawn_All_Items_In_Loot_Table(Basic_Consumables_Loot_Table(game_state), room, game_state);
    //Spawn_All_Items_In_Loot_Table(Basic_Trinkets_Loot_Table(game_state), room, game_state);
    //Spawn_All_Items_In_Loot_Table(Basic_Weapons_Loot_Table(game_state), room, game_state);
    //Spawn_All_Items_In_Loot_Table(Basic_Armors_Loot_Table(game_state), room, game_state);

    Create_Assasin_Bandit(room, game_state);
}


SIG Loot_Table Caves_Wildlife_Section(Game_State* game_state)
{
    struct local
    {

        static void Generic_Ambush(Game_State* game_state, f32 change)
        {
            if(change)
            {
                Set_Ambush_Change(change, game_state);
            }

            {
                Ambush_Option* option = Create_Ambush_Option(70, game_state);
                Add_Ambush_Creature_Spawner(option, {Offset(Create_Giant_Rat, game_state), 1, 3}, game_state);
            }

            {
                Ambush_Option* option = Create_Ambush_Option(40, game_state);
                Add_Ambush_Creature_Spawner(option, {Offset(Create_Giant_Rat, game_state), 2}, game_state);
                Add_Ambush_Creature_Spawner(option, {Offset(Create_Blight_Rat, game_state), 1}, game_state);
            }

            {
                Ambush_Option* option = Create_Ambush_Option(30, game_state);
                Add_Ambush_Creature_Spawner(option, {Offset(Create_Mutant_Hedgehog, game_state), 1}, game_state);
            }

            {
                Ambush_Option* option = Create_Ambush_Option(5, game_state);
                Add_Ambush_Creature_Spawner(option, {Offset(Create_Living_Vine, game_state), 1}, game_state);
            }

            {
                Ambush_Option* option = Create_Ambush_Option(3, game_state);
                Add_Ambush_Creature_Spawner(option, {Offset(Create_Small_Earth_Golem, game_state), 2}, game_state);
            }

            {
                Ambush_Option* option = Create_Ambush_Option(1, game_state);
                Add_Ambush_Creature_Spawner(option, {Offset(Create_Earth_Golem, game_state), 1}, game_state);
            }
        }

        static void Ambush_Ants(Game_State* game_state, f32 change)
        {
            if(change)
            {
                Set_Ambush_Change(change, game_state);
            }

            {
                Ambush_Option* option = Create_Ambush_Option(10, game_state);
                Add_Ambush_Creature_Spawner(option, {Offset(Create_Enlarged_Ant, game_state), 4, 6}, game_state);
            }
        }


        static void Ambush_Wolf(Game_State* game_state, f32 change)
        {
            if(change)
            {
                Set_Ambush_Change(change, game_state);
            }

            {
                Ambush_Option* option = Create_Ambush_Option(5, game_state);
                Add_Ambush_Creature_Spawner(option, {Offset(Create_Wolf, game_state), 2, 4}, game_state);
            }

            {
                Ambush_Option* option = Create_Ambush_Option(1, game_state);
                Add_Ambush_Creature_Spawner(option, {Offset(Create_Giant_Honey_Badger, game_state), 1}, game_state);
            }
        }


        static void Ambush_Swamp(Game_State* game_state, f32 change)
        {
            if(change)
            {
                Set_Ambush_Change(change, game_state);
            }

            {
                Ambush_Option* option = Create_Ambush_Option(10, game_state);
                Add_Ambush_Creature_Spawner(option, {Offset(Create_Mosquito, game_state), 1, 3}, game_state);
            }

            {
                Ambush_Option* option = Create_Ambush_Option(10, game_state);
                Add_Ambush_Creature_Spawner(option, {Offset(Create_Giant_Toad, game_state), 1, 2}, game_state);
            }

            {
                Ambush_Option* option = Create_Ambush_Option(10, game_state);
                Add_Ambush_Creature_Spawner(option, {Offset(Create_Leech, game_state), 2}, game_state);
            }

            {
                Ambush_Option* option = Create_Ambush_Option(5, game_state);
                Add_Ambush_Creature_Spawner(option, {Offset(Create_Mosquito, game_state), 2}, game_state);
                Add_Ambush_Creature_Spawner(option, {Offset(Create_Giant_Toad, game_state), 1}, game_state);
            }
        }


        static Entity* Supply_Room(Entity* fill_room_if_greater_than_zero, Game_State* game_state)
        {
            Entity* room = Request_Entity(game_state);
            room->rarity = Rarity::legendary;
            if(fill_room_if_greater_than_zero)
            {
                room->name_offset = Offset(STR("a supply room"), game_state);
                char room_description[] = 
                "Entrance here was well hidden, behind a heavy rock and through a tight crawlspace, but what a splendor!\n"
                "It is a supply room; someone has been collecting and neatly organising weapons, armor, and other supplies here.";
                room->description_offset = Offset(STR(room_description), game_state);

                Create_Chest(room, game_state);
                Create_Bookshelf(room, game_state);
                Create_Supply_Crate(room, game_state);
                Create_Alchemists_Pouch(room, game_state);

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


        static Entity* Swamp(Entity* fill_room_if_greater_than_zero, Game_State* game_state)
        {
            Entity* room = Request_Entity(game_state);
            room->rarity = Rarity::epic;
            if(fill_room_if_greater_than_zero)
            {
                Ambush_Swamp(game_state, 0.2f);

                room->name_offset = Offset(STR("a bog"), game_state);
                char room_description[] = 
                "As you take your next step, you suddenly sink waist deep into black water.\n"
                "You find your self in an underground swamp.";
                room->description_offset = Offset(STR(room_description), game_state);

                switch(Roll(4, game_state))
                {
                    case 1:
                    {
                        u64 mcount = 2 + Per_Count_Rolled_Square_Weighted_Random(2, game_state);
                        LOOP(mcount) Create_Mosquito(room, game_state);

                        Create_Leech(room, game_state);
                        Create_Giant_Toad(room, game_state);
                    }break;
                    
                    case 2:
                    {
                        Create_Mosquito(room, game_state);
                        Create_Giant_Toad(room, game_state);
                    }break;

                    case 3:
                    {
                        Create_Leech(room, game_state);
                        Create_Mosquito(room, game_state);
                        Create_Snake(room, game_state);
                    }break;

                    case 4:
                    {
                        LOOP(2) Create_Mosquito(room, game_state);
                        Create_Blight_Rat(room, game_state);
                    }break;
                }

                Generate_Standard_Random_Loot(room, game_state);
            }

            return room;
        }


        static Entity* Forest(Entity* fill_room_if_greater_than_zero, Game_State* game_state)
        {
            Entity* room = Request_Entity(game_state);
            room->rarity = Rarity::rare;
            if(fill_room_if_greater_than_zero)
            {
                Ambush_Wolf(game_state, 0.1f);

                room->name_offset = Offset(STR("a forest"), game_state);
                char room_description[] = 
                "As you approach, the hard rock under your feet gives away to soft soil.\n"
                "Plants grow here, even trees. The roof opens up and up above you can see the sky!\n"
                "The open air feels cold, but fresh.";
                room->description_offset = Offset(STR(room_description), game_state);

                if(Roll(3, game_state) > 1)
                {
                    u64 count = 1 + Per_Count_Rolled_Random(3, 3, game_state);
                    LOOP(count) Create_Wolf(room, game_state);
                }
                else
                {
                    Create_Living_Vine(room, game_state);
                }

                Generate_Standard_Random_Loot(room, game_state);
            }

            return room;
        }


        static Entity* Wounded_Bear(Entity* fill_room_if_greater_than_zero, Game_State* game_state)
        {
            Entity* room = Request_Entity(game_state);
            room->rarity = Rarity::legendary;
            if(fill_room_if_greater_than_zero)
            {
                Generic_Ambush(game_state, 0.07f);
                Ambush_Wolf(game_state, 0);

                room->name_offset = Offset(STR("the hunting grounds"), game_state);
                char room_description[] = 
                "Wolves are circling around a bear. The bear looks at you with pleading eyes, as if it was asking for help.";
                room->description_offset = Offset(STR(room_description), game_state);

                Entity* cave_bear = Create_Cave_Bear(room, game_state);
                cave_bear->faction = Faction::player;
                cave_bear->_threat = 350.f;

                LOOP(6) Create_Wolf(room, game_state);
                
                Create_Alchemists_Pouch(room, game_state);
                Generate_Standard_Random_Loot(room, game_state);
            }

            return room;
        }


        static Entity* Stream(Entity* fill_room_if_greater_than_zero, Game_State* game_state)
        {
            Entity* room = Request_Entity(game_state);
            if(fill_room_if_greater_than_zero)
            {
                Ambush_Wolf(game_state, 0.3f);

                room->name_offset = Offset(STR("a stream"), game_state);
                char room_description[] = 
                "A stream of water flows along the path.";
                room->description_offset = Offset(STR(room_description), game_state);

                u64 count = 1 + Per_Count_Rolled_Random(2, 2, game_state);
                LOOP(count) Create_Wolf(room, game_state);

                Generate_Standard_Random_Loot(room, game_state);
            }

            return room;
        }


        static Entity* Den(Entity* fill_room_if_greater_than_zero, Game_State* game_state)
        {
            Entity* room = Request_Entity(game_state);
            room->rarity = Rarity::epic;
            if(fill_room_if_greater_than_zero)
            {
                Ambush_Wolf(game_state, 0.9f);

                room->name_offset = Offset(STR("a wolf den"), game_state);
                char room_description[] = 
                "The wolfs look upon you with confused eyes, a pray just wandered into their den?\n"
                "No need for hunting this week. Rat tastes awful anyway.";
                room->description_offset = Offset(STR(room_description), game_state);

                LOOP(5) Create_Wolf(room, game_state);
                Create_Chest(room, game_state);

                Generate_Standard_Random_Loot(room, game_state);
            }

            return room;
        }


        static Entity* Mound(Entity* fill_room_if_greater_than_zero, Game_State* game_state)
        {
            Entity* room = Request_Entity(game_state);
            if(fill_room_if_greater_than_zero)
            {
                Generic_Ambush(game_state, 0.5f);

                room->name_offset = Offset(STR("the breeding grounds"), game_state);
                char room_description[] = 
                "It looks (and smells) like, this is where the foul rats come to breed.";
                room->description_offset = Offset(STR(room_description), game_state);


                u64 mounds = 3 + Per_Count_Rolled_Square_Weighted_Random(3, game_state);
                LOOP(mounds) Create_Rat_Mound(room, game_state);
                
                Generate_Standard_Random_Loot(room, game_state);
            }

            return room;
        }


        static Entity* Cave(Entity* fill_room_if_greater_than_zero, Game_State* game_state)
        {
            Entity* room = Request_Entity(game_state);
            if(fill_room_if_greater_than_zero)
            {
                Generic_Ambush(game_state, 0.5f);

                room->name_offset = Offset(STR("a cave"), game_state);
                char room_description[] = 
                "Walls are naturaly formed stone. The path leads downwards.";
                room->description_offset = Offset(STR(room_description), game_state);

                Create_Giant_Rat(room, game_state);
                
                Generate_Standard_Random_Loot(room, game_state);
            }

            return room;
        }


        static Entity* Opening(Entity* fill_room_if_greater_than_zero, Game_State* game_state)
        {
            Entity* room = Request_Entity(game_state);
            if(fill_room_if_greater_than_zero)
            {
                Generic_Ambush(game_state, 0.1f);

                room->name_offset = Offset(STR("a wide opening"), game_state);
                char room_description[] = 
                "The stone walls extend into the unseeable darkness. The ceiling must be very far away.\n"
                "In the black you can see bright glowing eyes moving towards you.";
                room->description_offset = Offset(STR(room_description), game_state);

                if(Roll(4, game_state) > 1)
                {
                    u32 dudes = 1 + (Roll(3, game_state) == 1);
                    LOOP(dudes) Create_Giant_Rat(room, game_state);
                    if(Roll(3, game_state) == 1) Create_Rat_Mound(room, game_state);
                }
                else
                {
                    LOOP(2) Create_Wolf(room, game_state);
                }

                
                Generate_Standard_Random_Loot(room, game_state);
            }

            return room;
        }


        static Entity* Hallway(Entity* fill_room_if_greater_than_zero, Game_State* game_state)
        {
            // TODO: Auto turret thing?
            Entity* room = Request_Entity(game_state);
            if(fill_room_if_greater_than_zero)
            {
                Generic_Ambush(game_state, 0.01f);

                room->name_offset = Offset(STR("a long hallway"), game_state);
                char room_description[] = 
                "In the dark path ahead you can something moving.\n";
                room->description_offset = Offset(STR(room_description), game_state);
                
                Loot_Table_Entry entries[] = 
                {
                    {Create_Giant_Rat,          5},
                    {Create_Wolf,               2},
                    {Create_Giant_Honey_Badger, 1},
                };
                
                Loot_Table table = {entries, Array_Length(entries), true};
                Generate_From_Loot_Table(room, table, 1, {}, game_state);
                
                Generate_Standard_Random_Loot(room, game_state);
            }

            return room;
        }

        static Entity* Burrow(Entity* fill_room_if_greater_than_zero, Game_State* game_state)
        {
            Entity* room = Request_Entity(game_state);
            if(fill_room_if_greater_than_zero)
            {
                Generic_Ambush(game_state, 0.05f);

                room->name_offset = Offset(STR("a burrow"), game_state);
                char room_description[] = 
                "A dark and tight space. There is very little room to manuver.\n";
                room->description_offset = Offset(STR(room_description), game_state);
                
                Create_Giant_Honey_Badger(room, game_state);
                
                Generate_Standard_Random_Loot(room, game_state);
            }

            return room;
        }

        static Entity* Recent_Battlefield(Entity* fill_room_if_greater_than_zero, Game_State* game_state)
        {
            Entity* room = Request_Entity(game_state);
            if(fill_room_if_greater_than_zero)
            {
                Generic_Ambush(game_state, 0.3f);
                Ambush_Ants(game_state, 0);

                room->name_offset = Offset(STR("a battlefield"), game_state);
                char room_description[] = 
                "It looks like a group goblins and humans recently fought here. The dead were unceremoniously left where they had fallen.";
                room->description_offset = Offset(STR(room_description), game_state);

                Create_Blight_Rat(room, game_state);

                Arena_Snapshot snapshot = Snapshot(&game_state->scratch_buffer);
                Generate_From_Loot_Table
                (
                    room, 
                    Basic_Merged_Loot_Table(game_state), 
                    Roll(3, game_state), 
                    Rules_Builder().Rarity(Comparison::maximum, Rarity::common).Finish(), 
                    game_state
                );

                Generate_From_Loot_Table
                (
                    room, 
                    Basic_Weapons_Loot_Table(game_state), 
                    1 + Per_Count_Rolled_Square_Weighted_Random(3, game_state), 
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
            room->rarity = Rarity::magical;
            if(fill_room_if_greater_than_zero)
            {
                Generic_Ambush(game_state, 0.5f);

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
                Set_Ambush_Change(0.9f, game_state);
                
                {
                    Ambush_Option* option = Create_Ambush_Option(70, game_state);
                    Add_Ambush_Creature_Spawner(option, {Offset(Create_Giant_Rat, game_state), 1, 3}, game_state);
                }

                {
                    Ambush_Option* option = Create_Ambush_Option(40, game_state);
                    Add_Ambush_Creature_Spawner(option, {Offset(Create_Giant_Rat, game_state), 2}, game_state);
                    Add_Ambush_Creature_Spawner(option, {Offset(Create_Blight_Rat, game_state), 1}, game_state);
                }

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
                
                Generate_Standard_Random_Loot(room, game_state);

                if(Roll(3, game_state) == 1) Create_Chest(room, game_state);
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

                Create_Mushroom(room, game_state);

                u64 creature = Roll(12, game_state);
                
                Loot_Table_Entry entries[] = 
                {
                    {Create_Giant_Rat,          15},
                    {Create_Mutant_Hedgehog,    3},
                    {Create_Giant_Honey_Badger, 3},
                    {Create_Blight_Rat,         6},
                    {Create_Wolf,               8},
                };
                
                Loot_Table table = {entries, Array_Length(entries), true};
                Generate_From_Loot_Table(room, table, 1, {}, game_state);


                Entity* bandit = Create_Bandit(room, game_state);
                bandit->_health = 0;

                if(Roll(10, game_state) == 1) Create_Chest(room, game_state);
            }

            return room;
        }


        static Entity* Empty_Cavern(Entity* fill_room_if_greater_than_zero, Game_State* game_state)
        {
            Entity* room = Request_Entity(game_state);
            room->rarity = Rarity::magical;
            if(fill_room_if_greater_than_zero)
            {
                room->name_offset = Offset(STR("a cavern"), game_state);
                char room_description[] = 
                "There doesn't seem to be anything of interest here.";
                room->description_offset = Offset(STR(room_description), game_state);
            }

            return room;
        }


        static Entity* Chamber(Entity* fill_room_if_greater_than_zero, Game_State* game_state)
        {
            Entity* room = Request_Entity(game_state);
            room->rarity = Rarity::rare;
            if(fill_room_if_greater_than_zero)
            {
                room->name_offset = Offset(STR("a chamber"), game_state);
                char room_description[] = 
                "You open a heavy door and step through. It is a small chamber, obviously man made.";
                room->description_offset = Offset(STR(room_description), game_state);

                if(Roll(4, game_state) == 1) Create_Earth_Golem(room, game_state);
                if(Roll(3, game_state) == 1) Create_Alchemists_Pouch(room, game_state);

                u64 r = Roll(5, game_state);
                switch(r)
                {
                    case 1:
                    {
                        Create_Supply_Crate(room, game_state);
                    }break;

                    case 2:
                    {
                        Create_Armor_Rack(room, game_state);
                    }break;

                    case 3:
                    {
                        Create_Weapon_Rack(room, game_state);
                    }break;

                    case 4:
                    {
                        Create_Bookshelf(room, game_state);
                    }break;

                    case 5:
                    {
                        Create_Chest(room, game_state);
                    }break;
                }
            }

            return room;
        }


        static Entity* Earthen_Hall(Entity* fill_room_if_greater_than_zero, Game_State* game_state)
        {
            Entity* room = Request_Entity(game_state);
            room->rarity = Rarity::epic;
            if(fill_room_if_greater_than_zero)
            {
                Generic_Ambush(game_state, 0.2f);

                room->name_offset = Offset(STR("the Earthen Hall"), game_state);
                char room_description[] = 
                "A grand hall made of uniform stone. It's like everything here, including the furniture,\n"
                "was made by carving out the stone around. Not even dwarfs can build like this.";
                room->description_offset = Offset(STR(room_description), game_state);

                Create_Earth_Golem(room, game_state);
                
                LOOP(2) Create_Small_Earth_Golem(room, game_state);

                LOOP(2) Create_Chest(room, game_state);
                Create_Bookshelf(room, game_state);
            }

            return room;
        }


        static Entity* Mudpit(Entity* fill_room_if_greater_than_zero, Game_State* game_state)
        {
            Entity* room = Request_Entity(game_state);
            if(fill_room_if_greater_than_zero)
            {
                Generic_Ambush(game_state, 0.15f);

                room->name_offset = Offset(STR("Mud pit"), game_state);
                char room_description[] = 
                "A wet muddy pit.";
                room->description_offset = Offset(STR(room_description), game_state);

                switch(Roll(4, game_state))
                {
                    case 1:
                    {
                        LOOP(2) Create_Small_Earth_Golem(room, game_state);
                    }break;

                    case 2: 
                    {
                        Create_Giant_Honey_Badger(room, game_state);
                    }break;

                    case 3:
                    {
                        Create_Living_Vine(room, game_state);
                    }break;
                }

                Generate_Standard_Random_Loot(room, game_state);
            }

            return room;
        }


        static Entity* Warzone(Entity* fill_room_if_greater_than_zero, Game_State* game_state)
        {
            Entity* room = Request_Entity(game_state);
            room->rarity = Rarity::magical;
            if(fill_room_if_greater_than_zero)
            {
                Generic_Ambush(game_state, 0.7f);
                Ambush_Ants(game_state, 0);

                room->name_offset = Offset(STR("a battlefield"), game_state);
                char room_description[] = 
                "Ants and rats are fighting over a corpse.\n";
                room->description_offset = Offset(STR(room_description), game_state);

                u64 rats = 3 + (Roll(3, game_state) == 1);
                u64 ants = 5 + Roll(4, game_state);

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
                Ambush_Ants(game_state, 1.0);

                room->name_offset = Offset(STR("an ant nest"), game_state);
                char room_description[] = 
                "The blackess around you is moving. If you focus hard on single spot you realise that,\n"
                "everything from the floor to the ceiling is covered in layers and layers of interleaving ants.";
                room->description_offset = Offset(STR(room_description), game_state);

                Entity* bandit = Create_Enlarged_Ant_Queen(room, game_state);

                Generate_Standard_Random_Loot(room, game_state);

                Create_Chest(room, game_state);
            }

            return room;
        }


        static Entity* Abandoned_Camp(Entity* fill_room_if_greater_than_zero, Game_State* game_state)
        {
            Entity* room = Request_Entity(game_state);
            if(fill_room_if_greater_than_zero)
            {
                Generic_Ambush(game_state, 0.1f);
                Ambush_Ants(game_state, 0);

                room->name_offset = Offset(STR("an abandoned camp"), game_state);
                char room_description[] = 
                "You can see torn up tents. There is also a firepit, but is has gone cold a long time ago.";
                room->description_offset = Offset(STR(room_description), game_state);

                switch(Roll(4, game_state))
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
                        Create_Giant_Honey_Badger(room, game_state);
                    }break;
                    
                    case 4:
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

                Create_Supply_Crate(room, game_state);
                
                if(Roll(3, game_state) == 1) Create_Bookshelf(room, game_state);
                
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
                Set_Ambush_Change(1.f, game_state);
                
                {
                    Ambush_Option* option = Create_Ambush_Option(1, game_state);
                    Add_Ambush_Creature_Spawner(option, {Offset(Create_Clear_Ambush_Table_Dummy_Entity, game_state), 1}, game_state);
                    Add_Ambush_Creature_Spawner(option, {Offset(Create_Cave_Bear, game_state), 1}, game_state);
                }

                room->name_offset = Offset(STR("a beasts lair"), game_state);
                char room_description[] = 
                "In the middle of the room there is what looks to you to be a \"bed\" of sorts.\n"
                "It's made of tree branches and leaves. Around it there are many half eaten carcasses.\n"
                "Some of them animals, others human... or humanoid. You can not tell.";
                room->description_offset = Offset(STR(room_description), game_state);

                u32 dudes = 1 + (Roll(4, game_state) == 1);
                LOOP(dudes) Create_Bear_Cub(room, game_state);
                if(Roll(10, game_state) == 1) Create_Chest(room, game_state);

                Generate_Standard_Random_Loot(room, game_state);
            }

            return room;
        }
    };

    local_storage Loot_Table_Entry entries[] = 
    {
        {local::Opening},           // 1
        {local::Carcase},           // 2
        {local::Abandoned_Camp},    // 3
        {local::Ant_Nest},          // 4
        {local::Warzone},           // 5
        {local::Small_Rat_Nest},    // 6
        {local::Empty_Cavern},      // 7
        {local::Beast_Lair},        // 8
        {local::Graveyard},         // 9
        {local::Recent_Battlefield},// 10
        {local::Hallway},           // 11
        {local::Supply_Room},       // 12
        {local::Den},               // 13
        {local::Forest},            // 14
        {local::Stream},            // 15
        {local::Chamber},           // 16
        {local::Burrow},            // 17
        {local::Earthen_Hall},      // 18
        {local::Mudpit},            // 19
        {local::Wounded_Bear},      // 20
        {local::Swamp},             // 21
        {local::Mound},             // 22
        {local::Cave},              // 23
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
        {Caves_Wildlife_Section(game_state), 10}, 
        {Caves_Bandit_Section(game_state),   5}, 
        {Caves_Spider_Section(game_state),   5}, 
        {Caves_Boss(game_state), 1}
    };

    Level_Segments level = {segments, Array_Length(segments)};
    return level;
}