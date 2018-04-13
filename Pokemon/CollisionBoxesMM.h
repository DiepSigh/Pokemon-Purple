#ifndef _COLLISIONBOXESMM_H
#define _COLLISIONBOXESMM_H

#include "gameEntity.h"
#include "camera.h"
#include "characters.h"
#include "AudioManager.h"

#include <iostream>


class CollisionBoxMM : public GameEntity {
private:

	Graphics* mGraphics;
	Texture *mBattle, *mDialog, *mCollisions, *mAudioSwitcher;
	Texture mCollisionBoxes[46];
	Texture mBattleBoxes[2];
	Texture mDialogBoxes[2];
	Texture mAudioSwitcherBox[2];
			
public:	
	static CollisionBoxMM* sInstance;
	static CollisionBoxMM* Instance();

	void DrawCollisions(Camera*);
	void DrawDialogBoxes(Camera*);
	void DrawBattleBoxes(Camera*);
	void DrawAudioSwitcherBoxes(Camera*);

	void CheckMoveRight(Characters*, Camera*, AudioManager*, CollisionBoxMM*);
	void CheckMoveLeft(Characters*, Camera*, AudioManager*, CollisionBoxMM*);
	void CheckMoveUp(Characters*, Camera*, AudioManager*, CollisionBoxMM*);
	void CheckMoveDown(Characters*, Camera*, AudioManager*, CollisionBoxMM*);
	
	float GetCollisonX(int num) { return mCollisionBoxes[num].GetPosX(); }
	float GetCollisonY(int num) { return mCollisionBoxes[num].GetPosY(); }
	float GetCollisonW(int num) { return mCollisionBoxes[num].GetPosWidth(); }
	float GetCollisonH(int num) { return mCollisionBoxes[num].GetPosHeight(); }

	float GetBattleEventX(int num) { return mBattleBoxes[num].GetPosX(); }
	float GetBattleEventY(int num) { return mBattleBoxes[num].GetPosY(); }
	float GetBattleEventW(int num) { return mBattleBoxes[num].GetPosWidth(); }
	float GetBattleEventH(int num) { return mBattleBoxes[num].GetPosHeight(); }

	float GetDialogEventX(int num) { return mDialogBoxes[num].GetPosX(); }
	float GetDialogEventY(int num) { return mDialogBoxes[num].GetPosY(); }
	float GetDialogEventW(int num) { return mDialogBoxes[num].GetPosWidth(); }
	float GetDialogEventH(int num) { return mDialogBoxes[num].GetPosHeight(); }

	float GetAudioSwitcherY(int num) { return mAudioSwitcherBox[num].GetPosY(); }


	CollisionBoxMM(float, float, Camera*);
	CollisionBoxMM();
	~CollisionBoxMM();
	void Render();

};

#endif // !_COLLISIONBOXESMM_H

