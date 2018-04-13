#include "pokemonSchool.h"

PokemonSchool::PokemonSchool(float x, float y) {

	mBoard1 = new Texture("pokemonSchool/board1.png", 0, 0, 32, 32);
	mBoard2 = new Texture("pokemonSchool/board2.png", 0, 0, 32, 32);
	mBookshelf1 = new Texture("pokemonSchool/bookshelf1.png", 0, 0, 32, 32);
	mBookShelf2 = new Texture("pokemonSchool/bookshelf2.png", 0, 0, 32, 32);
	mChair = new Texture("pokemonSchool/chair.png", 0, 0, 32, 32);
	mExit = new Texture("pokemonSchool/exit.png", 0, 0, 32, 32);
	mFloor = new Texture("pokemonSchool/floor.png", 0, 0, 32, 32);
	mFlower1 = new Texture("pokemonSchool/flower1.png", 0, 0, 32, 32);
	mFlower2 = new Texture("pokemonSchool/flower2.png", 0, 0, 32, 32);
	mTable1 = new Texture("pokemonSchool/table1.png", 0, 0, 32, 32);
	mTable2 = new Texture("pokemonSchool/table2.png", 0, 0, 32, 32);
	mTable3 = new Texture("pokemonSchool/table3.png", 0, 0, 32, 32);
	mTable4 = new Texture("pokemonSchool/table4.png", 0, 0, 32, 32);
	mWall = new Texture("pokemonSchool/wall.png", 0, 0, 32, 32);
	mWindow = new Texture("pokemonSchool/window.png", 0, 0, 32, 32);

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

	//mGraphics->DrawTexture(GetmTex()->GetSDLTex(), (mClipped) ? &mClipRect : NULL, &GetmTex()->GetmRenderRect());
	mGraphics->DrawTexture(GetmTex()->GetSDLTex(), (GetmTex()->GetClipped()) ? &GetmTex()->GetmClipRect() : NULL, &GetmTex()->GetmRenderRect());
}

void PokemonSchool::Update() {

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

void PokemonSchool::DrawMap(int tile) {

	switch (tile) {
	case 0:
		mTex = mBoard1;
		break;
	case 1:
		mTex = mBoard2;
		break;
	case 2:
		mTex = mBookshelf1;
		break;
	case 3:
		mTex = mBookShelf2;
		break;
	case 4:
		mTex = mChair;
		break;
	case 5:
		mTex = mExit;
		break;
	case 6:
		mTex = mFloor;
		break;
	case 7:
		mTex = mFlower1;
		break;
	case 8:
		mTex = mFlower2;
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
	}

	Render();

}