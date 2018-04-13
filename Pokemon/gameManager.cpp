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

	//Stephen's
	mBattle = battle::Instance();
	mPokebase = PokeBase::Instance();
	starter = new Pokemon(SQUIRTLE, 5);
	rivalStarter = new Pokemon(PIDGEY, 5);

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

	battle::Release();
	mBattle = NULL;

	delete mTex;
	mTex = NULL;
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
			//mLevelManager->Update();		

			//RENDERS!!!!!	
			mMenuManager->Update();
			mLevelManager->Render(mTimer->DeltaTime());
			//RENDERS!!!!!
			mGraphics->ClearBackBuffer();
			mLevelManager->Update();
			//Player Controller
			
			mBattle->battleActive(*starter, *rivalStarter);
			mBattle->Update(*starter, *rivalStarter);
			//Menu Controller
			//mMenuManager->Render();

			mGraphics->Render();
			mTimer->Reset();
		}
	}
}
