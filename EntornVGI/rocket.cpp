
#include "stdafx.h"
#include "rocket.h"

Rocket::Rocket()
{
	float m_x = 0;
	float m_y = 0;
	float m_z = 30;
	float m_alpha = 0;
}

float  Rocket::get_x() {
	return m_x;
}
float  Rocket::get_y() {
	return m_y;
}
float  Rocket::get_z() {
	return m_z;
}
float  Rocket::get_alpha() {
	return m_alpha;
}

void Rocket::calculateCoords()
{
}

void Rocket::set_x(int x) {
	m_x = x;
}
void Rocket::set_y(int y) {
	m_y = y;
}
void Rocket::set_z(int z) {
	m_z = z;
}
void Rocket::set_alpha(float alpha) {
	m_alpha = alpha;
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
void Rocket::decAlpha()
{
	m_alpha--;
}