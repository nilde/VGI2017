#pragma once
#include <string>
#include <stdlib.h>

class Particula
{
public:
	float x, y, z;
	float sx, sy, sz;
	float age;
	float ox, oy, oz;

	Particula();
	~Particula();

	void Create();

	int random(std::string valueToRandomize);

	void evolve();
	void draw();
};

