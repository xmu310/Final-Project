#include"func.h"

int32_t get_last_card(sPile *pile1,sPile *pile2){
	return get_card(pile1,pile2,pile2->num-1);
}
