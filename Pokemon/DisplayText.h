#ifndef DISPLAYTEXT_H
#define DISPLAYTEXT_H

//#include <fstream>
#include "texture.h"
#include "gameEntity.h"
#include "graphics.h"
#include "Dialouge.h"
#include <vector>


class TextScreen : public GameEntity {
protected:
	//std::string mSpeech;
public:
	TextScreen();
	TextScreen(int, int);
	~TextScreen();
	//std::string Talk(std::string);
	void Update();
	void Speech(int, int);
	void Render(int, int);
	TextScreen * mNPCtext;
	Dialouge* mDialouge;
	std::string GetDisplay() { return Display ; }
	void SetDisplay(std::string speech) { Display = speech; }

private:
	
	std::string Display;
	Graphics* mGraphics;
	AssetManager* mAssetManager;
	Vector2 mPos;
	
};

#endif // !DISPLAYTEXT_H
