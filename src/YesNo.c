#include"func.h"
int32_t YesNo(int32_t player_index){
	int32_t num;
	if(player_index==PlayerHuman){
		while(1){
			printf("Wanna do it?(1 for Yes, 0 for No): ");
			if(num_scanf(&num,0,1))break;
		}
	}else num=rand()%2;
	if(num==1)printf("Player%d choose Yes!\n",player_index+1);
	else printf("Player%d choose No!\n",player_index+1);
	return num;
}
