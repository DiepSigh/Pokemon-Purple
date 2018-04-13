#ifndef MENU_H
#define MENU_H

#include "SDL.h"
#include <string>
#include <vector>
#include "gameEntity.h"
#include <iostream>


class Menu : public GameEntity {
protected:
	

public:
	Menu();
	Menu(float, float, Texture*);
	~Menu();
	enum MenuStates { NEWGAME, OPTIONS, POKEDEX, POKEMON, ITEM, PLAYER, SAVE, EXIT };
	MenuStates GetMenuState() { return menuState; }
	void SetMenuState(MenuStates state) { menuState = state; }
	void CheckState();
	bool StrtMnuisActive = true;
	bool OptsMnuisActive = false;
	bool PlayerMnuisActive = false;
	bool PokedexisActive = false;
	void Update();
	void Render();



	Menu* menu;
	Menu* menu1;
	Menu* menu2;
	Menu* menu3;
	Menu* menu4;
	Menu* menu5;
	Menu* menu6;
	Menu* Cursor;
	Menu* Pokemon;

	void DrawPokemon();

	void CursorMoveDown();
	void CursorMoveUp();

private:
	MenuStates menuState;
	Vector2 mPos;
	Graphics* mGraphics;
	AssetManager* mAssetManager;
protected:
};
#endif // !MENU_H