#include "startRoom.h"

StartRoom::StartRoom() {

	mFloor = new AnimatedTexture("01_Start_Game_Room.png", 0, 0, 16, 16, 1, 0, AnimatedTexture::HORIZONTAL);
	mObjects = new AnimatedTexture("01_Start_Game_Room.png", 16, 16, 32, 32, 1, 0, AnimatedTexture::HORIZONTAL);
	mComputer = new AnimatedTexture("01_Start_Game_Room.png", 0, 16, 32, 32, 1, 0, AnimatedTexture::HORIZONTAL);
}

StartRoom::~StartRoom() {
	delete mFloor;
	mFloor = NULL;

	delete mObjects;
	mObjects = NULL;

	delete mComputer;
	mComputer = NULL;
}