#ifndef _COLLISIONBOXESMM_H
#define _COLLISIONBOXESMM_H

#include "gameEntity.h"
#include "camera.h"
#include "characters.h"
#include "AudioManager.h"

#include <iostream>


class CollisionBoxMM : public GameEntity {
private:

	Graphics* mGraphics;
	Texture mCollisionBoxes[47];
	
		
public:	
	static CollisionBoxMM* sInstance;
	static CollisionBoxMM* Instance();

	void DrawCollisions(Camera*);

	void CheckMoveRight(Characters*, Camera*, AudioManager*, CollisionBoxMM*);
	void CheckMoveLeft(Characters*, Camera*, AudioManager*, CollisionBoxMM*);
	void CheckMoveUp(Characters*, Camera*, AudioManager*, CollisionBoxMM*);
	void CheckMoveDown(Characters*, Camera*, AudioManager*, CollisionBoxMM*);
	
	float GetCollisonX(int num) { return mCollisionBoxes[num].GetPosX(); }
	float GetCollisonY(int num) { return mCollisionBoxes[num].GetPosY(); }
	float GetCollisonW(int num) { return mCollisionBoxes[num].GetPosWidth(); }
	float GetCollisonH(int num) { return mCollisionBoxes[num].GetPosHeight(); }

	CollisionBoxMM(float, float);
	CollisionBoxMM();
	~CollisionBoxMM();
	void Render();

};

#endif // !_COLLISIONBOXESMM_H

