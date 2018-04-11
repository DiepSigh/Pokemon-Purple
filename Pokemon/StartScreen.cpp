#include "StartScreen.h"

using namespace std;

StartScreen::StartScreen() {
	//mTex = new Texture("StartScreen.png", 0, 0, 800, 600);
	BGStartScreen = new StartScreen(0, 0, new Texture("StartScreen.png", 0, 0, 800, 600));
	BGStartScreen->SetPosX(0);
	BGStartScreen->SetPosY(0);
	
	isPlaying = false;
}

StartScreen::StartScreen(float x, float y, Texture *tex) {
	mGraphics = Graphics::Instance();
	mAssetManager = AssetManager::Instance();
	mIntro = AudioManager::Instance();
	SetPosX(x);
	SetPosY(y);
	//mPos.x = x;
	//mPos.y = y;
	mTex = tex;
	//Render();
	//Update();
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
