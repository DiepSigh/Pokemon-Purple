#include "CollisionBoxes.h"

CollisionBox* CollisionBox::sInstance = nullptr;

CollisionBox* CollisionBox::Instance() {
	if (sInstance == nullptr) {
		sInstance = new CollisionBox();
	}

	return sInstance;
}


CollisionBox::CollisionBox() {

	Rect1 = new CollisionBox(0,0, new Texture("collisionBox.png", 0, 0, 384,32));
	Rect1->SetPosX(352);
	Rect1->SetPosY(576);

	// Rect1->SetPosX(MasterMap->GetPosX() + );
	Rect2 = new CollisionBox(0,0, new Texture("collisionBox.png", 0, 0, 32, 512));
	Rect2->SetPosX(704);
	Rect2->SetPosY(64);

	Rect3 = new CollisionBox(0,0, new Texture("collisionBox.png", 0, 0, 32, 540));
	Rect3->SetPosX(92);
	Rect3->SetPosY(64);

	Rect4 = new CollisionBox(0,0, new Texture("collisionBox.png", 0, 0, 288, 32));
	Rect4->SetPosX(124);
	Rect4->SetPosY(64);

	Rect5 = new CollisionBox(0, 0, new Texture("collisionBox.png", 0, 0, 228, 32));
	Rect5->SetPosX(476);
	Rect5->SetPosY(64);

	Rect6 = new CollisionBox(0, 0, new Texture("collisionBox.png", 0, 0, 32, 32));
	Rect6->SetPosX(0);
	Rect6->SetPosY(0);

	Rect7 = new CollisionBox(0, 0, new Texture("collisionBox.png", 0, 0, 92, 32));
	Rect7->SetPosX(124);
	Rect7->SetPosY(576);

	Rect8 = new CollisionBox(0, 0, new Texture("collisionBox.png", 0, 0, 64, 32));
	Rect8->SetPosX(448);
	Rect8->SetPosY(188);

	Rect9 = new CollisionBox(0, 0, new Texture("collisionBox.png", 0, 0, 64, 32));
	Rect9->SetPosX(188);
	Rect9->SetPosY(188);

	Rect10 = new CollisionBox(0, 0, new Texture("collisionBox.png", 0, 0, 124, 32));
	Rect10->SetPosX(224);
	Rect10->SetPosY(320);
}

CollisionBox::CollisionBox(float x, float y, Texture* rect) {
	mGraphics = Graphics::Instance();
	
	mPos.x = x;
	mPos.y = y;
	mTex = rect;
}

CollisionBox::~CollisionBox() {

	delete Rect1;
	Rect1 = NULL;
	delete Rect2;
	Rect2 = NULL;
	delete Rect3;
	Rect3 = NULL;
	delete Rect4;
	Rect4 = NULL;
	delete Rect5;
	Rect5 = NULL;
	delete Rect6;
	Rect6 = NULL;
	delete Rect7;
	Rect7 = NULL;
	delete Rect8;
	Rect8 = NULL;
	delete Rect9;
	Rect9 = NULL;
	delete Rect10;
	Rect10 = NULL;

}

void CollisionBox::DrawCollisions() {

	Rect1->Render();
	Rect2->Render();
	Rect3->Render();
	Rect4->Render();
	Rect5->Render();
	Rect6->Render();
	Rect7->Render();
	Rect8->Render();
	Rect9->Render();
	Rect10->Render();
}

void CollisionBox::Render() {

	Vector2 pos = Pos(WORLD);
	GetmTex()->SetRenderRectX((int)(GetPosX()));
	GetmTex()->SetRenderRectY((int)(GetPosY()));

	mGraphics->DrawTexture(GetmTex()->GetSDLTex(), (GetmTex()->GetClipped()) ? &GetmTex()->GetmClipRect() : NULL, &GetmTex()->GetmRenderRect());

}