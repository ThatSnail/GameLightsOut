#include "SprSolid.h"
#include "include\HResources.h"
#include <iostream>
SprSolid::SprSolid() : Spr()
{
	image = HResources::SPR_SOLID;
	imageCount = 1;
	setup();
	setOriginTopLeft();
	setHitboxFull(HITBOX_RECTANGLE);
}


SprSolid::~SprSolid(void)
{
}
