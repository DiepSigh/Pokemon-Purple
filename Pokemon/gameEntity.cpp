#include "gameEntity.h"

GameEntity::GameEntity(float x, float y) {
	mPos.x = x;
	mPos.y = y;
	mRotation = 0.0f;
	mActive = true;
	mParent = NULL;
}

GameEntity::~GameEntity() {
	mParent = NULL;
}

void GameEntity::Pos(Vector2 pos) {
	mPos = pos;
}

Vector2 GameEntity::Pos(SPACE space) {
	if (space == LOCAL || mParent == NULL) {
		return mPos;
	}

	return mParent->Pos(WORLD) + RotateVector(mPos, mParent->Rotation(LOCAL));
}

void GameEntity::Rotation(float r) {
	mRotation = r;

	if (mRotation > 360.0f) {
		mRotation -= 360.0f;
	}

	if (mRotation < 0.0f) {
		mRotation += 360.0f;
	}
}

float GameEntity::Rotation(SPACE space) {
	if (space == LOCAL || mParent == NULL) {
		return mRotation;
	}

	return mParent->Rotation(WORLD) + mRotation;
}

void GameEntity::Active(bool active) {
	mActive = active;
}

bool GameEntity::Active() {
	return mActive;
}

void GameEntity::Parent(GameEntity* parent) {
	mPos = Pos(WORLD) - parent->Pos(WORLD);
	mParent = parent;
}

GameEntity* GameEntity::Parent() {
	return mParent;
}

void GameEntity::Update(){}

void GameEntity::Render() {}