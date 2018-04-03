#ifndef BATTLE_H
#define BATTLE_H
#include "Pokemon.h"

struct battle{
	enum side { PLAYER = 1, AI = 2 };

	battle();
	void battleMenu();
	//Fighting
	void fight(Pokemon &, Pokemon &);
	int AIChoice(Pokemon &);
	void firstAttack(Pokemon &, int Pmove, Pokemon &, int Amove); //determines who attacks first and attacks
	void statChange(int user, int move);
	bool attackMissed(int move, int accuracy, int evasion);
	int damageCalculation(Pokemon &, Pokemon &, int move);
	float typeEffectiveness(int moveType, int pokemonType); //returns the multiplier based on the type effective chart

	void switchOut(Pokemon &, Pokemon &);
	void items(Pokemon &, Pokemon &);
	void flee(Pokemon &, Pokemon &);
protected:
	//counter for moves
	int playerCounter;
	int aiCounter;

	//stat stages
	int attPlayer;
	int attAI;
	int defPlayer;
	int defAI;
	int spdPlayer;
	int spdAI;
	int spePlayer;
	int speAI;
	int accPlayer;
	int accAI;
	int evaPlayer;
	int evaAI;
};

#endif

//Texture * mPokemon
//mTex = image.jpg

//&GetmTex()->GetmRenderRect; (position drawn)