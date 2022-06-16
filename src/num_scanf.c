#include"func.h"
int32_t num_scanf(int32_t *num,int32_t lowest,int32_t highest){
	char buf[10000]={0},*endp;
	scanf("%[^\n]",buf);
	scanf("%*c");
	*num=strtol(buf,&endp,10);
	if(!strlen(buf)||*endp){
		printf("Not a number!\n");
		return 0;
	}else if(*num<lowest||*num>highest){
		if(lowest!=highest)printf("Number should be %d to %d!\n",lowest,highest);
		if(lowest==highest)printf("Number can only be %d!\n",lowest);
		return 0;
	}
	return 1;
}
