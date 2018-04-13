#ifndef CHARACTERS_H
#define CHARACTERS_H

#include "gameEntity.h"
#include "animatedTexture.h"
#include "texture.h"
#include "DisplayText.h"
#include <vector>

class Characters : public GameEntity {
public:
	Characters();
	void Player();
	void Render();
	void Update();

	void NPC();
	
	inline float GetSpeed() { return SPEED; }
	void SetSpeed(float s) { SPEED = s; }
	void DisplayText();

	float GetWPosX() { return wPosX; }
	void SetWPosX(float pos) { wPosX = pos; }

	float GetWPosY() { return wPosY; }
	void SetWPosY(float pos) { wPosY = pos; }

	float GetPlSize() { return PlayerSize; }
	
private:
	Graphics* mGraphics;
	Texture* mPlayer;
	float SPEED;
	TextScreen* mTextScreen;

	float wPosX;
	float wPosY;
	float PlayerSize = 32;

};

#endif // !CHARACTERS_H

