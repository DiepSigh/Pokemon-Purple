#ifndef BATTLE_H
#define BATTLE_H
#include "Pokemon.h"

struct battle{
	void battleMenu();
	void fight(Pokemon &, Pokemon &);
	int AI(Pokemon &);
	void firstAttack(Pokemon &, int, Pokemon &, int);
	int damageCalculation(Pokemon &, Pokemon &, int move);
	float typeEffectiveness(int moveType, int pokemonType); //returns the multiplier based on the type effective chart
	void switchOut(Pokemon &, Pokemon &);
	void items(Pokemon &, Pokemon &);
	void flee(Pokemon &, Pokemon &);
};

#endif

//Texture * mPokemon
//mTex = image.jpg

//&GetmTex()->GetmRenderRect; (position drawn)