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
	//mAudioMgr->PlayMusic("Palette_Town_Theme.wav");
	//mAudioMgr->PlayMusic("Road_Viridian_City_From_Palette.wav");
	
	mPlayerControls = new UserInput();
	mNPCtext = new TextScreen();

	//Stephen's
	mBattle = battle::Instance();
	starter = new Pokemon(VENUSAUR, 40);
	rivalStarter = new Pokemon(CHARIZARD, 40);
}

GameManager::~GameManager() {
	AssetManager::Release();
	LevelManager::Release();
	Graphics::Release();
	mGraphics = NULL;
	
	Timer::Release();
	mTimer = NULL;

	battle::Release();
	mBattle = NULL;

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

		mPlayerControls->Input(mMenuManager, mOptions, mBattle);

		while (SDL_PollEvent(&events) != 0) {
			if (events.type == SDL_QUIT) {
				mQuit = true;
			}
		}

		if(mTimer->DeltaTime() >= (0.1f / FRAME_RATE)){
			
			mGraphics->ClearBackBuffer();
			//UPDATES!!!!
			mMenuManager->Update();
			mLevelManager->Update();

			//RENDERS!!!!!
			mLevelManager->Render(mTimer->DeltaTime());
			mMenuManager->Render();

			//uncomment for battle. must render before update.
			//mBattle->battleActive(*starter, *rivalStarter);
			//mBattle->Update(*starter, *rivalStarter);

			mGraphics->Render();
			mTimer->Reset();

			
			
		}
	}
}
