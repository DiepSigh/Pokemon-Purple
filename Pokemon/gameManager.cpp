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

	//mTex = new AnimatedTexture("PokemonSpriteSheet.png",7,1,50,50,2,1.0f,AnimatedTexture::HORIZONTAL);
	//mTex->Pos(Vector2(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f));

	mTex = new Texture("Hello World!","POKEMONGB.ttf", 40);
	mTex->Pos(Vector2(400, 250));
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
			mTex->Update();
			mGraphics->ClearBackBuffer();

			//RENDERS!!!!!
			mTex->Render();
			mGraphics->Render();
			mTimer->Reset();
		}
	}
}