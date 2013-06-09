#include "ObjSolid.h"
#include "SprSolid.h"


ObjSolid::ObjSolid(double x, double y) : Obj(x, y)
{
	objectType = OBJ_SOLID;
	sprite = new SprSolid();
}


ObjSolid::~ObjSolid(void)
{
	delete sprite;
}
