#include "MasterMap.h"

using namespace std;

MasterMap::MasterMap(float x, float y) {
	//mMap = new Texture("MasterMap.png", 0, 0, 1550, 3200);
	mMap = new Texture("MasterMap.png", 0, 0, 3100, 6400);

	mGraphics = Graphics::Instance();
	mPos.x = x;
	mPos.y = y;
	SetPosX(-1600);
	SetPosY(-5800);

	mNPC1 = new NPC1;
	mNPC1->SetPosX(393);
	mNPC1->SetPosY(253);

	mNPC2 = new NPC2;
	mNPC2->SetPosX(583);
	mNPC2->SetPosY(475);
	
	mCam = Camera::Instance();
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
		
		mNPC1->Render();
		mNPC2->Render();
}
//NPC1//////////////////////
void MasterMap::NPC1Left() {
	mNPC1->SetPosX(mNPC1->GetPosX() + mCam->GetSpeed());
}
void MasterMap::NPC1Right() {
	mNPC1->SetPosX(mNPC1->GetPosX() - mCam->GetSpeed());
}
void MasterMap::NPC1Up() {
	mNPC1->SetPosY(mNPC1->GetPosY() + mCam->GetSpeed());
}
void MasterMap::NPC1Down() {
	mNPC1->SetPosY(mNPC1->GetPosY() - mCam->GetSpeed());
}

//NPC2/////////////////////
void MasterMap::NPC2Left() {
	mNPC2->SetPosX(mNPC2->GetPosX() + mCam->GetSpeed());
}
void MasterMap::NPC2Right() {
	mNPC2->SetPosX(mNPC2->GetPosX() - mCam->GetSpeed());
}
void MasterMap::NPC2Up() {
	mNPC2->SetPosY(mNPC2->GetPosY() + mCam->GetSpeed());
}
void MasterMap::NPC2Down() {
	mNPC2->SetPosY(mNPC2->GetPosY() - mCam->GetSpeed());
}

void MasterMap::DrawMap() {
	mTex = mMap;
	Render();

}