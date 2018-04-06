#ifndef CHARACTERS_H
#define CHARACTERS_H

#include "gameEntity.h"
#include "animatedTexture.h"
#include "texture.h"
#include "DisplayText.h"
#include <vector>

class Characters : public GameEntity{
public:
	Characters();
	void Player();
	void Render();
	void Update();
	inline float GetSpeed() { return SPEED; }
	void SetSpeed(float s) { SPEED = s; }
	void DisplayText();

private:
	Graphics* mGraphics;
	Texture* mPlayer;
	float SPEED;
	TextScreen* mTextScreen;

};

#endif // !CHARACTERS_H

