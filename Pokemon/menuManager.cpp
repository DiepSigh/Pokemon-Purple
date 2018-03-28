#include "menuManager.h"

MenuManager* MenuManager::sInstance = nullptr;

MenuManager::MenuManager(){
	menu = new Menu(80, 100, new Texture("pokédéx", "PKMNSOLID.ttf", 50));
	menu->SetPosX(500);
	menu->SetPosY(70);
	menu1 = new Menu(60, 50, new Texture("pokémon", "PKMNSOLID.ttf", 50));
	menu1->SetPosX(500);
	menu1->SetPosY(125);
	menu2 = new Menu(0, 0, new Texture("itém", "PKMNSOLID.ttf", 50));
	menu2->SetPosX(500);
	menu2->SetPosY(160);
	menu3 = new Menu(0, 0, new Texture("playér", "PKMNSOLID.ttf", 50));
	menu3->SetPosX(500);
	menu3->SetPosY(190);
	mGraphics = Graphics::Instance();
}

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


