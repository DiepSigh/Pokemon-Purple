#include "menuManager.h"

MenuManager* MenuManager::sInstance = nullptr;

MenuManager::MenuManager(){
<<<<<<< HEAD
	Menu::Menu();
	PokeDex::PokeDex();
	//Start Menu Activation
	StrtMnuisActive = true;

=======
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
>>>>>>> parent of 5fab02f... Menu Moving/RenderFull
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

<<<<<<< HEAD
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
=======
>>>>>>> parent of 5fab02f... Menu Moving/RenderFull

void MenuManager::MenuState() {

}