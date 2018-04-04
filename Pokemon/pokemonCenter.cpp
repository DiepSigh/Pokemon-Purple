#include "pokemonCenter.h"

PokemonCenter::PokemonCenter(float x, float y){

	mColumn1 = new Texture("pokemonCenter/column1.png", 0, 0, 32, 32);
	mColumn2 = new Texture("pokemonCenter/column2.png", 0, 0, 32, 32);
	mColumnEnd = new Texture("pokemonCenter/column_end.png", 0, 0, 32, 32);
	mComputer1 = new Texture("pokemonCenter/computer1.png", 0, 0, 32, 32);
	mComputer2 = new Texture("pokemonCenter/computer2.png", 0, 0, 32, 32);
	mExit = new Texture("pokemonCenter/exit.png", 0, 0, 32, 32);
	mFloor = new Texture("pokemonCenter/floor.png", 0, 0, 32, 32);
	mFloorShadow = new Texture("pokemonCenter/floor_shadow.png", 0, 0, 32, 32);
	mFlower1 = new Texture("pokemonCenter/flower1.png", 0, 0, 32, 32);
	mFlower2 = new Texture("pokemonCenter/flower2.png", 0, 0, 32, 32);
	mLongDesk1 = new Texture("pokemonCenter/long_desk1.png", 0, 0, 32, 32);
	mLongDesk2 = new Texture("pokemonCenter/long_desk2.png", 0, 0, 32, 32);
	mLongDesk3 = new Texture("pokemonCenter/long_desk3.png", 0, 0, 32, 32);
	mLongDesk4 = new Texture("pokemonCenter/long_desk4.png", 0, 0, 32, 32);
	mPicture1 = new Texture("pokemonCenter/picture1.png", 0, 0, 32, 32);
	mPicture2 = new Texture("pokemonCenter/picture2.png", 0, 0, 32, 32);
	mPokemonHeal1 = new Texture("pokemonCenter/pokemon_heal1.png", 0, 0, 32, 32);
	mPokemonHeal2 = new Texture("pokemonCenter/pokemon_heal2.png", 0, 0, 32, 32);
	mPokemonHeal3 = new Texture("pokemonCenter/pokemon_heal3.png", 0, 0, 32, 32);
	mPokemonHeal4 = new Texture("pokemonCenter/pokemon_heal4.png", 0, 0, 32, 32);
	mSofa1 = new Texture("pokemonCenter/sofa1.png", 0, 0, 32, 32);
	mSofa2 = new Texture("pokemonCenter/sofa2.png", 0, 0, 32, 32);
	mSofaFloor1 = new Texture("pokemonCenter/sofa_floor1.png", 0, 0, 32, 32);
	mSofaFloor2 = new Texture("pokemonCenter/sofa_floor2.png", 0, 0, 32, 32);
	mWall = new Texture("pokemonCenter/wall.png", 0, 0, 32, 32);
	mWayBackRoom = new Texture("pokemonCenter/way_back_room.png", 0, 0, 32, 32);

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
		mTex = mColumn1;
		break;
	case 1:
		mTex = mColumn2;
		break;
	case 2:
		mTex = mColumnEnd;
		break;
	case 3:
		mTex = mComputer1;
		break;
	case 4:
		mTex = mComputer2;
		break;
	case 5:
		mTex = mExit;
		break;
	case 6:
		mTex = mFloor;
		break;
	case 7:
		mTex = mFloorShadow;
		break;
	case 8:
		mTex = mFlower1;
		break;
	case 9:
		mTex = mFlower2;
		break;
	case 10:
		mTex = mLongDesk1;
		break;
	case 11:
		mTex = mLongDesk2;
		break;
	case 12:
		mTex = mLongDesk3;
		break;
	case 13:
		mTex = mLongDesk4;
		break;
	case 14:
		mTex = mPicture1;
		break;
	case 15:
		mTex = mPicture2;
		break;
	case 17:
		mTex = mPokemonHeal1;
		break;
	case 18:
		mTex = mPokemonHeal2;
		break;
	case 19:
		mTex = mPokemonHeal3;
		break;
	case 20:
		mTex = mPokemonHeal4;
		break;
	case 21:
		mTex = mSofa1;
		break;
	case 22:
		mTex = mSofa2;
		break;
	case 23:
		mTex = mSofaFloor1;
		break;
	case 24:
		mTex = mSofaFloor2;
		break;
	case 25:
		mTex = mWall;
		break;
	case 26:
		mTex = mWayBackRoom;
		break;

	}

	Render();

}