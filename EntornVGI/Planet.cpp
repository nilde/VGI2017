#include "stdafx.h"
#include "Planet.h"


Planet::Planet()
{
	radius = 1000;
	center[0] = 0;
	center[1] = 0;
	center[2] = 0;
}

Planet::Planet(float r) {
	radius = r;
	center[0] = 0;
	center[1] = 0;
	center[2] = 0;
}

Planet::Planet(float x, float y, float z, float r) {
	radius = r;
	center[0] = x;
	center[1] = y;
	center[2] = z;

}



Planet::~Planet()
{
}
