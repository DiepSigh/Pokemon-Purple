#include "reserchLab.h"

ReserchLab::ReserchLab(float x, float y) {

	mBigTableBottomMiddle = new Texture("reserchLab/big_table_bottom_middle.png", 0, 0, 32, 32);
	mBigTableTopLeft = new Texture("reserchLab/big_table_top_left.png", 0, 0, 32, 32);
	mBigTableTopMiddle = new Texture("reserchLab/big_table_top_middle.png", 0, 0, 32, 32);
	mBigTableTopRight = new Texture("reserchLab/big_table_top_right.png", 0, 0, 32, 32);
	mComputerTable1 = new Texture("reserchLab/computer_table1.png", 0, 0, 32, 32);
	mComputerTable2 = new Texture("reserchlab/computer_table2.png", 0, 0, 32, 32);
	mTableBook1 = new Texture("reserchLab/table_book1.png", 0, 0, 32, 32);
	mTableBook2 = new Texture("reserchLab/table_book2.png", 0, 0, 32, 32);
	mTableBottomLeft = new Texture("reserchLab/table_bottom_left.png", 0, 0, 32, 32);
	mTableBottomRight = new Texture("reserchLab/table_bottom_right.png", 0, 0, 32, 32);
	mBookshelf1 = new Texture("reserchLab/bookshelf1.png", 0, 0, 32, 32);
	mBookshelf2 = new Texture("reserchLab/bookshelf2.png", 0, 0, 32, 32);
	mExit = new Texture("reserchLab/exit.png", 0, 0, 32, 32);
	mFloor = new Texture("reserchLab/floor.png", 0, 0, 32, 32);
	mFlyer = new Texture("reserchLab/flyer.png", 0, 0, 32, 32);
	mWall = new Texture("reserchLab/wall.png", 0, 0, 32, 32);

	mGraphics = Graphics::Instance();
	mPos.x = x;
	mPos.y = y;

}

ReserchLab::~ReserchLab() {
	delete mBigTableBottomMiddle;
	mBigTableBottomMiddle = NULL;
	delete mBigTableTopLeft;
	mBigTableTopLeft = NULL;
	delete mBigTableTopMiddle;
	mBigTableTopMiddle = NULL;
	delete mBigTableTopRight;
	mBigTableTopRight = NULL;
	delete mComputerTable1;
	mComputerTable1 = NULL;
	delete mComputerTable2;
	mComputerTable2 = NULL;
	delete mTableBook1;
	mTableBook1 = NULL;
	delete mTableBook2;
	mTableBook2 = NULL;
	delete mTableBottomLeft;
	mTableBottomLeft = NULL;
	delete mTableBottomRight;
	mTableBottomRight = NULL;
	delete mBookshelf1;
	mBookshelf1 = NULL;
	delete mBookshelf2;
	mBookshelf2 = NULL;
	delete mExit;
	mExit = NULL;
	delete mFlyer;
	mFlyer = NULL;
	delete mFloor;
	mFloor = NULL;
	delete mWall;
	mWall = NULL;

}

void ReserchLab::Render() {

	Vector2 pos = Pos(WORLD);
	GetmTex()->SetRenderRectX((int)(GetPosX()));
	GetmTex()->SetRenderRectY((int)(GetPosY()));

	//mGraphics->DrawTexture(GetmTex()->GetSDLTex(), (mClipped) ? &mClipRect : NULL, &GetmTex()->GetmRenderRect());
	mGraphics->DrawTexture(GetmTex()->GetSDLTex(), (GetmTex()->GetClipped()) ? &GetmTex()->GetmClipRect() : NULL, &GetmTex()->GetmRenderRect());
}

void ReserchLab::Update() {
	
	SetPosY(100);
	SetPosX(250);

	for (int i = 0; i < 12; i++) {

		if (i != 0) {
			SetPosX(250);
			SetPosY(GetPosY() + 32);

		}

		for (int j = 0; j < 10; j++) {
			if (j != 0) {
				SetPosX(GetPosX() + 32);
			}

			DrawMap(map[i][j]);

		}

	}
	SetPosY(100);
	SetPosX(250);

}

void ReserchLab::DrawMap(int tile) {

	switch (tile) {
	case 0:
		mTex = mBigTableBottomMiddle;
		break;
	case 1:
		mTex = mBigTableTopLeft;
		break;
	case 2:
		mTex = mBigTableTopMiddle;
		break;
	case 3:
		mTex = mBigTableTopRight;
		break;
	case 4:
		mTex = mComputerTable1;
		break;
	case 5:
		mTex = mComputerTable2;
		break;
	case 6:
		mTex = mTableBook1;
		break;
	case 7:
		mTex = mTableBook2;
		break;
	case 8:
		mTex = mTableBottomLeft;
		break;
	case 9:
		mTex = mTableBottomRight;
		break;
	case 10:
		mTex = mBookshelf1;
		break;
	case 11:
		mTex = mBookshelf2;
		break;
	case 12:
		mTex = mExit;
		break;
	case 13:
		mTex = mFlyer;
		break;
	case 14:
		mTex = mWall;
		break;
	case 20:
		mTex = mFloor;
		break;
	}

	Render();


}