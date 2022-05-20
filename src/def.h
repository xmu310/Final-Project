#pragma once
#include<stdint.h>

#define RankNum 13

typedef enum _eSuit{
	Spade,
	Heart,
	Diamond,
	Club,
	SuitNum//4
}eSuit;

typedef enum _eIden{
	Sheriff,
	Deputy_Sheriff,
	Outlaw,
	Renegade,
	IdenNum//4
}eIden;

typedef enum _eRole{
	Bart_Cassidy,
	Black_Jack,
	Calamity_Janet,
	El_Gringo,
	Jesse_Jones,
	Jourdonnais,
	Kit_Carlson,
	Lucky_Duke,
	Paul_Regret,
	Pedro_Ramirez,
	Rose_Doolan,
	Sid_Ketchum,
	Slab_the_Killer,
	Suzy_Lafayette,
	Vulture_Sam,
	Willy_the_Kid,
	RoleNum//16
}eRole;

typedef enum _eType{
	Bang,//yellow card start//
	Missed,
	Beer,
	Sallon,
	Wells_Fargo,
	Diligenza,
	General_Store,
	Panic,
	Cat_Balou,
	Gatling,
	Indians,
	Duel,//yellow card end//
	
	Barrel,//blue card start//
	Scope,
	Appaloosa,
	Mustang,
	Jail,
	Dynamite,
	Volcanic,
	Schofield,
	Remington,
	Rev_Carabine,
	Winchedster,//blue card end//
	TypeNum//23
}eType;

extern char *iden_nametxt[IdenNum];
extern char *iden_helptxt[IdenNum];
extern int64_t role_blood[RoleNum];
extern char *role_nametxt[RoleNum];
extern char *role_helptxt[RoleNum];
extern char *type_nametxt[TypeNum];
extern char *type_helptxt[TypeNum];

typedef struct _sPile{
	eType type;
	eSuit suit;
	int64_t rank;
}sPile;

#define CardNum 80

extern sPile stock_pile[CardNum];
extern sPile discard_pile[CardNum];

typedef struct _sPlayer{
	eIden iden;
	eRole role;
	int64_t blood;
	int64_t hand[TypeNum][SuitNum][RankNum];
	int64_t effect[TypeNum][SuitNum][RankNum];
}sPlayer;

extern int64_t PlayerNum;
extern sPlayer *player;//It'll be sPlayer player[PlayerNum]
