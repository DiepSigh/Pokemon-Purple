#include "PokeDex.h"

PokeDex* PokeDex::sInstance = nullptr;

PokeDex* PokeDex::Instance() {
	if (sInstance == NULL) {
		sInstance = new PokeDex();
	}

	return sInstance;
}

PokeDex::PokeDex() {
	mPokeBase = PokeBase::Instance();
	j = 0;
	CursorCount = 0;
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
	DataDisplay = new PokeDex(0, 0, new Texture("Stats.png", 0, 0, 800, 600));
	DataDisplay->SetPosX(0);
	DataDisplay->SetPosY(0);
	SeenCount = 0;
	for (int i = 0; i < 7; i++) {
		if (i == 0) {
			DexPosY[i] = Counter;
		}
		else {
			DexPosY[i] = Counter;
		}
		Counter += 70;
	}

	for (int i = 0; i < 151; i++) {
		isSeen[i] = false;
	}
	/*
	for (int i = 0; i < 3; i++) {
		std::cout << mPokeBase->mP_name[i] << std::endl;
		if (isSeen[i]) {
			PkmnName[i] = new PokeDex(0, 0, new Texture(mPokeBase->mP_name[i], "PKMNSOLID.ttf", 30));
			isSeen[i] = true;
		}
		else {
			PkmnName[i] = new PokeDex(0, 0, new Texture("------------", "PKMNSOLID.ttf", 30));
		}
		PkmnName[i]->SetPosX(140);
		PkmnName[i]->SetPosY(DexPosY[i]);
	}
	*/
	for (int i = 0; i < 35; i++) {
		std::cout << mPokeBase->mP_name[j] << std::endl;
		PkmnName[i] = new PokeDex(0, 0, new Texture(mPokeBase->mP_name[j], "PKMNSOLID.ttf", 30));
		PkmnName[i]->SetPosX(140);
		PkmnName[i]->SetPosY(DexPosY[i]);
		if (PkmnName[35]) {
			PkmnName[i] = new PokeDex(0, 0, new Texture("------------", "PKMNSOLID.ttf", 30));
			PkmnName[i]->SetPosX(140);
			PkmnName[i]->SetPosY(DexPosY[i]);
		}
		isSeen[i] = true;
		j++;
		if (j == 35) {
			j = 0;
		}
	}
	/*
	for (int i = 7; i < 11; i++) {
		std::cout << mPokeBase->mP_name[j] << std::endl;
		PkmnName[i] = new PokeDex(0, 0, new Texture(mPokeBase->mP_name[j], "PKMNSOLID.ttf", 30));
		PkmnName[i]->SetPosX(140);
		PkmnName[i]->SetPosY(820);
		isSeen[i] = true;
		j++;
		if (j == 3) {
			j = 0;
		}
	}
	*/
	for (int i = 0; i < 151; i++) {
		if (isSeen[i]) {
			SeenCount++;
		}
	}
	SeenCounter = new PokeDex(0, 0, new Texture(std::to_string(SeenCount), "PKMNSOLID.ttf", 30));
	SeenCounter->SetPosX(670);
	SeenCounter->SetPosY(100);
}

PokeDex::PokeDex(float x, float y, Texture* tex) {
	mGraphics = Graphics::Instance();
	mAssetManager = AssetManager::Instance();

	SetPosX(x);
	SetPosY(y);
	mTex = tex;
}


PokeDex::~PokeDex() {
	delete PkDex;
	PkDex = NULL;

	delete Seen;
	Seen = NULL;

	delete Caught;
	Caught = NULL;

	delete Contents;
	Contents = NULL;

	delete Data;
	Data = NULL;

	delete Cry;
	Cry = NULL;

	delete Area;
	Area = NULL;

	delete Quit;
	Quit = NULL;

	delete CursorP;
	Quit = NULL;
}

void PokeDex::Release() {
	PokeDex::~PokeDex();
}

void PokeDex::Update() {
}

void PokeDex::Render() {
	GetmTex()->SetRenderRectX(GetPosX());
	GetmTex()->SetRenderRectY(GetPosY());
	mGraphics->DrawTexture(GetmTex()->GetSDLTex(), (GetmTex()->GetClipped()) ? &GetmTex()->GetmClipRect() : NULL, &GetmTex()->GetmRenderRect());
}

void PokeDex::CursorPMoveDown() {
	CursorCount++;
	std::cout << CursorCount << std::endl;
	if (CursorCount >= 151) {
		CursorCount = 151;
	}
	if (CursorP->GetPosY() == 95) {
		CursorP->SetPosY(165);
	}
	else if (CursorP->GetPosY() == 165) {
		CursorP->SetPosY(235);
	}
	else if (CursorP->GetPosY() == 235) {
		CursorP->SetPosY(305);
	}
	else if (CursorP->GetPosY() == 305) {
		CursorP->SetPosY(375);
	}
	else if (CursorP->GetPosY() == 375) {
		CursorP->SetPosY(445);
	}
	else if (CursorP->GetPosY() == 445) {
		CursorP->SetPosY(515);
	}
	else if (CursorP->GetPosY() == 515) {
		if (DexCheck) {
			SetValueR(GetValueR() + 1);
			SetValueT(GetValueT() + 1);
			CheckDraw();
		}
		DexCheck = true;
	}
}

void PokeDex::CursorPMoveUp() {
	CursorCount--;
	std::cout << CursorCount << std::endl;
	if (CursorCount <= 0) {
		CursorCount = 0;
	}
	if (CursorP->GetPosY() == 515) {
		CursorP->SetPosY(445);
	}
	else if (CursorP->GetPosY() == 445) {
		DexCheck = false;
		CursorP->SetPosY(375);
	}
	else if (CursorP->GetPosY() == 375) {
		CursorP->SetPosY(305);
	}
	else if (CursorP->GetPosY() == 305) {
		CursorP->SetPosY(235);
	}
	else if (CursorP->GetPosY() == 235) {
		CursorP->SetPosY(165);
	}
	else if (CursorP->GetPosY() == 165) {
		CursorP->SetPosY(95);
	}
	else if (CursorP->GetPosY() == 95) {
		if (DexCheck) {
			SetValueR(GetValueR() - 1);
			SetValueT(GetValueT() - 1);
			if (GetValueR() <= 0) {
				SetValueR(0);
			}
			if (GetValueT() <= 7) {
				SetValueT(7);
			}
			CheckDraw();
		}
		DexCheck = true;
	}
}

void PokeDex::CheckDraw() {
	int j = 0;
	for (int i = GetValueR(); i < GetValueT(); i++) {
		std::cout << DexPosY[j] << std::endl;
		PkmnName[i]->SetPosY(DexPosY[j]);
		j++;
	}
}

void PokeDex::PokemonSelected() {
	if (DeSelected) {
		Selected = true;
		CX = CursorP->GetPosX();
		CY = CursorP->GetPosY();
		PkmnName[CursorCount];
		CursorP->SetPosX(610);
		CursorP->SetPosY(315);
	}
	DeSelected = true;
}

void PokeDex::PokeDeselect() {
	Selected = false;
	if(Selected == false) {
		CursorP->SetPosX(CX);
		CursorP->SetPosY(CY);
	}
	DeSelected = true;
	DataCheck = false;
}

void PokeDex::PokeDexReset() {
	CursorP->SetPosX(100);
	CursorP->SetPosY(95);
	CursorCount = 0;
	SetValueR(0);
	SetValueT(7);

	CX = 0;
	CY = 0;

	std::cout << CursorCount << std::endl;
}

void PokeDex::DexData() {
	if (Selected && firstKeyDown) {
		DataCheck = true;
	}

	firstKeyDown = true;
}