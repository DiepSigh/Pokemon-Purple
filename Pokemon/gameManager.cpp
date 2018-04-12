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

	if (!Graphics::Initialized()) {
		mQuit = true;
	}
	
	mTimer = Timer::Instance();
	mLevelManager = LevelManager::Instance();
	mPlayerControls = new UserInput();
	
	// By Canados
	
	mAudioMgr = AudioManager::Instance();
	//mAudioMgr->PlayMusic("Palette_Town_Theme.wav");
	//mAudioMgr->PlayMusic("Road_Viridian_City_From_Palette.wav");
	
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
}

void GameManager::Run() {

	while (!mQuit) {
		mTimer->Update();
		mPlayerControls->Input(mMenuManager,mTimer->DeltaTime());
		while (SDL_PollEvent(&events) != 0) {
			if (events.type == SDL_QUIT) {
				mQuit = true;
			}
		}

		if(mTimer->DeltaTime() >= (0.1f / FRAME_RATE)){
//			std::cout << mTimer->DeltaTime() << std::endl;
			mGraphics->ClearBackBuffer();			
			//UPDATES!!!!
			mLevelManager->Update();	
			//RENDERS!!!!!	
			mMenuManager->Update();
			mLevelManager->Render(mTimer->DeltaTime());
			//Player Controller		
			//Menu Controller
			mMenuManager->Render();
			mGraphics->Render();
			mTimer->Reset();
		}
	}
}
