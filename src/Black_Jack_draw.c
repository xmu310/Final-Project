#include"func.h"
void Black_Jack_draw(){
	get_stock(PlayerNow,2);
	printf("Because Player%d's role is Black Jack, if his second card is Heart or Diamond, he/she can draw a card again.\n",PlayerNow+1);
	sPile temp=player[PlayerNow].hand;
	printf("The second card is:\n");
	print_card(1,temp,temp.num-1,1);
	if(temp.card[temp.num-1].suit==Heart||temp.card[temp.num-1].suit==Diamond){
		printf("Player%d's second card is Heart or Diamond, he/she can draw a card again.\n",PlayerNow+1);
		get_stock(PlayerNow,1);
	}else	printf("Player%d's second card is not Heart or Diamond, he/she can not draw a card again.\n",PlayerNow+1);
}
