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
	
	if (!Graphics::Initialized()) {
		mQuit = true;
	}
	
	mTimer = Timer::Instance();

	//mTex = new AnimatedTexture("01_Start_Game_Room.png",7,1,50,50,2,1.0f,AnimatedTexture::HORIZONTAL);
	//mTex->Pos(Vector2(Graphics::SCREEN_WIDTH * 0.25f, Graphics::SCREEN_HEIGHT * 0.25f));


}

GameManager::~GameManager() {
	AssetManager::Release();
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

		while (SDL_PollEvent(&events) != 0) {
			if (events.type == SDL_QUIT) {
				mQuit = true;
			}
		}

		if(mTimer->DeltaTime() >= (0.1f / FRAME_RATE)){



			//UPDATES!!!!
			//mTex->Update();


			mGraphics->ClearBackBuffer();

			//RENDERS!!!!!
					

			StartRoom startroom;
			startroom.GetComputer1()->Render();
			startroom.GetWall1()->Render();

			MasterMap map;
			map.GetMap()->Render();


									

			//mTex->Render();
			

			mGraphics->Render();
			mTimer->Reset();
		}
	}
}