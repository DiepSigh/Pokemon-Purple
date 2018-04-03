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
	mPlayer = new Characters();
	mPlayer->SetPosX(150);
	mPlayer->SetSpeed(2);
	//map1 = new Map1();
}

LevelManager::~LevelManager() {
	//delete map1;
	//map1 = nullptr;
}

void LevelManager::Update() {
	//map1->Update();
	//mPlayer->SetPosX(mPlayer->GetPosX() + 0.1f);
}

void LevelManager::Render() {
	//map1->Render();
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
