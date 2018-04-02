#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "graphics.h"
#include "timer.h"
#include "animatedTexture.h"
<<<<<<< HEAD
#include "menuManager.h"
=======
#include "levelmanager.h"
#include "userInput.h"
>>>>>>> MIKE

class GameManager {
private:
	static GameManager* sInstance;
	const int FRAME_RATE = 60;
	bool mQuit;
	SDL_Event events;
	bool isPlaying = false;
	Graphics* mGraphics;
	Timer* mTimer;
<<<<<<< HEAD
	Texture* mTex;
	MenuManager* mMenuManager;

=======
	AnimatedTexture* mTex;
	LevelManager* mLevelManager;
	UserInput* mPlayerControls;
	static SDL_Rect Camera;
>>>>>>> MIKE
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

