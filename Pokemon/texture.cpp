#include "texture.h"
#include "assetManager.h"

Texture::Texture(std::string filename, int x, int y, int w, int h) {
	mGraphics = Graphics::Instance();
	mTex = AssetManager::Instance()->getTexture(filename);

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

//Texture::Texture(std::string text, std::string fontPath, int size) {
//	mGraphics = Graphics::Instance();
//	mTex = AssetManager::Instance()->getTexture(text, fontPath, size);
//
//	mClipped = false;
//	SDL_QueryTexture(mTex, NULL, NULL, &mWidth, &mHeight);
//
//	mRenderRect.w = mWidth;
//	mRenderRect.h = mHeight;
//
//}

Texture::~Texture() {
	mTex = NULL;
	mGraphics = NULL;
}

void Texture::Render() {

//	mGraphics->DrawTexture(mTex, (mClipped) ? &mClipRect : NULL, &mRenderRect);
}

void Texture::Update() {

}