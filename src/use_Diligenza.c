#include"func.h"
void use_Diligenza(int32_t card_index){
	get_card(&discard,&player[PlayerNow].hand,card_index);
	get_stock(PlayerNow,2);
}
