#include"func.h"
void print_all_status(){
	fflush(stdout);
	if(SleepNum==0){
		printf("\nPress enter to continue\n");
		scanf("%*[^\n]");
		scanf("%*c");
	}else sleep(SleepNum);
	system("clear");
	for(int i=0;i<PlayerNum;i++){
		if(i!=PlayerHuman){
			printf("----------------\n");
			print_player_status(i);
		}
	}
	printf(">>>>>>>>>>>>>>>>>>\n");
	printf("(You) ");
	print_player_status(PlayerHuman);
	printf(">>>>>>>>>>>>>>>>>>\n");
	printf("Round: %d\n",Round);
	printf("stock/discard card number: (%d,%d)\n",stock.num,discard.num);
	printf("Now: Player%d\n",PlayerNow+1);
	if(Stage==0)printf("Stage: determine\n");
	if(Stage==1)printf("Stage: draw cards\n");
	if(Stage==2)printf("Stage: use cards\n");
	if(Stage==3)printf("Stage: discard cards\n");
	printf(">>>>>>>>>>>>>>>>>>\n");
}
