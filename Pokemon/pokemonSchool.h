#ifndef _POKEMONSCHOOL_H
#define _POKEMONSCHOOL_H

#include "gameEntity.h"

class PokemonSchool : public GameEntity {

private:
	
	Texture
		*mBoard1, *mBoard2, *mBookshelf1, *mBookShelf2, *mChair, *mExit, *mFloor,
		*mFlower1, *mFlower2, *mTable1, *mTable2, *mTable3, *mTable4, *mWall, *mWindow;

	int map[8][8] =
	{
				{ 13,14,13,0,1,13,13,2 },
				{ 6,6,6,6,6,6,6,3 },
				{ 6,6,6,6,6,6,6,6 },
				{ 6,6,6,9,11,6,6,6 },
				{ 6,6,6,10,12,6,6,6 },
				{ 6,6,6,4,6,6,6,6 },
				{ 7,6,6,6,6,6,6,7 },
				{ 8,6,5,5,6,6,6,8 },

	};

	Graphics* mGraphics;
	int tile;
	void DrawMap(int);

public:
	PokemonSchool(float, float);
	~PokemonSchool();
	void Render();
	void Update();

};

#endif // !_POKEMONSCHOOL_H

