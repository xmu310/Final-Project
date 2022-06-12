#include"func.h"

void use_Scope(int32_t card_index)
{
	
	get_card(&player[PlayerNow].equip,&player[PlayerNow].hand,card_index);
	printf("Scope has been equipped! o.o\n");

}
