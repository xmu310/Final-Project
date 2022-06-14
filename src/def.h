#pragma once
#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

typedef enum _eSuit{Spade,Heart,Diamond,Club}eSuit;
extern char *suit_nametxt[4];

typedef enum _eIden{Sheriff,Deputy_Sheriff,Outlaw,Renegade}eIden;
extern char *iden_nametxt[4];
extern char *iden_helptxt[4];

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
	Willy_the_Kid
}eRole;
extern int32_t role_blood[16];
extern char *role_nametxt[16];
extern char *role_helptxt[16];

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
	Winchedster//blue card end//
}eType;
extern char *type_nametxt[23];
extern char *type_helptxt[23];

typedef enum _eRank{A=1,J=11,Q,K}eRank;
extern char *rank_nametxt[1+13];

typedef struct _sCard{
	eType type;
	eSuit suit;
	eRank rank;
}sCard;
typedef struct _sPile{
	int32_t num;
	sCard card[80];
}sPile;
extern sPile stock;
extern sPile discard;

typedef struct _sPlayer{
	eIden iden;
	eRole role;
	int32_t maxblood;
	int32_t blood;
	int32_t alive;
	sPile hand;
	sPile equip;
}sPlayer;
extern int32_t PlayerNum;
extern int32_t PlayerNow;
extern int32_t PlayerHuman;
extern int32_t PlayerAlive;
extern int32_t AliveArr[4];
extern sPlayer player[7];

extern int32_t Round;
extern int32_t Stage;//0 for determine, 1 for draw cards, 2 for use cards, 3 for discard cards
extern int32_t BangNum;
extern int32_t SleepNum;

typedef enum _eAscii{
	aStart,
	aBomb,
	aExplode,
	aJail,
	aBeer,
	AsciiNum
}eAscii;
