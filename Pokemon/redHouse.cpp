#include "redHouse.h"

RedHouse::RedHouse(float x, float y) {

	mBookshelf1_1 = new Texture ("redHouse/bookshelf1_1.png", 0, 0, 32, 32);
	mBookshelf1_2 = new Texture ("redHouse/bookshelf1_2.png", 0, 0, 32, 32);
	mBookshelf2_1 = new Texture ("redHouse/bookshelf2_1.png", 0, 0, 32, 32);
	mBookshelf2_2 = new Texture ("redHouse/bookshelf2_2.png", 0, 0, 32, 32);
	mChair = new Texture ("redHouse/chair.png", 0, 0, 32, 32);
	mExit = new Texture ("redHouse/exit.png", 0, 0, 32, 32);
	mFloor = new Texture ("redHouse/floor.png", 0, 0, 32, 32);
	mFlower1 = new Texture ("redHouse/flower1.png", 0, 0, 32, 32);
	mFlower2 = new Texture ("redHouse/flower2.png", 0, 0, 32, 32);
	mPicture = new Texture ("redHouse/picture.png", 0, 0, 32, 32);
	mTable1 = new Texture ("redHouse/table1.png", 0, 0, 32, 32);
	mTable2 = new Texture ("redHouse/table2.png", 0, 0, 32, 32);
	mTable3 = new Texture ("redHouse/table3.png", 0, 0, 32, 32);
	mTable4 = new Texture ("redHouse/table4.png", 0, 0, 32, 32);
	mWall = new Texture ("redHouse/wall.png", 0, 0, 32, 32);
	mWindow = new Texture ("redHouse/window.png", 0, 0, 32, 32);

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

	mGraphics->DrawTexture(GetmTex()->GetSDLTex(), (mClipped) ? &mClipRect : NULL, &GetmTex()->GetmRenderRect());

}

void RedHouse::Update() {
	
	SetPosY(0);
	SetPosX(520);

	for (int i = 0; i < 8; i++) {

		if (i != 0) {
			SetPosX(520);
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
	SetPosX(520);

}

void RedHouse::DrawMap(int tile) {

	switch (tile) {
	case 0:
		mTex = mBookshelf1_1;
		break;
	case 1:
		mTex = mBookshelf1_2;
		break;
	case 2:
		mTex = mBookshelf2_1;
		break;
	case 3:
		mTex = mBookshelf2_2;
		break;
	case 4:
		mTex = mChair;
		break;
	case 5:
		mTex = mExit;
		break;
	case 6:
		mTex = mFlower1;
		break;
	case 7:
		mTex = mFlower2;
		break;
	case 8:
		mTex = mPicture;
		break;
	case 9:
		mTex = mTable1;
		break;
	case 10:
		mTex = mTable2;
		break;
	case 11:
		mTex = mTable3;
		break;
	case 12:
		mTex = mTable4;
		break;
	case 13:
		mTex = mWall;
		break;
	case 14:
		mTex = mWindow;
		break;
	case 20:
		mTex = mFloor;
		break;
	}

	Render();

}