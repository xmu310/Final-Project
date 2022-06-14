#include"func.h"
int32_t weapon_distance(){
	int32_t re=1;
	if(have_card(player[PlayerNow].equip,Schofield))re+=1;
	if(have_card(player[PlayerNow].equip,Remington))re+=2;
	if(have_card(player[PlayerNow].equip,Rev_Carabine))re+=3;
	if(have_card(player[PlayerNow].equip,Winchedster))re+=4;
	return re;
}
