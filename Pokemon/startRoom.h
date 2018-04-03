#ifndef _STARTROOM_H
#define _STARTROOM_H

#include "texture.h"
#include "gameEntity.h"

class StartRoom : public GameEntity {

private:

	Texture
	*mComputer1, *mComputer2, *mBed1, *mBed2, *mConsole, *mDownstairs, *mFloor,
	*mFlower1, *mFlower2, *mTableWall1, *mTableWall2, *mTable1, *mTable2, *mTv,
	*mWindow, *mWall;


	int map[8][8] = 
	{ 
					{ 0,2,3,6,6,7,6,7 },
					{ 1,4,5,20,20,20,20,8 },
					{ 20,20,20,20,20,20,20,20 },
					{ 20,20,20,20,20,20,20,20 },
					{ 20,20,20,9,20,20,20,20 },
					{ 20,20,20,10,20,20,20,20 },
					{ 11,20,20,20,20,20,13,20 },
					{ 12,20,20,20,20,20,14,20 }, 
	};

	Graphics* mGraphics;
	int tile;
	void DrawMap(int);

public:
	StartRoom(float, float);
	~StartRoom();
	void Render();
	void Update();

};

#endif // !STARTROOM_H

