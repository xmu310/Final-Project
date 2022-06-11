#include"func.h"

void use_Sallon(int32_t card_index){
	get_card(&discard,&player[PlayerNow].hand,card_index);
	for(int i=0;i<PlayerNum;i++){
		if(player[i].alive){
			player_plus_blood(i);
		}
	}
}
