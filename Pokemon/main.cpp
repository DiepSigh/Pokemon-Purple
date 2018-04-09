// Pokemon.cpp : Defines the entry point for the console application.
//
#include "gameManager.h"
#include "Pokemon.h"
#include "battle.h"

int main(int argc, char *argv[])
{
	//GameManager* game = GameManager::Instance();
	//game->Run();
	//GameManager::Release();
	//game = nullptr;

	//PokeBase *Pokedex = new PokeBase();
	//Pokedex->populatePokemon();

	Pokemon *rivalStarter;
	rivalStarter = new Pokemon(BULBASAUR, 20);
	Pokemon *starter;
	starter = new Pokemon(CHARMANDER, 20);
	//rivalStarter->displayStats();
	//starter->displayStats();
	battle encounter;
	encounter.fight(*rivalStarter, *starter);
    return 0;
}

