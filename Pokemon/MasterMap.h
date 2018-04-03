#ifndef  _MASTERMAP_h
#define _MASTERMAP_H

#include "animatedTexture.h"

class MasterMap {
public:
	MasterMap();
	~MasterMap();
	void Render();
	void Update();
	void Events();
	int GetPosX() { return PosX; }
	int GetPosY() { return PosY; }
	inline AnimatedTexture* GetMap() { return mMap; }

private:
	AnimatedTexture *mMap;
	int PosX;
	int PosY;
};


#endif // ! _MASTERMAP_h

