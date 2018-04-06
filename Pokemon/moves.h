//Stephen
#ifndef MOVES_H
#define MOVES_H

#include "gameEntity.h"
#include <string>
#include <iostream>
#include <fstream>
#include <random>

enum pokemon_type { NORMAL=0, FIGHTING=1, FLYING=2, POISON=3, GROUND=4, ROCK=5, BUG=7, GHOST=8,
	BLANK=9, FIRE=14, WATER=15, GRASS=16, ELECTRIC=17, PSYCHC=18, ICE=19, DRAGON=20 };

enum moves { ABSORB=1, ACID, ACID_ARMOR, AGILITY, AMNESIA, AURORA_BEAM, BARRAGE, BARRIER, BIDE, BIND,
	BITE, BLIZZARD, BODY_SLAM, BONE_CLUB, BONEMERANG, BUBBLE, BUBBLE_BEAM, CLAMP, COMET_PUNCH, CONFUSE_RAY,
	CONFUSION, CONSTRICT, CONVERSION, COUNTER, CRABHAMMER, CUT, DEFENSE_CURL, DIG, DISABLE, DIZZY_PUNCH,
	DOUBLE_KICK, DOUBLE_SLAP, DOUBLE_TEAM, DOUBLE_EDGE, DRAGON_RAGE, DREAM_EATER, DRILL_PECK, EARTHQUAKE, EGG_BOMB, EMBER,
	EXPLOSION, FIRE_BLAST, FIRE_PUNCH, FIRE_SPIN, FISSURE, FLAMETHROWER, FLASH, FLY, FOCUS_ENERGY, FURY_ATTACK,
	FURY_SWIPES, GLARE, GROWL, GROWTH, GUILLOTINE, GUST, HARDEN, HAZE, HEADBUTT, HIGH_JUMP_KICK,
	HORN_ATTACK, HORN_DRILL, HYDRO_PUMP, HYPER_BEAM, HYPER_FANG, HYPNOSIS, ICE_BEAM, ICE_PUNCH, JUMP_KICK, KARATE_CHOP,
	KINESIS, LEECH_LIFE, LEECH_SEED, LEER, LICK, LIGHT_SCREEN, LOVELY_KISS, LOW_KICK, MEDITATE, MEGA_DRAIN,
	MEGA_KICK, MEGA_PUNCH, METRONOME, MIMIC, MINIMIZE, MIRROR_MOVE, MIST, NIGHT_SHADE, PAY_DAY, PECK,
	PETAL_DANCE, PIN_MISSILE, POISON_GAS, POISON_POWDER, POISON_STING, POUND, PSYBEAM, PSYCHIC, PSYWAVE, QUICK_ATTACK,
	RAGE, RAZOR_LEAF, RAZOR_WIND, RECOVER, REFLECT, REST, ROAR, ROCK_SLIDE, ROCK_THROW, ROLLING_KICK,
	SAND_ATTACK, SCRATCH, SCREECH, SEISMIC_TOSS, SELF_DESTRUCT, SHARPEN, SING_, SKULL_BASH, SKY_ATTACK, SLAM,
	SLASH, SLEEP_POWDER, SLUDGE, SMOG, SMOKESCREEN, SOFT_BOILED, SOLAR_BEAM, SONIC_BOOM, SPIKE_CANNON, SPLASH,
	SPORE, STOMP, STRENGTH, STRING_SHOT, STRUGGLE, STUN_SPORE, SUBMISSION, SUBSTITUTE, SUPER_FANG, SUPERSONIC,
	SURF, SWIFT, SWORDS_DANCE, TACKLE, TAIL_WHIP, TAKE_DOWN, TELEPORT, THRASH, THUNDER, THUNDER_PUNCH,
	THUNDER_SHOCK, THUNDER_WAVE, THUNDERBOLT, TOXIC, TRANSFORM, TRI_ATTACK, TWINEEDLE, VICE_GRIP, VINE_WHIP, WATER_GUN,
	WATERFALL, WHIRLWIND, WING_ATTACK, WITHDRAW, WRAP};

enum move_category { PHYSICAL=1, SPECIAL=2, STATUS=3};

enum volatile_effect {BURN=1, PARALYSIS=2, /*POISON=3,*/ BAD_POISON=4, FREEZE=5, SLEEP=6 };
//non_volatile_effect { BOUND = 7, CONFUSE = 8, FLINCH = 9, LEECH = 10 }; battle.h
class Move {
public:
	Move();
	void getMove(int move); //gets move from CSV file

	friend int typeConvert(std::string &t); //takes string and converts to enum ("NORMAL" becomes 0 which is NORMAL)
	friend int randomGen(int low, int high); //returns number based on range

	//Getters
	inline int getMoveID() { return m_moveID; }
	std::string returnMove() { return m_moveName; }
	inline int getMoveType() { return m_moveType; }
	inline int getPower() { return m_movePower; }
	inline int getCat() { return m_moveCat; }
	inline int getAcc() { return m_moveAcc; }
	inline int getEffect() { return m_moveEffect; }
	inline int getPriority() { return m_movePriority; }
protected:
	int m_moveID;
	std::string m_moveName;
	int m_moveType;			//Normal, Fire, etc.
	std::string m_moveType_str;
	int m_moveCat;			//Physical, Special or Status
	int m_movePower;		//Base Power
	int m_moveAcc;			//Accuracy
	int m_movePPMax;		//Max PP of move
	int m_moveEffect;		//Status effect
	int m_moveChance;		//Chance for status
	int m_movePriority;
	int m_movePPCurrent;
};

#endif