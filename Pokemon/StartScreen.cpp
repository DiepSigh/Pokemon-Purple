#include "StartScreen.h"

using namespace std;

StartScreen::StartScreen() {
	BGStartScreen->SetPosX(0);
	BGStartScreen->SetPosY(0);	
}

StartScreen::StartScreen(float x, float y, Texture *tex) {
	mGraphics = Graphics::Instance();
	mAssetManager = AssetManager::Instance();
	mIntro = AudioManager::Instance();
	SetPosX(x);
	SetPosY(y);
	isPlaying = false;
	mTex = tex;
	StartChar = new StartScreen(320, 300, new AnimatedTexture("StartScreenChar.png", 0, 0, 130, 200, 2, 5, AnimatedTexture::HORIZONTAL));
}

StartScreen::StartScreen(float x, float y, AnimatedTexture *tex) {
	mGraphics = Graphics::Instance();
	mAssetManager = AssetManager::Instance();
	SetPosX(x);
	SetPosY(y);
	mTex = tex;
}

StartScreen::~StartScreen() {
	delete BGStartScreen;
	BGStartScreen = NULL;
}

void StartScreen::Render() {
	GetmTex()->SetRenderRectX(GetPosX());
	GetmTex()->SetRenderRectY(GetPosY());
	mGraphics->DrawTexture(GetmTex()->GetSDLTex(), (GetmTex()->GetClipped()) ? &GetmTex()->GetmClipRect() : NULL, &GetmTex()->GetmRenderRect());
}

void StartScreen::Update() {
	if (!isPlaying) {
		mIntro->IntroSound();
		isPlaying = true;
	}

}
