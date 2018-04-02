// Pokemon.cpp : Defines the entry point for the console application.
//
#include "gameManager.h"
#include "Pokemon.h"
#include <time.h>
int main(int argc, char *argv[])
{
	//GameManager* game = GameManager::Instance();
	//game->Run();
	//GameManager::Release();
	//game = nullptr;

	Pokemon Encounter(BULBASAUR, 50);
	Pokemon Encounter2(BULBASAUR, 50);
	Pokemon *test;
	test = new Pokemon(BULBASAUR, 50);
	test->displayStats();
	Encounter.displayStats();
	Encounter2.displayStats();
    return 0;
}

