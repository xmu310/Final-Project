#include"func.h"

void use_Dynamite(int32_t card_index)
{
//MEOW MEOW//onluy one piece
	
	
	get_card(&player[PlayerNow].equip,&player[PlayerNow].hand,card_index);
	print_ascii(aBomb);
	printf("Dynamite has been set! ^.^ \n");
}
