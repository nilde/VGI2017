#ifndef _PARTICLES
#define _PARTICLES
#include <string>
#include "stdafx.h"
#include <stdlib.h>



class Particles {
public:
	const int static MAX_PARTICLES = 100;
	int ORIGIN_X;
	int ORIGIN_Y;
	int ORIGIN_Z;

	int AGE_DECREMENT;
	int VEL_DECREMENT;
	int UPDATE_VEL_X;
	int UPDATE_VEL_Y;
	int UPDATE_VEL_Z;

	//Se define un struct con todas las propiedades de cada partícula
	//x, y, z corresponden a la posición
	//sz, sy, sz corresponden a la velocidad
	//age para controlar el recorrido en el sistema
	struct PARTICLE {
		float x, y, z;
		float sx, sy, sz;
		float age;
	} particle[MAX_PARTICLES];


	//Constructor
	Particles();

	void initialize();
	int random(std::string valueToRandomize);
	void create(int i);
	void evolve(int i);
	void draw();

};


#endif