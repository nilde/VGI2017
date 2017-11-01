#include "stdafx.h"
#include "rocket.h"

Rocket::Rocket()
{
	stop = false;

	xo = 0;
	yo = 0;
	zo = 0;

	m_x = xo;
	m_y = yo;
	m_z = zo;
	m_alpha = 0;

	vyo = 0;
	vxo = 0;
	vzo = 50;

	vx = vxo;
	vy = vyo;
	vz = vzo;

	ax = 0;
	ay = 0;
	az = -9.8;
}

float Rocket::DespZ(float t) {
	return (vzo*t + az*t*t / 2);
}

float Rocket::DespX(float t) {
	return(vx*t);
}

float Rocket::DespY(float t) {
	return(0);
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
	
	Rocket();

}