#include"func.h"

int64_t get_card(int64_t player_index){
	return change_card(&player[player_index].hand,&stock);
}
