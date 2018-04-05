#include "pokemonLeague.h"

PokemonLeague::PokemonLeague(float x, float y) {
	
	mCarpet1 = &plCarpet1;
	mCarpet2 = &plCarpet2;
	mDoor = &plDoor;
	mFloor = &plFloor;
	mStatue1 = &plStatue1;
	mStatue2 = &plStatue2;
	mStatue3 = &plStatue3;
	mWall = &Wall;

	mGraphics = Graphics::Instance();
	mPos.x = x;
	mPos.y = y;

}

PokemonLeague::~PokemonLeague() {
	delete mCarpet1;
	mCarpet1 = NULL;
	delete mCarpet2;
	mCarpet2 = NULL;
	delete mDoor;
	mDoor = NULL;
	delete mFloor;
	mFloor = NULL;
	delete mStatue1;
	mStatue1 = NULL;
	delete mStatue2;
	mStatue2 = NULL;
	delete mStatue3;
	mStatue3 = NULL;
	delete mWall;
	mWall = NULL;

}

void PokemonLeague::Render() {

	Vector2 pos = Pos(WORLD);
	GetmTex()->SetRenderRectX((int)(GetPosX()));
	GetmTex()->SetRenderRectY((int)(GetPosY()));

	//mGraphics->DrawTexture(GetmTex()->GetSDLTex(), (mClipped) ? &mClipRect : NULL, &GetmTex()->GetmRenderRect());
	mGraphics->DrawTexture(GetmTex()->GetSDLTex(), (GetmTex()->GetClipped()) ? &GetmTex()->GetmClipRect() : NULL, &GetmTex()->GetmRenderRect());
}

void PokemonLeague::Update() {

	SetPosY(140);
	SetPosX(250);

	for (int i = 0; i < 8; i++) {

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
	SetPosY(140);
	SetPosX(250);
}

void PokemonLeague::DrawMap(int tile) {
	switch (tile) {
	case 0:
		mTex = *mCarpet1;
		break;
	case 1:
		mTex = *mCarpet2;
		break;
	case 2:
		mTex = *mDoor;
		break;
	case 3:
		mTex = *mFloor;
		break;
	case 4:
		mTex = *mStatue1;
		break;
	case 5:
		mTex = *mStatue2;
		break;
	case 6:
		mTex = *mStatue3;
		break;
	case 7:
		mTex = *mWall;
		break;
	}

	Render();
}