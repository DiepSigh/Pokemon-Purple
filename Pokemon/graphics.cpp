#include "graphics.h"

Graphics* Graphics::sInstance = NULL;
bool Graphics::sInitialized = false;

Graphics* Graphics::Instance() {
	if (sInstance == NULL) {
		sInstance = new Graphics();
	}

	return sInstance;
}

void Graphics::Release() {
	delete sInstance;
	sInstance = NULL;
	sInitialized = false;
}

bool Graphics::Initialized() {
	return sInitialized;
}

Graphics::Graphics() {
	mBackBuffer = NULL;
	sInitialized = Init();
}

Graphics::~Graphics() {
	SDL_DestroyWindow(mWindow);
	mWindow = NULL;
	SDL_DestroyRenderer(mRenderer);
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
}

bool Graphics::Init() {
	if (SDL_Init(SDL_INIT_VIDEO || SDL_INIT_AUDIO) < 0) {
		printf("SDL Initialization Error: %s\n", SDL_GetError());
	}

	mWindow = SDL_CreateWindow("Pokemon", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOWEVENT_NONE);

	if (mWindow == NULL) {
		printf("Window Creation Error %s\n", SDL_GetError());
	}

	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
	

	if (mRenderer == NULL) {
		printf("Renderer Creation Error: %s\n", SDL_GetError());
	}

	SDL_SetRenderDrawColor(mRenderer, 0xff, 0xff, 0xff, 0xff);

	int flag = IMG_INIT_PNG;

	if (!(IMG_Init(flag)&flag)) {
		printf("IMG Initialization Error: %s\n", SDL_GetError());
		return false;
	}

	mBackBuffer = SDL_GetWindowSurface(mWindow);

	if (TTF_Init() == -1) {

		printf("TTF Initialization error: %s\n", TTF_GetError());
		return false;
	}

	return true;
}

void Graphics::Render() {
	SDL_RenderPresent(mRenderer);
}

SDL_Texture* Graphics::LoadTexture(std::string path) {
	SDL_Texture* tex = NULL;
	SDL_Surface* surface = IMG_Load(path.c_str());

	if (surface == NULL) {
		printf("Image Load Error: Path(%s) * Error(%s)\n", path.c_str(), IMG_GetError());
	}

	tex = SDL_CreateTextureFromSurface(mRenderer, surface);

	if (tex == NULL) {
		printf("Create Texture Error %s\n", SDL_GetError());
		return tex;
	}

	SDL_FreeSurface(surface);

	return tex;
}

SDL_Texture* Graphics::CreateTextTexture(TTF_Font* font, std::string text) {

	SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), {0,0,0});
	if (surface == NULL) {

		printf("Text Render Error: %s\n", TTF_GetError());
		return NULL;
	}

	SDL_Texture* tex = SDL_CreateTextureFromSurface(mRenderer, surface);
	if (tex == NULL) {

		printf("Text Texture Creation Error: %s\n", SDL_GetError());
		return NULL;
	}

	SDL_FreeSurface(surface);
	return tex;
}

void Graphics::ClearBackBuffer() {
	SDL_RenderClear(mRenderer);
}

void Graphics::DrawTexture(SDL_Texture* tex, SDL_Rect* clip, SDL_Rect* rend) {
	SDL_RenderCopy(mRenderer, tex, clip, rend);
}

