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
	void startBattle();
	void Render();
	static battle* sInstance;
	static battle* Instance();
	static void Release();

protected:
	//count for bound moves
	int m_boundCount;

	std::string m_message;

	battle * m_battleScreen = nullptr;
	//Graphics * m_graphics = nullptr;
	//AssetManager * m_aManager = nullptr;
	Graphics* mGraphics;
	AssetManager* mAssetManager;
};

#endif

//Texture * mPokemon
//mTex = image.jpg

//&GetmTex()->GetmRenderRect; (position drawn)