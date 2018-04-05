#include "pokemonSchool.h"

PokemonSchool::PokemonSchool(float x, float y) {

	mBoard1 = &psBoard1;
	mBoard2 = &psBoard2;
	mBookshelf1 = &Bookshelf2_1;
	mBookShelf2 = &Bookshelf2_2;
	mChair = &Chair;
	mExit = &psExit;
	mFloor = &Floor;
	mFlower1 = &Flower1;
	mFlower2 = &Flower2;
	mTable1 = &psTable1;
	mTable2 = &psTable2;
	mTable3 = &TableTopRight;
	mTable4 = &Bottom_Table_Right;
	mWall = &Wall;
	mWindow = &Window;

	mGraphics = Graphics::Instance();
	mPos.x = x;
	mPos.y = y;

}

PokemonSchool::~PokemonSchool() {
	delete mBoard1;
	mBoard1 = NULL;
	delete mBoard2;
	mBoard2 = NULL;
	delete mBookshelf1;
	mBookshelf1 = NULL;
	delete mBookShelf2;
	mBookShelf2 = NULL;
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

void PokemonSchool::Render() {

	Vector2 pos = Pos(WORLD);
	GetmTex()->SetRenderRectX((int)(GetPosX()));
	GetmTex()->SetRenderRectY((int)(GetPosY()));

	mGraphics->DrawTexture(GetmTex()->GetSDLTex(), (GetmTex()->GetClipped()) ? &GetmTex()->GetmClipRect() : NULL, &GetmTex()->GetmRenderRect());
}

void PokemonSchool::Update() {

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

void PokemonSchool::DrawMap(int tile) {

	switch (tile) {
	case 0:
		mTex = *mBoard1;
		break;
	case 1:
		mTex = *mBoard2;
		break;
	case 2:
		mTex = *mBookshelf1;
		break;
	case 3:
		mTex = *mBookShelf2;
		break;
	case 4:
		mTex = *mChair;
		break;
	case 5:
		mTex = *mExit;
		break;
	case 6:
		mTex = *mFloor;
		break;
	case 7:
		mTex = *mFlower1;
		break;
	case 8:
		mTex = *mFlower2;
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
	}

	Render();

}