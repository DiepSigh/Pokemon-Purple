#ifndef NPC_H
#define NPC_H

using namespace std;

#include "characters.h"
#include "DisplayText.h"
#include "graphics.h"
#include "assetManager.h"


class NPC : public Characters {
protected:
	Graphics * mGraphics;
	AssetManager* mAssetManager;

private:
	int mRow;
	int mCol;
	bool mTalk;
	bool mWalkRoute;
	bool misTrainer;
	bool mLoseBattle;

public:
	NPC();
	void Render();
	int GetRow() { return mRow; }
	int GetCol() { return mCol; }
	void SetRow(int r) { mRow = r; }
	void SetCol(int c) { mCol = c; }
	bool Talk();
	bool WalkRoute();
	bool isTrainer();
	bool LoseBattle();
	~NPC();
	
	
};

#endif // !NPC_H

