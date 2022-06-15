#include"func.h"
void card_scanf(int32_t player_index,int32_t *type,int32_t *card_index){
	if(PlayerNow==PlayerHuman){
		while(1){
			printf("Which kind do you want to choose (0 for hand card, 1 for equip card): ");
			if(!num_scanf(type,0,1))continue;
			if((*type==0&&player[player_index].hand.num>0)||(*type==1&&player[player_index].equip.num>0))break;
			printf("This player has no card of this kind.\n");
		}
		while(1){
			printf("Which card do you want to choose (enter card index): ");
			if((*type==0&&num_scanf(card_index,1,player[player_index].hand.num))||
	                   (*type==1&&num_scanf(card_index,1,player[player_index].equip.num)))break;
		}
		*card_index-=1;
	}else{
		while(1){
			*type=rand()%2;
			if((*type==0&&player[player_index].hand.num>0)||(*type==1&&player[player_index].equip.num>0))break;
		}
		if(*type==0)*card_index=rand()%player[player_index].hand.num;
		if(*type==1)*card_index=rand()%player[player_index].equip.num;
	}
}
