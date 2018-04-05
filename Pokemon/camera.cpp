#include "camera.h"
#include <iostream>

Camera* Camera::sInstance = nullptr;
bool Camera::sInitialized = false;
SDL_Rect Camera::mMainCamera = { 1000,1000,400,320 };

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

}

Camera::Camera(int x,int y) {
	mPos.x = x;
	mPos.y = y;
	mTex = new Texture;
	mGraphics = Graphics::Instance();
}

Camera::~Camera() {
	//delete map1;
	//map1 = nullptr;
}

void Camera::UpdatePos(Characters &mPlayer) {
	//GetCamXPos()->SetCamXPos(mPlayerXPos);

	//if (mMainCamera.x < 0) { mMainCamera.x = 0; }
	//if (mMainCamera.y < 0) { mMainCamera.y = 0; }
	//if (mMainCamera.x > mMainCamera.w) { mMainCamera.x = mMainCamera.w; }
	//if (mMainCamera.y > mMainCamera.h) { mMainCamera.y = mMainCamera.h; }	
}

void Camera::Render() {
	Vector2 pos = Pos(LOCAL);
	GetmTex()->SetRenderRectX((int)(mMainCamera.x));
	GetmTex()->SetRenderRectY((int)(mMainCamera.y));
	mGraphics->DrawTexture(GetmTex()->GetSDLTex(), (GetmTex()->GetClipped()) ? &GetmTex()->GetmClipRect() : NULL, &mMainCamera);
}

