#include"func.h"
#include<unistd.h>

void use_Gatling(int32_t card_index){
	int32_t num;
	get_card(&discard,&player[PlayerNow].hand,card_index);
	for(int i=0;i<PlayerNum;i++){
		sleep(1);
		if(player[i].alive&&i!=PlayerNow){
			if(player[i].role==Jourdonnais){
				printf("Because player%d is Jourdonnais, he/she has built-in barrel.\n",i+1);	
				if(det(i).suit==Heart){
					printf("Player%d missed!",i+1);
					continue;
				}
			}
			if(find_card_index(player[i].equip,Barrel,&num)){
				printf("Player%d uses a \"Barrel\".\n",i+1);	
				if(det(i).suit==Heart){
					printf("Player%d missed!",i+1);
					continue;
				}
			}
			if(find_card_index(player[i].hand,Missed,&num)){
				get_card(&discard,&player[i].hand,num);
				printf("Player%d uses a \"Missed\".\n",i+1);				
			}else if(player[i].role==Calamity_Janet&&find_card_index(player[i].hand,Bang,&num)){
				get_card(&discard,&player[i].hand,num);
				printf("Because player%d is Calamity Janet, he/she can use a \"Bang\" as \"Missed\"\n",i+1);	
			}else{
				printf("Player%d have no \"Missed\".\n",i+1);
				player_minus_blood(PlayerNow,i);
			}
		}
	}
}
