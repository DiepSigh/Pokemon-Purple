#include "camera.h"
#include "levelManager.h"

Camera* Camera::sInstance = nullptr;
bool Camera::sInitialized = false;
SDL_Rect Camera::mMainCamera = { 0,0,800,640 };
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
	mMainCamera.x = mPlayerXPos - mMainCamera.w / 2;
	mMainCamera.y = mPlayerYPos - mMainCamera.h / 2;

	if (mMainCamera.x < 0) { mMainCamera.x = 0; }
	if (mMainCamera.y < 0) { mMainCamera.y = 0; }
	if (mMainCamera.x > mMainCamera.w) { mMainCamera.x = mMainCamera.w; }
	if (mMainCamera.y > mMainCamera.h) { mMainCamera.y = mMainCamera.h; }

}

