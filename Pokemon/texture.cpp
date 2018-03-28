#include "texture.h"

Texture::Texture() {}

Texture::Texture(std::string filename, int x, int y, int w, int h) {
	mGraphics = Graphics::Instance();
	SDLTex = AssetManager::Instance()->GetTexture(filename);

	mClipped = true;

	mWidth = w;
	mHeight = h;

	mRenderRect.w = mWidth;
	mRenderRect.h = mHeight;

	mClipRect.x = x;
	mClipRect.y = y;
	mClipRect.w = mWidth;
	mClipRect.h = mHeight;
}

Texture::Texture() {};

Texture::Texture(std::string text, std::string fontPath, int size) {
	mGraphics = Graphics::Instance();
	SDLTex = AssetManager::Instance()->GetText(text, fontPath, size);

	mClipped = false;

	SDL_QueryTexture(SDLTex, NULL, NULL, &mWidth, &mHeight);

	mRenderRect.w = mWidth;
	mRenderRect.h = mHeight;
}

Texture::~Texture() {
	
	SDLTex = NULL;
	mGraphics = NULL;
}

void Texture::Render() {
	//Vector2 pos = Pos(WORLD);
	//SetRenderRectX(10);
	//SetRenderRectY(15);
	//mRenderRect.x =(int)pos.x;
	//mRenderRect.y =(int)pos.y;

	//mGraphics->DrawTexture(mTex, (mClipped)? &mClipRect : NULL, &mRenderRect);
	//GetmGraphics()->DrawTexture(GetSDLTex(), GetClipped() ? &GetmClipRect() : NULL, &GetmRenderRect());

}

void Texture::Update(){

}