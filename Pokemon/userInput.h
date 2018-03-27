#ifndef USERINPUT_H
#define USERINPUT_H

#include "gameEntity.h"
#include "SDL.h"
#include <iostream>
#include "SDL_keycode.h"

class UserInput{
public:
	UserInput();
	void Input();
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void buttonA();
	void buttonS();
	void buttonEnter();

private:
	SDL_Event events;
	

};

#endif
