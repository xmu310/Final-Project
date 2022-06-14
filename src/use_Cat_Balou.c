#include"func.h"
void use_Cat_Balou(int32_t card_index){
	int32_t have_card_player=0,player_index,type,num;
	for(int i=0;i<PlayerNum;i++){
		if(i==PlayerNow||!player[i].alive)continue;
		if(player[i].hand.num+player[i].equip.num>0)have_card_player++;
	}
	if(have_card_player==0){printf("Because no other player has card, you can't use this card!\n");return;}
	get_card(&discard,&player[PlayerNow].hand,card_index);
	if(PlayerNow==PlayerHuman){
		while(1){
			player_scanf(&player_index);
			if(player[player_index].hand.num+player[player_index].equip.num>0)break;
			printf("This player has no card.\n");
		}
	}else{
		while(1){
			player_scanf(&player_index);
			if(player[player_index].hand.num+player[player_index].equip.num>0)break;
		}
	}
	type_scanf(player_index,&type);
	card_scanf(player_index,type,&num);
	if(type==0)get_card(&discard,&player[player_index].hand,num);
	if(type==1)get_card(&discard,&player[player_index].equip,num);
	printf("Player%d discard this card.\n",player_index+1);
	ask_Suzy_Lafayette(player_index);
}
