#include"func.h"
#include<stdlib.h>
#include<time.h>

void shuffling(sPile *pile){
	srand(time(0));
	for(int i=0;i<pile->num;i++){
		int64_t x,y;
		x=rand()%pile->num;
		while((y=rand()%pile->num)==x)1;
		sCard tmp=pile->card[x];
		pile->card[x]=pile->card[y];
		pile->card[y]=tmp;
	}
}
