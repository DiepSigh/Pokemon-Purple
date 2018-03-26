#include "playerWalk.h"

PlayerWalk::PlayerWalk(){}

void PlayerWalk::Input(){
	printf("test\n");

	while (SDL_PollEvent(&events) != 0) {
		if (events.type == SDL_QUIT) {
			mQuit = true;
		}
	}

	switch (events.type) {
	case SDL_KEYDOWN:
		switch (events.key.keysym.sym) {
		case SDLK_LEFT:
			printf("you clicked left arrow\n");
			break;

		case SDLK_RIGHT:
			printf("you cliked right arrow\n");
			break;

		case SDLK_UP:
			printf("you clicked up arrow\n");
			break;

		case SDLK_DOWN:
			printf("you clicked down arrow\n");
		}
	}
}

void PlayerWalk::moveLeft(){}

void PlayerWalk::moveRight(){}

void PlayerWalk::moveUp(){}

void PlayerWalk::moveDown(){}
