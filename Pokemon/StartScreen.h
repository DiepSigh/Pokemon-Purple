#pragma once

#include "mathHelper.h"
#include "animatedTexture.h"
#include "gameEntity.h"
#include "AudioManager.h"
#include "assetManager.h"

class StartScreen : public GameEntity {

public:
	StartScreen();
	StartScreen(float, float, Texture*);
	StartScreen(float, float, AnimatedTexture*);
	~StartScreen();
	void Render();
	void Update();
	StartScreen *BGStartScreen;
	StartScreen *StartChar;
	AnimatedTexture *mIntroChar;
	StartScreen *StartPokemon;


private:
	Graphics *mGraphics;
	AudioManager *mIntro;
	bool isPlaying;
	AssetManager *mAssetManager;

};
