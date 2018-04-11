#ifndef _COLLISIONBOXESMM_H
#define _COLLISIONBOXESMM_H

#include "gameEntity.h"
#include "camera.h"


class CollisionBoxMM : public GameEntity {
private:

	Graphics* mGraphics;
	Texture mCollisionBoxes[46];
	
		
public:	
	static CollisionBoxMM* sInstance;
	static CollisionBoxMM* Instance();

	void DrawCollisions(Camera*);
	
	Texture GetCollisons() { return mCollisionBoxes[46]; }

	CollisionBoxMM(float, float);
	CollisionBoxMM();
	~CollisionBoxMM();
	void Render();

};

#endif // !_COLLISIONBOXESMM_H

