#include"func.h"

void use_Appaloosa(int32_t card_index)
{
	//MEOW MEOW
	
	for(int i=0;i<player[PlayerNow].equip.num;i++)
	{
if(player[PlayerNow].equip.card[i].type==Mustang||player[PlayerNow].equip.card[i].type==Appaloosa)
		{
		get_card(&discard,&player[PlayerNow].equip,i);
		i--;
		}
	
	
	}
	get_card(&player[PlayerNow].equip,&player[PlayerNow].hand,card_index);
	printf("Appaloosa has been equipped! o.o\n");




}
