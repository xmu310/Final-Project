#include"func.h"

void use_Barrel(int32_t card_index)
{
	//MEOW MEOW //two pieces
	
	for(int i=0;i<player[PlayerNow].equip.num;i++)
	{
if(player[PlayerNow].equip.card[i].type==Barrel)
		{
		printf("You have already equipped the barrel,");
		printf("so you can't equip again! >.<\n");
		return;
		}
	}
	get_card(&player[PlayerNow].equip,&player[PlayerNow].hand,card_index);
	printf("Barrel has been equipped! o.o\n");

}
