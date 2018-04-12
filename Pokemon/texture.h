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
	Texture();
	Texture(std::string, int, int, int, int);
	Texture(float, float, float, float);
	~Texture();

	virtual void Render();
	virtual void Update();

	Texture(std::string text, std::string fontPath, int size);

	SDL_Texture *GetSDLTex() { return SDLTex; }
	Graphics *GetmGraphics() { return mGraphics; }
	int GetWidth() { return mWidth; }
	int GetHeight() { return mHeight; }
	bool GetClipped() { return mClipped; }
	SDL_Rect GetmRenderRect() { return mRenderRect; }
	SDL_Rect GetmClipRect() { return mClipRect; }

	void SetRenderRectX(int x) { mRenderRect.x = x; }
	void SetRenderRectY(int y) { mRenderRect.y = y; }
	void SetRenderRectW(int w) { mRenderRect.w = w; }
	void SetRenderRectH(int h) { mRenderRect.h = h; }

	float GetPosX() { return PosX; } // by Canados
	float GetPosY() { return PosY; } // by Canados
	float GetPosWidth() { return Width; } // by Canados
	float GetPosHeight() { return Height; } // by Canados

	void SetPosX(float posX) { PosX = posX; }
	void SetPosY(float posY) { PosY = posY; }

private:
	float PosX;	// by Canados
	float PosY; // by Canados
	float Width; // by Canados
	float Height; // by Canados
};
#endif // !TEXTURE_H

