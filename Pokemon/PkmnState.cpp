#include "PkmnState.h"

PkmnState::PkmnState() {

}

PkmnState::~PkmnState() {
}

void PkmnState::Render() {
	GetmTex()->SetRenderRectX(GetPosX());
	GetmTex()->SetRenderRectY(GetPosY());

	mGraphics->DrawTexture(GetmTex()->GetSDLTex(), (GetmTex()->GetClipped()) ? &GetmTex()->GetmClipRect() : NULL, &GetmTex()->GetmRenderRect());
}

void PkmnState::Update() {

}

void PkmnState::PokemonState() {
	Pokemon->Render();
}
