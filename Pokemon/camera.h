#ifndef CAMERA_H
#define CAMERA_H

#include "SDL_Rect.h"
#include "graphics.h"

class Camera {
	Camera();
	Camera(SDL_Rect, int, int);	

public:
	static SDL_Rect cameraRect;
	int screenWidth = Graphics::SCREEN_WIDTH;
	int screenHeight = Graphics::SCREEN_WIDTH;
private:
	
};


#endif