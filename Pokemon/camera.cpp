#include "camera.h"
#include <iostream>

Camera* Camera::sInstance = nullptr;
bool Camera::sInitialized = false;
SDL_Rect Camera::mMainCamera = { 0,0,400,320 };

using namespace std;

Camera* Camera::Instance()
{
	if (sInstance == nullptr) {
		sInstance = new Camera();
	}
	return sInstance;
}

bool Camera::Initialized() {
	return sInitialized;
}

Camera::Camera() {
	//map1 = new Map1();
}

Camera::~Camera() {
	//delete map1;
	//map1 = nullptr;
}

void Camera::UpdatePos() {
	//GetCamXPos()->SetCamXPos(mPlayerXPos);
	//mMainCamera.y = mPlayerYPos;
	
//	cout << mMainCamera.x;

	//if (mMainCamera.x < 0) { mMainCamera.x = 0; }
	//if (mMainCamera.y < 0) { mMainCamera.y = 0; }
	//if (mMainCamera.x > mMainCamera.w) { mMainCamera.x = mMainCamera.w; }
	//if (mMainCamera.y > mMainCamera.h) { mMainCamera.y = mMainCamera.h; }
	
}

