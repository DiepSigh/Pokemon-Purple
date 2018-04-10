#include "MasterMap.h"


MasterMap::MasterMap(float x, float y) {

	mMap = &masterMap;

	mGraphics = Graphics::Instance();
	mPos.x = x;
	mPos.y = y;
	SetPosX(-800);
	SetPosY(-2900);
}


MasterMap::~MasterMap() {

	delete mMap;
	mMap = NULL;

}

void MasterMap::Render() {

	Vector2 pos = Pos(WORLD);
	GetmTex()->SetRenderRectX((int)(GetPosX()));
	GetmTex()->SetRenderRectY((int)(GetPosY()));

	mGraphics->DrawTexture(GetmTex()->GetSDLTex(), (GetmTex()->GetClipped()) ? &GetmTex()->GetmClipRect() : NULL, &GetmTex()->GetmRenderRect());
	
	
}

void MasterMap::Update() {
	SetPosX(GetPosX());
	SetPosY(GetPosY());

		DrawMap();
}

void MasterMap::DrawMap() {
	
	mTex = *mMap;
	Render();

}