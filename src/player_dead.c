#include"func.h"

int32_t player_dead(int32_t player_index){
	if(!is_player_exist(player_index))return 0;
	combine_pile(&player[player_index].hand,&player[player_index].equip);
	for(int i=0;i<PlayerNum;i++){
		if(player[i].role==Vulture_Sam)combine_pile(&player[i].hand,&player[player_index].hand);
	}
	combine_pile(&discard,&player[player_index].hand);
	player[player_index].alive=0;
	if(player[player_index].iden==Sheriff)SheriffAlive--;
	if(player[player_index].iden==Deputy_Sheriff)DeputySheriffAlive--;
	if(player[player_index].iden==Outlaw)OutlawAlive--;
	if(player[player_index].iden==Renegade)RenegadeAlive--;
	return 1;
}
