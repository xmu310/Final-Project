#include"func.h"
void player_minus_blood(int32_t player1_index,int32_t player2_index){
	sleep(1);
	fflush(stdout);
	player[player2_index].blood--;
	printf("Player%d's blood has been -1 !\n",player2_index+1);
	if(player[player2_index].role==Bart_Cassidy){
		printf("Because player%d is Bart Cassidy, he/she can choose a card from stock.\n",player2_index+1);
		get_stock(player2_index,1);
	}
	if(player[player2_index].role==El_Gringo){
		printf("Because player%d is El Gringo, he/she can get a card from player%d's hand cards.\n",player2_index+1,player1_index+1);
		get_last_card(&player[player2_index].hand,&player[player1_index].hand);
		printf("Player%d gets a card from player%d's hand cards.\n",player2_index+1,player1_index+1);
	}
	dead_struggling(player2_index);
	if(player[player2_index].blood<=0){
		printf("Because player%d's blood is %d ( <= 0 ) ,\n",player2_index+1,player[player2_index].blood);
		printf("Player%d was killed by player%d!\n",player2_index+1,player1_index+1);
		player_dead(player2_index);
		if(player[player1_index].iden==Sheriff&&player[player2_index].iden==Deputy_Sheriff){
			printf("Because player%d (Deputy Sheriff) was killed by player%d (Sheriff), player%d should discard all the cards!\n",player2_index+1,player1_index+1,player1_index+1);
			combine_pile(&discard,&player[player1_index].hand);
			combine_pile(&discard,&player[player1_index].equip);
		}
		if(player[player2_index].iden==Outlaw){
			printf("Because player%d (Outlaw) was killed by player%d, player%d can get 3 cards from stock pile!\n",player2_index+1,player1_index+1,player1_index+1);
			get_stock(player1_index,3);
		}
	}
}
