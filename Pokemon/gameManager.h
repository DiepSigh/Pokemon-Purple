#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "graphics.h"
#include "timer.h"
#include "animatedTexture.h"
#include "menuManager.h"
#include "startRoom.h"
#include "playerHouse.h"
#include "redHouse.h"
#include "reserchLab.h"
#include "pokemonMart.h"
#include "pokemonCenter.h"
#include "pokemonSchool.h"
#include "viridianCityHouse.h"
#include "pokemonLeague.h"
#include "MasterMap.h"

class GameManager {
private:
	static GameManager* sInstance;
	const int FRAME_RATE = 60;
	bool mQuit;
	SDL_Event events;
	bool isPlaying = false;
	Graphics* mGraphics;
	Timer* mTimer;
	Texture* mTex;
	MenuManager* mMenuManager;
	StartRoom* mStartRoom;
	PlayerHouse* mPlayerHouse;
	RedHouse* mRedHouse;
	ReserchLab* mReserchLab;
	PokemonMart* mPokemonMart;
	PokemonCenter* mPokemonCenter;
	PokemonSchool* mPokemonSchool;
	ViridianCityHouse* mViridianCityHouse;
	PokemonLeague* mPokemonLeague;
	MasterMap* mMasterMap;

public:
	static GameManager* Instance();
	static void Release();
	void Run();
	bool GetIsPlaying() { return isPlaying; }
	void SetIsPlaying(bool playing) { isPlaying = playing; }

private:
	GameManager();
	~GameManager();
};

#endif // !GAMEMANAGER_H

