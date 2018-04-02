#ifndef ANIMATEDTEXTURE_H
#define ANIMATEDTEXTURE_H

#include "timer.h"
#include "texture.h"

class AnimatedTexture : public Texture {
public:
	enum WRAP_MODE {ONCE = 0, LOOP = 1 };
	enum ANIM_DIR {HORIZONTAL = 0, VERTICAL = 1};

private:
	Timer* mTimer;
	int mStartX;
	int mStartY;
	float mAnimationTimer;
	float mAnimationSpeed;
	float mTimerPerFrame;
	int mFrameCount;
	WRAP_MODE mWrapMode;
	ANIM_DIR mAnimationDirection;
	bool mAnimationDone;

public:
	AnimatedTexture();
	AnimatedTexture(std::string, int, int, int, int, int, float, ANIM_DIR);
	~AnimatedTexture();
	void WrapMode(WRAP_MODE);
	void Update();
};
#endif // !ANIMATEDTEXTURE_H

