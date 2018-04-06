#include "Options.h"

Options* Options::sInstance = nullptr;

Options* Options::Instance() {
	if (sInstance == nullptr) {
		sInstance = new Options();
	}

	return sInstance;
}


Options::Options() {
	textSpeed = new Options(0, 0, new Texture("TEXT SPEED", "PKMNSOLID.ttf", 30));
	textSpeed->SetPosX(40);
	textSpeed->SetPosY(50);
	btlAnimation = new Options(0, 0, new Texture("BATTLE ANIMATION", "PKMNSOLID.ttf", 30));
	btlAnimation->SetPosX(40);
	btlAnimation->SetPosY(170);
	btlStyle = new Options(0, 0, new Texture("BATTLE STYLE", "PKMNSOLID.ttf", 30));
	btlStyle->SetPosX(40);
	btlStyle->SetPosY(290);
	Cancel = new Options(0, 0, new Texture("CANCEL", "PKMNSOLID.ttf", 30));
	Cancel->SetPosX(70);
	Cancel->SetPosY(400);
	Fast = new Options(0, 0, new Texture("FAST", "PKMNSOLID.ttf", 30));
	Fast->SetPosX(70);
	Fast->SetPosY(100);
	Medium = new Options(0, 0, new Texture("MEDIUM", "PKMNSOLID.ttf", 30));
	Medium->SetPosX(240);
	Medium->SetPosY(100);
	Slow = new Options(0, 0, new Texture("SLOW", "PKMNSOLID.ttf", 30));
	Slow->SetPosX(460);
	Slow->SetPosY(100);
	On = new Options(0, 0, new Texture("ON", "PKMNSOLID.ttf", 30));
	On->SetPosX(70);
	On->SetPosY(220);
	Off = new Options(0, 0, new Texture("OFF", "PKMNSOLID.ttf", 30));
	Off->SetPosX(310);
	Off->SetPosY(220);
	Shift = new Options(0, 0, new Texture("SHIFT", "PKMNSOLID.ttf", 30));
	Shift->SetPosX(70);
	Shift->SetPosY(340);
	Set = new Options(0, 0, new Texture("SET", "PKMNSOLID.ttf", 30));
	Set->SetPosX(310);
	Set->SetPosY(340);
	CursorO = new Options(0, 0, new Texture("arrowPKMN.png", 0, 0, 40, 40));
	CursorO->SetPosX(Fast->GetPosX() - 40);
	CursorO->SetPosY(Fast->GetPosY() - 5);
}

Options::Options(float x, float y, Texture* tex) {
	mGraphics = Graphics::Instance();
	mAssetManager = AssetManager::Instance();

	SetPosX(x);
	SetPosY(y);
	mTex = tex;

	//SetmTex(tex);
	/*
	mPos.x = x;
	mPos.y = y;
	mTex = tex;
	*/
}


Options::~Options() {

}

void Options::Render() {
	GetmTex()->SetRenderRectX(GetPosX());
	GetmTex()->SetRenderRectY(GetPosY());

	mGraphics->DrawTexture(GetmTex()->GetSDLTex(), (GetmTex()->GetClipped()) ? &GetmTex()->GetmClipRect() : NULL, &GetmTex()->GetmRenderRect());
}

void Options::Update() {

}


//Have to set x,y to be exact only. use both x,y. if not it will break..... FIXXXXXXXXXXXXXXXX
void Options::oCursorDown() {
	if (CursorO->GetPosY() == Fast->GetPosY() - 5) {
		CursorO->SetPosY(On->GetPosY() - 5);
	}
	else if (CursorO->GetPosY() == On->GetPosY() - 5) {
		CursorO->SetPosY(Shift->GetPosY() - 5);
	}
	else if (CursorO->GetPosY() == Shift->GetPosY() - 5) {
		CursorO->SetPosY(Cancel->GetPosY() - 5);
	}
	else if (CursorO->GetPosY() == Cancel->GetPosY() - 5) {
		CursorO->SetPosY(Fast->GetPosY() - 5);
	}
	else if (CursorO->GetPosY() == Off->GetPosY()) {
		CursorO->SetPosY(Set->GetPosY());
	}
	else if (CursorO->GetPosX() == Set->GetPosX() && CursorO->GetPosY() == Set->GetPosY()) {
		CursorO->SetPosX(Cancel->GetPosX() - 40);
		CursorO->SetPosY(Cancel->GetPosY() - 5);
	}
}

void Options::oCursorUp() {
	if (CursorO->GetPosY() == Fast->GetPosY() - 5) {
		CursorO->SetPosY(Cancel->GetPosY() - 5);
	}
	else if (CursorO->GetPosY() == Cancel->GetPosY() - 5) {
		CursorO->SetPosY(Shift->GetPosY() - 5);
	}
	else if (CursorO->GetPosY() == Shift->GetPosY() - 5) {
		CursorO->SetPosY(On->GetPosY() - 5);
	}
	else if (CursorO->GetPosY() == On->GetPosY() - 5) {
		CursorO->SetPosY(Fast->GetPosY() - 5);
	}
}

void Options::oCursorLeft() {
	//Text speed left
	if (CursorO->GetPosX() == Slow->GetPosX() - 40) {
		CursorO->SetPosX(Medium->GetPosX() - 40);
	}
	else if (CursorO->GetPosX() == Medium->GetPosX() - 40) {
		CursorO->SetPosX(Fast->GetPosX() - 40);
	}
	else if (CursorO->GetPosX() == Fast->GetPosX() - 40) {
		CursorO->SetPosX(Slow->GetPosX() - 40);
	}

	//Battle Animation left
	else if (CursorO->GetPosX() == On->GetPosX() - 40) {
		CursorO->SetPosX(Off->GetPosX() - 40);
	}
	else if (CursorO->GetPosX() == Off->GetPosX() - 40){
		CursorO->SetPosX(On->GetPosX() - 40);
	}
	//Battle Style
	else if (CursorO->GetPosX() == Shift->GetPosX() - 40) {
		CursorO->SetPosX(Set->GetPosX() - 40);
	}
	else if(Cursor->GetPosX() == Set->GetPosX() - 40){
		CursorO->SetPosX(Shift->GetPosX() - 40);
	}
}

void Options::oCursorRight() {

}