#include"func.h"

int32_t player_dead(int32_t player_index){
	if(!is_player_exist(player_index))return 0;
	player[player_index].alive=0;
	if(player[player_index].iden==Sheriff)SheriffAlive--;
	if(player[player_index].iden==Deputy_Sheriff)DeputySheriffAlive--;
	if(player[player_index].iden==Outlaw)OutlawAlive--;
	if(player[player_index].iden==Renegade)RenegadeAlive--;
	return 1;
}
