#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "graphics.h"
#include "timer.h"
#include "animatedTexture.h"
#include "menuManager.h"
#include "levelmanager.h"
#include "camera.h"
#include "userInput.h"
#include "AudioManager.h"

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
	AudioManager* mAudioMgr;
	PkmnState* mPokeState;
	Camera* mCamera;
	GameManager();
	~GameManager();
	Options* mOptions;

public:
	static GameManager* Instance();
	static void Release();
	void Run();
	bool GetIsPlaying() { return isPlaying; }
	void SetIsPlaying(bool playing) { isPlaying = playing; }
};

#endif // !GAMEMANAGER_H

