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
	
	Texture *mCollisions, *mExit;
	Texture mCollisionBoxes[7];
	Texture mOutOfHouse[1];
	
public:
	static CollisionBoxPH* sInstance;
	static CollisionBoxPH* Instance();

	
	void DrawCollisions(Camera*);
	void DrawExitTile(Camera*);

	void CheckMoveRight(Characters*, Camera*, AudioManager*, CollisionBoxPH*);
	void CheckMoveLeft(Characters*, Camera*, AudioManager*, CollisionBoxPH*);
	void CheckMoveUp(Characters*, Camera*, AudioManager*, CollisionBoxPH*);
	void CheckMoveDown(Characters*, Camera*, AudioManager*, CollisionBoxPH*);

	float GetCollisonX(int num) { return mCollisionBoxes[num].GetPosX(); }
	float GetCollisonY(int num) { return mCollisionBoxes[num].GetPosY(); }
	float GetCollisonW(int num) { return mCollisionBoxes[num].GetPosWidth(); }
	float GetCollisonH(int num) { return mCollisionBoxes[num].GetPosHeight(); }

	float GetExitTileX(int num) { return mOutOfHouse[num].GetPosX(); }
	float GetExitTileY(int num) { return mOutOfHouse[num].GetPosY(); }
	float GetExitTileW(int num) { return mOutOfHouse[num].GetPosWidth(); }
	float GetExitTileH(int num) { return mOutOfHouse[num].GetPosHeight(); }


	CollisionBoxPH(float, float, Camera*);
	CollisionBoxPH();
	~CollisionBoxPH();
	void Render();

};


#endif // ! _COLLISONBOXESPH_H

