#include"func.h"
#include<stdlib.h>

int32_t ask_Sid_Ketchum(int32_t player_index){
	int32_t num;
	if(!is_player_exist(player_index))return 0;
	if(player[player_index].role!=Sid_Ketchum)return 1;
	while(1){
		if(player[player_index].blood>=player[player_index].maxblood||player[player_index].hand.num<2)break;
		printf("Because Player%d's role is Sid Ketchum, he/she has chanced to discarded two cards to add blood!\n",player_index+1);
		printf("Wanna do it?(1 for Yes, other for No): ");
		if(player_index==PlayerHuman){
			if(!num_scanf(&num))num=0;
		}else{
			if(rand()%2)num=1;else num=0;
		}
		if(num==1){
			printf("Player%d choose Yes!\n",player_index+1);
		}else{
			printf("Player%d choose No!\n",player_index+1);
			break;
		}
		for(int i=0;i<2;i++){
			if(player_index==PlayerHuman){
				printf("%d. Which hand card do you want to discard (enter card index): ",i+1);
				if(!num_scanf(&num)||num<1||num>player[player_index].hand.num){
					printf("Error\n");
					continue;
				}
				num--;
			}else{
				num=rand()%player[player_index].hand.num;
			}
			printf("Player%d choose %d. %s\n",player_index+1,num+1,type_nametxt[player[player_index].hand.card[num].type]);
			get_card(&discard,&player[player_index].hand,num);
			printf("Player%d discarded a card to discard pile.\n",player_index+1);
			print_all_status();
		}
		printf("Because Player%d's role is Sid Ketchum, and he/she has discarded two cards, his/her blood can +1.\n",player_index+1);
		player_plus_blood(player_index);
		print_all_status();
	}
	return 1;
}
