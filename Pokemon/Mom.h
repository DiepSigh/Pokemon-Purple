#ifndef MOM_H
#define MOM_H

#include "NPC.h"

class Mom : public NPC {
public:	
	Mom();
	void Text();
	void Update();
	~Mom();
private:
	Texture * mMom;
};

#endif // !MOM_H

