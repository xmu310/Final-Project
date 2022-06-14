#include"func.h"
void ask_Suzy_Lafayette(int32_t player_index){
	if(player[player_index].role!=Suzy_Lafayette||player[player_index].hand.num>0)return;
	printf("Because Player%d's role is Suzy Lafayette, and he/she doesn't have hand card, he/she can draw a card from stock pile!\n",player_index+1);
	if(!YesNo(player_index))return;
	get_stock(player_index,1);
	print_all_status();
}
