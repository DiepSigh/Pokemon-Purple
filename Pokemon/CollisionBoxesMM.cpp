#include "CollisionBoxesMM.h"

CollisionBoxMM* CollisionBoxMM::sInstance = nullptr;

CollisionBoxMM* CollisionBoxMM::Instance() {
	if (sInstance == nullptr) {
		sInstance = new CollisionBoxMM(0,0);
	}

	return sInstance;
}

CollisionBoxMM::CollisionBoxMM() {}

CollisionBoxMM::CollisionBoxMM(float x, float y) {
	
	mTex = new Texture("collisionBox_test.png", 0, 0, 32, 32);
	
	mGraphics = Graphics::Instance();

	mPos.x = x;
	mPos.y = y;
	mCollisionBoxes[0] = Texture(-174, 165, 124, 32);
	mCollisionBoxes[1] = Texture(-174, 165, 32, 96);
	mCollisionBoxes[2] = Texture(-80, 165, 32, 96);
	mCollisionBoxes[3] = Texture(-46, 262, 352, 32);
	mCollisionBoxes[4] = Texture(-273, 262, 96, 32);
	mCollisionBoxes[5] = Texture(-175, 5, 124, 32);
	mCollisionBoxes[6] = Texture(15, 135, 192, 32);
	mCollisionBoxes[7] = Texture(-208, -122, 64, 32);
	mCollisionBoxes[8] = Texture(-112, -122, 64, 32);
	mCollisionBoxes[9] = Texture(-174, -186, 124, 64);
	mCollisionBoxes[10] = Texture(82, -186, 124, 64);
	mCollisionBoxes[11] = Texture(48, -122, 64, 32);
	mCollisionBoxes[12] = Texture(145, -122, 64, 32);
	mCollisionBoxes[13] = Texture(18, 70, 62, 32);
	mCollisionBoxes[14] = Texture(18, -26, 188, 96);
	mCollisionBoxes[15] = Texture(112, 70, 94, 32);
	mCollisionBoxes[16] = Texture(-273, -250, 288, 32);
	mCollisionBoxes[17] = Texture(83, -250, 220, 32);
	mCollisionBoxes[18] = Texture(-305, -218, 32, 480);
	mCollisionBoxes[19] = Texture(305, -216, 32, 480);

	mCollisionBoxes[20] = Texture(-17, -410, 32, 160);
	mCollisionBoxes[21] = Texture(-176, -410, 160, 32);
	mCollisionBoxes[22] = Texture(-208, -1372, 32, 966);
	mCollisionBoxes[23] = Texture(-176, -1404, 192, 32);
	mCollisionBoxes[25] = Texture(-16, -1560, 32, 156);
	mCollisionBoxes[26] = Texture(83, -410, 32, 160);
	mCollisionBoxes[27] = Texture(83, -410, 188, 32);
	mCollisionBoxes[28] = Texture(272, -1372, 32, 966);
	mCollisionBoxes[29] = Texture(80, -1404, 192, 32);
	mCollisionBoxes[30] = Texture(80, -1560, 32, 160);
	mCollisionBoxes[31] = Texture(-16, -570, 32, 32);
	mCollisionBoxes[32] = Texture(16, -554, 256, 16);
	mCollisionBoxes[33] = Texture(-176, -554, 64, 16);
	mCollisionBoxes[34] = Texture(-176, -698, 256, 32);
	mCollisionBoxes[35] = Texture(208, -682, 96, 16);
	mCollisionBoxes[36] = Texture(-176, -810, 32, 16);
	mCollisionBoxes[37] = Texture(-112, -810, 96, 16);
	mCollisionBoxes[38] = Texture(16, -810, 256, 16);
	mCollisionBoxes[39] = Texture(-176, -1018, 64, 32);
	mCollisionBoxes[40] = Texture(-112, -1002, 126, 16);
	mCollisionBoxes[41] = Texture(10, -1018, 132, 32);
	mCollisionBoxes[42] = Texture(-176, -1130, 190, 16);
	mCollisionBoxes[43] = Texture(-176, -1258, 320, 16);
	mCollisionBoxes[44] = Texture(-18, -1312, 32, 188);
	mCollisionBoxes[45] = Texture(48, -1626, 32, 32);

		
}


CollisionBoxMM::~CollisionBoxMM() {

	delete mTex;
	mTex = NULL;
	
}

void CollisionBoxMM::DrawCollisions(Camera* cam) {
	
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
	// **** BLOCKS BY SIGN RIGHT ****
	mTex->SetRenderRectW(256);
	mTex->SetRenderRectH(16);
	SetPosX(16 + cam->GetXPos());
	SetPosY(-554 + cam->GetYPos());
	Render();
	// **** BLOCKS BY SIGN LEFT ****
	mTex->SetRenderRectW(64);
	mTex->SetRenderRectH(16);
	SetPosX(-176 + cam->GetXPos());
	SetPosY(-554 + cam->GetYPos());
	Render();

	// **** TREES ****
	mTex->SetRenderRectW(256);
	mTex->SetRenderRectH(32);
	SetPosX(-176 + cam->GetXPos());
	SetPosY(-698 + cam->GetYPos());
	Render();

	// **** RIGHT BLOCKS BY TREES ****
	mTex->SetRenderRectW(96);
	mTex->SetRenderRectH(16);
	SetPosX(208 + cam->GetXPos());
	SetPosY(-682 + cam->GetYPos());
	Render();

	// **** NEXT BLOCKS BY TOP TREES LEFT ****
	mTex->SetRenderRectW(32);
	mTex->SetRenderRectH(16);
	SetPosX(-176 + cam->GetXPos());
	SetPosY(-810 + cam->GetYPos());
	Render();
	// **** NEXT BLOCKS BY TOP TREES CENTER ****
	mTex->SetRenderRectW(96);
	mTex->SetRenderRectH(16);
	SetPosX(-112 + cam->GetXPos());
	SetPosY(-810 + cam->GetYPos());
	Render();
	// **** NEXT BLOCKS BY TOP TREES RIGHT ****
	mTex->SetRenderRectW(256);
	mTex->SetRenderRectH(16);
	SetPosX(16 + cam->GetXPos());
	SetPosY(-810 + cam->GetYPos());
	Render();

	// **** NEXT TREES BLOCKS TREES ON LEFT ****
	mTex->SetRenderRectW(64);
	mTex->SetRenderRectH(32);
	SetPosX(-176 + cam->GetXPos());
	SetPosY(-1018 + cam->GetYPos());
	Render();

	// **** NEXT TREES BLOCKS TREES ON CENTER ****
	mTex->SetRenderRectW(126);
	mTex->SetRenderRectH(16);
	SetPosX(-112 + cam->GetXPos());
	SetPosY(-1002 + cam->GetYPos());
	Render();

	// **** NEXT TREES BLOCKS TREES ON RIGHT ****
	mTex->SetRenderRectW(132);
	mTex->SetRenderRectH(32);
	SetPosX(10 + cam->GetXPos());
	SetPosY(-1018 + cam->GetYPos());
	Render();

	// **** TOPEST BLOCKS
	mTex->SetRenderRectW(190);
	mTex->SetRenderRectH(16);
	SetPosX(-176 + cam->GetXPos());
	SetPosY(-1130 + cam->GetYPos());
	Render();
	// **** TOPEST BLOCKS
	mTex->SetRenderRectW(320);
	mTex->SetRenderRectH(16);
	SetPosX(-176 + cam->GetXPos());
	SetPosY(-1258 + cam->GetYPos());
	Render();
	// **** TOPEST TREES
	mTex->SetRenderRectW(32);
	mTex->SetRenderRectH(188);
	SetPosX(-18 + cam->GetXPos());
	SetPosY(-1312 + cam->GetYPos());
	Render();

	// **** TOP SIGN VERIDIAN CITY ****
	mTex->SetRenderRectW(32);
	mTex->SetRenderRectH(32);
	SetPosX(48 + cam->GetXPos());
	SetPosY(-1626 + cam->GetYPos());
	Render();
}

void CollisionBoxMM::Render() {

	Vector2 pos = Pos(WORLD);
	GetmTex()->SetRenderRectX((int)(GetPosX()));
	GetmTex()->SetRenderRectY((int)(GetPosY()));

	mGraphics->DrawTexture(GetmTex()->GetSDLTex(), (GetmTex()->GetClipped()) ? &GetmTex()->GetmClipRect() : NULL, &GetmTex()->GetmRenderRect());

}