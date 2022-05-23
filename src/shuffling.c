#include"func.h"
#include<stdlib.h>
#include<time.h>

void shuffling(sPile *pile,int64_t card_num){
	srand(time(0));
	for(int i=0;i<card_num;i++){
		int64_t x,y;
		x=rand()%card_num;
		while((y=rand()%card_num)==x)1;
		sPile tmp=pile[x];
		pile[x]=pile[y];
		pile[y]=tmp;
	}
}
