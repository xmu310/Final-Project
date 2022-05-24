#include"func.h"

int64_t unget_card(int64_t player_index){
	return ch_card(&stock,&player[player_index].hand);
}
