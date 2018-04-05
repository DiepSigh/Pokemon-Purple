#ifndef _MART_H
#define _MART_H

#include "mapsLoader.h"

class PokemonMart : public MapsLoader {

private:

	Texture

		**mCashbox, **mCashboxBottom, **mCashboxBottomLeft, **mCooler1, **mCooler2, **mExit, **mFloor, **mFloorShadow, **mShelfCashierBottom1, 
		**mShelfCashierBottom2, **mShelfCashier1, **mShelfCashier2, **mShelf1, **mShelf2, **mShelf3, **mShelf4, **mSignSale, **mSignSaleBottom;


	int map[8][8]=
	{
				{ 16,16,3,3,3,3,16,16 },
				{ 17,17,4,4,4,4,17,17 },
				{ 7,6,6,6,6,6,6,6 },
				{ 10,11,6,6,12,14,12,14 },
				{ 8,9,7,6,13,15,13,15 },
				{ 7,0,7,6,6,6,6,6 },
				{ 2,1,7,6,6,6,6,6 },
				{ 7,6,6,5,5,6,6,6 },

				
	};

	Graphics* mGraphics;
	int tile;
	void DrawMap(int);

public:
	PokemonMart(float, float);
	~PokemonMart();
	void Render();
	void Update();

};

#endif // !_MART_H

