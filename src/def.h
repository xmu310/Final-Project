#pragma once
#include<stdio.h>
#include<stdint.h>

typedef enum _eSuit{
	Spade,
	Heart,
	Diamond,
	Club,
	SuitNum//4
}eSuit;
extern char *suit_nametxt[SuitNum];

typedef enum _eIden{
	Sheriff,
	Deputy_Sheriff,
	Outlaw,
	Renegade,
	IdenNum//4
}eIden;
extern char *iden_nametxt[IdenNum];
extern char *iden_helptxt[IdenNum];

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
extern int64_t role_blood[RoleNum];
extern char *role_nametxt[RoleNum];
extern char *role_helptxt[RoleNum];

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
extern char *type_nametxt[TypeNum];
extern char *type_helptxt[TypeNum];

typedef enum _eRank{
	A=1,
	J=11,
	Q,
	K
}eRank;
#define RankNum 13
extern char *rank_nametxt[RankNum+1];

typedef struct _sCard{
	eType type;
	eSuit suit;
	eRank rank;
}sCard;
#define CardNum 80
typedef struct _sPile{
	int64_t num;
	sCard card[CardNum];
}sPile;
extern sPile stock;
extern sPile discard;

typedef struct _sPlayer{
	eIden iden;
	eRole role;
	int64_t blood;
	int64_t alive;
	sPile hand;
	sPile equip;
	int64_t state;
}sPlayer;
#define PlayerMaxNum 7
extern int64_t PlayerNum;
extern int64_t PlayerNow;
extern int64_t PlayerHuman;
extern sPlayer player[PlayerMaxNum];
