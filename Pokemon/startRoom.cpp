#include "startRoom.h"

StartRoom::StartRoom() {
	
	mComputer1 = new Texture("01_Start_Game_Room.png", 0, 0, 256, 256);
	mWall1 = new Texture("01_Start_Game_Room.png", 0, 0, 128, 128);
	mWall2 = new Texture("01_Start_Game_Room.png", 32, 0, 16, 16);
	mWall3 = new Texture("01_Start_Game_Room.png", 48, 0, 16, 16);
	mWall4 = new Texture("01_Start_Game_Room.png", 64, 0, 16, 16);
	mWall5 = new Texture("01_Start_Game_Room.png", 80, 0, 16, 16);
	mWall6 = new Texture("01_Start_Game_Room.png", 96, 0, 16, 16);
	mWall7 = new Texture("01_Start_Game_Room.png", 112, 0, 16, 16);

	mComputer2 = new Texture("01_Start_Game_Room.png", 0, 16, 16, 16);
	mTable1 = new Texture("01_Start_Game_Room.png", 16, 16, 16, 16);
	mTable2 = new Texture("01_Start_Game_Room.png", 32, 16, 16, 16);
	mFloor1 = new Texture("01_Start_Game_Room.png", 48, 0, 16, 16);
	mFloor2 = new Texture("01_Start_Game_Room.png", 64, 16, 16, 16);
	mFloor3 = new Texture("01_Start_Game_Room.png", 80, 16, 16, 16);
	mFloor4 = new Texture("01_Start_Game_Room.png", 96, 16, 16, 16);
	mStairs = new Texture("01_Start_Game_Room.png", 112, 16, 16, 16);

	mFloor5 = new Texture("01_Start_Game_Room.png", 0, 32, 16, 16);
	mFloor6 = new Texture("01_Start_Game_Room.png", 16, 32, 16, 16);
	mFloor7 = new Texture("01_Start_Game_Room.png", 32, 32, 16, 16);
	mFloor8 = new Texture("01_Start_Game_Room.png", 48, 32, 16, 16);
	mFloor9 = new Texture("01_Start_Game_Room.png", 64, 32, 16, 16);
	mFloor10 = new Texture("01_Start_Game_Room.png", 80, 32, 16, 16);
	mFloor11 = new Texture("01_Start_Game_Room.png", 96, 32, 16, 16);
	mFloor12 = new Texture("01_Start_Game_Room.png", 112, 32, 16, 16);

	mFloor13 = new Texture("01_Start_Game_Room.png", 0, 48, 16, 16);
	mFloor14 = new Texture("01_Start_Game_Room.png", 16, 48, 16, 16);
	mFloor15 = new Texture("01_Start_Game_Room.png", 32, 48, 16, 16);
	mFloor16 = new Texture("01_Start_Game_Room.png", 48, 48, 16, 16);
	mFloor17 = new Texture("01_Start_Game_Room.png", 64, 48, 16, 16);
	mFloor18 = new Texture("01_Start_Game_Room.png", 80, 48, 16, 16);
	mFloor19 = new Texture("01_Start_Game_Room.png", 96, 48, 16, 16);
	mFloor20 = new Texture("01_Start_Game_Room.png", 112, 48, 16, 16);

	mFloor21 = new Texture("01_Start_Game_Room.png", 0, 64, 16, 16);
	mFloor22 = new Texture("01_Start_Game_Room.png", 16, 64, 16, 16);
	mFloor23 = new Texture("01_Start_Game_Room.png", 32, 64, 16, 16);
	mTelevision = new Texture("01_Start_Game_Room.png", 48, 64, 16, 16);
	mFloor24 = new Texture("01_Start_Game_Room.png", 64, 64, 16, 16);
	mFloor25 = new Texture("01_Start_Game_Room.png", 80, 64, 16, 16);
	mFloor26 = new Texture("01_Start_Game_Room.png", 96, 64, 16, 16);
	mFloor27 = new Texture("01_Start_Game_Room.png", 112, 64, 16, 16);

	mFloor28 = new Texture("01_Start_Game_Room.png", 0, 80, 16, 16);
	mFloor29 = new Texture("01_Start_Game_Room.png", 16, 80, 16, 16);
	mFloor30 = new Texture("01_Start_Game_Room.png", 32, 80, 16, 16);
	mConsole = new Texture("01_Start_Game_Room.png", 48, 80, 16, 16);
	mFloor31 = new Texture("01_Start_Game_Room.png", 64, 80, 16, 16);
	mFloor32 = new Texture("01_Start_Game_Room.png", 80, 80, 16, 16);
	mFloor33 = new Texture("01_Start_Game_Room.png", 96, 80, 16, 16);
	mFloor34 = new Texture("01_Start_Game_Room.png", 112, 80, 16, 16);

	mBed1 = new Texture("01_Start_Game_Room.png", 0, 96, 16, 16);
	mFloor35 = new Texture("01_Start_Game_Room.png", 16, 96, 16, 16);
	mFloor36 = new Texture("01_Start_Game_Room.png", 32, 96, 16, 16);
	mFloor37 = new Texture("01_Start_Game_Room.png", 48, 96, 16, 16);
	mFloor38 = new Texture("01_Start_Game_Room.png", 64, 96, 16, 16);
	mFloor39 = new Texture("01_Start_Game_Room.png", 80, 96, 16, 16);
	mFlower1 = new Texture("01_Start_Game_Room.png", 96, 96, 16, 16);
	mFloor40 = new Texture("01_Start_Game_Room.png", 112, 96, 16, 16);

	mBed2 = new Texture("01_Start_Game_Room.png", 0, 112, 16, 16);
	mFloor41 = new Texture("01_Start_Game_Room.png", 16, 112, 16, 16);
	mFloor42 = new Texture("01_Start_Game_Room.png", 32, 112, 16, 16);
	mFloor43 = new Texture("01_Start_Game_Room.png", 48, 112, 16, 16);
	mFloor44 = new Texture("01_Start_Game_Room.png", 64, 112, 16, 16);
	mFloor45 = new Texture("01_Start_Game_Room.png", 80, 112, 16, 16);
	mFlower2 = new Texture("01_Start_Game_Room.png", 96, 112, 16, 16);
	mFloor46 = new Texture("01_Start_Game_Room.png", 112, 112, 16, 16);

}


StartRoom::~StartRoom() {

	delete mComputer1;
	mComputer1 = NULL;
	delete mWall1;
	mWall1 = NULL;
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
	delete mTable1;
	mTable1 = NULL;
	delete mTable2;
	mTable2 = NULL;
	delete mFloor1;
	mFloor1 = NULL;
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

	delete mBed1;
	mBed1 = NULL;
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
	delete mFlower1;
	mFlower1 = NULL;
	delete mFloor40;
	mFloor40 = NULL;

	delete mBed2;
	mBed2 = NULL;
	delete mFloor41;
	mFloor41 = NULL;
	delete mFloor42;
	mFloor42 = NULL;
	delete mFloor43;
	mFloor43 = NULL;
	delete mFloor44;
	mFloor44 = NULL;
	delete mFloor45;
	mFloor45 = NULL;
	delete mFlower2;
	mFlower2 = NULL;
	delete mFloor46;
	mFloor46 = NULL;


}

void StartRoom::Render() {

	Vector2 pos = Pos(WORLD);
	//mRenderRect.x = (int)(pos.x - mWidth * 0.0f);
	//mRenderRect.y = (int)(pos.x - mHeight * 0.0f);

	mGraphics->DrawTexture(GetmTex()->GetSDLTex(), (GetmTex()->GetClipped()) ? &GetmTex()->GetmClipRect() : NULL, &GetmTex()->GetmRenderRect());
}

void StartRoom::Update() {}



