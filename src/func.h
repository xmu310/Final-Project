#pragma once
#include"def.h"

//if success, return 1, else return 0.
int32_t set_game(int32_t player_num);
void shuffling();
int32_t get_card(sPile *pile1,sPile *pile2,int32_t card_index);
int32_t unget_card(sPile *pile1,int32_t card_index,sPile *pile2);
int32_t get_last_card(sPile *pile1,sPile *pile2);
int32_t unget_last_card(sPile *pile1,sPile *pile2);
void combine_pile(sPile *pile1,sPile *pile2);
int32_t num_scanf(int32_t *num);
void print_all_player();
