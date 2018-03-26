#include "animatedTexture.h"

AnimatedTexture::AnimatedTexture(std::string filename, int x, int y, int w, int h, int frameCount, float animationSpeed, ANIM_DIR animationDir) : Texture(filename, x, y, w, h) {
	mTimer = Timer::Instance();
	mStartX = x;
	mStartY = y;

	mFrameCount = frameCount = frameCount;
	mAnimationSpeed = animationSpeed;
	mTimerPerFrame = mAnimationSpeed / mFrameCount;
	mAnimationTimer = 0.0f;
	mAnimationDirection = animationDir;
	mAnimationDone = false;
	mWrapMode = LOOP;

}

AnimatedTexture::~AnimatedTexture(){}

void AnimatedTexture::WrapMode(WRAP_MODE mode) {
	mWrapMode = mode;
}

void AnimatedTexture::Update() {
	if (!mAnimationDone) {
		mAnimationTimer += mTimer->DeltaTime();

		if (mAnimationTimer >= mAnimationSpeed) {
			if (mWrapMode == LOOP) {
				mAnimationTimer - +mAnimationSpeed;
			}
		}
		else {
			mAnimationDone = true;
			mAnimationTimer = mAnimationSpeed - mTimerPerFrame;
		}
	}
	if (mAnimationDirection == HORIZONTAL) {
		mClipRect.x = mStartX + (int)(mAnimationTimer / mTimerPerFrame) * mWidth;
	}
	else {
		mClipRect.y = mStartY + (int)(mAnimationTimer / mTimerPerFrame) * mHeight;
	}
}