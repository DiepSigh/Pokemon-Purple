#ifndef MOVES_H
#define MOVES_H

enum moves {};

enum move_category { PHYSICAL=1, SPECIAL=2, STATUS=3};

enum volatile_effect {BURN=1, FREEZE=2, PARALYSIS=3, POISON=4, TOXIC=5, SLEEP=6 };
enum non_volatile_effect {BOUND=7, CONFUSE=8, FLINCH=9, LEECH=10};
enum effect {RECOVERY=11};
struct Move {
protected:
	int m_moveID;
	int m_moveName;
	int m_movePower;		//Base Power
	int m_moveCat;			//Physical, Special or Status
	int m_moveType;			//Normal, Fire, etc.
	int m_moveAcc;			//Accuracy
	int m_moveEffect;		//Status effect
	int m_moveChance;		//Chance for status
	int m_movePPCurrent;
	int m_movePPMax;
	int m_movePriority;
};

#endif