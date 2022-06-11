#include"func.h"
#include"stdlib.h"

void Kit_Carlson_draw(){
	int32_t num=0,ini;
	printf("Because Player%d's role is Kit Carlson, he/she can draw three cards from stock pile to see, and put one back to stock pile.\n",PlayerNow+1);
	get_stock(PlayerNow);
	printf("Player%d got a card from stock pile.\n",PlayerNow+1);
	get_stock(PlayerNow);
	printf("Player%d got a card from stock pile.\n",PlayerNow+1);
	get_stock(PlayerNow);
	printf("Player%d got a card from stock pile.\n",PlayerNow+1);
	if(PlayerNow==PlayerHuman){
		printf("You drawed three cards, ");
		ini=player[PlayerNow].hand.num-1-2;
		for(int i=0;i<3;i++){
			printf("%d. (%s,%s) %s\n",i+1,
					suit_nametxt[player[PlayerNow].hand.card[ini+i].suit],
					rank_nametxt[player[PlayerNow].hand.card[ini+i].rank],
					type_nametxt[player[PlayerNow].hand.card[ini+i].type]
			);
		}
		printf("Which card do you want to put back (enter card index): ");
		while(!num_scanf(&num)||num<1||num>3){
			printf("Error!\n");
			printf("Please enter again!\n\n");
		}
		num--;
	}else{
		num=rand()%3;
	}
	get_card(&stock,&player[PlayerNow].hand,player[PlayerNow].hand.num-1-2+num);
	printf("Player%d put a card back to stock pile.\n",PlayerNow+1);
}
