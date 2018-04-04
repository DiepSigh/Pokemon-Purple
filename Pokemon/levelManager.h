#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include "characters.h"
#include "camera.h"

class LevelManager {

private:
	static LevelManager* sInstance;
	static bool sInitialized;

public:
	static LevelManager* Instance();
	static void Release();
	static bool Initialized();
	void Render();
	void Update();
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void buttonA();
	void buttonS();
	void buttonC();

private:
	LevelManager();
	~LevelManager();
	Characters* mPlayer;
	Camera* mCamera;
	int mMapId;
	float mNewPlayerXPos;
	float mNewPlayerYPos;
	//Map1* map1;
};


#endif // !LEVELMANAGER_H

