#include"func.h"
void Kit_Carlson_draw(){
	int32_t num=0;
	sPile tmp=player[PlayerNow].hand;
	printf("Because Player%d's role is Kit Carlson, he/she can draw three cards from stock pile to see, and put one back to stock pile.\n",PlayerNow+1);
	get_stock(PlayerNow,3);
	if(PlayerNow==PlayerHuman){
		print_card(1,tmp,tmp.num-3,3);
		while(1){
			printf("Which card do you want to put back (enter card index): ");
			if(num_scanf(&num,1,3))break;
		}
		num--;
	}else num=rand()%3;
	get_card(&stock,&tmp,tmp.num-3+num);
	printf("Player%d put a card back to stock pile.\n",PlayerNow+1);
}
