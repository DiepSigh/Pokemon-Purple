#ifndef DIALOUGE_H
#define DIALOUGE_H

#include "gameEntity.h"
#include"graphics.h"
#include "texture.h"
#include <iostream>
#include <fstream>
#include <string>


class Dialouge : public GameEntity {
private:
	static Dialouge* sInstance;
	std::string NPCtext[188][27];

public:
	static Dialouge* Instance();
	void textDisplay();
	static void Release();
	std::string GetNPCtext(int r, int c) { return NPCtext[r][c]; }
	Dialouge();
	~Dialouge();

private:
	Graphics* mGraphics;
	Texture* mTextBox;
	
};

#endif // !DIALOUGE_H
