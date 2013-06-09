#include "ObjChar.h"
#include "SprChar.h"


ObjChar::ObjChar(double x, double y) : Obj(x, y)
{
	objectType = OBJ_CHAR;
	sprite = new SprChar();

	gravityDirection = 270;
}

ObjChar::~ObjChar(void)
{
	delete sprite;
}

void ObjChar::onStep()
{
	Obj::onStep();
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if(!isCollidingAt(x - 2, y, OBJ_SOLID))
		{
			x -= 2;
		}
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if(!isCollidingAt(x + 2, y, OBJ_SOLID))
		{
			x += 2;
		}
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if(isCollidingAt(x, y + 1, OBJ_SOLID))
		{
			vspeed = -12;
		}
	}
	if(isCollidingAt(x, y + 1, OBJ_SOLID))
	{
		gravity = 0;
	}
	else
	{
		gravity = 1;
	}
	/*
	if(isCollidingAt(x, y, OBJ_SOLID))
	{
		moveContact(90, abs(vspeed), Obj::OBJ_SOLID);
		vspeed = 0;
	}
	*/
}