#include "CollisionBoxesPH.h"

CollisionBoxPH* CollisionBoxPH::sInstance = nullptr;

CollisionBoxPH* CollisionBoxPH::Instance() {
	if (sInstance == nullptr) {
		sInstance = new CollisionBoxPH(0, 0);
	}

	return sInstance;
}

CollisionBoxPH::CollisionBoxPH() {}

CollisionBoxPH::CollisionBoxPH(float x, float y) {

	mTex = new Texture("collisionBox_test.png", 0, 0, 32, 32);

	mGraphics = Graphics::Instance();

	mPos.x = x;
	mPos.y = y;
	mCollisionBoxes[0] = Texture(-50, -100, 64, 64);
	mCollisionBoxes[1] = Texture(14, -100, 192, 32);
	mCollisionBoxes[2] = Texture(46, 28, 64, 64);
	mCollisionBoxes[3] = Texture(46, -68, 32, 32);
	mCollisionBoxes[4] = Texture(-82, -100, 32, 256);
	mCollisionBoxes[5] = Texture(-50, 156, 256, 32);
	mCollisionBoxes[6] = Texture(206, -68, 32, 224);

}

CollisionBoxPH::~CollisionBoxPH() {

	delete mTex;
	mTex = NULL;

}

void CollisionBoxPH::DrawCollisions(Camera* cam) {

	// **** BOOKSHELF **** 
	mTex->SetRenderRectW(64);
	mTex->SetRenderRectH(64);
	SetPosX(-50 + cam->GetXPos());
	SetPosY(-100 + cam->GetYPos());
	Render();

	// **** WALL **** 
	mTex->SetRenderRectW(192);
	mTex->SetRenderRectH(32);
	SetPosX(14 + cam->GetXPos());
	SetPosY(-100 + cam->GetYPos());
	Render();

	// **** TABLE **** 
	mTex->SetRenderRectW(64);
	mTex->SetRenderRectH(64);
	SetPosX(46 + cam->GetXPos());
	SetPosY(28 + cam->GetYPos());
	Render();

	// **** TV **** 
	mTex->SetRenderRectW(32);
	mTex->SetRenderRectH(32);
	SetPosX(46 + cam->GetXPos());
	SetPosY(-68 + cam->GetYPos());
	Render();

	// **** LEFT SIDE ****
	mTex->SetRenderRectW(32);
	mTex->SetRenderRectH(256);
	SetPosX(-82 + cam->GetXPos());
	SetPosY(-100 + cam->GetYPos());
	Render();

	// **** BOTTOM SIDE ****
	mTex->SetRenderRectW(256);
	mTex->SetRenderRectH(32);
	SetPosX(-50 + cam->GetXPos());
	SetPosY(156 + cam->GetYPos());
	Render();

	// **** RIGHT SIDE ****
	mTex->SetRenderRectW(32);
	mTex->SetRenderRectH(224);
	SetPosX(206 + cam->GetXPos());
	SetPosY(-68 + cam->GetYPos());
	Render();

}

void CollisionBoxPH::Render() {

	Vector2 pos = Pos(WORLD);
	GetmTex()->SetRenderRectX((int)(GetPosX()));
	GetmTex()->SetRenderRectY((int)(GetPosY()));

	mGraphics->DrawTexture(GetmTex()->GetSDLTex(), (GetmTex()->GetClipped()) ? &GetmTex()->GetmClipRect() : NULL, &GetmTex()->GetmRenderRect());
}