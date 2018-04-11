#include "menu.h"
#include "PokeBase.h"

class PokeDex : public Menu {
public:
	PokeDex();
	PokeDex(float, float, Texture*);
	~PokeDex();

	static PokeDex* sInstance;
	static PokeDex* Instance();

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
	PokeDex* SeenCounter;

	PokeDex* PkmnName[151];

	PokeBase* mPokeBase;

	void CursorPMoveDown();
	void CursorPMoveUp();
	void CheckDraw();
	int CursorCount;

	void PokemonSelected();
	void PokeDeselect();

	bool DexCheck = false;

	bool Selected = false;
	bool DeSelected = true;

	void Update();
	void Render();
	void Release();

	int DexPosY[7];

	int GetValueR() { return r; }
	int GetValueT() { return t; }
	void SetValueR(int R) { r = R; }
	void SetValueT(int T) { t = T; }

private:
	PokedexState PkDexState;
	Graphics * mGraphics;
	AssetManager* mAssetManager;
	float Counter = 100;

	bool isSeen[151];

	int SeenCount;

	int j;

	int g;

	int r = 0;
	int t = 7;

	float CX;
	float CY;
};