#pragma once
#include"def.h"

//if success, return 1, else return 0.
int64_t set_game(int64_t player_num);
void shuffling(sPile *pile);
int64_t change_card(sPile *pile1,sPile *pile2);
int64_t get_card(int64_t player_index);
