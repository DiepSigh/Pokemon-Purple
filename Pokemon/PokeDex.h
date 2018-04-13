#include "menu.h"
#include "PokeBase.h"

class PokeDex : public Menu {
private:
	bool firstKeyDown = false;
public:
	PokeDex();
	PokeDex(float, float, Texture*);
	~PokeDex();

	static PokeDex* sInstance;
	static PokeDex* Instance();

	bool PKDexActive = false;

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
	PokeDex* DataDisplay;
	PokeDex* Height;
	PokeDex* Weight;
	PokeDex* type;

	PokeDex* PkmnName[151];

	PokeBase* mPokeBase;

	void CursorPMoveDown();
	void CursorPMoveUp();
	void CheckDraw();
	int CursorCount;

	void PokemonSelected();
	void PokeDeselect();
	void PokeDexReset();

	void DexData();

	bool DexCheck = false;
	bool DataCheck = false;
	bool Selected = false;
	bool DeSelected = false;

	void Update();
	void Render();
	void Release();

	int DexPosY[7];

	int GetValueR() { return r; }
	int GetValueT() { return t; }
	void SetValueR(int R) { r = R; }
	void SetValueT(int T) { t = T; }
	void SetFirstKeyDown(bool keyDown) { firstKeyDown = keyDown; }


private:
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