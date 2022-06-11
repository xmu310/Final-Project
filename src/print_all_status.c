#include"func.h"
#include"stdlib.h"
#include"unistd.h"

void print_all_status(){
	fflush(stdout);
	sleep(2);
	system("clear");
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
	printf("Now: Player%d\n",PlayerNow+1);
	if(Stage==0)printf("Stage: determine\n");
	if(Stage==1)printf("Stage: draw cards\n");
	if(Stage==2)printf("Stage: use cards\n");
	if(Stage==3)printf("Stage: discard cards\n");
	printf(">>>>>>>>>>>>>>>>>>\n");
}
