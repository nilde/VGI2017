#include "stdafx.h"
#include "rocket.h"
#include <stdlib.h>
#include "math.h"

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

	if (iteracion == 200) {
		az = ax = ay = 0;
	}

	float dy =  center[1] - m_y;
	float dz =  center[2] - m_z;


	if (dy != 0) {
		m_alpha = arcotangente(dz/dy);
	}
	else {
		if (m_z > center[2]) {
			m_alpha = 90;
		}
		else if(m_z < center[2]){
			m_alpha = 270;
		}
		else {
			m_alpha = 0;
		}
	}

	float distancia = sqrt(dy*dy + dz*dz);

	float real_az = az - 1.2 * seno(m_alpha);
	float real_ay = ay - 1.2 * coseno(m_alpha);



	vx = vx + ax * step;
	vy = vy + real_ay * step;
	vz = vz + real_az * step;

	m_z = m_z + vz*step;
	m_x = m_x + vx*step;
	m_y = m_y + vy*step;

	



}


void Rocket::Initialize() {
	float angle = 70; // entre 0 y 90
	float impulse = 2;

	xo = 0;
	yo = 0;
	zo = 5;

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
