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

AssetManager::AssetManager(){}

AssetManager::~AssetManager() {
	for (auto tex : mTexture) {
		if (tex.second != NULL) {
			SDL_DestroyTexture(tex.second);
		}
	}
	mTexture.clear();
}

SDL_Texture* AssetManager::getTexture(std::string filename) {
	std::string fullPath = SDL_GetBasePath();
	fullPath.append("Assets\\" + filename);

	if (mTexture[filename] == nullptr) {
		mTexture[fullPath] = Graphics::Instance()->LoadTexture(fullPath);
	}

	return mTexture[fullPath];
}