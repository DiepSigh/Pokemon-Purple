#include "playerHouse.h"


PlayerHouse::PlayerHouse(float x, float y) {

	mBookshelf1 = &Bookshelf1_1;
	mBookshelf2 = &Bookshelf1_2;
	mChair = &Chair;
	mExit = &phExit;
	mFloor = &Floor;
	mTable1 = &phTable1;
	mTable2 = &phTable2;
	mTable3 = &Bottom_Table_Left;
	mTable4 = &Bottom_Table_Right;
	mTv = &Tv;
	mUpstairs = &phUpstairs;
	mWall = &Wall;
	mWindow = &Curtains;

	mGraphics = Graphics::Instance();
	mPos.x = x;
	mPos.y = y;
	SetPosX(350);
	SetPosY(200);
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

	mGraphics->DrawTexture(GetmTex()->GetSDLTex(), (GetmTex()->GetClipped()) ? &GetmTex()->GetmClipRect() : NULL, &GetmTex()->GetmRenderRect());
}

void PlayerHouse::Update() {

	SetPosY(GetPosY());
	SetPosX(GetPosX());

	for (int i = 0; i < 8; i++) {

		if (i != 0) {
			SetPosX(GetPosX() - 224);
			SetPosY(GetPosY() + 32);

		}

		for (int j = 0; j < 8; j++) {
			if (j != 0) {
				SetPosX(GetPosX() + 32);
			}

			DrawMap(map[i][j]);

		}

	}
	SetPosY(GetPosY() - 224);
	SetPosX(GetPosX() - 224);

}

void PlayerHouse::DrawMap(int tile) {
	
	switch (tile) {
	case 0:
		mTex = *mBookshelf1;
		break;
	case 1:
		mTex = *mBookshelf2;
		break;
	case 2:
		mTex = *mChair;
		break;
	case 3:
		mTex = *mTable1;
		break;
	case 4:
		mTex = *mTable2;
		break;
	case 5:
		mTex = *mTable3;
		break;
	case 6:
		mTex = *mTable4;
		break;
	case 7:
		mTex = *mTv;
		break;
	case 8:
		mTex = *mUpstairs;
		break;
	case 9:
		mTex = *mWall;
		break;
	case 10:
		mTex = *mWindow;
		break;
	case 11:
		mTex = *mExit;
		break;
	case 20:
		mTex = *mFloor;
		break;
	}

	Render();



}

