#ifndef _MASTERMAP_h
#define _MASTERMAP_H

#include "gameEntity.h"

class MasterMap : public GameEntity {

private:

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

