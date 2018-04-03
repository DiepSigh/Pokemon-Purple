#include "TextManager.h"


TextManager::TextManager() {
	mTextScreen = new TextScreen(0, 0, "OAK");
	mTextScreen->SetPosX(10);
	mTextScreen->SetPosY(10);
}

TextManager::~TextManager()
{
}

void TextManager::Render()
{
	mTextScreen->Render();
}

void TextManager::Update()
{
}
