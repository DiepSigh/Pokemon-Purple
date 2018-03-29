#ifndef _STARTROOM_H
#define _STARTROOM_H

#include "gameEntity.h"

class StartRoom : public GameEntity {

private:

	Texture
	*mComputer1, *mComputer2, *mBed1, *mBed2, *mConsole, *mDownstairs, *mFloor,
	*mFlower1, *mFlower2, *mTableWall1, *mTableWall2, *mTable1, *mTable2, *mTv,
	*mWindow, *mWall;

	// array for variables
	/*Texture *tileSet[64] = 
	{	mComputer1, mWall1, mWall2, mWall3, mWall4, mWall5, mWall6, mWall7,
		mComputer2, mTable1, mTable2, mFloor1, mFloor2, mFloor3, mFloor4, mStairs,
		mFloor5, mFloor6, mFloor7, mFloor8, mFloor9, mFloor10, mFloor11, mFloor12,
		mFloor13, mFloor14, mFloor15, mFloor16, mFloor17, mFloor18, mFloor19, mFloor20,
		mFloor21, mFloor22, mFloor23, mTelevision, mFloor24, mFloor25, mFloor26, mFloor27,
		mFloor28, mFloor29, mFloor30, mConsole, mFloor31, mFloor32, mFloor33, mFloor34,
		mBed1, mFloor35, mFloor36, mFloor37, mFloor38, mFloor39, mFlower1, mFloor40,
		mBed2, mFloor41, mFloor42, mFloor43, mFloor44, mFloor45, mFlower2, mFloor46
	};*/ 

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

	int xPos;
	int yPos;
	Graphics* mGraphics;
	int tile;

	void DrawMap(int);
	//Texture* mTile;

public:
	StartRoom(float, float);
	~StartRoom();
	virtual void Render();
	virtual void Update();
	
	inline Texture* GetComputer1() { return mComputer1; }
	inline Texture* GetComputer2() { return mComputer2; }
	inline Texture* GetTable1() { return mTable1; }
	inline Texture* GetTable2() { return mTable2; }
	inline Texture* GetTableWall1() { return mTableWall1; }
	inline Texture* GetTableWall2() { return mTableWall2; }
	inline Texture* GetTv() { return mTv; }
	inline Texture* GetWindow() { return mWindow; }
	inline Texture* GetWall() { return mWall; }
	inline Texture* GetBed1() { return mBed1; }
	inline Texture* GetBed2() { return mBed2; }
	inline Texture* GetConsole() { return mConsole; }
	inline Texture* GetDownstairs() { return mDownstairs; }
	inline Texture* GetFloor() { return mFloor; }
	inline Texture* GetFlower1() { return mFlower1; }
	inline Texture* GEtFlower2() { return mFlower2; }

};

#endif // !STARTROOM_H

