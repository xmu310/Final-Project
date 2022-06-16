#include"func.h"
void use_Panic(int32_t card_index){
	int32_t have_card_player=0,player_index,type,num;
	for(int i=0;i<PlayerNum;i++){
		if(i==PlayerNow||!player[i].alive)continue;
		if(distance(PlayerNow,i)<=1&&player[i].hand.num+player[i].equip.num>0)have_card_player++;
	}
	if(have_card_player==0){
		printf("Because no player in the distance 1 has card, you can't use this card!\n");
		return;
	}
	get_card(&discard,&player[PlayerNow].hand,card_index);
	if(PlayerNow==PlayerHuman){
		while(1){
			player_scanf(&player_index);
			if(distance(PlayerNow,player_index)>1){
				printf("The distance between you and Player%d is %d, so you can't choose him/her!\n",player_index+1,distance(PlayerNow,player_index));
				continue;
			}
			if(player[player_index].hand.num+player[player_index].equip.num>0)break;
			printf("This player has no card.\n");
		}
	}else{
		while(1){
			player_scanf(&player_index);
			if(distance(PlayerNow,player_index)>1)continue;
			if(player[player_index].hand.num+player[player_index].equip.num>0)break;
		}
	}
	card_scanf(player_index,&type,&num);
	if(type==0)get_card(&player[PlayerNow].hand,&player[player_index].hand,num);
	if(type==1)get_card(&player[PlayerNow].hand,&player[player_index].equip,num);
	printf("Player%d get a card from the Player%d.\n",PlayerNow+1,player_index+1);
	ask_Suzy_Lafayette(player_index);
}
