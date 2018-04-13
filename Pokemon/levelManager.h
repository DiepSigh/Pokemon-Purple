#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include "characters.h"
#include "camera.h"
#include "StartScreen.h"
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
#include "Oak.h"

class LevelManager {

public:
	static LevelManager* Instance();
	static void Release();
	static bool Initialized();
	void Render(float);
	void Update();
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void buttonA();
	void buttonS();
	void buttonC();
	Camera* mCamera;
	enum ActiveLevel{NONE,START, MASTERMAP, PLAYERHOUSE};
	ActiveLevel GetLevelName(){ return activeLevel; }
	void SetLevelName(ActiveLevel levelName) { activeLevel = levelName; }

private:
	LevelManager();
	~LevelManager();
	static LevelManager* sInstance;
	static bool sInitialized;
	StartScreen* mStartScreen;
	StartScreen* mStartPokemon;
	StartRoom* mStartRoom;
	AnimatedTexture *mIntroChar;

	PlayerHouse* mPlayerHouse;
	RedHouse* mRedHouse;
	ReserchLab* mReserchLab;
	PokemonMart* mPokemonMart;
	PokemonCenter* mPokemonCenter;
	PokemonSchool* mPokemonSchool;
	ViridianCityHouse* mViridianCityHouse;
	PokemonLeague* mPokemonLeague;
	MasterMap* mMasterMap;
	Characters* mPlayer;
	Timer* mTimer;
	int mMapId;
	float mNewPlayerXPos;
	float mNewPlayerYPos;
	ActiveLevel activeLevel = START;


};


#endif // !LEVELMANAGER_H

