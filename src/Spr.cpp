#include "Spr.h"
#include <iostream>

Spr::Spr()
{
	imageCount = 1;
	hitbox = sf::Rect<int>();

	tex = new sf::Texture();
}


Spr::~Spr(void)
{
	delete tex;
}

void Spr::setOriginCenter()
{
	if(image!=NULL)
	{
		origX = imageWidth / 2;
		origY = imageHeight / 2;
	}
}

void Spr::setHitboxFull(HitboxType hitboxType)
{
	this->hitboxType = hitboxType;

	if(image != NULL)
	{
		hitbox = sf::Rect<int>(0, 0, imageWidth, imageHeight);
	}
}

void Spr::setOriginTopLeft()
{
	origX = 0;
	origY = 0;
}

void Spr::setup()
{
	int xx = image->getSize().x;
	int yy = image->getSize().y;
	imageWidth = xx / imageCount;
	imageHeight = yy;
	tex->loadFromImage(*image);
}

void Spr::setHitbox(int x1, int y1, int x2, int y2, HitboxType type)
{
	hitboxType = type;
    hitbox = sf::Rect<int>(x1, y1, x2, y2);
}

sf::Rect<double> Spr::getTransformedHitbox(double x, double y)
{
	sf::Rect<double> transformedHitbox = sf::Rect<double>(x + hitbox.left - origX,
                                                          y + hitbox.top - origY,
														  x + hitbox.left + hitbox.width - origX,
														  y + hitbox.top + hitbox.height - origY);
    return transformedHitbox;
}
