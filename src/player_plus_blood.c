#include"func.h"
void player_plus_blood(int32_t player_index){
	sleep(1);
	fflush(stdout);
	player[player_index].blood++;
	if(player[player_index].blood>=player[player_index].maxblood){
		printf("Player%d's blood has been added to max!\n",player_index+1);
		player[player_index].blood=player[player_index].maxblood;
	}else printf("Player%d's blood has been +1 !\n",player_index+1);
}
