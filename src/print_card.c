#include"func.h"
void print_card(int32_t index,sPile pile,int32_t pos,int32_t times){
	for(int i=0;i<times;i++){
		printf("%d. (%s,%s) %s\n",index+i,
				suit_nametxt[pile.card[pos+i].suit],
				rank_nametxt[pile.card[pos+i].rank],
				type_nametxt[pile.card[pos+i].type]
		);
	}
}
