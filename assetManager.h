#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include "graphics.h"
#include <map>

class AssetManager {
	static AssetManager* sInstance;
	std::map<std::string, SDL_Texture*> mTexture;

public:
	static AssetManager* Instance();
	static void Release();
	SDL_Texture* getTexture(std::string);

private:
	AssetManager();
	~AssetManager();
};

#endif