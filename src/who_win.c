#include"func.h"

int32_t who_win(){
	if(!SheriffAlive){
		if(RenegadeAlive&&!DeputySheriffAlive&&!OutlawAlive)return 3;
		return 2;
	}
	if(!RenegadeAlive&&!OutlawAlive)return 1;
	return 0;
}
