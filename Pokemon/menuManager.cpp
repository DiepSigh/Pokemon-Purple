#include "menuManager.h"
using namespace std;

MenuManager* MenuManager::sInstance = nullptr;


MenuManager::MenuManager() {
	mMenu = new Menu();
	mOptions = new Options();
	mPlayerMenu = new PlayerMenu();
	mPokeDex = new PokeDex();
	//Start Menu Activation
	StrtMnuisActive = true;
	OptsMnuisActive = false;

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

	if (OptsMnuisActive) {
		LoadOptions();
	}
	if (PlayerMnuisActive) {
		LoadPlayerM();
	}
	if (PokedexisActive) {
		LoadPokeDex();
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

void MenuManager::MenuState() {
	switch ((int)Cursor->GetPosY()) {
	case 30:
		if ((int)Cursor->GetPosY() == menu->GetPosY()) {
			printf("Entering Pokedex");
			PokedexisActive = true;
		}
		break;
	case 80:
		//Load POKEMON
		if ((int)Cursor->GetPosY() == menu1->GetPosY()) {
			//Use Pokemon Render function
			//Pokemon->Render();
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
			PlayerMnuisActive = true;
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
			OptsMnuisActive = true;
			StrtMnuisActive = false;
		}
		break;
	case 330:
		StrtMnuisActive = false;
		//Load EXIT
		break;
	}
}

void MenuManager::LoadOptions() {
	mOptions->textSpeed->Render();
	mOptions->btlAnimation->Render();
	mOptions->btlStyle->Render();
	mOptions->Cancel->Render();
	mOptions->Fast->Render();
	mOptions->Medium->Render();
	mOptions->Slow->Render();
	mOptions->On->Render();
	mOptions->Off->Render();
	mOptions->Shift->Render();
	mOptions->Set->Render();
	mOptions->CursorO->Render();
}

void MenuManager::LoadPlayerM() {
	mPlayerMenu->MenuP->Render();
	mPlayerMenu->Name->Render();
	mPlayerMenu->Money->Render();
	mPlayerMenu->Time->Render();
	mPlayerMenu->PlayerName->Render();
	mPlayerMenu->PlayerMoney->Render();
	mPlayerMenu->GameTime->Render();
}

void MenuManager::LoadPokeDex() {
	mPokeDex->PkDex->Render();
	mPokeDex->Contents->Render();
	mPokeDex->Seen->Render();
	mPokeDex->Caught->Render();
	mPokeDex->Data->Render();
	mPokeDex->Cry->Render();
	mPokeDex->Area->Render();
	mPokeDex->Quit->Render();

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

