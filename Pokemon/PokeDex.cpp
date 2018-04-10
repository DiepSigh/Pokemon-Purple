#include "PokeDex.h"

PokeDex::PokeDex() {
	mPokeBase = PokeBase::Instance();
	Counter = 40;
	j = 0;
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
	CursorP = new PokeDex(0, 0, new Texture("arrowPKMN.png", 0, 0, 40, 40));
	CursorP->SetPosX(100);
	CursorP->SetPosY(95);
	for (int i = 0; i < 3; i++) {
		std::cout << mPokeBase->mP_name[i] << std::endl;
		std::cout << "----------------------------------\n" << std::endl;
		PkmnName[i] = new PokeDex(0, 0, new Texture(mPokeBase->mP_name[i], "PKMNSOLID.ttf", 30));
		PkmnName[i]->SetPosX(140);
		PkmnName[i]->SetPosY(60 + Counter);
		Counter += 70;
	}

	for (int i = 3; i < 7; i++) {
		std::cout << mPokeBase->mP_name[j] << std::endl;
		std::cout << "----------------------------------\n" << std::endl;
		PkmnName[i] = new PokeDex(0, 0, new Texture(mPokeBase->mP_name[j], "PKMNSOLID.ttf", 30));
		PkmnName[i]->SetPosX(140);
		PkmnName[i]->SetPosY(60 + Counter);
		Counter += 70;
		j++;
		if (j == 3) {
			j = 0;
		}
	}

	for (int i = 7; i < 11; i++) {
		std::cout << mPokeBase->mP_name[j] << std::endl;
		std::cout << "----------------------------------\n" << std::endl;
		PkmnName[i] = new PokeDex(0, 0, new Texture(mPokeBase->mP_name[j], "PKMNSOLID.ttf", 30));
		PkmnName[i]->SetPosX(140);
		PkmnName[i]->SetPosY(60 + Counter);
		Counter += 70;
		j++;
		if (j == 3) {
			j = 0;
		}
	}
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

void PokeDex::CursorPMoveDown() {
	if (CursorP->GetPosY() == 95) {
		std::cout << CursorP->GetPosY();
		CursorP->SetPosY(165);
	}
	else if (CursorP->GetPosY() == 165) {
		std::cout << CursorP->GetPosY();
		CursorP->SetPosY(235);
	}
	else if (CursorP->GetPosY() == 235) {
		std::cout << CursorP->GetPosY();
		CursorP->SetPosY(305);
	}
	else if (CursorP->GetPosY() == 305) {
		std::cout << CursorP->GetPosY();
		CursorP->SetPosY(375);
	}
	else if (CursorP->GetPosY() == 375) {
		std::cout << CursorP->GetPosY();
		CursorP->SetPosY(445);
	}
	else if (CursorP->GetPosY() == 445) {
		std::cout << CursorP->GetPosY();
		CursorP->SetPosY(515);
	}
	else if (CursorP->GetPosY() == 515) {
		std::cout << CursorP->GetPosY();
		if (DexCheck) {
			SetValueR(GetValueR() + 1);
			SetValueT(GetValueT() + 1);
			CheckDraw();
		}
		DexCheck = true;
	}
}

void PokeDex::CheckDraw() {
	for (int i = GetValueR(); i < GetValueT(); i++) {
		PkmnName[i]->SetPosY(PkmnName[i]->GetPosY() - 70);
	}
}
