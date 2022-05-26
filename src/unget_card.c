#include"func.h"

int32_t unget_card(sPile *pile1,int32_t card_index,sPile *pile2){
	return get_card(pile2,pile1,card_index);
}
