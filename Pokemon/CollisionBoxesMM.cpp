#include "CollisionBoxesMM.h"

CollisionBoxMM* CollisionBoxMM::sInstance = nullptr;

CollisionBoxMM* CollisionBoxMM::Instance() {
	if (sInstance == nullptr) {
		sInstance = new CollisionBoxMM(0,0,Camera::Instance());
	}

	return sInstance;
}

CollisionBoxMM::CollisionBoxMM() {}

CollisionBoxMM::CollisionBoxMM(float x, float y, Camera* cam) {
	
	mCollisions = new Texture("collisionBox.png", 0, 0, 32, 32);
	mDialog = new Texture("dialogBox.png", 0, 0, 32, 32);
	mBattle = new Texture("battleBox.png", 0, 0, 32, 32);
	mAudioSwitcher = new Texture("audioswitcherBox.png", 0, 0, 64, 32);
		
	mGraphics = Graphics::Instance();
	
	mPos.x = x;
	mPos.y = y;

	mBattleBoxes[0] = Texture(17 + cam->GetXPos(), -378 + cam->GetYPos(), 64, 124);
	mDialogBoxes[0] = Texture(-96 + cam->GetXPos(), 90 + cam->GetYPos(), 32, 32);
	mAudioSwitcherBox[0] = Texture(17 + cam->GetXPos(), -216 + cam->GetYPos(), 32, 32);

	mCollisionBoxes[0] = Texture(-174 + cam->GetXPos(), 165 + cam->GetYPos(), 124, 32);
	mCollisionBoxes[1] = Texture(-174 + cam->GetXPos(), 165 + cam->GetYPos(), 32, 96);
	mCollisionBoxes[2] = Texture(-80 + cam->GetXPos(), 165 + cam->GetYPos(), 32, 96);
	mCollisionBoxes[3] = Texture(-46 + cam->GetXPos(), 262 + cam->GetYPos(), 352, 32); 
	mCollisionBoxes[4] = Texture(-175 + cam->GetXPos(), 5 + cam->GetYPos(), 124, 32); // left sign + fence
	mCollisionBoxes[5] = Texture(15 + cam->GetXPos(), 140 + cam->GetYPos(), 192, 32); // right sign + fence
	mCollisionBoxes[6] = Texture(-208 + cam->GetXPos(), -122 + cam->GetYPos(), 60, 32); // left house + sign
	mCollisionBoxes[7] = Texture(-110 + cam->GetXPos(), -122 + cam->GetYPos(), 60, 32); // left house right buttom
	mCollisionBoxes[8] = Texture(-174 + cam->GetXPos(), -186 + cam->GetYPos(), 124, 64); // left house buttom
	mCollisionBoxes[9] = Texture(82 + cam->GetXPos(), -184 + cam->GetYPos(), 123, 62); // right house top
	mCollisionBoxes[10] = Texture(48 + cam->GetXPos(), -122 + cam->GetYPos(), 60, 32); // right house left buttom + sign
	mCollisionBoxes[11] = Texture(145 + cam->GetXPos(), -122 + cam->GetYPos(), 60, 32); // right house right buttom
	mCollisionBoxes[12] = Texture(18 + cam->GetXPos(), 70 + cam->GetYPos(), 60, 32); //bottum house left buttom
	mCollisionBoxes[13] = Texture(18 + cam->GetXPos(), -26 + cam->GetYPos(), 188, 96); // buttom house top
	mCollisionBoxes[14] = Texture(114 + cam->GetXPos(), 70 + cam->GetYPos(), 94, 32); // buttom house left buttom
	mCollisionBoxes[15] = Texture(-273 + cam->GetXPos(), -250 + cam->GetYPos(), 288, 28); // top border left side
	mCollisionBoxes[16] = Texture(83 + cam->GetXPos(), -250 + cam->GetYPos(), 220, 28); // top border right side
	mCollisionBoxes[17] = Texture(-305 + cam->GetXPos(), -218 + cam->GetYPos(), 32, 480); // pallet town border left side
	mCollisionBoxes[18] = Texture(305 + cam->GetXPos(), -216 + cam->GetYPos(), 32, 480); // pallet town border right side
	mCollisionBoxes[19] = Texture(-273 + cam->GetXPos(), 262 + cam->GetYPos(), 96, 32); // pallet town buttom border left side
	
	mCollisionBoxes[20] = Texture(-17 + cam->GetXPos(), -410 + cam->GetYPos(), 32, 160); // route1 border middle left
	mCollisionBoxes[21] = Texture(83 + cam->GetXPos(), -410 + cam->GetYPos(), 32, 160); // route1 border middle right
	mCollisionBoxes[22] = Texture(-176 + cam->GetXPos(), -410 + cam->GetYPos(), 160, 32); // route1 left border middle on left
	mCollisionBoxes[23] = Texture(83 + cam->GetXPos(), -410 + cam->GetYPos(), 188, 32); // route1 right border middle on right
	mCollisionBoxes[24] = Texture(-208 + cam->GetXPos(), -1372 + cam->GetYPos(), 32, 966); // route1 left border edge
	mCollisionBoxes[25] = Texture(272 + cam->GetXPos(), -1372 + cam->GetYPos(), 32, 966); // route1 right border edge

/*	mCollisionBoxes[26] = Texture(-176, -1404, 192, 32);
	mCollisionBoxes[27] = Texture(-16, -1560, 32, 156);
	mCollisionBoxes[28] = Texture(80, -1404, 192, 32);
	mCollisionBoxes[29] = Texture(80, -1560, 32, 160);
	mCollisionBoxes[30] = Texture(-16, -570, 32, 32);
	mCollisionBoxes[31] = Texture(16, -554, 256, 16);
	mCollisionBoxes[32] = Texture(-176, -554, 64, 16);
	mCollisionBoxes[33] = Texture(-176, -698, 256, 32);
	mCollisionBoxes[34] = Texture(208, -682, 96, 16);
	mCollisionBoxes[35] = Texture(-176, -810, 32, 16);
	mCollisionBoxes[36] = Texture(-112, -810, 96, 16);
	mCollisionBoxes[37] = Texture(16, -810, 256, 16);
	mCollisionBoxes[38] = Texture(-176, -1018, 64, 32);
	mCollisionBoxes[39] = Texture(-112, -1002, 126, 16);
	mCollisionBoxes[40] = Texture(10, -1018, 132, 32);
	mCollisionBoxes[41] = Texture(-176, -1130, 190, 16);
	mCollisionBoxes[42] = Texture(-176, -1258, 320, 16);
	mCollisionBoxes[43] = Texture(-18, -1312, 32, 188);
	mCollisionBoxes[44] = Texture(48, -1626, 32, 32);   */
			
}

CollisionBoxMM::~CollisionBoxMM() {

	delete mTex;
	mTex = NULL;
	delete mBattle;
	mBattle = NULL;
	delete mDialog;
	mDialog = NULL;
	delete mAudioSwitcher;
	mAudioSwitcher = NULL;
}

void CollisionBoxMM::DrawAudioSwitcherBoxes(Camera* cam, AudioManager* audio) {

	mTex = mAudioSwitcher;
	mAudioSwitcher->SetRenderRectW(64);
	mAudioSwitcher->SetRenderRectH(32);
	SetPosX(17 + cam->GetXPos());
	SetPosY(-216 + cam->GetYPos());
	Render();

}

void CollisionBoxMM::DrawBattleBoxes(Camera* cam, AudioManager* audio) {

	mTex = mBattle;
	mBattle->SetRenderRectW(64);
	mBattle->SetRenderRectH(124);
	SetPosX(17 + cam->GetXPos());
	SetPosY(-378 + cam->GetYPos());
	Render();
}

void CollisionBoxMM::DrawDialogBoxes(Camera* cam) {

	mTex = mDialog;
	mDialog->SetRenderRectW(32);
	mDialog->SetRenderRectH(32);
	SetPosX(-96 + cam->GetXPos());
	SetPosY(90 + cam->GetYPos());
	Render();
}

void CollisionBoxMM::DrawCollisions(Camera* cam) {
	
	mTex = mCollisions;
	// **** LAKE TOP #0 **** 
	mTex->SetRenderRectW(124);
	mTex->SetRenderRectH(32);
	SetPosX(-174 + cam->GetXPos());
	SetPosY(165 + cam->GetYPos());
	Render();
	// **** LAKE LEFT SIDE #1 ****
	mTex->SetRenderRectW(32);
	mTex->SetRenderRectH(96);
	SetPosX(-174 + cam->GetXPos());
	SetPosY(165 + cam->GetYPos());
	Render();
	// **** LAKE RIGHT SIDE #2 ****
	mTex->SetRenderRectW(32);
	mTex->SetRenderRectH(96);
	SetPosX(-80 + cam->GetXPos());
	SetPosY(165 + cam->GetYPos());
	Render();
	// **** BOTTOM BORDER RIGHT #3 **** 
	mTex->SetRenderRectW(352);
	mTex->SetRenderRectH(32);
	SetPosX(-46 + cam->GetXPos());
	SetPosY(262 + cam->GetYPos());
	Render();
	// **** LEFT SIGN #4 ****
	mTex->SetRenderRectW(124);
	mTex->SetRenderRectH(32);
	SetPosX(-175 + cam->GetXPos());
	SetPosY(5 + cam->GetYPos());
	Render();
	// **** RIGHT SIGN #5 ****
	mTex->SetRenderRectW(192);
	mTex->SetRenderRectH(32);
	SetPosX(15 + cam->GetXPos());
	SetPosY(140 + cam->GetYPos());
	Render();
	// **** LEFT HOUSE left bottom #6 **** 
	mTex->SetRenderRectW(60);
	mTex->SetRenderRectH(32);
	SetPosX(-208 + cam->GetXPos());
	SetPosY(-122 + cam->GetYPos());
	Render();
	// **** LEFT HOUSE right bottom #7 ****
	mTex->SetRenderRectW(60);
	mTex->SetRenderRectH(32);
	SetPosX(-110 + cam->GetXPos());
	SetPosY(-122 + cam->GetYPos());
	Render();
	// **** LEFT HOUSE top #8 ****
	mTex->SetRenderRectW(124);
	mTex->SetRenderRectH(64);
	SetPosX(-174 + cam->GetXPos());
	SetPosY(-186 + cam->GetYPos());
	Render();
	// **** RIGHT HOUSE top #9 **** 
	mTex->SetRenderRectW(123);
	mTex->SetRenderRectH(64);
	SetPosX(82 + cam->GetXPos());
	SetPosY(-186 + cam->GetYPos());
	Render();
	// **** RIGHT HOUSE left part + sign #10 **** 
	mTex->SetRenderRectW(60);
	mTex->SetRenderRectH(32);
	SetPosX(48 + cam->GetXPos());
	SetPosY(-122 + cam->GetYPos());
	Render();
	// **** RIGHT HOUSE right part #11 **** 
	mTex->SetRenderRectW(60);
	mTex->SetRenderRectH(32);
	SetPosX(145 + cam->GetXPos());
	SetPosY(-122 + cam->GetYPos());
	Render();
	// **** BOTTOM HOUSE LEFT BUTTOM #12 **** 
	mTex->SetRenderRectW(60);
	mTex->SetRenderRectH(32);
	SetPosX(18 + cam->GetXPos());
	SetPosY(70 + cam->GetYPos());
	Render();
	// **** BOTTOM HOUSE TOP #13 **** 
	mTex->SetRenderRectW(188);
	mTex->SetRenderRectH(96);
	SetPosX(18 + cam->GetXPos());
	SetPosY(-26 + cam->GetYPos());
	Render();
	// **** BOTTOM HOUSE TOP LEFT BUTTOM #14 **** 
	mTex->SetRenderRectW(94);
	mTex->SetRenderRectH(32);
	SetPosX(114 + cam->GetXPos());
	SetPosY(70 + cam->GetYPos());
	Render();
	// **** TOP BORDER LEFT SIDE #15 ****
	mTex->SetRenderRectW(288);
	mTex->SetRenderRectH(28);
	SetPosX(-273 + cam->GetXPos());
	SetPosY(-250 + cam->GetYPos());
	Render();
	// **** TOP BORDER RIGHT SIDE #16 ****
	mTex->SetRenderRectW(220);
	mTex->SetRenderRectH(28);
	SetPosX(83 + cam->GetXPos());
	SetPosY(-250 + cam->GetYPos());
	Render();
	// **** PALLET TOWN BORDER LEFT SIDE #17 ****
	mTex->SetRenderRectW(32);
	mTex->SetRenderRectH(480);
	SetPosX(-305 + cam->GetXPos());
	SetPosY(-218 + cam->GetYPos());
	Render();
	// **** PALLET TOWN BORDER RIGHT SIDE #18 ****
	mTex->SetRenderRectW(32);
	mTex->SetRenderRectH(480);
	SetPosX(305 + cam->GetXPos());
	SetPosY(-216 + cam->GetYPos());
	Render();
	// **** PALLET TOWN BOTTOM BORDER LEFT #19 ****
	mTex->SetRenderRectW(96);
	mTex->SetRenderRectH(32);
	SetPosX(-273 + cam->GetXPos());
	SetPosY(262 + cam->GetYPos());
	Render();  

	/// **** ROUTE1 ****

	// **** ROUTE1 LEFT BORDER MIDDLE #20 ****
	mTex->SetRenderRectW(32);
	mTex->SetRenderRectH(160);
	SetPosX(-17 + cam->GetXPos());
	SetPosY(-410 + cam->GetYPos());
	Render();
	// **** ROUTE1 RIGHT BORDER MIDDLE #21 ****
	mTex->SetRenderRectW(32);
	mTex->SetRenderRectH(160);
	SetPosX(83 + cam->GetXPos());
	SetPosY(-410 + cam->GetYPos());
	Render();
	// **** BOTTOM RIGHT BORDER MIDDLE ON RIGHT #22 ****
	mTex->SetRenderRectW(160);
	mTex->SetRenderRectH(32);
	SetPosX(-176 + cam->GetXPos());
	SetPosY(-410 + cam->GetYPos());
	Render();
	// **** BOTTOM RIGHT BORDER MIDDLE ON RIGHT #23 ****
	mTex->SetRenderRectW(188);
	mTex->SetRenderRectH(32);
	SetPosX(83 + cam->GetXPos());
	SetPosY(-410 + cam->GetYPos());
	Render();
	// **** ROUTE1 LEFT BORDER #24 ****
	mTex->SetRenderRectW(32);
	mTex->SetRenderRectH(966);
	SetPosX(-208 + cam->GetXPos());
	SetPosY(-1372 + cam->GetYPos());
	Render();
	// **** ROUTE1 RIGHT BORDER #25 ****
	mTex->SetRenderRectW(32);
	mTex->SetRenderRectH(966);
	SetPosX(272 + cam->GetXPos());
	SetPosY(-1372 + cam->GetYPos());
	Render();

	// **** TOP LEFT BORDER ON RIGHT #26 ****
	mTex->SetRenderRectW(192);
	mTex->SetRenderRectH(32);
	SetPosX(-176 + cam->GetXPos());
	SetPosY(-1404 + cam->GetYPos());
	Render();
	// **** TOP LEFT BORDER MIDDLE #27 ****
	mTex->SetRenderRectW(32);
	mTex->SetRenderRectH(156);
	SetPosX(-16 + cam->GetXPos());
	SetPosY(-1560 + cam->GetYPos());
	Render();
	// **** TOP RIGHT BORDER ON LEFT #28 ****
	mTex->SetRenderRectW(192);
	mTex->SetRenderRectH(32);
	SetPosX(80 + cam->GetXPos());
	SetPosY(-1404 + cam->GetYPos());
	Render();
	// **** TOP RIGHT BORDER MIDDLE #29 ****
	mTex->SetRenderRectW(32);
	mTex->SetRenderRectH(160);
	SetPosX(80 + cam->GetXPos());
	SetPosY(-1560 + cam->GetYPos());
	Render();
	// **** SIGN #30 ****
	mTex->SetRenderRectW(32);
	mTex->SetRenderRectH(32);
	SetPosX(-16 + cam->GetXPos());
	SetPosY(-570 + cam->GetYPos());
	Render();
	// **** BLOCKS BY SIGN RIGHT #31 ****
	mTex->SetRenderRectW(256);
	mTex->SetRenderRectH(16);
	SetPosX(16 + cam->GetXPos());
	SetPosY(-554 + cam->GetYPos());
	Render();
	// **** BLOCKS BY SIGN LEFT #32 ****
	mTex->SetRenderRectW(64);
	mTex->SetRenderRectH(16);
	SetPosX(-176 + cam->GetXPos());
	SetPosY(-554 + cam->GetYPos());
	Render();
	// **** TREES #33 ****
	mTex->SetRenderRectW(256);
	mTex->SetRenderRectH(32);
	SetPosX(-176 + cam->GetXPos());
	SetPosY(-698 + cam->GetYPos());
	Render();
	// **** RIGHT BLOCKS BY TREES #34 ****
	mTex->SetRenderRectW(96);
	mTex->SetRenderRectH(16);
	SetPosX(208 + cam->GetXPos());
	SetPosY(-682 + cam->GetYPos());
	Render();
	// **** NEXT BLOCKS BY TOP TREES LEFT #35 ****
	mTex->SetRenderRectW(32);
	mTex->SetRenderRectH(16);
	SetPosX(-176 + cam->GetXPos());
	SetPosY(-810 + cam->GetYPos());
	Render();
	// **** NEXT BLOCKS BY TOP TREES CENTER #36 ****
	mTex->SetRenderRectW(96);
	mTex->SetRenderRectH(16);
	SetPosX(-112 + cam->GetXPos());
	SetPosY(-810 + cam->GetYPos());
	Render();
	// **** NEXT BLOCKS BY TOP TREES RIGHT #37 ****
	mTex->SetRenderRectW(256);
	mTex->SetRenderRectH(16);
	SetPosX(16 + cam->GetXPos());
	SetPosY(-810 + cam->GetYPos());
	Render();
	// **** NEXT TREES BLOCKS TREES ON LEFT #38 ****
	mTex->SetRenderRectW(64);
	mTex->SetRenderRectH(32);
	SetPosX(-176 + cam->GetXPos());
	SetPosY(-1018 + cam->GetYPos());
	Render();
	// **** NEXT TREES BLOCKS TREES ON CENTER #39 ****
	mTex->SetRenderRectW(126);
	mTex->SetRenderRectH(16);
	SetPosX(-112 + cam->GetXPos());
	SetPosY(-1002 + cam->GetYPos());
	Render();
	// **** NEXT TREES BLOCKS TREES ON RIGHT #40 ****
	mTex->SetRenderRectW(132);
	mTex->SetRenderRectH(32);
	SetPosX(10 + cam->GetXPos());
	SetPosY(-1018 + cam->GetYPos());
	Render();
	// **** TOPEST BLOCKS #41 ****
	mTex->SetRenderRectW(190);
	mTex->SetRenderRectH(16);
	SetPosX(-176 + cam->GetXPos());
	SetPosY(-1130 + cam->GetYPos());
	Render();
	// **** TOPEST BLOCKS #42 ****
	mTex->SetRenderRectW(320);
	mTex->SetRenderRectH(16);
	SetPosX(-176 + cam->GetXPos());
	SetPosY(-1258 + cam->GetYPos());
	Render();
	// **** TOPEST TREES #43 ****
	mTex->SetRenderRectW(32);
	mTex->SetRenderRectH(188);
	SetPosX(-18 + cam->GetXPos());
	SetPosY(-1312 + cam->GetYPos());
	Render();
	// **** TOP SIGN VERIDIAN CITY #44 ****
	mTex->SetRenderRectW(32);
	mTex->SetRenderRectH(32);
	SetPosX(48 + cam->GetXPos());
	SetPosY(-1626 + cam->GetYPos());
	Render();
	


}


void CollisionBoxMM::CheckMoveRight(Characters* mPlayer, Camera* mCamera, AudioManager* mAudioMgr, CollisionBoxMM* mCollisionBoxMM) {
	
	
	// ***** TESTING COLLISIONS RIGHT MOVE *****
	mPlayer->SetWPosX(mPlayer->GetWPosX() + mCamera->GetSpeed());
	std::cout << "Player World X Y " << mPlayer->GetWPosX() << " " << mPlayer->GetWPosY() << std::endl;
	mCamera->SetSpeed(5);

	// check box #0
	if (mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(0)
		&& mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(0)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(0)
		&& mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(0) + mCollisionBoxMM->GetCollisonH(0)
		)
	{

		mAudioMgr->BumpSFX();
		std::cout << "It is working, you can't go Right" << std::endl;
		mCamera->SetSpeed(0);
	}
	// Check box #1 Lake left side
	if (mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(1)
		&& mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(1)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(1)
		&& mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(1) + mCollisionBoxMM->GetCollisonH(1)
		)
	{

		mAudioMgr->BumpSFX();
		std::cout << "It is working, you can't go Right" << std::endl;
		mCamera->SetSpeed(0);
	}
	// Check box #4 left sign
	if (mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(4)
		&& mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(4)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(4)
		&& mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(4) + mCollisionBoxMM->GetCollisonH(4)
		)
	{

		mAudioMgr->BumpSFX();
		std::cout << "It is working, you can't go Right" << std::endl;
		mCamera->SetSpeed(0);
	}
	// Check box #5 right sign
	if (mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(5)
		&& mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(5)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(5)
		&& mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(5) + mCollisionBoxMM->GetCollisonH(5)
		)
	{

		mAudioMgr->BumpSFX();
		std::cout << "It is working, you can't go Right" << std::endl;
		mCamera->SetSpeed(0);
	}
	// Check box #6 left house + sign
	if (mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(6)
		&& mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(6)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(6)
		&& mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(6) + mCollisionBoxMM->GetCollisonH(6)
		)
	{

		mAudioMgr->BumpSFX();
		std::cout << "It is working, you can't go Right" << std::endl;
		mCamera->SetSpeed(0);
	}
	// Check box #7 left house right buttom 
	if (mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(7)
		&& mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(7)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(7)
		&& mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(7) + mCollisionBoxMM->GetCollisonH(7)
		)
	{

		mAudioMgr->BumpSFX();
		std::cout << "It is working, you can't go Right" << std::endl;
		mCamera->SetSpeed(0);
	}
	// Check box #8 left house top 
	if (mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(8)
		&& mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(8)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(8)
		&& mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(8) + mCollisionBoxMM->GetCollisonH(8)
		)
	{

		mAudioMgr->BumpSFX();
		std::cout << "It is working, you can't go Right" << std::endl;
		mCamera->SetSpeed(0);
	}
	// Check box #9 right house top 
	if (mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(9)
		&& mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(9)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(9)
		&& mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(9) + mCollisionBoxMM->GetCollisonH(9)
		)
	{

		mAudioMgr->BumpSFX();
		std::cout << "It is working, you can't go Right" << std::endl;
		mCamera->SetSpeed(0);
	}
	// Check box #10 left house buttom + sign 
	if (mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(10)
		&& mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(10)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(10)
		&& mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(10) + mCollisionBoxMM->GetCollisonH(10)
		)
	{

		mAudioMgr->BumpSFX();
		std::cout << "It is working, you can't go Right" << std::endl;
		mCamera->SetSpeed(0);
	}
	// Check box #11 right house buttom 
	if (mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(11)
		&& mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(11)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(11)
		&& mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(11) + mCollisionBoxMM->GetCollisonH(11)
		)
	{

		mAudioMgr->BumpSFX();
		std::cout << "It is working, you can't go Right" << std::endl;
		mCamera->SetSpeed(0);
	}
	// Check box #12 buttom house left buttom 
	if (mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(12)
		&& mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(12)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(12)
		&& mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(12) + mCollisionBoxMM->GetCollisonH(12)
		)
	{

		mAudioMgr->BumpSFX();
		std::cout << "It is working, you can't go Right" << std::endl;
		mCamera->SetSpeed(0);
	}
	// Check box #13 buttom house top 
	if (mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(13)
		&& mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(13)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(13)
		&& mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(13) + mCollisionBoxMM->GetCollisonH(13)
		)
	{

		mAudioMgr->BumpSFX();
		std::cout << "It is working, you can't go Right" << std::endl;
		mCamera->SetSpeed(0);
	}
	// Check box #14 buttom house right buttom 
	if (mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(14)
		&& mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(14)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(14)
		&& mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(14) + mCollisionBoxMM->GetCollisonH(14)
		)
	{

		mAudioMgr->BumpSFX();
		std::cout << "It is working, you can't go Right" << std::endl;
		mCamera->SetSpeed(0);
	}
	// Check box #16 top border right side 
	if (mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(16)
		&& mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(16)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(16)
		&& mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(16) + mCollisionBoxMM->GetCollisonH(16)
		)
	{

		mAudioMgr->BumpSFX();
		std::cout << "It is working, you can't go Right" << std::endl;
		mCamera->SetSpeed(0);
	}
	// Check box #18 pallet town right border 
	if (mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(18)
		&& mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(18)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(18)
		&& mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(18) + mCollisionBoxMM->GetCollisonH(18)
		)
	{

		mAudioMgr->BumpSFX();
		std::cout << "It is working, you can't go Right" << std::endl;
		mCamera->SetSpeed(0);
	}
	// Check box #21 route1 border middle right  
	if (mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(21)
		&& mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(21)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(21)
		&& mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(21) + mCollisionBoxMM->GetCollisonH(21)
		)
	{

		mAudioMgr->BumpSFX();
		std::cout << "It is working, you can't go Right" << std::endl;
		mCamera->SetSpeed(0);
	}
	// Check box #25 route1 right border edge 
	if (mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(25)
		&& mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(25)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(25)
		&& mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(25) + mCollisionBoxMM->GetCollisonH(25)
		)
	{

		mAudioMgr->BumpSFX();
		std::cout << "It is working, you can't go Right" << std::endl;
		mCamera->SetSpeed(0);
	}
	//Check Battle event right turn
	if (mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetBattleEventY(0)
		&& mPlayer->GetWPosY() < mCollisionBoxMM->GetBattleEventY(0) + mCollisionBoxMM->GetBattleEventH(0)
		)
	{

		std::cout << "It is working Battle has began..." << std::endl;

	}
	// Check Dialog event right turn 
	if (mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetDialogEventX(0)
		&& mPlayer->GetWPosX() < mCollisionBoxMM->GetDialogEventX(0)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetDialogEventY(0)
		&& mPlayer->GetWPosY() < mCollisionBoxMM->GetDialogEventY(0) + mCollisionBoxMM->GetDialogEventH(0)
		)
	{

		std::cout << "It is working, Hello my name is NPS!!!" << std::endl;
		mCamera->SetSpeed(0);
	}



} // ^^^^^ TESTING COLLISIONS RIGHT MOVE ^^^^^

void CollisionBoxMM::CheckMoveLeft(Characters* mPlayer, Camera* mCamera, AudioManager* mAudioMgr, CollisionBoxMM* mCollisionBoxMM) {

	// ***** TESTING COLLISIONS LEFT MOVE *****
	mPlayer->SetWPosX(mPlayer->GetWPosX() - mCamera->GetSpeed());
	std::cout << "Player World X Y " << mPlayer->GetWPosX() << " " << mPlayer->GetWPosY() << std::endl;
	mCamera->SetSpeed(5);

	// check lake top side #0
	if (mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(0) + mCollisionBoxMM->GetCollisonW(0)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(0) + mCollisionBoxMM->GetCollisonW(0)
		&& mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(0) + mCollisionBoxMM->GetCollisonH(0)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(0))
	{

		mAudioMgr->BumpSFX();
		std::cout << "It is working, you can't Go Left..." << std::endl;
		mCamera->SetSpeed(0);
	}
	// check lake right side #2
	if (mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(2) + mCollisionBoxMM->GetCollisonW(2)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(2) + mCollisionBoxMM->GetCollisonW(2)
		&& mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(2) + mCollisionBoxMM->GetCollisonH(2)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(2))
	{

		mAudioMgr->BumpSFX();
		std::cout << "It is working, you can't Go Left..." << std::endl;
		mCamera->SetSpeed(0);
	}
	// check  #4 left sign
	if (mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(4) + mCollisionBoxMM->GetCollisonW(4)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(4) + mCollisionBoxMM->GetCollisonW(4)
		&& mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(4) + mCollisionBoxMM->GetCollisonH(4)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(4))
	{

		mAudioMgr->BumpSFX();
		std::cout << "It is working, you can't Go Left..." << std::endl;
		mCamera->SetSpeed(0);
	}
	// check  #5 right sign
	if (mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(5) + mCollisionBoxMM->GetCollisonW(5)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(5) + mCollisionBoxMM->GetCollisonW(5)
		&& mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(5) + mCollisionBoxMM->GetCollisonH(5)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(5))
	{

		mAudioMgr->BumpSFX();
		std::cout << "It is working, you can't Go Left..." << std::endl;
		mCamera->SetSpeed(0);
	}
	// check #6 left house + sign
	if (mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(6) + mCollisionBoxMM->GetCollisonW(6)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(6) + mCollisionBoxMM->GetCollisonW(6)
		&& mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(6) + mCollisionBoxMM->GetCollisonH(6)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(6))
	{

		mAudioMgr->BumpSFX();
		std::cout << "It is working, you can't Go Left..." << std::endl;
		mCamera->SetSpeed(0);
	}
	// check #7 left house right buttom
	if (mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(7) + mCollisionBoxMM->GetCollisonW(7)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(7) + mCollisionBoxMM->GetCollisonW(7)
		&& mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(7) + mCollisionBoxMM->GetCollisonH(7)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(7))
	{

		mAudioMgr->BumpSFX();
		std::cout << "It is working, you can't Go Left..." << std::endl;
		mCamera->SetSpeed(0);
	}
	// check #8 left house top
	if (mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(8) + mCollisionBoxMM->GetCollisonW(8)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(8) + mCollisionBoxMM->GetCollisonW(8)
		&& mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(8) + mCollisionBoxMM->GetCollisonH(8)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(8))
	{

		mAudioMgr->BumpSFX();
		std::cout << "It is working, you can't Go Left..." << std::endl;
		mCamera->SetSpeed(0);
	}
	// check #9 right house top
	if (mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(9) + mCollisionBoxMM->GetCollisonW(9)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(9) + mCollisionBoxMM->GetCollisonW(9)
		&& mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(9) + mCollisionBoxMM->GetCollisonH(9)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(9))
	{

		mAudioMgr->BumpSFX();
		std::cout << "It is working, you can't Go Left..." << std::endl;
		mCamera->SetSpeed(0);
	}
	// Check box #10 left house buttom + sign 
	if (mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(10) + mCollisionBoxMM->GetCollisonW(10)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(10) + mCollisionBoxMM->GetCollisonW(10)
		&& mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(10) + mCollisionBoxMM->GetCollisonH(10)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(10))
	{

		mAudioMgr->BumpSFX();
		std::cout << "It is working, you can't Go Left..." << std::endl;
		mCamera->SetSpeed(0);
	}
	// Check box #11 right house buttom 
	if (mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(11) + mCollisionBoxMM->GetCollisonW(11)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(11) + mCollisionBoxMM->GetCollisonW(11)
		&& mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(11) + mCollisionBoxMM->GetCollisonH(11)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(11))
	{

		mAudioMgr->BumpSFX();
		std::cout << "It is working, you can't Go Left..." << std::endl;
		mCamera->SetSpeed(0);
	}
	// Check box #12 buttom house left buttom 
	if (mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(12) + mCollisionBoxMM->GetCollisonW(12)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(12) + mCollisionBoxMM->GetCollisonW(12)
		&& mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(12) + mCollisionBoxMM->GetCollisonH(12)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(12))
	{

		mAudioMgr->BumpSFX();
		std::cout << "It is working, you can't Go Left..." << std::endl;
		mCamera->SetSpeed(0);
	}
	// Check box #13 buttom house top 
	if (mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(13) + mCollisionBoxMM->GetCollisonW(13)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(13) + mCollisionBoxMM->GetCollisonW(13)
		&& mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(13) + mCollisionBoxMM->GetCollisonH(13)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(13))
	{

		mAudioMgr->BumpSFX();
		std::cout << "It is working, you can't Go Left..." << std::endl;
		mCamera->SetSpeed(0);
	}
	// Check box #14 buttom house right buttom 
	if (mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(14) + mCollisionBoxMM->GetCollisonW(14)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(14) + mCollisionBoxMM->GetCollisonW(14)
		&& mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(14) + mCollisionBoxMM->GetCollisonH(14)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(14))
	{

		mAudioMgr->BumpSFX();
		std::cout << "It is working, you can't Go Left..." << std::endl;
		mCamera->SetSpeed(0);
	}
	// Check box #15 top border left side 
	if (mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(15) + mCollisionBoxMM->GetCollisonW(15)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(15) + mCollisionBoxMM->GetCollisonW(15)
		&& mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(15) + mCollisionBoxMM->GetCollisonH(15)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(15))
	{

		mAudioMgr->BumpSFX();
		std::cout << "It is working, you can't Go Left..." << std::endl;
		mCamera->SetSpeed(0);
	}
	// Check box #17 pallet town left border 
	if (mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(17) + mCollisionBoxMM->GetCollisonW(17)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(17) + mCollisionBoxMM->GetCollisonW(17)
		&& mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(17) + mCollisionBoxMM->GetCollisonH(17)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(17))
	{

		mAudioMgr->BumpSFX();
		std::cout << "It is working, you can't Go Left..." << std::endl;
		mCamera->SetSpeed(0);
	}
	// Check box #20 route1 left border middle 
	if (mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(20) + mCollisionBoxMM->GetCollisonW(20)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(20) + mCollisionBoxMM->GetCollisonW(20)
		&& mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(20) + mCollisionBoxMM->GetCollisonH(20)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(20))
	{

		mAudioMgr->BumpSFX();
		std::cout << "It is working, you can't Go Left..." << std::endl;
		mCamera->SetSpeed(0);
	}
	// Check box #24 route1 left border edge 
	if (mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(24) + mCollisionBoxMM->GetCollisonW(24)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(24) + mCollisionBoxMM->GetCollisonW(24)
		&& mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(24) + mCollisionBoxMM->GetCollisonH(24)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(24))
	{

		mAudioMgr->BumpSFX();
		std::cout << "It is working, you can't Go Left..." << std::endl;
		mCamera->SetSpeed(0);
	}
	//Check Battle event left turn
	if (mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetBattleEventY(0)
		&& mPlayer->GetWPosY() < mCollisionBoxMM->GetBattleEventY(0) + mCollisionBoxMM->GetBattleEventH(0)
		)
	{

		std::cout << "It is working Battle has began..." << std::endl;

	}
	// Check Dialog event left turn
	if (mPlayer->GetWPosX() < mCollisionBoxMM->GetDialogEventX(0) + mCollisionBoxMM->GetDialogEventW(0)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetDialogEventX(0) + mCollisionBoxMM->GetDialogEventW(0)
		&& mPlayer->GetWPosY() < mCollisionBoxMM->GetDialogEventY(0) + mCollisionBoxMM->GetDialogEventH(0)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetDialogEventY(0)
		)
	{

		std::cout << "It is working, Hello my name is NPS!!!" << std::endl;
		mCamera->SetSpeed(0);
	}

} // ^^^^^ TESTING COLLISIONS LEFT MOVE ^^^^^

void CollisionBoxMM::CheckMoveUp(Characters* mPlayer, Camera* mCamera, AudioManager* mAudioMgr, CollisionBoxMM* mCollisionBoxMM) {

	// ***** TESTING COLLISIONS MOVE UP *****
	mPlayer->SetWPosY(mPlayer->GetWPosY() - mCamera->GetSpeed());
	std::cout << "Player World X Y " << mPlayer->GetWPosX() << " " << mPlayer->GetWPosY() << std::endl;
	mCamera->SetSpeed(5);

	// check box #4 left sign
	if (mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(4) + mCollisionBoxMM->GetCollisonH(4)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(4) + mCollisionBoxMM->GetCollisonH(4)
		&& mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(4) + mCollisionBoxMM->GetCollisonW(4)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(4)

		)
	{
		mAudioMgr->BumpSFX();
		std::cout << "It is working You cant go up..." << std::endl;
		mCamera->SetSpeed(0);
	}
	// check box #4 right sign
	if (mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(5) + mCollisionBoxMM->GetCollisonH(5)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(5) + mCollisionBoxMM->GetCollisonH(5)
		&& mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(5) + mCollisionBoxMM->GetCollisonW(5)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(5)

		)
	{
		mAudioMgr->BumpSFX();
		std::cout << "It is working You cant go up..." << std::endl;
		mCamera->SetSpeed(0);
	}
	// check box #6 left house + sign
	if (mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(6) + mCollisionBoxMM->GetCollisonH(6)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(6) + mCollisionBoxMM->GetCollisonH(6)
		&& mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(6) + mCollisionBoxMM->GetCollisonW(6)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(6)

		)
	{
		mAudioMgr->BumpSFX();
		std::cout << "It is working You cant go up..." << std::endl;
		mCamera->SetSpeed(0);
	}
	// check box #7 left house right buttom
	if (mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(7) + mCollisionBoxMM->GetCollisonH(7)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(7) + mCollisionBoxMM->GetCollisonH(7)
		&& mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(7) + mCollisionBoxMM->GetCollisonW(7)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(7)

		)
	{
		mAudioMgr->BumpSFX();
		std::cout << "It is working You cant go up..." << std::endl;
		mCamera->SetSpeed(0);
	}
	// check box #8 left house top
	if (mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(8) + mCollisionBoxMM->GetCollisonH(8)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(8) + mCollisionBoxMM->GetCollisonH(8)
		&& mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(8) + mCollisionBoxMM->GetCollisonW(8)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(8)

		)
	{
		mAudioMgr->BumpSFX();
		std::cout << "It is working You cant go up..." << std::endl;
		mCamera->SetSpeed(0);
	}
	// check box #9 right house top
	if (mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(9) + mCollisionBoxMM->GetCollisonH(9)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(9) + mCollisionBoxMM->GetCollisonH(9)
		&& mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(9) + mCollisionBoxMM->GetCollisonW(9)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(9)

		)
	{
		mAudioMgr->BumpSFX();
		std::cout << "It is working You cant go up..." << std::endl;
		mCamera->SetSpeed(0);
	}
	// Check box #10 left house buttom + sign 
	if (mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(10) + mCollisionBoxMM->GetCollisonH(10)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(10) + mCollisionBoxMM->GetCollisonH(10)
		&& mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(10) + mCollisionBoxMM->GetCollisonW(10)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(10)

		)
	{
		mAudioMgr->BumpSFX();
		std::cout << "It is working You cant go up..." << std::endl;
		mCamera->SetSpeed(0);
	}
	// Check box #11 right house buttom
	if (mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(11) + mCollisionBoxMM->GetCollisonH(11)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(11) + mCollisionBoxMM->GetCollisonH(11)
		&& mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(11) + mCollisionBoxMM->GetCollisonW(11)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(11)

		)
	{
		mAudioMgr->BumpSFX();
		std::cout << "It is working You cant go up..." << std::endl;
		mCamera->SetSpeed(0);
	}
	// Check box #12 buttom house left buttom
	if (mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(12) + mCollisionBoxMM->GetCollisonH(12)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(12) + mCollisionBoxMM->GetCollisonH(12)
		&& mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(12) + mCollisionBoxMM->GetCollisonW(12)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(12)

		)
	{
		mAudioMgr->BumpSFX();
		std::cout << "It is working You cant go up..." << std::endl;
		mCamera->SetSpeed(0);
	}
	// Check box #13 buttom house top
	if (mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(13) + mCollisionBoxMM->GetCollisonH(13)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(13) + mCollisionBoxMM->GetCollisonH(13)
		&& mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(13) + mCollisionBoxMM->GetCollisonW(13)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(13)

		)
	{
		mAudioMgr->BumpSFX();
		std::cout << "It is working You cant go up..." << std::endl;
		mCamera->SetSpeed(0);
	}
	// Check box #14 buttom house buttom right
	if (mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(14) + mCollisionBoxMM->GetCollisonH(14)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(14) + mCollisionBoxMM->GetCollisonH(14)
		&& mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(14) + mCollisionBoxMM->GetCollisonW(14)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(14)

		)
	{
		mAudioMgr->BumpSFX();
		std::cout << "It is working You cant go up..." << std::endl;
		mCamera->SetSpeed(0);
	}
	// Check box #15 top border left side
	if (mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(15) + mCollisionBoxMM->GetCollisonH(15)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(15) + mCollisionBoxMM->GetCollisonH(15)
		&& mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(15) + mCollisionBoxMM->GetCollisonW(15)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(15)

		)
	{
		mAudioMgr->BumpSFX();
		std::cout << "It is working You cant go up..." << std::endl;
		mCamera->SetSpeed(0);
	}
	// Check box #16 top border right side
	if (mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(16) + mCollisionBoxMM->GetCollisonH(16)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(16) + mCollisionBoxMM->GetCollisonH(16)
		&& mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(16) + mCollisionBoxMM->GetCollisonW(16)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(16)

		)
	{
		mAudioMgr->BumpSFX();
		std::cout << "It is working You cant go up..." << std::endl;
		mCamera->SetSpeed(0);
	}

	// Checking battle events move UP
	if (mPlayer->GetWPosY() < mCollisionBoxMM->GetBattleEventY(0) + mCollisionBoxMM->GetBattleEventH(0)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetBattleEventY(0) 
		&& mPlayer->GetWPosX() < mCollisionBoxMM->GetBattleEventX(0) + mCollisionBoxMM->GetBattleEventW(0)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetBattleEventX(0)
		)
	{

		std::cout << "It is working Battle has began..." << std::endl;

		if (mCollisionBoxMM->GetAudioClick() == false)
		{
			mCollisionBoxMM->SetAudioClick(true);
			std::cout << "<<<< Audio switcher is working...\nRoad to Viridian City From Palette theme should playing..." << std::endl;
			mAudioMgr->RoadToViridianCitySound();
		}

	}



	// Check dialog events move UP
	if (mPlayer->GetWPosY() < mCollisionBoxMM->GetDialogEventY(0) + mCollisionBoxMM->GetDialogEventH(0)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetDialogEventY(0) + mCollisionBoxMM->GetDialogEventH(0)
		&& mPlayer->GetWPosX() < mCollisionBoxMM->GetDialogEventX(0) + mCollisionBoxMM->GetDialogEventW(0)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetDialogEventX(0)

		)
	{

		std::cout << "It is working, Hello my name is NPS!!!" << std::endl;
		mCamera->SetSpeed(0);
	}

} // ^^^^^ TESTING COLLISIONS MOVE UP ^^^^^

void CollisionBoxMM::CheckMoveDown(Characters* mPlayer, Camera* mCamera, AudioManager* mAudioMgr, CollisionBoxMM* mCollisionBoxMM) {

	// ***** TESTING COLLISIONS MOVE DOWN *****
	mPlayer->SetWPosY(mPlayer->GetWPosY() + mCamera->GetSpeed());
	std::cout << "Player World X Y " << mPlayer->GetWPosX() << " " << mPlayer->GetWPosY() << std::endl;
	mCamera->SetSpeed(5);

	// check box #0
	if (mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(0)
		&& mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(0)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(0)
		&& mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(0) + mCollisionBoxMM->GetCollisonW(0)

		)
	{
		mAudioMgr->BumpSFX();
		std::cout << "It is working, You can't go down..." << std::endl;
		mCamera->SetSpeed(0);
	}

	// check box #3 bottom border 
	if (mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(3)
		&& mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(3)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(3)
		&& mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(3) + mCollisionBoxMM->GetCollisonW(3)

		)
	{
		mAudioMgr->BumpSFX();
		std::cout << "It is working, You can't go down..." << std::endl;
		mCamera->SetSpeed(0);
	}

	// check box #4 left sign
	if (mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(4)
		&& mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(4)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(4)
		&& mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(4) + mCollisionBoxMM->GetCollisonW(4)

		)
	{
		mAudioMgr->BumpSFX();
		std::cout << "It is working, You can't go down..." << std::endl;
		mCamera->SetSpeed(0);
	}

	// check box #5 right sign
	if (mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(5)
		&& mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(5)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(5)
		&& mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(5) + mCollisionBoxMM->GetCollisonW(5)

		)
	{
		mAudioMgr->BumpSFX();
		std::cout << "It is working, You can't go down..." << std::endl;
		mCamera->SetSpeed(0);
	}
	// check box #6 left house + sign
	if (mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(6)
		&& mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(6)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(6)
		&& mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(6) + mCollisionBoxMM->GetCollisonW(6)

		)
	{
		mAudioMgr->BumpSFX();
		std::cout << "It is working, You can't go down..." << std::endl;
		mCamera->SetSpeed(0);
	}
	// check box #8 left house top
	if (mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(8)
		&& mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(8)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(8)
		&& mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(8) + mCollisionBoxMM->GetCollisonW(8)

		)
	{
		mAudioMgr->BumpSFX();
		std::cout << "It is working, You can't go down..." << std::endl;
		mCamera->SetSpeed(0);
	}
	// check box #9 right house top
	if (mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(9)
		&& mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(9)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(9)
		&& mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(9) + mCollisionBoxMM->GetCollisonW(9)

		)
	{
		mAudioMgr->BumpSFX();
		std::cout << "It is working, You can't go down..." << std::endl;
		mCamera->SetSpeed(0);
	}
	// Check box #10 left house buttom + sign 
	if (mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(10)
		&& mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(10)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(10)
		&& mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(10) + mCollisionBoxMM->GetCollisonW(10)

		)
	{
		mAudioMgr->BumpSFX();
		std::cout << "It is working, You can't go down..." << std::endl;
		mCamera->SetSpeed(0);
	}
	// Check box #13 buttom house top
	if (mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(13)
		&& mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(13)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(13)
		&& mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(13) + mCollisionBoxMM->GetCollisonW(13)

		)
	{
		mAudioMgr->BumpSFX();
		std::cout << "It is working, You can't go down..." << std::endl;
		mCamera->SetSpeed(0);
	}
	// Check box #19 buttom border left side
	if (mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(19)
		&& mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(19)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(19)
		&& mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(19) + mCollisionBoxMM->GetCollisonW(19)

		)
	{
		mAudioMgr->BumpSFX();
		std::cout << "It is working, You can't go down..." << std::endl;
		mCamera->SetSpeed(0);
	}
	// Check box #20 route1 left border middle 
	if (mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(20)
		&& mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(20)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(20)
		&& mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(20) + mCollisionBoxMM->GetCollisonW(20)

		)
	{
		mAudioMgr->BumpSFX();
		std::cout << "It is working, You can't go down..." << std::endl;
		mCamera->SetSpeed(0);
	}
	// Check box #21 route1 border middle right 
	if (mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(21)
		&& mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(21)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(21)
		&& mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(21) + mCollisionBoxMM->GetCollisonW(21)

		)
	{
		mAudioMgr->BumpSFX();
		std::cout << "It is working, You can't go down..." << std::endl;
		mCamera->SetSpeed(0);
	}
	// Check box #22 route1 middle left border on left  
	if (mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(22)
		&& mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(22)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(22)
		&& mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(22) + mCollisionBoxMM->GetCollisonW(22)

		)
	{
		mAudioMgr->BumpSFX();
		std::cout << "It is working, You can't go down..." << std::endl;
		mCamera->SetSpeed(0);
	}
	// Check box #23 route1 middle left border on left  
	if (mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonY(23)
		&& mPlayer->GetWPosY() < mCollisionBoxMM->GetCollisonY(23)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetCollisonX(23)
		&& mPlayer->GetWPosX() < mCollisionBoxMM->GetCollisonX(23) + mCollisionBoxMM->GetCollisonW(23)

		)
	{
		mAudioMgr->BumpSFX();
		std::cout << "It is working, You can't go down..." << std::endl;
		mCamera->SetSpeed(0);
	}
	// Checking battle events move DOWN
	if (mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetBattleEventY(0)
		&& mPlayer->GetWPosY() < mCollisionBoxMM->GetBattleEventY(0) + mCollisionBoxMM->GetBattleEventH(0)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetBattleEventX(0)
		&& mPlayer->GetWPosX() < mCollisionBoxMM->GetBattleEventX(0) + mCollisionBoxMM->GetBattleEventW(0)

		)
	{
	
		std::cout << "It is working Battle has began..." << std::endl;
		
	}

	if (mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetDialogEventY(0)
		&& mPlayer->GetWPosY() < mCollisionBoxMM->GetDialogEventY(0)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetDialogEventX(0)
		&& mPlayer->GetWPosX() < mCollisionBoxMM->GetDialogEventX(0) + mCollisionBoxMM->GetDialogEventW(0)

		)
	{

		std::cout << "It is working, Hello my name is NPS!!!" << std::endl;
		mCamera->SetSpeed(0);
	}

	if (mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxMM->GetAudioSwitcherY(0)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxMM->GetAudioSwitcherX(0)
		&& mPlayer->GetWPosX() < mCollisionBoxMM->GetAudioSwitcherX(0) + mCollisionBoxMM->GetAudioSwitcherW(0)
		&& mCollisionBoxMM->GetAudioClick() == true)
	{
		std::cout << "<<<<  Audio switcher turned back... \nPallet Town Theme Should Playing" << std::endl;
		mAudioMgr->PalletTownSound();
		mCollisionBoxMM->SetAudioClick(false);
	}

} // ***** TESTING COLLISIONS MOVE DOWN *****


void CollisionBoxMM::Render() {

	Vector2 pos = Pos(WORLD);
	GetmTex()->SetRenderRectX((int)(GetPosX()));
	GetmTex()->SetRenderRectY((int)(GetPosY()));

	mGraphics->DrawTexture(GetmTex()->GetSDLTex(), (GetmTex()->GetClipped()) ? &GetmTex()->GetmClipRect() : NULL, &GetmTex()->GetmRenderRect());

}