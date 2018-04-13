#include "NPC2.h"

NPC2::NPC2() {
	mGraphics = Graphics::Instance();
	mNPC2 = new Texture("NPC2.png", 0, 0, 32, 32);
	mTex = mNPC2;
}

void NPC2::Text() {
	SetRow(8);
	SetCol(0);
}

void NPC2::Update()
{
}

NPC2::~NPC2()
{
}
