#ifndef _MASTERMAP_h
#define _MASTERMAP_H

#include "animatedTexture.h"
#include "gameEntity.h"
#include "camera.h"
#include "NPC1.h"
#include <iostream>


class MasterMap : public GameEntity {

private:
	int PosX;
	int PosY;

	Texture *mMap;
	Graphics* mGraphics;
	void DrawMap();
	NPC1* mNPC1;
	Camera* mCam;
	MasterMap* mMasterMap;

public:
	MasterMap(float, float);
	~MasterMap();
	void Render();
	void Update();

};


#endif // ! _MASTERMAP_h

