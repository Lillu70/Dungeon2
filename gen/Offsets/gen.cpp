

// ===================================
// Copyright (c) 2025 by Valtteri Kois
// All rights reserved.
// ===================================

char* banner = 
"\n"
"// ===================================\n"
"// Copyright (c) %d by Valtteri Kois\n"
"// All rights reserved.\n"
"// ===================================\n";

char* warning = 
"\n// --- This is a generated file. Do not edit manually! ---\n\n\n";

char* structure =
"struct %s_Offset\n"
"{\n"
"    u64 v;\n"
"};\n"
"\n";

char* code =
"// ---- %s ----\n"
"SIG _inline %s_Offset Offset(%s* pointer, Game_State* game_state)\n"
"{\n"
"    Assert(game_state->executable_base_address);\n"
"    %s_Offset offset = {};\n"
"    if(pointer)\n"
"    {\n"
"        offset = {u64((char*)pointer - game_state->executable_base_address) + 1};\n"
"    }\n"
"    return offset;\n"
"}\n"
"\n"
"SIG _inline %s* Pointer(%s_Offset offset, Game_State* game_state)\n"
"{\n"
"    %s* pointer = {};\n"
"    if(offset.v)\n"
"    {\n"
"        pointer = (%s*)(game_state->executable_base_address + offset.v - 1);\n"
"    }\n"
"    return pointer;\n"
"}\n"
"// -------- \n\n";

#include <stdio.h>

void gen_code(char* t)
{
	printf(code, t, t, t, t, t, t, t, t);
}

void gen_structure(char* t)
{
	printf(structure, t);
}

int main(int argc, char** argv)
{
	char* types[] = 
	{
		"GENERATE_ENTITY_FN",
		"PROTOTYPE_ENT_GS",
		"PROTOTYPE_ENT_ENT_GS",
		"PROTOTYPE_EFFINST_ENT_GS",
		"PROTOTYPE_EFFINST_ENT_ENT_GS",
		"PROTOTYPE_EFFINST_ENT_ENT_AR_GS",
		"PROTOTYPE_EFFINST_ENTOFF_ENT_DDR_GS",
		"PROTOTYPE_EFFINST_ENT_S32PTR_STR_GS",
		"PROTOTYPE_EFFINST_ENT_STAT_S32PTR_S16PTR_GS",
	};
	
	#define Array_Length(array) (sizeof(array) / sizeof(array[0]))

	if(argc == 1)
	{
		printf(banner, 2025);
		printf(warning);

		for(unsigned long long i = 0; i < Array_Length(types); ++i)
		{
			gen_code(types[i]);
		}
	}
	else
	{
		printf(banner, 2025);
		printf(warning);

		for(unsigned long long i = 0; i < Array_Length(types); ++i)
		{
			gen_structure(types[i]);
		}
	}

}