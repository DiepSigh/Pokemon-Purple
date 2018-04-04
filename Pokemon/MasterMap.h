#ifndef _MASTERMAP_h
#define _MASTERMAP_H

#include "animatedTexture.h"
<<<<<<< HEAD

class MasterMap {
=======
#include "gameEntity.h"


class MasterMap : public GameEntity {

private:
	int PosX;
	int PosY;

	Texture *mMap;
	Graphics* mGraphics;
	void DrawMap();

>>>>>>> master
public:
	MasterMap(float, float);
	~MasterMap();
	void Render();
	void Update();
<<<<<<< HEAD
	void Events();
	int GetPosX() { return PosX; }
	int GetPosY() { return PosY; }
	inline AnimatedTexture* GetMap() { return mMap; }

private:
	AnimatedTexture *mMap;
	int PosX;
	int PosY;
=======

>>>>>>> master
};


#endif // ! _MASTERMAP_h

