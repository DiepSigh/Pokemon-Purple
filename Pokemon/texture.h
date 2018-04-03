#ifndef TEXTURE_H
#define TEXTURE_H

#include "assetManager.h"

class Texture{
protected:
	Graphics *mGraphics;
	SDL_Texture *SDLTex;

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

	//SDL_Texture *GetmTex() { return mTex; }
	SDL_Texture *GetSDLTex() { return SDLTex; }
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