#include "menu.h"

class MenuManager {
public:
	static MenuManager* Instance;

private:
	static MenuManager* Instance();


	MenuManager();
	~MenuManager();

};