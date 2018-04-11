#pragma once
#include"mathHelper.h"
#include"texture.h"
#include "gameEntity.h"
#include "AudioManager.h"

class StartScreen : public GameEntity {

public:
	StartScreen();
	~StartScreen();
	void Render();
	void Update();

private:
	Graphics *mGraphics;
	Texture *mTex;
	AudioManager *mIntro;
	bool isPlaying;
};
