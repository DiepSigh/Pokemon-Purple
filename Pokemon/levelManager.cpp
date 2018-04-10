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
	mPlayer->SetSpeed(2);

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

	//cout << "mCameraPOSx: " + (int)mCamera->GetCamXPos() << std::endl;
	//cout << "mPlayerPOSx: " + (int)mPlayer->GetPosX() << std::endl;
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
	
	//delete map1;
	//map1 = nullptr;
}

void LevelManager::Update() {

	//map1->Update();
	//mPlayer->SetPosX(mPlayer->GetPosX() + 0.1f);
}

void LevelManager::Render(float t) {
	///LEVEL LOAD TEST
	switch (activeLevel)
	{
	case NONE :
		break;

	case PLAYERHOUSE :
		mPlayerHouse->Update();

		break;
	case MASTERMAP :
		mMasterMap->Update();

		break;

	default:
		break;
	}
	//mPlayerHouse->isActive = true;
	
	mPlayer->Render();
}

void LevelManager::moveLeft() {

	switch (activeLevel)
	{
	case NONE:
		break;

	case PLAYERHOUSE:
		mPlayerHouse->SetPosX(mPlayerHouse->GetPosX() + mCamera->GetSpeed());
		mCamera->SetXPos(mCamera->GetXPos() + mCamera->GetSpeed());

		break;
	case MASTERMAP:
		mMasterMap->SetPosX(mMasterMap->GetPosX() + mCamera->GetSpeed());
		mCamera->SetXPos(mCamera->GetXPos() + mCamera->GetSpeed());
		break;

	default:
		break;
	}
	//mPlayer->SetPosX(mPlayer->GetPosX() - mPlayer->GetSpeed());
	//mCamera->SetVel(2);
	//mCamera->SetSpeed(0.01f/*mCamera->GetSpeed() * mCamera->GetVel()*/);
	//if (mCamera->GetSpeed() > 0.01f) {
	//	mCamera->SetSpeed(0.01f);
	//}
	//cout << mCamera->GetXPos() << endl;
}

void LevelManager::moveRight() {


	switch (activeLevel)
	{
	case NONE:
		break;

	case PLAYERHOUSE:
		mPlayerHouse->SetPosX(mPlayerHouse->GetPosX() - mCamera->GetSpeed());
		mCamera->SetXPos(mCamera->GetXPos() - mCamera->GetSpeed());

		break;
	case MASTERMAP:
		mMasterMap->SetPosX(mMasterMap->GetPosX() - mCamera->GetSpeed());
		mCamera->SetXPos(mCamera->GetXPos() - mCamera->GetSpeed());
		break;

	default:
		break;
	}	//mPlayer->SetPosX(mPlayer->GetPosX() + mPlayer->GetSpeed());
	//mCamera->SetVel(2);
	//mCamera->SetSpeed(0.01f/*mCamera->GetSpeed() * mCamera->GetVel()*/);
	//if (mCamera->GetSpeed() > 0.01f) {
	//	mCamera->SetSpeed(0.01f);
	//}
	//mCamera->SetXPos(mCamera->GetXPos() + mCamera->GetSpeed());
	//cout << mCamera->GetXPos() <<endl;

}

void LevelManager::moveUp() {


	switch (activeLevel)
	{
	case NONE:
		break;

	case PLAYERHOUSE:
		mPlayerHouse->SetPosY(mPlayerHouse->GetPosY() + mCamera->GetSpeed());
		mCamera->SetYPos(mCamera->GetYPos() + mCamera->GetSpeed());

		break;
	case MASTERMAP:
		mMasterMap->SetPosY(mMasterMap->GetPosY() + mCamera->GetSpeed());
		mCamera->SetYPos(mCamera->GetYPos() + mCamera->GetSpeed());
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
		mPlayerHouse->SetPosY(mPlayerHouse->GetPosY() - mCamera->GetSpeed());
		mCamera->SetYPos(mCamera->GetYPos() - mCamera->GetSpeed());

		break;
	case MASTERMAP:
		mMasterMap->SetPosY(mMasterMap->GetPosY() - mCamera->GetSpeed());
		mCamera->SetYPos(mCamera->GetYPos() - mCamera->GetSpeed());
		break;

	default:
		break;
	}	//mCamera->SetVel(2);
	//mCamera->SetSpeed(0.01f/*mCamera->GetSpeed() * mCamera->GetVel()*/);
	//if (mCamera->GetSpeed() > 0.01f) {
	//	mCamera->SetSpeed(0.01f);
	//}
	//mCamera->SetYPos(mCamera->GetYPos() - mCamera->GetSpeed());
	//cout << mCamera->GetYPos() << endl;
}

void LevelManager::NormalizeVel() {
	mCamera->SetVel(0);
	mCamera->SetSpeed(mCamera->GetSpeed() * mCamera->GetVel());
}
void LevelManager::buttonA() {}

void LevelManager::buttonS() {}

void LevelManager::buttonC() {}
