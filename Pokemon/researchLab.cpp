#include "researchLab.h"

ResearchLab::ResearchLab(float x, float y) {

	mBigTableBottomMiddle = &rlBigTableBottomMiddle;
	mBigTableTopLeft = &rlBigTableTopLeft;
	mBigTableTopMiddle = &rlBigTableTopMiddle;
	mBigTableTopRight = &rlBigTableTopRight;
	mComputerTable1 = &rlComputerTable1;
	mComputerTable2 = &rlComputerTable2;
	mTableBook1 = &rlTableBook1;
	mTableBook2 = &rlTableBook2;
	mTableBottomLeft = &rlTableBottomLeft;
	mTableBottomRight = &rlTableBottomRight;
	mBookshelf1 = &rlBookshelf1;
	mBookshelf2 = &rlBookshelf2;
	mExit = &rlExit;
	mFloor = &rlFloor;
	mFlyer = &rlFlyer;
	mWall = &rlWall;

	mGraphics = Graphics::Instance();
	mPos.x = x;
	mPos.y = y;

}

ResearchLab::~ResearchLab() {
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

void ResearchLab::Render() {

	Vector2 pos = Pos(WORLD);
	GetmTex()->SetRenderRectX((int)(GetPosX()));
	GetmTex()->SetRenderRectY((int)(GetPosY()));

	//mGraphics->DrawTexture(GetmTex()->GetSDLTex(), (mClipped) ? &mClipRect : NULL, &GetmTex()->GetmRenderRect());
	mGraphics->DrawTexture(GetmTex()->GetSDLTex(), (GetmTex()->GetClipped()) ? &GetmTex()->GetmClipRect() : NULL, &GetmTex()->GetmRenderRect());
}

void ResearchLab::Update() {
	
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

void ResearchLab::DrawMap(int tile) {

	switch (tile) {
	case 0:
		mTex = *mBigTableBottomMiddle;
		break;
	case 1:
		mTex = *mBigTableTopLeft;
		break;
	case 2:
		mTex = *mBigTableTopMiddle;
		break;
	case 3:
		mTex = *mBigTableTopRight;
		break;
	case 4:
		mTex = *mComputerTable1;
		break;
	case 5:
		mTex = *mComputerTable2;
		break;
	case 6:
		mTex = *mTableBook1;
		break;
	case 7:
		mTex = *mTableBook2;
		break;
	case 8:
		mTex = *mTableBottomLeft;
		break;
	case 9:
		mTex = *mTableBottomRight;
		break;
	case 10:
		mTex = *mBookshelf1;
		break;
	case 11:
		mTex = *mBookshelf2;
		break;
	case 12:
		mTex = *mExit;
		break;
	case 13:
		mTex = *mFlyer;
		break;
	case 14:
		mTex = *mWall;
		break;
	case 20:
		mTex = *mFloor;
		break;
	}

	Render();


}