

// ===================================
// Copyright (c) 2025 by Valtteri Kois
// All rights reserved.
// ===================================

// TODO: Collapse entity_offset and reference... why do I have both?
// TODO: Test equipping the same ring twice.
// TODO: Make room picking based on a range. 20% up and and down from distance travelled.
// TODO: Add a conformation on proceeding when under an effect with a rounds duration. I.E. Are you sure you wish to travel under the the effect of the "Poison"?
// TODO: Confimation on drop if the item is equipped.
// TODO: Visualise apply poison rolls, also make it integer check not a float so it can be represented by a "dice".
// TODO: Level up / Rest mechanic.
// TODO: Make Loot command usable on items in the inventory.
// TODO: Consumable with a CD. Currenty acrhitecture does not support this. Large sacale effort?
// TODO: Consumable stacking.
// TODO: Make effect iterators survive deletions... Effects_Root_Node* iteration ID. iterator ID also stored in the effect instance when iterated, skip effect if ID already same as iterator. 
// Nuke the ID when an effect is deleted. at least a good catch against tampering, but also start over the iteration skipping over the ones with last runs ID. Replace with this runs ID incase delete happens again.

// TODO: Implement More attack modifiers
// TODO: Make help command describe common effects.


#define DEVMODE      1
#define SEED         0
#define RANDOM_SEED  0
#define SAVE_ON_EXIT 0
#define ENABLE_WAIT  0
#define ENTRANCE     1
#define QUICKSTART   1

#include <stdio.h>
#include <stdarg.h> // TODO: Dig in this include and see what the fuck it does. Maybe I can do it my self and remove the include.

#define Print printf
#define Terminate(MSG) Print("[FATAL ERROR]: %s\nAborting... FILE: %s  LINE: %lu\n", MSG, __FILE__, __LINE__); *((s32*)0) = 666 
#define Warn(MSG) Print("\n[WARNING]: %s FILE:%s LINE:%lu", MSG, __FILE__, __LINE__)

#include "LibPrimordial\Primitives.h"

#include "HEADACHE_OUTPUT.h" // NOTE: Generated file!

#include "LibPrimordial\Basic.cpp"
#include "LibPrimordial\Maths.cpp"
#include "LibPrimordial\String.cpp"
#include "LibPrimordial\Arena.cpp"
#include "LibPrimordial\Win32.cpp"

#include "Dungeon.h"
#include "Generated_Offsets.cpp"

#include "Effects.cpp"
#include "Items.cpp"
#include "Factory.cpp"


SIG char* Get_Output_Color_CSTR(ANSI_Color_Buffer* buffer, u8 red, u8 green, u8 blue)
{
    char* format_string = "\x1b[38;2;%hhu;%hhu;%hhum";
    s32 size = snprintf(buffer->data, Array_Length(buffer->data), format_string, red, green, blue);
    Assert(size + 1 < Array_Length(buffer->data));

    return buffer->data;
}


SIG char* Get_Output_Color_CSTR(ANSI_Color_Buffer* buffer, Color color)
{
    char* result = Get_Output_Color_CSTR(buffer, color.r, color.g, color.b);
    return result;
}


SIG void Set_Output_Color(u8 red, u8 green, u8 blue)
{
    ANSI_Color_Buffer buffer;
    char* c = Get_Output_Color_CSTR(&buffer, red, green, blue);
    Print("%s", c);
}


SIG void Set_Output_Color(Color color)
{
    Set_Output_Color(color.r, color.g, color.b);
}


SIG char* Entity_Color(Entity* entity, Game_State* game_state)
{
    char* result = game_state->default_color.data;
    if(entity->flags & EFlags::actor)
    {
        if(entity->faction != Faction::none)
        {
            Entity* player = Dereference(game_state->player, game_state);
            if(entity->faction == player->faction)
            {
                result = game_state->ally_color.data;
            }
            else
            {
                result = game_state->enemy_color.data;
            }
        }
    }
    else if(Is_Item(entity))
    {
        result = game_state->rarity_colors[entity->rarity].data;
    }

    return result;
}


SIG String Format_Message(Game_State* game_state, char* format_string, ...)
{
    // https://cplusplus.com/reference/cstdio/vsnprintf/

    va_list args;
    va_start(args, format_string); // The fuck do these actually do?

    s32 size = vsnprintf(0, 0, format_string, args) + 1;
    String message = {(char*)Push(&game_state->messages_buffer, size), u64(size) - 1};
    s32 size2 = vsnprintf(message.ptr, size, format_string, args) + 1;
    
    Assert(size);
    Assert(size == size2);

    va_end(args);
    return message;
}


SIG _inline void Flush_Messages(Game_State* game_state)
{
    game_state->messages = {};
    Clear(&game_state->messages_buffer, Zero_Memory::no);
}


SIG _inline void Print_Messages(Game_State* game_state)
{
    if(game_state->messages.count)
    {
        for(u64 i = 0; i < game_state->messages.count; ++i)
        {
            String str = game_state->messages.ctrl_block[i];
            Wait(0.8, game_state);
            Print("\n%s", str.ptr);
        }

        Wait(1, game_state);
    }

    Flush_Messages(game_state);
}


SIG void Push_Message(String message, Game_State* game_state)
{
    Assert(message.ptr && message.length);

    String* new_ctrl_block = Push_Array(&game_state->messages_buffer, String, game_state->messages.count + 1);
    
    Mem_Copy(new_ctrl_block, game_state->messages.ctrl_block, sizeof(String) * game_state->messages.count);
    
    // NOTE: This intentionally "leaks" the old control block memory.
    game_state->messages.ctrl_block = new_ctrl_block;
    game_state->messages.ctrl_block[game_state->messages.count] = message;
    game_state->messages.count += 1;
}


SIG void Wait(f64 seconds, Game_State* game_state)
{
    if(game_state->enable_dramatic_pausing)
    {
        OS_Sleep(seconds);
    }
}


SIG String Get_User_Input(Game_State* game_state)
{
    u64 size = Kilobytes(2);
    Assert(size <= u64(U32_MAX));
    
    char* user_input_buffer = Push_Array(&game_state->scratch_buffer, char, size);
    fgets(user_input_buffer, (s32)(size - 1), stdin);
    
    u64 length = Null_Terminated_Length(user_input_buffer) - 2;
     
    // NOTE: Remove the newline character from the end of the user input buffer.
    *(user_input_buffer + length) = 0;
    
    String result = {user_input_buffer, length};
    
    return result;
}


SIG bool User_Query_Yes_No(Game_State* game_state)
{
    bool result = false;
    bool again;
    do
    {
        Print(" Use \"yes\" or \"no\" :");
        again = false;
        
        String user_input = Get_User_Input(game_state);
        
        bool yes = Match_Case_Insensitive(user_input, STR("yes")) || Match_Case_Insensitive(user_input, STR("y"));
        bool no = Match_Case_Insensitive(user_input, STR("no")) || Match_Case_Insensitive(user_input, STR("n"));
        if(0);
        else if(yes)
        {
            result = true;
        }
        else if(no)
        {
            result = false;
        }
        else
        {
            Print("\nInvalid input. Please try again.");
            again = true;
        }
    }
    while(again);
    
    return result;
}


SIG Reference* Find_Empty_Slot(Entity_Node* node)
{
    Reference* result = 0;
    
    Reference* first = node->entities;
    Reference* last = first + Array_Length(node->entities);
    
    for(Reference* ref = first; ref < last; ++ref)
    {
        if(!ref->offset)
        {
            Assert(ref->ID == 0);
            
            result = ref;
            break;
        }
    }
    
    return result;
}


SIG _inline Entity_Offset Offset(Entity* entity, Game_State* game_state)
{
    Entity_Offset offset = {};
    if(entity)
    {
        offset = {Storage_Offset(entity, game_state)};
    }

    return offset;
}


SIG _inline Entity* Pointer(Entity_Offset offset, Game_State* game_state)
{
    Entity* pointer = {};
    if(offset.v)
    {
        pointer = (Entity*)Pull_From_Storage_Offset(offset.v, game_state);
    }

    return pointer;
}


SIG _inline Effect_Offset Offset(Effect* effect, Game_State* game_state)
{
    Effect_Offset offset = {};
    if(effect)
    {
        Assert(effect->ID);
        offset = {Storage_Offset(effect, game_state), effect->ID};
    }

    return offset;
}


SIG _inline Effect* Pointer(Effect_Offset offset, Game_State* game_state)
{
    Effect* pointer = {};
    if(offset.v)
    {
        pointer = (Effect*)Pull_From_Storage_Offset(offset.v, game_state);
        Assert(offset.ID == pointer->ID);
    }

    return pointer;
}


SIG _inline Entity_Node_Offset Offset(Entity_Node* entity_node, Game_State* game_state)
{
    Entity_Node_Offset offset = {};
    if(entity_node)
    {
        offset = {Storage_Offset(entity_node, game_state)};
    }

    return offset;
}


SIG _inline Entity_Node* Pointer(Entity_Node_Offset offset, Game_State* game_state)
{
    Entity_Node* pointer = {};
    if(offset.v)
    {
        pointer = (Entity_Node*)Pull_From_Storage_Offset(offset.v, game_state);
    }

    return pointer;
}


SIG _inline Effects_Node_Offset Offset(Effects_Node* effects_node, Game_State* game_state)
{
    Effects_Node_Offset offset = {};
    if(effects_node)
    {
        offset = {Storage_Offset(effects_node, game_state)};
    }

    return offset;
}


SIG _inline Effects_Node* Pointer(Effects_Node_Offset offset, Game_State* game_state)
{
    Effects_Node* pointer = {};
    if(offset.v)
    {
        pointer = (Effects_Node*)Pull_From_Storage_Offset(offset.v, game_state);
    }

    return pointer;
}


SIG String Unwrap_String(String_Wrapper* strw, Game_State* game_state)
{
    char* ptr = (char*)Pull_From_Storage_Offset(strw->offset, game_state);
    String result = {ptr, strw->length};
    return result;
}


SIG String_Offset Offset(String str, Game_State* game_state)
{
    String_Offset offset = {};

    // CONSIDER: Instead of searching the bucketed array for a match, it might sence to use hash table.
    // but the table is only for "registeration", so this is not code that runs often.


    // - Look for a string in the string_table that matches the provided one.
    // - If one is found, return the offset to that one.
    // - Otherwise, push the string data into the permanent storage and,
    // add a field in the string_table that describes the lenght and location of the new string.


    if(str.ptr && str.length)
    {
        String_Table_Root* string_table_root = &game_state->string_table;
        String_Table* table = (String_Table*)Pull_From_Storage_Offset(string_table_root->table_offset, game_state);
        u64 count = string_table_root->count;
        
        while(table)
        {
            for(u64 i = 0; i < count; ++i)
            {
                String_Wrapper* strw = table->entries + i;
                Assert(strw->offset && strw->length);
                String cmp = Unwrap_String(strw, game_state);

                if(Match_Case_Sensitive(str, cmp))
                {
                    offset.v = Storage_Offset(strw, game_state);
                    goto EXIT;
                }
            }

            count = Array_Length(table->entries);
            table = (String_Table*)Pull_From_Storage_Offset(table->next_offset, game_state);
        }

        // No match was found if *HERE* is reached.
        if(string_table_root->count == Array_Length(table->entries))
        {
            String_Table* node = Push_Struct(&game_state->permanent_storage, String_Table);
            node->next_offset = string_table_root->table_offset;
            string_table_root->table_offset = Storage_Offset(node, game_state);
            string_table_root->count = 0;
        }
        
        char* data = (char*)Push(&game_state->permanent_storage, str.length + 1);
        Mem_Copy(data, str.ptr, str.length);

        table = (String_Table*)Pull_From_Storage_Offset(string_table_root->table_offset, game_state);
        String_Wrapper* strw = table->entries + string_table_root->count;
        string_table_root->count += 1;

        strw->length = str.length;
        strw->offset = Storage_Offset(data, game_state);

        offset.v = Storage_Offset(strw, game_state);

        EXIT:;
    }

    return offset;
}


SIG String Get_String(String_Offset offset, Game_State* game_state)
{
    String str = {};
    if(offset.v)
    {
        String_Wrapper* strw = (String_Wrapper*)Pull_From_Storage_Offset(offset.v, game_state);
        str = Unwrap_String(strw, game_state);
    }

    return str;
}


SIG _inline u64 Storage_Offset(void* ptr, Game_State* game_state)
{
    u64 result = 0;
    if(ptr)
    {
        Assert(ptr >= game_state->permanent_storage.memory);
        result = ((u8*)ptr - game_state->permanent_storage.memory) + 1;
    }

    return result;
}


SIG _inline void* Pull_From_Storage_Offset(u64 offset, Game_State* game_state)
{
    void* result = 0;
    if(offset)
    {
        u8* base_address = game_state->permanent_storage.memory;
        result = base_address + (offset - 1);
    }
    
    return result;
}


SIG Reference* Find_Entity(Entity* entity, Entity_Root_Node* storage, Game_State* game_state, Entity_Node** out_node DEF(0))
{
    Reference* result = 0;
    
    Entity_Iterator iter = Make_Iterator(storage, game_state);

    u64 entity_offset = Storage_Offset(entity, game_state);

    while(Reference* ref = Next(&iter))
    {
        if(ref->offset == entity_offset)
        {
            Assert(Dereference(ref, game_state));
            
            if(out_node)
            {
                *out_node = iter.node;
            }
            result = ref;
        }
    }
    
    return result;
}


SIG Entity* Find_Entity_By_Name_Or_Reference_Number(Entity* actor, Reference space, String name_or_reference_number, Game_State* game_state, Verbose::T verbose DEF(Verbose::T(1)))
{
    Entity* result = 0;
    if(Entity* room = Dereference(space, game_state))
    {
        result = Find_Entity_By_Name_Or_Reference_Number(actor, room, name_or_reference_number, game_state, verbose);
    }

    return result;
}


SIG Entity* Find_Entity_By_Name(Entity* actor, Entity* space, String name, Game_State* game_state, Verbose::T verbose DEF(Verbose::T(1)))
{
    Entity* target = 0;

    Entity_Iterator iter = Make_Iterator(space, game_state);
    while(Entity* entity = Next_Entity(&iter))
    {
        String entity_name = Get_String(entity->name_offset, game_state);
        if(entity != actor && Match_Case_Insensitive(entity_name, name))
        {
            target = entity;
            break;
        }
    }
    
    if(!target && verbose)
    {
        Print("\nThe target name (%s) used as an argument did not match any entity.", name.ptr);
    }

    return target;
}


SIG Entity* Find_Entity_By_Name_Or_Reference_Number(Entity* actor, Entity* space, String name_or_reference_number, Game_State* game_state, Verbose::T verbose DEF(Verbose::T(1)))
{
    name_or_reference_number = Skip_Zeroes(name_or_reference_number);
    
    Entity* target = 0;

    if(space && name_or_reference_number.length)
    {
        if(Is_Positive_Integer(name_or_reference_number))
        {
            // Okey.. convert string to int.
            
            u64 target_idx = To_U64(name_or_reference_number);
            if(target_idx)
            {
                // Because the actor it self does not "count" we have to do the dumb thing and iterate through the bucket to find the actor.
                // Sort of would have to anyway because the storage does not support random access, but you could something smarter than
                // actual full iteration. Like walk the link list until you're in the right bucket and then jump to the right one.
                
                u64 entity_count = 0;
                Entity_Iterator iter = Make_Iterator(space, game_state);
                while(Entity* entity = Next_Entity(&iter))
                {
                    if(entity != actor)
                    {
                        entity_count += 1;
                        if(target_idx == entity_count)
                        {
                            target = entity;
                            break;
                        }
                    }
                }
            }
            
            if(!target && verbose)
            {
                Print("\nThe reference number (%llu) used as an argument did not match any entity.", target_idx);
            }
        }
        else
        {
            target = Find_Entity_By_Name(actor, space, name_or_reference_number, game_state, verbose);
        }
    }
    
    return target;
}


SIG Reference Make_Reference(Entity* entity, Game_State* game_state)
{
    Assert(entity->ID);
    u64 offset = Storage_Offset(entity, game_state);
    Reference result = {offset, entity->ID};
    return result;
}


SIG Entity* Dereference(Reference* reference, Game_State* game_state) 
{
    Entity* result = 0;
    if(reference->ID)
    {
        Assert(reference->offset);
        u64 offset = reference->offset - 1;

        result = (Entity*)(game_state->permanent_storage.memory + offset);

        if(result->ID != reference->ID)
        {
            result = 0;
        }
    }
    
    return result;
};


SIG Entity* Dereference(Reference reference, Game_State* game_state)
{
    Entity* result = Dereference(&reference, game_state);
    return result;
};


SIG Entity_Iterator Make_Iterator(Entity_Root_Node* root, Game_State* game_state)
{
    Entity_Iterator iter = {0};
    if(root && root->node_offset.v)
    {
        iter.node = Pointer(root->node_offset, game_state);
        iter.count = root->count;
        
        iter.game_state = game_state;
        
        #if SLOW
        iter.root = root;
        iter.count_snapshot = root->count;
        #endif
    }
    
    
    Assert((iter.node && iter.count > 0 && iter.count <= Array_Length(iter.node->entities)) || (!iter.node && iter.count == 0));

    return iter;
}


SIG Entity_Iterator Make_Iterator(Entity* entity, Game_State* game_state)
{
    Entity_Root_Node* inv = &entity->inventory;
    Entity_Iterator iter = Make_Iterator(inv, game_state);
    return iter;
}


SIG Effects_Iterator Make_Iterator(Effects_Root* root, Game_State* game_state)
{
    Effects_Iterator iter = {};
    iter.game_state     = game_state;
    iter.current_node   = Pointer(root->root_offset, game_state);
    iter.last_node      = Pointer(root->head_offset, game_state);
    iter.count          = (iter.current_node == iter.last_node)? root->head_count : Array_Length(iter.current_node->instances);
    iter.head_count     = root->head_count;

    Assert
    (
        (iter.head_count && iter.current_node && iter.count > 0 && iter.count <= Array_Length(iter.current_node->instances)) || 
        (!iter.current_node && !iter.last_node && iter.count == 0)
    );
    
    return iter;
}


SIG Reference* Next(Entity_Iterator* iter)
{
    Reference* element = {};
    if(iter->root)
    {
        Assert(iter->root->count == iter->count_snapshot); // Iterator invalidated!
        Assert(iter->idx <= iter->count);
        
        if(iter->idx == iter->count)
        {
            if(Entity_Node* next_node = Pointer(iter->node->next, iter->game_state))
            {
                iter->count = Array_Length(iter->node->entities);
                iter->node = next_node;
                iter->idx = 0;
            }
            else
            {
                return 0;
            }
        }
        
        element = iter->node->entities + iter->idx;
        iter->idx += 1;
    }
    
    return element;
}


SIG Entity* Next_Entity(Entity_Iterator* iter)
{
    Entity* result = 0;
    Reference* ref = Next(iter);
    if(ref)
    {
        result = Dereference(ref, iter->game_state);
        Assert(result);
    }
    
    return result;
}


SIG u64 Count(Entity_Root_Node* root_node, Game_State* game_state)
{
    u64 c = 0;
    Entity_Iterator iter = Make_Iterator(root_node, game_state);
    while(Reference* entity = Next(&iter))
    {
        c += 1;
    }

    return c;
}


SIG bool Memory_Snapshot_Save(String file_path, Game_State* game_state)
{
    String buffer = To_String(&game_state->permanent_storage);
    bool success = OS_Write_File(buffer, file_path, &game_state->scratch_buffer);

    return success;
}


SIG bool Memory_Snapshot_Restore(String file_path, Game_State* game_state)
{
    bool result = false;
    
    String buffer = OS_Read_File(file_path, &game_state->scratch_buffer);
    if(buffer.length && buffer.ptr)
    {
        result = true;        
        
        Arena permanent_storage = game_state->permanent_storage;
        Arena scratch_buffer = game_state->scratch_buffer;
        Arena messages_buffer = game_state->messages_buffer;
        
        Clear(&permanent_storage, Zero_Memory::yes);
        void* dest = Push(&permanent_storage, buffer.length);
        Mem_Copy(dest, buffer.ptr, buffer.length);
        Clear(&messages_buffer, Zero_Memory::yes);
        Clear(&scratch_buffer, Zero_Memory::yes);

        game_state->executable_base_address = (char*)OS_Get_Executable_Base_Address();
        game_state->permanent_storage = permanent_storage;
        game_state->messages_buffer = messages_buffer;
        game_state->scratch_buffer = scratch_buffer;
        game_state->loaded = true;
        
        Flush_Messages(game_state);
    }

    return result;
}


SIG Effect_Instance* Next_Effect_Instance(Effects_Iterator* iter)
{
    Assert(iter->idx <= iter->count);

    Effect_Instance* result = 0;
    if(iter->current_node)
    {
        if(iter->idx == iter->count)
        {
            if(iter->current_node != iter->last_node)
            {
                Effects_Node* next_node = Pointer(iter->current_node->next, iter->game_state);
                Assert(next_node);

                iter->count = (next_node == iter->last_node)? iter->head_count : Array_Length(iter->current_node->instances);
                iter->current_node = next_node;
                iter->idx = 0;
            }
            else
            {
                goto END;
            }
        }
        
        result = iter->current_node->instances + iter->idx;
        iter->idx += 1;
    }
    
    END:;
    return result;
}


SIG _inline Effect_Instance* Next(Effects_Iterator* iter)
{
    Effect_Instance* instance = Next_Effect_Instance(iter);
    return instance;
}


SIG Effect* Next_Effect(Effects_Iterator* iter)
{
    Effect* result = 0;
    
    Effect_Instance* next = Next_Effect_Instance(iter);
    if(next)
    {
        result = Pointer(next->effect_offset, iter->game_state);
    }
    
    return result;
}


SIG Backwards_Iterator Make_Backwards_Iterator(Entity_Root_Node* root, Game_State* game_state)
{
    Entity_Node* last = Pointer(root->node_offset, game_state);
    while(last->next.v)
    {
        last = Pointer(last->next, game_state);
    }
    u64 count = (root->node_offset.v == Storage_Offset(last, game_state))? root->count : Array_Length(last->entities);
    
    Backwards_Iterator back_iter = {root, last, count - 1, game_state};
    return back_iter;
}


SIG Reference* Previous(Backwards_Iterator* back_iter)
{
    // TODO: Rewrite this. This version of the function was quickly hacked together to get offset based nodes to compile, but...
    // it really should be done with more thought.

    Game_State* game_state = back_iter->game_state;

    Assert(game_state);

    Reference* ref = 0;
    if(back_iter->node)
    {
        ref = back_iter->node->entities + back_iter->index;
        if(back_iter->index == 0)
        {
            Entity_Root_Node* root = back_iter->root;
            
            u64 offset = Storage_Offset(back_iter->node, game_state);
            if(offset == root->node_offset.v)
            {
                back_iter->node = 0;
            }
            else
            {
                Entity_Node* node = Pointer(root->node_offset, game_state);
                while(Pointer(node->next, game_state) != back_iter->node)
                {
                    node = Pointer(node->next, game_state);
                }
                
                back_iter->node = node;

                bool is_root_node = back_iter->node == Pointer(root->node_offset, game_state);
                back_iter->index = is_root_node? root->count : Array_Length(node->entities);
            }
        }
        
        back_iter->index -= 1;
    }
    
    return ref;
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


SIG u32 Roll(u32 range, Game_State* game_state)
{
    u32 result = 0;
    if(range)
    {
        result = (Random_PCG(&game_state->random_state) % range) + 1;
    }
    
    return result;
}


SIG s32 Roll(Dice dice, Game_State* game_state)
{
    s32 v = 0;
    for(u64 i = 0; i < dice.count; ++i)
    {
        v += Roll(dice.faces, game_state);
    }
    
    return v;
}


/*
    Roll die in the form; (count)d(faces) and record each indivitual dice. 
    The return value ptr points to the sum. The dice roll are stored sequentially after it.
*/
SIG s32* Roll_With_Record(Dice dice, Game_State* game_state)
{
    s32* v = Push_Struct(&game_state->scratch_buffer, s32);
    for(u64 i = 0; i < dice.count; ++i)
    {
        s32 r = Roll(dice.faces, game_state);
        *Push_Struct(&game_state->scratch_buffer, s32) = r;
        *v += r;
    }
    
    return v;
}


SIG f32 Random_F32(Game_State* game_state)
{
    // TODO: better implementation.
    u32 random = Random_PCG(&game_state->random_state);
    f32 result = f32(random) / f32(U32_MAX);
    
    return result;
}


SIG Roll_Result Stat_Roll(s32 value, Stats::T stat, Game_State* game_state)
{
    Assert(stat < Stats::armor);

    Roll_Result rr = {};

    rr.stat = stat;
    rr.stat_value = value;
    rr.dice = {1, 20};
    rr.dice_result = Roll(rr.dice, game_state);
    rr.total_result = rr.stat_value + rr.dice_result;
    
    return rr;
}


SIG s32 Value(Roll_Result rr)
{
    s32 result = rr.total_result;
    return result;
}


SIG Roll_Result Stat_Roll(Entity* entity, Stats::T stat, Game_State* game_state)
{
    Assert(stat < Stats::armor);

    s32 value = Get_Stat_Value(entity, stat, game_state);
    Roll_Result rr = Stat_Roll(value, stat, game_state);

    return rr;
}


SIG _inline bool Is_Rolled(Roll_Result rr)
{
    bool result = rr.stat;
    return result;
}


SIG void Print_Dice(Dice dice, s32 result)
{
    Print("%dd%d = %d", dice.count, dice.faces, result);
}


SIG void Print_Roll_Result(Roll_Result rr)
{
    Print("[%s]:%d (%d", Stats::name[rr.stat].ptr, rr.total_result, rr.stat_value);
    
    if(rr.dice.count)
    {
        Print(" + ");
        Print_Dice(rr.dice, rr.dice_result);
    }
    Print(")");
}


SIG void Print_Attack_Record(Attack_Record* ar, Game_State* game_state)
{
    struct local
    {
        static void Print_Hit_Determination_Rolls(Attack_Record* ar, Game_State* game_state)
        {
            Wait(0.8, game_state);
            Print("\nTo hit: [crit dice]: %d (fumble: <= %d | crit: >= %d)  ", ar->crit_dice_result, ar->crit_ranges.failure, ar->crit_ranges.success);
            if(!ar->is_critical_success && !ar->is_critical_failure)
            {
                Wait(0.4, game_state);
                Print_Roll_Result(ar->accuracy_roll);
                Print(", VS ");
                Print_Roll_Result(ar->dodge_roll);
            }
        }
    };

    Entity* attacker = Dereference(ar->attacker, game_state);
    Entity* defender = Dereference(ar->defender, game_state);
    
    String attacker_name = Colored_Name(attacker, game_state);
    String defender_name = Colored_Name(defender, game_state);

    if(ar->attack_modifier == Attack_Mod::standard)
    {
        Print("\n%s attacks %s...", attacker_name.ptr, defender_name.ptr);
    }
    else
    {
        Print("\n%s uses %s attack against %s...", attacker_name.ptr, Attack_Mod::name[ar->attack_modifier].ptr, defender_name.ptr);
    }
    
    Wait(1, game_state);

    if(ar->target_pre_attack_health > 0)
    {
        if(ar->is_hit)
        {
            Print((ar->is_critical_success)? "and the attack is a critical success!" : " and the attack lands.");
            Wait(0.5, game_state);

            {
                char* cstart    = game_state->damage_color.data;
                char* cend      = game_state->default_color.data;
                Print(" Dealing %s%d%s points of damage.", cstart, ar->deal_damage_result.damage_after_mitigation, cend);
            }

            Wait(0.8, game_state);
            if(ar->deal_damage_result.damage_to_temp_health)
            {
                char* cstart = game_state->temp_health_color.data;
                char* cend = game_state->default_color.data;
                Print(" Temporary health absorbs %s%d%s points.", cstart, ar->deal_damage_result.damage_to_temp_health, cend);
            }

            if(ar->deal_damage_result.is_killing_blow)
            {
                char* w = (defender->flags & EFlags::actor)? "dies" : "breaks";
                String message = {};
                if(ar->deal_damage_result.exp_reward)
                {
                    message = Format_Message
                    (
                        game_state, 
                        "%s %s. %s receives %s%d%s points of experience.", 
                        defender_name.ptr, 
                        w, 
                        attacker_name.ptr, 
                        game_state->exp_color.data,
                        ar->deal_damage_result.exp_reward,
                        game_state->default_color.data
                    );
                }
                else
                {
                    message = Format_Message(game_state, "%s %s.", defender_name.ptr, w);
                }

                Push_Message(message, game_state);
            }
            else if(ar->deal_damage_result.damage_after_mitigation)
            {
                ANSI_Color_Buffer* cbuf = Push_Struct(&game_state->messages_buffer, ANSI_Color_Buffer);
                char* cstart    = Get_Output_Color_CSTR(cbuf, 180, 20, 20);
                char* cend      = game_state->default_color.data;

                String message = Format_Message(game_state, "%s is down to %s%d%s health.", defender_name.ptr, cstart, defender->_health, cend);
                Push_Message(message, game_state);
            }

            
            local::Print_Hit_Determination_Rolls(ar, game_state);
            Wait(0.8, game_state);

            if(ar->damage_modifier_count)
            {
                Print("\nDamage modifiers:");
                for(u64 i = 0; i < ar->damage_modifier_count; ++i)
                {
                    Damage_Modifier* mod = ar->damage_modifiers + i;

                    if(i > 0)
                    {
                        if(i == ar->damage_modifier_count - 1 && !ar->deal_damage_result.damage_after_mitigation)
                        {
                            Print(" and");
                        }
                        else
                        {
                            Print(",");
                        }
                    }
                    
                    struct Separator
                    {
                        u64 count;
                        u64 idx;
                        
                        void print()
                        {
                            if(idx > 0)
                            {
                                if(idx == count - 1)
                                {
                                    Print(" and ");
                                }
                                else
                                {
                                    Print(", ");
                                }
                            }
                            idx += 1;    
                        }
                    };

                    Separator separator = 
                    {
                        u64(mod->has_damage_multiplier) + 
                        (mod->raw_damage_modifier > 0) + 
                        (mod->pierce > 0) + 
                        (mod->damage_die.count > 0)
                    };

                    Print(" %s(", Effect_Name(mod->source, game_state).ptr);
                    if(mod->has_damage_multiplier)
                    {
                        separator.print();
                        Print("mult: %.2fx", mod->damage_multiplier);
                    }
                    if(mod->raw_damage_modifier)
                    {
                        separator.print();
                        Print("raw: %d", mod->raw_damage_modifier);
                    }
                    if(mod->pierce)
                    {
                        separator.print();
                        Print("pierce: %d", mod->pierce);
                    }
                    if(mod->damage_die.count)
                    {
                        separator.print();
                        Print("dice:");
                        for(u64 j = 0; j < mod->damage_die.count; ++j)
                        {
                            s32* result = mod->results_control_block[j];
                            Dice dice = mod->damage_die.unique_die[j];
                            
                            Print(" %dd%d = %d", dice.count, dice.faces, *result);
                            if(dice.count > 1)
                            {
                                Print(":[");
                                for(u64 y = 1; y <= dice.count; ++y)
                                {
                                    Print("%d", result[y]);
                                    if(y < dice.count)
                                    {
                                        Print(", ");
                                    }
                                }
                                Print("]");
                            }

                            if(mod->damage_die.count > 1 && j < mod->damage_die.count - 1)
                            {
                                Print(",");
                            }
                        }
                    }
                    Print(")");
                }
                
                if(ar->deal_damage_result.mitigation_after_pierce)
                {
                    if(ar->deal_damage_result.mitigation_after_pierce < ar->deal_damage_result.true_mitigation)
                    {
                        // TODO: Print pierce sources.
                        Print
                        (
                            " and Target armor(-%d = [armor]:%d - [pierce]:%d)", 
                            ar->deal_damage_result.mitigation_after_pierce,
                            ar->deal_damage_result.true_mitigation,
                            ar->deal_damage_result.pierce
                        );
                    }
                    else
                    {
                        Print(" and Target armor(-%d)", ar->deal_damage_result.mitigation_after_pierce);
                    }
                }
            }
        }
        else
        {
            if(ar->is_critical_failure)
            {
                Print(" but %s fumbles the attack and loses its next turn.", attacker_name.ptr);
            }
            else
            {
                Print(" but the attack misses.");
            }

            local::Print_Hit_Determination_Rolls(ar, game_state);
        }
    }
    else
    {
        char* w = Is_Item(defender)? "broken" : "dead";

        Print("but, %s is already %s.", defender_name.ptr, w);
    }
}


SIG _inline String Name_(Entity* entity, Game_State* game_state)
{
    String name = Get_String(entity->name_offset, game_state);
    return name;
}


SIG String Name(Entity* entity, Game_State* game_state)
{
    String name = Get_String(entity->name_offset, game_state);
    if(entity->dublicate_identifier)
    {
        name = Format_Message(game_state, "%s (%d)", name.ptr, entity->dublicate_identifier);
    }

    return name;
}


SIG String Colored_Name(Entity* entity, Game_State* game_state)
{
    char* cstart = Entity_Color(entity, game_state);
    char* cend = game_state->default_color.data;
    String name = Name(entity, game_state);
    String result = Format_Message(game_state, "%s%s%s", cstart, name.ptr, cend);
    result.length = name.length;
    return result;
}


SIG char* Action_Name(AT::T action)
{
    char* action_name = 0;
    switch(action)
    {
        case AT::free:
        {
            action_name = "Free";
        }break;
        
        case AT::normal:
        {
            action_name = "Normal";
        }break;
        
        case AT::bonus:
        {
            action_name = "Bonus";
        }break;
    }

    Assert(action_name);
    
    return action_name;
}


SIG void Print_Required_Equipment_Slots(Entity* item)
{
    Assert(item->flags & EFlags::equippable);
    
    u32 slots = item->required_equipment_slots;
    bool first = true;
    for(u64 i = 0; i < Equipment_Slots::COUNT; ++i)
    {
        u32 flag = Equipment_Slots::flag[i];
        if(slots & flag)
        {
            if(!first)
            {
                Print(" & ");
            }
            
            first = false;
            Print("%s", Equipment_Slots::name[i].ptr);
            slots &= ~flag;
        }
    }
}


SIG void Push_Generic_Apply_Effect_Message(Effect_Instance* source_effect, Entity* target, Effect_Instance new_effect, Apply_Effect_Result apply, Game_State* game_state)
{
    if(apply != Apply_Effect_Result::failed)
    {
        Arena* scratch_buffer = &game_state->scratch_buffer;

        String target_name = Colored_Name(target, game_state);
        String source_name = Effect_Name(source_effect, game_state);
        String new_effect_name = Effect_Name(&new_effect, game_state);
        
        u64 duration = new_effect.duration;
        String message = {};
        if(duration != UNLIMITED_DURATION)
        {
            String duration_name = duration_type_names[s32(new_effect.duration_type)];

            char* format_string = 0;
            switch(apply)
            {
                case Apply_Effect_Result::success:
                {
                    format_string = (duration == 1)? 
                    "%s applies %s to the %s for %llu %s." : "%s applies %s to the %s for %llu %ss.";
                }break;

                case Apply_Effect_Result::refresh:
                {
                    format_string = (duration == 1)? 
                    "%s refreshes %s on the %s. Setting its duration to %llu %s." : "%s refreshes %s on the %s. Setting its duration to %llu %ss.";
                }break;

                default:;
            }

            message = Format_Message(game_state, format_string, source_name.ptr, new_effect_name.ptr, target_name.ptr, duration, duration_name.ptr);
        }
        else
        {
            char* format_string = 0;
            switch(apply)
            {
                case Apply_Effect_Result::success:
                {
                    format_string = "%s applies %s to the %s for unlimited duration.";
                }break;

                default:;
            }

            message = Format_Message(game_state, format_string, source_name.ptr, new_effect_name.ptr, target_name.ptr);
        }
        
        Push_Message(message, game_state);
    }
}


SIG void Remove_From_Residence(Entity* entity, Game_State* game_state)
{
    if(Entity* residence = Dereference(entity->residence, game_state))
    {
        Unequip(entity, game_state);
        
        Entity_Root_Node* root = &residence->inventory;

        // - Find the entity from it's residence container.
        // - Remove the reference.
        // - Move the top item into into it's place.
        // - If this results in an empty node. Release that node back in to the system.
        
        Reference* ref = Find_Entity(entity, root, game_state);
        Assert(ref); // <- You have to find your self in your residence container!!!
        
        root->count -= 1;
        Entity_Node* root_node = Pointer(root->node_offset, game_state);
        Reference* head = root_node->entities + root->count;
        
        *ref = *head;
        *head = {};
        
        if(!root->count)
        {
            Release_Entity_Node(root, game_state);
        }
        
        entity->residence = {};
        entity->dublicate_identifier = {};
    }
}


SIG void Release_Entity_Node(Entity_Root_Node* root, Game_State* game_state)
{
    Assert(root->count == 0);

    Entity_Node *node = Pointer(root->node_offset, game_state);
    if(node->next.v)
    {
        root->node_offset = node->next;
        root->count = Array_Length(node->entities);
    }
    else
    {
        root->node_offset = {};
        root->count = 0;
    }    

    *node = {};
    node->next = game_state->free_node_offset;
    game_state->free_node_offset = Offset(node, game_state);
}


SIG Entity_Node* Request_Entity_Node(Game_State* game_state)
{
    Entity_Node* node = Pointer(game_state->free_node_offset, game_state);
    if(node)
    {
        game_state->free_node_offset = node->next;
        *node = {};
    }
    else
    {
        node = Push_Struct(&game_state->permanent_storage, Entity_Node);
    }
    
    return node;
}


SIG Effect* Request_Effect(Game_State* game_state)
{
    Effect* effect = Pointer(game_state->free_effect_offset, game_state);
    if(effect)
    {
        game_state->free_effect_offset = effect->next;
        *effect = {};
    }
    else
    {
        effect = Push_Struct(&game_state->permanent_storage, Effect);
    }

    game_state->prev_entity_ID += 1;
    effect->ID = game_state->prev_entity_ID;
    
    effect->flags |= Effect_Flags::can_be_released;
    Assert(effect->flags);

    return effect;
}


SIG void Release_Effect(Effect* effect, Game_State* game_state)
{
    if(effect->flags & Effect_Flags::can_be_released)
    {
        Effect_Offset offset = Offset(effect, game_state);
        offset.ID = 0;

        *effect = {};
        effect->next = game_state->free_effect_offset;
        game_state->free_effect_offset = offset;
    }
}


SIG Entity* Request_Entity(Game_State* game_state)
{
    Entity* entity = Pointer(game_state->free_entity_offset, game_state);
    if(entity)
    {
        game_state->free_entity_offset = entity->next;
        *entity = {};
    }
    else
    {
        entity = Push_Struct(&game_state->permanent_storage, Entity);
    }

    game_state->prev_entity_ID += 1;
    entity->ID = game_state->prev_entity_ID;

    Assert(entity->ID);

    return entity;
}


SIG void Release_Entity(Entity* entity, Game_State* game_state)
{
    *entity = {};
    entity->next = game_state->free_entity_offset;
    game_state->free_entity_offset = Offset(entity, game_state);
}


SIG Effects_Node* Request_Effects_Node(Game_State* game_state)
{
    Effects_Node* node = Pointer(game_state->free_effects_offset, game_state);
    if(node)
    {
        game_state->free_effects_offset = node->next;
        *node = {};
    }
    else
    {
        node = Push_Struct(&game_state->permanent_storage, Effects_Node);
    }
    
    return node;
}


SIG void Release_Effects_Node(Effects_Node* node, Game_State* game_state)
{
    *node = {};
    node->next = game_state->free_effects_offset;
    game_state->free_effects_offset = Offset(node, game_state);
}


SIG void Insert(Entity* entity, Entity_Root_Node* storage, Game_State* game_state)
{
    Reference* ref = 0;
    
    // - Does the root have a node?
    if(!storage->node_offset.v)
    {
        // - If NOT request node.
        Entity_Node* node = Request_Entity_Node(game_state);
        storage->node_offset = Offset(node, game_state);
        ref = Find_Empty_Slot(node);
    }
    else
    {
        // - Does the root node have space?
        Entity_Node* root_node = Pointer(storage->node_offset, game_state);
        ref = Find_Empty_Slot(root_node);
        if(!ref)
        {
            // - If NOT request a node. Link the node into the chain.
            Entity_Node* node = Request_Entity_Node(game_state);
            
            // Update linkage.
            node->next = storage->node_offset;
            storage->node_offset = Offset(node, game_state);
            storage->count = 0;
            
            ref = Find_Empty_Slot(node);
            Assert(ref); // <- a fresh node should always have space!
        } 
    }
    
    *ref = Make_Reference(entity, game_state);
    storage->count += 1;
}


SIG void Deep_Insert(Entity* entity, Entity* storage_entity, Game_State* game_state)
{
    if(storage_entity)
    {
        Remove_From_Residence(entity, game_state);
        entity->residence = Make_Reference(storage_entity, game_state);

        // Assign a unique identifier for the entities inside.
        {
            Arena_Snapshot snapshot = Snapshot(&game_state->scratch_buffer);
            Entity** matching_names = (Entity**)Push(&game_state->scratch_buffer, 0);
            u64 matching_name_count = 0;

            String entity_true_name = Get_String(entity->name_offset, game_state);
            Entity_Iterator iter = Make_Iterator(storage_entity, game_state);
            while(Entity* e = Next_Entity(&iter))
            {
                String target_true_name = Get_String(e->name_offset, game_state);
                if(Match_Case_Sensitive(entity_true_name, target_true_name))
                {
                    *Push_Struct(&game_state->scratch_buffer, Entity*) = e;
                    matching_name_count += 1;
                }
            }
            
            if(matching_name_count)
            {
                *Push_Struct(&game_state->scratch_buffer, Entity*) = entity;
                matching_name_count += 1;
                for(u64 i = 0; i < matching_name_count; ++i)
                {
                    Entity* e = matching_names[i];
                    e->dublicate_identifier = (i + 1);
                }
            }

            Restore(&game_state->scratch_buffer, snapshot);
        }

        Entity_Root_Node* storage = &storage_entity->inventory;
        Insert(entity, storage, game_state);
    }
}


SIG void Remove_All_Effects(Entity* entity, Game_State* game_state)
{
    Effects_Root* root = &entity->active_effects;

    Effects_Node* node = Pointer(root->root_offset, game_state);
    Effects_Node* last = Pointer(root->head_offset, game_state);
    
    if(node)
    {
        Assert(!last->next.v);
        
        u64 count = (node == last)? root->head_count: Array_Length(node->instances);
        while(node)
        {
            for(u64 i = 0; i < count; ++i)
            {
                Effect_Instance* instance = node->instances + i;
                Effect* effect = Pointer(instance->effect_offset, game_state);
                Release_Effect(effect, game_state);
            }
            
            Effects_Node* next = Pointer(node->next, game_state); // NOTE: snap before nuke.
            Release_Effects_Node(node, game_state);

            count = (node == last)? root->head_count: Array_Length(node->instances);
            node = next;
        }
    }
}


void _Delete_Entity_Internal(Entity* entity, Game_State* game_state)
{
    // Release all inventory nodes. 
    // Release all effect nodes.
    // Recursively do the same for all entities residing within.

    Remove_All_Effects(entity, game_state);
    
    while(Entity_Node* node = Pointer(entity->inventory.node_offset, game_state))
    {
        for(u64 i = 0; i < entity->inventory.count; ++i)
        {
            Entity* e = Dereference(node->entities + i, game_state);
            if(Dereference(e->residence, game_state) == entity)
            {
                _Delete_Entity_Internal(e, game_state);
            }
        }

        entity->inventory.count = 0;
        Release_Entity_Node(&entity->inventory, game_state);
    }

    Release_Entity(entity, game_state);
}


SIG void Delete_Entity(Entity* entity, Game_State* game_state)
{
    Remove_From_Residence(entity, game_state);
    _Delete_Entity_Internal(entity, game_state);
}


SIG bool Has_Content(Entity_Root_Node* root)
{
    bool result = (root && root->count);
    return result;
}


SIG bool Is_Empty(Entity_Root_Node* root)
{
    bool result = !Has_Content(root);
    return result;
}

struct On_Get_Stat_Value_Storage
{
    PROTOTYPE_EFFINST_ENT_STAT_S32PTR_S16PTR_GS* fn;
    Effect_Instance* instance;
};


SIG s32 Get_Stat_Value(Entity* entity, Stats::T stat, Game_State* game_state, u64* out_effect_count DEF(0))
{
    s16 base = {entity->_stats[stat]};
    s32 bonuses = 0;
    Arena_Snapshot snapshot = Snapshot(&game_state->scratch_buffer);
    
    On_Get_Stat_Value_Storage* on_get_stat_value_storage = (On_Get_Stat_Value_Storage*)Push(&game_state->scratch_buffer, 0);
    u64 on_get_stat_value_storage_count = 0;

    u64 count = 0;
    Effects_Iterator iter = Make_Iterator(&entity->active_effects, game_state);
    while(Effect_Instance* instance = Next(&iter))
    {
        Effect* effect = Pointer(instance->effect_offset, game_state);
        if(PROTOTYPE_EFFINST_ENT_STAT_S32PTR_S16PTR_GS* fn = Pointer(effect->on_get_stat_value_fn_offset, game_state))
        {
            *Push_Struct(&game_state->scratch_buffer, On_Get_Stat_Value_Storage) = {fn, instance};
            on_get_stat_value_storage_count += 1;
        }

        s16 mod = effect->stat_modifiers[stat];
        if(mod)
        {
            bonuses += mod;
            count += 1;
        }
    }
    
    // CONSIDER: Do on_get_stat_value_fns count as effecting the stat?
    if(out_effect_count)
    {
        *out_effect_count = count;
    }

    for(u64 i = 0; i < on_get_stat_value_storage_count; ++i)
    {
        On_Get_Stat_Value_Storage* storage = on_get_stat_value_storage + i;
        storage->fn(storage->instance, entity, stat, &bonuses, &base, game_state);
    }

    Restore(&game_state->scratch_buffer, snapshot);
    
    s32 result = Max(s32(base + bonuses), s32(1));
    return result;
}


SIG s32 Exp_To_Level_Up(s32 _lvl)
{
    f32 lvl = f32(_lvl);
    s32 result = s32( -100.f + (1.f + Square(lvl + 1)) * 100.f );
    return result;
}


SIG _inline s32 Exp_To_Level_Up(Entity* entity)
{
    s32 result = Exp_To_Level_Up(entity->_lvl);
    return result;
}


SIG s16 Calculate_Level(Entity* entity)
{
    s64 total_stats = 0;
    for(u64 i = 0; i < Stats::COUNT; ++i)
    {
        total_stats += entity->_stats[i];
    }

    s16 lvl = Max(s16(1), s16(f32(total_stats / f32(Stats::points_per_lvl) + 0.5f)));
    return lvl;
}


SIG void Set_Level_Based_On_Stats(Entity* entity)
{
    entity->_lvl = Calculate_Level(entity);
    entity->exp = (entity->_lvl)? (Exp_To_Level_Up(entity->_lvl - 1)) : 0;
}


SIG s16 Level(Entity* entity)
{
    s16 result = Max(s16(1), s16(entity->_lvl + 1));
    return result;
}


SIG s32 Max_Health(Entity* entity, Game_State* game_state)
{
    s32 result = Get_Stat_Value(entity, Stats::vitality, game_state) * 5;
    
    if(entity->flags & EFlags::godmode)
    {
        result = 100000;
    }
    
    return result;
}


SIG f32 Critical_Multiplier(Entity* entity, Game_State* game_state)
{
    f32 result = 2.f;
    return result;
}


SIG s32 Carry_Capacity(Entity* entity, Game_State* game_state)
{
    s32 result = 50;
    s32 mod = 0;
    Effects_Iterator iter = Make_Iterator(&entity->active_effects, game_state);
    while(Effect* effect = Next_Effect(&iter))
    {
        mod += effect->carry_capacity_modifier;
    }

    if(entity->flags & EFlags::godmode)
    {
        result += 100000;
    }
    
    result = Max(1, result + mod);
    return result;
}


SIG s32 Exp_Reward(Entity* entity)
{
    s32 result = entity->bonus_exp_reward;

    if(entity->flags & EFlags::actor)
    {
        result += Level(entity) * 100;
    }
    
    return result;
}


SIG s32 Carrying_Amount(Entity* entity, Game_State* game_state)
{
    s32 result = 0;
    Entity_Iterator iter = Make_Iterator(&entity->inventory, game_state);
    while(Entity* item = Next_Entity(&iter))
    {
        result += item->weight;
    }
    
    return result;
}


SIG Critical_Ranges_Result Critical_Ranges(Entity* entity, Game_State* game_state, u32* out_success_effecting_count DEF(0), u32* out_failure_effecing_count DEF(0))
{
    Critical_Ranges_Result result = {1, 1};
    if(entity)
    {
        Effects_Iterator iter = Make_Iterator(&entity->active_effects, game_state);

        u32 success_count = 0;
        u32 failure_count = 0;
        while(Effect* effect = Next_Effect(&iter))
        {
            if(effect->critical_success_range)
            {
                success_count += 1;
                result.success += effect->critical_success_range;
            }

            if(effect->critical_failure_range)
            {
                failure_count += 1;
                result.failure += effect->critical_failure_range;
            }
        }

        result.success = (CRITICAL_DICE_RANGE + 1) - Max(1, Min(result.success, (CRITICAL_DICE_RANGE)));
        result.failure = Max(1, Min(result.failure, (CRITICAL_DICE_RANGE - 1)));

        if(out_success_effecting_count)
        {
            *out_success_effecting_count = success_count;
        }

        if(out_failure_effecing_count)
        {
            *out_failure_effecing_count = failure_count;
        }
    }

    return result;
}


SIG void Full_Heal(Entity* entity, Game_State* game_state)
{
    entity->_health = Max_Health(entity, game_state);
}


SIG bool Is_Item(Entity* entity)
{
    bool result =  (entity->flags & EFlags::item) || (entity->flags & EFlags::interactable) || (entity->flags & EFlags::equippable);
    return result;
}


SIG bool Is_Alive(Entity* entity)
{
    bool result = entity->_health > 0 && entity->flags & EFlags::actor;
    return result;
}


SIG bool Is_Hostile_Against(Entity* A, Entity* B)
{
    bool result = A->faction != Faction::none && B->faction != Faction::none && A->faction != B->faction;
    return result;
}


SIG bool Is_Living_Enemy_Of(Entity* actor, Entity* target)
{
    bool result = Is_Alive(actor) && Is_Hostile_Against(actor, target);
    return result;
}


SIG s32 Give_Temporary_Health(Entity* entity, s32 amount, String source_name, Verbose::T verbose, Game_State* game_state)
{
    s32 shield_amount = 0;
    if(amount > 0)
    {
        Assert(entity);
        entity->_temp_health += amount;
        shield_amount = amount;
        
        if(verbose)
        {
            String entity_name = Name(entity, game_state);
            String message = Format_Message(game_state, "%s resives %d points of temporary health from %s.", entity_name.ptr, shield_amount, source_name.ptr);
            Push_Message(message, game_state);
        }
    }

    return shield_amount;
}


SIG Healing_Result Heal(Entity* entity, s32 amount, String source_name, Verbose::T verbose, Game_State* game_state)
{
    Effects_Iterator iter = Make_Iterator(&entity->active_effects, game_state);
    while(Effect_Instance* instance = Next(&iter))
    {
        Effect* effect = Pointer(instance->effect_offset, game_state);
        if(PROTOTYPE_EFFINST_ENT_S32PTR_STR_GS* fn = Pointer(effect->on_heal_fn_offset, game_state))
        {
            fn(instance, entity, &amount, source_name, game_state);
        }
    }

    if(entity->_health < 0)
    {
        amount = 0;
    }

    Healing_Result result = {amount};
    
    result.health_snapshot = entity->_health;
    result.max_health = Max_Health(entity, game_state);

    entity->_health = Min(entity->_health + amount, result.max_health);
    result.healing_done = {entity->_health - result.health_snapshot};
    result.overhealing = amount - result.healing_done;
    if(amount)
    {
        result.overhealing_percentage = f32(result.overhealing) / f32(amount) * 100.f;
        
        if(verbose)
        {
            String message = {};
            String entity_name = Name(entity, game_state);

            if(result.health_snapshot == result.max_health)
            {
                message = Format_Message
                (
                    game_state,
                    "%s attempts to heal %s, but %s is already at full health [overhealing: %d = %.2f%%].", 
                    source_name.ptr, 
                    entity_name.ptr, 
                    entity_name.ptr, 
                    result.overhealing, 
                    result.overhealing_percentage
                );

            }
            else
            {
                message = Format_Message
                (
                    game_state,
                    "%s heals %s for %d points [overhealing: %d = %.2f%%].", 
                    source_name.ptr, 
                    entity_name.ptr, 
                    result.healing_done, 
                    result.overhealing, 
                    result.overhealing_percentage
                );
            }

            Push_Message(message, game_state);
        }
    }

    return result;
}


SIG Deal_Damage_Result Deal_Damage(Entity* defender, Reference attacker, String source_name, s32 dmg, s32 pierce, Damage_Type type, Game_State* game_state, Verbose::T verbose)
{
    Deal_Damage_Result ddr = {};

    if(dmg > 0)
    {
        switch(type)
        {
            case Damage_Type::physical:
            {
                ddr.true_mitigation = Get_Stat_Value(defender, Stats::armor, game_state);
                ddr.mitigation_after_pierce = Max(0, ddr.true_mitigation - pierce);
                ddr.pierce = pierce;
            }break;

            default:;
        }

        ddr.damage_after_mitigation = Max(1, dmg - ddr.mitigation_after_pierce);

        if(defender->_health > 0)
        {
            Assert(defender->_temp_health >= 0);
            
            ddr.damage_to_temp_health = Min(ddr.damage_after_mitigation, defender->_temp_health);

            defender->_temp_health -= ddr.damage_to_temp_health;
            ddr.damage_to_true_health = ddr.damage_after_mitigation - ddr.damage_to_temp_health;
            defender->_health -= ddr.damage_to_true_health;
            
            Assert(ddr.damage_to_temp_health >= 0);
            Assert(defender->_temp_health >= 0);
            
            if(defender->_health <= 0)
            {
                ddr.is_killing_blow = true;
                
                ddr.exp_reward = Exp_Reward(defender);
                
                // NOTE: Proc on damage taken
                {
                    Effects_Iterator iter = Make_Iterator(&defender->active_effects, game_state);
                    while(Effect_Instance* instance = Next(&iter))
                    {
                        Effect* effect = Pointer(instance->effect_offset, game_state);

                        if(PROTOTYPE_EFFINST_REF_ENT_DDR_GS* on_damage_taken_fn = Pointer(effect->on_damage_taken_fn_offset, game_state))
                        {
                            on_damage_taken_fn(instance, attacker, defender, &ddr, game_state);
                        }
                    }
                }
                
                if(Entity* e = Dereference(attacker, game_state))
                {
                    e->exp += ddr.exp_reward;
                }

                // If this entity is an item equipped on someone... unequip it.
                {
                    Entity* residence = Dereference(defender->residence, game_state);
                    if(residence && defender->_health <= 0)
                    {
                        Unequip(residence, defender, game_state);
                    }
                }
            }

            if(verbose)
            {
                String defender_name = Colored_Name(defender, game_state);
                if(ddr.is_killing_blow)
                {

                    String message = {};
                    if(ddr.damage_to_temp_health)
                    {
                        message = Format_Message
                        (
                            game_state, 
                            "%s takes %s%d%s points of damage from %s. Temporary health absorbs %s%d%s points. %s dies.", 
                            defender_name.ptr,
                            game_state->damage_color.data, 
                            ddr.damage_after_mitigation,
                            game_state->default_color.data,
                            source_name.ptr, 
                            game_state->temp_health_color.data,
                            ddr.damage_to_temp_health,
                            game_state->default_color.data,
                            defender_name.ptr
                        );
                    }
                    else
                    {
                        message = Format_Message
                        (
                            game_state, 
                            "%s takes %s%d%s points of damage from %s. %s dies.", 
                            defender_name.ptr, 
                            game_state->damage_color.data, 
                            ddr.damage_after_mitigation,
                            game_state->default_color.data,
                            source_name.ptr, 
                            defender_name.ptr
                        );
                        
                    }
                    Push_Message(message, game_state);

                    char* attacker_name_ptr = 0;
                    if(Entity* e = Dereference(attacker, game_state))
                    {
                        attacker_name_ptr = Colored_Name(e, game_state).ptr;
                    }
                    
                    if(attacker_name_ptr && ddr.exp_reward)
                    {
                        String message2 = Format_Message
                        (
                            game_state, 
                            "%s resives %s%d%s points of experience.", 
                            attacker_name_ptr,
                            game_state->exp_color.data,
                            ddr.exp_reward,
                            game_state->default_color.data
                        );
                        Push_Message(message2, game_state);
                    }
                }
                else
                {
                    String message = {};
                    if(ddr.damage_to_temp_health)
                    {
                        message = Format_Message
                        (
                            game_state, 
                            "%s takes %s%d%s points of damage from %s. Temporary health absorbs %s%d%s points.",
                            defender_name.ptr,
                            game_state->damage_color.data,
                            ddr.damage_after_mitigation,
                            game_state->default_color.data,
                            source_name.ptr,
                            game_state->temp_health_color.data,
                            ddr.damage_to_temp_health,
                            game_state->default_color.data
                        );
                    }
                    else
                    {
                        message = Format_Message
                        (
                            game_state, 
                            "%s takes %s%d%s points of damage from %s.", 
                            defender_name.ptr,
                            game_state->damage_color.data, 
                            ddr.damage_after_mitigation, 
                            game_state->default_color.data,
                            source_name.ptr
                        );
                    }

                    Push_Message(message, game_state);
                }
            }
        }    
    }

    return ddr;
}


SIG _inline Deal_Damage_Result Deal_Damage(Entity* defender, Entity* attacker, String dmg_src_name, s32 dmg, s32 pierce, Damage_Type type, Game_State* game_state, Verbose::T verbose)
{
    Reference atref = Make_Reference(attacker, game_state);
    Deal_Damage_Result ddr = Deal_Damage(defender, atref, dmg_src_name, dmg, pierce, type, game_state, verbose);
    return ddr;
}


SIG void Proc_Effects(u64 offset, Entity* attacker, Entity* defender, Attack_Record* ar, Game_State* game_state)
{
    // CONSIDER: Delete this function and figure out something more type safe!
    Effects_Iterator iter = Make_Iterator(&attacker->active_effects, game_state);
    while(Effect_Instance* instance = Next_Effect_Instance(&iter))
    {
        char* effect_base_address = (char*)Pointer(instance->effect_offset, game_state);
        PROTOTYPE_EFFINST_ENT_ENT_AR_GS_Offset offset_offset = *(PROTOTYPE_EFFINST_ENT_ENT_AR_GS_Offset*)(effect_base_address + offset);
        
        if(PROTOTYPE_EFFINST_ENT_ENT_AR_GS* fn = Pointer(offset_offset, game_state))
        {
            fn(instance, attacker, defender, ar, game_state);
        }
    }
}


SIG void Proc_Effects(u64 offset, Entity* target, Game_State* game_state)
{
    // CONSIDER: Delete this function and figure out something more type safe!
    Effects_Iterator iter = Make_Iterator(&target->active_effects, game_state);
    while(Effect_Instance* instance = Next_Effect_Instance(&iter))
    {
        char* effect_base_address = (char*)Pointer(instance->effect_offset, game_state);
        PROTOTYPE_EFFINST_ENT_GS_Offset offset_offset = *(PROTOTYPE_EFFINST_ENT_GS_Offset*)(effect_base_address + offset);
        if(PROTOTYPE_EFFINST_ENT_GS* fn = Pointer(offset_offset, game_state))
        {
            fn(instance, target, game_state);
        }
    }
}


SIG String Effect_Name(Effect_Instance* instance, Game_State* game_state)
{
    String result = {};

    Effect* effect = Pointer(instance->effect_offset, game_state);
    String effect_name = Get_String(effect->name_offset, game_state);
    
    if(effect_name.ptr)
    {
        result = effect_name;
    }
    else if(Entity* source = Dereference(instance->source, game_state))
    {
        result = Colored_Name(source, game_state);
    }

    return result;
}


SIG u64 Count_Effect_Instances(Effects_Root* root, Effect_Instance cmp, Game_State* game_state, Effect_Instance** out_shortest_duration DEF(0))
{
    u64 count = 0;

    Effect_Offset effect_offset = cmp.effect_offset;

    Effect_Instance* shortest_duration = 0;

    Effects_Iterator iter = Make_Iterator(root, game_state);
    while(Effect_Instance* instance = Next(&iter))
    {
        if(instance->effect_offset.v == effect_offset.v && instance->duration_type == cmp.duration_type)
        {
            count += 1;
            if(!shortest_duration || instance->duration < shortest_duration->duration)
            {
                shortest_duration = instance;
            }
        }
    }

    if(count && out_shortest_duration)
    {
        *out_shortest_duration = shortest_duration;
    }

    return count;
}


SIG void Delete_Effect_Slot(Effects_Root* root, Effects_Node* node, u64 *idx, u64* count, Game_State* game_state)
{
    Effects_Node* head = Pointer(root->head_offset, game_state);

    root->head_count -= 1;
    Effect_Instance* slot = node->instances + *idx;
    Effect_Instance* head_slot = head->instances + root->head_count;

    Effect* effect = Pointer(slot->effect_offset, game_state);
    Release_Effect(effect, game_state);
    
    *slot = *head_slot;
    *head_slot = {};
    *idx -= 1;
    
    if(head == node && count)
    {
        *count -= 1;
    }

    if(!root->head_count)
    {
        Effects_Node* prev = Pointer(head->prev, game_state);
        if(prev)
        {
            root->head_offset = head->prev;
            root->head_count = Array_Length(prev->instances);
            prev->next = {};
            
            Release_Effects_Node(head, game_state);
        }
        else
        {
            Assert(node->next.v == 0);
            *root = {};
        }
    }
}


SIG Effect_Instance* New_Effect_Slot(Effects_Root* root, Game_State* game_state)
{
    // If you don't have a root node; get one.
    Effects_Node* root_node = Pointer(root->root_offset, game_state);
    Effects_Node* head_node = 0;
    if(!root_node)
    {
        Assert(root->head_offset.v == 0);
        Assert(root->head_count == 0);
        
        Effects_Node* node = Request_Effects_Node(game_state);
        root->root_offset = Offset(node, game_state);
        root->head_offset = root->root_offset;
        root->head_count = 0;

        head_node = node;
    }
    
    // If you do have a node, but it's full; get a new one and update the linkage.
    else if(root->head_count == Array_Length(root_node->instances))
    {
        Effects_Node* node = Request_Effects_Node(game_state);
        node->prev = root->head_offset;

        Effects_Node* previous_head_node = Pointer(root->head_offset, game_state);
        previous_head_node->next = Offset(node, game_state);

        root->head_offset = previous_head_node->next;
        root->head_count = 0;

        head_node = node;
    }
    else
    {
        head_node = Pointer(root->head_offset, game_state);
    }
    
    Assert(head_node && root->head_count < Array_Length(root_node->instances));

    Effect_Instance* instance_slot = head_node->instances + root->head_count;
    root->head_count += 1;

    return instance_slot;
}


SIG Apply_Effect_Result Apply_Effect(Entity* target, Effect_Instance instance, Game_State* game_state)
{
    Apply_Effect_Result result = Apply_Effect_Result::failed;
    Effect* effect = Pointer(instance.effect_offset, game_state);
    
    if(instance.duration_type != Duration_Type::round)
    {
        instance.zero_ticked = true;
    }

    if(target && instance.effect_offset.v)
    {
        Assert(Dereference(instance.source, game_state)); // Do you have to have source?
        Assert(effect->type < Effect_Type::COUNT);       

        if(Is_Alive(target))
        {
            Effect_Instance* slot = 0;
            Effect_Instance* shortest_duration = 0;
            u64 max_stacks = 1 + effect->bonus_stacks;
            u64 effect_count = Count_Effect_Instances(&target->active_effects, instance, game_state, &shortest_duration);

            if(effect_count < max_stacks)
            {
                result = Apply_Effect_Result::success;
                slot = New_Effect_Slot(&target->active_effects, game_state);
                *slot = instance;
                slot->round_applied = game_state->round;
            }
            
            else if(shortest_duration->duration <= instance.duration && instance.duration != UNLIMITED_DURATION)
            {
                Assert(instance.duration_type == shortest_duration->duration_type);
                slot = shortest_duration;
                
                result = Apply_Effect_Result::refresh;
                shortest_duration->duration = Max(instance.duration, shortest_duration->duration);
                shortest_duration->zero_ticked = instance.zero_ticked;
            }

            PROTOTYPE_EFFINST_ENT_GS* on_apply_fn = Pointer(effect->on_apply_fn_offset, game_state);
            if(slot && on_apply_fn)
            {
                on_apply_fn(slot, target, game_state);
            }
        }
    }
    
    if(result != Apply_Effect_Result::success && effect)
    {
        Release_Effect(effect, game_state);
    }

    return result;
}


SIG void Remove_Effects_From_Source(Entity* actor, Entity* source, Game_State* game_state)
{
    Effects_Root* root = &actor->active_effects;
    
    Effects_Node* node = Pointer(root->root_offset, game_state);
    u64 count = (node == Pointer(root->head_offset, game_state))? root->head_count : Array_Length(node->instances);
    
    while(node)
    {
        for(u64 idx = 0; idx < count; ++idx)
        {
            Effect_Instance* instance = node->instances + idx;
            
            if(Dereference(instance->source, game_state) == source)
            {
                Delete_Effect_Slot(root, node, &idx, &count, game_state);
            }
        }

        node = Pointer(node->next, game_state);
        count = (node == Pointer(root->head_offset, game_state))? root->head_count : Array_Length(node->instances);
    }
}


SIG u64 Remove_Effects_Of_Type(Entity* actor, Effect_Type::T type_to_remove, Game_State* game_state, Verbose::T verbose)
{
    u64 removed_effect_count = 0;

    Effects_Root* root = &actor->active_effects;
    
    Effects_Node* node = Pointer(root->root_offset, game_state);
    u64 count = (node == Pointer(root->head_offset, game_state))? root->head_count : Array_Length(node->instances);
    
    while(node)
    {
        for(u64 idx = 0; idx < count; ++idx)
        {
            Effect_Instance* instance = node->instances + idx;
            
            if(Pointer(instance->effect_offset, game_state)->type == type_to_remove)
            {
                if(verbose)
                {
                    Print("\n%s removed.", Effect_Name(instance, game_state).ptr);
                }
                Delete_Effect_Slot(root, node, &idx, &count, game_state);
                removed_effect_count += 1;
            }
        }

        node = Pointer(node->next, game_state);
        count = (node == Pointer(root->head_offset, game_state))? root->head_count : Array_Length(node->instances);
    }

    return removed_effect_count;
}


void Describe_Effect(Effect* effect, u64 depth, Game_State* game_state)
{
    struct local
    {
        static void Line(u64 depth)
        {
            Print("\n");
            for(u64 i = 0; i < depth; ++i)
            {
                Print("| ");
            }
        }
    };

    if(effect)
    {
        Assert(effect->damage_die.count <= Array_Length(effect->damage_die.unique_die));
        
        if(effect->type)
        {
            local::Line(depth);
            Print("Type: [%s]", Effect_Type::names[effect->type].ptr);
        }

        if(effect->critical_success_range)
        {
            char c = (effect->critical_success_range > 0)? '+' : '-';
            local::Line(depth);
            Print("Crtical range: %c %d", c, effect->critical_success_range);
        }

        if(effect->critical_failure_range)
        {
            char c = (effect->critical_failure_range > 0)? '+' : '-';
            local::Line(depth);
            Print("Fumple range: %c %d", c, effect->critical_failure_range);
        }
        
        if(effect->flags & Effect_Flags::has_damage_multiplier)
        {
            local::Line(depth);
            Print("Damage multiplier: %.2f", effect->damage_multiplier);
        }

        if(effect->raw_damage_modifier)
        {
            local::Line(depth);
            Print("Raw damage modifier: %d", effect->raw_damage_modifier);
        }

        if(effect->thorns_damage)
        {
            local::Line(depth);
            Print("Thorns damage: %d", effect->thorns_damage);
        }

        if(effect->carry_capacity_modifier)
        {
            char c = (effect->carry_capacity_modifier > 0)? '+' : '-';
            local::Line(depth);
            Print("Carrying capacity modifeir: %c %d", c, effect->carry_capacity_modifier);
        }
        

        switch(effect->damage_die.count)
        {
            case 0:
            {
                // NOTE: Do nothing on zero.
            }break;
            
            case 1:
            {
                Dice dice = effect->damage_die.unique_die[0];
                local::Line(depth);
                Print("Damage dice: %dd%d", dice.count, dice.faces);
            }break;
            
            default:
            {
                local::Line(depth);
                Print("Damage dice:");
                for(s16 i = 0; i < effect->damage_die.count; ++i)
                {
                    Dice dice = effect->damage_die.unique_die[i];
                    Print(" %dd%d", dice.count, dice.faces);
                    
                    if(i < effect->damage_die.count - 1)
                    {
                        Print(",");
                    }
                }
            }
        }
        
        {
            bool first = true;
            for(u64 i = 0; i < Array_Length(effect->stat_modifiers); ++i)
            {
                s16 mod = effect->stat_modifiers[i];
                if(mod)
                {
                    if(first)
                    {
                        local::Line(depth);
                        Print("Stat Modifiers:");
                        first = false;
                    }
                    
                    char* sign = (mod > 0)? "+" : "-";
                    local::Line(depth + 1);
                    Print("%10s: %s %d", Stats::name[i].ptr, sign, Abs(mod));
                }
            }
        }

        if(PROTOTYPE_EFFINST_ENT_GS* on_apply_fn = Pointer(effect->on_apply_fn_offset, game_state))
        {
            local::Line(depth);
            Print("[On apply]: ");
            on_apply_fn(0, 0, 0);
        }

        if(PROTOTYPE_EFFINST_ENT_GS* on_turn_end_fn = Pointer(effect->on_turn_end_fn_offset, game_state))
        {
            local::Line(depth);
            Print("[On turn end]: ");
            on_turn_end_fn(0, 0, 0);
        }

        if(PROTOTYPE_EFFINST_ENT_GS* on_turn_start_fn = Pointer(effect->on_turn_start_fn_offset, game_state))
        {
            local::Line(depth);
            Print("[On turn start]: ");
            on_turn_start_fn(0, 0, 0);
        }
        
        if(PROTOTYPE_EFFINST_ENT_ENT_AR_GS* on_attack_fn = Pointer(effect->on_attack_fn_offset, game_state))
        {
            local::Line(depth);
            Print("[On attack]: ");
            on_attack_fn(0, 0, 0, 0, 0);
        }
        
        if(PROTOTYPE_EFFINST_ENT_ENT_AR_GS* on_miss_fn = Pointer(effect->on_miss_fn_offset, game_state))
        {
            local::Line(depth);
            Print("[On miss]: ");
            on_miss_fn(0, 0, 0, 0, 0);
        }
        
        if(PROTOTYPE_EFFINST_ENT_ENT_AR_GS* on_hit_fn = Pointer(effect->on_hit_fn_offset, game_state))
        {
            local::Line(depth);
            Print("[On hit]: ");
            on_hit_fn(0, 0, 0, 0, 0);
        }
        
        if(PROTOTYPE_EFFINST_ENT_ENT_AR_GS* on_dodge_fn = Pointer(effect->on_dodge_fn_offset, game_state))
        {
            local::Line(depth);
            Print("[On dodge]: ");
            on_dodge_fn(0, 0, 0, 0, 0);
        }
        
        if(PROTOTYPE_EFFINST_REF_ENT_DDR_GS* on_damage_taken_fn = Pointer(effect->on_damage_taken_fn_offset, game_state))
        {
            local::Line(depth);
            Print("[On damage taken]: ");
            on_damage_taken_fn(0, {}, 0, 0, 0);
        }
        
        if(PROTOTYPE_EFFINST_ENT_S32PTR_STR_GS* on_heal_fn = Pointer(effect->on_heal_fn_offset, game_state))
        {
            local::Line(depth);
            Print("[On heal]: ");
            on_heal_fn(0, 0, 0, {}, 0);
        }
        
        if(PROTOTYPE_EFFINST_ENT_STAT_S32PTR_S16PTR_GS* on_get_stat_value_fn = Pointer(effect->on_get_stat_value_fn_offset, game_state))
        {
            local::Line(depth);
            Print("[On on read stat value]: ");
            on_get_stat_value_fn(0, 0, Stats::T(0), 0, 0, 0);
        }
    }
}


SIG void Inspect(Entity* target, Game_State* game_state)
{
    String target_name = Colored_Name(target, game_state);

    Print("[%s]", target_name.ptr);

    if(target->weight)
    {
        Print("\nWeight: %d", target->weight);
    }

    if(target->description_offset.v)
    {
        String description = Get_String(target->description_offset, game_state);
        Print("\nDescription: %s", description.ptr);
    }
    else
    {
        Print("\n%s has no description.", target_name.ptr);
    }
    
    if(target->flags & EFlags::equippable && target->on_equip_effect_offset.v)
    {
        Print("\nSlots: ");
        Print_Required_Equipment_Slots(target);
        
        Effect* effect = Pointer(target->on_equip_effect_offset, game_state);
        Describe_Effect(effect, 0, game_state);
    }
    
    if(target->flags & EFlags::interactable && target->interactable.on_use_fn_offset.v)
    {
        Print("\n[On Consume]: ");
        Pointer(target->interactable.on_use_fn_offset, game_state)(0, 0, 0);
    }

    if(target->interactable.uses_count)
    {
        Print("\n");
        Print_Uses(target);
    }
}


SIG bool Is_Equipped(Entity* actor, Entity* item, Game_State* game_state)
{
    bool result = false;
    
    Entity_Offset item_offset = Offset(item, game_state);

    for(u64 i = 0; i < Equipment_Slots::COUNT; ++i)
    {
        if(Entity* equiped_entity = Dereference(actor->equipment[i], game_state))
        {
            Entity_Offset equipped_offset = Offset(equiped_entity, game_state);
            if(item_offset.v == equipped_offset.v)
            {
                result = true;
                break;
            }
        }
    }
    
    return result;
}


SIG bool Unequip(Entity* actor, Entity* item, Game_State* game_state)
{
    bool result = false;
    Entity* item_residence = Dereference(item->residence, game_state);
    if(actor == item_residence)
    {
        for(u64 i = 0; i < Array_Length(actor->equipment); ++i)
        {
            Entity* equiped_item = Dereference(actor->equipment + i, game_state);
            if(item == equiped_item)
            {
                Remove_Effects_From_Source(actor, equiped_item, game_state);
                actor->equipment[i] = {};
                result = true;
            }
        }
        
        Assert(!Is_Equipped(actor, item, game_state));
    }
    
    return result;
}


SIG bool Unequip(Entity* item, Game_State* game_state)
{
    Entity* actor = Dereference(item->residence, game_state);
    bool result = Unequip(actor, item, game_state);
    return result;
}


SIG bool Use(Entity* actor, Entity* item, Game_State* game_state, Verbose::T verbose)
{
    Interactable* interactable = &item->interactable;
    bool result = (item->flags & EFlags::interactable) && interactable->on_use_fn_offset.v;
    
    if(result)
    {
        String item_name = Name(item, game_state);

        if(interactable->uses_count)
        {
            Flush_Messages(game_state);
            Pointer(interactable->on_use_fn_offset, game_state)/*It does call it ->*/(item, actor, game_state);
            Print_Messages(game_state);

            if(interactable->uses_count != UNLIMITED_USES)
            {
                interactable->uses_count -= 1;
            
                if(interactable->uses_count == 0)
                {
                    Print("\n%s is now out of usages.", item_name.ptr);

                    if(PROTOTYPE_ENT_GS* on_empty_fn = Pointer(interactable->on_empty_fn_offset, game_state))
                    {
                        on_empty_fn(item, game_state);
                    }
                }
            }
        }
        else
        {
            Print("\n%s is empty, so it can't be used anymore...", item_name.ptr);
        }
    }

    return result;
}


SIG bool Equip(Entity* actor, Entity* target, Game_State* game_state, Verbose::T verbose DEF(Verbose::T(0)))
{
    bool item_was_equiped = true;

    String target_name = Colored_Name(target, game_state);

    if(!(target->flags & EFlags::equippable))
    {
        if(verbose)
        {
            Print("\nYou try to equip %s, but can't figure out how...", target_name.ptr);
        }
        item_was_equiped = false;
    }
    else if(target->_health <= 0)
    {
        if(verbose)
        {
            Print("\nYou try to equip %s, but it is broken!", target_name.ptr);
        }
        item_was_equiped = false;
    }
    else if(!Is_Alive(actor))
    {
        if(verbose)
        {
            Print("\nYou try to equip %s, but you are dead...", target_name.ptr);
        }
        item_was_equiped = false;
    }

    if(item_was_equiped)
    {
        if(!Is_Equipped(actor, target, game_state))
        {
            Reference target_ref = Make_Reference(target, game_state);
            
            Arena* scratch_buffer = &game_state->scratch_buffer;
            
            Arena_Snapshot snapshot = Snapshot(scratch_buffer);
            
            // CONSIDER: Use the stack for storage? These arrays are small and the size is known at compile time.
            
            Reference** slots_to_use    = Push_Array(scratch_buffer, Reference*, Equipment_Slots::COUNT);
            u64 slots_to_use_count      = 0;
            Reference** blocking_slots  = Push_Array(scratch_buffer, Reference*, Equipment_Slots::COUNT);
            u64 blocking_slots_count    = 0;
            
            // Find out if the slots are available?
            u32 slots_required = target->required_equipment_slots;
            u32 blocking_slot_flags = 0;
            for(u64 i = 0; i < Equipment_Slots::COUNT; ++i)
            {
                // NOTE: rings will have the same flag or multile slots.
                u32 flag = Equipment_Slots::flag[i];
                if(flag & slots_required)
                {
                    Reference* slot = actor->equipment + i;
                    Entity* object = Dereference(slot, game_state);
                    
                    if(object)
                    {
                        if(!(blocking_slot_flags & flag))
                        {
                            blocking_slots[blocking_slots_count] = slot;
                            blocking_slots_count += 1;
                            blocking_slot_flags |= flag;
                        }
                    }
                    else
                    {
                        // Free slot.
                        slots_to_use[slots_to_use_count] = slot;
                        slots_to_use_count += 1;
                        slots_required &= ~flag;
                    }
                }
            }
            
            // If all the bits in the required slots bit field were turned off, then there was a free slot available of each type.
            if(slots_required == 0)
            {
                if(verbose)
                {
                    Print("\nYou equip %s", target_name.ptr);
                }
                
                for(u64 i = 0; i < slots_to_use_count; ++i)
                {
                    Reference* slot = slots_to_use[i];
                    *slot = target_ref;
                }
            }
            
            // One or more items is occupying the slots required for the insertion of this item.
            else
            {
                Entity** unique_blocking_entities = Push_Array(scratch_buffer, Entity*, blocking_slots_count);
                u64 unique_blocking_entity_count = 0;
                
                for(u64 i = 0; i < blocking_slots_count; ++i)
                {
                    Entity* entity = Dereference(blocking_slots[i], game_state);
                    
                    bool unique = true;
                    
                    for(u64 j = 0; j < unique_blocking_entity_count; ++j)
                    {
                        if(unique_blocking_entities[j] == entity)
                        {
                            unique = false;
                            break;
                        }
                    }
                    
                    if(unique)
                    {
                        unique_blocking_entities[unique_blocking_entity_count] = entity;
                        unique_blocking_entity_count += 1;
                    }
                }
                
                Assert(unique_blocking_entity_count > 0);
                
                bool unequip_blocking = true;
                if(verbose)
                {
                    if(unique_blocking_entity_count == 1)
                    {
                        Print
                        (
                            "\n%s is occypying a slot(s) that %s requires... Unequip it?", 
                            Colored_Name(*unique_blocking_entities, game_state).ptr,
                            target_name.ptr
                        );
                    }
                    else
                    {
                        Print("Items: ");
                        for(u64 i = 0; i < unique_blocking_entity_count; ++i)
                        {
                            if(i > 0)
                            {
                                if(i == unique_blocking_entity_count - 1)
                                {
                                    Print(" and ");
                                }
                                else
                                {
                                    Print(", ");
                                }
                            }
                            Print("%s", Colored_Name(unique_blocking_entities[i], game_state).ptr);
                        }
                        Print(" are blocking slots that %s requires... Unequip them?", target_name.ptr);
                    }
                    
                    unequip_blocking = User_Query_Yes_No(game_state);
                }
                
                if(unequip_blocking)
                {
                    if(verbose)
                    {
                        Print("\nYou equip %s", target_name.ptr);
                    }
                    
                    for(u64 i = 0; i < unique_blocking_entity_count; ++i)
                    {
                        bool item_was_unequipped = Unequip(actor, unique_blocking_entities[i], game_state);
                        Assert(item_was_unequipped);
                    }
                    
                    for(u64 i = 0; i < blocking_slots_count; ++i)
                    {
                        Reference* slot = blocking_slots[i];
                        *slot = target_ref;
                    }
                    
                    for(u64 i = 0; i < slots_to_use_count; ++i)
                    {
                        Reference* slot = slots_to_use[i];
                        *slot = target_ref;
                    }
                }
                else
                {
                    Print("\nAborting... equip %s", target_name.ptr);
                    item_was_equiped = false;
                }
            }
            
            Restore(scratch_buffer, snapshot);
            
            if(item_was_equiped && target->on_equip_effect_offset.v)
            {
                Effect_Instance on_equip_effect_instance = 
                {
                    UNLIMITED_DURATION,
                    target->on_equip_effect_offset,
                    target_ref
                };
                
                Apply_Effect_Result apply = Apply_Effect(actor, on_equip_effect_instance, game_state);
                Assert(apply == Apply_Effect_Result::success);
            }
        }
        else if(verbose)
        {
            Print("\n%s is already equipped...", target_name.ptr);
            item_was_equiped = false;
        }
    }
    
    return item_was_equiped;
}


SIG void Print_Uses(Entity* entity)
{
    if(entity->interactable.uses_count)
    {
        if(entity->interactable.uses_count == UNLIMITED_USES)
        {
            Print("Uses: [UNLIMITED]");
        }
        else
        {
            Print("Uses: %d", entity->interactable.uses_count);
        }
    }
    else
    {
        Print("Uses: [EMPTY]");
    }
}


SIG void Open(Entity* actor, Game_State* game_state)
{
    actor->flags |= EFlags::is_open;
    
    Entity_Root_Node* inventory = &actor->inventory;
    
    while(Has_Content(inventory))
    {
        if(Entity_Node* inv = Pointer(inventory->node_offset, game_state))
        {
            Entity* entity = Dereference(inv->entities, game_state);
            Entity* residence = Dereference(actor->residence, game_state);

            Deep_Insert(entity, residence, game_state);
            
            Print("\n\t- %s", Name(entity, game_state).ptr);
        }
        else
        {
            Warn("Invalid code path.");
            break;
        }
    }
}


SIG u64 Longest_Entity_Name_In_Actor_Storage(Entity* actor, Game_State* game_state, u64* out_count DEF(0))
{
    Entity* storage = Dereference(actor->residence, game_state);

    u64 count = 0;
    u64 result = 0;
    Entity_Iterator iter = Make_Iterator(storage, game_state);
    while(Entity* entity = Next_Entity(&iter))
    {
        if(entity != actor)
        {
            count += 1;
            result = Max(result, Name(entity, game_state).length);
        }
    }

    if(out_count)
    {
        *out_count = count;
    }

    return result;
}


SIG u64 Longest_Entity_Name_In_Actor_Inventory(Entity* actor, Game_State* game_state, u64* out_count DEF(0), s16* out_heaviest_weight DEF(0))
{
    s16 heaviest_weight = 0;
    u64 count = 0;
    u64 result = 0;
    Entity_Iterator iter = Make_Iterator(actor, game_state);
    while(Entity* entity = Next_Entity(&iter))
    {
        count += 1;
        result = Max(result, Name(entity, game_state).length);
        heaviest_weight = Max(heaviest_weight, entity->weight);
    }

    if(out_count)
    {
        *out_count = count;
    }

    if(out_heaviest_weight)
    {
        *out_heaviest_weight = heaviest_weight;
    }

    return result;
}


SIG bool Glance(Entity* actor, Game_State* game_state, Report_Turn_Taken_Status::T report_turn_taken_status DEF(Report_Turn_Taken_Status::T(1)))
{
    Entity* actor_residence = Dereference(actor->residence, game_state);
    
    Assert(actor_residence);

    bool first = true;
    if(actor_residence)
    {
        u64 entity_total_count;
        s32 longest_entity_name = (s32)Longest_Entity_Name_In_Actor_Storage(actor, game_state, &entity_total_count);
        s32 digit_count = Digits(s32(entity_total_count));

        u32 entity_count = 0;
        
        Entity_Iterator iter = Make_Iterator(actor_residence, game_state);
        while(Entity* entity = Next_Entity(&iter))
        {
            if(entity != actor)
            {
                entity_count += 1;

                if(first)
                {
                    Print("\nYou glance around the room and see:");
                    Wait(0.2, game_state);
                    first = false;
                }

                Print
                (
                    "\n| - %-*d %s%*s%s", 
                    digit_count,
                    entity_count, 
                    Entity_Color(entity, game_state), 
                    longest_entity_name,
                    Name(entity, game_state).ptr, 
                    game_state->default_color.data
                );
                Wait(0.1, game_state);

                if(entity->flags & EFlags::actor && !(entity->flags & EFlags::hidden_iniative))
                {
                    if(Is_Alive(entity))
                    {
                        Print(" [HP:%d/%d]", entity->_health, Max_Health(entity, game_state));
                    }
                    else
                    {
                        Print(" [DEAD]");
                    }
                }
                else if(Is_Item(entity))
                {
                    if(entity->_health <= 0)
                    {
                        Print(" [BROKEN]");
                    }
                }
                
                if(report_turn_taken_status && !(entity->actions & AT::normal) && Is_Alive(entity) && !(entity->flags & EFlags::hidden_iniative))
                {
                    // TODO: Ask Nyxm what was the word!!! spent? used? ... i dunno. Just ask.
                    Print(" *EXHAUSTED*");
                }
                
                if(entity->flags & (EFlags::container & EFlags::is_open) && Is_Empty(&entity->inventory))
                {
                    Print(" [EMPTY]");
                }
            }
        }
    }
    
    return !first;
}


SIG void Remove_Random_Effect(Entity* entity, String source_name, Game_State* game_state)
{
    u32 count = 0;
    Effects_Iterator iter = Make_Iterator(&entity->active_effects, game_state);
    while(Effect* effect = Next_Effect(&iter))
    {
        if(effect->type)
        {
            count += 1;
        }
    }

    if(count)
    {
        u32 idx_to_delete = Roll(count, game_state) - 1;
        count = 0;
        iter = Make_Iterator(&entity->active_effects, game_state);
        while(Effect_Instance* instance = Next(&iter))
        {
            Effect* effect = Pointer(instance->effect_offset, game_state);
            if(effect->type)
            {
                if(count == idx_to_delete)
                {
                    String effect_name = Effect_Name(instance, game_state);
                    String message = Format_Message(game_state, "%s removes %s from %s.", source_name.ptr, effect_name.ptr, Name(entity, game_state).ptr);
                    Push_Message(message, game_state);
                    
                    iter.idx -= 1;
                    Delete_Effect_Slot(&entity->active_effects, iter.current_node, &iter.idx, 0, game_state);
                    break;
                }
                count += 1;
            }
        }
    }
}


SIG Damage_Modifiers_Result Damage_Modifier_From_Effects(Entity* attacker, Attack_Record* ar, Game_State* game_state)
{
    s32 total_pierce = 0;
    s32 total_mod = 0;
    f32 total_mult = 1;

    u64 effect_count_with_damage_modifiers = 1;
    if(ar->is_critical_success)
    {
        effect_count_with_damage_modifiers += 1;
    }

    {
        Effects_Iterator iter = Make_Iterator(&attacker->active_effects, game_state);
        while(Effect* effect = Next_Effect(&iter))
        {
            if(effect->damage_die.count || effect->raw_damage_modifier || (effect->flags & Effect_Flags::has_damage_multiplier))
            {
                effect_count_with_damage_modifiers += 1;
            }
        }
    }
        
    ar->damage_modifier_count = effect_count_with_damage_modifiers;
    ar->damage_modifiers = Push_Array(&game_state->scratch_buffer, Damage_Modifier, ar->damage_modifier_count);

    u64 modifier_idx = 0;
    
    if(ar->is_critical_success)
    {
        Damage_Modifier crit_mod = {};
        crit_mod.source = Push_Struct(&game_state->scratch_buffer, Effect_Instance);
        crit_mod.source->effect_offset = Get_Critical_Effect_Offset(game_state);
        crit_mod.damage_multiplier = Critical_Multiplier(attacker, game_state);
        
        crit_mod.has_damage_multiplier = true;
        total_mult *= crit_mod.damage_multiplier;
        
        ar->damage_modifiers[modifier_idx] = crit_mod;
        modifier_idx += 1;
    }
    
    {
        Damage_Modifier might_mod = {};
        might_mod.source = Push_Struct(&game_state->scratch_buffer, Effect_Instance);
        might_mod.source->effect_offset = Get_Might_Effect_Offset(game_state);
        might_mod.raw_damage_modifier = Get_Stat_Value(attacker, Stats::might, game_state);
        total_mod += might_mod.raw_damage_modifier;

        ar->damage_modifiers[modifier_idx] = might_mod;
        modifier_idx += 1;
    }

    Effects_Iterator iter = Make_Iterator(&attacker->active_effects, game_state);
    while(Effect_Instance* instance = Next(&iter))
    {
        Effect* effect = Pointer(instance->effect_offset, game_state);
        if(effect->damage_die.count || effect->raw_damage_modifier || (effect->flags & Effect_Flags::has_damage_multiplier))
        {
            Damage_Modifier mod = {};
            mod.source = instance;
            mod.damage_die = effect->damage_die;
            mod.results_control_block = Push_Array(&game_state->scratch_buffer, s32*, mod.damage_die.count);
            mod.raw_damage_modifier = effect->raw_damage_modifier;
            mod.damage_multiplier = effect->damage_multiplier;
            mod.pierce = effect->pierce;
            mod.has_damage_multiplier = (effect->flags & Effect_Flags::has_damage_multiplier) > 0;

            for(s16 i = 0; i < effect->damage_die.count; ++i)
            {
                Dice dice = effect->damage_die.unique_die[i];
                s32* result = Roll_With_Record(dice, game_state);
                mod.results_control_block[i] = result;
                total_mod += *result;
            }

            total_pierce += mod.pierce;
            total_mod += mod.raw_damage_modifier;
            if(mod.has_damage_multiplier)
            {
                total_mult *= mod.damage_multiplier;
            }

            ar->damage_modifiers[modifier_idx] = mod;
            modifier_idx += 1;
        }
    }

    total_mod = Round_To_S32(f32(total_mod) * total_mult);

    return {total_mod, total_pierce};
}


SIG u64 Attack_Modifier_Mask(Attack_Mod::T modifier)
{
    u64 mask = u64(1) << u64(modifier);
    return mask;
}


SIG u64 Class_Mask(Class::T _class)
{
    u64 mask = u64(1) << u64(_class);
    return mask;
}


SIG bool Can_Use_Attack_Modifier(Entity* entity, Attack_Mod::T modifier)
{
    bool standard_attack = !modifier;
    bool knows_the_attack = (entity->known_attack_modifiers & Attack_Modifier_Mask(modifier)) > 0;
    bool result = standard_attack || knows_the_attack;
    result = result || (entity->flags & EFlags::godmode) > 0;

    return result;
}


SIG void Apply_Or_Describe_Attak_Modifier(Entity** attacker_ptr, Entity** defender_ptr, Attack_Mod::T modifier, Game_State* game_state)
{
    // It might seem strange to use the same function for describing and applying, 
    // but this way I don't need two places that connect the function to the enumarion.
    Entity* attacker = *attacker_ptr;
    Entity* defender = *defender_ptr;

    switch(modifier)
    {
        case Attack_Mod::COUNT:
        case Attack_Mod::standard:
        break;

        case Attack_Mod::reckless:
        {
            Apply_Effect(attacker, Reckless_Attack(attacker, game_state), game_state);
        }break;

        case Attack_Mod::careful:
        {
            Apply_Effect(attacker, Careful_Attack(attacker, game_state), game_state);
        }break;

        case Attack_Mod::weakspot:
        {
            Apply_Effect(attacker, Weakspot_Attack(attacker, game_state), game_state);
        }break;

        case Attack_Mod::allin:
        {
            Apply_Effect(attacker, Allin_Attack(attacker, game_state), game_state);
        }break;

        case Attack_Mod::guarding:
        {
            Apply_Effect(attacker, Guarding_Attack(attacker, game_state), game_state);
        }break;

        case Attack_Mod::evasive:
        {
            Apply_Effect(attacker, Evasive_Attack(attacker, game_state), game_state);
        }break;

        case Attack_Mod::execute:
        {
            Apply_Effect(attacker, Execute_Attack(attacker, game_state), game_state);
        }break;

        case Attack_Mod::disarming:
        {
            Apply_Effect(attacker, Disarming_Attack(attacker, game_state), game_state);
        }break;

        case Attack_Mod::vampiric:
        {
            Apply_Effect(attacker, Vampiric_Attack(attacker, game_state), game_state);
        }break;

        case Attack_Mod::blessed:
        {
            Apply_Effect(attacker, Blessed_Attack(attacker, game_state), game_state);
        }break;

        case Attack_Mod::berserking:
        {
            Apply_Effect(attacker, Berserking_Attack(attacker, game_state), game_state);
        }break;

        case Attack_Mod::targeted:
        {
            if(attacker)
            {
                *defender_ptr = 0;

                AGAIN:
                Print("\nType the name the item equipped on %s that you wish to attack: ", Name(defender, game_state).ptr);
                String item_name = Get_User_Input(game_state);
                Entity* target_item = Find_Entity_By_Name(attacker, defender, item_name, game_state, Verbose::yes);
                if(target_item && Is_Equipped(defender, target_item, game_state))
                {
                    Print("Targeting: %s.", Name(target_item, game_state).ptr);
                    *defender_ptr = target_item;
                }
                else
                {
                    Print("\n%s is not an equipped item on %s. Do you wish to try again?", item_name.ptr, Name(defender, game_state).ptr);
                    if(User_Query_Yes_No(game_state))
                    {
                        goto AGAIN;
                    }
                }
            }
            else
            {
                Print("\nTarget an equiped item on the target.");
            }
        }break;

        case Attack_Mod::cleansing:
        {
            if(attacker)
            {
                Remove_Random_Effect(attacker, STR("Cleansing attack"), game_state);
            }
            else
            {
                Print("\nRemoves a random effect from the attacker.");
            }
        }break;

        case Attack_Mod::redirect:
        {
            Apply_Effect(attacker, Redirect_Attack(attacker, game_state), game_state);
        }break;

        case Attack_Mod::change:
        {
            Apply_Effect(attacker, Change_Attack(attacker, game_state), game_state);
        }break;

        case Attack_Mod::thieving:
        {
            Apply_Effect(attacker, Thieving_Attack(attacker, game_state), game_state);
        }break;

        case Attack_Mod::stylish:
        {
            Apply_Effect(attacker, Stylish_Attack(attacker, game_state), game_state);
        }break;

        // TODO: After the modifiers have been implemented kill the default. 
        // So that I get a compiler error if I add a new modifier, but forget to include it here.
        #if 1
        default:
        {
            Warn("Unimplemented attack modifier!");
        }
        #endif
    }
}


SIG void Proc_Thorns(Entity* attacker, Entity* defender, Game_State* game_state)
{
    Effects_Iterator iter = Make_Iterator(&defender->active_effects, game_state);
    while(Effect_Instance* instance = Next(&iter))
    {
        Effect* effect = Pointer(instance->effect_offset, game_state);
        if(effect->thorns_damage)
        {
            String effect_name = Effect_Name(instance, game_state);
            if(effect->thorns_damage > 0)
            {
                Deal_Damage(attacker, defender, effect_name, effect->thorns_damage, 0, Damage_Type::magical, game_state, Verbose::yes);
            }
            else
            {
                s32 healing = Abs(effect->thorns_damage);
                Heal(attacker, healing, effect_name, Verbose::yes, game_state);
            }
        }
    }
}


SIG void Attack(Entity* attacker, Entity* defender, Game_State* game_state, Attack_Mod::T modifier DEF(Attack_Mod::T(0)))
{
    Flush_Messages(game_state);

    Assert(attacker);

    Arena_Snapshot snapshot = Snapshot(&game_state->scratch_buffer);
    
    Apply_Or_Describe_Attak_Modifier(&attacker, &defender, modifier, game_state);

    if(attacker && defender)
    {
        Attack_Record ar = {};

        ar.attacker = Make_Reference(attacker, game_state);
        ar.defender = Make_Reference(defender, game_state);
        ar.attack_modifier = modifier;

        ar.target_pre_attack_health = defender->_health;
        
        if(ar.target_pre_attack_health > 0)
        {
            ar.crit_ranges = Critical_Ranges(attacker, game_state);
            ar.crit_dice_result = (s8)(Roll(CRITICAL_DICE_RANGE, game_state));

            if(ar.crit_dice_result >= ar.crit_ranges.success)
            {
                ar.is_critical_success = true;
            }
            else if(ar.crit_dice_result <= ar.crit_ranges.failure)
            {
                ar.is_critical_failure = true;
            }
            else
            {
                ar.accuracy_roll = Stat_Roll(attacker, Stats::accuracy, game_state);
                ar.dodge_roll = Stat_Roll(defender, Stats::dodge, game_state);
            }
            
            if(!ar.is_critical_failure && (ar.accuracy_roll.total_result >= ar.dodge_roll.total_result || ar.is_critical_success))
            {
                ar.is_hit = true;
                Damage_Modifiers_Result dmr = Damage_Modifier_From_Effects(attacker, &ar, game_state);

                String attacker_name = Name(attacker, game_state);
                ar.deal_damage_result = Deal_Damage(defender, attacker, attacker_name, dmr.damage, dmr.pierce, Damage_Type::physical, game_state, Verbose::no);

                Proc_Thorns(attacker, defender, game_state);

                // HIT!
                Proc_Effects(Offset_Of(Effect, on_hit_fn_offset), attacker, defender, &ar, game_state);
            }
            else
            {
                if(ar.is_critical_failure)
                {
                    attacker->stunned += 1;
                }

                Proc_Effects(Offset_Of(Effect, on_miss_fn_offset), attacker, defender, &ar, game_state);
                Proc_Effects(Offset_Of(Effect, on_dodge_fn_offset), defender, attacker, &ar, game_state);
            }

            Proc_Effects(Offset_Of(Effect, on_attack_fn_offset), attacker, defender, &ar, game_state);
        }
        
        Print_Attack_Record(&ar, game_state);
        
        Tick_Down_Effect_Durations(attacker, Duration_Type::attack, game_state);
        
        Print_Messages(game_state);

        Restore(&game_state->scratch_buffer, snapshot);
    }
}


SIG void Player_Action(Entity* actor, String actor_name, Game_State* game_state)
{
    Glance(actor, game_state);

    bool has_turn = true;
    while(actor->actions & AT::normal && has_turn)
    {
        if(actor->actions == Full_Action)
        {
            Print("\n\n- What do you [HP:%d/%d] do? : ", actor->_health, Max_Health(actor, game_state));
        }
        else if(actor->actions & AT::normal)
        {
            Print("\n\n- What do you [HP:%d/%d] do? (Normal action left) : ", actor->_health, Max_Health(actor, game_state));
        }
        
        String user_input = Get_User_Input(game_state);
        
        bool matching_command = false;
        
        Game_Command* first = Player_Actions;
        Game_Command* last = first + Array_Length(Player_Actions);
        
        for(Game_Command* cmd = first; cmd < last; ++cmd)
        {
            if(Match_Beginning_Case_Insensitive(user_input, cmd->name))
            {
                matching_command = true;
                
                String args = Forward(user_input, cmd->name.length);
                args = Skip_Whitespace(args);
                
                if(cmd->action_type == AT::free || actor->actions & cmd->action_type)
                {
                    u8 action_snapshot = actor->actions;
                    actor->actions &= ~cmd->action_type;
                    
                    switch(cmd->fn(actor, args, game_state))
                    {
                        case CMD_Result::success:
                        {
                            if(!game_state->loaded)
                            {
                                has_turn = !cmd->ends_turn;
                            }
                            else
                            {
                                return;
                            }
                        }break;
                        
                        case CMD_Result::invalid_args:
                        {
                            actor->actions = action_snapshot;
                            Print("\nInvalid arguments: \"%s\" for command... please try again. Use \"help\" %s for details.", args.ptr, cmd->name.ptr);
                        }break;
                        
                        case CMD_Result::abort:
                        {
                            actor->actions = action_snapshot;
                            Print("\nCommand aborted...");
                        }break;
                        
                        default:
                        {
                            Terminate("\nInvalid Code path!");
                        }
                    }
                }
                else
                {
                    Print("\n%s is a %s action. You have already used this type of action this turn.", cmd->name.ptr, Action_Name(cmd->action_type));
                }
                break;
            }
        }
        
        if(!matching_command)
        {
            Print("\nInvalid input... please try again. Use \"help\" to see a list of commands.");
        }
    }
}


SIG Entity* Redirected_Target(Entity* actor, String actor_name, Game_State* game_state)
{
    Entity* target = 0;
    Entity* space_entity = Dereference(actor->residence, game_state);
    Entity* player = Dereference(game_state->player, game_state);
    if(player && space_entity)
    {
        struct local
        {
            static bool Hostile_Against_Player(Entity* entity, void* user_ptr, Game_State*)
            {
                bool result = Is_Hostile_Against(entity, (Entity*)user_ptr);
                return result;
            }
        };

        target = Random_Entity_That_Matches_Criteria(&space_entity->inventory, local::Hostile_Against_Player, player, game_state);
        if(target)
        {
            Assert(target);
            Wait(0.8, game_state);
            Print("\n%s is redirected!", actor_name.ptr);
        }
        else
        {
            Wait(0.8, game_state);
            Print("\n%s is redirected, but there are no valid redirect targets in the room. Redirect is ignored.", actor_name.ptr);
        }
    }
    else
    {
        game_state->internal_error = true;
    }

    return target;
}


SIG Entity* Random_Entity_That_Matches_Criteria(Entity_Root_Node* storage, bool(*conditional)(Entity* entity, void* user_ptr, Game_State* game_state), void* user_ptr, Game_State* game_state)
{
    Entity* result = 0;
    if(storage)
    {
        u32 count = 0;
        Entity_Iterator iter = Make_Iterator(storage, game_state);
        while(Entity* entity = Next_Entity(&iter))
        {
            if(conditional(entity, user_ptr, game_state))
            {
                count += 1;
            }
        }

        if(count)
        {
            u32 idx = Roll(count, game_state) - 1;
            count = 0;
            iter = Make_Iterator(storage, game_state);
            while(Entity* entity = Next_Entity(&iter))
            {
                if(conditional(entity, user_ptr, game_state))
                {
                    if(idx == count)
                    {
                        result = entity;
                        break;
                    }
                    count += 1;
                }
            }
        }
    }

    return result;
}


SIG Entity* Find_Attack_Target(Entity* actor, Game_State* game_state)
{
    Entity* result = 0;

    u32 count = 0;
    Entity* room = Dereference(actor->residence, game_state);
    if(room)
    {
        struct local
        {
            static bool Condition(Entity* entity, void* user_ptr, Game_State*)
            {
                bool result = Is_Living_Enemy_Of(entity, (Entity*)user_ptr);
                return result;
            }
        };

        result = Random_Entity_That_Matches_Criteria(&room->inventory, local::Condition, actor, game_state);
    }
    else
    {
        Assert(0);
        game_state->internal_error = true;
    }

    return result;
}


SIG void NPC_Action(Entity* actor, String actor_name, Game_State* game_state)
{
    if(actor->flags & EFlags::aggressive)
    {
        if(actor->faction != Faction::none, actor->actions & AT::normal)
        {
            Entity* target = Find_Attack_Target(actor, game_state);

            if(actor->flags & EFlags::redirected)
            {
                if(Entity* new_target = Redirected_Target(actor, actor_name, game_state))
                {
                    target = new_target;
                }
            }

            if(target)
            {
                if(Is_Alive(target))
                {
                    Wait(.5, game_state);
                    actor->actions &= ~AT::normal;
                    Attack(actor, target, game_state);
                }
            }
        }
    }

    
    if(actor->flags & EFlags::burst_container)
    {
        Entity_Root_Node* inventory = &actor->inventory;
        if(Has_Content(inventory))
        {
            f32 v = Random_F32(game_state);
            
            bool bursts_open = v <= actor->burst_change;
            if(bursts_open)
            {
                if(Entity* outside_entity = Dereference(actor->residence, game_state))
                {
                    Entity_Root_Node* outside = &outside_entity->inventory;
                
                    // "%s bursts open releasing its conents:\n"
                    String str = Get_String(actor->burst_message_offset, game_state);
                    char* msg = (str.ptr)? str.ptr : "opens releasing it's contents";

                    Print("\n\n%s %s:", actor_name.ptr, msg);
                    Open(actor, game_state);
                }
                else
                {
                    game_state->internal_error = true;
                }
            }
        }
    }
}


SIG void Take_Action(Entity* actor, Game_State* game_state)
{
    Assert(game_state->running);
    Assert(actor->flags & EFlags::actor);

    if(Is_Alive(actor))
    {
        String actor_name = Colored_Name(actor, game_state);

        if(!(actor->flags & EFlags::hidden_iniative))
        {
            if(!actor->stunned)
            {
                Print("\n\n%s takes turn. ", actor_name.ptr);
            }
            else
            {
                Print("\n\n%s is stunned (%d) and loses its turn!", actor_name.ptr, actor->stunned);
            }         
        }

        if(!(actor->flags & EFlags::started_turn))
        {
            if(actor->_temp_health)
            {
                Print("\n%d points of temporary health expire.", actor->_temp_health);
                actor->_temp_health = 0;
            }

            Flush_Messages(game_state);

            Tick_Down_Effect_Durations(actor, Duration_Type::round, game_state);
            Proc_Effects(Offset_Of(Effect, on_turn_start_fn_offset), actor, game_state);
            actor->flags |= EFlags::started_turn;

            Print_Messages(game_state);
        }

        if(!actor->stunned)
        {
            if(Is_Alive(actor))
            {
                if(actor->flags & EFlags::player_controlled)
                {
                    Player_Action(actor, actor_name, game_state);
                }
                else
                {
                    NPC_Action(actor, actor_name, game_state);
                }
            }
        }
        else
        {
            actor->stunned -= 1;
        }    
        
        if(game_state->running && !game_state->restart && !game_state->loaded)
        {
            Flush_Messages(game_state);
            
            actor->flags &= ~EFlags::started_turn;
            Proc_Effects(Offset_Of(Effect, on_turn_end_fn_offset), actor, game_state);

            Print_Messages(game_state);
        }
    }

    actor->flags &= ~EFlags::redirected;
}


SIG u64 Hash_From_Key(Effect_Hash_Key key)
{
    u64 result = Weld(Random_PCG(key.line), Random_PCG(key.file));
    return result;
}


SIG bool Retrive_Effect(Effect_Hash_Key key, Effect_Offset* out, Game_State* game_state)
{
    bool result = false;
    
    Assert(key.line && key.file);

    u64 hash = Hash_From_Key(key);

    Effect_Hash_Table* htable = &game_state->permanent_effects;
    u64 idx = hash % Array_Length(htable->entries);
    
    Effect_Hash_Table_Entry entry = htable->entries[idx];
    Effect_Offset offset = entry.first_offset;
    for(u64 i = 0; i < entry.chain_length; ++i)
    {
        if(Effect* e = Pointer(offset, game_state))
        {
            if(e->key == key)
            {
                *out = offset;
                result = true;
                break;
            }
            else
            {
                offset = e->next;
            }
        }
        else
        {
            break;
        }
    }

    return result;
}


SIG Effect_Offset Insert_Effect(Effect effect, Effect_Hash_Key key, Game_State* game_state)
{
    #if SLOW
    Effect_Offset dummy;
    Assert(!Retrive_Effect(key, &dummy, game_state));
    #endif
    
    u64 hash = Hash_From_Key(key);

    Effect* permanent_storage_location = Request_Effect(game_state);
    *permanent_storage_location = effect;
    permanent_storage_location->key = key;
    permanent_storage_location->flags &= ~Effect_Flags::can_be_released;

    Effect_Hash_Table* htable = &game_state->permanent_effects;
    u64 idx = hash % Array_Length(htable->entries);
    Effect_Hash_Table_Entry* entry = htable->entries + idx;
    
    htable->insertions += 1;
    entry->chain_length += 1;
    if(entry->chain_length > 1)
    {
        if(entry->chain_length == 2)
        {
            htable->unique_collision_count += 1;
        }
        
        htable->collision_count += 1;
    }

    permanent_storage_location->next = entry->first_offset;
    Effect_Offset result = Offset(permanent_storage_location, game_state);
    entry->first_offset = result;

    return result;
}


SIG void Generate_From_Loot_Table(Entity* storage, Loot_Table table, u64 count, Rarity_Mode mode, Rarity::T target_rarity_A, Rarity::T target_rarity_B, Game_State* game_state)
{
    struct local
    {
        static bool Is_Suitable(Rarity::T entry_rarity, Rarity::T target_rarity_A, Rarity::T target_rarity_B, Rarity_Mode mode)
        {
            bool result = false;

            switch(mode)
            {
                case Rarity_Mode::minimum:
                {
                    result = entry_rarity >= target_rarity_A;
                }break;

                case Rarity_Mode::maximum:
                {
                    result = entry_rarity <= target_rarity_A;
                }break;

                case Rarity_Mode::between:
                {
                    result = entry_rarity >= target_rarity_A && entry_rarity <= target_rarity_B;
                }break;

                case Rarity_Mode::guaranteed:
                {
                    result = entry_rarity == target_rarity_A;
                }break;
            }

            return result;
        }
    };

    if(count)
    {
        f32 suitable_total_change = 0;
        Loot_Table_Entry* end = table.array + table.count;
        for(Loot_Table_Entry* entry = table.array; entry < end; ++entry)
        {
            if(local::Is_Suitable(entry->rarity, target_rarity_A, target_rarity_B, mode))
            {
                suitable_total_change += entry->change;
            }
        }
        
        if(suitable_total_change > 0)
        {
            LOOP(count)
            {
                f32 selector = Random_F32(game_state) * suitable_total_change;
                f32 accumilator = 0;

                for(Loot_Table_Entry* entry = table.array; entry < end; ++entry)
                {   
                    if(local::Is_Suitable(entry->rarity, target_rarity_A, target_rarity_B, mode))
                    {
                        accumilator += entry->change;
                        if(selector <= accumilator)
                        {
                            entry->fn(storage, game_state);
                            break;
                        }
                    }
                }
            }
        }
    }
}


SIG Loot_Table Merge_Loot_Tables(Loot_Table A, Loot_Table B, Arena* arena)
{
    Loot_Table table = {};
    table.count = A.count + B.count;
    table.array = Push_Array(arena, Loot_Table_Entry, table.count);
    Mem_Copy(table.array, A.array, sizeof(*A.array) * A.count);
    Mem_Copy(table.array + A.count, B.array, sizeof(*B.array) * B.count);
    return table;
}


SIG Loot_Table Merge_Loot_Tables(Loot_Table A, Loot_Table B, Loot_Table C, Arena* arena)
{
    Loot_Table result = Merge_Loot_Tables(C, Merge_Loot_Tables(A, B, arena), arena);
    return result;
}


SIG Loot_Table Merge_Loot_Tables(Loot_Table A, Loot_Table B, Loot_Table C, Loot_Table D, Arena* arena)
{
    Loot_Table result = Merge_Loot_Tables(D, Merge_Loot_Tables(C, Merge_Loot_Tables(A, B, arena), arena), arena);
    return result;
}


SIG Loot_Table Merge_Loot_Tables(Loot_Table A, Loot_Table B, Loot_Table C, Loot_Table D, Loot_Table E, Arena* arena)
{
    Loot_Table result = Merge_Loot_Tables(E, Merge_Loot_Tables(D, Merge_Loot_Tables(C, Merge_Loot_Tables(A, B, arena), arena), arena), arena);
    return result;
}


SIG Loot_Table Merge_Loot_Tables(Loot_Table A, Loot_Table B, Loot_Table C, Loot_Table D, Loot_Table E, Loot_Table F, Arena* arena)
{
    Loot_Table result = Merge_Loot_Tables(F, Merge_Loot_Tables(E, Merge_Loot_Tables(D, Merge_Loot_Tables(C, Merge_Loot_Tables(A, B, arena), arena), arena), arena), arena);
    return result;
}


SIG void Fill_Loot_Table_Changes_And_Item_Rarity(Loot_Table* table, Game_State* game_state)
{
    struct local
    {
        static f32 Standard_Drop_Change_Based_On_Rarity(Rarity::T rarity)
        {
            using namespace Rarity;

            constexpr f32 STANDARD_COMMON_DROP_CHANGE       = 100;
            constexpr f32 STANDARD_RARE_DROP_CHANGE         = 70;
            constexpr f32 STANDARD_MAGICAL_DROP_CHANGE      = 50;
            constexpr f32 STANDARD_EPIC_DROP_CHANGE         = 20;
            constexpr f32 STANDARD_LEGENDARY_DROP_CHANGE    = 1;

            switch(rarity)
            {
                case common:
                {
                    return STANDARD_COMMON_DROP_CHANGE;
                }break;

                case rare:
                {
                    return STANDARD_RARE_DROP_CHANGE;
                }break;

                case magical:
                {
                    return STANDARD_MAGICAL_DROP_CHANGE;
                }break;

                case epic:
                {
                    return STANDARD_EPIC_DROP_CHANGE;
                }break;

                case legendary:
                {
                    return STANDARD_LEGENDARY_DROP_CHANGE;
                }break;

                case COUNT: Terminate("Invalid code path!");
            }
            return 0;
        }
    };

    if(!table->filled)
    {
        table->filled = true;

        Loot_Table_Entry* end = table->array + table->count;
        for(Loot_Table_Entry* entry = table->array; entry < end; ++entry)
        {
            if(entry->change <= 0)
            {
                // Even if the user filled in a Rarity, the generation function is used to get the "True" rarity of the item.
                {
                    Entity* entity = entry->fn(0, game_state);
                    entry->rarity = entity->rarity;
                    Delete_Entity(entity, game_state);
                }

                // But the change can be pre filled in... for what ever the reason.
                if(entry->change <= 0)
                {
                    entry->change = local::Standard_Drop_Change_Based_On_Rarity(entry->rarity);
                }
            }
        }
    }
}


SIG bool Roll_Initiative(Entity* entity, Game_State* game_state)
{
    bool result = false;

    if(entity && Is_Alive(entity))
    {
        Roll_Result initative = {};
        initative.total_result = S16_MIN;
        bool visible = !(entity->flags & (EFlags::hidden_iniative | EFlags::goes_last)) && !entity->stunned;
        
        if(!entity->stunned)
        {
            entity->actions = Full_Action;
        }
        else
        {
            entity->actions = 0;
        }

        if(!entity->stunned && !(entity->flags & EFlags::goes_last))
        {
            initative = Stat_Roll(entity, Stats::speed, game_state);
        }
        
        entity->initiative = {Make_Reference(entity, game_state), initative, visible};
        result = true;
        
        entity->flags &= ~EFlags::goes_last;
    }
    
    return result;
}


SIG void Sort_Iniative_Order(Reference* refs, Game_State* game_state)
{
    struct local
    {
        static bool Is_Sorted(Game_State* game_state)
        {
            bool result = true;
            s64 last_initiative = S64_MAX;
            Entity_Iterator iter = Make_Iterator(&game_state->initiative_order, game_state);
            while(Reference* ref = Next(&iter))
            {
                Entity* entity = Dereference(ref, game_state);
                s64 initiative = entity->initiative.value.total_result;
                if(last_initiative < initiative)
                {
                    result = false;
                    break;
                }

                last_initiative = initiative;
            }

            return result;
        }


        static bool Is_Sorted(Reference* refs, u64 count, Game_State* game_state)
        {
            bool result = true;
            
            for(u64 i = 0; i < count - 1; ++i)
            {
                Reference* A = refs + i;
                Reference* B = A + 1;

                Entity* EA = Dereference(A, game_state);
                Entity* EB = Dereference(B, game_state);

                s32 a = local::Init(EA);
                s32 b = local::Init(EB);

                if(a < b || (a == b && EA->initiative.value.stat_value < EB->initiative.value.stat_value))
                {
                    result = false;
                    break;
                }
            }
        
            return result;
        }

        static bool Content_is_Valid(Reference* refs, u64 count, Game_State* game_state)
        {
            bool result = true;
            for(u64 i = 0; i < count; ++i)
            {
                if(Dereference(refs + i, game_state) == 0)
                {
                    result = false;
                    break;
                }
            }
            return result;
        }

        static _inline s32 Init(Entity* entity)
        {
            s32 result = entity->initiative.value.total_result;
            return result;
        }

        static _inline void Swap(Reference* a, Reference* b)
        {
            Reference copy = *a;
            *a = *b;
            *b = copy;
        }
    };

    // TODO: Better sorting algorithm! This is just a bubble sort. Maybe merge sort would work well with these linked buckets?
    u64 count = game_state->initiative_count;
    
    Assert(count);
    if(count)
    {
        Assert(local::Content_is_Valid(refs, count, game_state));

        bool swapped = true;
        for(u64 i = 0; i < count - 1 && swapped; ++i)
        {
            swapped = false;
            for(u64 j = 0; j < count - 1; ++j)
            {
                Reference* A = refs + j;
                Reference* B = A + 1;

                Entity* EA = Dereference(A, game_state);
                Entity* EB = Dereference(B, game_state);
                
                Assert(EA);
                Assert(EB);

                s32 a = local::Init(EA);
                s32 b = local::Init(EB);

                if(b > a || (b == a && EB->initiative.value.stat_value > EA->initiative.value.stat_value))
                {
                    local::Swap(A, B);
                    swapped = true;
                }

                Assert(Dereference(A, game_state));
                Assert(Dereference(B, game_state));
            }
        }
        
        Assert(local::Is_Sorted(refs, count, game_state));

        Entity_Iterator iter = Make_Iterator(&game_state->initiative_order, game_state);
        
        u64 i = 0;
        while(Reference* reference = Next(&iter))
        {
            *reference = refs[i++];
        }

        Assert(local::Is_Sorted(game_state));
    }

}


SIG void Sort_Space(Entity_Root_Node* space, Game_State* game_state)
{
    /*
        [ALIVE]
        [DEAD] <--
        [ALIVE]  |
        [ALIVE]  |
        ->       |
        [ALIVE]  |
        [DEAD] <-|--
        [ALIVE]  | |
        [ALIVE]  | |
        ->       | |
        [ALIVE]  | |
        [ALIVE]--|>|
        [DEAD]   |
        [ALIVE]->|
        
        When encountering a dead thing; backwards iterate through the block chain to find the last living thing.
        If the last living thing is before the dead thing, then the space is sorted. Early out.
        If there is no living thing, then the space is also sorted. Early out.
        if the last living thing is after the dead thing. Swap them and continue.
    */
    
    Entity* player = Dereference(game_state->player, game_state);
    if(player)
    {
        u64 count = Count(space, game_state);
        int i = 0;
        
        Entity_Iterator iter = Make_Iterator(space, game_state);
        
        while(Reference* A = Next(&iter))
        {
            Entity* entity = Dereference(A, game_state);
            
            if(!Is_Living_Enemy_Of(entity, player))
            {
                // Find last living
                Backwards_Iterator back_iter = Make_Backwards_Iterator(space, game_state);
                while(Reference* B = Previous(&back_iter))
                {
                    Entity* other = Dereference(B, game_state);
                    
                    if(entity == other)
                    {
                        // Sorted! -> early exit.
                        // NOTE: goto to break out of nested loops. Don't @ me.
                        goto DONE;
                    }
                    else
                    {
                        if(Is_Living_Enemy_Of(other, player))
                        {
                            // Swap!
                            Reference temp = *A;
                            *A = *B;
                            *B = temp;
                        }
                    }

                    i += 1;
                }
            }
        }
        
        DONE:;
    }
    else
    {
        Assert(0);
        game_state->internal_error = true;
    }
}


SIG u64 Count_Longest_Round_Effect_Duration(Entity* actor, Game_State* game_state)
{
    u64 result = 0;
    Effects_Iterator iter = Make_Iterator(&actor->active_effects, game_state);
    while(Effect_Instance* instance = Next(&iter))
    {
        if(instance->duration != UNLIMITED_DURATION && instance->duration_type == Duration_Type::round)
        {
            result = Max(instance->duration, result);
        }
    }
    return result;
}


SIG void Tick_Down_Effect_Durations(Entity* actor, Duration_Type type, Game_State* game_state)
{
    #if SLOW
    {
        Effects_Iterator iter = Make_Iterator(&actor->active_effects, game_state);
        while(Effect_Instance* instance = Next(&iter))
        {
            instance->update_ticked = false;
        }
    }
    #endif

    Effects_Root* root = &actor->active_effects;
    
    Effects_Node* node = Pointer(root->root_offset, game_state);
    u64 count = (node == Pointer(root->head_offset, game_state))? root->head_count : Array_Length(node->instances);
    
    while(node)
    {
        for(u64 idx = 0; idx < count; ++idx)
        {
            Effect_Instance* instance = node->instances + idx;
            
            #if SLOW
            instance->update_ticked = true;
            #endif

            if(instance->duration != UNLIMITED_DURATION && instance->duration_type == type)
            {
                if(instance->zero_ticked)
                {
                    instance->duration -= 1;
                    if(!instance->duration)
                    {
                        Effect* effect = Pointer(instance->effect_offset, game_state);
                        Assert(effect);

                        String effect_name = Get_String(effect->name_offset, game_state);
                        if(effect_name.ptr)
                        {
                            Push_Message(Format_Message(game_state, "%s expires.", effect_name.ptr), game_state);
                        }
                        else
                        {
                            Warn("Un-named effect expired... error?");
                            Push_Message(STR("Unknown effect expires."), game_state);
                        }

                        Delete_Effect_Slot(root, node, &idx, &count, game_state);
                    }
                }
                else
                {
                    instance->zero_ticked = true;
                }
            }
        }

        node = Pointer(node->next, game_state);
        count = (node == Pointer(root->head_offset, game_state))? root->head_count : Array_Length(node->instances);
    }

    #if SLOW
    {
        Effects_Iterator iter = Make_Iterator(&actor->active_effects, game_state);
        while(Effect_Instance* instance = Next(&iter))
        {
            Assert(instance->update_ticked);
        }
    }
    #endif
}


SIG _inline void Enter_A_Room_Printout(Entity* player, Entity* room, Game_State* game_state)
{
    if(game_state->level != 0 || game_state->distance_travelled > 1)
    {
        Print("\n\n%s travels deeper into The Dungeon.", Name(player, game_state).ptr);
    }
    
    Wait(1, game_state);
    Print("\n.");
    Wait(0.5, game_state);
    Print("\n..");
    Wait(0.5, game_state);
    Print("\n...");
    Wait(1, game_state);
    Print("\n\n%s arrives at %s.", Colored_Name(player, game_state).ptr, Name(room, game_state).ptr);
    Wait(1.5, game_state);
    Print("\n%s", Get_String(room->description_offset, game_state).ptr);
    Wait(2, game_state);
    Print("\n");
    Glance(player, game_state, Report_Turn_Taken_Status::no);
}


SIG Room_Generator_Element Pick_Room_Generator(Room_Generator_Element_Array array, u32 selector, Game_State* game_state)
{
    u64 idx = array.count - 1;

    u32 accumulator = 0;
    for(u64 i = 0; i < array.count; ++i)
    {
        accumulator += array.array[i].size;
        
        if(selector <= accumulator)
        {
            idx = i;
            break;
        }
    }

    Room_Generator_Element result = array.array[idx];
    return result;
}


SIG Room_Generator_Element Pick_Room_Generator(Room_Generator_Element_Array array, Game_State* game_state)
{
    s32 total = 0;
    for(u64 i = 0; i < array.count; ++i)
    {
        total += array.array[i].size;
    }
    Assert(total);
    u32 selector = Roll(total, game_state) - 1;
    Room_Generator_Element result = Pick_Room_Generator(array, selector, game_state);
    return result;
}


SIG void Prompt_User_For_Command_And_Attempt_To_Execute(Command* commands, u64 count, void* user_ptr, Game_State* game_state)
{
    CMD_Result::T result = CMD_Result::none;

    String user_input = Get_User_Input(game_state);
    String name = {};
    String args = {};
    String help = STR("help");

    if(Match_Beginning_Case_Insensitive(user_input, help))
    {
        name = help;
        args = Forward(user_input, name);
        args = Skip_Whitespace(args);

        // User asking for a command description.
        if(args.length > 0)
        {
            for(u64 i = 0; i < count; ++i)
            {
                Command cmd = commands[i];

                String cmd_name;
                cmd.fn(Call_Style::name, &cmd_name, {});
                Assert(name.length && name.ptr);

                if(Match_Beginning_Case_Insensitive(args, cmd_name))
                {
                    result = CMD_Result::success;
                    cmd.fn(Call_Style::describe, 0, {});
                    break;
                }
            }
        }

        // User asking for command list.
        else
        {
            result = CMD_Result::success;
            
            Print("\nAvailable commands are: ");
            for(u64 i = 0; i < count; ++i)
            {
                Command cmd = commands[i];

                String cmd_name;
                cmd.fn(Call_Style::name, &cmd_name, {});
                Assert(cmd_name.length && cmd_name.ptr);
                Print("\n|%11s", cmd_name.ptr);
            }
        }
    }
    else
    {
        for(u64 i = 0; i < count; ++i)
        {
            Command cmd = commands[i];

            cmd.fn(Call_Style::name, &name, {});
            Assert(name.length && name.ptr);

            if(Match_Beginning_Case_Insensitive(user_input, name))
            {
                args = Forward(user_input, name);
                args = Skip_Whitespace(args);
                
                result = cmd.fn(Call_Style::execute, user_ptr, args);
                break;
            }
        }
    }

    switch(result)
    {
        case CMD_Result::success:break;
        
        case CMD_Result::invalid_args:
        {
            Print("\nInvalid arguments \"%s\" for command \"%s\". Use the command \"help %s\" for more information.", args.ptr, name.ptr, name.ptr);
        }break;

        case CMD_Result::abort:
        {
            Print("\nCommand \"%s\" was aborted.", name.ptr);
        }break;

        case CMD_Result::none:
        {
            Print("\n\"%s\" is not a valid command. Use the command \"help\" for a list of available commands.", user_input.ptr);
        }break;
    }
}


SIG void Create_Player_Charater(Game_State* game_state)
{
    Wait(1.3, game_state);
    Print("\n\nTo start off with pick a class. This choise determines your starting stats, equipment and known attack modfiers.");
    Wait(0.5, game_state);
    Print("\nMore classes can be unlocked by playing the game.");
    Wait(0.5, game_state);
    Print("\nIf you're new it is recomended to first try the \"adventurer\".");

    u64 available_classes = 
        Class_Mask(Class::adventurer) | 
        Class_Mask(Class::knight) | 
        Class_Mask(Class::wretched);

    Character_Creator cc = {game_state, (Entity**)Push(&game_state->scratch_buffer, 0)};

    for(u64 i = 0; i < Class::COUNT; ++i)
    {
        u64 mask = Class_Mask(Class::T(i));
        if((available_classes & mask) && Class::create_fn[i])
        {
            *Push_Struct(&game_state->scratch_buffer, Entity*) = Class::create_fn[i](game_state);
            cc.template_count += 1;
        }
    }
    Assert(cc.template_count);
    
    
    #if !QUICKSTART
    {
        Arena_Snapshot snapshot = Snapshot(&game_state->scratch_buffer);
        Command* commands;
        u64 count;

        Get_Character_Creator_Commands(game_state, &commands, &count);
        Wait(1, game_state);
        cc.running = true;
        while(cc.running)
        {
            Print("\n\n- What do you do: ");
            Prompt_User_For_Command_And_Attempt_To_Execute(commands, count, &cc, game_state);
        }

        Restore(&game_state->scratch_buffer, snapshot);
    }
    #endif

    if(game_state->running)
    {
        Entity** selection = cc.class_templates + cc.selected_idx;
        
        for(u64 i = 0; i < cc.template_count; ++i)
        {
            if((cc.class_templates + i) != selection)
            {
                Delete_Entity(cc.class_templates[i], game_state);
            }
        }

        Entity* player = *selection;
        player->flags = 
            EFlags::player_controlled   |
            EFlags::actor;
        
        player->faction = Faction::player;    
        player->weight = 100;

        game_state->player = Make_Reference(player, game_state);
        Full_Heal(player, game_state);

        #if !QUICKSTART
        {
            Wait(1, game_state);
            Print("\n\nNow name your %s : ", Name(player, game_state).ptr);
            String name = Get_User_Input(game_state);
            player->name_offset = Offset(name, game_state);
        }
        #endif


        Wait(1, game_state);
        Print("\n\nGood luck %s!", Colored_Name(player, game_state).ptr);
        Wait(2, game_state);

        #if ENTRANCE
        game_state->room_generation_override_fn_offset = Offset(Generate_Entrance_Room, game_state);
        #endif
    }
}

        
SIG void Tick_Active_Effects_Down_To_Zero(Entity* actor, Game_State* game_state)
{
    u64 longest_round_effect_duration = Count_Longest_Round_Effect_Duration(actor, game_state);
    for(u64 i = 0; i < longest_round_effect_duration && Is_Alive(actor); ++i)
    {
        Effects_Iterator iter = Make_Iterator(&actor->active_effects, game_state);
        while(Effect_Instance* instance = Next(&iter))
        {
            Effect* effect = Pointer(instance->effect_offset, game_state);
            if(PROTOTYPE_EFFINST_ENT_GS* turn_start = Pointer(effect->on_turn_start_fn_offset, game_state))
            {
                turn_start(instance, actor, game_state);
            }

            if(PROTOTYPE_EFFINST_ENT_GS* turn_end = Pointer(effect->on_turn_end_fn_offset, game_state))
            {
                turn_end(instance, actor, game_state);
            }
        }

        Tick_Down_Effect_Durations(actor, Duration_Type::round, game_state);
    }
}


SIG Entity* Proceed_To_Next_Room(Game_State* game_state)
{
    Room_Generator_Element_Array(*levels[])() = 
    {
        Caves,
    };
    
    Entity* player = Dereference(game_state->player, game_state);
    Entity* prev_room = Dereference(player->residence, game_state);
    
    Flush_Messages(game_state);
    Tick_Active_Effects_Down_To_Zero(player, game_state);
    Tick_Down_Effect_Durations(player, Duration_Type::room, game_state);
    Print_Messages(game_state);

    Entity* room = prev_room;
    if(Is_Alive(player))
    {
        game_state->active_initiative_index = 0;
        game_state->initiative_count = 0;
        game_state->next_room = false;

        if(game_state->distance_travelled < 0)
        {
            game_state->distance_travelled = 0;
            game_state->level += 1;
            if(game_state->level == Array_Length(levels))
            {
                // you win!
            }
        }
        
        if(prev_room)
        {
            Remove_From_Residence(player, game_state);
            Assert(Dereference(player->residence, game_state) == 0);
            Delete_Entity(prev_room, game_state);
        }        
        room = Request_Entity(game_state);


        if(PROTOTYPE_ENT_GS* override_fn = Pointer(game_state->room_generation_override_fn_offset, game_state))
        {
            override_fn(room, game_state);
            game_state->room_generation_override_fn_offset = {};
        }
        else
        {
            Room_Generator_Element_Array rooms = levels[game_state->level % Array_Length(levels)]();
            u32 roll = Roll(21, game_state);
            u32 offset = Round_To_S32(Square_Root(f32(roll)));
            u32 selector = game_state->distance_travelled + offset;
            
            u32 accumulator = 0;
            Room_Generator_Element generator = Pick_Room_Generator(rooms, selector, game_state);
            generator.fn(room, game_state);

            game_state->distance_travelled += 1;
        }
        
        Deep_Insert(player, room, game_state);
        Sort_Space(&room->inventory, game_state);

        Enter_A_Room_Printout(player, room, game_state);
    }
    
    return room;
}


SIG void Prepare_Game_Round(Game_State* game_state)
{
    if(game_state->active_initiative_index == game_state->initiative_count)
    {
        game_state->initiative_count = 0;
        game_state->active_initiative_index = 0;

        Entity* player = Dereference(&game_state->player, game_state);
        Entity* room = Dereference(player->residence, game_state);

        Entity_Root_Node* space = &room->inventory;
        Assert(space);
        
        Sort_Space(space, game_state);

        while(game_state->initiative_order.node_offset.v)
        {
            game_state->initiative_order.count = 0;
            Release_Entity_Node(&game_state->initiative_order, game_state);
        }
        
        u64 visible_initiative_count = 0;
        Arena_Snapshot snapshot = Snapshot(&game_state->scratch_buffer);
        Reference* refs_base = (Reference*)Push(&game_state->scratch_buffer, 0);
        
        #if SLOW
        Reference* expected_next = refs_base;
        u64 counter = 0;
        #endif
        
        u64 longest_entity_name_lenght = 0;
        s32 longest_digit_count = 0;
        {
            Entity_Iterator iter = Make_Iterator(space, game_state);
            while(Reference* ref = Next(&iter))
            {
                Entity* entity = Dereference(ref, game_state);
                Assert(entity);

                if(Roll_Initiative(entity, game_state))
                {
                    longest_digit_count = Max(longest_digit_count, Digits(entity->initiative.value.total_result));
                    longest_entity_name_lenght = Max(longest_entity_name_lenght, Name(entity, game_state).length);
                    game_state->initiative_count += 1;
                    if(entity->initiative.visible)
                    {
                        visible_initiative_count += 1;
                    }

                    Insert(entity, &game_state->initiative_order, game_state);
                    
                    Reference* array_entry = Push_Struct(&game_state->scratch_buffer, Reference);
                    *array_entry = *ref;
                    
                    Assert(Dereference(*array_entry, game_state));
                    Assert(array_entry == (expected_next++));
                }
            }
        }
        
        Assert(game_state->initiative_count);
        if(game_state->initiative_count)
        {
            Sort_Iniative_Order(refs_base, game_state);

            if(visible_initiative_count > 1)
            {
                Print("\n\nBegin of a new round of combat! Press [Enter] to roll initiative: ");
                Get_User_Input(game_state);

                Print("\nInitiative order is:");
                
                Entity_Iterator iter = Make_Iterator(&game_state->initiative_order, game_state);
                while(Reference* ref = Next(&iter))
                {
                    Entity* entity = Dereference(ref, game_state);
                    Initiative* init = &entity->initiative;

                    if(init->visible)
                    {
                        Wait(0.4, game_state);

                        s32 npadding = s32(longest_entity_name_lenght + 1);
                        s32 dpadding = s32(longest_digit_count);
                        Print
                        (
                            "\n| -%s%*s%s with initiative of %*d", 
                            Entity_Color(entity, game_state),
                            npadding, 
                            Name(entity, game_state).ptr,
                            game_state->default_color.data,
                            dpadding, 
                            init->value.total_result
                        );

                        Print(" [%s(%d) + ", Stats::name[init->value.stat].ptr, init->value.stat_value);
                        Print_Dice(init->value.dice, init->value.dice_result);
                        Print("]");
                    }
                }

                Wait(1, game_state);
            }
        }
        else
        {
            game_state->internal_error = true;
        }

        Restore(&game_state->scratch_buffer, snapshot);
    }
}


SIG void Excecute_Game_Round(Game_State* game_state)
{
    Entity_Node* node = Pointer(game_state->initiative_order.node_offset, game_state);
    u64 count = game_state->initiative_order.count;
    u64 i = 0;

    while(node)
    {
        for(u64 j = 0; j < count; ++j, ++i)
        {
            if(i == game_state->active_initiative_index)
            {
                Entity* entity = Dereference(node->entities[j], game_state);
                Take_Action(entity, game_state);

                if(!game_state->running || game_state->restart || game_state->loaded || game_state->next_room)
                {
                    return;
                }

                game_state->active_initiative_index += 1;
            }
            else if(i > game_state->active_initiative_index)
            {
                Assert(0);
                
                node = 0;
                j = count;
                game_state->internal_error = true;
            }
        }

        node = Pointer(node->next, game_state);
        count = Array_Length(node->entities);
    }
}


SIG void Exit_Handling(Game_State* game_state)
{
    if(!game_state->internal_error)
    {
        game_state->loaded = false;
        if(game_state->restart)
        {
            game_state->running = false;
        }
        else if(game_state->running)
        {
            Entity* player = Dereference(&game_state->player, game_state);
            if(!Is_Alive(player))
            {
                game_state->running = false;
                
                Print("\n\nYou have died! Would you like to play again?");
                game_state->restart = User_Query_Yes_No(game_state);
            }
        }
    }
    else
    {
        game_state->running = false;
        game_state->restart = false;

        Print("\n[ERROR] Sorry... the game encountered an unrecovable error and must be shutdown.");
        Get_User_Input(game_state);
    }
}


SIG bool Play_Game(Game_State* game_state)
{
    Reset_Game_State(game_state);
    
    Print("New game of DUNGEON HD!");
    Create_Player_Charater(game_state);        


    while(game_state->running)
    {
        /* GAME LOOP */
        game_state->round += 1;
        if(game_state->next_room)
        {
            Proceed_To_Next_Room(game_state);
        }

        Clear(&game_state->scratch_buffer, Zero_Memory::no);
        Flush_Messages(game_state);

        Prepare_Game_Round(game_state);
        Excecute_Game_Round(game_state);
        /*-----------*/
        
        Exit_Handling(game_state);
    }
    
    return game_state->restart;
}


SIG void Reset_Game_State(Game_State* game_state)
{
    // NOTE: take a snapshot of the arenas to not lose pointers.
    Arena perm_snapshot = game_state->permanent_storage;
    Arena scratch_snapshot = game_state->scratch_buffer;
    Arena messages_snapshot = game_state->messages_buffer;
    
    s32 seed_snap_shot = game_state->initial_seed;
    
    *game_state = {}; // <- just clear everything back to zero, ok.
    
    Clear(&perm_snapshot, Zero_Memory::yes);
    Clear(&scratch_snapshot, Zero_Memory::yes);
    Clear(&messages_snapshot, Zero_Memory::yes);
    
    // CONSIDER: Hmmm... not sure about this.
    // Pointer to the game_state remains valid as it's always the first thing pushed on to the permanent storage.
    Game_State* state = Push_Struct(&perm_snapshot, Game_State);
    Assert(state == game_state);
    
    // --------
    game_state->permanent_storage = perm_snapshot;
    game_state->messages_buffer = messages_snapshot;
    game_state->scratch_buffer = scratch_snapshot;

    game_state->initial_seed = seed_snap_shot;
    game_state->random_state = seed_snap_shot;
    // --------

    String_Table* string_table_address = Push_Struct(&game_state->permanent_storage, String_Table);
    game_state->string_table.table_offset = Storage_Offset(string_table_address, game_state);
    game_state->executable_base_address = (char*)OS_Get_Executable_Base_Address();

    #if ENABLE_WAIT
    game_state->enable_dramatic_pausing = true;
    #endif

    Get_Output_Color_CSTR(&game_state->default_color,    204, 204, 204);
    Get_Output_Color_CSTR(&game_state->ally_color,         0, 200, 100);
    Get_Output_Color_CSTR(&game_state->enemy_color,      230,  70,  70);
    Get_Output_Color_CSTR(&game_state->damage_color,     180,  40,  40);
    Get_Output_Color_CSTR(&game_state->temp_health_color,255,   0, 255);
    Get_Output_Color_CSTR(&game_state->exp_color,        110, 110, 255);

    game_state->rarity_colors[Rarity::common] = game_state->default_color;
    Get_Output_Color_CSTR(&game_state->rarity_colors[Rarity::rare],          80, 140,  80);
    Get_Output_Color_CSTR(&game_state->rarity_colors[Rarity::magical],       80,  80, 230);
    Get_Output_Color_CSTR(&game_state->rarity_colors[Rarity::epic],         163,  73, 164);
    Get_Output_Color_CSTR(&game_state->rarity_colors[Rarity::legendary],    240, 100,  20);

    game_state->next_room = true;
    game_state->running = true;
}


SIG Game_State* Create_Game_State()
{
    Arena permanent_storage = Create_Arena();

    Game_State* game_state = Push_Struct(&permanent_storage, Game_State);
    game_state->permanent_storage = permanent_storage;

    Initialize_Arena(&game_state->scratch_buffer);
    Initialize_Arena(&game_state->messages_buffer);

    game_state->initial_seed = 
    #if RANDOM_SEED
    (u32)OS_Time();
    #else
    SEED;
    #endif

    return game_state;
}


s32 main(s32 argc, char** argv)
{
    Game_State* game_state = Create_Game_State();
    
    while(Play_Game(game_state));
    
    return 0;
}


SIG CMD_Result::T Kill_Command(Entity* actor, String args, Game_State* game_state)
{
    Entity* target = Find_Entity_By_Name_Or_Reference_Number(actor, actor->residence, args, game_state);
    
    CMD_Result::T result = CMD_Result::invalid_args;

    if(target)
    {
        if(Is_Alive(target))
        {
            result = CMD_Result::success;
            Flush_Messages(game_state);
            Deal_Damage(target, actor, STR("Kill Command"), target->_health, 0, Damage_Type::magical, game_state, Verbose::yes);
            Print_Messages(game_state);
        }
        else
        {
            Print("\nTarget needs to be a living entity.");
            result = CMD_Result::abort;
        }
    }

    return result;
}



SIG CMD_Result::T Toggle_Dramatic_Pause(Entity* actor, String args, Game_State* game_state)
{
    CMD_Result::T result = CMD_Result::success;
    if(!args.length)
    {
        game_state->enable_dramatic_pausing = !game_state->enable_dramatic_pausing;
        if(game_state->enable_dramatic_pausing)
        {
            Print("\nDramatic pause enabled.");
        }
        else
        {
            Print("\nDramatic pause disabled.");
        }
    }
    else
    {
        result = CMD_Result::invalid_args;
    }

    return result;
}


SIG CMD_Result::T Toggle_Godmode(Entity* actor, String args, Game_State* game_state)
{
    Entity* player = Dereference(&game_state->player, game_state);
    player->flags ^= EFlags::godmode;
    if(player->flags & EFlags::godmode)
    {
        Print("\nGodmode is enabled.");
    }
    else
    {
        Print("\nGodmode is disabled.");
    }
    
    Full_Heal(player, game_state);

    return CMD_Result::success;
}


SIG CMD_Result::T Help_Command(Entity* entity, String args, Game_State* game_state)
{
    CMD_Result::T result = CMD_Result::invalid_args;
    
    if(!args.length)
    {
        result = CMD_Result::success;
        
        Print("\nUse \"help\" followed by command name for a detailed description.\nAvailable commands:");
        
        Game_Command* first = Player_Actions;
        Game_Command* last = first + Array_Length(Player_Actions);
        
        for(Game_Command* cmd = first; cmd < last; ++cmd)
        {
            Print("\n| %s", cmd->name.ptr);
        }
    }
    else
    {
        Game_Command* first = Player_Actions;
        Game_Command* last = first + Array_Length(Player_Actions);
        
        for(Game_Command* cmd = first; cmd < last; ++cmd)
        {
            if(Match_Case_Insensitive(args, cmd->name))
            {
                result = CMD_Result::success;
                char* action_name = Action_Name(cmd->action_type);
                
                Print("\n[%s]\nAction type: %s\nDescription: %s\nArguments: %s", cmd->name.ptr, action_name, cmd->description, cmd->arguments);
                break;
            }
        }
    }
    
    return result;
}


SIG CMD_Result::T Attacks_Command(Entity* entity, String args, Game_State* game_state)
{
    CMD_Result::T result = CMD_Result::invalid_args;
    
    if(!args.length)
    {
        result = CMD_Result::success;
        
        Print("\nTo use an attack modifier, type the modfier name after the attack command, but before the target name or reference number.");
        Print("\nUse \"attacks\" followed by command name for a detailed description.");
        
        if(entity->known_attack_modifiers)
        {
            Print("\nAvailable modifiers:");
            
            for(u64 i = 1; i < Attack_Mod::COUNT; ++i)
            {
                Attack_Mod::T mod = Attack_Mod::T(i);
                if(Can_Use_Attack_Modifier(entity, mod))
                {
                    Print("\n| %s", Attack_Mod::name[i].ptr);
                }
            }
        }
        else
        {
            Print("\nYou don't know any attack modifiers.");
        }
    }
    else
    {
        for(u64 i = 1; i < Attack_Mod::COUNT; ++i)
        {
            if(Match_Case_Insensitive(args, Attack_Mod::name[i]))
            {
                Attack_Mod::T mod = Attack_Mod::T(i);

                if(Can_Use_Attack_Modifier(entity, mod))
                {
                    result = CMD_Result::success;
                    Entity* null = 0;
                    Print("[%s] \n| ", Attack_Mod::name[i].ptr);
                    Apply_Or_Describe_Attak_Modifier(&null, &null, mod, game_state);
                    break;
                }
            }
        }
    }
    
    return result;
}


SIG CMD_Result::T Pickup_Command(Entity* actor, String args, Game_State* game_state)
{
    CMD_Result::T result = CMD_Result::success;
    
    Entity* target = Find_Entity_By_Name_Or_Reference_Number(actor, actor->residence, args, game_state);
    
    if(target)
    {
        String target_name = Name(target, game_state);

        s64 carrying_amount = Carrying_Amount(actor, game_state);
        s64 carry_capacity = Carry_Capacity(actor, game_state);
        
        s16 target_weight = target->weight;
        
        if(Is_Alive(target) && !target->stunned && !(actor->flags & EFlags::godmode))
        {
            Print("\nYou try to pickup %s but its alive!!!\n%s gets a free attack against you: ", target_name.ptr, target_name.ptr);
            Attack(target, actor, game_state);
        }
        else
        {
            if(carrying_amount + target_weight > carry_capacity)
            {
                Print
                (
                    "\nYou try to pickup %s but its too heavy. (Carrying: [%lld/%lld] > Object weight: %d)", 
                    target_name.ptr,
                    carrying_amount,
                    carry_capacity,
                    target_weight
                );
            }
            else
            {
                Print("\nYou pickup %s. (Now carrying: [%lld/%lld])", target_name.ptr, carrying_amount + target_weight, carry_capacity);
                Deep_Insert(target, actor, game_state);
            }
        }
    }
    else
    {
        result = CMD_Result::invalid_args;
    }

    return result;
}


SIG CMD_Result::T Inventory_Command(Entity* actor, String args, Game_State* game_state)
{
    CMD_Result::T result = CMD_Result::success;
    
    if(args.length == 0)
    {
        Entity_Iterator iter = Make_Iterator(&actor->inventory, game_state);
        if(iter.count)
        {
            s16 heaviest_item_weight;
            u64 total_count;
            s32 longest_item_name = (s32)Longest_Entity_Name_In_Actor_Inventory(actor, game_state, &total_count, &heaviest_item_weight);
            s32 count_digit_count = s32(Digits(s32(total_count)));
            s32 weight_digit_count = Digits(heaviest_item_weight);

            u64 count = 0;
            s32 carrying_amount = Carrying_Amount(actor, game_state);
            s32 carry_capacity = Carry_Capacity(actor, game_state);
            Print("\nYour inventory [%d/%d] contains:", carrying_amount, carry_capacity);
            while(Entity* entity = Next_Entity(&iter))
            {
                count += 1;
                Print
                (
                    "\n| %s %-*llu %s%-*s%s [Weight: %*d]", 
                    (Is_Equipped(actor, entity, game_state))? "*" : "-", 
                    count_digit_count,
                    count, 
                    Entity_Color(entity, game_state),
                    longest_item_name,
                    Name(entity, game_state).ptr, 
                    game_state->default_color.data,
                    weight_digit_count,
                    entity->weight
                );
                

                if(entity->_health <= 0)
                {
                    if(Is_Item(entity))
                    {
                        Print(" [BROKEN]");
                    }
                    
                    if(entity->flags & EFlags::actor)
                    {
                        Print(" [DEAD]");
                    }
                }

                if(entity->interactable.uses_count || (entity->flags & EFlags::interactable))
                {
                    Print(" [");
                    Print_Uses(entity);
                    Print("]");
                }

                if(entity->flags & EFlags::equippable)
                {
                    Print(" [Slots: ");
                    Print_Required_Equipment_Slots(entity);
                    Print("]");
                }
            }
        }
        else
        {
            Print("\nYou inventory is empty.");
        }
    }
    else
    {
        result = CMD_Result::invalid_args;
    }
    
    return result;
}


SIG CMD_Result::T Proceed_Command(Entity* actor, String args, Game_State* game_state)
{
    CMD_Result::T result = CMD_Result::success;
    
    if(args.length == 0)
    {
        Entity* room = Dereference(actor->residence, game_state);
        if(room)
        {
            struct Catch_Attempt
            {
                Roll_Result roll;
                Entity* entity;
            };

            bool success = true;
            
            Arena_Snapshot snapshot = Snapshot(&game_state->scratch_buffer);
            Catch_Attempt* catch_attempts = (Catch_Attempt*)Push(&game_state->scratch_buffer, 0);
            u64 count = 0;
            
            Roll_Result flee_roll = Stat_Roll(actor, Stats::speed, game_state);

            Entity_Iterator iter = Make_Iterator(room, game_state);
            while(Entity* entity = Next_Entity(&iter))
            {
                if(Is_Living_Enemy_Of(entity, actor))
                {
                    Roll_Result catch_roll = Stat_Roll(entity, Stats::speed, game_state);
                    *Push_Struct(&game_state->scratch_buffer, Catch_Attempt) = {catch_roll, entity};
                    count += 1;
                    
                    if(Value(catch_roll) > Value(flee_roll))
                    {
                        success = false;
                    }
                }
            }

            if(count)
            {
                String actor_name = Name(actor, game_state);

                for(u64 i = 0; i < count; ++i)
                {
                    Catch_Attempt attempt = catch_attempts[i];

                    Wait(1, game_state);

                    if(Value(attempt.roll) > Value(flee_roll))
                    {
                        Print("\n%s stops %s from escaping: ", Name(attempt.entity, game_state).ptr, actor_name.ptr);
                    }
                    else
                    {
                        Print("\n%s evaides %s successully: ", actor_name.ptr, Name(attempt.entity, game_state).ptr);
                    }

                    Print_Roll_Result(flee_roll);
                    Print(" VS ");
                    Print_Roll_Result(catch_attempts[i].roll);
                }

                if(success)
                {
                    Print("\nYou manage to escape!");
                }
                else
                {
                    Print("\nYou are prevented from proceeding.");
                }
            }
            
            Wait(1, game_state);
            if(success || (actor->flags & EFlags::godmode))
            {
                Print("\nProceeding...\n");
                game_state->next_room = true;
            }

            Restore(&game_state->scratch_buffer, snapshot);
        }
        else
        {
            Assert(0);
            game_state->internal_error = true;
        }
    }
    else
    {
        result = CMD_Result::invalid_args;
    }
    
    return result;
}


SIG CMD_Result::T Equipment_Command(Entity* actor, String args, Game_State* game_state)
{
    CMD_Result::T result = CMD_Result::success;
    
    if(args.length == 0)
    {
        Print("Equipped items:");
        u64 longest_equipment_slot_name_length = 0;
        for(u64 i = 0; i < Equipment_Slots::COUNT; ++i)
        {
            longest_equipment_slot_name_length = Max(longest_equipment_slot_name_length, Equipment_Slots::name[i].length);
        }

        for(u64 i = 0; i < Equipment_Slots::COUNT; ++i)
        {
            Print("\n| %*s:", s32(longest_equipment_slot_name_length), Equipment_Slots::name[i].ptr);
            if(Entity* entity = Dereference(actor->equipment + i, game_state))
            {
                Print(" %s", Colored_Name(entity, game_state).ptr);
            }
            else
            {
                Print(" [EMPTY]");
            }
        }
    }
    else
    {
        result = CMD_Result::invalid_args;
    }
    
    return result;
}


SIG CMD_Result::T Drop_Command(Entity* actor, String args, Game_State* game_state)
{
    CMD_Result::T result = CMD_Result::success;
    
    Entity* target = Find_Entity_By_Name_Or_Reference_Number(actor, actor, args, game_state);
    
    if(target)
    {
        String target_name = Name(target, game_state);

        if(Unequip(actor, target, game_state))
        {
            Print("\n%s unequiped.", target_name.ptr);
        }
        
        if(Entity* room = Dereference(actor->residence, game_state))
        {
            Deep_Insert(target, room, game_state);
        }
        Print("\n%s dropped.", target_name.ptr);
    }
    else
    {
        result = CMD_Result::invalid_args;
    }
    
    return result;
}


SIG CMD_Result::T Use_Command(Entity* actor, String args, Game_State* game_state)
{
    CMD_Result::T result = CMD_Result::success;

    Entity* target = Find_Entity_By_Name_Or_Reference_Number(actor, actor, args, game_state);
    
    if(target)
    {
        String target_name = Name(target, game_state);
        Print("\nYou attempt to use %s.", target_name.ptr);
        if(!Use(actor, target, game_state, Verbose::yes))
        {
            Print("\nAttempt failed.");
        }
    }
    else
    {
        result = CMD_Result::invalid_args;
    }

    return result;
}


SIG CMD_Result::T Equip_Command(Entity* actor, String args, Game_State* game_state)
{
    CMD_Result::T result = CMD_Result::success;
    
    Entity* target = Find_Entity_By_Name_Or_Reference_Number(actor, actor, args, game_state);
    
    if(target)
    {
        String target_name = Name(target, game_state);
        if(!Equip(actor, target, game_state, Verbose::yes))
        {
            result = CMD_Result::abort;
        }
    }
    else
    {
        result = CMD_Result::invalid_args;
    }
    
    return result;
}


SIG CMD_Result::T Unequip_Command(Entity* actor, String args, Game_State* game_state)
{
    CMD_Result::T result = CMD_Result::success;
    
    Entity* target = Find_Entity_By_Name_Or_Reference_Number(actor, actor, args, game_state);
    
    if(target)
    {
        String target_name = Name(target, game_state);

        if(Unequip(actor, target, game_state))
        {
            Print("\n%s unequipped.", target_name.ptr);
        }
        else
        {
            result = CMD_Result::abort;
            Print("\n%s is not equipped...", target_name.ptr);
        }
    }
    else
    {
        result = CMD_Result::invalid_args;
    }
    
    return result;
}


SIG CMD_Result::T Stats_Command(Entity* actor, String args, Game_State* game_state)
{
    CMD_Result::T result = CMD_Result::success;
    
    if(args.length == 0)
    {
        Critical_Ranges_Result cr_base = Critical_Ranges(0, 0);
        u32 success_effecting_count;
        u32 failure_effecting_count;
        Critical_Ranges_Result cr = Critical_Ranges(actor, game_state, &success_effecting_count, &failure_effecting_count);

        String crit_range_name = STR("crit range");
        String fumple_range_name = STR("fumple range");
        
        Print("\nStats are:");
        u64 longest_stat_name_length = 0;
        s32 largest_stat_value = 0;
        for(u64 i = 0; i < Stats::COUNT; ++i)
        {
            longest_stat_name_length = Max(longest_stat_name_length, Stats::name[i].length);
            largest_stat_value = Max(largest_stat_value, Get_Stat_Value(actor, Stats::T(i), game_state));
        }
        longest_stat_name_length = Max(longest_stat_name_length, crit_range_name.length);
        longest_stat_name_length = Max(longest_stat_name_length, fumple_range_name.length);
        largest_stat_value = Max(largest_stat_value, s32((CRITICAL_DICE_RANGE + 1) - cr.success));
        largest_stat_value = Max(largest_stat_value, s32(cr.failure));

        s32 larget_stat_value_digit_count = Digits(largest_stat_value);
        
        for(u64 i = 0; i < Stats::COUNT; ++i)
        {
            s16 base = actor->_stats[i];
            u64 effect_count;
            s32 total = Get_Stat_Value(actor, Stats::T(i), game_state, &effect_count);
            
            Print("\n| %*s: %*d ", s32(longest_stat_name_length), Stats::name[i].ptr, larget_stat_value_digit_count, total);
            if(effect_count)
            {
                Print("= base: %d", base);
                
                Effects_Iterator iter = Make_Iterator(&actor->active_effects, game_state);
                while(Effect_Instance* instance = Next_Effect_Instance(&iter))
                {
                    s16 mod = Pointer(instance->effect_offset, game_state)->stat_modifiers[i];
                    if(mod)
                    {
                        String src_name = Effect_Name(instance, game_state);
                        
                        Print(" + %d:(%s)", mod, src_name.ptr);
                    }
                }
            }
        }

        Print
        (
            "\n| %*s: %*d ", 
            s32(longest_stat_name_length), 
            crit_range_name.ptr, 
            larget_stat_value_digit_count, 
            (CRITICAL_DICE_RANGE + 1) - cr.success
        );
        
        if(success_effecting_count)
        {
            Print("= base: %d", cr_base.success);

            Effects_Iterator iter = Make_Iterator(&actor->active_effects, game_state);
            while(Effect_Instance* instance = Next_Effect_Instance(&iter))
            {
                s8 mod = Pointer(instance->effect_offset, game_state)->critical_success_range;
                if(mod)
                {
                    String src_name = Effect_Name(instance, game_state);
                    
                    Print(" + %d:(%s)", mod, src_name.ptr);
                }
            }
        }

        Print
        (
            "\n| %*s: %*d ",
            s32(longest_stat_name_length),
            fumple_range_name.ptr,
            larget_stat_value_digit_count,
            cr.failure
        );
        
        if(failure_effecting_count)
        {
            Print("= base: %d", cr_base.failure);

            Effects_Iterator iter = Make_Iterator(&actor->active_effects, game_state);
            while(Effect_Instance* instance = Next_Effect_Instance(&iter))
            {
                s8 mod = Pointer(instance->effect_offset, game_state)->critical_failure_range;
                if(mod)
                {
                    String src_name = Effect_Name(instance, game_state);
                    
                    Print(" + %d:(%s)", mod, src_name.ptr);
                }
            }
        }
    }
    else
    {
        result = CMD_Result::invalid_args;
    }
    
    return result;
}


SIG CMD_Result::T Status_Command(Entity* actor, String args, Game_State* game_state)
{
    CMD_Result::T result = CMD_Result::success;
    
    if(args.length == 0)
    {
        Print("\nLevel: %d", Level(actor));
        Print("\nHealth: [%d/%d]", actor->_health, Max_Health(actor, game_state));
        Print("\nCarrying: [%d/%d]", Carrying_Amount(actor, game_state), Carry_Capacity(actor, game_state));
        Print("\nExperience: [%d/%d]", actor->exp, Exp_To_Level_Up(actor));
        if(actor->exp >= Exp_To_Level_Up(actor))
        {
            Print(" - You have sufficent experience to level up! Rest to manifest your new found powers.");
        }

        bool first = true;
        
        Effects_Iterator iter = Make_Iterator(&actor->active_effects, game_state);
        while(Effect_Instance* instance = Next(&iter))
        {
            Effect* effect = Pointer(instance->effect_offset, game_state);

            if(effect->type)
            {
                if(first)
                {
                    Print("\nActive Effects:");
                    first = false;
                }

                Print("\n[%s]", Effect_Name(instance, game_state).ptr);
                if(instance->duration == UNLIMITED_DURATION)
                {
                    Print("\n| Duration: Unlimited.");
                }
                else
                {
                    char* format_string = (instance->duration == 1)? "\n| Duration: %llu %s." : "\n| Duration: %llu %ss.";
                    Print(format_string, instance->duration, duration_type_names[u32(instance->duration_type)].ptr);
                }

                Describe_Effect(effect, 1, game_state);
            }
        }
    }
    else
    {
        result = CMD_Result::invalid_args;
    }
    
    return result;
}


SIG CMD_Result::T Inspect_Command(Entity* actor, String args, Game_State* game_state)
{
    CMD_Result::T result = CMD_Result::abort;

    Entity* space = Dereference(actor->residence, game_state);
    
    String inv = STR("inventory");
    
    if(Match_Beginning_Case_Insensitive(args, inv))
    {
        Print("Looking from the inventory.\n");
        
        args = Forward(args, inv.length);
        args = Skip_Whitespace(args);
        
        space = actor;
    }
    

    if(space)
    {
        
        if(Entity* target = Find_Entity_By_Name_Or_Reference_Number(actor, space, args, game_state))
        {
            result = CMD_Result::success;
            Inspect(target, game_state);
        }
        else
        {
            result = CMD_Result::invalid_args;
            Print("The inspect command requires a name of the target (or a reference number) to be passed as an argument.\n"); 
        }    
    }
    else
    {
        Assert(0);
    }

    return result;
}


SIG CMD_Result::T Pass_Command(Entity* actor, String args, Game_State* game_state)
{
    CMD_Result::T result = CMD_Result::success;
    if(args.length == 0)
    {
        Print("\nYou pass your turn.");
    }
    else
    {
        result = CMD_Result::invalid_args;
    }
    
    return result;
}


SIG CMD_Result::T Glance_Command(Entity* actor, String args, Game_State* game_state)
{
    Assert(actor);
    
    CMD_Result::T result = CMD_Result::success;
    
    if(args.length == 0)
    {
        if(!Glance(actor, game_state))
        {
            Print("\nYou glance around the room... ");
            Wait(1, game_state);
            Print("but nothing catches your eye.");
        }
    }
    else
    {
        result = CMD_Result::invalid_args;
    }

    return result;
}


SIG CMD_Result::T Restart_Command(Entity* actor, String args, Game_State* game_state)
{
    CMD_Result::T result = CMD_Result::success;
    
    bool restart = false;

    if(args.length == 0)
    {
        Print("\nAre you sure you want to restart game?");
        restart = User_Query_Yes_No(game_state);
        if(!restart)
        {
            result = CMD_Result::abort;
        }
    }
    else if(Match_Case_Sensitive(args, STR("!")))
    {
        restart = true;
    }
    else
    {
        result = CMD_Result::invalid_args;        
    }

    if(restart)
    {
        Print("\nRestarting game...");
        game_state->restart = true;
        game_state->running = false;
    }
    
    return result;
}


SIG CMD_Result::T Save_Command(Entity* actor, String args, Game_State* game_state)
{
    CMD_Result::T result = CMD_Result::success;
    
    if(args.length == 0)
    {
        String path = STR("dungeon.data");
        if(Memory_Snapshot_Save(path, game_state))
        {
            Print("Game was successully saved!");
        }
        else
        {
            Print("Failed to save the game...\n");
            result = CMD_Result::abort;
        }
    }
    else
    {
        result = CMD_Result::invalid_args;
    }
    
    return result;
}


SIG CMD_Result::T Load_Command(Entity* actor, String args, Game_State* game_state)
{
    CMD_Result::T result = CMD_Result::success;
    
    if(args.length == 0)
    {
        String path = STR("dungeon.data");
        if(Memory_Snapshot_Restore(path, game_state))
        {
            Print("Game was successully loaded!");
        }
        else
        {
            Print("Failed to save the game...\n");
            result = CMD_Result::abort;
        }
    }
    else
    {
        result = CMD_Result::invalid_args;
    }
    
    return result;
}


SIG CMD_Result::T Exit_Command(Entity* actor, String args, Game_State* game_state)
{
    CMD_Result::T result = CMD_Result::success;
    
    bool exit = false;

    if(args.length == 0)
    {
        Print("\nAre you sure you want to exit game?");
        exit = User_Query_Yes_No(game_state);
        if(!exit)
        {
            result = CMD_Result::abort;
        }
    }
    else if(Match_Case_Sensitive(args, STR("!")))
    {
        exit = true;
    }
    else
    {
        result = CMD_Result::invalid_args;        
    }

    if(exit)
    {
        #if SAVE_ON_EXIT
        Memory_Snapshot_Save(STR("Dungeon.data"), game_state);
        #endif

        Print("Exiting game...\n");
        game_state->running = false;
    }
    
    return result;
}


SIG CMD_Result::T Loot_Command(Entity* actor, String args, Game_State* game_state)
{
    CMD_Result::T result = CMD_Result::success;
    
    Entity* target = Find_Entity_By_Name_Or_Reference_Number(actor, actor->residence, args, game_state);
    if(target)
    {
        String target_name = Name(target, game_state);

        if(target->flags & EFlags::container)
        {
            if(Has_Content(&target->inventory))
            {
                Print("\nYou open %s. It contains:", target_name.ptr);
                Open(target, game_state);
            }
            else
            {
                Print("\nYou open %s. It's empty.", target_name.ptr);
            }
        }
        else if(target->flags & EFlags::actor)
        {
            if(target->_health > 0)
            {
                Print("\n%s is alive and doens't take kindly to beeing looted.\n%s gets a free attack against you: ", target_name.ptr, target_name.ptr);
                Attack(target, actor, game_state);
            }
            else
            {
                if(Has_Content(&target->inventory))
                {
                    Print("\nYou loot %s. It contains:", target_name.ptr);
                    Open(target, game_state);
                }
                else
                {
                    Print("\nYou loot %s, but It's empty.", target_name.ptr);
                }
            }
        }
        else
        {
            Print("\n%s is not a container.", target_name.ptr);
            result = CMD_Result::abort;
        }
    }
    else
    {
       result = CMD_Result::invalid_args;
    }
    
    return result;
}


SIG CMD_Result::T Attack_Command(Entity* actor, String args, Game_State* game_state)
{
    CMD_Result::T result = CMD_Result::success;
    
    Attack_Mod::T modifier = Attack_Mod::standard;

    String args_copy = args;

    for(u64 i = 0; i < Attack_Mod::COUNT; ++i)
    {
        String attack_modifier_name = Attack_Mod::name[i];
        if(Match_Beginning_Case_Insensitive(args, attack_modifier_name))
        {
            modifier = Attack_Mod::T(i);
            
            args = Forward(args, attack_modifier_name);
            args = Skip_Whitespace(args);
            break;
        }
    }

    RETRY:
    Entity* target = Find_Entity_By_Name_Or_Reference_Number(actor, actor->residence, args, game_state, Verbose::no);

    if(target)
    {
        if(Can_Use_Attack_Modifier(actor, modifier))
        {
            Attack(actor, target, game_state, modifier);
        }
        else
        {
            String actor_name = Name(actor, game_state);
            Print("\n%s can't use the attack modifier: %s.", actor_name.ptr, Attack_Mod::name[modifier].ptr);
            result = CMD_Result::abort;
        }
    }
    else
    {
        if(modifier == Attack_Mod::standard)
        {
            // NOTE: Calling this again (or I suppose maybe for the third time?) just to now finally output the failure message.
            Find_Entity_By_Name_Or_Reference_Number(actor, actor->residence, args, game_state, Verbose::yes);
            
            Print("\nThe attack command requires a name of the target (or a reference number) to be passed as an argument."); 
            result = CMD_Result::invalid_args;
        }
        else
        {
            // NOTE: Attempt again without the attack modifier. This is incase there are objects with the same name as the attack modifier.
            // \o/ 
            //  |  
            // / \ 
            modifier = Attack_Mod::standard;
            args = args_copy;
            goto RETRY;
        }
    }

    return result;
}


SIG CMD_Result::T Set_Seed_Command(Entity* actor, String args, Game_State* game_state)
{
    CMD_Result::T result = CMD_Result::success;
    
    u32 new_seed = 0;
    u32* seed = 0;

    String seed_string = Skip_Zeroes(args);
    if(seed_string.length && Is_Positive_Integer(seed_string))
    {
        new_seed = (u32)To_U64(seed_string);
        seed = &new_seed;
    }
    
    if(seed)
    {
        game_state->random_state = *seed;
        game_state->initial_seed = *seed;
        Print("\nRandom Seed is set to: %d", game_state->random_state);
    }
    else
    {
        Print("\nThe set seed command requires a positive number as the argument.");
        result = CMD_Result::invalid_args;
    }

    return result;
}


SIG void Get_Character_Creator_Commands(Game_State* game_state, Command** out_commands, u64* out_count)
{
    struct local
    {
        static void Self_Describe(String name, String description, String args)
        {
            Print("[%s]", name.ptr);
            Print("\nDescription: %s", description.ptr);
            Print("\nArguments: %s", args.ptr);
        }

        static bool Find_By_Refnum_Or_Name(u64* out_idx, String args, Character_Creator* cc)
        {
            bool found = false;
            if(Is_Positive_Integer(Skip_Zeroes(args)))
            {
                u64 refnum = To_U64(args);
                Assert(refnum);
                if(refnum - 1 < cc->template_count)
                {
                    found = true;
                    *out_idx = refnum - 1;
                }
                else
                {
                    Print("\n%llu is not a valid reference number", refnum);
                }
            }
            else
            {
                for(u64 i = 0; i < cc->template_count; ++i)
                {
                    if(Match_Case_Insensitive(args, Name(cc->class_templates[i], cc->game_state)))
                    {
                        found = true;
                        *out_idx = i;
                        break;
                    }
                }

                if(!found)
                {
                    Print("\n%s is not a valid reference number or an available class name.", args.ptr);
                }
            }

            return found;
        }


        static CMD_Result::T list(Call_Style ccs, void* user_ptr, String args)
        {
            CMD_Result::T result = CMD_Result::abort;
            String cmd_name = STR(__func__);

            switch(ccs)
            {
                case Call_Style::name:
                {
                    *(String*)user_ptr = cmd_name;
                }break;

                case Call_Style::describe:
                {
                    char description[] = 
                    "Lists all available classes. Prefixed by a reference number used to select the class without having to type the full name.";

                    char arguments[] = 
                    "Takes no arguments.";
                    
                    String name;
                    list(Call_Style::name, &name, {});
                    Self_Describe(name, STR(description), STR(arguments));
                }break;

                case Call_Style::execute:
                {
                    if(args.length == 0)
                    {
                        result = CMD_Result::success;

                        Character_Creator* cc = (Character_Creator*)user_ptr;
                        u64 refnum = 0;

                        Print("\nAvailable classes:");
                        for(u64 i = 0; i < cc->template_count; ++i)
                        {
                            refnum += 1;
                            Wait(1, cc->game_state);
                            Entity* e = cc->class_templates[i];
                            Print("\n|\t%llu - %s", refnum, Name(e, cc->game_state).ptr);    
                        }
                    }
                    else
                    {
                        result = CMD_Result::invalid_args;
                    }
                }break;
            }

            return result;
        }

        static CMD_Result::T select(Call_Style ccs, void* user_ptr, String args)
        {
            CMD_Result::T result = CMD_Result::abort;
            String cmd_name = STR(__func__);

            switch(ccs)
            {
                case Call_Style::name:
                {
                    *(String*)user_ptr = cmd_name;
                }break;

                case Call_Style::describe:
                {
                    char description[] = 
                    "Start the game with the class used as the argument.";

                    char arguments[] =  
                    "Name of an available class or the reference number associated with that class. Use the \"list\" command to see the numbers.";

                    Self_Describe(cmd_name, STR(description), STR(arguments));
                }break;

                case Call_Style::execute:
                {
                    Character_Creator* cc = (Character_Creator*)user_ptr;
                    
                    u64 idx = 0;
                    if(Find_By_Refnum_Or_Name(&idx, args, cc))
                    {
                        Print("Starting game as the %s!", Name(cc->class_templates[idx], cc->game_state).ptr);
                        cc->selected_idx = idx;
                        cc->running = false;

                        result = CMD_Result::success;
                    }
                    else
                    {
                        result = CMD_Result::invalid_args;
                    }
                }break;
            }

            return result;
        }

        static CMD_Result::T inspect(Call_Style ccs, void* user_ptr, String args)
        {
            CMD_Result::T result = CMD_Result::abort;
            String cmd_name = STR(__func__);

            switch(ccs)
            {
                case Call_Style::name:
                {
                    *(String*)user_ptr = cmd_name;
                }break;

                case Call_Style::describe:
                {
                    char description[] = 
                    "Get more information about a starting equipment item on the class last used as the target of the \"describe\" command.";

                    char arguments[] = 
                    "Name of an item (or a reference number) listed in the starting equipment section of the \"desctibe\" command.";

                    Self_Describe(cmd_name, STR(description), STR(arguments));
                }break;

                case Call_Style::execute:
                {
                    Character_Creator* cc = (Character_Creator*)user_ptr;

                    Assert(cc->selected_idx < cc->template_count);
                    Entity* e = cc->class_templates[cc->selected_idx];
                    Entity* item = Find_Entity_By_Name_Or_Reference_Number(0, e, args, cc->game_state, Verbose::yes);
                    if(item)
                    {
                        result = CMD_Result::success;
                        Inspect(item, cc->game_state);
                    }
                    else
                    {
                        result = CMD_Result::invalid_args;
                    }

                }break;
            }

            return result;
        }

        static CMD_Result::T describe(Call_Style ccs, void* user_ptr, String args)
        {
            CMD_Result::T result = CMD_Result::abort;
            String cmd_name = STR(__func__);

            switch(ccs)
            {
                case Call_Style::name:
                {
                    *(String*)user_ptr = cmd_name;
                }break;

                case Call_Style::describe:
                {
                    char description[] = 
                    "Gives a full description of the class provided as the argument.";

                    char arguments[] = 
                    "Name of an available class or the reference number associated with that class. Use the \"list\" command to see the numbers.";

                    Self_Describe(cmd_name, STR(description), STR(arguments));
                }break;

                case Call_Style::execute:
                {
                    Character_Creator* cc = (Character_Creator*)user_ptr;

                    u64 idx = 0;
                    if(Find_By_Refnum_Or_Name(&idx, args, cc))
                    {
                        cc->selected_idx = idx;
                        result = CMD_Result::success;
                        
                        Entity* e = cc->class_templates[idx];

                        Print("[%s]", Name(e, cc->game_state).ptr);
                        Print("\nDescription: %s", Get_String(e->description_offset, cc->game_state).ptr);
                        Print("\nLevel: %d", Level(e));
                        Print("\nStats:");
                        for(u64 j = 0; j < Stats::COUNT - 1; ++j)
                        {
                            Print("\n|%11s: %d", Stats::name[j].ptr, e->_stats[j]);
                        }
                        if(e->known_attack_modifiers)
                        {
                            Print("\n\nAttack modifiers:");
                            for(u64 j = 1; j < Attack_Mod::COUNT; ++j)
                            {
                                if(Can_Use_Attack_Modifier(e, Attack_Mod::T(j)))
                                {
                                    Print("\n| %s", Attack_Mod::name[j].ptr);
                                }
                            }
                        }

                        if(e->inventory.node_offset.v)
                        {
                            Print("\n\nEquipment:");
                            u64 refnum = 0;
                            Entity_Iterator iter = Make_Iterator(e, cc->game_state);
                            while(Entity* item = Next_Entity(&iter))
                            {
                                refnum += 1;
                                Print("\n| %llu - %s", refnum, Name(item, cc->game_state).ptr);
                            }
                        }
                    }
                    else
                    {
                        result = CMD_Result::invalid_args;
                    }

                }break;
            }
            
            return result;
        }

        static CMD_Result::T exit(Call_Style ccs, void* user_ptr, String args)
        {
            CMD_Result::T result = CMD_Result::abort;
            String cmd_name = STR(__func__);

            switch(ccs)
            {
                case Call_Style::name:
                {
                    *(String*)user_ptr = cmd_name;
                }break;

                case Call_Style::describe:
                {
                    char description[] = 
                    "Quits the game.";

                    char arguments[] = 
                    "No arguments or \"!\" to skip the confirmation step.";

                    Self_Describe(cmd_name, STR(description), STR(arguments));
                }break;

                case Call_Style::execute:
                {
                    Character_Creator* cc = (Character_Creator*)user_ptr;

                    if(args.length == 0)
                    {
                        Print("\nAre you sure you want to quit the game? You haven't even played it yet! :");
                        if(User_Query_Yes_No(cc->game_state))
                        {
                            result = CMD_Result::success;
                        }
                        else
                        {
                            result = CMD_Result::abort;
                        }
                    }
                    else if(Match_Case_Sensitive(args, STR("!")))
                    {
                        result = CMD_Result::success;
                    }
                    else
                    {
                        result = CMD_Result::invalid_args;
                    }

                    if(result == CMD_Result::success)
                    {
                        cc->game_state->running = false;
                        cc->running = false;
                    }
                }break;
            }
            
            return result;
        }
    };

    Command commands[] = 
    {
        local::list,
        local::describe,
        local::select,
        local::inspect,
        local::exit,
    };

    *out_commands = Push_Array(&game_state->scratch_buffer, Command, Array_Length(commands));
    Mem_Copy(*out_commands, commands, sizeof(commands));

    *out_count = Array_Length(commands);
}