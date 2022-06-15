#include"func.h"
void print_player_status(int32_t player_index){
	sPlayer tmp=player[player_index];
	printf("player%d ",player_index+1);
	if(tmp.alive){
		printf("(blood %d/%d): ",tmp.blood,tmp.maxblood);
		if(tmp.iden==Sheriff||player_index==PlayerHuman)printf("%s",iden_nametxt[tmp.iden]);
		printf("\n%s\n",role_nametxt[tmp.role]);
		printf("%s\n",role_helptxt[tmp.role]);
		if(player_index!=PlayerHuman){
			printf("hand/equip card number: (%d,%d)\n",tmp.hand.num,tmp.equip.num);
		}
		if(player_index==PlayerHuman)printf("hand card number: %d\n",tmp.hand.num);
		if(player_index==PlayerHuman)for(int j=0;j<tmp.hand.num;j++){
			print_card(1+j,tmp.hand,j,1);
			printf("%s\n",type_helptxt[tmp.hand.card[j].type]);
		}
		if(player_index==PlayerHuman)printf("equip card number: %d\n",tmp.equip.num);
		for(int j=0;j<tmp.equip.num;j++){
			print_card(1+j,player[player_index].equip,j,1);
			printf("%s\n",type_helptxt[tmp.equip.card[j].type]);
		}
	}else printf("<dead>: %s\n",iden_nametxt[tmp.iden]);
}
