#include "menu.h"
#include "PokeBase.h"

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

	PokeDex* PkmnName[151];

	PokeBase* mPokeBase;

	void CursorPMoveDown();
	void CheckDraw();

	bool DexCheck = false;

	void Update();
	void Render();

	int GetValueR() { return r; }
	int GetValueT() { return t; }
	void SetValueR(int R) { r = R; }
	void SetValueT(int T) { t = T; }

private:
	PokedexState PkDexState;
	Graphics * mGraphics;
	AssetManager* mAssetManager;
	float Counter;
	int j;

	int r = 0;
	int t = 7;
};