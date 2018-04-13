#ifndef _PLAYERROOM_H
#define _PLAYERROOM_H

#include "gameEntity.h"
#include "camera.h"
#include "Mom.h"
#include <iostream>

class PlayerHouse : public GameEntity {
private:

	Texture
		*mBookshelf1, *mBookshelf2, *mChair, *mExit, *mFloor, *mTable1,
		*mTable2, *mTable3, *mTable4, *mTv, *mUpstairs, *mWall, *mWindow;

	int map[8][8] =
	{
			{ 0,0,9,10,9,10,9,10 },
			{ 1,1,20,7,20,20,20,8 },
			{ 20,20,20,20,20,20,20,20 },
			{ 20,20,20,20,20,20,20,20 },
			{ 20,20,2,3,4,2,20,20 },
			{ 20,20,2,5,6,2,20,20 },
			{ 20,20,20,20,20,20,20,20 },
			{ 20,20,11,11,20,20,20,20 },
	};

	Graphics* mGraphics;
	int tile;
	void DrawMap(int);
	float startYPos;
	Mom* mMom;
	Camera* mCam;
	PlayerHouse* mPlayerHouse;

public:
	PlayerHouse(float, float);
	~PlayerHouse();
	void Render();
	void Update();		
	bool isActive;
	void momLeft();
	void momRight();
	void momUp();
	void momDown();
};

#endif // !_PLAYERROOM_H
