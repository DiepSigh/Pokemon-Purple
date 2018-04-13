#include "menu.h"

using namespace std;

Menu::Menu(){
	menu = new Menu(80, 100, new Texture("POKEDEX", "PKMNSOLID.ttf", 30));
	menu->SetPosX(560);
	menu->SetPosY(30);
	menu1 = new Menu(60, 50, new Texture("POKEMON", "PKMNSOLID.ttf", 30));
	menu1->SetPosX(560);
	menu1->SetPosY(80);
	menu2 = new Menu(0, 0, new Texture("ITEM", "PKMNSOLID.ttf", 30));
	menu2->SetPosX(560);
	menu2->SetPosY(130);
	menu3 = new Menu(0, 0, new Texture("PLAYER", "PKMNSOLID.ttf", 30));
	menu3->SetPosX(560);
	menu3->SetPosY(180);
	menu4 = new Menu(0, 0, new Texture("SAVE", "PKMNSOLID.ttf", 30));
	menu4->SetPosX(560);
	menu4->SetPosY(230);
	menu5 = new Menu(0, 0, new Texture("OPTIONS", "PKMNSOLID.ttf", 30));
	menu5->SetPosX(560);
	menu5->SetPosY(280);
	menu6 = new Menu(0, 0, new Texture("EXIT", "PKMNSOLID.ttf", 30));
	menu6->SetPosX(560);
	menu6->SetPosY(330);
	Cursor = new Menu(0, 0, new Texture("arrowPKMN.png", 0, 0, 40, 40));
	Cursor->SetPosX(520);
	Cursor->SetPosY(30);
	Pokemon = new Menu(0, 0, new Texture("Choose a POKeMON.", "PKMNSOLID.ttf", 30));
	Pokemon->SetPosX(250);
	Pokemon->SetPosY(250);

}

Menu::Menu(float x, float y, Texture* tex) {
	mGraphics = Graphics::Instance();
	mAssetManager = AssetManager::Instance();

	mPos.x = x;
	mPos.y = y;
	mTex = tex;
}

void Menu::CheckState() {
}


Menu::~Menu() {
}

void Menu::Update() {

}

void Menu::Render() {
	GetmTex()->SetRenderRectX(GetPosX());
	GetmTex()->SetRenderRectY(GetPosY());

	mGraphics->DrawTexture(GetmTex()->GetSDLTex(), (GetmTex()->GetClipped()) ? &GetmTex()->GetmClipRect() : NULL, &GetmTex()->GetmRenderRect());
}

void Menu::CursorMoveDown() {
	Cursor->SetPosY(Cursor->GetPosY() + 50);

	if (Cursor->GetPosY() > 330) {
		Cursor->SetPosY(30);
	}
}

void Menu::CursorMoveUp() {
	Cursor->SetPosY(Cursor->GetPosY() - 50);

	if (Cursor->GetPosY() < 30) {
		Cursor->SetPosY(330);
	}
}

void Menu::DrawPokemon() {
	Pokemon->Render();
}