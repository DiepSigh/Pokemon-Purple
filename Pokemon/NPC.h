#ifndef NPC_H
#define NPC_H

using namespace std;

#include "characters.h"
#include "DisplayText.h"
#include <vector>

class NPC : public Characters {
public:
	NPC();
	~NPC();

private:
	vector <string> Talk;
	
};

#endif // !NPC_H

