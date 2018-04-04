#include "menuManager.h"

using namespace std;

MenuManager* MenuManager::sInstance = nullptr;

MenuManager::MenuManager(){
	mMenu = new Menu();
	//Start Menu Activation
	StrtMnuisActive = true;
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


void MenuManager::Update() {

}

void MenuManager::Render() {
	if (StrtMnuisActive) {
		StartMenu();
		switch ((int)Cursor->GetPosY()) {
		case 30:
			//Activate PkDexActive
			//Activate 	PkDexState = CONTENTS;
			//Load POKEDEX
			break;
		case 80:
			//Load POKEMON
			break;
		case 130:
			// Load ITEMS
			break;
		case 180:
			//Load PLAYER
			break;
		case 230:
			//Load SAVE
			break;
		case 380:
			//Load OPTIONS
			break;
		case 405:
			//Load EXIT
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
	Cursor->Render();
}



void MenuManager::MenuState() {

}