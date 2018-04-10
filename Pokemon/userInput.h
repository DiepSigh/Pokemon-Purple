#ifndef USERINPUT_H
#define USERINPUT_H

#include "SDL.h"
#include <iostream>
#include "SDL_keycode.h"
#include "levelManager.h"
#include "menuManager.h"

class UserInput : public Menu{

public:
	UserInput();
	void Input(float dt);
	void Input(MenuManager*, float);

private:
	SDL_Event events;
	LevelManager* mLevelManager;
	MenuManager* mMenu;
};

#endif
