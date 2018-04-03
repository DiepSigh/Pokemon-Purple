#include "userInput.h"


UserInput::UserInput(){
	mLevelManager = LevelManager::Instance();

	mMenu = MenuManager::Instance();
}

void UserInput::Input(){
		
	while (SDL_PollEvent(&events) != 0) {
		if (events.type == SDL_QUIT) {
			//mQuit = true;
		}

		//Example of keyboard/mouse functionality

		switch (events.type) {
		case SDL_KEYDOWN:
			switch (events.key.keysym.sym) {
			
			case SDLK_LEFT:
				//mLevelManager->moveLeft();
				break;

			case SDLK_RIGHT:
				//mLevelManager->moveRight();
				break;

			case SDLK_UP:
				mMenu->CursorMoveUp();
				//mLevelManager->moveUp();
				break;

			case SDLK_DOWN:
				mMenu->CursorMoveDown();
				//mLevelManager->moveDown();
				break;

			case SDLK_ESCAPE:
				//mQuit = true;
				break;
			}
			break;

		case SDL_KEYUP:
			switch (events.key.keysym.sym) {

			case SDLK_a:
				printf("You pressed 'a'\n");
				break;

			case SDLK_s:
				printf("You pressed 's'\n");
				break;

			case SDLK_c:
				break;

			}
			break;
		}

	}
}