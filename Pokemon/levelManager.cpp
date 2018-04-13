#include "levelmanager.h"
#include <iostream>

using namespace std;


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
	mCamera = Camera::Instance();
	mCamera->SetXPos(Graphics::SCREEN_WIDTH * 0.5f);
	mCamera->SetYPos(Graphics::SCREEN_HEIGHT * 0.5f);
	mCamera->SetSpeed(5);

	mPlayer = new Characters();
	mPlayer->SetPosX(400);
	mPlayer->SetPosY(300);
	mPlayer->SetSpeed(5);

	mStartScreen = new StartScreen(0, 0, new Texture("StartScreen.png", 0, 0, 800, 600));
	mStartRoom = new StartRoom(0, 0);
	mPlayerHouse = new PlayerHouse(0, 0);
	mRedHouse = new RedHouse(0, 0);
	mReserchLab = new ReserchLab(0, 0);
	mPokemonMart = new PokemonMart(0, 0);
	mPokemonCenter = new PokemonCenter(0, 0);
	mPokemonSchool = new PokemonSchool(0, 0);
	mViridianCityHouse = new ViridianCityHouse(0, 0);
	mPokemonLeague = new PokemonLeague(0, 0);
	mMasterMap = new MasterMap(0, 0);
}

LevelManager::~LevelManager() {
	delete mStartRoom;
	mStartRoom = NULL;

	delete mPlayerHouse;
	mPlayerHouse = NULL;

	delete mRedHouse;
	mRedHouse = NULL;

	delete mReserchLab;
	mReserchLab = NULL;

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

}

void LevelManager::Update() {
	//map1->Update();
	//mPlayer->SetPosX(mPlayer->GetPosX() + 0.1f);
}

void LevelManager::Render(float) {
	///LEVEL LOAD TEST
	switch (activeLevel)
	{
	case NONE:
		break;

	case START:
		mStartScreen->Update();
		mStartScreen->Render();
		mStartScreen->StartChar->GetmTex()->Update();
		mStartScreen->StartChar->Render();
		
		break;

	case PLAYERHOUSE :
		mPlayerHouse->Update();
		mPlayer->Render();
		break;

	case MASTERMAP :
		mMasterMap->Update();
		mPlayer->Render();
		break;

	default:
		break;
	
	mPlayer->Render();
	}
}

	void LevelManager::moveLeft() {

		switch (activeLevel)
		{
		case NONE:
			break;

		case PLAYERHOUSE:
			mCamera->SetXPos(mCamera->GetXPos() + mCamera->GetSpeed());
			mPlayerHouse->SetPosX(mPlayerHouse->GetPosX() + mCamera->GetSpeed());
			mPlayerHouse->momLeft();
			break;

		case MASTERMAP:
			mCamera->SetXPos(mCamera->GetXPos() + mCamera->GetSpeed());
			mMasterMap->SetPosX(mMasterMap->GetPosX() + mCamera->GetSpeed());
			mPlayer->Render();
			break;

		default:
			break;
		
	}
}

void LevelManager::moveRight() {


	switch (activeLevel)
	{
	case NONE:
		break;

	case PLAYERHOUSE:
		mCamera->SetXPos(mCamera->GetXPos() - mCamera->GetSpeed());
		mPlayerHouse->SetPosX(mPlayerHouse->GetPosX() - mCamera->GetSpeed());
		mPlayerHouse->momRight();
		break;

	case MASTERMAP:
		mCamera->SetXPos(mCamera->GetXPos() - mCamera->GetSpeed());
		mMasterMap->SetPosX(mMasterMap->GetPosX() - mCamera->GetSpeed());
		mPlayer->Render();
		break;

	default:
		break;
	}	
}

void LevelManager::moveUp() {


	switch (activeLevel)
	{
	case NONE:
		break;

	case PLAYERHOUSE:
		mCamera->SetYPos(mCamera->GetYPos() + mCamera->GetSpeed());
		mPlayerHouse->SetPosY(mPlayerHouse->GetPosY() + mCamera->GetSpeed());
		mPlayerHouse->momUp();
		mPlayer->Render();
		break;

	case MASTERMAP:
		mCamera->SetYPos(mCamera->GetYPos() + mCamera->GetSpeed());
		mMasterMap->SetPosY(mMasterMap->GetPosY() + mCamera->GetSpeed());
		mPlayer->Render();
		break;

	default:
		break;

	}	//mPlayer->SetPosY(mPlayer->GetPosY() - mPlayer->GetSpeed());
	//mCamera->SetVel(2);
	//mCamera->SetSpeed(0.01f/*mCamera->GetSpeed() * mCamera->GetVel()*/);
	//if (mCamera->GetSpeed() > 0.01f) {
	//	mCamera->SetSpeed(0.01f);
	//}
	//mCamera->SetYPos(mCamera->GetYPos() + mCamera->GetSpeed());
	//cout << mCamera->GetYPos() << endl;
}

void LevelManager::moveDown() {
	switch (activeLevel)
	{
	case NONE:
		break;

	case PLAYERHOUSE:
		mCamera->SetYPos(mCamera->GetYPos() - mCamera->GetSpeed());
		mPlayerHouse->SetPosY(mPlayerHouse->GetPosY() - mCamera->GetSpeed());
		mPlayerHouse->momDown();
		mPlayer->Render();
		break;
	case MASTERMAP:
		mCamera->SetYPos(mCamera->GetYPos() - mCamera->GetSpeed());
		mMasterMap->SetPosY(mMasterMap->GetPosY() - mCamera->GetSpeed());
		mPlayer->Render();
		break;

	default:
		break;
	}	
}

void LevelManager::buttonA() {}

void LevelManager::buttonS() {}

void LevelManager::buttonC() {}
