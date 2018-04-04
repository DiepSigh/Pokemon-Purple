#ifndef CAMERA_H
#define CAMERA_H

//APRIL 4th 10:02AM

#include "camera.h"
#include "characters.h"


class Camera {

private:
	static Camera* sInstance;
	static bool sInitialized;

public:
	static Camera* Instance();
	static bool Initialized();
	void UpdatePos();

	//GETTERS
	float GetPlayerXPos() { return mPlayerXPos; }
	float GetPlayerYPos() { return mPlayerYPos; }
	float GetCamXPos() { return mCamXPos; }
	float GetCamYPos() { return mCamYPos; }
	//Camera* GetCamXPos;
	//Camera* GetCamXPos() { return mCamXPos; }


	//SETTERS
	void SetPlayerXPos(int playerx) { mPlayerXPos = playerx; }
	void SetPlayerYPos(int playery) { mPlayerYPos = playery; }	
	void SetCamXPos(float camx) { mPlayerXPos = camx; }
	void SetCamYPos(float camy) { mPlayerYPos = camy; }
	static SDL_Rect mMainCamera;

private:
	Camera();
	~Camera();

	float mPlayerXPos;
	float mPlayerYPos;	
	float mCamXPos;
	float mCamYPos;
};


#endif // !CAMERA_H

