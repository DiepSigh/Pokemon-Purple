#include "menu.h"

Menu::Menu() {}



void Menu::CheckState() {
	menuState = NEWGAME;
	switch (menuState) {
		case NEWGAME:
			break;
		case OPTIONS:
			break;
		case POKEDEX:
			break;
		case POKEMON:
			break;
		case ITEM:
			break;
		case PLAYER:
			break;
		case SAVE:
			break;
		case EXIT:
			break;
	}
}


Menu::~Menu() {}

void Menu::Update(){}

void Menu::Render(){}
