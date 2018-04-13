#include "Oak.h"

Oak::Oak(){
	mGraphics = Graphics::Instance();
	mOak = new Texture("OAK.png", 0, 0, 51, 54);
	mTex = mOak;
}

void Oak::Text() {
	SetRow(0);
	SetCol(1);
}

Oak::~Oak()
{
}
