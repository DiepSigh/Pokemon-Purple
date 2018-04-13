#ifndef _MASTERMAP_h
#define _MASTERMAP_H

#include "animatedTexture.h"
#include "gameEntity.h"
#include "camera.h"
#include "NPC1.h"
#include "NPC2.h"
#include <iostream>


class MasterMap : public GameEntity {

private:
	int PosX;
	int PosY;

	Texture *mMap;
	Graphics* mGraphics;
	void DrawMap();
	NPC1* mNPC1;
	NPC2* mNPC2;
	Camera* mCam;
	MasterMap* mMasterMap;

public:
	MasterMap(float, float);
	~MasterMap();
	void Render();
	void Update();
	//NPC1
	void NPC1Left();
	void NPC1Right();
	void NPC1Up();
	void NPC1Down();
	//NPC2
	void NPC2Left();
	void NPC2Right();
	void NPC2Up();
	void NPC2Down();

};


#endif // ! _MASTERMAP_h

