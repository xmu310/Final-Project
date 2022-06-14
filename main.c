#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<time.h>
#include"src/def.h"
#include"src/func.h"
int main(int argc,char* argv[]){
	int32_t num,discard_num,loop,big_loop;
	char c,cc;
	SleepNum=1;
	while((c=getopt(argc,argv,"s:"))!=-1){
		if(c=='s'){
			if(sscanf(optarg,"%d%c",&SleepNum,&cc)!=1){printf("Error\n");return 0;}
			if(SleepNum<0||SleepNum>3){printf("sleep number only allowed 0-3 (0 for press enter to continue)\n");return 0;}
		}else{printf("Error\n");return 0;}
	}
	srand(time(0));
	while(1){
		system("clear");
		print_ascii(aStart);
		printf("Please enter the player number(4-7): ");
		if(num_scanf(&PlayerNum,4,7))break;
		sleep(1);
	}
	set_game();
	for(Round=1;!who_win();Round++){
		while(1){
			PlayerNow=(PlayerNow+1)%PlayerNum;
			if(player[PlayerNow].alive)break;
		}
		BangNum=0;

		Stage=0;//determine
		print_all_status();
		if(have_card(player[PlayerNow].equip,Dynamite)){
			det_Dynamite();
			if(who_win())break;
			if(!player[PlayerNow].alive)continue;
		}
		if(have_card(player[PlayerNow].equip,Jail)&&det_Jail()==1)continue;

		Stage=1;//draw cards
		print_all_status();
		if(player[PlayerNow].role==Black_Jack)Black_Jack_draw();
		else if(player[PlayerNow].role==Jesse_Jones)Jesse_Jones_draw();
		else if(player[PlayerNow].role==Kit_Carlson)Kit_Carlson_draw();
		else if(player[PlayerNow].role==Pedro_Ramirez)Pedro_Ramirez_draw();
		else get_stock(PlayerNow,2);

		Stage=2;//use cards
		for(big_loop=0;player[PlayerNow].alive&&!who_win()&&big_loop<7;big_loop++){
			print_all_status();
			ask_Suzy_Lafayette(PlayerNow);
			if(player[PlayerNow].hand.num<=0){printf("Player%d has no hand card!\n",PlayerNow+1);break;}
			ask_Sid_Ketchum(PlayerNow);
			if(PlayerNow==PlayerHuman){
				while(1){
					printf("Which hand card do you want to use (enter card index, 0 for skip): ");
					if(num_scanf(&num,0,player[PlayerNow].hand.num)){
						num--;
						if(num==-1)break;
						if(player[PlayerNow].hand.card[num].type!=Missed)break;
						if(player[PlayerNow].role==Calamity_Janet)break;
						printf("You can't not choose Missed!\n");
					}
				}
			}else{
				for(loop=0;;loop++){
					if(loop>7||player[PlayerNow].hand.num<=player[PlayerNow].blood){num=-1;break;}
					num=rand()%player[PlayerNow].hand.num;
					if(player[PlayerNow].hand.card[num].type!=Missed)break;
					if(player[PlayerNow].role==Calamity_Janet)break;
				}
			}
			if(num==-1){printf("Player%d chooses skip!\n",PlayerNow+1);break;}
			printf("Player%d uses %d. %s\n",PlayerNow+1,num+1,type_nametxt[player[PlayerNow].hand.card[num].type]);
			if(player[PlayerNow].hand.card[num].type==Missed&&player[PlayerNow].role==Calamity_Janet){
					printf("Because player%d is Calamity Janet, his/her Missed changed to Bang.\n",PlayerNow+1);
			}
			use_card(num);
		}
		if(who_win())break;
		if(!player[PlayerNow].alive)continue;

		Stage=3;//discard cards
		discard_num=0;
		while(1){
			print_all_status();
			ask_Suzy_Lafayette(PlayerNow);
			if(player[PlayerNow].hand.num<=0){printf("Player%d has no hand card!\n",PlayerNow+1);break;}
			if(PlayerNow==PlayerHuman){
				while(1){
					printf("Which hand card do you want to discard (enter card index, 0 for skip): ");
					if(num_scanf(&num,0,player[PlayerNow].hand.num)){
						num--;
						if(num!=-1)break;
						if(player[PlayerNow].hand.num<=player[PlayerNow].blood)break;
						printf("Because your hand card's number > your blood, you are not allowed to skip!\n");
					}
				}
			}else{
				if(player[PlayerNow].hand.num>player[PlayerNow].blood){
					num=rand()%player[PlayerNow].hand.num;
				}else num=-1;
			}
			if(num==-1){printf("Player%d chooses skip!\n",PlayerNow+1);break;}
			get_card(&discard,&player[PlayerNow].hand,num);
			printf("Player%d discards a card to discard pile.\n",PlayerNow+1);
			if(player[PlayerNow].role==Sid_Ketchum){
				discard_num++;
				if(discard_num>=2){
					discard_num-=2;
					printf("Because Player%d's role is Sid Ketchum, and he/she has discarded two cards, his/her blood can +1.\n",PlayerNow+1);
					player_plus_blood(PlayerNow);
				}
			}
		}
	}
	printf(">>>>>>>>>>>>>>>>>>\n");
	if(who_win()==1)printf("The winner is Sheriff and Deputy Sheriff.\n");
	if(who_win()==2)printf("The winner is Outlaw.\n");
	if(who_win()==3)printf("The winner is Renegade.\n");
	printf(">>>>>>>>>>>>>>>>>>\n");
	if(player[PlayerHuman].iden==who_win()||(who_win()==1&&player[PlayerHuman].iden==Sheriff)){
		printf("You win!\n");
	}else printf("You lose\n");
	return 0;
}
