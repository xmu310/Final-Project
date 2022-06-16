#pragma once
#include"def.h"

void set_game();
void player_scanf(int32_t *player_index);
void card_scanf(int32_t player_index,int32_t *type,int32_t *card_index);
void shuffling();
void combine_pile(sPile *pile1,sPile *pile2);
void get_stock(int32_t player_index,int32_t cardnum);//if stock pile have no card, it'll combine stock pile and dicard pile to stock pile, and shuffling, and pick a card.
void print_player_status(int32_t player_index);
void print_all_status();//it will wait 2 sec, then clear screen, print all status.
void print_card(int32_t index,sPile pile,int32_t pos,int32_t times);
void print_ascii(eAscii opt);
void player_plus_blood(int32_t player_index);//if player's blood added to max, this function will printf message, so you don't need to deal with maxblood's problem.
void player_minus_blood(int32_t player1_index,int32_t player2_index);
void dead_struggling(int32_t player_index);//if player's blood <= 0, ask player whether use beer to recovery.
void player_dead(int32_t player_index);

sCard det(int32_t player_index);//If this player is Lucky Duke, draw two cards for him/her, and ask him/her which card he/she wants to use to determine. If not, only draw a card from stock. And both return sCard, you don't need to recycle it, it just tmp card.
void det_Dynamite();
int32_t det_Jail();

void Black_Jack_draw();
void Jesse_Jones_draw();
void Kit_Carlson_draw();
void Pedro_Ramirez_draw();

void ask_Suzy_Lafayette(int32_t player_index);//If this player is Suzy Lafayette and have no hand card, ask him/her whether he/she wants to draw a card from stock. If this player is not Suzy Lafayette or still have hand card, then nothing to do.
void ask_Sid_Ketchum(int32_t player_index);//If this player is Sid Ketchum and blood is not max, ask him/her whether he/she wants to discard two cards to added his blood. If this player is not Sid Ketchum or blood is max, then nothing to do.

void use_card(int32_t card_index);
void use_Bang(int32_t card_index);
void use_Beer(int32_t card_index);
void use_Sallon(int32_t card_index);
void use_Wells_Fargo(int32_t card_index);
void use_Diligenza(int32_t card_index);
void use_General_Store(int32_t card_index);
void use_Panic(int32_t card_index);
void use_Cat_Balou(int32_t card_index);
void use_Gatling(int32_t card_index);
void use_Indians(int32_t card_index);
void use_Duel(int32_t card_index);
void use_Barrel(int32_t card_index);
void use_Scope(int32_t card_index);
void use_Appaloosa(int32_t card_index);
void use_Mustang(int32_t card_index);
void use_Jail(int32_t card_index);
void use_Dynamite(int32_t card_index);
void use_Volcanic(int32_t card_index);
void use_Schofield(int32_t card_index);
void use_Remington(int32_t card_index);
void use_Rev_Carabine(int32_t card_index);
void use_Winchedster(int32_t card_index);

//if success, return 1, else return 0.
int32_t get_card(sPile *pile1,sPile *pile2,int32_t card_index);
int32_t get_last_card(sPile *pile1,sPile *pile2);
int32_t num_scanf(int32_t *num,int32_t lowest,int32_t highest);
int32_t YesNo();
int32_t find_card_index(sPile pile,eType type,int32_t *pCard_index);

//if true, return 1, else return 0.
int32_t have_card(sPile pile,eType type);

int32_t distance(int32_t player1_index,int32_t player2_index);
int32_t weapon_distance();

//if Sheriff&Deputy_Sheriff win, return 1
//else if Outlaw wins, return 2
//else if Renegade wins, return 3
//else return 0
int32_t who_win();
