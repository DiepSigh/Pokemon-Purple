#include "menu.h"

Menu::Menu() {
}

Menu::~Menu() {}

void Menu::CheckState() {
	CheckState = NEWGAME;
	switch (CheckState) {
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

void Menu::Update(){}

void Menu::Render(){}
