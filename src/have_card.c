#include"func.h"
int32_t have_card(sPile pile,eType type){
	for(int i=0;i<pile.num;i++){
		if(pile.card[i].type==type)return 1;
	}
	return 0;
}
