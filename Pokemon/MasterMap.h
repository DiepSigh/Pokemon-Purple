#ifndef  _MASTERMAP_h
#define _MASTERMAP_H

#include "texture.h"

class MasterMap {

private:

	Texture *mMap;
	int PosX;
	int PosY;

public:
	MasterMap();
	~MasterMap();

	void Render();
	void Update();
	void Events();

	int GetPosX() { return PosX; }
	int GetPosY() { return PosY; }

	inline AnimatedTexture* GetMap() { return mMap; }
};


#endif // ! _MASTERMAP_h

