#include "stdafx.h"
#include "rocket.h"

Rocket::Rocket()
{
	Initialize();
}

float Rocket::DespZ(float t) {
	return (vzo*t + az*t*t / 2);
}

float Rocket::DespX(float t) {
	return(vx*t);
}

float Rocket::DespY(float t) {
	return(vy*t);
}


void Rocket::ExecuteTrayectory(float t) {
	m_z = zo + DespZ(t);
	m_x = xo + DespX(t);
	m_y = yo + DespY(t);

	if (m_z < 0) {
		stop = true;
	}
}


void Rocket::Restart() {
	Initialize();
}

void Rocket::Initialize() {
	stop = false;

	xo = 0;
	yo = 0;
	zo = 2;

	m_x = xo;
	m_y = yo;
	m_z = zo;
	m_alpha = 0;

	vxo = 10;
	vyo = 00;
	vzo = 30;

	vx = vxo;
	vy = vyo;
	vz = vzo;

	ax = 0;
	ay = 0;
	az = -9.8;
}