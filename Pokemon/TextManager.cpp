#include "TextManager.h"

TextManager* TextManager::sInstance = nullptr;

TextManager* TextManager::Instance() {
	if (sInstance == nullptr) {
		sInstance = new TextManager();
	}
	return sInstance;
}

TextManager::TextManager() {
	mTextScreen = new TextScreen(0, 0, "SPEAROW");
	mTextScreen->SetPosX(130);
	mTextScreen->SetPosY(450);
	mTextScreen->Speech();
}
void TextManager::Release() {
	delete mTextScreen;
	mTextScreen = NULL;
}

TextManager::~TextManager(){

}

void TextManager::Render()
{
	mTextScreen->Render();
}

void TextManager::Update()
{
}


