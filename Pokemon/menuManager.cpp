#include "menuManager.h"
using namespace std;

MenuManager* MenuManager::sInstance = nullptr;

MenuManager::MenuManager(){
	Menu::Menu();
	PokeDex::PokeDex();
	//Start Menu Activation
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
			//Activate PkDexActive
			//Activate 	PkDexState = CONTENTS;
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
	Cursor->SetPosY(Cursor->GetPosY() + 0.1);
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

void MenuManager::MenuState() {

}