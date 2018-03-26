#ifndef STARTROOM_H
#define STARTROOM_H

#include "animatedTexture.h"
#include "graphics.h"

class StartRoom : public AnimatedTexture {

private:
	AnimatedTexture* mFloor;
	AnimatedTexture* mObject;

public:
	StartRoom();
	~StartRoom();
	//inline AnimatedTexture* GetFloor() {return mFloor;}


};

#endif // !_STARTROOM_H

