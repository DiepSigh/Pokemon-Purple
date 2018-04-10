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
	void populateMoves();
	void populateLearningMoves();

	static PokeBase* sInstance;
	static PokeBase* Instance();
	static void Release();
private:
	int mP_Pokemon = 151; //amount to loop/populate
	int mP_Moves = 166;

	//POKEMON
	int mP_pokedex[151]; //stores # in pokedex
	std::string mP_name[151]; //stores nickname if any

	//Other
	int mP_type1[151];
	int mP_type2[151];
	std::string mP_type1_str[151];
	std::string mP_type2_str[151];
	int mP_catchRate[151];
	int mP_expYield[151];
	int mP_expGroup[151]; //part of one of four exp groups
	int mP_evolve[151]; //level Pokemon evolves at

	//description
	std::string mP_kind[151];
	std::string mP_height[151];
	float mP_weight[151];
	std::string mP_description[151];

	//static stats
	int mP_baseHP[151];
	int mP_baseAtk[151];
	int mP_baseDef[151];
	int mP_baseSpd[151];
	int mP_baseSpe[151];

	//MOVES
	int mP_moveID[166];
	std::string mP_moveName[166];
	int mP_moveType[166];		//Normal, Fire, etc.
	std::string mP_moveType_str[166];
	int mP_moveCat[166];		//Physical, Special or Status
	int mP_movePower[166];		//Base Power
	int mP_moveAcc[166];		//Accuracy
	int mP_movePPMax[166];		//Max PP of move
	int mP_moveEffect[166];		//Status effect
	int mP_moveChance[166];		//Chance for status
	int mP_movePriority[166];

	int mP_numMoves[151]; //number of moves they can learn from leveing
	int mP_learnLevel[151][10]; //levels moves will be learned
	int mP_moveToLearn[151][10]; //moves to be learnt
};

#endif