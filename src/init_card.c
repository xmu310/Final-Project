#include"func.h"
#include<stdlib.h>

int64_t add_card(eType type,eSuit suit,eRank rank){
	static int64_t num=0;
	if(num<CardNum){
		stock_pile[num].type=type;
		stock_pile[num].suit=suit;
		stock_pile[num].rank=rank;
	}
	num++;
	return num;
}

void init_card(){
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

	int64_t total=add_card(0,0,0)-1;
	if(total!=CardNum){printf("added card (%ld) != CardNum (%d)\n",total,CardNum);exit(0);}
}
