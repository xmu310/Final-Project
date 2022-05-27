#include"func.h"

void print_who_win(){
	if(who_win()==0)printf("The game isn't end.\n");
	if(who_win()==1)printf("The winner is Sheriff and Deputy Sheriff.\n");
	if(who_win()==2)printf("The winner is Outlaw.\n");
	if(who_win()==3)printf("The winner is Renegade.\n");
	printf(">>>>>>>>>>>>>>>>>>\n");
	if(who_win()==1&&(player[PlayerHuman].iden==Sheriff||player[PlayerHuman].iden==Deputy_Sheriff)||
			who_win()==2&&player[PlayerHuman].iden==Outlaw||
			who_win()==3&&player[PlayerHuman].iden==Renegade
			)printf("You win!\n");else printf("You lose\n");
}
