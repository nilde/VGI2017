#include "stdafx.h"
#include "Planet.h"


Planet::Planet()
{
	size = 1000;
	center[0] = 0;
	center[1] = 0;
	center[2] = -size;
}

Planet::Planet(float _size) {
	size = _size;
	center[0] = 0;
	center[1] = 0;
	center[2] = -size;
}

Planet::Planet(float x, float y, float z, float _size) {
	center[0] = x;
	center[1] = y;
	center[2] = z;
	size = _size;
}



Planet::~Planet()
{
}
