#include"func.h"
void shuffling(){
	combine_pile(&stock,&discard);
	for(int i=0;i<stock.num;i++){
		int32_t x,y;
		x=rand()%stock.num;
		while((y=rand()%stock.num)==x);
		sCard tmp=stock.card[x];
		stock.card[x]=stock.card[y];
		stock.card[y]=tmp;
	}
}
