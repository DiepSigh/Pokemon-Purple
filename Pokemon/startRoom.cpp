#include "startRoom.h"


StartRoom::StartRoom(float x, float y) {

	mComputer1 = &srComputer1;
	mComputer2 = &srComputer2;
	mBed1 = &srBed1;
	mBed2 = &srBed2;
	mConsole = &srConsole;
	mDownstairs = &srDownstairs;
	mFloor = &Floor;
	mFlower1 = &Flower1;
	mFlower2 = &Flower2;
	mTable1 = &Bottom_Table_Left;
	mTable2 = &Bottom_Table_Right;
	mTableWall1 = &srTableWall1;
	mTableWall2 = &srTableWall2;
	mTv = &Tv;
	mWall = &Wall;
	mWindow = &Curtains;
	
	mGraphics = Graphics::Instance();
	mPos.x = x;
	mPos.y = y;
}

StartRoom::~StartRoom() {

	delete mComputer1;
	mComputer1 = NULL;
	delete mComputer2;
	mComputer2 = NULL;
	delete mTable1;
	mTable1 = NULL;
	delete mTable2;
	mTable2 = NULL;
	delete mBed1;
	mBed1 = NULL;
	delete mBed2;
	mBed2 = NULL;
	delete mConsole;
	mConsole = NULL;
	delete mDownstairs;
	mDownstairs = NULL;
	delete mFloor;
	mFloor = NULL;
	delete mFlower1;
	mFlower1 = NULL;
	delete mFlower2;
	mFlower2 = NULL;
	delete mTable1;
	mTable1 = NULL;
	delete mTable2;
	mTable2 = NULL;
	delete mTableWall1;
	mTableWall1 = NULL;
	delete mTableWall2;
	mTableWall2 = NULL;
	delete mTv;
	mTv = NULL;

}

void StartRoom::Render() {

	Vector2 pos = Pos(WORLD);
		
	GetmTex()->SetRenderRectX((int)(GetPosX()));
	GetmTex()->SetRenderRectY((int)(GetPosY()));

	mGraphics->DrawTexture(GetmTex()->GetSDLTex(), (GetmTex()->GetClipped()) ? &GetmTex()->GetmClipRect() : NULL, &GetmTex()->GetmRenderRect());
	//mGraphics->DrawTexture(GetmTex()->GetSDLTex(), (mClipped)? &mClipRect : NULL, &GetmTex()->GetmRenderRect());
}

void StartRoom::Update() {
	
	SetPosY(140);
	SetPosX(250);	

	for (int i = 0; i < 8; i++) {
	
		if (i != 0) {
			SetPosX(250);
			SetPosY(GetPosY() + 32);
			
		}
		
		for (int j = 0; j < 8; j++) {
			if (j != 0) {
				SetPosX(GetPosX() + 32);
			}
		
			DrawMap(map[i][j]);
			
		}
	
	}
	SetPosY(140);
	SetPosX(250);


}

void StartRoom::DrawMap(int tile) {

		switch (tile) {
		case 0:
			mTex = *mComputer1;
			break;
		case 1:
			mTex = *mComputer2;
			break;
		case 2:
			mTex = *mTableWall1;
			break;
		case 3:
			mTex = *mTableWall2;
			break;
		case 4:
			mTex = *mTable1;
			break;
		case 5:
			mTex = *mTable2;
			break;
		case 6:
			mTex = *mWall;
			break;
		case 7:
			mTex = *mWindow;
			break;
		case 8:
			mTex = *mDownstairs;
			break;
		case 9:
			mTex = *mTv;
			break;
		case 10:
			mTex = *mConsole;
			break;
		case 11:
			mTex = *mBed1;
			break;
		case 12:
			mTex = *mBed2;
			break;
		case 13:
			mTex = *mFlower1;
			break;
		case 14:
			mTex = *mFlower2;
			break;
		case 20:
			mTex = *mFloor;
			break;
		}

	Render();
}



