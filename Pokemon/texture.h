#ifndef TEXTURE_H
#define TEXTURE_H

#include "graphics.h"

class Texture {
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
	//Texture(std::string, std::string, int);
	~Texture();
	virtual void Render();
	virtual void Update();

	SDL_Texture *getmTex() { return mTex; }
	Graphics *getmGraphics() { return mGraphics; }
	int getWidth() { return mWidth; }
	int getHeight() { return mHeight; }
	bool getClipped() { return mClipped; }
	SDL_Rect getmRenderRect() { return mRenderRect; }
	SDL_Rect getmClipRect() { return mClipRect; }
	void setRenderRectX(int x) { mRenderRect.x = x; }
	void setRenderRectY(int y) { mRenderRect.y = y; }

};

#endif