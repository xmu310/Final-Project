#include"func.h"
sCard det(int32_t player_index){
	sCard tmp={0};
	int32_t num=0;
	if(player[player_index].role!=Lucky_Duke){
		printf("Because Player%d isn't Lucky Duke, he/she can only gets one card to determine.\n",player_index+1);
		get_stock(player_index,1);
		tmp=player[player_index].hand.card[player[player_index].hand.num-1];
		printf("%d. (%s,%s) %s\n",1,
				suit_nametxt[tmp.suit],
				rank_nametxt[tmp.rank],
				type_nametxt[tmp.type]
		);
		get_last_card(&discard,&player[player_index].hand);
		return tmp;
	}
	printf("Because Player%d is Lucky Duke, he/she can gets two cards and choose one to determine.\n",player_index+1);
	get_stock(player_index,2);
	if(player_index==PlayerHuman){
		printf("There are two cards:\n");
		for(int i=0;i<2;i++){
			tmp=player[player_index].hand.card[player[player_index].hand.num-1-1+i];
			printf("%d. (%s,%s) %s\n",i+1,
					suit_nametxt[tmp.suit],
					rank_nametxt[tmp.rank],
					type_nametxt[tmp.type]
			);
		}
		printf("Which card do you want to use to determine (enter card index): ");
		while(!num_scanf(&num)||num!=1&&num!=2){
			printf("Error!\n");
			printf("Please enter again!\n");
		}
		num--;
	}else{
		num=rand()%2;
		tmp=player[player_index].hand.card[player[player_index].hand.num-1-1+num];
		if(tmp.suit!=Heart)num=!num;
	}
	tmp=player[player_index].hand.card[player[player_index].hand.num-1-1+num];
	printf("Player%d choose %d. (%s,%s) %s\n",player_index+1,num+1,
			suit_nametxt[tmp.suit],
			rank_nametxt[tmp.rank],
			type_nametxt[tmp.type]
	);
	get_last_card(&discard,&player[player_index].hand);
	get_last_card(&discard,&player[player_index].hand);
	return tmp;
}
