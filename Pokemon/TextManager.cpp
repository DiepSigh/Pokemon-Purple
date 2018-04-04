#include "TextManager.h"


TextManager::TextManager() {
	mTextScreen = new TextScreen(0, 0, "OAK");
	mTextScreen->SetPosX(130);
	mTextScreen->SetPosY(450);
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
