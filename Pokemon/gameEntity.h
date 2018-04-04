#ifndef GAMEENTITY_H
#define GAMEENTITY_H

#include "mathHelper.h"
#include "animatedTexture.h"

class GameEntity : public Texture {
protected:
	Texture* mTex;
	AnimatedTexture* mAtex;
<<<<<<< HEAD

public:
	enum SPACE {LOCAL = 0, WORLD = 1};
=======
	Vector2 mPos;
>>>>>>> master

private:
	float  mRotation;
	bool mActive;
	GameEntity* mParent;

public:
	Texture* GetmTex() { return mTex; }
	void SetmTex(Texture* tex) {mTex = tex;}
	GameEntity(float x = 0.0f, float y = 0.0f);
<<<<<<< HEAD
	~GameEntity();

=======
	~GameEntity();	
	enum SPACE {LOCAL = 0, WORLD = 1};
>>>>>>> master
	float GetPosX() { return mPos.x; }
	float GetPosY() { return mPos.y; }
	void SetPosX(float x) { mPos.x = x; }
	void SetPosY(float y) { mPos.y = y; }
<<<<<<< HEAD
	AnimatedTexture* GetmAtex() { return mAtex; }

=======

	AnimatedTexture* GetmAtex() { return mAtex; }
>>>>>>> master
	void Pos(Vector2 pos);
	
	Vector2 Pos(SPACE space = WORLD);
	void Rotation(float rotation);
	float Rotation(SPACE space = WORLD);
	void Active(bool active);
	bool Active();
	void Parent(GameEntity*);
	GameEntity* Parent();
<<<<<<< HEAD
	
=======


>>>>>>> master
	virtual void Update();
	virtual void Render();


};
#endif // !GAMEENTITY_H
<<<<<<< HEAD
=======

>>>>>>> master
