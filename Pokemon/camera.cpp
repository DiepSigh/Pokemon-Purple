#include "camera.h"
#include "gameManager.h"


Camera::Camera() {}

Camera::Camera(SDL_Rect, int screenWidth,int screenHeight) {
	screenWidth = 800;
	screenHeight = 640;
}
	SDL_Rect Camera::cameraRect = { 0, 0,screenWidth, screenHeight };
