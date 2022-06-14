#include"func.h"
int32_t num_scanf(int32_t *num){
	int32_t re;
	char buf[10000]={0},*endp;
	scanf("%[^\n]",buf);
	scanf("%*c");
	*num=strtol(buf,&endp,10);
	if(!strlen(buf)||*endp)re=0;else re=1;
	return re;
}
