#include "Mom.h"

Mom::Mom() {
	mGraphics = Graphics::Instance();
	mMom = new Texture("MOM.png", 0, 0, 32, 32);
	mTex = mMom;
}

void Mom::Text() {
	SetRow(5);
	SetCol(26);
}

Mom::~Mom()
{
}
