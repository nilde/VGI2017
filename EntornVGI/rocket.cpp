
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
	vxo = 10;
	vzo = 200;

	vx = vxo;
	vy = vyo;
	vz = vzo;

	ax = 0;
	ay = 0;
	ax = -9.8;
}


void Rocket::ExecuteTrayectory(float t) {
	m_z = zo + vzo*t + az*t*t / 2;
	m_x = xo + vx*t;

	if (m_z < 0) {
		stop = true;
	}
}

bool Rocket::Stoped() {
	return(stop);
}

void Rocket::Restart() {
	
	Rocket();

}