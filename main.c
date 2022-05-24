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
	for(int i=0;i<PlayerNum;i++){
		printf("%s\n",role_nametxt[player[i].role]);
	}
	return 0;
}
