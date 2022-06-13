#include"func.h"

void use_Indians(int32_t card_index){
	int32_t num;
	get_card(&discard,&player[PlayerNow].hand,card_index);
	for(int i=0;i<PlayerNum;i++){
		if(player[i].alive&&i!=PlayerNow){
			if(find_card_index(player[i].hand,Bang,&num)){
				get_card(&discard,&player[i].hand,num);
				printf("Player%d discard a \"Bang\"\n",i+1);				
			}else if(player[i].role==Calamity_Janet&&find_card_index(player[i].hand,Missed,&num)){
				get_card(&discard,&player[i].hand,num);
				printf("Because player%d is Calamity Janet, so he can discard a \"Missed\" as \"Bang\"\n",i+1);	
			}else{
				printf("Player%d have no \"Bang\".\n",i+1);
				player_minus_blood(PlayerNow,i);
			}
		}
	}
}
