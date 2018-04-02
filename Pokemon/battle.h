#ifndef BATTLE_H
#define BATTLE_H
#include "Pokemon.h"

class battle{
public:
	void battleMenu();
	void fight(Pokemon &, Pokemon &);
	void AI();
	void firstAttack(Pokemon &, int, Pokemon &, int);
	int damageCalculation(Pokemon &, Pokemon &, int move);
	float typeEffectiveness(int moveType, int pokemonType);
	void switchOut(Pokemon &, Pokemon &);
	void items(Pokemon &, Pokemon &);
	void flee(Pokemon &, Pokemon &);
};

#endif

//Texture * mPokemon
//mTex = image.jpg

//&GetmTex()->GetmRenderRect; (position drawn)