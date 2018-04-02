#include "gameManager.h"
#include "startRoom.h"
#include "MasterMap.h"
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

<<<<<<< HEAD
	//mTex = new AnimatedTexture("01_Start_Game_Room.png",7,1,50,50,2,1.0f,AnimatedTexture::HORIZONTAL);
	//mTex->Pos(Vector2(Graphics::SCREEN_WIDTH * 0.25f, Graphics::SCREEN_HEIGHT * 0.25f));

=======
	//mTex = new AnimatedTexture("PokemonSpriteSheet.png",0,0,50,50,5,1.0f,AnimatedTexture::HORIZONTAL);
	//mTex->Pos(Vector2(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f));
>>>>>>> MIKE
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
			//mTex->Update();
<<<<<<< HEAD

			mGraphics->ClearBackBuffer();
		

			//RENDERS!!!!!
			StartRoom startroom;
			startroom.GetComputer1()->Render();
			startroom.GetWall1()->Render();

			MasterMap map;
			map.GetMap()->Render();


									

			//mTex->Render();
			

			//mTex->Render();
			mMenuManager->menu->Render();
			mMenuManager->menu1->Render();
			mMenuManager->menu2->Render();

=======
			mGraphics->ClearBackBuffer();
			mLevelManager->Update();
			mLevelManager->Render();
			//RENDERS!!!!!
			//mTex->Render();
>>>>>>> MIKE
			mGraphics->Render();
			mTimer->Reset();
		}
	}
}