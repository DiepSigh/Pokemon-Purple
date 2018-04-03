#include "PokeDex.h"

PokeDex::PokeDex() {
	PKDexActive = true;
}

PokeDex::~PokeDex() {
	
}

void PokeDex::Update() {

}

void PokeDex::Render() {
	GetmTex()->SetRenderRectX(GetPosX());
	GetmTex()->SetRenderRectY(GetPosY());

	mGraphics->DrawTexture(GetmTex()->GetSDLTex(), (GetClipped()) ? &GetmClipRect() : NULL, &GetmTex()->GetmRenderRect());
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