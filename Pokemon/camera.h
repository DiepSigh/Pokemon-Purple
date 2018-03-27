#ifndef CAMERA_H
#define CAMERA_H

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "graphics.h"

class Camera {
	Camera();
	Camera(SDL_Rect, int, int);	

public:

	static SDL_Rect m_cameraRect;
	int m_screenWidtht;
	int m_screenHeight;

	int getPosX(int);
	int getPosY(int);

	void UpdatePos(int, int);

private:

	int m_camX;
	int m_camY;

};


#endif