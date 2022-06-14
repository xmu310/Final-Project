#include"func.h"
void type_scanf(int32_t player_index,int32_t *type){
	if(PlayerNow==PlayerHuman){
		while(1){
			printf("Which kind do you want to choose (0 for hand card, 1 for equip card): ");
			if(!num_scanf(type,0,1))continue;
			if((*type==0&&player[player_index].hand.num>0)||(*type==1&&player[player_index].equip.num>0))break;
			printf("This player has no card of this kind.\n");
		}
	}else{
		while(1){
			*type=rand()%2;
			if((*type==0&&player[player_index].hand.num>0)||(*type==1&&player[player_index].equip.num>0))break;
		}
	}
}
