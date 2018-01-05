#include "stdafx.h"
#include "rocket.h"
#include <stdlib.h>
#include "math.h"

#include <iostream>
using namespace std;

#define PI 3.14159265


Rocket::Rocket()
{
	Initialize();
}

float seno(float x) {
	return sin(x*PI / 180);
}

float coseno(float x) {
	return cos(x*PI / 180);
}

float arcotangente(float x) {
	return (atan(x)*(180/PI));
}


void Rocket::ExecuteTrayectory(int iteracion, float step, GLfloat center[3]) {
	if (iteracion == max_iter) {
		az = ax = ay = 0;
	}
	if (iteracion == max_iter - 200) {
		az = ax = 0;
		ay = 14;

	}

	if (iteracion == max_iter - 222) {
		combustible = false;
	}


	float dy =  center[1] - m_y;
	float dz =  center[2] - m_z;


	if (vy != 0) {
		m_alpha = arcotangente(vz/vy);
		if ( vy < 0 ){
			m_alpha = m_alpha + 180;
		}
	}

	float betta;

	if (m_y != 0) {
		betta = arcotangente(float(abs(m_z)) / float(abs(m_y)));
	}
	else {
		betta = 90;
	}

	float distancia = sqrt(dy*dy + dz*dz);

	float real_az = 0;
	float real_ay = 0;
	if (m_z >= 0) {
		real_az = az - 9.8 * seno(betta);
	}
	else {
		real_az = az + 9.8 * seno(betta);
	}
	if (m_y >= 0) {
		if (iteracion > 200 ) {
			real_ay = ay - 9.8 * coseno(betta);
		}
		
	}
	else {
		if (iteracion > 200) {
			real_ay = ay + 9.8 * coseno(betta);
		}
	}
	vx = vx + ax * step;
	vy = vy + real_ay * step;
	vz = vz + real_az * step;

	m_z = m_z + vz*step;
	m_x = m_x + vx*step;
	m_y = m_y + vy*step;
}

float Rocket::get_altura() {
	return sqrt(m_z*m_z + m_y*m_y);
}


void Rocket::Initialize() {
	float angle = 90; // entre 0 y 90
	float impulse = 12;

	max_iter = 600;

	xo = 71;
	yo = -59.5;
	zo = 6371;
	//zo = yo = xo = 0;

	combustible = false;

	m_x = xo;
	m_y = yo;
	m_z = zo;
	m_alpha = angle;

	vx = vz = vy = 0;

	ax = 0;
	auto a = seno(angle);
	az = impulse * seno(angle);
	ay = impulse * coseno(angle);

}





void Rocket::Restart(){
	Initialize();
}
