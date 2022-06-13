#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<time.h>
#include"src/def.h"
#include"src/func.h"
int main(){
	int32_t num,discard_num;
	srand(time(0));
	while(1){
		system("clear");
		printf("Please enter the player number(4-7, Exit:0): ");
		if(!num_scanf(&num)){
			printf("Not integer!\n");
		}else if(!num){
			return 0;
		}else if(num<4||num>7){
			printf("number should be in 4 to 7\n");
		}else break;
		sleep(1);
	}
	if(!set_game(num)){printf("Error!\n");return 0;}
	while(1){
		Stage=0;//determine
		print_all_status();
		if(have_card(player[PlayerNow].equip,Dynamite)){
			det_Dynamite();
			if(!player[PlayerNow].alive){
				next_round();
				continue;
			}
		}
		if(have_card(player[PlayerNow].equip,Jail)){
			if(det_Jail()==1){
				next_round();
				continue;
			}
		}

		Stage=1;//draw cards
		print_all_status();
		if(player[PlayerNow].role==Black_Jack){
			Black_Jack_draw();
		}else if(player[PlayerNow].role==Jesse_Jones){
			Jesse_Jones_draw();
		}else if(player[PlayerNow].role==Kit_Carlson){
			Kit_Carlson_draw();
		}else if(player[PlayerNow].role==Pedro_Ramirez){
			Pedro_Ramirez_draw();
		}else{
			get_stock(PlayerNow);
			printf("Player%d gets a card from stock pile.\n",PlayerNow+1);
			get_stock(PlayerNow);
			printf("Player%d gets a card from stock pile.\n",PlayerNow+1);
		}

		Stage=2;//use cards
		while(1){
			print_all_status();
			ask_Suzy_Lafayette(PlayerNow);
			if(player[PlayerNow].hand.num<=0){
				printf("Player%d has no hand card!\n",PlayerNow+1);
				break;
			}
			ask_Sid_Ketchum(PlayerNow);
			if(PlayerNow==PlayerHuman){
				printf("Which hand card do you want to use (enter card index, -1 for skip): ");
				while(1){
					if(!num_scanf(&num)||num<1&&num!=-1||num>player[PlayerNow].hand.num){
						printf("Error\n");
						continue;
					}
					if(num==-1)break;
					num--;
					if(player[PlayerNow].hand.card[num].type==Missed){
						if(player[PlayerNow].role==Calamity_Janet)break;
						printf("You can't not choose Missed!\n");
						continue;
					}else break;
				}
			}else{
				while(1){
					if(!(rand()%3)){
						num=-1;
						break;
					}else{
						num=rand()%player[PlayerNow].hand.num;
						if(player[PlayerNow].hand.card[num].type==Missed){
							if(player[PlayerNow].role==Calamity_Janet)break;
							continue;
						}else break;
					}
				}
			}
			if(num==-1){
				printf("Player%d chooses skip!\n",PlayerNow+1);
				break;
			}
			printf("Player%d uses %d. %s\n",PlayerNow+1,num+1,type_nametxt[player[PlayerNow].hand.card[num].type]);
			if(player[PlayerNow].hand.card[num].type==Missed&&player[PlayerNow].role==Calamity_Janet){
					printf("Because you are Calamity Janet, your Missed changed to Bang.\n");
			}
			use_card(num);
			if(!player[PlayerNow].alive)break;
		}
		if(!player[PlayerNow].alive){
			next_round();
			continue;
		}

		Stage=3;//discard cards
		discard_num=0;
		while(1){
			print_all_status();
			ask_Suzy_Lafayette(PlayerNow);
			if(player[PlayerNow].hand.num<=0){
				printf("Player%d has no hand card!\n",PlayerNow+1);
				break;
			}
			if(PlayerNow==PlayerHuman){
				printf("Which hand card do you want to discard (enter card index, -1 for skip): ");
				while(1){
					if(!num_scanf(&num)||num<1&&num!=-1||num>player[PlayerNow].hand.num){
						printf("Error\n");
						continue;
					}
					if(num==-1){
						if(player[PlayerNow].hand.num>player[PlayerNow].blood){
							printf("Because your hand card's number is bigger than your blood, you are not allowed to skip!\n");
							continue;
						}else break;
					}
					num--;
					break;
				}
			}else{
				while(1){
					if(rand()%2){
						num=-1;
						if(player[PlayerNow].hand.num>player[PlayerNow].blood)continue;else break;
					}else{
						num=rand()%player[PlayerNow].hand.num;
						break;
					}
				}
			}
			if(num==-1){
				printf("Player%d chooses skip!\n",PlayerNow+1);
				break;
			}
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

		next_round();
	}
	print_who_win();
	end_game();
	return 0;
}
