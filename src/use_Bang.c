#include"func.h"
void use_Bang(int32_t card_index){
	int32_t be_attacked_player=0,player_index,num,missnum=0;
	char *str[2]={"once","twice"};
	if(BangNum!=0&&player[PlayerNow].role!=Willy_the_Kid&&!have_card(player[PlayerNow].equip,Volcanic)){
		printf("Bang can not use twice!(unless you are Willy the Kid or you have Volcanic)\n");	
	}
	for(int i=0;i<PlayerNum;i++){
		if(i==PlayerNow||!player[i].alive)continue;
		if(distance(PlayerNow,i)<=weapon_distance())be_attacked_player++;
	}
	if(be_attacked_player==0){
		printf("Because no player in the weapon distance %d, you can't use this card!\n",weapon_distance());
		return;
	}
	BangNum++;
	get_card(&discard,&player[PlayerNow].hand,card_index);
	if(PlayerNow==PlayerHuman){
		printf("Which player do you want to attack (enter player index):");
		while(1){
			if(!num_scanf(&player_index)||player_index<1||player_index>PlayerNum){
				printf("Error!\n");
				printf("Please enter again!\n\n");
				continue;
			}
			player_index--;
			if(player_index==PlayerNow||!player[player_index].alive){
				printf("You can't choose yourself or dead player!\n");
				printf("Please enter again!\n\n");
				continue;
			}
			if(distance(PlayerNow,player_index)>weapon_distance()){
				printf("The distance between you and Player%d is %d ( > weapon distance %d), so you can't choose him/her!\n",player_index+1,distance(PlayerNow,player_index),weapon_distance());
				printf("Please enter again!\n\n");
				continue;
			}else break;
		}
	}else{
		while(1){
			player_index=rand()%PlayerNum;
			if(player_index==PlayerNow||!player[player_index].alive){
				continue;
			}
			if(distance(PlayerNow,player_index)>weapon_distance()){
				continue;
			}else break;
		}
	}
	if(player[PlayerNow].role!=Slab_the_Killer){
		if(player[player_index].role==Jourdonnais){
			printf("Because player%d is Jourdonnais, he/she has built-in barrel.\n",player_index+1);	
			if(det(player_index).suit==Heart){
				printf("Determination success!\n");
				printf("Player%d missed successfully!\n",player_index+1);
				return;
			}else{
				printf("Determination failed!\n");
			}
		}
		if(find_card_index(player[player_index].equip,Barrel,&num)){
			printf("Player%d uses a \"Barrel\".\n",player_index+1);	
			if(det(player_index).suit==Heart){
				printf("Determination success!\n");
				printf("Player%d missed successfully!\n",player_index+1);
				return;
			}else{
				printf("Determination failed!\n");
			}
		}
		if(find_card_index(player[player_index].hand,Missed,&num)){
			get_card(&discard,&player[player_index].hand,num);
			printf("Player%d uses a \"Missed\".\n",player_index+1);				
			printf("Player%d missed successfully!\n",player_index+1);
		}else if(player[player_index].role==Calamity_Janet&&find_card_index(player[player_index].hand,Bang,&num)){
			get_card(&discard,&player[player_index].hand,num);
			printf("Because player%d is Calamity Janet, he/she can use a \"Bang\" as \"Missed\"\n",player_index+1);	
			printf("Player%d missed successfully!\n",player_index+1);
		}else{
			printf("Player%d have no \"Missed\".\n",player_index+1);
			player_minus_blood(PlayerNow,player_index);
		}
	}else{
		printf("Because player%d is Slab the Killer, player being attacked should missed twice successfully.\n",PlayerNow+1);	
		if(player[player_index].role==Jourdonnais){
			printf("Because player%d is Jourdonnais, he/she has built-in barrel.\n",player_index+1);	
			if(det(player_index).suit==Heart){
				printf("Determination success!\n");
				missnum++;
				printf("Player%d missed %s successfully!\n",player_index+1,str[missnum-1]);
			}else{
				printf("Determination failed!\n");
			}
		}
		if(find_card_index(player[player_index].equip,Barrel,&num)){
			printf("Player%d uses a \"Barrel\".\n",player_index+1);	
			if(det(player_index).suit==Heart){
				printf("Determination success!\n");
				missnum++;
				printf("Player%d missed %s successfully!\n",player_index+1,str[missnum-1]);
			}else{
				printf("Determination failed!\n");
			}
		}
		while(missnum<2){
			if(find_card_index(player[player_index].hand,Missed,&num)){
				get_card(&discard,&player[player_index].hand,num);
				printf("Player%d uses a \"Missed\".\n",player_index+1);				
				printf("Player%d missed %s successfully!\n",player_index+1,str[missnum-1]);
			}else if(player[player_index].role==Calamity_Janet&&find_card_index(player[player_index].hand,Bang,&num)){
				get_card(&discard,&player[player_index].hand,num);
				printf("Because player%d is Calamity Janet, he/she can use a \"Bang\" as \"Missed\"\n",player_index+1);	
				printf("Player%d missed %s successfully!\n",player_index+1,str[missnum-1]);
			}else{
				printf("Player%d have no \"Missed\".\n",player_index+1);
				player_minus_blood(PlayerNow,player_index);
				return;
			}
		}
	}
}
