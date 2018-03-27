#ifndef STARTROOM_H
#define STARTROOM_H

#include "animatedTexture.h"

class StartRoom : public AnimatedTexture {

protected:

	//AnimatedTexture* tileSet[64] = { mWall, mWall2, mWall3, mWall4, mWall5, mWall6, mWall7 };
	
	AnimatedTexture* mWall;
	AnimatedTexture* mWall2;
	AnimatedTexture* mWall3;
	AnimatedTexture* mWall4;
	AnimatedTexture* mWall5;
	AnimatedTexture* mWall6;
	AnimatedTexture* mWall7;

	AnimatedTexture* mStairs;
	AnimatedTexture* mTable;
	AnimatedTexture* mTable2;
	AnimatedTexture* mTelevision;
	AnimatedTexture* mConsole;

	AnimatedTexture* mFloor;
	AnimatedTexture* mFloor2;
	AnimatedTexture* mFloor3;
	AnimatedTexture* mFloor4;
	AnimatedTexture* mFloor5;
	AnimatedTexture* mFloor6;
	AnimatedTexture* mFloor7;
	AnimatedTexture* mFloor8;
	AnimatedTexture* mFloor9;
	AnimatedTexture* mFloor10;
	AnimatedTexture* mFloor11;
	AnimatedTexture* mFloor12;
	AnimatedTexture* mFloor13;
	AnimatedTexture* mFloor14;
	AnimatedTexture* mFloor15;
	AnimatedTexture* mFloor16;
	AnimatedTexture* mFloor17;
	AnimatedTexture* mFloor18;
	AnimatedTexture* mFloor19;
	AnimatedTexture* mFloor20;
	AnimatedTexture* mFloor21;
	AnimatedTexture* mFloor22;
	AnimatedTexture* mFloor23;
	AnimatedTexture* mFloor24;
	AnimatedTexture* mFloor25;
	AnimatedTexture* mFloor26;
	AnimatedTexture* mFloor27;
	AnimatedTexture* mFloor28;
	AnimatedTexture* mFloor29;
	AnimatedTexture* mFloor30;
	AnimatedTexture* mFloor31;
	AnimatedTexture* mFloor32;
	AnimatedTexture* mFloor33;
	AnimatedTexture* mFloor34;
	AnimatedTexture* mFloor35;
	AnimatedTexture* mFloor36;
	AnimatedTexture* mFloor37;
	AnimatedTexture* mFloor38;
	AnimatedTexture* mFloor39;
	AnimatedTexture* mFloor40;
	AnimatedTexture* mFloor41;
	AnimatedTexture* mFloor42;
	AnimatedTexture* mFloor43;
	AnimatedTexture* mFloor44;
	AnimatedTexture* mFloor45;
	AnimatedTexture* mFloor46;


	AnimatedTexture* mObjects;
	AnimatedTexture* mComputer;
	AnimatedTexture* mComputer2;
	AnimatedTexture* mBed;
	AnimatedTexture* mBed2;
	AnimatedTexture* mFlower;
	AnimatedTexture* mFlower2;


public:
	StartRoom();
	~StartRoom();

	void Render();
	void Update();

	inline AnimatedTexture* GetComputer() { return mComputer; }
	inline AnimatedTexture* GetWall() { return mWall; }
	inline AnimatedTexture* GetWall2() { return mWall2; }
	inline AnimatedTexture* GetWall3() { return mWall3; }
	inline AnimatedTexture* GetWall4() { return mWall4; }
	inline AnimatedTexture* GetWall5() { return mWall5; }
	inline AnimatedTexture* GetWall6() { return mWall6; }
	inline AnimatedTexture* GetWall7() { return mWall7; }
	
	inline AnimatedTexture* GetComputer2() { return mComputer2; }
	inline AnimatedTexture* GetTable() { return mTable; }
	inline AnimatedTexture* GetTable2() { return mTable2; }
	inline AnimatedTexture* GetFloor() { return mFloor; }
	inline AnimatedTexture* GetFloor2() { return mFloor2; }
	inline AnimatedTexture* GetFloor3() { return mFloor3; }
	inline AnimatedTexture* GetFloor4() { return mFloor4; }
	inline AnimatedTexture* GetStairs() { return mStairs; }





	inline AnimatedTexture* GetTelevision() { return mTelevision; }
	inline AnimatedTexture* GetConsole() { return mConsole; }

		

	inline AnimatedTexture* GetBed() { return mBed; }
	inline AnimatedTexture* GetBed2() { return mBed2; }

	inline AnimatedTexture* GetFlower() { return mFlower; }
	inline AnimatedTexture* GetFlower2() { return mFlower2; }


};

#endif // !STARTROOM_H

