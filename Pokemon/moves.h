#ifndef MOVES_H
#define MOVES_H

#include <string>

enum pokemon_type { NORMAL=0, FIGHTING=1, FLYING=2, POISON=3, GROUND=4, ROCK=5, BUG=7, 
	GHOST=8, BLANK=9, FIRE=14, WATER=15, GRASS=16, ELECTRIC=17, PSYCHIC=18, ICE=19, DRAGON=20 };
enum moves {ABSORB=1, ACID, ACID_ARMOR, AGILITY, AMNESIA, AURORA_BEAM};

enum move_category { PHYSICAL=1, SPECIAL=2, STATUS=3};

enum volatile_effect {BURN=1, PARALYSIS=2, /*POISON=3,*/ TOXIC=4, FREEZE=5, SLEEP=6 };
enum non_volatile_effect {BOUND=7, CONFUSE=8, FLINCH=9, LEECH=10};
enum effect {RECOVERY=11};

class Move {
public:
	Move();
	const void getMove(int move);
	int typeConvert(std::string t);
protected:
	int m_moveID;
	std::string m_moveName;
	int m_moveType;			//Normal, Fire, etc.
	std::string m_moveType_str;
	int m_moveCat;			//Physical, Special or Status
	int m_movePower;		//Base Power
	int m_moveAcc;			//Accuracy
	int m_movePPMax;
	int m_moveEffect;		//Status effect
	int m_moveChance;		//Chance for status
	int m_movePriority;
	int m_movePPCurrent;
};

#endif