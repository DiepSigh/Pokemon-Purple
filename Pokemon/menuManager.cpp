#include "menuManager.h"
using namespace std;

MenuManager* MenuManager::sInstance = nullptr;

MenuManager::MenuManager(){
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
	menu6 = new Menu(0, 0, new Texture("exit", "PKMNSOLID.ttf", 40));
	menu6->SetPosX(560);
	menu6->SetPosY(340);
	Cursor = new Menu(0, 0, new Texture("arrowPKMN.png", 0, 0, 40, 40));
	Cursor->SetPosX(520);
	Cursor->SetPosY(30);

	StrtMnuisActive = true;

	mGraphics = Graphics::Instance();
}

MenuManager::MenuManager(int, int, Texture*){}

MenuManager*MenuManager::Instance(){
	if (sInstance == nullptr) {
		sInstance = new MenuManager();
	}

	return sInstance;
}

void MenuManager::Release() {
	delete sInstance;
	sInstance = nullptr;
}

MenuManager::~MenuManager(){
	MenuManager::Release();
	Graphics::Release();
	mGraphics = NULL;
}

void MenuManager::Update() {

}

void MenuManager::Render() {
	if (StrtMnuisActive) {
		cout << ((int) Cursor->GetPosY());
		StartMenu();
		switch ((int)Cursor->GetPosY()) {
		case 30:
			//Load POKEDEX
			break;
		case 80:
			//Load POKEMON
			break;
		case 140:
			// Load ITEMS
			break;
		case 190:
			//Load PLAYER
			break;
		case 240:
			//Load SAVE
			break;
		case 290:
			//Load OPTIONS
			break;
		case 340:
			//Load EXIT
			StrtMnuisActive = false;
			break;
		}
	}
}

void MenuManager::StartMenu() {
	menu->Render();
	menu1->Render();
	menu2->Render();
	menu3->Render();
	menu4->Render();
	menu5->Render();
	menu6->Render();
	//Cursor->SetPosY(Cursor->GetPosY() + 0.1);
	Cursor->Render();

}

void MenuManager::CursorMoveDown(){
	Cursor->SetPosY(Cursor->GetPosY() + 50);

	if (Cursor->GetPosY() > 340) {
		Cursor->SetPosY(30);
	}
}

void MenuManager::CursorMoveUp() {
	Cursor->SetPosY(Cursor->GetPosY() - 50);

	if (Cursor->GetPosY() < 30) {
		Cursor->SetPosY(340);
	}
}

