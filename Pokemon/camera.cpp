#include "camera.h"
#include <iostream>

Camera* Camera::sInstance = nullptr;

Camera* Camera::Instance() {

	float mPosX = 0;
	float mPosY = 0;
	 
	if (sInstance == nullptr) {
		sInstance = new Camera();
	}
	return sInstance;
}

Camera::Camera() {

}
void Camera::Release() {
	delete sInstance;
	sInstance = nullptr;
}
Camera::~Camera() {

}

void Camera::Update() {

}

