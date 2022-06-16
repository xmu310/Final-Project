#include"func.h"
#include<stdlib.h>

void use_Jail(int32_t card_index)
{
	//MEOW MEOW
	//except i & the police are there ?? players
	
	int J_player=0;
	
	for(int i=0;i<PlayerNum;i++)
	{
		if(player[i].iden!=Sheriff&&i!=PlayerNow&&player[i].alive)
		{
			J_player++;
		}
	}
	if(J_player<=0){printf("JAIL can't be used\n");return;}
	
	int J_who=0;
	if(PlayerNow==PlayerHuman){
		while(1)
		{
		player_scanf(&J_who);
		if(player[J_who].iden!=Sheriff&&J_who!=PlayerNow)break;	
			else{printf("JAIL ERROR QAQ\n");}
		}
	}else{
		while(1)
		{
			player_scanf(&J_who);
		if(player[J_who].iden!=Sheriff&&J_who!=PlayerNow)
			{
			break;	
			}
		}
	}
	get_card(&player[J_who].equip,&player[PlayerNow].hand,card_index);
	
	printf("PLAYER %d WOULD BE in the jail haha !  \n",J_who+1);


}
