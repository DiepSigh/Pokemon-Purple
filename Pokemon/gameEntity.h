#ifndef GAMEENTITY_H
#define GAMEENTITY_H

#include "mathHelper.h"
#include "animatedTexture.h"

class GameEntity {
protected:
	Texture* mTex;
	AnimatedTexture* mAtex;

public:
	enum SPACE {LOCAL = 0, WORLD = 1};

private:
	Vector2 mPos;
	float  mRotation;
	bool mActive;
	GameEntity* mParent;

public:
	GameEntity(float x = 0.0f, float y = 0.0f);
	~GameEntity();
	Texture* GetmTex() { return mTex; }
	AnimatedTexture* GetmAtex() { return mAtex; }
	void Pos(Vector2 pos);
	Vector2 Pos(SPACE space = WORLD);
	void Rotation(float rotation);
	float Rotation(SPACE space = WORLD);
	void Active(bool active);
	bool Active();
	void Parent(GameEntity*);
	GameEntity* Parent();
	float GetPosX() { return mPos.x; }
	float GetPosY() { return mPos.y; }
	void SetPosX(float x) { mPos.x = x; }
	void SetPosY(float y) { mPos.y = y; }

	virtual void Update();
	virtual void Render();
};
#endif

