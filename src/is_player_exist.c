#include"func.h"

int32_t is_player_exist(int32_t player_index){
	if(player_index<0||player_index>PlayerNum)return 0;
	return 1;
}
