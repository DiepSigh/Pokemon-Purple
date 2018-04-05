#include "redHouse.h"

RedHouse::RedHouse(float x, float y) {

	mBookshelf1_1 = &Bookshelf1_1;
	mBookshelf1_2 = &Bookshelf1_2;
	mBookshelf2_1 = &Bookshelf2_1;
	mBookshelf2_2 = &Bookshelf2_2;
	mChair = &Chair;
	mExit = &rhExit;
	mFloor = &Floor;
	mFlower1 = &Flower1;
	mFlower2 = &Flower2;
	mPicture = &rhPicture;
	mTable1 = &rhTable1;
	mTable2 = &rhTable2;
	mTable3 = &Bottom_Table_Left;
	mTable4 = &Bottom_Table_Right;
	mWall = &Wall;
	mWindow = &Window;

	mGraphics = Graphics::Instance();
	mPos.x = x;
	mPos.y = y;

}

RedHouse::~RedHouse() {

	delete mBookshelf1_1;
	mBookshelf1_1 = NULL;
	delete mBookshelf1_2;
	mBookshelf1_2 = NULL;
	delete mBookshelf2_1;
	mBookshelf2_1 = NULL;
	delete mBookshelf2_2;
	mBookshelf2_2 = NULL;
	delete mChair;
	mChair = NULL;
	delete mExit;
	mExit = NULL;
	delete mFloor;
	mFloor = NULL;
	delete mFlower1;
	mFlower1 = NULL;
	delete mFlower2;
	mFlower2 = NULL;
	delete mPicture;
	mPicture = NULL;
	delete mTable1;
	mTable1 = NULL;
	delete mTable2;
	mTable2 = NULL;
	delete mTable3;
	mTable3 = NULL;
	delete mTable4;
	mTable4 = NULL;
	delete mWall;
	mWall = NULL;
	delete mWindow;
	mWindow = NULL;
}

void RedHouse::Render() {

	Vector2 pos = Pos(WORLD);
	GetmTex()->SetRenderRectX((int)(GetPosX()));
	GetmTex()->SetRenderRectY((int)(GetPosY()));

	//mGraphics->DrawTexture(GetmTex()->GetSDLTex(), (mClipped) ? &mClipRect : NULL, &GetmTex()->GetmRenderRect());
	mGraphics->DrawTexture(GetmTex()->GetSDLTex(), (GetmTex()->GetClipped()) ? &GetmTex()->GetmClipRect() : NULL, &GetmTex()->GetmRenderRect());
}

void RedHouse::Update() {
	
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

void RedHouse::DrawMap(int tile) {

	switch (tile) {
	case 0:
		mTex = *mBookshelf1_1;
		break;
	case 1:
		mTex = *mBookshelf1_2;
		break;
	case 2:
		mTex = *mBookshelf2_1;
		break;
	case 3:
		mTex = *mBookshelf2_2;
		break;
	case 4:
		mTex = *mChair;
		break;
	case 5:
		mTex = *mExit;
		break;
	case 6:
		mTex = *mFlower1;
		break;
	case 7:
		mTex = *mFlower2;
		break;
	case 8:
		mTex = *mPicture;
		break;
	case 9:
		mTex = *mTable1;
		break;
	case 10:
		mTex = *mTable2;
		break;
	case 11:
		mTex = *mTable3;
		break;
	case 12:
		mTex = *mTable4;
		break;
	case 13:
		mTex = *mWall;
		break;
	case 14:
		mTex = *mWindow;
		break;
	case 20:
		mTex = *mFloor;
		break;
	}

	Render();

}