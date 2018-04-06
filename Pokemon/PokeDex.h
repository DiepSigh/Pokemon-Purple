#include "menu.h"

class PokeDex : public Menu {
public:
	PokeDex();
	~PokeDex();
	enum PokedexState { CONTENTS, DATA, CRY, AREA, QUIT };
	PokedexState GetDexState() { return PkDexState; }
	void SetDexState(PokedexState state) { PkDexState = state; }
	bool PKDexActive = false;
	void CheckDexState();

	void Update();
	void Render();

	PokeDex* contents;

private:
	PokedexState PkDexState;


};