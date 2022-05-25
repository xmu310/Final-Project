#include<stdio.h>
#include<stdint.h>
#include"src/def.h"
#include"src/func.h"
int main(){
	int num;
	printf("Please enter the player number:");
	scanf("%d",&num);
	if(!set_game(num)){
		printf("Error!\n");
		return 0;
	}
	printf("PlayerNum:%ld\n",PlayerNum);
	printf("PlayerNow:%ld\n",PlayerNow);
	printf("PlayerHuman:%ld\n",PlayerHuman);
	for(int i=0;i<PlayerNum;i++){
		printf("-----\n");
		printf("%s\n",iden_nametxt[player[i].iden]);
		printf("%s\n",role_nametxt[player[i].role]);
		printf("role_blood:%ld\n",role_blood[player[i].role]);
		printf("blood:%ld\n",player[i].blood);
		printf("alive:%ld\n",player[i].alive);
		printf("hand_num:%ld\n",player[i].hand.num);
		for(int j=0;j<player[i].hand.num;j++){
			printf("\n%s\n",type_nametxt[player[i].hand.card[j].type]);
			printf("%d:(%s,",j+1,suit_nametxt[player[i].hand.card[j].suit]);
			printf("%s)\n",rank_nametxt[player[i].hand.card[j].rank]);
		}
		printf("equit_num:%ld\n",player[i].equip.num);
		for(int j=0;j<player[i].equip.num;j++){
			printf("\n%s\n",type_nametxt[player[i].equip.card[j].type]);
			printf("%d:(%s,",j+1,suit_nametxt[player[i].equip.card[j].suit]);
			printf("%s)\n",rank_nametxt[player[i].equip.card[j].rank]);
		}
	}
	printf("stock_num:%ld\n",stock.num);
	for(int i=0;i<stock.num;i++){
			printf("\n%s\n",type_nametxt[stock.card[i].type]);
			printf("%d:(%s,",i+1,suit_nametxt[stock.card[i].suit]);
			printf("%s)\n",rank_nametxt[stock.card[i].rank]);
	}
	return 0;
}
