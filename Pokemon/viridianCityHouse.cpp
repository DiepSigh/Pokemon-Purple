#include "viridianCityHouse.h"

ViridianCityHouse::ViridianCityHouse(float x, float y) {

	mBookshelf1_1 = new Texture("viridianCityHouse/bookshelf1_1.png", 0, 0, 32, 32);
	mBookshelf1_2 = new Texture("viridianCityHouse/bookshelf1_2.png", 0, 0, 32, 32);
	mBookshelf2_1 = new Texture("viridianCityHouse/bookshelf2_1.png", 0, 0, 32, 32);
	mBookshelf2_2 = new Texture("viridianCityHouse/bookshelf2_2.png", 0, 0, 32, 32);
	mChair = new Texture("viridianCityHouse/chair.png", 0, 0, 32, 32);
	mClipboard = new Texture("viridianCityHouse/clipboard.png", 0, 0, 32, 32);
	mExit = new Texture("viridianCityHouse/exit.png", 0, 0, 32, 32);
	mFloor = new Texture("viridianCityHouse/floor.png", 0, 0, 32, 32);
	mFlower1 = new Texture("viridianCityHouse/flower1.png", 0, 0, 32, 32);
	mFlower2 = new Texture("viridianCityHouse/flower2.png", 0, 0, 32, 32);
	mPicture = new Texture("viridianCityHouse/picture.png", 0, 0, 32, 32);
	mTable1 = new Texture("viridianCityHouse/table1.png", 0, 0, 32, 32);
	mTable2 = new Texture("viridianCityHouse/table2.png", 0, 0, 32, 32);
	mTable3 = new Texture("viridianCityHouse/table3.png", 0, 0, 32, 32);
	mTable4 = new Texture("viridianCityHouse/table4.png", 0, 0, 32, 32);
	mWall = new Texture("viridianCityHouse/wall.png", 0, 0, 32, 32);
	mWindow = new Texture("viridianCityHouse/window.png", 0, 0, 32, 32);

	mGraphics = Graphics::Instance();
	mPos.x = x;
	mPos.y = y;
	
}

ViridianCityHouse::~ViridianCityHouse() {
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
	delete mClipboard;
	mClipboard = NULL;
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

void ViridianCityHouse::Render() {
	Vector2 pos = Pos(WORLD);
	GetmTex()->SetRenderRectX((int)(GetPosX()));
	GetmTex()->SetRenderRectY((int)(GetPosY()));

	//mGraphics->DrawTexture(GetmTex()->GetSDLTex(), (mClipped) ? &mClipRect : NULL, &GetmTex()->GetmRenderRect());
	mGraphics->DrawTexture(GetmTex()->GetSDLTex(), (GetmTex()->GetClipped()) ? &GetmTex()->GetmClipRect() : NULL, &GetmTex()->GetmRenderRect());
}

void ViridianCityHouse::Update() {
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

void ViridianCityHouse::DrawMap(int tile) {
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
		mTex = mClipboard;
		break;
	case 6:
		mTex = mExit;
		break;
	case 7:
		mTex = mFloor;
		break;
	case 8:
		mTex = mFlower1;
		break;
	case 9:
		mTex = mFlower2;
		break;
	case 10:
		mTex = mTable1;
		break;
	case 11:
		mTex = mTable2;
		break;
	case 12:
		mTex = mTable3;
		break;
	case 13:
		mTex = mTable4;
		break;
	case 14:
		mTex = mWall;
		break;
	case 15:
		mTex = mWindow;
		break;
	case 16:
		mTex = mPicture;
		break;
	}

	Render();

}