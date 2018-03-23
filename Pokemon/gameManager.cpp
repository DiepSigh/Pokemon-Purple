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
	//mTex = new AnimatedTexture("PokemonSpriteSheet.png", 7, 1, 50, 50, 2, 1.0f,AnimatedTexture::HORIZONTAL);
}

GameManager::~GameManager() {
	Graphics::Release();
	mGraphics = NULL;
	Timer::Release();
	mTimer = NULL;
}

void GameManager::Run() {
	while (!mQuit) {
		mTimer->Update();
		while (SDL_PollEvent(&events) != 0) {
			if (events.type == SDL_QUIT) {
				mQuit = true;
			}
			switch (events.type) {
			case SDL_KEYDOWN:
				switch (events.key.keysym.sym) {
				case SDLK_a:
					printf("You pressed 'a'\n");
					break;
				case SDLK_LEFT:
					printf("You pressed left arrow\n");
					break;
				case SDLK_ESCAPE:
					break;
				}
				break;

			case SDL_MOUSEMOTION:
				printf(events.motion.x + ", " + events.motion.y);
				break;

			case SDL_MOUSEBUTTONDOWN:
				printf("You clicked.\n");
				break;

			case SDL_MOUSEBUTTONUP:
				printf("You released mouse click.\n");
				break;
			}
		}
		if (mTimer->DeltaTime() >= (0.1f / FRAME_RATE)) {
			//Updates
			mGraphics->ClearBackBuffer();

			//Renders
			mGraphics->Render();

			mTimer->Reset();
		}
	}
}