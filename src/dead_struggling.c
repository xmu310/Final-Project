#include"func.h"
int32_t dead_struggling(int32_t player_index){
	int32_t card_index,num;
	if(!is_player_exist(player_index)||!player[player_index].alive)return 0;
	if(player[player_index].blood<=0&&player[player_index].role==Sid_Ketchum)ask_Sid_Ketchum(player_index);
	while(player[player_index].blood<=0&&have_card(player[player_index].hand,Beer)){
		if(player_index==PlayerHuman){
			printf("Your blood is %d ( <= 0 ). Wanna use beer to recovery?\n",player[player_index].blood);
			while(1){
				printf("(1 for yes, 0 for no): ");
				if(num_scanf(&num,0,1))break;
			}
		}else{
			num=1;
		}
		if(num==1){
			printf("Player%d choose Yes!\n",player_index+1);
			find_card_index(player[player_index].hand,Beer,&card_index);
			get_card(&discard,&player[player_index].hand,card_index);
			player_plus_blood(player_index);
		}else{
			printf("Player%d choose No!\n",player_index+1);
			break;
		}
	}
	return 1;
}
