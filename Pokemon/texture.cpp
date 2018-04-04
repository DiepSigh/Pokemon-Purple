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
	//mRenderRect.x = (int)(pos.x - mWidth * 0.5f);
	//mRenderRect.y = (int)(pos.x - mHeight * 0.5f);
	//
	//mGraphics->DrawTexture(SDLTex, (mClipped)? &mClipRect : NULL, &mRenderRect);
}

void Texture::Update(){

}