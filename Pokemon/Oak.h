#ifndef OAK_H
#define OAK_H

#include "NPC.h"

class Oak :  public NPC {
public:
	Oak();
	void Text();
	~Oak();

private:
	Texture* mOak; 

};


#endif // !OAK_H
