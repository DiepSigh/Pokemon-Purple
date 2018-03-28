#include "menu.h"

using namespace std;

Menu::Menu(){

}

Menu::Menu(float x, float y, Texture* tex) {
	mGraphics = Graphics::Instance();
	mAssetManager = AssetManager::Instance();

	mPos.x = x;
	mPos.y = y;
	mTex = tex;



}

void Menu::CheckState() {
	menuState = NEWGAME;
	switch (menuState) {
		case NEWGAME:
			break;
		case OPTIONS:
			break;
		case POKEDEX:
			break;
		case POKEMON:
			break;
		case ITEM:
			break;
		case PLAYER:
			break;
		case SAVE:
			break;
		case EXIT:
			break;
	}
}


Menu::~Menu() {}

void Menu::Update(){}

void Menu::Render(){
	GetmTex()->SetRenderRectX(GetPosX());
	GetmTex()->SetRenderRectY(GetPosY());

	//GetmGraphics()->DrawTexture(GetmTex()->GetSDLTex(), GetClipped() ? &GetmClipRect() : NULL, &GetmTex()->GetmRenderRect());
	mGraphics->DrawTexture(GetmTex()->GetSDLTex(), (GetClipped()) ? &GetmClipRect() : NULL, &GetmTex()->GetmRenderRect());

}
