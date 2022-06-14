#include"func.h"
int32_t dead_struggling(int32_t player_index){
	int32_t card_index;
	if(!is_player_exist(player_index)||!player[player_index].alive)return 0;
	if(player[player_index].blood<=0&&player[player_index].role==Sid_Ketchum)ask_Sid_Ketchum(player_index);
	while(player[player_index].blood<=0&&have_card(player[player_index].hand,Beer)){
		printf("Your blood is %d ( <= 0 ). Wanna use beer to recovery?\n",player[player_index].blood);
		if(!YesNo(player_index))return 1;
		find_card_index(player[player_index].hand,Beer,&card_index);
		get_card(&discard,&player[player_index].hand,card_index);
		player_plus_blood(player_index);
	}
	return 1;
}
