#include "CollisionBoxes.h"

CollisionBox* CollisionBox::sInstance = nullptr;

CollisionBox* CollisionBox::Instance() {
	if (sInstance == nullptr) {
		sInstance = new CollisionBox();
	}

	return sInstance;
}


CollisionBox::CollisionBox() {
		
	Rect1 = new CollisionBox(0,0, new Texture("collisionBox.png", 0, 0, 384, 32));
	Rect1->SetPosX(352);
	Rect1->SetPosY(576);

	
	Rect2 = new CollisionBox(0,0, new Texture("collisionBox.png", 0, 0, 32, 512));
	Rect2->SetPosX(704);
	Rect2->SetPosY(64);

	Rect3 = new CollisionBox(0,0, new Texture("collisionBox.png", 0, 0, 32, 544));
	Rect3->SetPosX(96);
	Rect3->SetPosY(64);

	Rect4 = new CollisionBox(0,0, new Texture("collisionBox.png", 0, 0, 288, 32));
	Rect4->SetPosX(124);
	Rect4->SetPosY(64);

	Rect5 = new CollisionBox(0, 0, new Texture("collisionBox.png", 0, 0, 228, 32));
	Rect5->SetPosX(480);
	Rect5->SetPosY(64);

	Rect6 = new CollisionBox(0, 0, new Texture("collisionBox.png", 0, 0, 64, 32));
	Rect6->SetPosX(288);
	Rect6->SetPosY(192);

	Rect7 = new CollisionBox(0, 0, new Texture("collisionBox.png", 0, 0, 96, 32));
	Rect7->SetPosX(124);
	Rect7->SetPosY(576);

	Rect8 = new CollisionBox(0, 0, new Texture("collisionBox.png", 0, 0, 64, 32));
	Rect8->SetPosX(448);
	Rect8->SetPosY(192);

	Rect9 = new CollisionBox(0, 0, new Texture("collisionBox.png", 0, 0, 64, 32));
	Rect9->SetPosX(192);
	Rect9->SetPosY(192);

	Rect10 = new CollisionBox(0, 0, new Texture("collisionBox.png", 0, 0, 124, 32));
	Rect10->SetPosX(224);
	Rect10->SetPosY(320);

	Rect11 = new CollisionBox(0, 0, new Texture("collisionBox.png", 0, 0, 124, 64));
	Rect11->SetPosX(224);
	Rect11->SetPosY(128);

	Rect12 = new CollisionBox(0, 0, new Texture("collisionBox.png", 0, 0, 64, 32));
	Rect12->SetPosX(416);
	Rect12->SetPosY(384);

	Rect13 = new CollisionBox(0, 0, new Texture("collisionBox.png", 0, 0, 192, 96));
	Rect13->SetPosX(416);
	Rect13->SetPosY(288);

	Rect14 = new CollisionBox(0, 0, new Texture("collisionBox.png", 0, 0, 192, 32));
	Rect14->SetPosX(416);
	Rect14->SetPosY(448);

	Rect15 = new CollisionBox(0, 0, new Texture("collisionBox.png", 0, 0, 124, 64));
	Rect15->SetPosX(480);
	Rect15->SetPosY(128);

	Rect16 = new CollisionBox(0, 0, new Texture("collisionBox.png", 0, 0, 64, 32));
	Rect16->SetPosX(544);
	Rect16->SetPosY(192);

	Rect17 = new CollisionBox(0, 0, new Texture("collisionBox.png", 0, 0, 92, 32));
	Rect17->SetPosX(512);
	Rect17->SetPosY(384);

	Rect18 = new CollisionBox(0, 0, new Texture("collisionBox.png", 0, 0, 124, 32));
	Rect18->SetPosX(224);
	Rect18->SetPosY(480);

	Rect19 = new CollisionBox(0, 0, new Texture("collisionBox.png", 0, 0, 32, 92));
	Rect19->SetPosX(224);
	Rect19->SetPosY(512);

	Rect20 = new CollisionBox(0, 0, new Texture("collisionBox.png", 0, 0, 32, 92));
	Rect20->SetPosX(316);
	Rect20->SetPosY(512);

	Rect21 = new CollisionBox(0, 0, new Texture("collisionBox.png", 0, 0, 32, 64));
	Rect21->SetPosX(384);
	Rect21->SetPosY(0);

	Rect22 = new CollisionBox(0, 0, new Texture("collisionBox.png", 0, 0, 32, 92));
	Rect22->SetPosX(480);
	Rect22->SetPosY(0);


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
	delete Rect11;
	Rect11 = NULL;
	delete Rect12;
	Rect12 = NULL;
	delete Rect13;
	Rect13 = NULL;
	delete Rect14;
	Rect14 = NULL;
	delete Rect15;
	Rect15 = NULL;
	delete Rect16;
	Rect16 = NULL;
	delete Rect17;
	Rect17 = NULL;
	delete Rect18;
	Rect18 = NULL;
	delete Rect19;
	Rect19 = NULL;
	delete Rect20;
	Rect20 = NULL;
	delete Rect21;
	Rect21 = NULL;
	delete Rect22;
	Rect22 = NULL;
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
	Rect11->Render();
	Rect12->Render();
	Rect13->Render();
	Rect14->Render();
	Rect15->Render();
	Rect16->Render();
	Rect17->Render();
	Rect18->Render();
	Rect19->Render();
	Rect20->Render();
	Rect21->Render();
	Rect22->Render();
}

void CollisionBox::Render() {

	Vector2 pos = Pos(WORLD);
	GetmTex()->SetRenderRectX((int)(GetPosX()));
	GetmTex()->SetRenderRectY((int)(GetPosY()));

	mGraphics->DrawTexture(GetmTex()->GetSDLTex(), (GetmTex()->GetClipped()) ? &GetmTex()->GetmClipRect() : NULL, &GetmTex()->GetmRenderRect());

}