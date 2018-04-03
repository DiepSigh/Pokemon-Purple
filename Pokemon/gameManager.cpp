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
	
	// By Canados //
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
	mAudioMgr = AudioManager::Instance();
	mAudioMgr->PalletTownSound();
	
	// By Canados //
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

	
	AudioManager::Release(); // By Canados
	mAudioMgr = NULL;
	
	delete mStartRoom; // By Canados
	mStartRoom = NULL;

	delete mPlayerHouse; // By Canados
	mPlayerHouse = NULL;

	delete mRedHouse; // By Canados
	mRedHouse = NULL;

	delete mReserchLab; // By Canados
	mReserchLab = NULL;

	delete mPokemonMart; // By Canados
	mPokemonMart = NULL;

	delete mPokemonCenter; // By Canados
	mPokemonCenter = NULL;

	delete mPokemonSchool; // By Canados
	mPokemonSchool = NULL;

	delete mViridianCityHouse; // By Canados
	mViridianCityHouse = NULL;

	delete mPokemonLeague; // By Canados
	mPokemonLeague = NULL;

	delete mMasterMap; // By Canados
	mMasterMap = NULL;
	
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

			mMenuManager->Render();  // By Canados
			//mStartRoom->Update(); // By Canados
			//mPlayerHouse->Update(); // By Canados
			//mRedHouse->Update(); // By Canados
			//mReserchLab->Update(); // By Canados
			//mPokemonMart->Update(); // By Canados
			//mPokemonCenter->Update(); // By Canados
			//mPokemonSchool->Update(); // By Canados
			//mViridianCityHouse->Update(); // By Canados
			//mPokemonLeague->Update(); // By Canados
			
			
			//MenuManager->Update();

			mGraphics->ClearBackBuffer();
			mMasterMap->Update();
			mLevelManager->Update();
			mLevelManager->Render();
			//RENDERS!!!!!			

			

			mGraphics->Render();
			mTimer->Reset();
		}
	}
}