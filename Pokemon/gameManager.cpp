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
	
	// By Canados --------->
	mMasterMap = new MasterMap(0, 0);
	//mStartRoom = new StartRoom(0, 0);
	//mPlayerHouse = new PlayerHouse(0, 0);
	//mRedHouse = new RedHouse(0, 0);
	//mResearchLab = new ResearchLab(0, 0);
	//mPokemonMart = new PokemonMart(0, 0);
	//mPokemonCenter = new PokemonCenter(0, 0);
	//mPokemonSchool = new PokemonSchool(0, 0);
	//mViridianCityHouse = new ViridianCityHouse(0, 0);
	//mPokemonLeague = new PokemonLeague(0, 0);

	mAudioMgr = AudioManager::Instance();
	mAudioMgr->PalletTownSound();
	
	// <--------- By Canados
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

	// By Canados --------->
	AudioManager::Release(); 
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
	//<--------- By Canados
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
						
			//MenuManager->Update();

			mGraphics->ClearBackBuffer();
			mLevelManager->Update();
		
			//RENDERS!!!!!			
		
			//mMenuManager->Render();  
			

			// By Canados --------->
			mMasterMap->Update();
			//mStartRoom->Update(); 
			//mPlayerHouse->Update(); 
			//mRedHouse->Update(); 
			//mResearchLab->Update(); 
			//mPokemonMart->Update(); 
			//mPokemonCenter->Update(); 
			//mPokemonSchool->Update(); 
			//mViridianCityHouse->Update();  
			//mPokemonLeague->Update(); 
			// <--------- By Canados

			
			mLevelManager->Render();
			mGraphics->Render();
			mTimer->Reset();
		}
	}
}