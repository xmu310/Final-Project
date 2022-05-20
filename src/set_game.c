#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"def.h"

char *iden_nametxt[IdenNum];
char *iden_helptxt[IdenNum];
int64_t role_blood[RoleNum];
char *role_nametxt[RoleNum];
char *role_helptxt[RoleNum];
char *type_nametxt[TypeNum];
char *type_helptxt[TypeNum];

sPile stock_pile[CardNum];
sPile discard_pile[CardNum];

int64_t PlayerNum;
sPlayer *player;

void checkdef();
void init_arr();
void init_game();

int64_t set_game(int64_t player_num){
	checkdef();
	if(player_num<4||player_num>7)return -1;
	init_arr();
	init_game();
	return 0;
}

#define checkdef_m(x,y) do{if(x!=y){printf(#x" in def.h is wrong!\n");exit(0);}}while(0)

void checkdef(){
	checkdef_m(RankNum,13);
	checkdef_m(SuitNum,4);
	checkdef_m(IdenNum,4);
	checkdef_m(RoleNum,16);
	checkdef_m(TypeNum,23);
	checkdef_m(CardNum,80);
}

#define checkfopen_m(x) do{\
	fp=fopen("data/"#x".txt","r");\
	if(!fp){printf("data/"#x".txt doesn't exist!\n");exit(0);}\
}while(0)

#define core_fscanf_m(x,y) do{\
	fscanf(fp,"%[^:]:",buf);\
	if(strcmp(#x,buf)){printf(#x" doesn't match in data/"#y".txt!(%s)\n",buf);exit(0);}\
	fscanf(fp,"%m[^\n]\n%m[^:]:\n",&y##_nametxt[x],&y##_helptxt[x]);\
	y##_helptxt[x][strlen(y##_helptxt[x])-1]=0;\
}while(0)

#define rcore_fscanf_m(x,y) do{\
	fscanf(fp,"%[^:]:",buf);\
	if(strcmp(#x,buf)){printf(#x" doesn't match in data/"#y".txt!(%s)\n",buf);exit(0);}\
	fscanf(fp,"%ld:",&y##_blood[x]);\
	fscanf(fp,"%m[^\n]\n%m[^:]:\n",&y##_nametxt[x],&y##_helptxt[x]);\
	y##_helptxt[x][strlen(y##_helptxt[x])-1]=0;\
}while(0)

#define iden_fscanf_m(x) core_fscanf_m(x,iden)
#define role_fscanf_m(x) rcore_fscanf_m(x,role)
#define type_fscanf_m(x) core_fscanf_m(x,type)

void init_arr(){
	FILE *fp;
	char buf[100]={0};

	checkfopen_m(iden);
	iden_fscanf_m(Sheriff);
	iden_fscanf_m(Deputy_Sheriff);
	iden_fscanf_m(Outlaw);
	iden_fscanf_m(Renegade);
	fclose(fp);

	checkfopen_m(role);
	role_fscanf_m(Bart_Cassidy);
	role_fscanf_m(Black_Jack);
	role_fscanf_m(Calamity_Janet);
	role_fscanf_m(El_Gringo);
	role_fscanf_m(Jesse_Jones);
	role_fscanf_m(Jourdonnais);
	role_fscanf_m(Kit_Carlson);
	role_fscanf_m(Lucky_Duke);
	role_fscanf_m(Paul_Regret);
	role_fscanf_m(Pedro_Ramirez);
	role_fscanf_m(Rose_Doolan);
	role_fscanf_m(Sid_Ketchum);
	role_fscanf_m(Slab_the_Killer);
	role_fscanf_m(Suzy_Lafayette);
	role_fscanf_m(Vulture_Sam);
	role_fscanf_m(Willy_the_Kid);
	fclose(fp);

	checkfopen_m(type);
	type_fscanf_m(Bang);
	type_fscanf_m(Missed);
	type_fscanf_m(Beer);
	type_fscanf_m(Sallon);
	type_fscanf_m(Wells_Fargo);
	type_fscanf_m(Diligenza);
	type_fscanf_m(General_Store);
	type_fscanf_m(Panic);
	type_fscanf_m(Cat_Balou);
	type_fscanf_m(Gatling);
	type_fscanf_m(Indians);
	type_fscanf_m(Duel);
	type_fscanf_m(Barrel);
	type_fscanf_m(Scope);
	type_fscanf_m(Appaloosa);
	type_fscanf_m(Mustang);
	type_fscanf_m(Jail);
	type_fscanf_m(Dynamite);
	type_fscanf_m(Volcanic);
	type_fscanf_m(Schofield);
	type_fscanf_m(Remington);
	type_fscanf_m(Rev_Carabine);
	type_fscanf_m(Winchedster);
	fclose(fp);
}

void init_game(){
}
