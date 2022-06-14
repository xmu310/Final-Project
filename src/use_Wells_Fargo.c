#include"func.h"
void use_Wells_Fargo(int32_t card_index){
	get_card(&discard,&player[PlayerNow].hand,card_index);
	get_stock(PlayerNow,3);
}
