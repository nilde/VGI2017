#include "stdafx.h"
#include "rocket.h"
#include <stdlib.h>
#include "math.h"

#include <iostream>


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


void Rocket::ExecuteTrayectory(int iteracion, float step, GLfloat center[3],int defective) {
	if (iteracion == max_iter) {
		az = ax = ay = 0;
	}
	if (iteracion >= max_iter - Diff_Fase  && iteracion < max_iter) {
		az = ax = 0;
		ay = 5;
		if (m_special != 90) {
			m_special++;
		}
	}
	if (iteracion == max_iter - Diff_Fase) {
		combustible = false;
	}
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

	float distancia = sqrt(m_y*m_y + m_z*m_z + m_x*m_x);
	gravity = ((Tradi *60000)/ (distancia*distancia));//((const_G * Tmassa) / (distancia*distancia));
	double real_az = 0;
	double real_ay = 0;
	if (m_z >= 0) {
		real_az = az - gravity * seno(betta);
	}
	else {
		real_az = az + gravity * seno(betta);
	}
	if (m_y >= 0) {
		if (iteracion > 100 ) {
			real_ay = ay - gravity * coseno(betta);
		}
	}
	else {
		if (iteracion > 100) {
			real_ay = ay + gravity * coseno(betta);
		}
	}
	vx = vx + ax * step;
	vy = vy + real_ay * step;
	vz = vz + real_az * step;
	if (distancia <= Tradi + 10) {
		vx = 0;
		vy = 0;
		vz = 0;
		combustible = false;
	}
	m_z = m_z + vz*step;
	m_x = m_x + vx*step;
	m_y = m_y + vy*step;
}

void Rocket::ExecuteTrayectory2(int iteracion, float step, GLfloat center[3],int defective) {
	if (iteracion == (max_iter - Diff_Fase + 50)) {
		az = ax = ay = 0;
	}
	if (iteracion == (max_iter - Diff_Fase - 10)) {
		az = -10;
		ax = 0;
		ay = 5;
		combustible = false;
	}
	if (vy != 0) {
		m_alpha = arcotangente(vz / vy);
		if (vy < 0) {
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

	float distancia = sqrt((m_y*m_y)+(m_z*m_z));
	gravity = ((Tradi * 60000) / (distancia*distancia));//((const_G * Tmassa) / (distancia*distancia));
	double real_az = 0;
	double real_ay = 0;
	if (m_z >= 0) {
		real_az = az - gravity * seno(betta);
	}
	else {
		real_az = az + gravity * seno(betta);
	}
	if (m_y >= 0) {
		if (iteracion > 100) {
			real_ay = ay - gravity * coseno(betta);
		}
	}
	else {
		if (iteracion > 100) {
			real_ay = ay + gravity * coseno(betta);
		}
	}
	vx = vx + ax * step;
	vy = vy + real_ay * step;
	vz = vz + real_az * step;
	if (distancia <= Tradi + 10) {
		vx = 0;
		vy = 0;
		vz = 0;
		combustible = false;
	}
	m_z = m_z + vz*step;
	m_x = m_x + vx*step;
	m_y = m_y + vy*step;
}

void Rocket::ExecuteTrayectory3(int iteracion, float step, GLfloat center[3],int defective) {
	if (iteracion == (max_iter - Diff_Fase + 50)) {
		az = ax = ay = 0;
	}
	if (iteracion == (max_iter - Diff_Fase - 12)) {
		az = -10;
		ax = 0;
		ay = 5;
		combustible = false;
	}
	if (vy != 0) {
		m_alpha = arcotangente(vz / vy);
		if (vy < 0) {
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

	float distancia = sqrt((m_y*m_y) + (m_z*m_z));
	gravity = ((Tradi * 60000) / (distancia*distancia));//((const_G * Tmassa) / (distancia*distancia));
	double real_az = 0;
	double real_ay = 0;
	if (m_z >= 0) {
		real_az = az - gravity * seno(betta);
	}
	else {
		real_az = az + gravity * seno(betta);
	}
	if (m_y >= 0) {
		if (iteracion > 100) {
			real_ay = ay - gravity * coseno(betta);
		}
	}
	else {
		if (iteracion > 100) {
			real_ay = ay + gravity * coseno(betta);
		}
	}
	vx = vx + ax * step;
	vy = vy + real_ay * step;
	vz = vz + real_az * step;
	if (distancia <= Tradi + 10) {
		vx = 0;
		vy = 0;
		vz = 0;
		combustible = false;
	}
	m_z = m_z + vz*step;
	m_x = m_x + vx*step;
	m_y = m_y + vy*step;
}

void Rocket::ExecuteTrayectory4(int iteracion, float step, GLfloat center[3],int defective) {
	if (iteracion == (max_iter - Diff_Fase + 50)) {
		az = ax = ay = 0;
	}
	if (iteracion == (max_iter - Diff_Fase - 13)) {
		az = -10;
		ax = 0;
		ay = 5;
		combustible = false;
	}
	if (vy != 0) {
		m_alpha = arcotangente(vz / vy);
		if (vy < 0) {
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

	float distancia = sqrt((m_y*m_y) + (m_z*m_z));
	gravity = ((Tradi * 60000) / (distancia*distancia));//((const_G * Tmassa) / (distancia*distancia));
	double real_az = 0;
	double real_ay = 0;
	if (m_z >= 0) {
		real_az = az - gravity * seno(betta);
	}
	else {
		real_az = az + gravity * seno(betta);
	}
	if (m_y >= 0) {
		if (iteracion > 100) {
			real_ay = ay - gravity * coseno(betta);
		}
	}
	else {
		if (iteracion > 100) {
			real_ay = ay + gravity * coseno(betta);
		}
	}
	vx = vx + ax * step;
	vy = vy + real_ay * step;
	vz = vz + real_az * step;
	if (distancia <= Tradi + 10) {
		vx = 0;
		vy = 0;
		vz = 0;
		combustible = false;
	}
	m_z = m_z + vz*step;
	m_x = m_x + vx*step;
	m_y = m_y + vy*step;
}

float Rocket::get_altura() {
	return sqrt(m_z*m_z + m_y*m_y);
}


void Rocket::Initialize() {
	float angle = 90; // entre 0 y 90
	float impulse = 14;

	xo = 71;
	yo = -59.5;
	zo = 6375;

	combustible = false;

	m_x = xo;
	m_y = yo;
	m_z = zo;
	m_alpha = angle;
	m_special = 0;

	vx = vz = vy = 0;

	ax = 0;
	auto a = seno(angle);
	az = impulse * seno(angle);
	ay = impulse * coseno(angle);

}





void Rocket::Restart(){
	Initialize();
}

void Rocket::setGravity(float actualGravity) {
	gravity = actualGravity;
}
void Rocket::setPropellant(int propellantType) {
	if (propellantType == 1) {
		propellantBonus = 1.0;
	}
	else {
		if (propellantType == 2) {
			propellantBonus = 1.5;
		}
		else {
			propellantBonus = 2.0;
		}
	}
	


}