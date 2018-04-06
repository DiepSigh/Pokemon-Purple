#ifndef _COLLISIONBOXES_H
#define _COLLISIONBOXES_H

#include "gameEntity.h"
#include "texture.h"

class CollisionBox : public GameEntity {
private:

	Graphics* mGraphics;

public:	
	static CollisionBox* sInstance;
	static CollisionBox* Instance();

	void DrawCollisions();

	CollisionBox* Rect1;
	CollisionBox* Rect2;
	CollisionBox* Rect3;
	CollisionBox* Rect4;
	CollisionBox* Rect5;
	CollisionBox* Rect6;
	CollisionBox* Rect7;
	CollisionBox* Rect8;
	CollisionBox* Rect9;
	CollisionBox* Rect10;

	CollisionBox(float x, float y, Texture* tex);
	CollisionBox();
	~CollisionBox();
	void Render();

};

#endif // !_COLLISIONBOXES_H

