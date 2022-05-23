#include"func.h"

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
	for(int i=1;i<=13;i++)add_card(Bang,Diamond,i);
	for(int i=2;i<=9;i++)add_card(Bang,Club,i);
	for(int i=2;i<=8;i++)add_card(Missed,Spade,i);

	printf("Added card num:%ld/%d\n",add_card(0,0,0)-1,CardNum);
}
