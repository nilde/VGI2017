#ifndef _PARTICLES
#define _PARTICLES
#include <string>
// #include "stdafx.h"
#include <stdlib.h>
#include "Particula.h"


class Particles {
public:
	const int static MAX_PARTICLES = 1;
	int ORIGIN_X;
	int ORIGIN_Y;
	int ORIGIN_Z;

	int AGE_DECREMENT;
	int VEL_DECREMENT;
	int UPDATE_VEL_X;
	int UPDATE_VEL_Y;
	int UPDATE_VEL_Z;

	Particula particle[MAX_PARTICLES];

	void draw();

	//Se define un struct con todas las propiedades de cada partícula
	//x, y, z corresponden a la posición
	//sz, sy, sz corresponden a la velocidad
	//age para controlar el recorrido en el sistema




	//Constructor
	Particles();

	void initialize();

};


#endif