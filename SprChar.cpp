#include "SprChar.h"
#include "include\HResources.h"
#include <iostream>

SprChar::SprChar(void) : Spr()
{
	image = HResources::SPR_CHAR;
	imageCount = 1;
	setup();
	setOriginCenter();
	setHitboxFull(HITBOX_RECTANGLE);
}


SprChar::~SprChar(void)
{
}
