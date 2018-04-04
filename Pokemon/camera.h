#ifndef CAMERA_H
#define CAMERA_H

#include "characters.h"
#include "graphics.h"

class Camera : public GameEntity{

private:
	static Camera* sInstance;
	static bool sInitialized;

public:
	Camera(int,int);
	Camera();
	~Camera();

	static Camera* Instance();
	static bool Initialized();
	void UpdatePos(Characters &mPlayer);
	void Render();
	//GETTERS
	float GetPlayerXPos() { return mPlayerXPos; }
	float GetPlayerYPos() { return mPlayerYPos; }
	int GetCamXPos() { return mCamXPos; }
	int GetCamYPos() { return mCamYPos; }
	//Camera* GetCamXPos;
	//Camera* GetCamXPos() { return mCamXPos; }


	//SETTERS
	 void SetPlayerXPos(int playerx) { mPlayerXPos = playerx; }
	 void SetPlayerYPos(int playery) { mPlayerYPos = playery; }
	 void SetCamXPos(float camx) { mPlayerXPos = camx; }
	 void SetCamYPos(float camy) { mPlayerYPos = camy; }
	 static SDL_Rect mMainCamera;

private:
	
	float mPlayerXPos;
	float mPlayerYPos;	
	float mCamXPos;
	float mCamYPos;
	Graphics* mGraphics;
};


#endif // !CAMERA_H

