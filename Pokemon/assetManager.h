#ifndef ASSETSMANAGER_H
#define ASSETSMANAGER_H

#include "graphics.h"
#include <map>

class AssetManager {
private:
	static AssetManager* sInstance;
	std::map<std::string, SDL_Texture*> mTexture;

public:
	static AssetManager* Instance();
	static void Release();
	SDL_Texture* GetTexture(std::string);

private:
	AssetManager();
	~AssetManager();
};
#endif // !ASSETSMANAGER_H

