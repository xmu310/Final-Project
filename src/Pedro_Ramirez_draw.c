#include"func.h"
void Pedro_Ramirez_draw(){
	int32_t num=0;
	printf("Because Player%d's role is Pedro Ramirez, his/her first card can draw from stock pile or discard pile.\n",PlayerNow+1);
	if(PlayerNow==PlayerHuman){
		while(1){
			printf("Which pile do you want to choose (0 for stock pile, 1 for discard pile): ");
			if(!num_scanf(&num,0,1))continue;
			if(num==0&&stock.num<=0){
				printf("Stock piles have no card!\n");
				continue;
			}else if(num==1&&discard.num<=0){
				printf("discard piles have no card!\n");
				continue;
			}else break;
		}
	}else{
		while(1){
			num=rand()%2;
			if(num==0&&stock.num<=0)continue;
			if(num==1&&discard.num<=0)continue;
			break;
		}
	}
	if(num==0){
		get_stock(PlayerNow,1);
	}else{
		get_last_card(&player[PlayerNow].hand,&discard);
		printf("Player%d got a card from discard pile.\n",PlayerNow+1);
	}
	get_stock(PlayerNow,1);
}
