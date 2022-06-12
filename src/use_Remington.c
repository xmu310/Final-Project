#include"func.h"

void use_Remington(int32_t card_index)
{
	//MEOW MEOW
	
	for(int i=0;i<player[PlayerNow].equip.num;i++)
	{
if(player[PlayerNow].equip.card[i].type==Volcanic||player[PlayerNow].equip.card[i].type==Schofield||player[PlayerNow].equip.card[i].type==Remington||player[PlayerNow].equip.card[i].type==Rev_Carabine||player[PlayerNow].equip.card[i].type==Winchedster)
		{
		get_card(&discard,&player[PlayerNow].equip,i);
		i--;
		}
	
	
	}
	get_card(&player[PlayerNow].equip,&player[PlayerNow].hand,card_index);
	printf("Remigton has been weaponed! >.<\n");


}
