#include "camera.h"


Camera::Camera() {}

Camera::Camera(SDL_Rect, int screenWidth,int screenHeight) {

}

SDL_Rect Camera::m_cameraRect = { 0, 0, Graphics::SCREEN_WIDTH, Graphics::SCREEN_HEIGHT };

void Camera::UpdatePos() {
	//cameraRect.x = Player.GetComponent<TransformComponent>().position.x - Graphics::SCREEN_WIDTH / 2;
	//cameraRect.y = Player.GetComponent<TransformComponent>().position.y - Graphics::SCREEN_HEIGHT / 2;
	
}