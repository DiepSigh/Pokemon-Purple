#ifndef _MASTERMAP_h
#define _MASTERMAP_H

#include "animatedTexture.h"
#include "gameEntity.h"


class MasterMap : public GameEntity {

private:
	int PosX;
	int PosY;

	Texture *mMap;
	Graphics* mGraphics;
	void DrawMap();

public:
	MasterMap(float, float);
	~MasterMap();
	void Render();
	void Update();

};


#endif // ! _MASTERMAP_h

