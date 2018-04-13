#include "PokeDex.h"

PokeDex::PokeDex() {
	PkDex = new PokeDex(0, 0, new Texture("PokeDexMenu.png", 0, 0, 800, 600));
	PkDex->SetPosX(0);
	PkDex->SetPosY(0);
	Seen = new PokeDex(0, 0, new Texture("SEEN", "PKMNSOLID.ttf", 30));
	Seen->SetPosX(650);
	Seen->SetPosY(60);
	Caught = new PokeDex(0, 0, new Texture("OWN", "PKMNSOLID.ttf", 30));
	Caught->SetPosX(650);
	Caught->SetPosY(160);
	Contents = new PokeDex(0, 0, new Texture("CONTENTS", "PKMNSOLID.ttf", 30));
	Contents->SetPosX(60);
	Contents->SetPosY(60);
	Data = new PokeDex(0, 0, new Texture("DATA", "PKMNSOLID.ttf", 30));
	Data->SetPosX(650);
	Data->SetPosY(320);
	Cry = new PokeDex(0, 0, new Texture("CRY", "PKMNSOLID.ttf", 30));
	Cry->SetPosX(650);
	Cry->SetPosY(385);
	Area = new PokeDex(0, 0, new Texture("AREA", "PKMNSOLID.ttf", 30));
	Area->SetPosX(650);
	Area->SetPosY(460);
	Quit = new PokeDex(0, 0, new Texture("QUIT", "PKMNSOLID.ttf", 30));
	Quit->SetPosX(650);
	Quit->SetPosY(520);
}

PokeDex::PokeDex(float x, float y, Texture* tex) {
	mGraphics = Graphics::Instance();
	mAssetManager = AssetManager::Instance();

	SetPosX(x);
	SetPosY(y);
	mTex = tex;
}

PokeDex::~PokeDex() {
	
}

void PokeDex::Update() {

}

void PokeDex::Render() {
	GetmTex()->SetRenderRectX(GetPosX());
	GetmTex()->SetRenderRectY(GetPosY());

	mGraphics->DrawTexture(GetmTex()->GetSDLTex(), (GetmTex()->GetClipped()) ? &GetmTex()->GetmClipRect() : NULL, &GetmTex()->GetmRenderRect());

}

void PokeDex::CheckDexState() {
	if (PKDexActive) {
		switch (PkDexState) {
		case CONTENTS:
			//Pokemon Selection
			break;
		case DATA:
			//Load Pokemon Data
			break;
		case CRY:
			//Play Pokemon Cry
			break;
		case AREA:
			//Load Map where pokemon is found
			break;
		case QUIT:
			//Disable PokeDex
			PKDexActive = false;
			break;
		}
	}
}