#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include "characters.h"
#include "camera.h"
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
#include "Mom.h"

class LevelManager {
private:
	static LevelManager* sInstance;
	static bool sInitialized;
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
	void NormalizeVel();
	enum ActiveLevel{NONE, MASTERMAP, PLAYERHOUSE};
	ActiveLevel GetLevelName(){ return activeLevel; }
	void SetLevelName(ActiveLevel levelName) { activeLevel = levelName; }

private:
	LevelManager();
	~LevelManager();
	Characters* mPlayer;
	int mMapId;
	float mNewPlayerXPos;
	float mNewPlayerYPos;
	ActiveLevel activeLevel = PLAYERHOUSE;
	Oak* mOak;
	Mom* mMom;
};


#endif // !LEVELMANAGER_H

