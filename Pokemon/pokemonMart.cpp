#include "pokemonMart.h"

PokemonMart::PokemonMart(float x, float y) {

	mCashbox = &pmCashbox;
	mCashboxBottom = &pmCashboxBottom;
	mCashboxBottomLeft = &pmCashboxBottomLeft;
	mCooler1 = &pmCooler1;
	mCooler2 = &pmCooler2;
	mExit = &pmExit;
	mFloor = &Floor2;
	mFloorShadow = &Floor2Shadow;
	mShelfCashierBottom1 = &pmShelfCashierBottom1;
	mShelfCashierBottom2 = &pmShelfCashierBottom2;
	mShelfCashier1 = &pmShelfCashier1;
	mShelfCashier2 = &pmShelfCashier2;
	mShelf1 = &pmShelf1;
	mShelf2 = &pmShelf2;
	mShelf3 = &pmShelf3;
	mShelf4 = &pmShelf4;
	mSignSale = &pmSignSale;
	mSignSaleBottom = &pmSignSaleBottom;

	mGraphics = Graphics::Instance();
	mPos.x = x;
	mPos.y = y;

}

PokemonMart::~PokemonMart(){
	delete mCashbox;
	mCashbox = NULL;
	delete mCashboxBottom;
	mCashboxBottom = NULL;
	delete mCashboxBottomLeft;
	mCashboxBottomLeft = NULL;
	delete mCooler1;
	mCooler1 = NULL;
	delete mCooler2;
	mCooler2 = NULL;
	delete mExit;
	mExit = NULL;
	delete mFloor;
	mFloor = NULL;
	delete mFloorShadow;
	mFloorShadow = NULL;
	delete mShelfCashierBottom1;
	mShelfCashierBottom1 = NULL;
	delete mShelfCashierBottom2;
	mShelfCashierBottom2 = NULL;
	delete mShelfCashier1;
	mShelfCashier1 = NULL;
	delete mShelfCashier2;
	mShelfCashier2 = NULL;
	delete mShelf1;
	mShelf1 = NULL;
	delete mShelf2;
	mShelf2 = NULL;
	delete mShelf3;
	mShelf3 = NULL;
	delete mShelf4;
	mShelf4 = NULL;
	delete mSignSale;
	mSignSale = NULL;
	delete mSignSaleBottom;
	mSignSaleBottom = NULL;
}

void PokemonMart::Render() {

	Vector2 pos = Pos(WORLD);
	GetmTex()->SetRenderRectX((int)(GetPosX()));
	GetmTex()->SetRenderRectY((int)(GetPosY()));

	mGraphics->DrawTexture(GetmTex()->GetSDLTex(), (GetmTex()->GetClipped()) ? &GetmTex()->GetmClipRect() : NULL, &GetmTex()->GetmRenderRect());

}

void PokemonMart::Update() {
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

void PokemonMart::DrawMap(int tile) {


	switch (tile) {
	case 0:
		mTex = *mCashbox;
		break;
	case 1:
		mTex = *mCashboxBottom;
		break;
	case 2:
		mTex = *mCashboxBottomLeft;
		break;
	case 3:
		mTex = *mCooler1;
		break;
	case 4:
		mTex = *mCooler2;
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
		mTex = *mShelfCashierBottom1;
		break;
	case 9:
		mTex = *mShelfCashierBottom2;
		break;
	case 10:
		mTex = *mShelfCashier1;
		break;
	case 11:
		mTex = *mShelfCashier2;
		break;
	case 12:
		mTex = *mShelf1;
		break;
	case 13:
		mTex = *mShelf2;
		break;
	case 14:
		mTex = *mShelf3;
		break;
	case 15:
		mTex = *mShelf4;
		break;
	case 16:
		mTex = *mSignSale;
		break;
	case 17:
		mTex = *mSignSaleBottom;
		break;

	}

	Render();

}


