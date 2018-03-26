#ifndef TEXTURE_H
#define TEXTURE_H

#include "graphics.h"
#include "assetManager.h"
#include "gameEntity.h"

class Texture : public GameEntity {
protected:
	SDL_Texture *mTex;
	Graphics *mGraphics;

	int mWidth;
	int mHeight;

	bool mClipped;
	SDL_Rect mRenderRect;
	SDL_Rect mClipRect;

public:
	Texture(std::string, int, int, int, int);
	~Texture();
	Texture();
	virtual void Render();
	virtual void Update();

	Texture(std::string text, std::string fontPath, int size);

	SDL_Texture *GetmTex() { return mTex; }
	Graphics *GetmGraphics() { return mGraphics; }
	int GetWidth() { return mWidth; }
	int GetHeight() { return mHeight; }
	bool GetClipped() { return mClipped; }
	SDL_Rect GetmRenderRect() { return mRenderRect; }
	SDL_Rect GetmClipRect() { return mClipRect; }
	void SetRenderRectX(int x) { mRenderRect.x = x; }
	void SetRenderRectY(int y) { mRenderRect.y = y; }
};
#endif // !TEXTURE_H

