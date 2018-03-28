#include "gameManager.h"

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

	playerControls = new UserInput();

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

		

		playerControls->Input();

		if(mTimer->DeltaTime() >= (0.1f / FRAME_RATE)){
			//UPDATES!!!!

			mGraphics->ClearBackBuffer();
		

			//RENDERS!!!!!
			//mTex->Render();
			mMenuManager->menu->Render();
			mMenuManager->menu1->Render();
			mMenuManager->menu2->Render();
			mGraphics->Render();
			mTimer->Reset();
		}
	}
}