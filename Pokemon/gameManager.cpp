#include "gameManager.h"
#include <iostream>

GameManager* GameManager::sInstance = nullptr;

GameManager* GameManager::Instance() {
	if (sInstance == nullptr) {
		sInstance = new GameManager();
	}

	return sInstance;
}

void GameManager::Release() {
	delete sInstance;
	sInstance = nullptr;
}

GameManager::GameManager() {
	mQuit = false;
	mGraphics = Graphics::Instance();
	mMenuManager = MenuManager::Instance();

	if (!Graphics::Initialized()) {
		mQuit = true;
	}
	
	mTimer = Timer::Instance();
	mLevelManager = LevelManager::Instance();
	mPlayerControls = new UserInput();
	

}

GameManager::~GameManager() {

	AssetManager::Release();
	LevelManager::Release();
	
	Graphics::Release();
	mGraphics = NULL;
	
	Timer::Release();
	mTimer = NULL;

	delete mTex;
	mTex = NULL;

}


void GameManager::Run() {

	while (!mQuit) {
		mTimer->Update();
		mPlayerControls->Input();

		while (SDL_PollEvent(&events) != 0) {
			if (events.type == SDL_QUIT) {
				mQuit = true;
			}
		}

		if(mTimer->DeltaTime() >= (0.1f / FRAME_RATE)){

			//UPDATES!!!!

			mGraphics->ClearBackBuffer();
			mLevelManager->Update();
			//RENDERS!!!!!			
		
			//mMenuManager->Render();  

			
			mLevelManager->Render();
			mGraphics->Render();
			mTimer->Reset();
		}
	}
}