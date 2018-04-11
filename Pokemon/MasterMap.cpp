#include "MasterMap.h"

MasterMap::MasterMap() {}

MasterMap::MasterMap(float x, float y) {

	mMap = &masterMap;

	mGraphics = Graphics::Instance();
	mPos.x = x;
	mPos.y = y;
	SetPosX(-1504);
	SetPosY(-4910);
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