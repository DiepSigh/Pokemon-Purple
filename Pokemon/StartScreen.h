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
	~StartScreen();
	void Render();
	void Update();
	StartScreen *BGStartScreen;

private:
	Graphics *mGraphics;
	AudioManager *mIntro;
	
	AssetManager *mAssetManager;
	bool isPlaying;
};
