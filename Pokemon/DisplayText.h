#ifndef DISPLAYTEXT_H
#define DISPLAYTEXT_H

#include <fstream>
#include <string>
#include <iostream>
#include "texture.h"
#include "gameEntity.h"
#include "graphics.h"
#include <vector>


class TextScreen : public GameEntity {
protected:
	std::string mSpeech;
public:
	TextScreen();
	TextScreen(int, int, std::string);
	~TextScreen();
	std::string Talk(std::string);
	void Update();
	void Speech();
	void Render();
	TextScreen* mNPCtext;
	std::string GetDisplay() { return Display ; }
	void SetDisplay(std::string speech) { Display = speech; }

private:
	std::string Display;
	Graphics* mGraphics;
	AssetManager* mAssetManager;
	Vector2 mPos;
	std::vector <std::string> Dialouge;
	
};

#endif // !DISPLAYTEXT_H
