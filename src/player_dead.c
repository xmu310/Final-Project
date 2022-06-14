#include"func.h"
void player_dead(int32_t player_index){
	player[player_index].alive=0;
	PlayerAlive--;
	AliveArr[player[player_index].iden]--;
	combine_pile(&player[player_index].hand,&player[player_index].equip);
	for(int i=0;i<PlayerNum;i++){
		if(player[i].alive&&player[i].role==Vulture_Sam)combine_pile(&player[i].hand,&player[player_index].hand);
	}
	combine_pile(&discard,&player[player_index].hand);
}
