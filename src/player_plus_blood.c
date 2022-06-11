#include"func.h"

int32_t player_plus_blood(int32_t player_index){
	if(!is_player_exist)return 0;
	player[player_index].blood++;
	if(player[player_index].blood>=player[player_index].maxblood){
		printf("Player%d's blood has been added to max!",player_index+1);
		player[player_index].blood=player[player_index].maxblood;
	}
	return 1;
}
