#ifndef MENUMANAGER_H
#define MENUMANAGER_H

#include "menu.h"
#include "PokeDex.h"

class MenuManager {
public:
	static void Release();
	Graphics* mGraphics;
	static MenuManager* sInstance;
	static MenuManager* Instance();
<<<<<<< HEAD
	void StartMenu();


	void CursorMoveDown();
	void CursorMoveUp();

	void MenuState();

	void Update();
	void Render();

=======
	Menu* menu;
	Menu* menu1;
	Menu* menu2;
	Menu* menu3;
>>>>>>> parent of 5fab02f... Menu Moving/RenderFull
private:
	float xu;
	MenuManager();
	~MenuManager();
};
#endif // !MENUMANAGER_H

