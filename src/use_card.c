#include"func.h"

void use_card(int32_t card_index){
#define buildif(x) if(player[PlayerNow].hand.card[card_index].type==x)use_##x(card_index)
	buildif(Bang);
	buildif(Beer);
	buildif(Sallon);
	buildif(Wells_Fargo);
	buildif(Diligenza);
	buildif(General_Store);
	buildif(Panic);
	buildif(Cat_Balou);
	buildif(Gatling);
	buildif(Indians);
	buildif(Duel);
	buildif(Barrel);
	buildif(Scope);
	buildif(Appaloosa);
	buildif(Mustang);
	buildif(Jail);
	buildif(Dynamite);
	buildif(Volcanic);
	buildif(Schofield);
	buildif(Remington);
	buildif(Rev_Carabine);
	buildif(Winchedster);
#undef buildif
}
