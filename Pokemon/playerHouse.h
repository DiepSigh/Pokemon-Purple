#ifndef _PLAYERROOM_H
#define _PLAYERROOM_H

#include "mapsLoader.h"

class PlayerHouse : public MapsLoader {
private:

	Texture
		**mBookshelf1, **mBookshelf2, **mChair, **mExit, **mFloor, **mTable1,
		**mTable2, **mTable3, **mTable4, **mTv, **mUpstairs, **mWall, **mWindow;

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

public:
	PlayerHouse(float, float);
	~PlayerHouse();
	void Render();
	void Update();

		
};



#endif // !_PLAYERROOM_H
