#ifndef _POKEMONCENTER_H
#define _POKEMONCANTER_H

#include "gameEntity.h"

class PokemonCenter : public GameEntity {

	private:

		Texture
			*mColumn1, *mColumn2, *mColumnEnd, *mComputer1, *mComputer2, *mExit, *mFloor, *mFloorShadow, *mFlower1, *mFlower2, *mLongDesk1, *mLongDesk2,
			*mLongDesk3, *mLongDesk4, *mPicture1, *mPicture2, *mPokemonHeal1, *mPokemonHeal2, *mPokemonHeal3, *mPokemonHeal4, *mSofa1, *mSofa2,
			*mSofaFloor1, *mSofaFloor2, *mWayBackRoom, *mWall;

		int map[8][14]
		{
						{ 0,17,18,14,15,0,17,18,25,25,26,25,26,25 },
						{ 1,19,20,7,6,1,19,20,6,6,6,6,6,6 },
						{ 2,10,11,12,11,2,11,11,11,11,13,6,13,11 },
						{ 6,6,6,6,6,6,6,6,6,6,6,6,6,3 },
						{ 21,23,6,6,6,6,6,6,6,6,6,6,6,4 },
						{ 22,24,6,6,6,6,6,6,6,6,6,6,6,6 },
						{ 8,8,6,6,6,6,8,8,6,6,6,6,8,8 },
						{ 9,9,6,5,5,6,9,9,6,6,6,6,9,9 },

		
		};

		Graphics* mGraphics;
		int tile;
		void DrawMap(int);

public:
	PokemonCenter(float, float);
	~PokemonCenter();
	void Render();
	void Update();
};

#endif // !_POKEMONCENTER_H

