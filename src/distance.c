#include"func.h"

int32_t distance(int32_t player1_index,int32_t player2_index){
	int32_t re=0;
	if(player1_index<0||player1_index>PlayerNum)return 0;
	if(player2_index<0||player2_index>PlayerNum)return 0;
	if(!player[player1_index].alive)return 0;
	if(!player[player2_index].alive)return 0;
	if(player1_index==player2_index)return 0;
	for(int i=player1_index;i!=player2_index;i=(i+1)%PlayerNum)if(player[i].alive)re++;
	if(PlayerAlive-re<re)re=PlayerAlive-re;
	if(player[player2_index].role==Paul_Regret)re++;
	if(player[player1_index].role==Rose_Doolan)re--;
	if(have_card(player[player1_index].equip,Scope))re--;
	if(have_card(player[player1_index].equip,Appaloosa))re--;
	if(have_card(player[player2_index].equip,Mustang))re++;
	if(re<1)re=1;
	return re;
}
