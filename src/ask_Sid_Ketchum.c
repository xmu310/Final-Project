#include"func.h"
void ask_Sid_Ketchum(int32_t player_index){
	int32_t num;
	if(player[player_index].role!=Sid_Ketchum)return;
	while(1){
		if(player[player_index].blood>=player[player_index].maxblood||player[player_index].hand.num<2)break;
		printf("Because Player%d's role is Sid Ketchum, he/she has chanced to discarded two cards to add blood!\n",player_index+1);
		if(!YesNo(player_index))return;
		for(int i=0;i<2;i++){
			if(player_index==PlayerHuman){
				while(1){
					printf("Which hand card do you want to discard (%d/2) (enter card index): ",i+1);
					if(num_scanf(&num,1,player[player_index].hand.num))break;
				}
				num--;
			}else num=rand()%player[player_index].hand.num;
			printf("Player%d chooses %d. %s\n",player_index+1,num+1,type_nametxt[player[player_index].hand.card[num].type]);
			get_card(&discard,&player[player_index].hand,num);
			printf("Player%d discards a card to discard pile.\n",player_index+1);
			print_all_status();
		}
		printf("Because Player%d's role is Sid Ketchum, and he/she has discarded two cards, his/her blood can +1.\n",player_index+1);
		player_plus_blood(player_index);
		print_all_status();
	}
}
