#ifndef DIALOUGE_H
#define DIALOUGE_H

#include <iostream>
#include <fstream>
#include <string>


class Dialouge {
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
	
};

#endif // !DIALOUGE_H
