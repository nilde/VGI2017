
#include "stdafx.h"
#include "rocket.h"

Rocket::Rocket()
{
	int m_x = 0;
	int m_y = 0;
	int m_z = 2.5;
	int m_alpha = 0;
}

void Rocket::calculateCoords()
{
}

void Rocket::incX()
{
	m_x++;
}
void Rocket::decX()
{
	m_x--;
}
void Rocket::incY()
{
	m_y++;
}
void Rocket::decY()
{
	m_y--;
}
void Rocket::incZ()
{
	m_z++;
}
void Rocket::decZ()
{
	m_z--;
}
void Rocket::incAlpha()
{
	m_alpha++;
}