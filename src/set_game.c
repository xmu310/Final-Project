#include"func.h"
#include<stdlib.h>
#include<string.h>
#include<time.h>

char *suit_nametxt[SuitNum];
char *iden_nametxt[IdenNum];
char *iden_helptxt[IdenNum];
int32_t role_blood[RoleNum];
char *role_nametxt[RoleNum];
char *role_helptxt[RoleNum];
char *type_nametxt[TypeNum];
char *type_helptxt[TypeNum];
char *rank_nametxt[RankNum+1];

sPile stock;
sPile discard;

int32_t PlayerNum;
int32_t PlayerNow;
int32_t PlayerHuman;
sPlayer player[PlayerMaxNum];
int32_t Round;

void checkdef();
void init_arr();
void init_card();
void init_player();

int32_t set_game(int32_t player_num){
	checkdef();
	if(player_num<4||player_num>7)return 0;
	PlayerNum=player_num;
	init_arr();
	init_card();
	init_player();
	return 1;
}

#define checkdef_m(x,y) do{if(x!=y){printf(#x" in def.h is wrong!\n");exit(0);}}while(0)
void checkdef(){
	checkdef_m(SuitNum,4);
	checkdef_m(IdenNum,4);
	checkdef_m(RoleNum,16);
	checkdef_m(TypeNum,23);
	checkdef_m(CardNum,80);
	checkdef_m(RankNum,13);
	checkdef_m(PlayerMaxNum,7);
}
#undef checkdef_m

void init_arr(){
	FILE *fp;
	char buf[100]={0};

#define InitSuit_m(x) suit_nametxt[x]=#x 
	InitSuit_m(Spade);
	InitSuit_m(Heart);
	InitSuit_m(Diamond);
	InitSuit_m(Club);
#undef InitSuit_m

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
	fscanf(fp,"%d:",&y##_blood[x]);\
	fscanf(fp,"%m[^\n]\n%m[^:]:\n",&y##_nametxt[x],&y##_helptxt[x]);\
	y##_helptxt[x][strlen(y##_helptxt[x])-1]=0;\
}while(0)

#define iden_fscanf_m(x) core_fscanf_m(x,iden)
	checkfopen_m(iden);
	iden_fscanf_m(Sheriff);
	iden_fscanf_m(Deputy_Sheriff);
	iden_fscanf_m(Outlaw);
	iden_fscanf_m(Renegade);
	fclose(fp);
#undef iden_fscanf_m

#define role_fscanf_m(x) rcore_fscanf_m(x,role)
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
#undef role_fscanf_m

#define type_fscanf_m(x) core_fscanf_m(x,type)
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
#undef type_fscanf_m

#undef rcore_fscanf_m
#undef core_fscanf_m
#undef checkfopen_m


#define InitRank_m(x) rank_nametxt[x]=#x 
	InitRank_m(0);
	InitRank_m(A);
	InitRank_m(2);
	InitRank_m(3);
	InitRank_m(4);
	InitRank_m(5);
	InitRank_m(6);
	InitRank_m(7);
	InitRank_m(8);
	InitRank_m(9);
	InitRank_m(10);
	InitRank_m(J);
	InitRank_m(Q);
	InitRank_m(K);
}
#undef InitRank_m 

int32_t add_card(eType type,eSuit suit,eRank rank){
	if(stock.num>=CardNum)return 0;
	stock.card[stock.num].type=type;
	stock.card[stock.num].suit=suit;
	stock.card[stock.num].rank=rank;
	stock.num++;
	return 1;
}

void init_card(){
	stock.num=0;
	discard.num=0;
	add_card(Bang,Spade,A);
	add_card(Bang,Heart,Q);
	add_card(Bang,Heart,K);
	add_card(Bang,Heart,A);
	for(int i=1;i<=K;i++)add_card(Bang,Diamond,i);
	for(int i=2;i<=9;i++)add_card(Bang,Club,i);

	for(int i=2;i<=8;i++)add_card(Missed,Spade,i);
	add_card(Missed,Club,A);
	for(int i=10;i<=K;i++)add_card(Missed,Club,i);

	for(int i=6;i<=J;i++)add_card(Beer,Heart,i);

	add_card(Sallon,Heart,5);

	add_card(Wells_Fargo,Heart,3);

	add_card(Diligenza,Spade,9);
	add_card(Diligenza,Spade,9);

	add_card(General_Store,Spade,Q);
	add_card(General_Store,Club,9);

	add_card(Panic,Heart,J);
	add_card(Panic,Heart,Q);
	add_card(Panic,Heart,A);
	add_card(Panic,Diamond,8);

	add_card(Cat_Balou,Heart,K);
	for(int i=9;i<=J;i++)add_card(Cat_Balou,Diamond,i);

	add_card(Gatling,Heart,10);

	add_card(Indians,Diamond,K);
	add_card(Indians,Diamond,A);

	add_card(Duel,Spade,J);
	add_card(Duel,Diamond,Q);
	add_card(Duel,Club,8);

	add_card(Barrel,Spade,Q);
	add_card(Barrel,Spade,K);

	add_card(Scope,Spade,A);

	add_card(Appaloosa,Spade,A);

	add_card(Mustang,Heart,8);

	add_card(Jail,Spade,10);
	add_card(Jail,Spade,J);
	add_card(Jail,Heart,4);

	add_card(Dynamite,Heart,2);

	add_card(Volcanic,Spade,10);
	add_card(Volcanic,Club,10);

	add_card(Schofield,Spade,K);
	add_card(Schofield,Club,J);
	add_card(Schofield,Club,Q);

	add_card(Remington,Club,K);

	add_card(Rev_Carabine,Club,A);

	add_card(Winchedster,Spade,8);

	if(stock.num!=80){printf("added card (%d) != CardNum (%d)\n",stock.num,CardNum);exit(0);}
}

void init_player(){
	srand(time(0));
	PlayerNow=0;
	PlayerHuman=rand()%PlayerNum;
	shuffling();
	eIden player_iden_arr[PlayerMaxNum]={
		Sheriff,
		Outlaw,
		Outlaw,
		Renegade,
		Deputy_Sheriff,
		Outlaw,
		Sheriff
	};
	for(int i=0;i<PlayerMaxNum;i++)player[i].iden=player_iden_arr[i];
	for(int i=0;i<100;i++){
		int32_t x,y;
		x=rand()%PlayerNum;
		while((y=rand()%PlayerNum)==x)1;
		eIden tmp=player[x].iden;
		player[x].iden=player[y].iden;
		player[y].iden=tmp;
	}
	for(int i=0;i<PlayerNum;i++){
		int32_t check=0;
		while(!check){
			check=1;
			player[i].role=rand()%RoleNum;
			for(int j=0;j<i;j++)if(player[i].role==player[j].role)check=0;
		}
		player[i].maxblood=role_blood[player[i].role];
		if(player[i].iden==Sheriff)player[i].maxblood++;
		player[i].blood=player[i].maxblood;
		player[i].alive=1;
		player[i].hand.num=0;
		player[i].equip.num=0;
		for(int j=0;j<player[i].blood;j++)get_last_card(&player[i].hand,&stock);
	}
	Round=1;
}
