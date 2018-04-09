#ifndef _COLLISIONBOXES_H
#define _COLLISIONBOXES_H

#include "mapsLoader.h"


class CollisionBox : public MapsLoader {
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
	CollisionBox* Rect11;
	CollisionBox* Rect12;
	CollisionBox* Rect13;
	CollisionBox* Rect14;
	CollisionBox* Rect15;
	CollisionBox* Rect16;
	CollisionBox* Rect17;
	CollisionBox* Rect18;
	CollisionBox* Rect19;
	CollisionBox* Rect20;
	CollisionBox* Rect21;
	CollisionBox* Rect22;

	CollisionBox(float x, float y, Texture* tex);
	CollisionBox();
	~CollisionBox();
	void Render();

};

#endif // !_COLLISIONBOXES_H

