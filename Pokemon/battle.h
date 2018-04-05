//Stephen
#ifndef BATTLE_H
#define BATTLE_H
#include "Pokemon.h"

struct battle{
	enum side { PLAYER = 1, AI = 2 };
	enum non_volatile_effect { BOUND = 7, CONFUSE = 8, FLINCH = 9, LEECH = 10 };

	battle();
	void battleMenu();
	//Fighting
	void fight(Pokemon &, Pokemon &);
	int AIChoice(Pokemon &); //returns a random number from 0 to amount of moves learned
	int firstAttack(Pokemon &, int Pmove, Pokemon &, int Amove); //determines who attacks first and attacks
	void secondAttack(Pokemon &, Pokemon &, int move); //second attack if neither Pokemon have fainted
	bool faintCheck(Pokemon &, Pokemon &); //returns true if one of the Pokemon has fainted
	void nvStatusChange(int affected, int effect); //called when non-volatile affects a Pokemon
	void vStatusChange(Pokemon &affected, int effect); //called when Pokemon status change occurs from a move
	void statChange(int affected, int move); //called when a stat change occurs from a move
	bool attackMissed(int move, int accuracy, int evasion); //determines whether an move hits or misses
	int damageCalculation(Pokemon &, Pokemon &, int move); //calculates damage
	float typeEffectiveness(int moveType, int pokemonType); //returns the multiplier based on the type effective chart

	void switchOut(Pokemon &, Pokemon &);
	void items(Pokemon &, Pokemon &);
	void flee(Pokemon &, Pokemon &);
protected:
	//counter for moves
	int playerCounter;
	int aiCounter;

	//non_volatile_effect
	bool playerBound;
	bool aiBound;
	bool playerConfuse;
	bool aiConfuse;
	bool playerFlinch;
	bool aiFlinch;
	bool playerSeed;
	bool aiSeed;

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