#include "menuManager.h"

MenuManager* MenuManager::sInstance = nullptr;

MenuManager::MenuManager(){
	menu = new Menu(80, 100, new Texture("POKÈMON", "POKEMONGB.ttf", 30));
	menu1 = new Menu(60, 50, new Texture("POKÈMON", "POKEMONGB.ttf", 30));
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


