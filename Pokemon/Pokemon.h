//Stephen

//Resources:
//Data Structure: https://bulbapedia.bulbagarden.net/wiki/Pok%C3%A9mon_data_structure_in_Generation_I
//Base Stats: https://bulbapedia.bulbagarden.net/wiki/List_of_Pok%C3%A9mon_by_base_stats_(Generation_I)
//EXP Yield: https://bulbapedia.bulbagarden.net/wiki/List_of_Pok%C3%A9mon_by_effort_value_yield_(Generation_III-IV)
//Catch Rate: https://bulbapedia.bulbagarden.net/wiki/List_of_Pok%C3%A9mon_by_catch_rate
#ifndef POKEMON_H
#define POKEMON_H

#include "PokeBase.h"
#include "gameEntity.h"
#include "moves.h"
#include <math.h>

enum pokemon_status { OK=0, FROZEN=1, PARALYZED=2, POISONED=3, BADLY_POISONED=4, BURNED = 5, ASLEEP=6 };

const int MAX_EV = 65535;

class Pokemon : public GameEntity {
public:
	Pokemon();
	Pokemon(int pokemon, int level);
	~Pokemon();
	void retrievePokemon(int pokemon); //Grabs data from PokeBase class to Pokemon variables
	void retrieveMoves(int pokemon); //Stores learnable moves at levels in m_learnLevel[] and m_moveToLearn[]
	void setIV(); //Sets IV's randomly
	void emptyEV(); //Sets all EV's to 0
	void setStats(); //Sets stats of Pokemon based on IV's, current EV's, and level
	void setMoves(int pokemon, int level); //Sets 4 learnables moves based on level or less
	void setEXP(); //Sets EXP of Pokemon based on level; should only be called when new Pokemon is created
	void gainEXP(Pokemon &);
	void levelUP();
	void gainEVs(Pokemon &);
	void displayMoves();
	void displayStats();
	void displayStats2();

	//Battle
	void hurt(int damage);
	void heal(int amount);
	void resetStatStages(); //Resets stages of stats for battles
	inline void awake() { m_status = OK; m_sleepCount = 0; }
	inline void asleep() { m_sleepCount++; }
	inline void cured() { m_status = OK; m_poisonCount = 0; }
	inline void poison() { m_poisonCount++; }
	inline void resetConfused() { setConfused(false); m_confusedCount = 0; }
	inline void confused() { m_confusedCount++; }
	inline void fainted() { m_fainted = true; m_hp = 0; m_status = OK; }
	inline void restored() { m_fainted = false; m_hp = m_maxHP; }
	void useMove(int num) { move[num].useMove(); } //uses move's PP

	//Getters
	inline bool getSeen() { return m_seen; }
	inline int getSeenCount() { return m_seenCount; }
	inline std::string getName() { return m_nickname; }
	inline Move getMove(int k) { return move[k]; }
	inline int getLevel() { return m_level; }
	inline int getStatus() { return m_status; }
	inline bool getFainted() { return m_fainted; }
	inline int getHP() { return m_hp; }
	inline int getMaxHP() { return m_maxHP; }
	inline int getAtk() { return m_atk; }
	inline int getDef() { return m_def; }
	inline int getSpd() { return m_spd; }
	inline int getSpe() { return m_spe; }
	inline int getType1() { return m_type1; }
	inline int getType2() { return m_type2; }

	inline int getBaseSpd() { return m_baseSpd; }
	inline int getEXPYield() { return m_expYield; }

	inline int getAtkStage() { return m_atkStage; }
	inline int getDefStage() { return m_defStage; }
	inline int getSpdStage() { return m_spdStage; }
	inline int getSpeStage() { return m_speStage; }
	inline int getAccStage() { return m_accStage; }
	inline int getEvaStage() { return m_evaStage; }

	inline bool getBounded() { return m_bounded; }
	inline bool getConfused() { return m_confused; }
	inline int getConfusedCount() { return m_confusedCount; }
	inline bool getFlinched() { return m_flinched; }
	inline bool getSeeded() { return m_seeded; }

	inline int getSleepCount() { return m_sleepCount; }
	inline int getPoisonCount() { return m_poisonCount; }

	//Setters
	inline void setStatus(int status) { m_status = status; }

	inline void setAtkStage(int stage) { m_atkStage += stage; }
	inline void setDefStage(int stage) { m_defStage += stage; }
	inline void setSpdStage(int stage) { m_spdStage += stage; }
	inline void setSpeStage(int stage) { m_speStage += stage; }
	inline void setAccStage(int stage) { m_accStage += stage; }
	inline void setEvaStage(int stage) { m_evaStage += stage; }

	inline void setBounded(bool state) { m_bounded = state; }
	inline void setConfused(bool state) { m_confused = state; }
	inline void setFlinched(bool state) { m_flinched = state; }
	inline void setSeeded(bool state) { m_seeded = state; }

	//Rendering / Sprites
	Pokemon(int, int, Texture*);
	Pokemon* getFront() { return m_frontSprite; } //112x112
	Pokemon* getBack() { return m_backSprite; } //256x256
	void Render();

protected:
	Pokemon *m_frontSprite = nullptr;
	int m_frontX;
	int m_frontY;
	Pokemon *m_backSprite = nullptr;
	int m_backX;
	int m_backY;

	PokeBase *Pokebase = nullptr;
	Graphics *mGraphics = nullptr;
	AssetManager *mAssetManager = nullptr;

	int m_pokedex; //stores # in pokedex
	bool m_seen;
	int m_seenCount = 0;
	std::string m_nickname; //stores nickname if any
	int m_level;
	int m_status; //poisoned, paralyzed, non-volatile status
	bool m_fainted;
	int m_exp; //current amount of exp
	Move move[4];

	//Other
	int m_type1;
	int m_type2;
	std::string m_type1_str;
	std::string m_type2_str;
	int m_catchRate;
	int m_expYield; //used for calculating how much exp they give
	int m_expGroup; //part of one of four exp groups
	int m_evolve; //level Pokemon evolves at

	//description
	std::string m_kind;
	std::string m_height;
	float m_weight;
	std::string m_description;

	//moves
	int m_numMoves; //number of moves they can learn from leveing
	int m_learnLevel[10]; //levels moves will be learned
	int m_moveToLearn[10]; //moves to be learnt

	int m_maxHP;
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

	//stat stages for battle
	int m_atkStage;
	int m_defStage;
	int m_spdStage;
	int m_speStage;
	int m_accStage;
	int m_evaStage;

	//more battle stuff
	bool m_bounded;
	bool m_confused;
	int m_confusedCount;
	bool m_flinched;
	bool m_seeded;

	int m_sleepCount;
	int m_poisonCount;
};

#endif // !POKEMON_H