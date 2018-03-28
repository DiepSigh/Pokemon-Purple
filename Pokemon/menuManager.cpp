#include "menuManager.h"

MenuManager* MenuManager::sInstance = nullptr;

MenuManager::MenuManager(){
	menu = new Menu(80, 100, new Texture("POKéMON", "PKMNSOLID.ttf", 60));
	menu->SetPosX(100);
	menu->SetPosY(500);
	menu1 = new Menu(60, 50, new Texture("POKéDEX", "PKMNSOLID.ttf", 60));
	menu1->SetPosX(500);
	menu1->SetPosY(400);
	menu2 = new Menu(0, 0, new Texture("Hello Andre", "PKMNSOLID.ttf", 100));
	menu2->SetPosX(250);
	menu2->SetPosY(250);
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


