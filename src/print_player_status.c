#include"func.h"

int32_t print_player_status(int32_t player_index){
	if(player_index<0||player_index>PlayerNum)return 0;
	printf("player%d ",player_index+1);
	if(player[player_index].alive){
		printf("(blood %d/%d): ",player[player_index].blood,player[player_index].maxblood);
		if(player[player_index].iden==Sheriff||player_index==PlayerHuman)printf("%s",iden_nametxt[player[player_index].iden]);
		printf("\n%s\n",role_nametxt[player[player_index].role]);
		printf("%s\n",role_helptxt[player[player_index].role]);
		if(player_index!=PlayerHuman){
			printf("hand/equip card number: (%d,%d)\n",player[player_index].hand.num,player[player_index].equip.num);
		}
		if(player_index==PlayerHuman)printf("hand card number: %d\n",player[player_index].hand.num);
		if(player_index==PlayerHuman)for(int j=0;j<player[player_index].hand.num;j++){
			printf("%d. (%s,%s) %s\n",j+1,
					suit_nametxt[player[player_index].hand.card[j].suit],
					rank_nametxt[player[player_index].hand.card[j].rank],
					type_nametxt[player[player_index].hand.card[j].type]);
			printf("%s\n",type_helptxt[player[player_index].hand.card[j].type]);
		}
		if(player_index==PlayerHuman)printf("equip card number: %d\n",player[player_index].equip.num);
		for(int j=0;j<player[player_index].equip.num;j++){
			printf("%d. (%s,%s) %s\n",j+1,
					suit_nametxt[player[player_index].equip.card[j].suit],
					rank_nametxt[player[player_index].equip.card[j].rank],
					type_nametxt[player[player_index].equip.card[j].type]);
			printf("%s\n",type_helptxt[player[player_index].equip.card[j].type]);
		}
	}else printf("<dead>: %s\n",iden_nametxt[player[player_index].iden]);
	return 1;
}
