#include "playerHouse.h"


PlayerHouse::PlayerHouse(float x, float y) {

	mBookshelf1 = new Texture("playerHouse/bookshelf1.png", 0, 0, 32, 32);
	mBookshelf2 = new Texture("playerHouse/bookshelf2.png", 0, 0, 32, 32);
	mChair = new Texture("playerHouse/chair.png", 0, 0, 32, 32);
	mExit = new Texture("playerHouse/exit.png", 0, 0, 32, 32);
	mFloor = new Texture("playerHouse/floor.png", 0, 0, 32, 32);
	mTable1 = new Texture("playerHouse/table1.png", 0, 0, 32, 32);
	mTable2 = new Texture("playerHouse/table2.png", 0, 0, 32, 32);
	mTable3 = new Texture("playerHouse/table3.png", 0, 0, 32, 32);
	mTable4 = new Texture("playerHouse/table4.png", 0, 0, 32, 32);
	mTv = new Texture("playerHouse/tv.png", 0, 0, 32, 32);
	mUpstairs = new Texture("playerHouse/upstairs.png", 0, 0, 32, 32);
	mWall = new Texture("playerHouse/wall.png", 0, 0, 32, 32);
	mWindow = new Texture("playerHouse/window.png", 0, 0, 32, 32);

	mGraphics = Graphics::Instance();
	mPos.x = x;
	mPos.y = y;
}

PlayerHouse::~PlayerHouse() {

	delete mBookshelf1;
	mBookshelf1 = NULL;
	delete mBookshelf2;
	mBookshelf2 = NULL;
	delete mChair;
	mChair = NULL;
	delete mExit;
	mExit = NULL;
	delete mFloor;
	mFloor = NULL;
	delete mTable1;
	mTable1 = NULL;
	delete mTable2;
	mTable2 = NULL;
	delete mTable3;
	mTable3 = NULL;
	delete mTable4;
	mTable4 = NULL;
	delete mTv;
	mTv = NULL;
	delete mUpstairs;
	mUpstairs = NULL;
	delete mWall;
	mWall = NULL;
	delete mWindow;
	mWindow = NULL;

}

void PlayerHouse::Render() {
	Vector2 pos = Pos(WORLD);
	GetmTex()->SetRenderRectX((int)(GetPosX()));
	GetmTex()->SetRenderRectY((int)(GetPosY()));

	//mGraphics->DrawTexture(GetmTex()->GetSDLTex(), (mClipped) ? &mClipRect : NULL, &GetmTex()->GetmRenderRect());
	mGraphics->DrawTexture(GetmTex()->GetSDLTex(), (GetmTex()->GetClipped()) ? &GetmTex()->GetmClipRect() : NULL, &GetmTex()->GetmRenderRect());
}

void PlayerHouse::Update() {

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

void PlayerHouse::DrawMap(int tile) {
	
	switch (tile) {
	case 0:
		mTex = mBookshelf1;
		break;
	case 1:
		mTex = mBookshelf2;
		break;
	case 2:
		mTex = mChair;
		break;
	case 3:
		mTex = mTable1;
		break;
	case 4:
		mTex = mTable2;
		break;
	case 5:
		mTex = mTable3;
		break;
	case 6:
		mTex = mTable4;
		break;
	case 7:
		mTex = mTv;
		break;
	case 8:
		mTex = mUpstairs;
		break;
	case 9:
		mTex = mWall;
		break;
	case 10:
		mTex = mWindow;
		break;
	case 11:
		mTex = mExit;
		break;
	case 20:
		mTex = mFloor;
		break;
	}

	Render();



}

