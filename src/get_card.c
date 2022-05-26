#include"func.h"

int32_t get_card(sPile *pile1,sPile *pile2,int32_t card_index){
	if(card_index<0||card_index>=pile2->num)return 0;
	pile1->card[pile1->num]=pile2->card[card_index];
	pile1->num++;
	pile2->num--;
	for(int i=card_index;i<pile2->num;i++)pile2->card[i]=pile2->card[i+1];
	return 1;
}
