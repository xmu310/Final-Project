#include<stdio.h>
#include<stdint.h>
#include"all.h"
int main(){
	int num;
	printf("Please enter the player number:");
	scanf("%d",&num);
	if(!set_game(num)){
		printf("Error!\n");
		return 0;
	}
	for(int i=0;i<CardNum;i++){
		printf("%d:\n",i+1);
		printf("%s\n",type_nametxt[stock_pile[i].type]);
		printf("(%s,",suit_nametxt[stock_pile[i].suit]),
		printf("%s)\n",rank_nametxt[stock_pile[i].rank]);
	}
	return 0;
}
