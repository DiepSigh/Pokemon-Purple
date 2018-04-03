#include "menu.h"

using namespace std;

Menu::Menu(){
	menu = new Menu(80, 100, new Texture("pokédéx", "PKMNSOLID.ttf", 40));
	menu->SetPosX(560);
	menu->SetPosY(30);
	menu1 = new Menu(60, 50, new Texture("pokémon", "PKMNSOLID.ttf", 40));
	menu1->SetPosX(560);
	menu1->SetPosY(80);
	menu2 = new Menu(0, 0, new Texture("itém", "PKMNSOLID.ttf", 40));
	menu2->SetPosX(560);
	menu2->SetPosY(140);
	menu3 = new Menu(0, 0, new Texture("playér", "PKMNSOLID.ttf", 40));
	menu3->SetPosX(560);
	menu3->SetPosY(190);
	menu4 = new Menu(0, 0, new Texture("savé", "PKMNSOLID.ttf", 40));
	menu4->SetPosX(560);
	menu4->SetPosY(240);
	menu5 = new Menu(0, 0, new Texture("options", "PKMNSOLID.ttf", 40));
	menu5->SetPosX(560);
	menu5->SetPosY(290);
	menu6 = new Menu(0, 0, new Texture("éxit", "PKMNSOLID.ttf", 40));
	menu6->SetPosX(560);
	menu6->SetPosY(340);
	Cursor = new Menu(0, 0, new Texture("arrowPKMN.png", 0, 0, 40, 40));
	Cursor->SetPosX(520);
	Cursor->SetPosY(30);
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

	mGraphics->DrawTexture(GetmTex()->GetSDLTex(), (GetClipped()) ? &GetmClipRect() : NULL, &GetmTex()->GetmRenderRect());

}
