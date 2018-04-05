#ifndef TEXTMANAGER_H
#define TEXTMANAGER_H

#include "DisplayText.h"

class TextManager : public TextScreen{
public:
	TextManager();
	~TextManager();
	void Release();

	static TextManager* sInstance;
	static TextManager* Instance();

	void Render();
	void Update();


private:
	TextScreen * mTextScreen;
};
#endif // !TEXTMANAGER_H

