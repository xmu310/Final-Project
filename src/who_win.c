#include"func.h"
int32_t who_win(){
	if(!AliveArr[Sheriff]){
		if(AliveArr[Renegade]&&AliveArr[Deputy_Sheriff]&&AliveArr[Outlaw])return 3;
		return 2;
	}
	if(!AliveArr[Renegade]&&!AliveArr[Outlaw])return 1;
	return 0;
}
