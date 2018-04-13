#ifndef PokeBase_H
#define PokeBase_H

#include <random>
#include <string>
#include <iostream>
#include <fstream>

enum pokemon {
	MISSINGNO, BULBASAUR, IVYSAUR, VENUSAUR, CHARMANDER, CHARMELEON, CHARIZARD, SQUIRTLE, WARTORTLE, BLASTOISE, CATERPIE, METAPOD, BUTTERFREE,
	WEEDLE, KAKUNA, BEEDRILL, PIDGEY, PIDGEOTTO, PIDGEOT, RATTATA, RATICATE, SPEAROW, FEAROW, EKANS, ARBOK, PIKACHU, RAICHU, SANDSHREW, SANDSLASH,
	NIDORAN_F, NIDORINA, NIDOQUEEN, NIDORAN_M, NIDORINO, NIDOKING, CLEFAIRY, CLEFABLE, VULPIX, NINETALES, JIGGLYPUFF, WIGGLYTUFF, ZUBAT, GOLBAT,
	ODDISH, GLOOM, VILEPLUME, PARAS, PARASECT, VENONAT, VENOMOTH, DIGLETT, DUGTRIO, MEOWTH, PERSIAN, PSYDUCK, GOLDUCK, MANKEY, PRIMEAPE, GROWLITHE,
	ARCANINE, POLIWAG, POLIWHIRL, POLIWRATH, ABRA, KADABRA, ALAKAZAM, MACHOP, MACHOKE, MACHAMP, BELLSPROUT, WEEPINBELL, VICTREEBEL, TENTACOOL,
	TENTACRUEL, GEODUDE, GRAVELER, GOLEM, PONYTA, RAPIDASH, SLOWPOKE, SLOWBRO, MAGNEMITE, MAGNETON, FARFETCHD, DODUO, DODRIO, SEEL, DEWGONG,
	GRIMER, MUK, SHELLDER, CLOYSTER, GASTLY, HAUNTER, GENGAR, ONIX, DROWZEE, HYPNO, KRABBY, KINGLER, VOLTORB, ELECTRODE, EXEGGCUTE, EXEGGUTOR,
	CUBONE, MAROWAK, HITMONLEE, HITMONCHAN, LICKITUNG, KOFFING, WEEZING, RHYHORN, RHYDON, CHANSEY, TANGELA, KANGASKHAN, HORSEA, SEADRA, GOLDEEN,
	SEAKING, STARYU, STARMIE, MR_MIME, SCYTHER, JYNX, ELECTABUZZ, MAGMAR, PINSIR, TAUROS, MAGIKARP, GYARADOS, LAPRAS, DITTO, EEVEE, VAPOREON,
	JOLTEON, FLAREON, PORYGON, OMANYTE, OMASTAR, KABUTO, KABUTOPS, AERODACTYL, SNORLAX, ARTICUNO, ZAPDOS, MOLTRES, DRATINI, DRAGONAIR, DRAGONITE,
	MEWTWO, MEW
};

enum experience_group { SLOW = 1, MED_SLOW = 2, MED_FAST = 3, FAST = 4 };

class PokeBase {
public:
	friend class Pokemon;
	friend class Move;
	friend class PokeDex;
	PokeBase();
	void populatePokemon();
	//void populateMoves();
	//void populateLearningMoves();

	static PokeBase* sInstance;
	static PokeBase* Instance();
	static void Release();
private:
	int mP_Pokemon = NIDOKING; //amount to loop/populate
	int mP_Moves = 166;

	//POKEMON
	int mP_pokedex[NIDOKING]; //stores # in pokedex
	std::string mP_name[NIDOKING]; //stores nickname if any

	//Other
	int mP_type1[NIDOKING];
	int mP_type2[NIDOKING];
	std::string mP_type1_str[NIDOKING];
	std::string mP_type2_str[NIDOKING];
	int mP_catchRate[NIDOKING];
	int mP_expYield[NIDOKING];
	int mP_expGroup[NIDOKING]; //part of one of four exp groups
	int mP_evolve[NIDOKING]; //level Pokemon evolves at

	//description
	std::string mP_kind[NIDOKING];
	std::string mP_height[NIDOKING];
	float mP_weight[NIDOKING];
	std::string mP_description[NIDOKING];

	//static stats
	int mP_baseHP[NIDOKING];
	int mP_baseAtk[NIDOKING];
	int mP_baseDef[NIDOKING];
	int mP_baseSpd[NIDOKING];
	int mP_baseSpe[NIDOKING];

	////MOVES
	//int mP_moveID[166];
	//std::string mP_moveName[166];
	//int mP_moveType[166];		//Normal, Fire, etc.
	//std::string mP_moveType_str[166];
	//int mP_moveCat[166];		//Physical, Special or Status
	//int mP_movePower[166];		//Base Power
	//int mP_moveAcc[166];		//Accuracy
	//int mP_movePPMax[166];		//Max PP of move
	//int mP_moveEffect[166];		//Status effect
	//int mP_moveChance[166];		//Chance for status
	//int mP_movePriority[166];

	//int mP_numMoves[151]; //number of moves they can learn from leveing
	//int mP_learnLevel[151][10]; //levels moves will be learned
	//int mP_moveToLearn[151][10]; //moves to be learnt
};

#endif