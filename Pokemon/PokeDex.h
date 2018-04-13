#include "menu.h"

class PokeDex : public Menu {
public:
	PokeDex();
	PokeDex(float, float, Texture*);
	~PokeDex();
	enum PokedexState { CONTENTS, DATA, CRY, AREA, QUIT };
	PokedexState GetDexState() { return PkDexState; }
	void SetDexState(PokedexState state) { PkDexState = state; }
	bool PKDexActive = false;
	void CheckDexState();

	PokeDex* PkDex;
	PokeDex* Seen;
	PokeDex* Caught;
	PokeDex* Contents;
	PokeDex* Data;
	PokeDex* Cry;
	PokeDex* Area;
	PokeDex* Quit;
	PokeDex* CursorP;


	void Update();
	void Render();

	PokeDex* contents;

private:
	PokedexState PkDexState;
	Graphics * mGraphics;
	AssetManager* mAssetManager;


};