#ifndef MENU_H
#define MENU_H

#include "SDL.h"
#include "timer.h"
#include <string>
#include <vector>
#include "math.h"
#include "graphics.h"
#include  "texture.h"
#include "assetManager.h"

class Menu : public Texture {
public:
	Menu();
	~Menu();
	enum MenuStates { NEWGAME, OPTIONS, POKEDEX, POKEMON, ITEM, PLAYER, SAVE, EXIT };
	MenuStates GetMenuState() { return menuState; }
	void SetMenuState(MenuStates state) { menuState = state; }
	void CheckState();
	bool isActive = false;
	void Update();
	void Render();
	Texture* GetmTex() { return mTexi; }
	

private:
	MenuStates menuState;
	Vector2 mPos;
	Graphics* mGraphics;
	AssetManager* mAssetManager;

protected:
	Texture* mTexi;
	SDL_Texture* mSDLTex;
};

#endif // !MENU_H
