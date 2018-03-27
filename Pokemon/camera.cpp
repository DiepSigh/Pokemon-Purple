#include "camera.h"

Camera::Camera() {}

Camera::Camera(SDL_Rect, int screenWidth,int screenHeight) {

	int m_screenWidth = Graphics::SCREEN_WIDTH;
	int m_screenHeight = Graphics::SCREEN_WIDTH;
	int m_camX = 0;
	int m_camY = 0;
}

SDL_Rect Camera::m_cameraRect = { 0, 0, Graphics::SCREEN_WIDTH, Graphics::SCREEN_HEIGHT };

int Camera::getPosX(int m_camX)
{
	return m_camX;
}

int Camera::getPosY(int m_camY)
{
	return m_camY;
}

void Camera::UpdatePos(int camX, int camY) {
	//cameraRect.x = Player.GetComponent<TransformComponent>().position.x - Graphics::SCREEN_WIDTH / 2;
	//cameraRect.y = Player.GetComponent<TransformComponent>().position.y - Graphics::SCREEN_HEIGHT / 2;
}


