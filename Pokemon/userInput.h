#ifndef USERINPUT_H
#define USERINPUT_H

#include "SDL.h"
#include <iostream>
#include "SDL_keycode.h"
#include "levelManager.h"
#include "menuManager.h"
#include "battle.h"

class UserInput : public Menu{
public:
	UserInput();
	void Input();
	void Input(MenuManager*, Options*, battle*);

private:
	SDL_Event events;
	LevelManager* mLevelManager;
	MenuManager* mMenu;

};

#endif
