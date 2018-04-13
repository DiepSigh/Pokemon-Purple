#ifndef GAMEENTITY_H
#define GAMEENTITY_H

#include "mathHelper.h"
#include "animatedTexture.h"

class GameEntity {
protected:
	Texture* mTex;
	AnimatedTexture* mAtex;
	Vector2 mPos;

private:
	float  mRotation;
	bool mActive;
	GameEntity* mParent;

public:
	Texture* GetmTex() { return mTex; }

	void SetmTex(Texture* tex) {mTex = tex;}

	AnimatedTexture* GetmAtex() { return mAtex; }

	GameEntity(float x = 0.0f, float y = 0.0f);
	~GameEntity();	
	enum SPACE {LOCAL = 0, WORLD = 1};
	float GetPosX() { return mPos.x; }
	float GetPosY() { return mPos.y; }
	void SetPosX(float x) { mPos.x = x; }
	void SetPosY(float y) { mPos.y = y; }

	void Pos(Vector2 pos);
	Vector2 Pos(SPACE space = WORLD);
	void Rotation(float rotation);
	float Rotation(SPACE space = WORLD);
	void Active(bool active);
	bool Active();
	void Parent(GameEntity*);
	GameEntity* Parent();

	virtual void Update();
	virtual void Render();


};
#endif // !GAMEENTITY_H

