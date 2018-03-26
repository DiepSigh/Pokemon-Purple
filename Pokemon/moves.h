#ifndef MOVES_H
#define MOVES_H

#include "Pokemon.h"

class Move : protected Pokemon {
protected:
	int m_moveID;
	int m_moveName;
	int m_moveEffect;
	int m_movePower;
	int m_moveAcc;
	int m_moveType;
	int m_movePP;
};

#endif