#ifndef STARTROOM_H
#define STARTROOM_H

#include "animatedTexture.h"

class StartRoom : public AnimatedTexture {

protected:
	AnimatedTexture* mFloor;
	AnimatedTexture* mObjects;
	AnimatedTexture* mComputer;

public:
	StartRoom();
	~StartRoom();
	inline AnimatedTexture* GetFloor() {return mFloor;}
	inline AnimatedTexture* GetObjects() {return mObjects;}
	inline AnimatedTexture* GetComputer() {return mComputer;}

};

#endif // !STARTROOM_H

