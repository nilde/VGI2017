#pragma once
class Planet
{
public:
	Planet();
	Planet(float radius);
	Planet(float x, float y, float z, float radius);
	~Planet();

	float radius;
	GLfloat center[3];
};

