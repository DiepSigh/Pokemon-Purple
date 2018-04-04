#include "startRoom.h"

StartRoom::StartRoom(float x, float y) {
	
	mComputer1 = new Texture("startRoom/computer1.png", 0, 0, 32, 32); 
	mComputer2 = new Texture("startRoom/computer2.png", 0, 0, 32, 32);
	mBed1 = new Texture("startRoom/bed1.png", 0, 0, 32, 32);
	mBed2 = new Texture("startRoom/bed2.png", 0, 0, 32, 32);
	mConsole = new Texture("startRoom/console.png", 0, 0, 32, 32);
	mDownstairs = new Texture("startRoom/downstairs.png", 0, 0, 32, 32);
	mFloor = new Texture("startRoom/floor.png", 0, 0, 32, 32); 
	mFlower1 = new Texture("startRoom/flower1.png", 0, 0, 32, 32);
	mFlower2 = new Texture("startRoom/flower2.png", 0, 0, 32, 32);
	mTable1 = new Texture("startRoom/table1.png", 0, 0, 32, 32);
	mTable2 = new Texture("startRoom/table2.png", 0, 0, 32, 32);
	mTableWall1 = new Texture("startRoom/table_wall1.png", 0, 0, 32, 32);
	mTableWall2 = new Texture("startRoom/table_wall2.png", 0, 0, 32, 32);
	mTv = new Texture("startRoom/tv.png", 0, 0, 32, 32);
	mWall = new Texture("startRoom/wall.png", 0, 0, 32, 32); 
	mWindow = new Texture("startRoom/window.png", 0, 0, 32, 32);
	
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
	//mRenderRect.x = (int)(pos.x - mWidth * 0.0f);
	//mRenderRect.y = (int)(pos.x - mHeight * 0.0f);

	mGraphics->DrawTexture(GetmTex()->GetSDLTex(), (GetmTex()->GetClipped()) ? &GetmTex()->GetmClipRect() : NULL, &GetmTex()->GetmRenderRect());
	GetmTex()->SetRenderRectX((int)(GetPosX()));
	GetmTex()->SetRenderRectY((int)(GetPosY()));

	//mGraphics->DrawTexture(GetmTex()->GetSDLTex(), (mClipped)? &mClipRect : NULL, &GetmTex()->GetmRenderRect());
}

void StartRoom::Update() {
	
	SetPosY(0);
	SetPosX(0);	

	for (int i = 0; i < 8; i++) {
	
		if (i != 0) {
			SetPosX(0);
			SetPosY(GetPosY() + 32);
			
		}
		
		for (int j = 0; j < 8; j++) {
			if (j != 0) {
				SetPosX(GetPosX() + 32);
			}
		
			DrawMap(map[i][j]);
			
		}
	
	}
	SetPosY(0);
	SetPosX(0);


}

void StartRoom::DrawMap(int tile) {

		switch (tile) {
		case 0:
			mTex = mComputer1;
			break;
		case 1:
			mTex = mComputer2;
			break;
		case 2:
			mTex = mTableWall1;
			break;
		case 3:
			mTex = mTableWall2;
			break;
		case 4:
			mTex = mTable1;
			break;
		case 5:
			mTex = mTable2;
			break;
		case 6:
			mTex = mWall;
			break;
		case 7:
			mTex = mWindow;
			break;
		case 8:
			mTex = mDownstairs;
			break;
		case 9:
			mTex = mTv;
			break;
		case 10:
			mTex = mConsole;
			break;
		case 11:
			mTex = mBed1;
			break;
		case 12:
			mTex = mBed2;
			break;
		case 13:
			mTex = mFlower1;
			break;
		case 14:
			mTex = mFlower2;
			break;
		case 20:
			mTex = mFloor;
			break;
		}

	Render();
}



