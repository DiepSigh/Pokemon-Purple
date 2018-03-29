#ifndef MENUMANAGER_H
#define MENUMANAGER_H

#include "menu.h"

class MenuManager : public Menu {
public:
	static void Release();
	Graphics* mGraphics;
	static MenuManager* sInstance;
	static MenuManager* Instance();
	void StartMenu();
	Menu* menu;
	Menu* menu1;
	Menu* menu2;
	Menu* menu3;
	Menu* menu4;
	Menu* menu5;
	Menu* menu6;
	Menu* Cursor;

	void CursorMoveDown();
	void CursorMoveUp();

	void Update();
	void Render();

private:
	MenuManager();
	MenuManager(int, int, Texture*);
	~MenuManager();
};
#endif // !MENUMANAGER_H

