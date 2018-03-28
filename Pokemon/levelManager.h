#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H


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

private:
	LevelManager();
	~LevelManager();

	int mMapId;
	float mNewPlayerXPos;
	float mNewPlayerYPos;
	//Map1* map1;
};


#endif // !LEVELMANAGER_H

