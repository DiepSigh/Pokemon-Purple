#ifndef CHARACTERS_H
#define CHARACTERS_H

#include "gameEntity.h"
#include "animatedTexture.h"
#include "texture.h"

class Characters : public GameEntity{
public:
	Characters();
	void Player();
	void Render();
	void Update();
	void NPC();
	inline float GetSpeed() { return SPEED; }
	void SetSpeed(float s) { SPEED = s; }

private:
	Graphics* mGraphics;
	Texture* mPlayer;
	float SPEED;

};

#endif // !CHARACTERS_H

