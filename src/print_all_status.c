#include"func.h"

void print_all_status(){
	printf("Round: %d\n",Round);
	printf(">>>>>>>>>>>>>>>>>>\n");
	for(int i=0;i<PlayerNum;i++){
		if(i!=PlayerHuman){
			if(i)printf("----------------\n");
			print_player_status(i);
		}
	}
	printf("----------------\n");
	printf("stock card number: %d\n",stock.num);
	printf("discard card number: %d\n",discard.num);
	printf(">>>>>>>>>>>>>>>>>>\n");
	printf("(You)\n");
	print_player_status(PlayerHuman);
	printf(">>>>>>>>>>>>>>>>>>\n");
}
