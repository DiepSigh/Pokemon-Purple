#include "camera.h"

Camera* Camera::sInstance = nullptr;
bool Camera::sInitialized = false;

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
	//GetCamXPos() + GetCamYPos() / 2 == (GetPlayerXPos() + GetPlayerYPos()) / 2;
//SET THESE VALUSE^
}
