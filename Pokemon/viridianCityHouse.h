#ifndef _VIRIDIANCITYHOUSE_H
#define _VIRIDIANCITYHOUSE_H

#include "gameEntity.h"

class ViridianCityHouse : GameEntity {
private:

	Texture
		*mBookshelf1_1, *mBookshelf1_2, *mBookshelf2_1, *mBookshelf2_2, *mChair, *mClipboard, *mExit, *mFloor, 
		*mFlower1, *mFlower2, *mPicture, *mTable1, *mTable2, *mTable3, *mTable4, *mWall, *mWindow;

	int map[8][8] = 
	{	
			{ 2,2,14,16,5,15,14,0 },
			{ 3,3,7,7,7,7,7,1 },
			{ 7,7,7,7,7,7,7,7 },
			{ 7,7,4,10,11,4,7,7 },
			{ 7,7,4,12,13,4,7,7 },
			{ 7,7,7,7,7,7,7,7 },
			{ 8,7,7,7,7,7,7,8 },
			{ 9,7,6,6,7,7,7,9 },
		
	};
		 
	Graphics* mGraphics;
	int tile;
	void DrawMap(int);
public:

	ViridianCityHouse(float, float);
	~ViridianCityHouse();
	void Render();
	void Update();

};

#endif // !_VIRIDIANCITYHOUSE_H

