#include"func.h"
int32_t player_dead(int32_t player_index){
	if(!is_player_exist(player_index))return 0;
	combine_pile(&player[player_index].hand,&player[player_index].equip);
	for(int i=0;i<PlayerNum;i++){
		if(player[i].role==Vulture_Sam)combine_pile(&player[i].hand,&player[player_index].hand);
	}
	combine_pile(&discard,&player[player_index].hand);
	player[player_index].alive=0;
	PlayerAlive--;
	AliveArr[player[player_index].iden]--;
	return 1;
}
