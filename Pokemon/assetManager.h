#ifndef ASSETSMANAGER_H
#define ASSETSMANAGER_H

#include "graphics.h"
#include <map>

class AssetManager {
private:
	static AssetManager* sInstance;
	std::map<std::string, SDL_Texture*> mTexture;
	std::map<std::string, SDL_Texture*>mText;
	std::map<std::string, TTF_Font*>mFonts;


public:
	static AssetManager* Instance();
	static void Release();
	SDL_Texture* GetTexture(std::string);
	SDL_Texture* GetText(std::string text, std::string filename, int size);

private:
	AssetManager();
	~AssetManager();

	TTF_Font* GetFont(std::string filename, int size);
};
#endif // !ASSETSMANAGER_H

