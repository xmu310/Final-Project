#include"func.h"

int64_t ch_card(sPile *pile1,sPile *pile2){
	if(pile2->num<=0)return 0;
	pile1->card[pile1->num]=pile2->card[pile2->num-1];
	pile1->num++;
	pile2->num--;
	return 1;
}
