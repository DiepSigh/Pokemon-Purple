#include "CollisionBoxesPH.h"

CollisionBoxPH* CollisionBoxPH::sInstance = nullptr;

CollisionBoxPH* CollisionBoxPH::Instance() {
	if (sInstance == nullptr) {
		sInstance = new CollisionBoxPH(0, 0,Camera::Instance());
	}

	return sInstance;
}

CollisionBoxPH::CollisionBoxPH() {}

CollisionBoxPH::CollisionBoxPH(float x, float y, Camera* cam) {

	mCollisions = new Texture("collisionBox.png", 0, 0, 32, 32);
	mExit = new Texture("exitBox.png", 0, 0, 32, 32);

	mGraphics = Graphics::Instance();
	mPos.x = x;
	mPos.y = y;

	mOutOfHouse[0] = Texture(180 + cam->GetXPos(), -78 + cam->GetYPos(), 32, 32); // uot of house

	mCollisionBoxes[0] = Texture(-50 + cam->GetXPos(), -100 + cam->GetYPos(), 60, 60); // bookshelf 
	mCollisionBoxes[1] = Texture(14 + cam->GetXPos(), -100 + cam->GetYPos(), 192, 32); // wall
	mCollisionBoxes[2] = Texture(48 + cam->GetXPos(), 28 + cam->GetYPos(), 60, 60); // table
	mCollisionBoxes[3] = Texture(48 + cam->GetXPos(), -68 + cam->GetYPos(), 28, 32); // tv
	mCollisionBoxes[4] = Texture(-82 + cam->GetXPos(), -100 + cam->GetYPos(), 32, 256); // left side
	mCollisionBoxes[5] = Texture(-50 + cam->GetXPos(), 156 + cam->GetYPos(), 256, 32); // bottom side
	mCollisionBoxes[6] = Texture(206 + cam->GetXPos(), -68 + cam->GetYPos(), 32, 224); // right side


}

CollisionBoxPH::~CollisionBoxPH() {

	delete mTex;
	mTex = NULL;
	delete mCollisions;
	mCollisions = NULL;
	delete mExit;
	mExit = NULL;
	
}

void CollisionBoxPH::DrawExitTile(Camera* cam) {
	mTex = mExit;
	mTex->SetRenderRectW(32);
	mTex->SetRenderRectH(32);
	SetPosX(180 + cam->GetXPos());
	SetPosY(-78 + cam->GetYPos());
	Render();

}

void CollisionBoxPH::DrawCollisions(Camera* cam) {

	mTex = mCollisions;
	// **** BOOKSHELF #0 ****  
	mTex->SetRenderRectW(64);
	mTex->SetRenderRectH(64);
	SetPosX(-54 + cam->GetXPos());
	SetPosY(-100 + cam->GetYPos());
	Render();

	// **** WALL #1 **** 
	mTex->SetRenderRectW(192);
	mTex->SetRenderRectH(32);
	SetPosX(14 + cam->GetXPos());
	SetPosY(-100 + cam->GetYPos());
	Render();

	// **** TABLE #2 **** 
	mTex->SetRenderRectW(64);
	mTex->SetRenderRectH(64);
	SetPosX(46 + cam->GetXPos());
	SetPosY(28 + cam->GetYPos());
	Render();

	// **** TV # 3 **** 
	mTex->SetRenderRectW(28);
	mTex->SetRenderRectH(32);
	SetPosX(48 + cam->GetXPos());
	SetPosY(-68 + cam->GetYPos());
	Render();

	// **** LEFT SIDE #4 ****
	mTex->SetRenderRectW(32);
	mTex->SetRenderRectH(256);
	SetPosX(-82 + cam->GetXPos());
	SetPosY(-100 + cam->GetYPos());
	Render();

	// **** BOTTOM SIDE #5 ****
	mTex->SetRenderRectW(256);
	mTex->SetRenderRectH(32);
	SetPosX(-50 + cam->GetXPos());
	SetPosY(156 + cam->GetYPos());
	Render();

	// **** RIGHT SIDE #6 ****
	mTex->SetRenderRectW(32);
	mTex->SetRenderRectH(224);
	SetPosX(206 + cam->GetXPos());
	SetPosY(-68 + cam->GetYPos());
	Render();
}

void CollisionBoxPH::CheckMoveRight(Characters* mPlayer, Camera* mCamera, AudioManager* mAudioMgr, CollisionBoxPH* mCollisionBoxPH) {



	// ***** TESTING COLLISIONS RIGHT MOVE *****
	mPlayer->SetWPosX(mPlayer->GetWPosX() + mCamera->GetSpeed());
	std::cout << "Player World X Y " << mPlayer->GetWPosX() << " " << mPlayer->GetWPosY() << std::endl;
	mCamera->SetSpeed(5);

	// check box #2 Table right move
	if (mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxPH->GetCollisonX(2)
		&& mPlayer->GetWPosX() < mCollisionBoxPH->GetCollisonX(2)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxPH->GetCollisonY(2)
		&& mPlayer->GetWPosY() < mCollisionBoxPH->GetCollisonY(2) + mCollisionBoxPH->GetCollisonH(2)
		)
	{

		mAudioMgr->BumpSFX();
		std::cout << "It is working, you can't go Right" << std::endl;
		mCamera->SetSpeed(0);
		
	}

	// check box #3 TV right move
	if (mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxPH->GetCollisonX(3)
		&& mPlayer->GetWPosX() < mCollisionBoxPH->GetCollisonX(3)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxPH->GetCollisonY(3)
		&& mPlayer->GetWPosY() < mCollisionBoxPH->GetCollisonY(3) + mCollisionBoxPH->GetCollisonH(3)
		)
	{

		mAudioMgr->BumpSFX();
		std::cout << "It is working, you can't go Right" << std::endl;
		mCamera->SetSpeed(0);
		
	}

	// check box #6 right line right move
	if (mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxPH->GetCollisonX(6)
		&& mPlayer->GetWPosX() < mCollisionBoxPH->GetCollisonX(6)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxPH->GetCollisonY(6)
		&& mPlayer->GetWPosY() < mCollisionBoxPH->GetCollisonY(6) + mCollisionBoxPH->GetCollisonH(6)
		)
	{

		mAudioMgr->BumpSFX();
		std::cout << "It is working, you can't go Right" << std::endl;
		mCamera->SetSpeed(0);
		
	}

	// check box out of house
	if (mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxPH->GetExitTileX(0)
		&& mPlayer->GetWPosX() < mCollisionBoxPH->GetExitTileX(0)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxPH->GetExitTileY(0)
		&& mPlayer->GetWPosY() < mCollisionBoxPH->GetExitTileY(0) + mCollisionBoxPH->GetExitTileH(0)
		)
	{
		std::cout << "It's working... \nYou get out of house..." << std::endl;
	}
}

void CollisionBoxPH::CheckMoveLeft(Characters* mPlayer, Camera* mCamera, AudioManager* mAudioMgr, CollisionBoxPH* mCollisionBoxPH) {

	// ***** TESTING COLLISIONS LEFT MOVE *****
	mPlayer->SetWPosX(mPlayer->GetWPosX() - mCamera->GetSpeed());
	std::cout << "Player World X Y " << mPlayer->GetWPosX() << " " << mPlayer->GetWPosY() << std::endl;
	mCamera->SetSpeed(5);

	// check box #0 Bookshelf
	if (mPlayer->GetWPosX() < mCollisionBoxPH->GetCollisonX(0) + mCollisionBoxPH->GetCollisonW(0)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxPH->GetCollisonX(0) + mCollisionBoxPH->GetCollisonW(0)
		&& mPlayer->GetWPosY() < mCollisionBoxPH->GetCollisonY(0) + mCollisionBoxPH->GetCollisonH(0)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxPH->GetCollisonY(0))
	{

		mAudioMgr->BumpSFX();
		std::cout << "It is working, you can't Go Left..." << std::endl;
		mCamera->SetSpeed(0);
	}

	// check box #2 Table
	if (mPlayer->GetWPosX() < mCollisionBoxPH->GetCollisonX(2) + mCollisionBoxPH->GetCollisonW(2)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxPH->GetCollisonX(2) + mCollisionBoxPH->GetCollisonW(2)
		&& mPlayer->GetWPosY() < mCollisionBoxPH->GetCollisonY(2) + mCollisionBoxPH->GetCollisonH(2)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxPH->GetCollisonY(2))
	{

		mAudioMgr->BumpSFX();
		std::cout << "It is working, you can't Go Left..." << std::endl;
		mCamera->SetSpeed(0);
	}

	// check box #3 TV
	if (mPlayer->GetWPosX() < mCollisionBoxPH->GetCollisonX(3) + mCollisionBoxPH->GetCollisonW(3)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxPH->GetCollisonX(3) + mCollisionBoxPH->GetCollisonW(3)
		&& mPlayer->GetWPosY() < mCollisionBoxPH->GetCollisonY(3) + mCollisionBoxPH->GetCollisonH(3)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxPH->GetCollisonY(3))
	{

		mAudioMgr->BumpSFX();
		std::cout << "It is working, you can't Go Left..." << std::endl;
		mCamera->SetSpeed(0);
	}

	// check box #4 left line left move
	if (mPlayer->GetWPosX() < mCollisionBoxPH->GetCollisonX(4) + mCollisionBoxPH->GetCollisonW(4)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxPH->GetCollisonX(4) + mCollisionBoxPH->GetCollisonW(4)
		&& mPlayer->GetWPosY() < mCollisionBoxPH->GetCollisonY(4) + mCollisionBoxPH->GetCollisonH(4)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxPH->GetCollisonY(4))
	{

		mAudioMgr->BumpSFX();
		std::cout << "It is working, you can't Go Left..." << std::endl;
		mCamera->SetSpeed(0);
	}
}

void CollisionBoxPH::CheckMoveUp(Characters* mPlayer, Camera* mCamera, AudioManager* mAudioMgr, CollisionBoxPH* mCollisionBoxPH) {

	// ***** TESTING COLLISIONS MOVE UP *****
	mPlayer->SetWPosY(mPlayer->GetWPosY() - mCamera->GetSpeed());
	std::cout << "Player World X Y " << mPlayer->GetWPosX() << " " << mPlayer->GetWPosY() << std::endl;
	mCamera->SetSpeed(5);

	// check box #1 Wall move up
	if (mPlayer->GetWPosY() < mCollisionBoxPH->GetCollisonY(1) + mCollisionBoxPH->GetCollisonH(1)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxPH->GetCollisonY(1) + mCollisionBoxPH->GetCollisonH(1)
		&& mPlayer->GetWPosX() < mCollisionBoxPH->GetCollisonX(1) + mCollisionBoxPH->GetCollisonW(1)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxPH->GetCollisonX(1)

		)
	{
		mAudioMgr->BumpSFX();
		std::cout << "It is working You cant go up..." << std::endl;
		mCamera->SetSpeed(0);
		
	}


	// check box #0 Bookshelf move up
	if (mPlayer->GetWPosY() < mCollisionBoxPH->GetCollisonY(0) + mCollisionBoxPH->GetCollisonH(0)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxPH->GetCollisonY(0) + mCollisionBoxPH->GetCollisonH(0)
		&& mPlayer->GetWPosX() < mCollisionBoxPH->GetCollisonX(0) + mCollisionBoxPH->GetCollisonW(0)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxPH->GetCollisonX(0)

		)
	{
		mAudioMgr->BumpSFX();
		std::cout << "It is working You cant go up..." << std::endl;
		mCamera->SetSpeed(0);
	}



	// check box #2 Table move up
	if (mPlayer->GetWPosY() < mCollisionBoxPH->GetCollisonY(2) + mCollisionBoxPH->GetCollisonH(2)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxPH->GetCollisonY(2) + mCollisionBoxPH->GetCollisonH(2)
		&& mPlayer->GetWPosX() < mCollisionBoxPH->GetCollisonX(2) + mCollisionBoxPH->GetCollisonW(2)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxPH->GetCollisonX(2))
	{
		mAudioMgr->BumpSFX();
		std::cout << "It is working You cant go up..." << std::endl;
		mCamera->SetSpeed(0);
	}

	// check box #3 TV move up
	if (mPlayer->GetWPosY() < mCollisionBoxPH->GetCollisonY(3) + mCollisionBoxPH->GetCollisonH(3)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxPH->GetCollisonY(3) + mCollisionBoxPH->GetCollisonH(3)
		&& mPlayer->GetWPosX() < mCollisionBoxPH->GetCollisonX(3) + mCollisionBoxPH->GetCollisonW(3)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxPH->GetCollisonX(3))
	{
		mAudioMgr->BumpSFX();
		std::cout << "It is working You cant go up..." << std::endl;
		mCamera->SetSpeed(0);
		
	}

	if (mPlayer->GetWPosY() < mCollisionBoxPH->GetExitTileY(0) + mCollisionBoxPH->GetExitTileH(0)
		&& mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxPH->GetExitTileY(0) + mCollisionBoxPH->GetExitTileH(0)
		&& mPlayer->GetWPosX() < mCollisionBoxPH->GetExitTileX(0) + mCollisionBoxPH->GetExitTileW(0)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxPH->GetExitTileX(0))
	{
		std::cout << "It's working... \nYou get out of house..." << std::endl;
		
	}
	
}

void CollisionBoxPH::CheckMoveDown(Characters* mPlayer, Camera* mCamera, AudioManager* mAudioMgr, CollisionBoxPH* mCollisionBoxPH) {

	// ***** TESTING COLLISIONS MOVE DOWN *****
	mPlayer->SetWPosY(mPlayer->GetWPosY() + mCamera->GetSpeed());
	std::cout << "Player World X Y " << mPlayer->GetWPosX() << " " << mPlayer->GetWPosY() << std::endl;
	mCamera->SetSpeed(5);

	// check box #2 Table
	if (mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxPH->GetCollisonY(2)
		&& mPlayer->GetWPosY() < mCollisionBoxPH->GetCollisonY(2)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxPH->GetCollisonX(2)
		&& mPlayer->GetWPosX() < mCollisionBoxPH->GetCollisonX(2) + mCollisionBoxPH->GetCollisonW(2)

		)
	{
		mAudioMgr->BumpSFX();
		std::cout << "It is working, You can't go down..." << std::endl;
		mCamera->SetSpeed(0);

	}

	// check box #5 bottom line
	if (mPlayer->GetWPosY() + mPlayer->GetPlSize() > mCollisionBoxPH->GetCollisonY(5)
		&& mPlayer->GetWPosY() < mCollisionBoxPH->GetCollisonY(5)
		&& mPlayer->GetWPosX() + mPlayer->GetPlSize() > mCollisionBoxPH->GetCollisonX(5)
		&& mPlayer->GetWPosX() < mCollisionBoxPH->GetCollisonX(5) + mCollisionBoxPH->GetCollisonW(5)

		)
	{
		mAudioMgr->BumpSFX();
		std::cout << "It is working, You can't go down..." << std::endl;
		mCamera->SetSpeed(0);
	}
}


void CollisionBoxPH::Render() {

	Vector2 pos = Pos(WORLD);
	GetmTex()->SetRenderRectX((int)(GetPosX()));
	GetmTex()->SetRenderRectY((int)(GetPosY()));

	mGraphics->DrawTexture(GetmTex()->GetSDLTex(), (GetmTex()->GetClipped()) ? &GetmTex()->GetmClipRect() : NULL, &GetmTex()->GetmRenderRect());
}