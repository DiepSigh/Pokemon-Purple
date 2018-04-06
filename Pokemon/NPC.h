#ifndef NPC_H
#define NPC_H

using namespace std;

#include "characters.h"
#include "DisplayText.h"
#include <vector>

class NPC : public Characters {
public:
	NPC();
	NPC(std::string);
	~NPC();

private:
	std::string Name;
};

#endif // !NPC_H

