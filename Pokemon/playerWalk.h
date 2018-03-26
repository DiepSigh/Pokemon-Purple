#ifndef PLAYERWALK_H
#define PLAYERWALK_H

#include "gameEntity.h"
#include <SDL.h>
#include <iostream>

class PlayerWalk : public GameEntity {
public:
	PlayerWalk();
	void Input();
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();

private:
	SDL_Event events;

};


#endif
