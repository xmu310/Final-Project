#pragma once
#include"def.h"

void shuffling();
void combine_pile(sPile *pile1,sPile *pile2);
void print_all_status();
void next_round();

//if success, return 1, else return 0.
int32_t set_game(int32_t player_num);
int32_t get_card(sPile *pile1,sPile *pile2,int32_t card_index);
int32_t unget_card(sPile *pile1,int32_t card_index,sPile *pile2);
int32_t get_last_card(sPile *pile1,sPile *pile2);
int32_t unget_last_card(sPile *pile1,sPile *pile2);
int32_t num_scanf(int32_t *num);
int32_t print_player_status(int32_t player_index);

//if the pile have card, return 1, else return 0.
int32_t have_card(sPile pile,eType type);

//if success, return distance, else return 0;
//There're three cases return 0:
//First is Player1 and player2 isn't exists.
//Second is either player1 or player2 is dead.
//Third is player1 and player2 are the same.
int32_t distance(int32_t player1_index,int32_t player2_index);
