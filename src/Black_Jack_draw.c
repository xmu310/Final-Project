#include"func.h"

void Black_Jack_draw(){
	get_stock(PlayerNow);
	printf("Player%d got a card from stock pile.\n",PlayerNow+1);
	get_stock(PlayerNow);
	printf("Player%d got a card from stock pile.\n",PlayerNow+1);
	sPile temp=player[PlayerNow].hand;
	printf("This card is %s\n",type_nametxt[temp.card[temp.num-1].type]);
	printf("Which is (%s,%s)\n",
			suit_nametxt[temp.card[temp.num-1].suit],
			rank_nametxt[temp.card[temp.num-1].rank]
	);
	if(temp.card[temp.num-1].rank==Heart||temp.card[temp.num-1].rank==Diamond){
		printf("Because Player%d's role is Black Jack, and his second card is Heart or Diamond, he/she can draw a card again.\n",PlayerNow+1);
		get_stock(PlayerNow);
		printf("Player%d got a card from stock pile.\n",PlayerNow+1);
	}
}
