#include "userInput.h"


UserInput::UserInput(){
	mLevelManager = LevelManager::Instance();
}

void UserInput::Input(){
		while (SDL_PollEvent(&events) != 0) {
		if (events.type == SDL_QUIT) {
			//mQuit = true;
		}
		//Keyboard functionality
		switch (events.type) {
		case SDL_KEYDOWN:
			switch (events.key.keysym.sym) {
			
			case SDLK_LEFT:
				mLevelManager->moveLeft();
				printf("You pressed left arrow\n");
				break;

			case SDLK_RIGHT:
				mLevelManager->moveRight();
				break;

			case SDLK_UP:
				mLevelManager->moveUp();
				break;

			case SDLK_DOWN:
				mLevelManager->moveDown();
				break;

			case SDLK_ESCAPE:
				//mQuit = true;
				break;
			}
			break;

		case SDL_KEYUP:
			switch (events.key.keysym.sym) {

			case SDLK_a:
				break;

			case SDLK_s:
				break;

			case SDLK_c:
				break;
			}
			break;
		}

	}
}