#ifndef MENUMANAGER_H
#define MENUMANAGER_H

#include "menu.h"
#include "PokeDex.h"

class MenuManager : public Menu {
public:
	static void Release();
	Graphics* mGraphics;
	static MenuManager* sInstance;
	static MenuManager* Instance();
	void StartMenu();


	void CursorMoveDown();
	void CursorMoveUp();

	void MenuState();

	void Update();
	void Render();

private:
	MenuManager();
	MenuManager(int, int, Texture*);
	~MenuManager();
};
#endif // !MENUMANAGER_H

