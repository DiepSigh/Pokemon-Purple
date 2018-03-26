#ifndef CAMERA_H
#define CAMERA_H

#include "SDL_Rect.h"
#include "graphics.h"

class Camera {
	Camera();
	Camera(SDL_Rect, int, int);	

public:

	static SDL_Rect m_cameraRect;
	int m_screenWidth = Graphics::SCREEN_WIDTH;
	int m_screenHeight = Graphics::SCREEN_WIDTH;
	int LEVEL_WIDTH = 1280;
	int LEVEL_HEIGHT = 960;
	void UpdatePos();

private:
	
};


#endif