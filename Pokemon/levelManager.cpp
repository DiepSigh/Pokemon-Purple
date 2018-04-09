#include "levelmanager.h"


LevelManager* LevelManager::sInstance = nullptr;
bool LevelManager::sInitialized = false;

LevelManager* LevelManager::Instance()
{
	if (sInstance == nullptr) {
		sInstance = new LevelManager();
	}
	return sInstance;
}

void LevelManager::Release() {
	delete sInstance;
	sInitialized = false;

}

bool LevelManager::Initialized() {
	return sInitialized;
}

LevelManager::LevelManager() {
	// By Canados --------->
	mCollisionBoxes = CollisionBox::Instance();
	
	mMasterMap = new MasterMap(0, 0);
	//mStartRoom = new StartRoom(0, 0);
	//mPlayerHouse = new PlayerHouse(0, 0);
	//mRedHouse = new RedHouse(0, 0);
	//mResearchLab = new ResearchLab(0, 0);
	//mPokemonMart = new PokemonMart(0, 0);
	//mPokemonCenter = new PokemonCenter(0, 0);
	//mPokemonSchool = new PokemonSchool(0, 0);
	//mViridianCityHouse = new ViridianCityHouse(0, 0);
	//mPokemonLeague = new PokemonLeague(0, 0);
	//mAudioMgr = AudioManager::Instance();
	//mAudioMgr->PalletTownSound();
	// <--------- By Canados

	mPlayer = new Characters();
	mPlayer->SetPosX(170);
	mPlayer->SetPosY(150);
	mPlayer->SetSpeed(2);
}

LevelManager::~LevelManager() {
	//delete map1;
	//map1 = nullptr;

	// By Canados --------->
	AudioManager::Release();
	mAudioMgr = NULL;

	delete mStartRoom;
	mStartRoom = NULL;

	delete mPlayerHouse;
	mPlayerHouse = NULL;

	delete mRedHouse;
	mRedHouse = NULL;

	delete mResearchLab;
	mResearchLab = NULL;

	delete mPokemonMart;
	mPokemonMart = NULL;

	delete mPokemonCenter;
	mPokemonCenter = NULL;

	delete mPokemonSchool;
	mPokemonSchool = NULL;

	delete mViridianCityHouse;
	mViridianCityHouse = NULL;

	delete mPokemonLeague;
	mPokemonLeague = NULL;

	delete mMasterMap;
	mMasterMap = NULL;
	//<--------- By Canados

}

void LevelManager::Update() {
	//map1->Update();
	//mPlayer->SetPosX(mPlayer->GetPosX() + 0.1f);
}

void LevelManager::Render() {
	//map1->Render();
	

	// By Canados --------->
	mMasterMap->Update();

	//mStartRoom->Update(); 
	//mPlayerHouse->Update(); 
	//mRedHouse->Update(); 
	//mResearchLab->Update(); 
	//mPokemonMart->Update(); 
	//mPokemonCenter->Update(); 
	//mPokemonSchool->Update(); 
	//mViridianCityHouse->Update();  
	//mPokemonLeague->Update(); 
	mCollisionBoxes->DrawCollisions();
	// <--------- By Canados

	mPlayer->Render();
}

void LevelManager::moveLeft() {
	mPlayer->SetPosX(mPlayer->GetPosX() - mPlayer->GetSpeed());
}

void LevelManager::moveRight() {
	mPlayer->SetPosX(mPlayer->GetPosX() + mPlayer->GetSpeed());
}

void LevelManager::moveUp() {
	mPlayer->SetPosY(mPlayer->GetPosY() - mPlayer->GetSpeed());
}

void LevelManager::moveDown() {
	mPlayer->SetPosY(mPlayer->GetPosY() + mPlayer->GetSpeed());
}

void LevelManager::buttonA() {}

void LevelManager::buttonS() {}

void LevelManager::buttonC() {}
