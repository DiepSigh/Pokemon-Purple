// Pokemon.cpp : Defines the entry point for the console application.
//
#include "gameManager.h"
#include "Pokemon.h"
#include <time.h>
int main(int argc, char *argv[])
{
	/*GameManager* game = GameManager::Instance();
	game->Run();
	GameManager::Release();
	game = nullptr;*/
	srand(static_cast<unsigned int> (time(0))); //seed
	Pokemon Encounter(CHARMANDER, 5);

    return 0;
}

