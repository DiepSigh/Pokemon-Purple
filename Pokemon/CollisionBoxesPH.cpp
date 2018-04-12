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

	mCollisionBoxes[0] = Texture(-50+400, -100+300, 64, 64);
	mCollisionBoxes[1] = Texture(14+400, -100+300, 192, 32);
	mCollisionBoxes[2] = Texture(46+400, 28+300, 64, 64);
	mCollisionBoxes[3] = Texture(46+400, -68+300, 32, 32);
	mCollisionBoxes[4] = Texture(-82+400, -100+300, 32, 256);
	mCollisionBoxes[5] = Texture(-50+400, 156+300, 256, 32);
	mCollisionBoxes[6] = Texture(206+400, -68+300, 32, 224);

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

/*	// **** TV **** 
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
*/
}

void CollisionBoxPH::CheckMoveRight(Characters* mPlayer, Camera* mCamera, AudioManager* mAudioMgr, CollisionBoxPH* mCollisionBoxPH) {


	// ***** TESTING COLLISIONS RIGHT MOVE *****
	mPlayer->SetWPosX(mPlayer->GetWPosX() + mCamera->GetSpeed());
	std::cout << "Player World X Y " << mPlayer->GetWPosX() << " " << mPlayer->GetWPosY() << std::endl;


	// check box #2 Table
	if (mPlayer->GetWPosX() + mPlayer->GetPlSize() >= mCollisionBoxPH->GetCollisonX(2)
		&& mPlayer->GetWPosX() < mCollisionBoxPH->GetCollisonX(2)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxPH->GetCollisonY(2)
		&& mPlayer->GetWPosY() < mCollisionBoxPH->GetCollisonY(2) + mCollisionBoxPH->GetCollisonH(2)
		)
	{

		mAudioMgr->BumpSFX();
		std::cout << "It is working, you can't go Right" << std::endl;
	}

}

void CollisionBoxPH::CheckMoveLeft(Characters* mPlayer, Camera* mCamera, AudioManager* mAudioMgr, CollisionBoxPH* mCollisionBoxPH) {

	// ***** TESTING COLLISIONS LEFT MOVE *****
	mPlayer->SetWPosX(mPlayer->GetWPosX() - mCamera->GetSpeed());
	std::cout << "Player World X Y " << mPlayer->GetWPosX() << " " << mPlayer->GetWPosY() << std::endl;

	// check box #0 Bookshelf
	if (mPlayer->GetWPosX() <= mCollisionBoxPH->GetCollisonX(0) + mCollisionBoxPH->GetCollisonW(0)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxPH->GetCollisonX(0) + mCollisionBoxPH->GetCollisonW(0)
		&& mPlayer->GetWPosY() < mCollisionBoxPH->GetCollisonY(0) + mCollisionBoxPH->GetCollisonH(0)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxPH->GetCollisonY(0))
	{

		mAudioMgr->BumpSFX();
		std::cout << "It is working, you can't Go Left..." << std::endl;
	}

	// check box #2 Table
	if (mPlayer->GetWPosX() <= mCollisionBoxPH->GetCollisonX(2) + mCollisionBoxPH->GetCollisonW(2)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxPH->GetCollisonX(2) + mCollisionBoxPH->GetCollisonW(2)
		&& mPlayer->GetWPosY() < mCollisionBoxPH->GetCollisonY(2) + mCollisionBoxPH->GetCollisonH(2)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxPH->GetCollisonY(2))
	{

		mAudioMgr->BumpSFX();
		std::cout << "It is working, you can't Go Left..." << std::endl;
	}


}

void CollisionBoxPH::CheckMoveUp(Characters* mPlayer, Camera* mCamera, AudioManager* mAudioMgr, CollisionBoxPH* mCollisionBoxPH) {

	// ***** TESTING COLLISIONS MOVE UP *****
	mPlayer->SetWPosY(mPlayer->GetWPosY() - mCamera->GetSpeed());
	std::cout << "Player World X Y " << mPlayer->GetWPosX() << " " << mPlayer->GetWPosY() << std::endl;

	// check box #0 Bookshelf
	if (mPlayer->GetWPosY() < mCollisionBoxPH->GetCollisonY(0) + mCollisionBoxPH->GetCollisonH(0)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxPH->GetCollisonY(0) + mCollisionBoxPH->GetCollisonH(0)
		&& mPlayer->GetWPosX() < mCollisionBoxPH->GetCollisonX(0) + mCollisionBoxPH->GetCollisonH(0)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxPH->GetCollisonX(0)

		)
	{
		mAudioMgr->BumpSFX();
		std::cout << "It is working You cant go up..." << std::endl;
	}

	// check box #1 Wall
	if (mPlayer->GetWPosY() < mCollisionBoxPH->GetCollisonY(1) + mCollisionBoxPH->GetCollisonH(1)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxPH->GetCollisonY(1) + mCollisionBoxPH->GetCollisonH(1)
		&& mPlayer->GetWPosX() < mCollisionBoxPH->GetCollisonX(1) + mCollisionBoxPH->GetCollisonH(1)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxPH->GetCollisonX(1))
	{
		mAudioMgr->BumpSFX();
		std::cout << "It is working You cant go up..." << std::endl;
	}

	// check box #2 Table
	if (mPlayer->GetWPosY() < mCollisionBoxPH->GetCollisonY(2) + mCollisionBoxPH->GetCollisonH(2)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxPH->GetCollisonY(2) + mCollisionBoxPH->GetCollisonH(2)
		&& mPlayer->GetWPosX() < mCollisionBoxPH->GetCollisonX(2) + mCollisionBoxPH->GetCollisonH(2)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxPH->GetCollisonX(2))
	{
		mAudioMgr->BumpSFX();
		std::cout << "It is working You cant go up..." << std::endl;
	}

}

void CollisionBoxPH::CheckMoveDown(Characters* mPlayer, Camera* mCamera, AudioManager* mAudioMgr, CollisionBoxPH* mCollisionBoxPH) {

	// ***** TESTING COLLISIONS MOVE DOWN *****
	mPlayer->SetWPosY(mPlayer->GetWPosY() + mCamera->GetSpeed());
	std::cout << "Player World X Y " << mPlayer->GetWPosX() << " " << mPlayer->GetWPosY() << std::endl;

	// check box #2 Table
	if (mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxPH->GetCollisonY(2)
		&& mPlayer->GetWPosY() < mCollisionBoxPH->GetCollisonY(2)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxPH->GetCollisonX(2)
		&& mPlayer->GetWPosX() < mCollisionBoxPH->GetCollisonX(2) + mCollisionBoxPH->GetCollisonW(2)

		)
	{
		mAudioMgr->BumpSFX();
		std::cout << "It is working, You can't go down..." << std::endl;
	}
}


void CollisionBoxPH::Render() {

	Vector2 pos = Pos(WORLD);
	GetmTex()->SetRenderRectX((int)(GetPosX()));
	GetmTex()->SetRenderRectY((int)(GetPosY()));

	mGraphics->DrawTexture(GetmTex()->GetSDLTex(), (GetmTex()->GetClipped()) ? &GetmTex()->GetmClipRect() : NULL, &GetmTex()->GetmRenderRect());
}