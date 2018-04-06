#include "userInput.h"


UserInput::UserInput(){
	mLevelManager = LevelManager::Instance();
}

void UserInput::Input(MenuManager* menuM) {
	while (SDL_PollEvent(&events) != 0) {
		if (events.type == SDL_QUIT) {
				//mQuit = true;
			}
		switch (events.type) {
			case SDL_KEYDOWN:
			switch (events.key.keysym.sym) {

			case SDLK_LEFT:
				//World Control
				if (menuM->StrtMnuisActive == false) {
					mLevelManager->moveLeft();
				}
				break;

			case SDLK_RIGHT:
				//World Control
				if (menuM->StrtMnuisActive == false) {
					mLevelManager->moveRight();
				}
				//printf("You pressed right arrow\n");
				break;

			case SDLK_UP:
				if (menuM->StrtMnuisActive) {
					menuM->CursorMoveUp();
				}
				//World Control
				else if (menuM->StrtMnuisActive == false) {
					mLevelManager->moveUp();
				}
				break;

			case SDLK_DOWN:
				if (menuM->StrtMnuisActive) {
					menuM->CursorMoveDown();
				}
				//World Control
				else if (menuM->StrtMnuisActive == false) {
					mLevelManager->moveDown();
				}
				break;

			case SDLK_ESCAPE:
				//mQuit = true;
				break;
			}
			break;

			case SDL_KEYUP:

			switch (events.key.keysym.sym) {
				case SDLK_a:
					if (menuM->StrtMnuisActive) {
						menuM->StrtMnuisActive = false;
					}
					//World Control
					break;

				case SDLK_s:
					if (menuM->StrtMnuisActive) {
						menuM->MenuState();
					}
					//World Control
					break;

				case SDLK_c:
					//Opens Menu
					if (menuM->StrtMnuisActive == false) {
						printf("Opening menu");
						menuM->StrtMnuisActive = true;
					}
					break;

				}
				break;
		}
	}
}


//Not needed anymore..... 
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
				mLevelManager->moveLeft();
				break;

			case SDLK_RIGHT:
				mLevelManager->moveRight();
				//printf("You pressed right arrow\n");
				break;

			case SDLK_UP:
				//mLevelManager->moveUp();
				//Cursor->CursorMoveUp();
				mMenu->Cursor->CursorMoveUp();
				//printf("You pressed up arrow\n");
				break;

			case SDLK_DOWN:
				//mLevelManager->moveDown();
				//Cursor->CursorMoveDown();
				mMenu->Cursor->CursorMoveDown();
				//printf("You pressed down arrow\n");
				break;

			case SDLK_ESCAPE:
				//mQuit = true;
				break;
			}
			break;

		case SDL_KEYUP:
			switch (events.key.keysym.sym) {

			case SDLK_a:
				//printf("You pressed 'a'\n");
				break;

			case SDLK_s:
				//printf("You pressed 's'\n");
				break;

			case SDLK_c:
				//printf("You pressed 'c'\n");
				break;

			case SDLK_UP:
				mLevelManager->NormalizeVel();
				break;

			case SDLK_DOWN:
				mLevelManager->NormalizeVel();

				break;

			case SDLK_LEFT:
				mLevelManager->NormalizeVel();

				break;

			case SDLK_RIGHT:
				mLevelManager->NormalizeVel();

				break;

			}
			break;
		}

	}
}