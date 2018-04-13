#include "NPC1.h"

NPC1::NPC1() {
	mGraphics = Graphics::Instance();
	mNPC1 = new Texture("NPC#1.png", 0, 0, 32, 32);
	mTex = mNPC1;
}

void NPC1::Text() {
	SetRow(7);
	SetCol(0);
}

void NPC1::Update()
{
}

NPC1::~NPC1()
{
}
