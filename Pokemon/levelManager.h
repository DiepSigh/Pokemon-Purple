#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H
#include "characters.h"
#include "startRoom.h"
#include "playerHouse.h"
#include "redHouse.h"
#include "researchLab.h"
#include "pokemonMart.h"
#include "pokemonCenter.h"
#include "pokemonSchool.h"
#include "viridianCityHouse.h"
#include "pokemonLeague.h"
#include "MasterMap.h"
#include "AudioManager.h"
#include "CollisionBoxes.h"

class LevelManager {

private:
	static LevelManager* sInstance;
	static bool sInitialized;

public:
	static LevelManager* Instance();
	static void Release();
	static bool Initialized();
	void Render();
	void Update();
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void buttonA();
	void buttonS();
	void buttonC();

private:
	LevelManager();
	~LevelManager();
	Characters* mPlayer;
	CollisionBox *mCollisionBoxes;
	MapsLoader* mapsLoader;
	StartRoom* mStartRoom;
	PlayerHouse* mPlayerHouse;
	RedHouse* mRedHouse;
	ResearchLab* mResearchLab;
	PokemonMart* mPokemonMart;
	PokemonCenter* mPokemonCenter;
	PokemonSchool* mPokemonSchool;
	ViridianCityHouse* mViridianCityHouse;
	PokemonLeague* mPokemonLeague;
	MasterMap* mMasterMap;
	AudioManager* mAudioMgr;

	int mMapId;
	float mNewPlayerXPos;
	float mNewPlayerYPos;
	//Map1* map1;
};


#endif // !LEVELMANAGER_H

