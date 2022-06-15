#include"func.h"
sCard det(int32_t player_index){
	sPile tmp=player[player_index].hand;
	sCard re;
	int32_t num=0;
	if(player[player_index].role!=Lucky_Duke){
		printf("Because Player%d isn't Lucky Duke, he/she can only gets one card to determine.\n",player_index+1);
		get_stock(player_index,1);
		re=tmp.card[tmp.num-1];
		print_card(1,tmp,tmp.num-1,1);
		get_last_card(&discard,&tmp);
		return re;
	}
	printf("Because Player%d is Lucky Duke, he/she can gets two cards and choose one to determine.\n",player_index+1);
	get_stock(player_index,2);
	if(player_index==PlayerHuman){
		printf("There are two cards:\n");
		print_card(1,tmp,tmp.num-2,2);
		while(1){
			printf("Which card do you want to use to determine (enter card index): ");
			if(num_scanf(&num,1,2))break;
		}
		num--;
	}else{
		num=rand()%2;
		if(tmp.card[tmp.num-2+num].suit!=Heart)num=!num;
	}
	re=tmp.card[tmp.num-2+num];
	printf("Player%d chooses:\n",player_index+1);
	print_card(num+1,tmp,tmp.num-2+num,1);
	get_last_card(&discard,&tmp);
	get_last_card(&discard,&tmp);
	return re;
}
