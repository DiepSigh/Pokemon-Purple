#ifndef  _COLLISONBOXESPH_H
#define _COLLIISIONBOXESPH_H

#include "gameEntity.h"
#include "camera.h"
#include "characters.h"
#include "AudioManager.h"

#include <iostream>

class CollisionBoxPH : public GameEntity {
private:

	Graphics* mGraphics;
	Texture mCollisionBoxes[7];
	
public:
	static CollisionBoxPH* sInstance;
	static CollisionBoxPH* Instance();

	void DrawCollisions(Camera*);
	

	void CheckMoveRight(Characters*, Camera*, AudioManager*, CollisionBoxPH*);
	void CheckMoveLeft(Characters*, Camera*, AudioManager*, CollisionBoxPH*);
	void CheckMoveUp(Characters*, Camera*, AudioManager*, CollisionBoxPH*);
	void CheckMoveDown(Characters*, Camera*, AudioManager*, CollisionBoxPH*);

	float GetCollisonX(int num) { return mCollisionBoxes[num].GetPosX(); }
	float GetCollisonY(int num) { return mCollisionBoxes[num].GetPosY(); }
	float GetCollisonW(int num) { return mCollisionBoxes[num].GetPosWidth(); }
	float GetCollisonH(int num) { return mCollisionBoxes[num].GetPosHeight(); }


	CollisionBoxPH(float, float, Camera*);
	CollisionBoxPH();
	~CollisionBoxPH();
	void Render();

};


#endif // ! _COLLISONBOXESPH_H

