#ifndef _PARTICLES
#define _PARTICLES
#include <string>
#include "stdafx.h"
#include <stdlib.h>



class Particles {
public:
	const int static MAX_PARTICLES = 5;
	int ORIGIN_X;
	int ORIGIN_Y;
	int ORIGIN_Z;

	float alpha = 0.6;

	int AGE_DECREMENT;
	int VEL_DECREMENT;
	int UPDATE_VEL_X;
	int UPDATE_VEL_Y;
	int UPDATE_VEL_Z;

	int output = 0;
	int max = 1;
	int min = 0;

	int red_min = 80;
	int red_max = 100;
	int green_min = 0;
	int green_max = 50;
	int blue_min = 1;
	int blue_max = 3;
	int age_min = 1;
	int age_max = 50;
	int sx_min = -50;
	int sx_max = 50;
	int sy_min = -200;
	int sy_max = -100;
	int sz_min = -50;
	int sz_max = 50;
	int size_min = 1;
	int size_max = 10;



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