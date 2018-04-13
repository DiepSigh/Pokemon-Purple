#ifndef _REDHOUSE_H
#define _REDHOUSE_H

#include "mapsLoader.h"

class RedHouse : public MapsLoader {

private:

	Texture
		**mBookshelf1_1, **mBookshelf1_2, **mBookshelf2_1, **mBookshelf2_2, **mChair, **mExit, **mFloor,
		**mFlower1, **mFlower2, **mPicture, **mTable1, **mTable2, **mTable3, **mTable4, **mWall, **mWindow;


	int map[8][8] = 
	{
				{ 2,2,13,8,13,14,13,0 },
				{ 3,3,20,20,20,20,20,1 },
				{ 20,20,20,20,20,20,20,20 },
				{ 20,20,4,9,10,4,20,20 },
				{ 20,20,4,11,12,4,20,20 },
				{ 20,20,20,20,20,20,20,20 },
				{ 6,20,20,20,20,20,20,6 },
				{ 7,20,5,5,20,20,20,7 },	
	
	};

	Graphics* mGraphics;
	int tile;
	void DrawMap(int);

public:

	RedHouse(float, float);
	~RedHouse();
	void Render();
	void Update();
	
};

#endif // !_REDHOUSE_H

