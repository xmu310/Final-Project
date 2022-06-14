#include"func.h"
void use_General_Store(int32_t card_index){
	get_card(&discard,&player[PlayerNow].hand,card_index);
	sPile tmp={0};
	int32_t num,total=PlayerAlive,player_index=PlayerNow;
	get_stock(PlayerNow,total);
	for(int i=0;i<total;i++)get_last_card(&tmp,&player[PlayerNow].hand);
	while(1){
		sleep(1);
		if(player_index==PlayerHuman){
			printf("There are %d card in the list:\n",total);
			for(int i=0;i<total;i++){
				printf("%d. (%s,%s) %s\n",i+1,
						suit_nametxt[tmp.card[i].suit],
						rank_nametxt[tmp.card[i].rank],
						type_nametxt[tmp.card[i].type]
				);
			}
			while(1){
				printf("Which one do you want to choose (enter card index):");
				if(num_scanf(&num,1,total))break;
			}
			num--;
		}else num=rand()%total;
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
