#include"func.h"
#include<stdlib.h>

void use_Cat_Balou(int32_t card_index){
	int32_t have_card_player=0,player_index,type,num;
	for(int i=0;i<PlayerNum;i++){
		if(i==PlayerNow||!player[i].alive)continue;
		if(player[i].hand.num+player[i].equip.num>0)have_card_player++;
	}
	if(have_card_player==0){
		printf("Because no other player has card, you can't use this card!\n");
		return;
	}
	get_card(&discard,&player[PlayerNow].hand,card_index);
	if(PlayerNow==PlayerHuman){
		printf("Which player's card do you want to choose (enter player index):");
		while(1){
			if(!num_scanf(&player_index)||player_index<1||player_index>PlayerNum){
				printf("Error!\n");
				printf("Please enter again!\n\n");
				continue;
			}
			player_index--;
			if(player_index==PlayerNow||!player[player_index].alive){
				printf("You can't choose yourself!\n");
				printf("Please enter again!\n\n");
				continue;
			}
			if(player[player_index].hand.num+player[player_index].equip.num<=0){
				printf("This player has no card.");
				printf("Please enter again!\n\n");
				continue;
			}else break;
		}
		printf("Which kind do you want to choose (0 for hand card, 1 for equip card):");
		while(1){
			if(!num_scanf(&type)||type!=0&&type!=1){
				printf("Error!\n");
				printf("Please enter again!\n\n");
				continue;
			}
			if(type==0&&player[player_index].hand.num<=0||type==1&&player[player_index].equip.num<=0){
				printf("This player has no card of this kind.");
				printf("Please enter again!\n\n");
				continue;
			}else break;
		}
		printf("Which card do you want to choose (enter card index):");
		while(1){
			if(!num_scanf(&num)||num<1||type==0&&num>player[player_index].hand.num||type==1&&num>player[player_index].equip.num){
				printf("Error!\n");
				printf("Please enter again!\n\n");
				continue;
			}else{
				num--;
				break;
			}
		}
	}else{
		while(1){
			player_index=rand()%PlayerNum;
			if(player_index==PlayerNow||!player[player_index].alive){
				continue;
			}
			if(player[player_index].hand.num+player[player_index].equip.num<=0){
				continue;
			}else break;
		}
		while(1){
			player_index=rand()%2;
			if(type==0&&player[player_index].hand.num<=0||type==1&&player[player_index].equip.num<=0){
				continue;
			}else break;
		}
		if(type==0)type=rand()%player[player_index].hand.num;
		if(type==1)type=rand()%player[player_index].equip.num;
	}
	if(type==0)get_card(&discard,&player[player_index].hand,num);
	if(type==1)get_card(&discard,&player[player_index].equip,num);
	printf("Player%d discard this card.\n",player_index+1);
}
