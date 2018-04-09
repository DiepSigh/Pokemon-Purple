#include "DisplayText.h"

using namespace std;

TextScreen::TextScreen(){
	mGraphics = Graphics::Instance();
	mAssetManager = AssetManager::Instance();
}

TextScreen::TextScreen(int x, int y) {
	mGraphics = Graphics::Instance();
	mAssetManager = AssetManager::Instance();
	mDialouge = Dialouge::Instance();
	mPos.x = x;
	mPos.y = y;
	mTex = new Texture(mDialouge->GetNPCtext(70, 0), "PKMNSOLID.ttf", 25);
}

TextScreen::~TextScreen()
{
}

void TextScreen::Update()
{
}

void TextScreen::Render(int r, int c)
{
	Speech(r,c);//Calls Function to set X/Y pos and mTex
	GetmTex()->SetRenderRectX(GetPosX());
	GetmTex()->SetRenderRectY(GetPosY());

	mGraphics->DrawTexture(GetmTex()->GetSDLTex(), (GetClipped()) ? &GetmClipRect() : NULL, &GetmTex()->GetmRenderRect());

}

void TextScreen::Speech(int r, int c) {
	mGraphics = Graphics::Instance();
	mAssetManager = AssetManager::Instance();
	mDialouge = Dialouge::Instance();
	SetPosX(100);
	SetPosY(500);
	mTex = new Texture(mDialouge->GetNPCtext(r,c), "PKMNSOLID.ttf", 25);
}
