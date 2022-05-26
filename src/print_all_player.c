#include"func.h"

void print_all_player(){
	printf("Round: %d\n",Round);
	printf(">>>>>>>>>>>>>>>>>>\n");
	for(int i=0;i<PlayerNum;i++){
		if(i)printf("----------------\n");
		if(i==PlayerHuman)printf("(You)\n");
		printf("player%d",i+1);
		if(player[i].alive){
			printf("(%d/%d): ",player[i].blood,player[i].maxblood);
			if(player[i].iden==Sheriff)printf("%s",iden_nametxt[player[i].iden]);
			printf("\nrole: %s\n",role_nametxt[player[i].role]);
			printf("role ability: %s\n",role_helptxt[player[i].role]);
			printf("hand card number: %d\n",player[i].hand.num);
			if(i==PlayerHuman)for(int j=0;j<player[i].hand.num;j++){
				printf("(%d) %s\n",j+1,type_nametxt[player[i].hand.card[j].type]);
				printf("effect: %s\n",type_helptxt[player[i].hand.card[j].type]);
			}
			printf("equip card number: %d\n",player[i].equip.num);
			for(int j=0;j<player[i].equip.num;j++){
				printf("(%d) %s\n",j+1,type_nametxt[player[i].equip.card[j].type]);
				printf("effect: %s\n",type_helptxt[player[i].equip.card[j].type]);
			}
		}else printf("<dead>: %s\n",iden_nametxt[player[i].iden]);
	}
	printf(">>>>>>>>>>>>>>>>>>\n");
}
