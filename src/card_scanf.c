#include"func.h"
void card_scanf(int32_t player_index,int32_t type,int32_t *card_index){
	if(PlayerNow==PlayerHuman){
		while(1){
			printf("Which card do you want to choose (enter card index): ");
			if((type==0&&num_scanf(card_index,1,player[player_index].hand.num))||
	                   (type==1&&num_scanf(card_index,1,player[player_index].equip.num)))break;
		}
		*card_index-=1;
	}else{
		if(type==0)*card_index=rand()%player[player_index].hand.num;
		if(type==1)*card_index=rand()%player[player_index].equip.num;
	}
}
