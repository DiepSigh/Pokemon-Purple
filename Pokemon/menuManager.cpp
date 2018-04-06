#include "menuManager.h"

using namespace std;

MenuManager* MenuManager::sInstance = nullptr;

MenuManager::MenuManager() {
	mMenu = new Menu();
	//Start Menu Activation
	StrtMnuisActive = false;
	mGraphics = Graphics::Instance();
}

MenuManager*MenuManager::Instance() {
	if (sInstance == nullptr) {
		sInstance = new MenuManager();
	}

	return sInstance;
}

void MenuManager::Release() {
	delete sInstance;
	sInstance = nullptr;
}

MenuManager::~MenuManager() {
	MenuManager::Release();
	Graphics::Release();
	mGraphics = NULL;
}


void MenuManager::Update() {

}

void MenuManager::Render() {
	if (StrtMnuisActive) {
		//cout << ((int) Cursor->GetPosY());

		StartMenu();
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
	switch ((int)Cursor->GetPosY()) {
	case 30:
		if ((int)Cursor->GetPosY() == menu->GetPosY()) {
			printf("Entering Pokedex");
		}
		break;
	case 80:
		//Load POKEMON
		if ((int)Cursor->GetPosY() == menu1->GetPosY()) {
			//Use Pokemon Render function
			Pokemon->Render();
			printf("Entering Pokemon");
		}
		break;
	case 130:
		if ((int)Cursor->GetPosY() == menu2->GetPosY()) {
			printf("Entering Items");
		}
		// Load ITEMS
		break;
	case 180:
		if ((int)Cursor->GetPosY() == menu3->GetPosY()) {
			printf("Entering Player");
		}
		//Load PLAYER
		break;
	case 230:
		if ((int)Cursor->GetPosY() == menu4->GetPosY()) {
			printf("Entering Save");
		}
		//Load SAVE
		break;
	case 280:
		if ((int)Cursor->GetPosY() == menu5->GetPosY()) {
			printf("Entering Options");
		}
		//Load OPTIONS
		break;
	case 330:
		StrtMnuisActive = false;
		//Load EXIT
		break;
	}
}