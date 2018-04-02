#ifndef DISPLAYTEXT_H
#define DISPLAYTEXT_H

#include <fstream>
#include <iostream>
#include "texture.h"

class TextScreen {
public:
	TextScreen();
	void Talk(std::string);
	void Update();

private:

};

#endif // !DISPLAYTEXT_H
