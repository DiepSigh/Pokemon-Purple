#ifndef MENUMANAGER_H
#define MENUMANAGER_H

#include "menu.h"
#include "PokeDex.h"

<<<<<<< HEAD
class MenuManager : public Menu{
=======
class MenuManager : public Menu {
>>>>>>> master
public:
	static void Release();
	Graphics* mGraphics;
	static MenuManager* sInstance;
	static MenuManager* Instance();
<<<<<<< HEAD
=======
	void StartMenu();

>>>>>>> master

	void StartMenu();

	Menu* mMenu;
	void MenuState();

	void Update();
	void Render();
<<<<<<< HEAD
=======

>>>>>>> master
private:
	MenuManager();
	MenuManager(int, int, Texture*);
	~MenuManager();
};
#endif // !MENUMANAGER_H