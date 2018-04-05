#ifndef MENUMANAGER_H
#define MENUMANAGER_H

#include "menu.h"
#include "PokeDex.h"
#include "PkmnState.h"
#include "Options.h"

class MenuManager : public Menu{
public:
	static void Release();
	Graphics* mGraphics;
	static MenuManager* sInstance;
	static MenuManager* Instance();

	void StartMenu();

	Menu* mMenu;
	Options* mOptions;

	void MenuState();

	void Update();
	void Render();

	void LoadOptions();
private:
	MenuManager();
	~MenuManager();
};
#endif // !MENUMANAGER_H
