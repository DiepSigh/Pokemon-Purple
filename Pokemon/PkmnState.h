#include "menu.h"

class PkmnState : public Menu {
public:
	PkmnState();
	~PkmnState();

	void Render();
	void Update();
	
	void PokemonState();

private:
	Graphics* mGraphics;
};