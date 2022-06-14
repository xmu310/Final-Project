#include"func.h"
void use_Beer(int32_t card_index){
	get_card(&discard,&player[PlayerNow].hand,card_index);
	if(PlayerAlive<=2){
		printf("Because <= 2 players alive, this card is no effect!\n");
		return;
	}
	player_plus_blood(PlayerNow);
}
