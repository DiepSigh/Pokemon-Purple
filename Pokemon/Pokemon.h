#ifndef POKEMON_H
#define POKEMON_H

//Resources:
//EXP Yield: https://bulbapedia.bulbagarden.net/wiki/List_of_Pok%C3%A9mon_by_effort_value_yield_(Generation_III-IV)
//Data Structure: https://bulbapedia.bulbagarden.net/wiki/Pok%C3%A9mon_data_structure_in_Generation_I
//Base Stats: https://bulbapedia.bulbagarden.net/wiki/List_of_Pok%C3%A9mon_by_base_stats_(Generation_I)


// Base of Pokémon
#include <string>

enum pokemon_type { NORMAL=0, FIGHTING=1, FLYING=2, POISON=3, GROUND=4, ROCK=5, BUG=7, GHOST=8, BLANK=9, FIRE=14, WATER=15, GRASS=16, ELECTRIC=17, PSYCHIC=18, ICE=19, DRAGON=20 };

enum pokemon {MISSINGNO, BULBASAUR, IVYSAUR, VENUSAUR, CHARMANDER, CHARMELEON, CHARIZARD, SQUIRTLE, WARTORTLE, BLASTOISE, CATERPIE, METAPOD, BUTTERFREE,
	  WEEDLE, KAKUNA, BEEDRILL, PIDGEY, PIDGEOTTO, PIDGEOT, RATTATA, RATICATE, SPEAROW, FEAROW, EKANS, ARBOK, PIKACHU, RAICHU, SANDSHREW, SANDSLASH,  
	  NIDORAN_F, NIDORINA, NIDOQUEEN, NIDORAN_M, NIDORINO, NIDOKING, CLEFAIRY, CLEFABLE, VULPIX, NINETALES, JIGGLYPUFF, WIGGLYTUFF, ZUBAT, GOLBAT,  
	  ODDISH, GLOOM, VILEPLUME, PARAS, PARASECT, VENONAT, VENOMOTH, DIGLETT, DUGTRIO};

class Pokemon {
public:
	Pokemon();
	Pokemon(int pokemon, int level);
	const void getPokemon(int pokemon);
	void setIV();
	void setStats();
	const void displayStats();

protected:
	int m_pokedex; //stores # in pokedex
	std::string m_name; //stores nickname if any

	const int m_MAX_EV = 65535;



	//dynamic stats
	int m_level;
	int m_hp;
	int m_att;
	int m_def;
	int m_spd;
	int m_spe;
	int m_exp;

	//IV
	int m_IV_hp;
	int m_IV_att;
	int m_IV_def;
	int m_IV_spd;
	int m_IV_spe;

	//EV
	int m_EV_hp;
	int m_EV_att;
	int m_EV_def;
	int m_EV_spd;
	int m_EV_spe;

	//static stats
	int m_baseHP;
	int m_baseAtk;
	int m_baseDef;
	int m_baseSpd;
	int m_baseSpe;

	int m_type1;
	int m_type2;
	int m_catchRate;
	int m_expYield;
};

#endif // !POKEMON_H