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
	mPlayer->SetPosX(mCamera->GetXPos());
	mPlayer->SetPosY(mCamera->GetYPos());

	mPlayer->SetWPosX(mCamera->GetXPos()); // by Canados
	mPlayer->SetWPosY(mCamera->GetYPos()); // by Canados
	
	//std::cout << "Player X Y "  << mPlayer->GetPosX() << " " << mPlayer->GetPosY() << endl; // checking PlayerX position

	std::cout << "Camera X Y " <<  mCamera->GetXPos() << " " << mCamera->GetYPos() << endl;

	std::cout << "Player World X Y " << mPlayer->GetWPosX() << " " << mPlayer->GetWPosY() << endl; // cheking PlayerX world position

	
	mPlayer->SetSpeed(2);

	mCollisionBoxMM = CollisionBoxMM::Instance();

	mCollisionBoxPH = CollisionBoxPH::Instance();
	
	mMasterMap = new MasterMap(0, 0);
		
	mStartRoom = new StartRoom(0, 0);
	mPlayerHouse = new PlayerHouse(0, 0);
	mRedHouse = new RedHouse(0, 0);
	mResearchLab = new ResearchLab(0, 0);
	mPokemonMart = new PokemonMart(0, 0);
	mPokemonCenter = new PokemonCenter(0, 0);
	mPokemonSchool = new PokemonSchool(0, 0);
	mViridianCityHouse = new ViridianCityHouse(0, 0);
	mPokemonLeague = new PokemonLeague(0, 0);


	mOak = new Oak;
	mOak->SetPosX(250);
	mOak->SetPosY(250);
	//map1 = new Map1();
	//cout << "mCameraPOSx: " + (int)mCamera->GetCamXPos() << std::endl;
	//cout << "mPlayerPOSx: " + (int)mPlayer->GetPosX() << std::endl;
}

LevelManager::~LevelManager() {

	delete mCollisionBoxMM;
	mCollisionBoxMM = NULL;

	delete mCollisionBoxPH;
	mCollisionBoxPH = NULL;

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


}

void LevelManager::Update() {
	//map1->Update();
	//mPlayer->SetPosX(mPlayer->GetPosX() + 0.1f);
}

void LevelManager::Render(float t) {
	///LEVEL LOAD TEST
	switch (activeLevel)
	{
	case NONE:
		break;

	case PLAYERHOUSE:
		mPlayerHouse->Update();
		mCollisionBoxPH->DrawCollisions(mCamera);
		
		break;
	case MASTERMAP:
		mMasterMap->Update();
		mCollisionBoxMM->DrawCollisions(mCamera);
		mCollisionBoxMM->DrawBattleBoxes(mCamera);
		mCollisionBoxMM->DrawDialogBoxes(mCamera);
		
		break;

	default:
		break;
	}
	//mPlayerHouse->isActive = true;

	mPlayer->Render();
	mOak->Render();//Renders .png image
}

void LevelManager::moveLeft() {

	
	switch (activeLevel)
	{
	case NONE:
		break;

	case PLAYERHOUSE:
		mCamera->SetXPos(mCamera->GetXPos() + mCamera->GetSpeed());
		mPlayerHouse->SetPosX(mPlayerHouse->GetPosX() + mCamera->GetSpeed());

		mCollisionBoxPH->CheckMoveLeft(mPlayer, mCamera, mAudioMgr, mCollisionBoxPH);
		

		break;
	case MASTERMAP:
		mCamera->SetXPos(mCamera->GetXPos() + mCamera->GetSpeed());
		mMasterMap->SetPosX(mMasterMap->GetPosX() + mCamera->GetSpeed());

		mCollisionBoxMM->CheckMoveLeft(mPlayer, mCamera, mAudioMgr, mCollisionBoxMM);
		
					
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
		
		mCollisionBoxPH->CheckMoveRight(mPlayer, mCamera, mAudioMgr, mCollisionBoxPH);

		break;
	case MASTERMAP:
		mCamera->SetXPos(mCamera->GetXPos() - mCamera->GetSpeed());
		mMasterMap->SetPosX(mMasterMap->GetPosX() - mCamera->GetSpeed());
		
		mCollisionBoxMM->CheckMoveRight(mPlayer,mCamera,mAudioMgr,mCollisionBoxMM);

	
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
		
		mCollisionBoxPH->CheckMoveUp(mPlayer, mCamera, mAudioMgr, mCollisionBoxPH);

		break;
	case MASTERMAP:
		mCamera->SetYPos(mCamera->GetYPos() + mCamera->GetSpeed());
		mMasterMap->SetPosY(mMasterMap->GetPosY() + mCamera->GetSpeed());
			
		mCollisionBoxMM->CheckMoveUp(mPlayer, mCamera, mAudioMgr, mCollisionBoxMM);
		
		
		break;

	default:
		break;
	}	
		
}

void LevelManager::moveDown() {

	
	switch (activeLevel)
	{
	case NONE:
		break;

	case PLAYERHOUSE:
		mCamera->SetYPos(mCamera->GetYPos() - mCamera->GetSpeed());
		mPlayerHouse->SetPosY(mPlayerHouse->GetPosY() - mCamera->GetSpeed());
		
		mCollisionBoxPH->CheckMoveDown(mPlayer, mCamera, mAudioMgr, mCollisionBoxPH);

		break;
	case MASTERMAP:
		mCamera->SetYPos(mCamera->GetYPos() - mCamera->GetSpeed());
		mMasterMap->SetPosY(mMasterMap->GetPosY() - mCamera->GetSpeed());

		mCollisionBoxMM->CheckMoveDown(mPlayer, mCamera, mAudioMgr, mCollisionBoxMM);
		
		
		break;

	default:
		break;
	}	
}

void LevelManager::NormalizeVel() {
	mCamera->SetVel(0);
	mCamera->SetSpeed(mCamera->GetSpeed() * mCamera->GetVel());
}

void LevelManager::buttonA() {}

void LevelManager::buttonS() {}

void LevelManager::buttonC() {}