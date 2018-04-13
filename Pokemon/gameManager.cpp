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

	mCamera = Camera::Instance();
	mOptions = Options::Instance();
	mPokeBase = PokeBase::Instance();


	mTextDisplay = Dialouge::Instance();

	if (!Graphics::Initialized()) {
		mQuit = true;
	}
	mTimer = Timer::Instance();

	mLevelManager = LevelManager::Instance();
	
	// By Canados
	
	mAudioMgr = AudioManager::Instance();
	
	mPlayerControls = new UserInput();
	mNPCtext = new TextScreen();

}

GameManager::~GameManager() {
	AssetManager::Release();
	LevelManager::Release();
	Graphics::Release();
	mGraphics = NULL;
	
	Timer::Release();
	mTimer = NULL;

	AudioManager::Release();
	mAudioMgr = NULL;

	delete mTex;
	mTex = NULL;
	delete mPlayerControls;
	mPlayerControls = NULL;

	delete mNPCtext;
	mNPCtext = NULL;
}

void GameManager::Run() {
	while (!mQuit) {
		mTimer->Update();
		mPlayerControls->Input(mMenuManager, mOptions);

		while (SDL_PollEvent(&events) != 0) {
			if (events.type == SDL_QUIT) {
				mQuit = true;
			}
		}

		if(mTimer->DeltaTime() >= (0.1f / FRAME_RATE)){
			
			mGraphics->ClearBackBuffer();
			//UPDATES!!!!
			//mLevelManager->Update();
			
			mMenuManager->Update();
			

			//RENDERS!!!!!
			mLevelManager->Update();
			//Player Controller
		
			//Menu Controller
			mMenuManager->Render();

			mGraphics->Render();
			mTimer->Reset();
		}
	}
}
