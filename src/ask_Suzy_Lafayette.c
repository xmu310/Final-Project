#include"func.h"
int32_t ask_Suzy_Lafayette(int32_t player_index){
	int32_t num;
	if(!is_player_exist(player_index))return 0;
	if(player[player_index].role!=Suzy_Lafayette||player[player_index].hand.num>0)return 1;
	printf("Because Player%d's role is Suzy Lafayette, and he/she doesn't have hand card, he/she can draw a card from stock pile!\n",player_index+1);
	if(player_index==PlayerHuman){
		while(1){
			printf("Wanna do it?(1 for Yes, 0 for No): \n");
			if(num_scanf(&num,0,1))break;
		}
	}else{
		if(rand()%2)num=1;else num=0;
	}
	if(num==1){
		printf("Player%d choose Yes!\n",player_index+1);
	}else{
		printf("Player%d choose No!\n",player_index+1);
		return 1;
	}
	get_stock(player_index,1);
	print_all_status();
	return 1;
}
