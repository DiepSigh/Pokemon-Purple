#include "texture.h"

Texture::Texture(std::string filename, int x, int y, int w, int h) {
	mGraphics = Graphics::Instance();
	mTex = AssetManager::Instance()->GetTexture(filename);

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

Texture::~Texture() {
	
	mTex = NULL;
	mGraphics = NULL;
}

void Texture::Render() {
	Vector2 pos = Pos(WORLD);
	mRenderRect.x = (int)(pos.x - mWidth * 0.5f);
	mRenderRect.y = (int)(pos.x - mHeight * 0.5f);

	mGraphics->DrawTexture(mTex, (mClipped)? &mClipRect : NULL, &mRenderRect);
}

void Texture::Update(){

}