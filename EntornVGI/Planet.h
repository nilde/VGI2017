#pragma once
class Planet
{
public:
	Planet();
	Planet(float _size);
	Planet(float x, float y, float z, float size);
	~Planet();

	float size;
	GLfloat center[3];
};

