#include"func.h"
void get_stock(int32_t player_index,int32_t cardnum){
	for(int i=0;i<cardnum;i++){
		if(!get_last_card(&player[player_index].hand,&stock)){
			shuffling();
			get_last_card(&player[player_index].hand,&stock);
		}
	}
	printf("Player%d gets %d card(s) from stock pile.\n",player_index+1,cardnum);
}
