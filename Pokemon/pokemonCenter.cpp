#include "pokemonCenter.h"

PokemonCenter::PokemonCenter(float x, float y){

	mColumn1 = &pcColumn1;
	mColumn2 = &pcColumn2;
	mColumnEnd = &pcColumnEnd;
	mComputer1 = &pcComputer1;
	mComputer2 = &pcComputer2;
	mExit = &pcExit;
	mFloor = &pcFloor;
	mFloorShadow = &pcFloorShadow;
	mFlower1 = &pcFlower1;
	mFlower2 = &pcFlower2;
	mLongDesk1 = &pcLongDesk1;
	mLongDesk2 = &pcLongDesk2;
	mLongDesk3 = &pcLongDesk3;
	mLongDesk4 = &pcLongDesk4;
	mPicture1 = &pcPicture1;
	mPicture2 = &pcPicture2;
	mPokemonHeal1 = &pcPokemonHeal1;
	mPokemonHeal2 = &pcPokemonHeal2;
	mPokemonHeal3 = &pcPokemonHeal3;
	mPokemonHeal4 = &pcPokemonHeal4;
	mSofa1 = &pcSofa1;
	mSofa2 = &pcSofa2;
	mSofaFloor1 = &pcSofaFloor1;
	mSofaFloor2 = &pcSofaFloor2;
	mWall = &pcWall;
	mWayBackRoom = &pcWayBackRoom;

	mGraphics = Graphics::Instance();
	mPos.x = x;
	mPos.y = y;

}

PokemonCenter::~PokemonCenter() {
	delete mColumn1;
	mColumn1 = NULL;
	delete mColumn2;
	mColumn2 = NULL;
	delete mColumnEnd;
	mColumnEnd = NULL;
	delete mComputer1;
	mComputer1 = NULL;
	delete mComputer2;
	mComputer2 = NULL;
	delete mExit;
	mExit = NULL;
	delete mFloor;
	mFloor = NULL;
	delete mFloorShadow;
	mFloorShadow = NULL;
	delete mFlower1;
	mFlower1 = NULL;
	delete mFlower2;
	mFlower2 = NULL;
	delete mLongDesk1;
	mLongDesk1 = NULL;
	delete mLongDesk2;
	mLongDesk2 = NULL;
	delete mLongDesk3;
	mLongDesk3 = NULL;
	delete mLongDesk4;
	mLongDesk4 = NULL;
	delete mPicture1;
	mPicture1 = NULL;
	delete mPicture2;
	mPicture2 = NULL;
	delete mPokemonHeal1;
	mPokemonHeal1 = NULL;
	delete mPokemonHeal2;
	mPokemonHeal2 = NULL;
	delete mPokemonHeal3;
	mPokemonHeal3 = NULL;
	delete mPokemonHeal4;
	mPokemonHeal4 = NULL;
	delete mSofa1;
	mSofa1 = NULL;
	delete mSofa2;
	mSofa2 = NULL;
	delete mSofaFloor1;
	mSofaFloor1 = NULL;
	delete mSofaFloor2;
	mSofaFloor2 = NULL;
	delete mWall;
	mWall = NULL;
	delete mWayBackRoom;
	mWayBackRoom = NULL;
}

void PokemonCenter::Render() {
	Vector2 pos = Pos(WORLD);
	GetmTex()->SetRenderRectX((int)(GetPosX()));
	GetmTex()->SetRenderRectY((int)(GetPosY()));

	//mGraphics->DrawTexture(GetmTex()->GetSDLTex(), (mClipped) ? &mClipRect : NULL, &GetmTex()->GetmRenderRect());
	mGraphics->DrawTexture(GetmTex()->GetSDLTex(), (GetmTex()->GetClipped()) ? &GetmTex()->GetmClipRect() : NULL, &GetmTex()->GetmRenderRect());
}

void PokemonCenter::Update() {
	SetPosY(140);
	SetPosX(200);

	for (int i = 0; i < 8; i++) {

		if (i != 0) {
			SetPosX(200);
			SetPosY(GetPosY() + 32);

		}

		for (int j = 0; j < 14; j++) {
			if (j != 0) {
				SetPosX(GetPosX() + 32);
			}

			DrawMap(map[i][j]);

		}

	}
	SetPosY(140);
	SetPosX(200);

}

void PokemonCenter::DrawMap(int tile) {

	switch (tile) {
	case 0:
		mTex = *mColumn1;
		break;
	case 1:
		mTex = *mColumn2;
		break;
	case 2:
		mTex = *mColumnEnd;
		break;
	case 3:
		mTex = *mComputer1;
		break;
	case 4:
		mTex = *mComputer2;
		break;
	case 5:
		mTex = *mExit;
		break;
	case 6:
		mTex = *mFloor;
		break;
	case 7:
		mTex = *mFloorShadow;
		break;
	case 8:
		mTex = *mFlower1;
		break;
	case 9:
		mTex = *mFlower2;
		break;
	case 10:
		mTex = *mLongDesk1;
		break;
	case 11:
		mTex = *mLongDesk2;
		break;
	case 12:
		mTex = *mLongDesk3;
		break;
	case 13:
		mTex = *mLongDesk4;
		break;
	case 14:
		mTex = *mPicture1;
		break;
	case 15:
		mTex = *mPicture2;
		break;
	case 17:
		mTex = *mPokemonHeal1;
		break;
	case 18:
		mTex = *mPokemonHeal2;
		break;
	case 19:
		mTex = *mPokemonHeal3;
		break;
	case 20:
		mTex = *mPokemonHeal4;
		break;
	case 21:
		mTex = *mSofa1;
		break;
	case 22:
		mTex = *mSofa2;
		break;
	case 23:
		mTex = *mSofaFloor1;
		break;
	case 24:
		mTex = *mSofaFloor2;
		break;
	case 25:
		mTex = *mWall;
		break;
	case 26:
		mTex = *mWayBackRoom;
		break;

	}

	Render();

}