#pragma once
#include "include\obj.h"
class ObjChar :
	public Obj
{
public:
	ObjChar(double x, double y);
	~ObjChar(void);

	void onStep();
};

