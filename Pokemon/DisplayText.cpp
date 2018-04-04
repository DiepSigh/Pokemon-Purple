#include "DisplayText.h"

using namespace std;

TextScreen::TextScreen(){
	mGraphics = Graphics::Instance();
	mAssetManager = AssetManager::Instance();
	//Talk("OAK");
	//mNPCtext = new TextScreen(0, 0, new Texture(mSpeech, "PKMNSOLID.ttf", 60));
	//mNPCtext->SetPosY(10);
	//mNPCtext->SetPosX(10);
}

TextScreen::TextScreen(int x, int y, string name) {
	mGraphics = Graphics::Instance();
	mAssetManager = AssetManager::Instance();

	mPos.x = x;
	mPos.y = y;
	Talk(name);
	mTex = new Texture(mSpeech, "PKMNSOLID.ttf", 40);
}

TextScreen::~TextScreen()
{
}

string TextScreen::Talk(string NPC){
	string Name;
	bool Found = false;
	
	std::ifstream src("../Debug/Assets/pokemonblue_text.csv");
	if (!src.is_open()) {
		std::cout << "Couldn't open file: pokemonblue_text.csv" << std::endl;
	} 
	else {
		do {
			getline(src, Name, ',');
			if (NPC == Name) {
				Found = true;
				do {
					getline(src, mSpeech, ',');
					Dialouge.push_back(mSpeech);
					cout << mSpeech;
				} while (mSpeech != "\n");
				
			}
			else {
				src.ignore(500, '\n');
				src.ignore(500, '\n');
			}
		} while (!Found || src.eof());
	} 
	src.close();
	return mSpeech;
}

void TextScreen::Update()
{
}

void TextScreen::Render()
{
	GetmTex()->SetRenderRectX(GetPosX());
	GetmTex()->SetRenderRectY(GetPosY());

	mGraphics->DrawTexture(GetmTex()->GetSDLTex(), (GetClipped()) ? &GetmClipRect() : NULL, &GetmTex()->GetmRenderRect());

}

void TextScreen::Speech() {

}
