#include"func.h"

void use_Wells_Fargo(int32_t card_index){
	get_card(&discard,&player[PlayerNow].hand,card_index);
	get_stock(PlayerNow);
	printf("Player%d got a card from stock pile.\n",PlayerNow+1);
	get_stock(PlayerNow);
	printf("Player%d got a card from stock pile.\n",PlayerNow+1);
	get_stock(PlayerNow);
	printf("Player%d got a card from stock pile.\n",PlayerNow+1);
}
