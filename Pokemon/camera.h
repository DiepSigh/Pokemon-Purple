#ifndef CAMERA_H
#define CAMERA_H

class Camera {
	Camera();
	Camera(SDL_Rect, int, int);	

public:
	static SDL_Rect cameraRect;
	static int screenWidth;
	static int screenHeight;
private:
	
};


#endif