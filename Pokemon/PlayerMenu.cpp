#include "PlayerMenu.h"

PlayerMenu* PlayerMenu::sInstance = nullptr;

PlayerMenu* PlayerMenu::Instance() {
	if (sInstance == nullptr) {
		sInstance = new PlayerMenu();
	}

	return sInstance;
}

PlayerMenu::PlayerMenu() {
	MenuP = new PlayerMenu(0, 0, new Texture("PlayerScreen.png", 0, 0, 800, 600));
	MenuP->SetPosX(0);
	MenuP->SetPosY(0);
	Name = new PlayerMenu(0, 0, new Texture("NAME/", "PKMNSOLID.ttf", 35));
	Name->SetPosX(120);
	Name->SetPosY(40);
	Money = new PlayerMenu(0, 0, new Texture("MONEY/", "PKMNSOLID.ttf", 35));
	Money->SetPosX(120);
	Money->SetPosY(110);
	Time = new PlayerMenu(0, 0, new Texture("TIME/", "PKMNSOLID.ttf", 35));
	Time->SetPosX(120);
	Time->SetPosY(180);
	PlayerName = new PlayerMenu(0, 0, new Texture("BLUE", "PKMNSOLID.ttf", 35));
	PlayerName->SetPosX(310);
	PlayerName->SetPosY(40);
	PlayerMoney = new PlayerMenu(0, 0, new Texture("$0000", "PKMNSOLID.ttf", 35));
	PlayerMoney->SetPosX(330);
	PlayerMoney->SetPosY(110);
	GameTime = new PlayerMenu(0, 0, new Texture(" 00 : 00", "PKMNSOLID.ttf", 30));
	GameTime->SetPosX(290);
	GameTime->SetPosY(180);
}

PlayerMenu::PlayerMenu(float x, float y, Texture* tex) {
	mGraphics = Graphics::Instance();
	mAssetManager = AssetManager::Instance();

	SetPosX(x);
	SetPosY(y);
	mTex = tex;
}

PlayerMenu::~PlayerMenu() {

}

void PlayerMenu::Render() {
	GetmTex()->SetRenderRectX(GetPosX());
	GetmTex()->SetRenderRectY(GetPosY());

	mGraphics->DrawTexture(GetmTex()->GetSDLTex(), (GetmTex()->GetClipped()) ? &GetmTex()->GetmClipRect() : NULL, &GetmTex()->GetmRenderRect());
}

void PlayerMenu::Update() {

}
