#ifndef _MASTERMAP_h
#define _MASTERMAP_H

#include "mapsLoader.h"


class MasterMap : public MapsLoader {

private:
	int PosX;
	int PosY;

	Texture **mMap;
	Graphics* mGraphics;
	void DrawMap();

public:
	MasterMap(float, float);
	~MasterMap();
	void Render();
	void Update();

};


#endif // ! _MASTERMAP_h

