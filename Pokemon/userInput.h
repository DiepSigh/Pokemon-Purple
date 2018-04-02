#ifndef USERINPUT_H
#define USERINPUT_H

#include "SDL.h"
#include <iostream>
#include "SDL_keycode.h"
#include "levelManager.h"

class UserInput{
public:
	UserInput();
	void Input();

private:
	SDL_Event events;
	LevelManager* mLevelManager;
	
};

#endif
