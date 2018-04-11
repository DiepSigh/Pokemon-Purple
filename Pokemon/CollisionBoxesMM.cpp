#include "CollisionBoxesMM.h"

CollisionBox* CollisionBox::sInstance = nullptr;

CollisionBox* CollisionBox::Instance() {
	if (sInstance == nullptr) {
		sInstance = new CollisionBox(0,0);
	}

	return sInstance;
}

CollisionBox::CollisionBox() {}

CollisionBox::CollisionBox(float x, float y) {
	
	mTex = new Texture("collisionBox.png", 0, 0, 32, 32);
	
	mGraphics = Graphics::Instance();

	mPos.x = x;
	mPos.y = y;
		
}

/*CollisionBox::CollisionBox(float x, float y, Texture* box) {
			
	mGraphics = Graphics::Instance();
	
	mPos.x = x;
	mPos.y = y;
	mTex = box;
}*/

CollisionBox::~CollisionBox() {

	delete mTex;
	mTex = NULL;
	
}

void CollisionBox::DrawCollisions(Camera* cam) {
	
	// **** LAKE TOP **** 
	mTex->SetRenderRectW(124);
	mTex->SetRenderRectH(32);
	SetPosX(-174 + cam->GetXPos());
	SetPosY(165 + cam->GetYPos());
	Render();
	// **** LAKE RIGHT SIDE ****
	mTex->SetRenderRectW(32);
	mTex->SetRenderRectH(96);
	SetPosX(-174 + cam->GetXPos());
	SetPosY(165 + cam->GetYPos());
	Render();
	// **** LAKE LEFT SIDE ****
	mTex->SetRenderRectW(32);
	mTex->SetRenderRectH(96);
	SetPosX(-80 + cam->GetXPos());
	SetPosY(165 + cam->GetYPos());
	Render();

	// **** BOTTOM BORDER RIGHT **** 
	mTex->SetRenderRectW(352);
	mTex->SetRenderRectH(32);
	SetPosX(-46 + cam->GetXPos());
	SetPosY(262 + cam->GetYPos());
	Render();
	// **** BOTTOM BORDER LEFT **** 
	mTex->SetRenderRectW(96);
	mTex->SetRenderRectH(32);
	SetPosX(-273 + cam->GetXPos());
	SetPosY(262 + cam->GetYPos());
	Render();
	// **** LEFT SIGN ****
	mTex->SetRenderRectW(124);
	mTex->SetRenderRectH(32);
	SetPosX(-175 + cam->GetXPos());
	SetPosY(5 + cam->GetYPos());
	Render();
	// **** RIGHT SIGN ****
	mTex->SetRenderRectW(192);
	mTex->SetRenderRectH(32);
	SetPosX(15 + cam->GetXPos());
	SetPosY(135 + cam->GetYPos());
	Render();
	// **** LEFT HOUSE **** 
	mTex->SetRenderRectW(64);
	mTex->SetRenderRectH(32);
	SetPosX(-208 + cam->GetXPos());
	SetPosY(-122 + cam->GetYPos());
	Render();
	mTex->SetRenderRectW(64);
	mTex->SetRenderRectH(32);
	SetPosX(-112 + cam->GetXPos());
	SetPosY(-122 + cam->GetYPos());
	Render();
	mTex->SetRenderRectW(124);
	mTex->SetRenderRectH(64);
	SetPosX(-174 + cam->GetXPos());
	SetPosY(-186 + cam->GetYPos());
	Render();

	// **** RIGHT HOUSE **** 
	mTex->SetRenderRectW(124);
	mTex->SetRenderRectH(64);
	SetPosX(82 + cam->GetXPos());
	SetPosY(-186 + cam->GetYPos());
	Render();
	mTex->SetRenderRectW(64);
	mTex->SetRenderRectH(32);
	SetPosX(48 + cam->GetXPos());
	SetPosY(-122 + cam->GetYPos());
	Render();
	mTex->SetRenderRectW(64);
	mTex->SetRenderRectH(32);
	SetPosX(145 + cam->GetXPos());
	SetPosY(-122 + cam->GetYPos());
	Render();

	// **** BOTTOM HOUSE **** 
	mTex->SetRenderRectW(62);
	mTex->SetRenderRectH(32);
	SetPosX(18 + cam->GetXPos());
	SetPosY(70 + cam->GetYPos());
	Render();
	mTex->SetRenderRectW(188);
	mTex->SetRenderRectH(96);
	SetPosX(18 + cam->GetXPos());
	SetPosY(-26 + cam->GetYPos());
	Render();
	mTex->SetRenderRectW(94);
	mTex->SetRenderRectH(32);
	SetPosX(112 + cam->GetXPos());
	SetPosY(70 + cam->GetYPos());
	Render();

	// **** TOP BORDER LEFT SIDE ****
	mTex->SetRenderRectW(288);
	mTex->SetRenderRectH(32);
	SetPosX(-273 + cam->GetXPos());
	SetPosY(-250 + cam->GetYPos());
	Render();
	// **** TOP BORDER LEFT SIDE ****
	mTex->SetRenderRectW(220);
	mTex->SetRenderRectH(32);
	SetPosX(83 + cam->GetXPos());
	SetPosY(-250 + cam->GetYPos());
	Render();
	// **** TOP BORDER LEFT SIDE ****
	mTex->SetRenderRectW(32);
	mTex->SetRenderRectH(480);
	SetPosX(-305 + cam->GetXPos());
	SetPosY(-218 + cam->GetYPos());
	Render();
	// **** TOP BORDER RIGHT SIDE ****
	mTex->SetRenderRectW(32);
	mTex->SetRenderRectH(480);
	SetPosX(305 + cam->GetXPos());
	SetPosY(-216 + cam->GetYPos());
	Render();

	/// **** ROUTE1 ****

	// **** BOTTOM LEFT BORDER MIDDLE ****
	mTex->SetRenderRectW(32);
	mTex->SetRenderRectH(160);
	SetPosX(-17 + cam->GetXPos());
	SetPosY(-410 + cam->GetYPos());
	Render();
	// **** BOTTOM LEFT BORDER MIDDLE ON LEFT ****
	mTex->SetRenderRectW(160);
	mTex->SetRenderRectH(32);
	SetPosX(-176 + cam->GetXPos());
	SetPosY(-410 + cam->GetYPos());
	Render();
	// **** LEFT BORDER ****
	mTex->SetRenderRectW(32);
	mTex->SetRenderRectH(966);
	SetPosX(-208 + cam->GetXPos());
	SetPosY(-1372 + cam->GetYPos());
	Render();
	// **** TOP LEFT BORDER ON RIGHT ****
	mTex->SetRenderRectW(192);
	mTex->SetRenderRectH(32);
	SetPosX(-176 + cam->GetXPos());
	SetPosY(-1404 + cam->GetYPos());
	Render();
	// **** TOP LEFT BORDER MIDDLE ****
	mTex->SetRenderRectW(32);
	mTex->SetRenderRectH(156);
	SetPosX(-16 + cam->GetXPos());
	SetPosY(-1560 + cam->GetYPos());
	Render();


	// **** BOTTOM RIGHT BORDER MIDDLE ****
	mTex->SetRenderRectW(32);
	mTex->SetRenderRectH(160);
	SetPosX(83 + cam->GetXPos());
	SetPosY(-410 + cam->GetYPos());
	Render();
	// **** BOTTOM RIGHT BORDER MIDDLE ON RIGHT ****
	mTex->SetRenderRectW(188);
	mTex->SetRenderRectH(32);
	SetPosX(83 + cam->GetXPos());
	SetPosY(-410 + cam->GetYPos());
	Render();
	// **** RIGHT BORDER ****
	mTex->SetRenderRectW(32);
	mTex->SetRenderRectH(966);
	SetPosX(272 + cam->GetXPos());
	SetPosY(-1372 + cam->GetYPos());
	Render();
	// **** TOP RIGHT BORDER ON LEFT ****
	mTex->SetRenderRectW(192);
	mTex->SetRenderRectH(32);
	SetPosX(80 + cam->GetXPos());
	SetPosY(-1404 + cam->GetYPos());
	Render();
	// **** TOP RIGHT BORDER MIDDLE ****
	mTex->SetRenderRectW(32);
	mTex->SetRenderRectH(160);
	SetPosX(80 + cam->GetXPos());
	SetPosY(-1560 + cam->GetYPos());
	Render();

	// **** SIGN ****
	mTex->SetRenderRectW(32);
	mTex->SetRenderRectH(32);
	SetPosX(-16 + cam->GetXPos());
	SetPosY(-570 + cam->GetYPos());
	Render();
	// **** BLOCKS BY SIGN RIGHT
	mTex->SetRenderRectW(256);
	mTex->SetRenderRectH(16);
	SetPosX(16 + cam->GetXPos());
	SetPosY(-554 + cam->GetYPos());
	Render();
	// **** BLOCKS BY SIGN LEFT
	mTex->SetRenderRectW(64);
	mTex->SetRenderRectH(16);
	SetPosX(-176 + cam->GetXPos());
	SetPosY(-554 + cam->GetYPos());
	Render();

}

void CollisionBox::Render() {

	Vector2 pos = Pos(WORLD);
	GetmTex()->SetRenderRectX((int)(GetPosX()));
	GetmTex()->SetRenderRectY((int)(GetPosY()));

	mGraphics->DrawTexture(GetmTex()->GetSDLTex(), (GetmTex()->GetClipped()) ? &GetmTex()->GetmClipRect() : NULL, &GetmTex()->GetmRenderRect());

}