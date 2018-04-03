#ifndef _POKEMONLEAGUE_H
#define _POKEMONLEAGUE_H

#include "gameEntity.h"

class PokemonLeague : public GameEntity {
private:

	Texture
		*mCarpet1, *mCarpet2, *mDoor, *mFloor, *mStatue1, *mStatue2, *mStatue3, *mWall;

	int map[8][10] = 
	{
				{ 7,7,7,4,2,2,4,7,7,7 },
				{ 3,3,3,5,0,1,5,3,3,3 },
				{ 3,3,3,3,0,1,3,3,3,3 },
				{ 3,3,3,3,0,1,3,3,3,3 },
				{ 3,3,3,3,0,1,3,3,3,3 },
				{ 3,3,3,3,0,1,3,3,3,3 },
				{ 3,3,3,6,0,1,6,3,3,3 },
				{ 3,3,3,5,0,1,5,3,3,3 },

	};

	Graphics* mGraphics;
	int tile;
	void DrawMap(int);

public:
	PokemonLeague(float, float);
	~PokemonLeague();
	void Render();
	void Update();

};

#endif // !_POKEMONLEAGUE_H

