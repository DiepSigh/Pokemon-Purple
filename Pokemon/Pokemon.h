#ifndef POKEMON_H
#define POKEMON_H

//Resources:
//Data Structure: https://bulbapedia.bulbagarden.net/wiki/Pok%C3%A9mon_data_structure_in_Generation_I
//Base Stats: https://bulbapedia.bulbagarden.net/wiki/List_of_Pok%C3%A9mon_by_base_stats_(Generation_I)
//EXP Yield: https://bulbapedia.bulbagarden.net/wiki/List_of_Pok%C3%A9mon_by_effort_value_yield_(Generation_III-IV)
//Catch Rate: https://bulbapedia.bulbagarden.net/wiki/List_of_Pok%C3%A9mon_by_catch_rate

// Base of Pokémon
#include <string>
#include "moves.h"

enum pokemon {MISSINGNO, BULBASAUR, IVYSAUR, VENUSAUR, CHARMANDER, CHARMELEON, CHARIZARD, SQUIRTLE, WARTORTLE, BLASTOISE, CATERPIE, METAPOD, BUTTERFREE,
	  WEEDLE, KAKUNA, BEEDRILL, PIDGEY, PIDGEOTTO, PIDGEOT, RATTATA, RATICATE, SPEAROW, FEAROW, EKANS, ARBOK, PIKACHU, RAICHU, SANDSHREW, SANDSLASH,  
	  NIDORAN_F, NIDORINA, NIDOQUEEN, NIDORAN_M, NIDORINO, NIDOKING, CLEFAIRY, CLEFABLE, VULPIX, NINETALES, JIGGLYPUFF, WIGGLYTUFF, ZUBAT, GOLBAT,  
	  ODDISH, GLOOM, VILEPLUME, PARAS, PARASECT, VENONAT, VENOMOTH, DIGLETT, DUGTRIO, MEOWTH, PERSIAN, PSYDUCK, GOLDUCK, MANKEY, PRIMEAPE, GROWLITHE,  
	  ARCANINE, POLIWAG, POLIWHIRL, POLIWRATH, ABRA, KADABRA, ALAKAZAM, MACHOP, MACHOKE, MACHAMP, BELLSPROUT, WEEPINBELL, VICTREEBEL, TENTACOOL,  
	  TENTACRUEL, GEODUDE, GRAVELER, GOLEM, PONYTA, RAPIDASH, SLOWPOKE, SLOWBRO, MAGNEMITE, MAGNETON, FARFETCHD, DODUO, DODRIO, SEEL, DEWGONG,  
	  GRIMER, MUK, SHELLDER, CLOYSTER, GASTLY, HAUNTER, GENGAR, ONIX, DROWZEE, HYPNO, KRABBY, KINGLER, VOLTORB, ELECTRODE, EXEGGCUTE, EXEGGUTOR,  
	  CUBONE, MAROWAK, HITMONLEE, HITMONCHAN, LICKITUNG, KOFFING, WEEZING, RHYHORN, RHYDON, CHANSEY, TANGELA, KANGASKHAN, HORSEA, SEADRA, GOLDEEN,  
	  SEAKING, STARYU, STARMIE, MR_MIME, SCYTHER, JYNX, ELECTABUZZ, MAGMAR, PINSIR, TAUROS, MAGIKARP, GYARADOS, LAPRAS, DITTO, EEVEE, VAPOREON,  
	  JOLTEON, FLAREON, PORYGON, OMANYTE, OMASTAR, KABUTO, KABUTOPS, AERODACTYL, SNORLAX, ARTICUNO, ZAPDOS, MOLTRES, DRATINI, DRAGONAIR, DRAGONITE,  
	  MEWTWO, MEW};

enum pokemon_type { NORMAL=0, FIGHTING=1, FLYING=2, POISON=3, GROUND=4, ROCK=5, BUG=7, GHOST=8, BLANK=9, FIRE=14, WATER=15, GRASS=16, ELECTRIC=17, PSYCHIC=18, ICE=19, DRAGON=20 };

enum pokemon_status { OK=0, BURNED=1, FROZEN=2, PARALYZED=3, POISONED=4, BADLY_POISONED=5, ASLEEP=6 };

enum experience_group { SLOW=1, MED_SLOW=2, MED_FAST=3, FAST=4 };

const int MAX_EV = 65535;

class Pokemon {
public:
	Pokemon();
	Pokemon(int pokemon, int level);
	const void getPokemon(int pokemon);
	void setIV();
	void emptyEV();
	int typeConvert(std::string t);
	void setStats();
	void expCalculator(int group);
	const void displayStats();

protected:
	int m_pokedex; //stores # in pokedex
	std::string m_nickname; //stores nickname if any
	int m_level;
	int m_status;
	int m_exp;
	Move move[4];
	//bool m_seen;

	//Other
	int m_type1;
	int m_type2;
	std::string m_type1_str;
	std::string m_type2_str;
	int m_catchRate;
	int m_expYield;
	int m_expGroup;

	//description
	std::string m_kind;
	std::string m_height;
	float m_weight;
	std::string m_description;

	//dynamic stats
	int m_hp;
	int m_atk;
	int m_def;
	int m_spd;
	int m_spe;

	//IV
	int m_IV_hp;
	int m_IV_atk;
	int m_IV_def;
	int m_IV_spd;
	int m_IV_spe;

	//EV
	int m_EV_hp;
	int m_EV_atk;
	int m_EV_def;
	int m_EV_spd;
	int m_EV_spe;

	//static stats
	int m_baseHP;
	int m_baseAtk;
	int m_baseDef;
	int m_baseSpd;
	int m_baseSpe;

};

#endif // !POKEMON_H