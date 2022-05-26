#include"func.h"
#include<stdlib.h>
#include<string.h>

int32_t num_scanf(int32_t *num){
	int32_t re;
	char buf[10000]={0},*endp;
	scanf("%[^\n]",buf);
	scanf("\n");
	*num=strtol(buf,&endp,10);
	if(!strlen(buf)||*endp)re=0;else re=1;
	return re;
}
