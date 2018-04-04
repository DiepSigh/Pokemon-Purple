#include "assetManager.h"

AssetManager* AssetManager::sInstance = NULL;

AssetManager* AssetManager::Instance() {
	if (sInstance == NULL) {
		sInstance = new AssetManager();
	}

	return sInstance;
}

void AssetManager::Release() {
	delete sInstance;
	sInstance = NULL;
}

AssetManager::AssetManager(){

}

AssetManager::~AssetManager() {
	for (auto tex : mTexture) {
		if (tex.second != NULL) {
			SDL_DestroyTexture(tex.second);
		}
	}
	mTexture.clear();

	for (auto text : mText) {
		if (text.second != NULL) {
			SDL_DestroyTexture(text.second);
		}
	}
	mText.clear();

	for (auto font : mFonts) {
		if (font.second != NULL) {
			TTF_CloseFont(font.second);
		}
	}
	mFonts.clear();
}

SDL_Texture* AssetManager::GetTexture(std::string filename) {
	std::string fullPath = SDL_GetBasePath();
	fullPath.append("Assets\\" + filename);

	if (mTexture[filename] == nullptr) {
		mTexture[fullPath] = Graphics::Instance()->LoadTexture(fullPath);
	}

	return mTexture[fullPath];
}

TTF_Font* AssetManager::GetFont(std::string filename, int size){
	std::string fullPath = SDL_GetBasePath();
	fullPath.append("Assets/" + filename);
	std::string key = fullPath + (char)size;

	if (mFonts[key] == nullptr) {

		mFonts[key] = TTF_OpenFont(fullPath.c_str(), size);
		if (mFonts[key] == nullptr) {
			//printf("Font Loading Error: %s\n font-%s, Error-%s", filename.c_str(), TTF_GetError());
		}
			
	}

	return mFonts[key];
}

SDL_Texture* AssetManager::GetText(std::string text, std::string filename, int size) {

	TTF_Font* font = GetFont(filename, size);

	std::string key = text + filename + (char)size;

	if (mText[key] == nullptr)
		mText[key] = Graphics::Instance()->CreateTextTexture(font, text);

	return mText[key];
}

//Adding music by Canados
Mix_Music* AssetManager::GetMusic(std::string filename) {

	std::string fullPath = SDL_GetBasePath();
	fullPath.append("Assets/" + filename);

	if (mMusic[fullPath] == nullptr) {
		mMusic[fullPath] = Mix_LoadMUS(fullPath.c_str());
		if (mMusic[fullPath] == NULL) {
			printf("Music Loading Error: File-%s Error-%s", filename.c_str(), Mix_GetError());
		}
	}

	return mMusic[fullPath];
}

//Adding SFX by Canados
Mix_Chunk* AssetManager::GetSFX(std::string filename) {

	std::string fullPath = SDL_GetBasePath();
	fullPath.append("Assets/" + filename);

	if (mSFX[fullPath] == nullptr) {
		mSFX[fullPath] = Mix_LoadWAV(fullPath.c_str());
		if (mSFX[fullPath] == NULL) {
			printf("SFX Loading Error: File-%s Error-%s", filename.c_str(), Mix_GetError());
		}
		
	}

	return mSFX[fullPath];

}
