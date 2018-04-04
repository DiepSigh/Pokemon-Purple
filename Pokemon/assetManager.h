#ifndef ASSETSMANAGER_H
#define ASSETSMANAGER_H

#include "graphics.h"
#include "SDL_mixer.h"
#include <map>

class AssetManager {
private:
	static AssetManager* sInstance;
	std::map<std::string, SDL_Texture*> mTexture;
	std::map<std::string, SDL_Texture*>mText;
	std::map<std::string, TTF_Font*>mFonts;
	std::map<std::string, Mix_Music*>mMusic; // By Canados
	std::map<std::string, Mix_Chunk*>mSFX; // By Canados


public:
	static AssetManager* Instance();
	static void Release();
	SDL_Texture* GetTexture(std::string);
	SDL_Texture* GetText(std::string text, std::string filename, int size);

	Mix_Music* GetMusic(std::string filename); // By Canados
	Mix_Chunk* GetSFX(std::string filename); // By Canados


private:
	AssetManager();
	~AssetManager();

	TTF_Font* GetFont(std::string filename, int size);
};
#endif // !ASSETSMANAGER_H

