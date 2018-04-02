#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "graphics.h"
#include "timer.h"
//#Include "animatedTexture.h"
#include "menuManager.h"
#include "userInput.h"
#include "levelManager.h"
#include "DisplayText.h"

class GameManager {
private:
	static GameManager* sInstance;
	const int FRAME_RATE = 60;
	bool mQuit;
	SDL_Event events;
	bool isPlaying = false;
	Graphics* mGraphics;
	Timer* mTimer;
	Texture* mTex;
	MenuManager* mMenuManager;
	LevelManager* mLevelManager;
	UserInput* mPlayerControls;
	

public:
	static GameManager* Instance();
	static void Release();
	void Run();
	bool GetIsPlaying() { return isPlaying; }
	void SetIsPlaying(bool playing) { isPlaying = playing; }

private:
	GameManager();
	~GameManager();
};

#endif // !GAMEMANAGER_H

