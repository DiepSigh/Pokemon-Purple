#include "NPC.h"

NPC::NPC()
{
}

void NPC::Render(){//allows for renders NPC.png image
	GetmTex()->SetRenderRectX(GetPosX());
	GetmTex()->SetRenderRectY(GetPosY());

	mGraphics->DrawTexture(GetmTex()->GetSDLTex(), (GetmTex()->GetClipped()) ? & GetmTex()->GetmClipRect() : NULL, &GetmTex()->GetmRenderRect());
}

bool NPC::Talk()
{
	return false;
}

bool NPC::WalkRoute()
{
	return false;
}

bool NPC::isTrainer()
{
	return false;
}

bool NPC::LoseBattle()
{
	return false;
}

NPC::~NPC()
{
}
