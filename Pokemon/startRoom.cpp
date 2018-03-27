#include "startRoom.h"

StartRoom::StartRoom() {

	mComputer = new AnimatedTexture("01_Start_Game_Room.png", 0, 0, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mWall = new AnimatedTexture("01_Start_Game_Room.png", 16, 0, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mWall2 = new AnimatedTexture("01_Start_Game_Room.png", 32, 0, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mWall3 = new AnimatedTexture("01_Start_Game_Room.png", 48, 0, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mWall4 = new AnimatedTexture("01_Start_Game_Room.png", 64, 0, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mWall5 = new AnimatedTexture("01_Start_Game_Room.png", 80, 0, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mWall6 = new AnimatedTexture("01_Start_Game_Room.png", 96, 0, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mWall7 = new AnimatedTexture("01_Start_Game_Room.png", 112, 0, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);

	mComputer2 = new AnimatedTexture("01_Start_Game_Room.png", 0, 16, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mTable = new AnimatedTexture("01_Start_Game_Room.png", 16, 16, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mTable2 = new AnimatedTexture("01_Start_Game_Room.png", 32, 16, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mFloor = new AnimatedTexture("01_Start_Game_Room.png", 48, 0, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mFloor2 = new AnimatedTexture("01_Start_Game_Room.png", 64, 16, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mFloor3 = new AnimatedTexture("01_Start_Game_Room.png", 80, 16, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mFloor4 = new AnimatedTexture("01_Start_Game_Room.png", 96, 16, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mStairs = new AnimatedTexture("01_Start_Game_Room.png", 112, 16, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);

	mFloor5 = new AnimatedTexture("01_Start_Game_Room.png", 0, 32, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mFloor6 = new AnimatedTexture("01_Start_Game_Room.png", 16, 32, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mFloor7 = new AnimatedTexture("01_Start_Game_Room.png", 32, 32, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mFloor8 = new AnimatedTexture("01_Start_Game_Room.png", 48, 32, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mFloor9 = new AnimatedTexture("01_Start_Game_Room.png", 64, 32, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mFloor10 = new AnimatedTexture("01_Start_Game_Room.png", 80, 32, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mFloor11 = new AnimatedTexture("01_Start_Game_Room.png", 96, 32, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mFloor12 = new AnimatedTexture("01_Start_Game_Room.png", 112, 32, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);

	mFloor13 = new AnimatedTexture("01_Start_Game_Room.png", 0, 48, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mFloor14 = new AnimatedTexture("01_Start_Game_Room.png", 16, 48, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mFloor15 = new AnimatedTexture("01_Start_Game_Room.png", 32, 48, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mFloor16 = new AnimatedTexture("01_Start_Game_Room.png", 48, 48, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mFloor17 = new AnimatedTexture("01_Start_Game_Room.png", 64, 48, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mFloor18 = new AnimatedTexture("01_Start_Game_Room.png", 80, 48, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mFloor19 = new AnimatedTexture("01_Start_Game_Room.png", 96, 48, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mFloor20 = new AnimatedTexture("01_Start_Game_Room.png", 112, 48, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);

	mFloor21 = new AnimatedTexture("01_Start_Game_Room.png", 0, 64, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mFloor22 = new AnimatedTexture("01_Start_Game_Room.png", 16, 64, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mFloor23 = new AnimatedTexture("01_Start_Game_Room.png", 32, 64, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mTelevision = new AnimatedTexture("01_Start_Game_Room.png", 48, 64, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mFloor24 = new AnimatedTexture("01_Start_Game_Room.png", 64, 64, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mFloor25 = new AnimatedTexture("01_Start_Game_Room.png", 80, 64, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mFloor26 = new AnimatedTexture("01_Start_Game_Room.png", 96, 64, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mFloor27 = new AnimatedTexture("01_Start_Game_Room.png", 112, 64, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);

	mFloor28 = new AnimatedTexture("01_Start_Game_Room.png", 0, 80, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mFloor29 = new AnimatedTexture("01_Start_Game_Room.png", 16, 80, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mFloor30 = new AnimatedTexture("01_Start_Game_Room.png", 32, 80, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mConsole = new AnimatedTexture("01_Start_Game_Room.png", 48, 80, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mFloor31 = new AnimatedTexture("01_Start_Game_Room.png", 64, 80, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mFloor32 = new AnimatedTexture("01_Start_Game_Room.png", 80, 80, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mFloor33 = new AnimatedTexture("01_Start_Game_Room.png", 96, 80, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mFloor34 = new AnimatedTexture("01_Start_Game_Room.png", 112, 80, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);

	mBed = new AnimatedTexture("01_Start_Game_Room.png", 0, 96, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mFloor35 = new AnimatedTexture("01_Start_Game_Room.png", 16, 96, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mFloor36 = new AnimatedTexture("01_Start_Game_Room.png", 32, 96, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mFloor37 = new AnimatedTexture("01_Start_Game_Room.png", 48, 96, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mFloor38 = new AnimatedTexture("01_Start_Game_Room.png", 64, 96, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mFloor39 = new AnimatedTexture("01_Start_Game_Room.png", 80, 96, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mFlower = new AnimatedTexture("01_Start_Game_Room.png", 96, 96, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mFloor40 = new AnimatedTexture("01_Start_Game_Room.png", 112, 96, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);

	mBed2 = new AnimatedTexture("01_Start_Game_Room.png", 0, 112, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mFloor41 = new AnimatedTexture("01_Start_Game_Room.png", 16, 112, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mFloor42 = new AnimatedTexture("01_Start_Game_Room.png", 32, 112, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mFloor43 = new AnimatedTexture("01_Start_Game_Room.png", 48, 112, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mFloor44 = new AnimatedTexture("01_Start_Game_Room.png", 64, 112, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mFloor45 = new AnimatedTexture("01_Start_Game_Room.png", 80, 112, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mFlower2 = new AnimatedTexture("01_Start_Game_Room.png", 96, 112, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mFloor46 = new AnimatedTexture("01_Start_Game_Room.png", 112, 112, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);

}

StartRoom::~StartRoom() {
	delete mComputer;
	mComputer = NULL;
	delete mWall;
	mWall = NULL;
	delete mWall2;
	mWall2 = NULL;
	delete mWall3;
	mWall3 = NULL;
	delete mWall4;
	mWall4 = NULL;
	delete mWall5;
	mWall5 = NULL;
	delete mWall6;
	mWall6 = NULL;
	delete mWall7;
	mWall7 = NULL;


	delete mComputer2;
	mComputer2 = NULL;
	delete mTable;
	mTable = NULL;
	delete mTable2;
	mTable2 = NULL;
	delete mFloor;
	mFloor = NULL;
	delete mFloor2;
	mFloor2 = NULL;
	delete mFloor3;
	mFloor3 = NULL;
	delete mFloor4;
	mFloor4 = NULL;
	delete mStairs;
	mStairs = NULL;


	delete mFloor5;
	mFloor5 = NULL;
	delete mFloor6;
	mFloor6 = NULL;
	delete mFloor7;
	mFloor7 = NULL;
	delete mFloor8;
	mFloor8 = NULL;
	delete mFloor9;
	mFloor9 = NULL;
	delete mFloor10;
	mFloor10 = NULL;
	delete mFloor11;
	mFloor11 = NULL;
	delete mFloor12;
	mFloor12 = NULL;


	delete mFloor13;
	mFloor13 = NULL;
	delete mFloor14;
	mFloor14 = NULL;
	delete mFloor15;
	mFloor15 = NULL;
	delete mFloor16;
	mFloor16 = NULL;
	delete mFloor17;
	mFloor17 = NULL;
	delete mFloor18;
	mFloor18 = NULL;
	delete mFloor19;
	mFloor18 = NULL;
	delete mFloor20;
	mFloor20 = NULL;

	delete mFloor21;
	mFloor21 = NULL;
	delete mFloor22;
	mFloor22 = NULL;
	delete mFloor23;
	mFloor23 = NULL;
	delete mTelevision;
	mTelevision = NULL;
	delete mFloor24;
	mFloor24 = NULL;
	delete mFloor25;
	mFloor25 = NULL;
	delete mFloor26;
	mFloor26 = NULL;
	delete mFloor27;
	mFloor27 = NULL;

	delete mFloor28;
	mFloor28 = NULL;
	delete mFloor29;
	mFloor29 = NULL;
	delete mFloor30;
	mFloor30 = NULL;
	delete mConsole;
	mConsole = NULL;
	delete mFloor31;
	mFloor31 = NULL;
	delete mFloor32;
	mFloor32 = NULL;
	delete mFloor33;
	mFloor33 = NULL;
	delete mFloor34;
	mFloor34 = NULL;

	delete mBed;
	mBed = NULL;
	delete mFloor35;
	mFloor35 = NULL;
	delete mFloor36;
	mFloor36 = NULL;
	delete mFloor37;
	mFloor37 = NULL;
	delete mFloor38;
	mFloor38 = NULL;
	delete mFloor39;
	mFloor39 = NULL;
	delete mFlower;
	mFlower = NULL;
	delete mFloor40;
	mFloor40 = NULL;


}