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
	
	mTex = new Texture("collisionBox_test.png", 0, 0, 32, 32);
	
	mGraphics = Graphics::Instance();
	
	mPos.x = x;
	mPos.y = y;

	mCollisionBoxes[0] = Texture(-174 + cam->GetXPos(), 165 + cam->GetYPos(), 124, 32);
	mCollisionBoxes[1] = Texture(-174 + cam->GetXPos(), 165 + cam->GetYPos(), 32, 96);
	mCollisionBoxes[2] = Texture(-80 + cam->GetXPos(), 165 + cam->GetYPos(), 32, 96);
	mCollisionBoxes[3] = Texture(-46 + cam->GetXPos(), 262 + cam->GetYPos(), 352, 32); 
	mCollisionBoxes[4] = Texture(-175 + cam->GetXPos(), 5 + cam->GetYPos(), 124, 32); // left sign
	mCollisionBoxes[5] = Texture(15 + cam->GetXPos(), 135 + cam->GetYPos(), 192, 32); // right sign
	mCollisionBoxes[6] = Texture(-208 + cam->GetXPos(), -122 + cam->GetYPos(), 60, 32); // left house
	mCollisionBoxes[7] = Texture(-110 + cam->GetXPos(), -122 + cam->GetYPos(), 60, 32); // left house  right bottom
//	mCollisionBoxes[8] = Texture(-174, -186, 124, 64);
//	mCollisionBoxes[9] = Texture(82, -186, 124, 64);
//	mCollisionBoxes[10] = Texture(48, -122, 64, 32);
//	mCollisionBoxes[11] = Texture(145, -122, 64, 32);
//	mCollisionBoxes[12] = Texture(18, 70, 62, 32);
//	mCollisionBoxes[13] = Texture(18, -26, 188, 96);
//	mCollisionBoxes[14] = Texture(112, 70, 94, 32);
//	mCollisionBoxes[15] = Texture(-273, -250, 288, 32);
//	mCollisionBoxes[16] = Texture(83, -250, 220, 32);
//	mCollisionBoxes[17] = Texture(-305, -218, 32, 480);
//	mCollisionBoxes[18] = Texture(305, -216, 32, 480);

///	mCollisionBoxes[19] = Texture(-17, -410, 32, 160);
///	mCollisionBoxes[20] = Texture(-176, -410, 160, 32);
///	mCollisionBoxes[21] = Texture(-208, -1372, 32, 966);
///	mCollisionBoxes[22] = Texture(-176, -1404, 192, 32);
///	mCollisionBoxes[23] = Texture(-16, -1560, 32, 156);
///	mCollisionBoxes[24] = Texture(83, -410, 32, 160);
///	mCollisionBoxes[25] = Texture(83, -410, 188, 32);
///	mCollisionBoxes[26] = Texture(272, -1372, 32, 966);
///	mCollisionBoxes[27] = Texture(80, -1404, 192, 32);
///	mCollisionBoxes[28] = Texture(80, -1560, 32, 160);
///	mCollisionBoxes[29] = Texture(-16, -570, 32, 32);
///	mCollisionBoxes[30] = Texture(16, -554, 256, 16);
///	mCollisionBoxes[31] = Texture(-176, -554, 64, 16);
///	mCollisionBoxes[22] = Texture(-176, -698, 256, 32);
///	mCollisionBoxes[33] = Texture(208, -682, 96, 16);
///	mCollisionBoxes[34] = Texture(-176, -810, 32, 16);
///	mCollisionBoxes[35] = Texture(-112, -810, 96, 16);
///	mCollisionBoxes[36] = Texture(16, -810, 256, 16);
///	mCollisionBoxes[37] = Texture(-176, -1018, 64, 32);
///	mCollisionBoxes[38] = Texture(-112, -1002, 126, 16);
///	mCollisionBoxes[39] = Texture(10, -1018, 132, 32);
///	mCollisionBoxes[40] = Texture(-176, -1130, 190, 16);
///	mCollisionBoxes[41] = Texture(-176, -1258, 320, 16);
///	mCollisionBoxes[42] = Texture(-18, -1312, 32, 188);
///	mCollisionBoxes[43] = Texture(48, -1626, 32, 32);

	
		
}


CollisionBoxMM::~CollisionBoxMM() {

	delete mTex;
	mTex = NULL;
	
}

void CollisionBoxMM::DrawCollisions(Camera* cam) {
	

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
	// **** RIGHT SIGN ****
	mTex->SetRenderRectW(192);
	mTex->SetRenderRectH(32);
	SetPosX(15 + cam->GetXPos());
	SetPosY(135 + cam->GetYPos());
	Render();
	// **** LEFT HOUSE left bottom **** 
	mTex->SetRenderRectW(60);
	mTex->SetRenderRectH(32);
	SetPosX(-208 + cam->GetXPos());
	SetPosY(-122 + cam->GetYPos());
	Render();
	// **** LEFT HOUSE right bottom ****
	mTex->SetRenderRectW(60);
	mTex->SetRenderRectH(32);
	SetPosX(-110 + cam->GetXPos());
	SetPosY(-122 + cam->GetYPos());
	Render();
/*	mTex->SetRenderRectW(124);
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
	*/

	/*	// **** BOTTOM BORDER LEFT ****
	mTex->SetRenderRectW(96);
	mTex->SetRenderRectH(32);
	SetPosX(-273 + cam->GetXPos());
	SetPosY(262 + cam->GetYPos());
	Render();  */
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

}

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

}

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
	// check box #6 left hous + sign
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

}

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
}


void CollisionBoxMM::Render() {

	Vector2 pos = Pos(WORLD);
	GetmTex()->SetRenderRectX((int)(GetPosX()));
	GetmTex()->SetRenderRectY((int)(GetPosY()));

	mGraphics->DrawTexture(GetmTex()->GetSDLTex(), (GetmTex()->GetClipped()) ? &GetmTex()->GetmClipRect() : NULL, &GetmTex()->GetmRenderRect());

}