#ifndef _STARTROOM_H
#define _STARTROOM_H

#include "texture.h"

class StartRoom : public Texture {

private:

	Texture
	*mComputer1, *mWall1, *mWall2, *mWall3, *mWall4, *mWall5, *mWall6, *mWall7,
	*mComputer2, *mTable1, *mTable2, *mFloor1, *mFloor2, *mFloor3, *mFloor4, *mStairs,
	*mFloor5, *mFloor6, *mFloor7, *mFloor8, *mFloor9, *mFloor10, *mFloor11, *mFloor12,
	*mFloor13, *mFloor14, *mFloor15, *mFloor16, *mFloor17, *mFloor18, *mFloor19, *mFloor20,
	*mFloor21, *mFloor22, *mFloor23, *mTelevision, *mFloor24, *mFloor25, *mFloor26, *mFloor27,
	*mFloor28, *mFloor29, *mFloor30, *mConsole, *mFloor31, *mFloor32, *mFloor33, *mFloor34,
	*mBed1, *mFloor35, *mFloor36, *mFloor37, *mFloor38, *mFloor39, *mFlower1, *mFloor40,
	*mBed2, *mFloor41, *mFloor42, *mFloor43, *mFloor44, *mFloor45, *mFlower2, *mFloor46;

	Texture *tileSet[64] = 
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
	

	inline Texture* GetComputer1() { return mComputer1; }
	inline Texture* GetWall1() { return mWall1; }
	inline Texture* GetWall2() { return mWall2; }
	inline Texture* GetWall3() { return mWall3; }
	inline Texture* GetWall4() { return mWall4; }
	inline Texture* GetWall5() { return mWall5; }
	inline Texture* GetWall6() { return mWall6; }
	inline Texture* GetWall7() { return mWall7; }
	
	inline Texture* GetComputer2() { return mComputer2; }
	inline Texture* GetTable1() { return mTable1; }
	inline Texture* GetTable2() { return mTable2; }
	inline Texture* GetFloor1() { return mFloor1; }
	inline Texture* GetFloor2() { return mFloor2; }
	inline Texture* GetFloor3() { return mFloor3; }
	inline Texture* GetFloor4() { return mFloor4; }
	inline Texture* GetStairs() { return mStairs; }

	inline Texture* GetFloor5() { return mFloor5; }
	inline Texture* GetFloor6() { return mFloor6; }
	inline Texture* GetFloor7() { return mFloor7; }
	inline Texture* GetFloor8() { return mFloor8; }
	inline Texture* GetFloor9() { return mFloor9; }
	inline Texture* GetFloor10() { return mFloor10; }
	inline Texture* GetFloor11() { return mFloor11; }
	inline Texture* GetFloor12() { return mFloor12; }

	inline Texture* GetFloor13() { return mFloor13; }
	inline Texture* GetFloor14() { return mFloor14; }
	inline Texture* GetFloor15() { return mFloor15; }
	inline Texture* GetFloor16() { return mFloor16; }
	inline Texture* GetFloor17() { return mFloor17; }
	inline Texture* GetFloor18() { return mFloor18; }
	inline Texture* GetFloor19() { return mFloor19; }
	inline Texture* GetFloor20() { return mFloor20; }

	inline Texture* GetFloor21() { return mFloor21; }
	inline Texture* GetFloor22() { return mFloor22; }
	inline Texture* GetFloor23() { return mFloor23; }
	inline Texture* GetTelevision() { return mTelevision; }
	inline Texture* GetFloor24() { return mFloor24; }
	inline Texture* GetFloor25() { return mFloor25; }
	inline Texture* GetFloor26() { return mFloor26; }
	inline Texture* GetFloor27() { return mFloor27; }

	inline Texture* GetFloor28() { return mFloor28; }
	inline Texture* GetFloor29() { return mFloor29; }
	inline Texture* GetFloor30() { return mFloor30; }
	inline Texture* GetConsole() { return mConsole; }
	inline Texture* GetFloor31() { return mFloor31; }
	inline Texture* GetFloor32() { return mFloor32; }
	inline Texture* GetFloor33() { return mFloor33; }
	inline Texture* GetFloor34() { return mFloor34; }
	
	inline Texture* GetBed1() { return mBed1; }
	inline Texture* GetFloor35() { return mFloor35; }
	inline Texture* GetFloor36() { return mFloor36; }
	inline Texture* GetFloor37() { return mFloor37; }
	inline Texture* GetFloor38() { return mFloor38; }
	inline Texture* GetFloor39() { return mFloor39; }
	inline Texture* GetFlower() { return mFlower1; }
	inline Texture* GetFloor40() { return mFloor40; }

	inline Texture* GetBed2() { return mBed2; }
	inline Texture* GetFloor41() { return mFloor41; }
	inline Texture* GetFloor42() { return mFloor42; }
	inline Texture* GetFloor43() { return mFloor43; }
	inline Texture* GetFloor44() { return mFloor44; }
	inline Texture* GetFloor45() { return mFloor45; }
	inline Texture* GetFlower2() { return mFlower2; }
	inline Texture* GetFloor46() { return mFloor46; }
	


};

#endif // !STARTROOM_H

