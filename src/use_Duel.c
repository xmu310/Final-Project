#include"func.h"
void use_Duel(int32_t card_index){
	int32_t player_index,num,turn=0,who=0;
	get_card(&discard,&player[PlayerNow].hand,card_index);
	player_scanf(&player_index);
	who=player_index;
	printf("Player%d and player%d starts duel!\n",PlayerNow+1,player_index+1);
	while(1){
		sleep(1);
		if(find_card_index(player[who].hand,Bang,&num)){
			get_card(&discard,&player[who].hand,num);
			printf("Player%d discard a \"Bang\"\n",who+1);				
		}else if(player[who].role==Calamity_Janet&&find_card_index(player[who].hand,Bang,&num)){
			get_card(&discard,&player[who].hand,num);
			printf("Because player%d is Calamity Janet, so he can discard a \"Missed\" as \"Bang\"\n",who+1);	
		}else{
			printf("Player%d have no \"Bang\".\n",who+1);
			player_minus_blood(PlayerNow,who);
			return;
		}
		turn=!turn;
		who=turn?PlayerNow:player_index;
	}
}
