#include "userInput.h"


UserInput::UserInput(){
	mLevelManager = LevelManager::Instance();
}

void UserInput::Input(MenuManager* menuM, Options* menuO) {
	while (SDL_PollEvent(&events) != 0) {
		if (events.type == SDL_QUIT) {
				//mQuit = true;
			}
		switch (events.type) {
			case SDL_KEYDOWN:
			switch (events.key.keysym.sym) {

			case SDLK_LEFT:
				// Option Menu Left
				if (menuM->OptsMnuisActive) {
					menuM->mOptions->oCursorLeft();
				}
				//World Control
				else if (menuM->StrtMnuisActive == false) {
					mLevelManager->moveLeft();
				}
				break;

			case SDLK_RIGHT:
				//Option Menu Right
				if (menuM->OptsMnuisActive) {
					menuM->mOptions->oCursorRight();
				}
				//World Control
				if (menuM->StrtMnuisActive == false && menuM->OptsMnuisActive == false) {
					mLevelManager->moveRight();
				}
				break;

			case SDLK_UP:
				//Main Menu Up
				if (menuM->StrtMnuisActive) {
					menuM->CursorMoveUp();
				}
				// Options Menu Up
				if (menuM->OptsMnuisActive) {
					menuM->mOptions->oCursorUp();
				}
				if (menuM->PokedexisActive) {
					menuM->mPokeDex->CursorPMoveUp();
				}
				//World Control Up
				else if (menuM->StrtMnuisActive == false) {
					mLevelManager->moveUp();
				}
				break;

			case SDLK_DOWN:
				//Main Menu Down
				if (menuM->StrtMnuisActive) {
					menuM->CursorMoveDown();
				}
				//Options Menu Down
				if (menuM->OptsMnuisActive) {
					menuM->mOptions->oCursorDown();
				}
				if (menuM->PokedexisActive) {
					menuM->mPokeDex->CursorPMoveDown();
				}
				//World Control Down
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
					if (menuM->OptsMnuisActive) {
						menuM->OptsMnuisActive = false;
						menuM->StrtMnuisActive = true;
					}
					if (menuM->PokedexisActive) {
						if (menuM->mPokeDex->Selected) {
							menuM->mPokeDex->PokeDeselect();
						}
						else if (menuM->mPokeDex->Selected == false){
							menuM->PokedexisActive = false;
							menuM->StrtMnuisActive = true;
							menuM->mPokeDex->PokeDexReset();
						}
					}
					//World Control
					break;

				case SDLK_s:
					if (menuM->StrtMnuisActive) {
						menuM->MenuState();
					}
					else if (menuM->StrtMnuisActive == false && menuM->OptsMnuisActive) {
						if (menuM->mOptions->CursorO->GetPosY() == menuM->mOptions->Cancel->GetPosY() - 5 && menuM->mOptions->CursorO->GetPosX() == menuM->mOptions->Cancel->GetPosX() - 40) {
							menuM->OptsMnuisActive = false;
							menuM->StrtMnuisActive = true;
						}
					}
					if (menuM->PokedexisActive && menuM->mPokeDex->Selected) {
						menuM->mPokeDex->DexData();
					}
					if (menuM->PokedexisActive) {
						menuM->StrtMnuisActive = false;
						menuM->mPokeDex->PokemonSelected();
					}

					

					//World Control
					break;

				case SDLK_c:
					//Opens Menu
					if (menuM->StrtMnuisActive == false) {
						menuM->StrtMnuisActive = true;
					}
					else if (menuM->StrtMnuisActive) {
						menuM->StrtMnuisActive = false;
					}
					if (menuM->OptsMnuisActive == true) {
						menuM->OptsMnuisActive = false;
						menuM->StrtMnuisActive = true;
					}
					if (menuM->PlayerMnuisActive = true) {
						menuM->PlayerMnuisActive = false;
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