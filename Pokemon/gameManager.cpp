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
	mLevelManager = LevelManager::Instance();
	mTextDisplay = Dialouge::Instance();
	if (!Graphics::Initialized()) {
		mQuit = true;
	}
	mTimer = Timer::Instance();
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
		mPlayerControls->Input();

		while (SDL_PollEvent(&events) != 0) {
			if (events.type == SDL_QUIT) {
				mQuit = true;
			}
		}


		if(mTimer->DeltaTime() >= (0.1f / FRAME_RATE)){
			//UPDATES
			mGraphics->ClearBackBuffer();
			//RENDERS
			//mMenuManager->menu->Render();
			mLevelManager->Update();
			mLevelManager->Render();
			//mNPCtext->Render(0,0);
			mGraphics->Render();
			mTimer->Reset();
		}
	}
}