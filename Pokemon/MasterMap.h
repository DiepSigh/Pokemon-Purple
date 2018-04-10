#ifndef _MASTERMAP_h
#define _MASTERMAP_H

//#include "animatedTexture.h"
#include "gameEntity.h"
#include "camera.h"
#include <iostream>
#include "mapsLoader.h"


class MasterMap : public MapsLoader {

private:
	int PosX;
	int PosY;

	Texture **mMap;
	Graphics* mGraphics;
	void DrawMap();

public:

	MasterMap();
	MasterMap(float, float);
	~MasterMap();
	void Render();
	void Update();

};


#endif // ! _MASTERMAP_h

