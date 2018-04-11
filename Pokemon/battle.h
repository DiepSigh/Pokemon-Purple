//Stephen
#ifndef BATTLE_H
#define BATTLE_H

#include "Pokemon.h"

struct battle : public GameEntity{
	enum side { PLAYER = 1, AI = 2 };

	battle();
	void battleMenu();
	//Fighting
	void fight(Pokemon &, Pokemon &);
	int AIChoice(Pokemon &); //returns a random number from 0 to amount of moves learned
	int firstAttack(Pokemon &, int Pmove, Pokemon &, int Amove); //first attack to determine who attacks second
	void attack(Pokemon &, Pokemon &, int move); //procedures for attacking
	bool playerFirst(Pokemon &, int Pmove, Pokemon &, int Amove); //checks to see if player attacks first. returns false if not
	/*multihit attacks case BARRAGE: case COMET_PUNCH: case DOUBLE_KICK: case FURY_ATTACK: case FURY_SWIPES: case PIN_MISSILE: case SPIKE_CANNON: case TWINEEDLE:
	//unique effect moves case CONVERSION: case COUNTER: case DISABLE: case DRAGON_RAGE: case DREAM_EATER: case FOCUS_ENERGY: 
	//case HAZE: case HIGH_JUMP_KICK: case JUMP_KICK: case METRONOME: case MIMIC: case MIRROR_MOVE: case MIST: case NIGHT_SHADE: case PAY_DAY
	//case PETAL_DANCE: case PSYWAVE: case RAGE: case ROAR: case SEISMIC_TOSS: case SONIC_BOOM: case SPLASH: case STRUGGLE:
	//case SUBSTITUTE: case SUPER_FANG: case TELEPORT: case THRASH: case TRANSFORM: case TRI_ATTACK: case WHIRLWIND:
	//recovery case ABSORB: case LEECH_LIFE: case MEGA_DRAIN: case RECOVER: case REST: case SOFT_BOILED
	//field case LIGHT_SCREEN: case REFLECT:
	//1hit ko case FISSURE: case GUILLOTINE: case HORN DRILL:
	//suicide case EXPLOSION: case SELF_DESTRUCT
	//2 turn attacks case BIDE: case DIG: case FLY: case HYPER_BEAM case RAZOR_WIND: case SKULL_BASH: case SKY_ATTACK: case SOLAR_BEAM:
	//related to above attacks case EARTHQUAKE: case GUST:
	//recoil case DOUBLE_EDGE: case SUBMISSION: case TAKE_DOWN:*/
	bool statusCheck1(Pokemon &); //checks for status before Pokemon attacks. returns false if Pokemon can't attack. checks for if bound, confused, paralyzed, frozen, asleep
	void statusCheck2(Pokemon &, Pokemon &); //checks for status after Pokemon attacks. takes damage if poisoned, burned, or seeded
	bool faintCheck(Pokemon &, Pokemon &); //returns true if one of the Pokemon has fainted
	void resetStates(Pokemon &, Pokemon &); //sets volatile states to false, sleep and poison counts to 0
	void chanceState(Pokemon &, Pokemon &, int move, int effect, int chance); //called when there's a chance of status or stat change
	void nvStatusChange(Pokemon &affected, int effect); //called when non-volatile status affects a Pokemon
	void vStatusChange(Pokemon &affected, int effect); //called when volatile states affects a Pokemon
	void statChange(Pokemon &, Pokemon &, int move); //called when a stat change occurs from a move
	float stageConversion(int stage); //converts stages of stats to a multiplier

	bool attackMissed(int move, int accuracy, int evasion); //determines whether an move hits or misses
	int damageCalculation(Pokemon &, Pokemon &, int move); //calculates damage
	float typeEffectiveness(int moveType, int pokemonType); //returns the multiplier based on the type effective chart

	void switchOut(Pokemon &, Pokemon &);
	void items(Pokemon &, Pokemon &);
	void flee(Pokemon &, Pokemon &);
	
	//Rendering
	battle(int, int, Texture*);
	void startBattle(Pokemon &one, Pokemon &two);
	void Render();
	static battle* sInstance;
	static battle* Instance();
	static void Release();

protected:
	//count for bound moves
	int m_boundCount;
	//holder for battle text
	std::string m_message;

	battle *m_battleScreen = nullptr;
	Pokemon *frontSprite = nullptr;
	Pokemon *backSprite = nullptr;
	Graphics *mGraphics = nullptr;
	AssetManager *mAssetManager = nullptr;
};

#endif

//Texture * mPokemon
//mTex = image.jpg

//&GetmTex()->GetmRenderRect; (position drawn)