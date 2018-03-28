#ifndef _STARTROOM_H
#define _STARTROOM_H

#include "animatedTexture.h"

class StartRoom : public AnimatedTexture {

private:

	AnimatedTexture
	*mComputer1, *mWall1, *mWall2, *mWall3, *mWall4, *mWall5, *mWall6, *mWall7,
	*mComputer2, *mTable1, *mTable2, *mFloor1, *mFloor2, *mFloor3, *mFloor4, *mStairs,
	*mFloor5, *mFloor6, *mFloor7, *mFloor8, *mFloor9, *mFloor10, *mFloor11, *mFloor12,
	*mFloor13, *mFloor14, *mFloor15, *mFloor16, *mFloor17, *mFloor18, *mFloor19, *mFloor20,
	*mFloor21, *mFloor22, *mFloor23, *mTelevision, *mFloor24, *mFloor25, *mFloor26, *mFloor27,
	*mFloor28, *mFloor29, *mFloor30, *mConsole, *mFloor31, *mFloor32, *mFloor33, *mFloor34,
	*mBed1, *mFloor35, *mFloor36, *mFloor37, *mFloor38, *mFloor39, *mFlower1, *mFloor40,
	*mBed2, *mFloor41, *mFloor42, *mFloor43, *mFloor44, *mFloor45, *mFlower2, *mFloor46;

	AnimatedTexture *tileSet[64] = 
	{	mComputer1, mWall1, mWall2, mWall3, mWall4, mWall5, mWall6, mWall7,
		mComputer2, mTable1, mTable2, mFloor1, mFloor2, mFloor3, mFloor4, mStairs,
		mFloor5, mFloor6, mFloor7, mFloor8, mFloor9, mFloor10, mFloor11, mFloor12,
		mFloor13, mFloor14, mFloor15, mFloor16, mFloor17, mFloor18, mFloor19, mFloor20,
		mFloor21, mFloor22, mFloor23, mTelevision, mFloor24, mFloor25, mFloor26, mFloor27,
		mFloor28, mFloor29, mFloor30, mConsole, mFloor31, mFloor32, mFloor33, mFloor34,
		mBed1, mFloor35, mFloor36, mFloor37, mFloor38, mFloor39, mFlower1, mFloor40,
		mBed2, mFloor41, mFloor42, mFloor43, mFloor44, mFloor45, mFlower2, mFloor46
	};

	int xPos;
	int yPos;
	Graphics* mGraphics;


public:
	StartRoom();
	~StartRoom();
	virtual void Render();
	virtual void Update();
	int GetPosX() { return xPos; }
	int GetPosY() { return yPos; }
	

	inline AnimatedTexture* GetComputer1() { return mComputer1; }
	inline AnimatedTexture* GetWall1() { return mWall1; }
	inline AnimatedTexture* GetWall2() { return mWall2; }
	inline AnimatedTexture* GetWall3() { return mWall3; }
	inline AnimatedTexture* GetWall4() { return mWall4; }
	inline AnimatedTexture* GetWall5() { return mWall5; }
	inline AnimatedTexture* GetWall6() { return mWall6; }
	inline AnimatedTexture* GetWall7() { return mWall7; }
	
	inline AnimatedTexture* GetComputer2() { return mComputer2; }
	inline AnimatedTexture* GetTable1() { return mTable1; }
	inline AnimatedTexture* GetTable2() { return mTable2; }
	inline AnimatedTexture* GetFloor1() { return mFloor1; }
	inline AnimatedTexture* GetFloor2() { return mFloor2; }
	inline AnimatedTexture* GetFloor3() { return mFloor3; }
	inline AnimatedTexture* GetFloor4() { return mFloor4; }
	inline AnimatedTexture* GetStairs() { return mStairs; }

	inline AnimatedTexture* GetFloor5() { return mFloor5; }
	inline AnimatedTexture* GetFloor6() { return mFloor6; }
	inline AnimatedTexture* GetFloor7() { return mFloor7; }
	inline AnimatedTexture* GetFloor8() { return mFloor8; }
	inline AnimatedTexture* GetFloor9() { return mFloor9; }
	inline AnimatedTexture* GetFloor10() { return mFloor10; }
	inline AnimatedTexture* GetFloor11() { return mFloor11; }
	inline AnimatedTexture* GetFloor12() { return mFloor12; }

	inline AnimatedTexture* GetFloor13() { return mFloor13; }
	inline AnimatedTexture* GetFloor14() { return mFloor14; }
	inline AnimatedTexture* GetFloor15() { return mFloor15; }
	inline AnimatedTexture* GetFloor16() { return mFloor16; }
	inline AnimatedTexture* GetFloor17() { return mFloor17; }
	inline AnimatedTexture* GetFloor18() { return mFloor18; }
	inline AnimatedTexture* GetFloor19() { return mFloor19; }
	inline AnimatedTexture* GetFloor20() { return mFloor20; }

	inline AnimatedTexture* GetFloor21() { return mFloor21; }
	inline AnimatedTexture* GetFloor22() { return mFloor22; }
	inline AnimatedTexture* GetFloor23() { return mFloor23; }
	inline AnimatedTexture* GetTelevision() { return mTelevision; }
	inline AnimatedTexture* GetFloor24() { return mFloor24; }
	inline AnimatedTexture* GetFloor25() { return mFloor25; }
	inline AnimatedTexture* GetFloor26() { return mFloor26; }
	inline AnimatedTexture* GetFloor27() { return mFloor27; }

	inline AnimatedTexture* GetFloor28() { return mFloor28; }
	inline AnimatedTexture* GetFloor29() { return mFloor29; }
	inline AnimatedTexture* GetFloor30() { return mFloor30; }
	inline AnimatedTexture* GetConsole() { return mConsole; }
	inline AnimatedTexture* GetFloor31() { return mFloor31; }
	inline AnimatedTexture* GetFloor32() { return mFloor32; }
	inline AnimatedTexture* GetFloor33() { return mFloor33; }
	inline AnimatedTexture* GetFloor34() { return mFloor34; }
	
	inline AnimatedTexture* GetBed1() { return mBed1; }
	inline AnimatedTexture* GetFloor35() { return mFloor35; }
	inline AnimatedTexture* GetFloor36() { return mFloor36; }
	inline AnimatedTexture* GetFloor37() { return mFloor37; }
	inline AnimatedTexture* GetFloor38() { return mFloor38; }
	inline AnimatedTexture* GetFloor39() { return mFloor39; }
	inline AnimatedTexture* GetFlower() { return mFlower1; }
	inline AnimatedTexture* GetFloor40() { return mFloor40; }

	inline AnimatedTexture* GetBed2() { return mBed2; }
	inline AnimatedTexture* GetFloor41() { return mFloor41; }
	inline AnimatedTexture* GetFloor42() { return mFloor42; }
	inline AnimatedTexture* GetFloor43() { return mFloor43; }
	inline AnimatedTexture* GetFloor44() { return mFloor44; }
	inline AnimatedTexture* GetFloor45() { return mFloor45; }
	inline AnimatedTexture* GetFlower2() { return mFlower2; }
	inline AnimatedTexture* GetFloor46() { return mFloor46; }
	


};

#endif // !STARTROOM_H

