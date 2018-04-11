#include "StartScreen.h"

using namespace std;

StartScreen::StartScreen() {
	mTex = new Texture("StartScreen.png",0,0,800,600);
	SetPosX(0);
	SetPosY(0);
	mGraphics = Graphics::Instance();
	mIntro = AudioManager::Instance();
	isPlaying = false;
}

StartScreen::~StartScreen() {

}

void StartScreen::Render() {
	mTex->SetRenderRectX((int)(GetPosX()));
	mTex->SetRenderRectY((int)(GetPosY()));
	mGraphics->DrawTexture(mTex->GetSDLTex(), (mTex->GetClipped()) ? &mTex->GetmClipRect() : NULL, &mTex->GetmRenderRect());
}

void StartScreen::Update() {
	if (!isPlaying) {
		mIntro->IntroSound();
		isPlaying = true;
	}
}
