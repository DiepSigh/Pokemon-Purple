#ifndef NPC1_H
#define NPC1_H

#include "NPC.h"

class NPC1 : public NPC {
public:
	NPC1();
	void Text();
	void Update();
	~NPC1();

private:
	Texture * mNPC1;
};
#endif // !NPC1_H
