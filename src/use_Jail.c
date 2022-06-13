#include"func.h"
#include<stdlib.h>

void use_Jail(int32_t card_index)
{
	//MEOW MEOW
	//except i & the police are there ?? players
	
	int J_player=0;
	
	for(int i=0;i<PlayerNum;i++)
	{
		if(player[i].iden!=Sheriff&&i!=PlayerNow)
		{
			J_player++;
		}
	}
	if(J_player<=0){printf("JAIL can't be used\n");return;}
	
	int J_who=0;
	if(PlayerNow==PlayerHuman){
		printf("Which player would you send him or her into the jail?\n");
		while(1)
		{
		if(num_scanf(&J_who)&&player[J_who-1].iden!=Sheriff&&J_who-1!=PlayerNow)
			{
			J_who--;
			break;	
			}
			else{printf("JAIL ERROR QAQ\n");}
		}
	}else{
		while(1)
		{
			J_who=rand()%PlayerNum;
		if(player[J_who].iden!=Sheriff&&J_who!=PlayerNow)
			{
			break;	
			}
		}
	}
	get_card(&player[J_who].equip,&player[PlayerNow].hand,card_index);
	
	printf("PLAYER %d WOULD BE in the jail haha !  \n",J_who+1);


}
