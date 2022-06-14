#include"func.h"
void use_card(int32_t card_index){
	if(player[PlayerNow].hand.card[card_index].type==Missed&&player[PlayerNow].role==Calamity_Janet){
		use_Bang(card_index);
		return;
	}
#define buildif(x) if(player[PlayerNow].hand.card[card_index].type==x){use_##x(card_index);return;}
	buildif(Bang)
	buildif(Beer)
	buildif(Sallon)
	buildif(Wells_Fargo)
	buildif(Diligenza)
	buildif(General_Store)
	buildif(Panic)
	buildif(Cat_Balou)
	buildif(Gatling)
	buildif(Indians)
	buildif(Duel)
	buildif(Barrel)
	buildif(Scope)
	buildif(Appaloosa)
	buildif(Mustang)
	buildif(Jail)
	buildif(Dynamite)
	buildif(Volcanic)
	buildif(Schofield)
	buildif(Remington)
	buildif(Rev_Carabine)
	buildif(Winchedster)
#undef buildif
}
