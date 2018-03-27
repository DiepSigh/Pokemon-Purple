#ifndef BATTLE_H
#define BATTLE_H
#include "Pokemon.h"

class battle : protected Pokemon, protected Move {
public:
	void battleMenu();
	void fight(Pokemon, Pokemon);
	void switchOut(Pokemon, Pokemon);
	void items(Pokemon, Pokemon);
	void flee(Pokemon, Pokemon);
};

#endif