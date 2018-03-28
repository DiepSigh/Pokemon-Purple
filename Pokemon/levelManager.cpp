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
	//map1 = new Map1();
}

LevelManager::~LevelManager() {
	//delete map1;
	//map1 = nullptr;
}

void LevelManager::Update() {
	//map1->Update();
}

void LevelManager::Render() {
	//map1->Render();
}
