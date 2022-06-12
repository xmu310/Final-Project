#include"func.h"
#include<stdlib.h>


void end_game()
{
	//MEOW >.< I LOVE U
	for(int i=0;i<IdenNum;i++)
	{
		free(iden_nametxt[i]);
		free(iden_helptxt[i]);
	}
	for(int i=0;i<RoleNum;i++)
	{
		free(role_nametxt[i]);
		free(role_helptxt[i]);
	}
	for(int i=0;i<TypeNum;i++)
	{
		free(type_nametxt[i]);
		free(type_helptxt[i]);
	}
	


}
