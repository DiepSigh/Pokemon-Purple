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

	if (!Graphics::Initialized()) {
		mQuit = true;
	}
	
	mTimer = Timer::Instance();

	playerControls = new PlayerWalk();

	mTex = new AnimatedTexture("PokemonSpriteSheet.png",7,1,50,50,2,1.0f,AnimatedTexture::HORIZONTAL);
	mTex->Pos(Vector2(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f));
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
			
			mTex->Update();
			mGraphics->ClearBackBuffer();

			//RENDERS!!!!!
			mTex->Render();
			mGraphics->Render();
			mTimer->Reset();
		}
	}
}