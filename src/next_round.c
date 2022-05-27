#include"func.h"

void next_round(){
	while(1){
		PlayerNow=(PlayerNow+1)%PlayerNum;
		if(player[PlayerNow].alive)break;
	}
	Round++;
}
