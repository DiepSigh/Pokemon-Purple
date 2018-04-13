#ifndef NPC2_H
#define NPC2_H

#include "NPC.h"

class NPC2 : public NPC {
public:
	NPC2();
	void Text();
	void Update();
	~NPC2();

private:
	Texture * mNPC2;
};
#endif // !NPC2_H
