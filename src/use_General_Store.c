#include"func.h"
#include<stdlib.h>

void use_General_Store(int32_t card_index){
	get_card(&discard,&player[PlayerNow].hand,card_index);
	sPile tmp;
	int32_t num,total=PlayerAlive,player_index=PlayerNow;
	for(int i=0;i<total;i++){
		get_stock(PlayerNow);
		get_last_card(&tmp,&player[PlayerNow].hand);
		printf("Player%d gets a card from stock pile.\n",PlayerNow+1);
	}
	while(1){
		if(player_index==PlayerHuman){
			printf("There are %d card in the list:\n",total);
			for(int i=0;i<total;i++){
				printf("%d. (%s,%s) %s\n",i+1,
						suit_nametxt[tmp.card[i].suit],
						rank_nametxt[tmp.card[i].rank],
						type_nametxt[tmp.card[i].type]
				);
			}
			printf("Which one do you want to choose (enter card index):");
			while(!num_scanf(&num)||num<1||num>total){
				printf("Error!\n");
				printf("Please enter again!\n\n");
			}
			num--;
		}else{
			num=rand()%total;
		}
		printf("Player%d gets a card.\n",player_index+1);
		get_card(&player[player_index].hand,&tmp,num);
		total--;
		if(total<=0)break;
		while(1){
			player_index=(player_index+1)%PlayerNum;
			if(player[player_index].alive)break;
		}
	}
}
