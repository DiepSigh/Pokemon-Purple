#ifndef  _COLLISONBOXESPH_H
#define _COLLIISIONBOXESPH_H

#include "gameEntity.h"
#include "camera.h"

class CollisionBoxPH : public GameEntity {
private:

	Graphics * mGraphics;
	Texture mCollisionBoxes[7];
	
public:
	static CollisionBoxPH* sInstance;
	static CollisionBoxPH* Instance();

	void DrawCollisions(Camera*);


	CollisionBoxPH(float, float);
	CollisionBoxPH();
	~CollisionBoxPH();
	void Render();

};


#endif // ! _COLLISONBOXESPH_H

