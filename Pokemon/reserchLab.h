#ifndef  _RESERCHLAB_H
#define _RESERCHLAB_H

#include "gameEntity.h"

class ReserchLab : public GameEntity {

	Texture
		*mBigTableBottomMiddle, *mBigTableTopLeft, *mBigTableTopMiddle, *mBigTableTopRight, *mTableBook1, *mTableBook2, *mTableBottomLeft, *mTableBottomRight,
		*mBookshelf1, *mBookshelf2, *mComputerTable1, *mComputerTable2, *mExit, *mFloor, *mFlyer, *mWall;


	int map[12][10] =
	{
				{ 14,14,14,14,13,13,10,10,10,10 },
				{ 4,5,6,7,20,20,11,11,11,11 },
				{ 8,9,8,9,20,20,20,20,20,20 },
				{ 20,20,20,20,20,20,1,2,3,20 },
				{ 20,20,20,20,20,20,8,0,9,20 },
				{ 20,20,20,20,20,20,20,20,20,20 },
				{ 10,10,10,10,20,20,10,10,10,10 },
				{ 11,11,11,11,20,20,11,11,11,11 },
				{ 20,20,20,20,20,20,20,20,20,20 },
				{ 20,20,20,20,20,20,20,20,20,20 },
				{ 20,20,20,20,20,20,20,20,20,20 },
				{ 20,20,20,20,12,12,20,20,20,20 },
	};

	Graphics* mGraphics;
	int tile;
	void DrawMap(int);

public:
	ReserchLab(float, float);
	~ReserchLab();
	void Render();
	void Update();

};


#endif //  _RESERCHLAB_H

