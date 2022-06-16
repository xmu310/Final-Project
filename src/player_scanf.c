#include"func.h"
void player_scanf(int32_t *player_index){
	if(PlayerNow==PlayerHuman){
		while(1){
			printf("Which player would you want to choose (enter player index): ");
			if(num_scanf(player_index,1,PlayerNum)){
				*player_index-=1;
				if(*player_index==PlayerNow){printf("You can not choose yourself!\n");continue;}
				if(!player[*player_index].alive){printf("You can not choose the dead player!\n");continue;}
				break;
			}
		}
	}else{
		while(1){
			*player_index=rand()%PlayerNum;
			if(player[*player_index].alive&&*player_index!=PlayerNow)break;
		}
	}
}
