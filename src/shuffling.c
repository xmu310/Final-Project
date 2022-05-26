#include"func.h"
#include<stdlib.h>
#include<time.h>

void shuffling(){
	srand(time(0));
	combine_pile(&stock,&discard);
	for(int i=0;i<stock.num;i++){
		int32_t x,y;
		x=rand()%stock.num;
		while((y=rand()%stock.num)==x)1;
		sCard tmp=stock.card[x];
		stock.card[x]=stock.card[y];
		stock.card[y]=tmp;
	}
}
