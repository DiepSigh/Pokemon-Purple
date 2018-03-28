#ifndef MENUMANAGER_H
#define MENUMANAGER_H

#include "menu.h"

class MenuManager {
public:
	static void Release();
	Graphics* mGraphics;
	static MenuManager* sInstance;
	static MenuManager* Instance();
	Menu* menu;
	Menu* menu1;
	Menu* menu2;
	Menu* menu3;
private:
	float xu;
	MenuManager();
	~MenuManager();
};
#endif // !MENUMANAGER_H

