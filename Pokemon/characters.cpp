#include "characters.h"

Characters::Characters(){
	mGraphics = Graphics::Instance();
	//mPlayer = new AnimatedTexture("PokemonSpriteSheet.png", 0, 0, 32, 32, 3, 1.0f, AnimatedTexture::HORIZONTAL);
	mPlayer = new Texture("PlayerTest.png", 0, 0, 32, 32);
	mTex = mPlayer;
}

void Characters::Player() {

}

void Characters::Render() {
	GetmTex()->SetRenderRectX(GetPosX());
	GetmTex()->SetRenderRectY(GetPosY());

	//GetmGraphics()->DrawTexture(GetmTex()->GetSDLTex(), GetClipped() ? &GetmClipRect() : NULL, &GetmTex()->GetmRenderRect());
	mGraphics->DrawTexture(GetmTex()->GetSDLTex(), (GetmTex()->GetClipped()) ? &GetmTex()->GetmClipRect() : NULL, &GetmTex()->GetmRenderRect());

}

void Characters::Update() {
}

void Characters::NPC(){

}
