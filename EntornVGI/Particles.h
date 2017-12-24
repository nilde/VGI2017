#ifndef _PARTICLES
#define _PARTICLES
#include <string>
#include "stdafx.h"
#include <stdlib.h>


//Se define un struct con todas las propiedades de cada partícula
//x, y, z corresponden a la posición
//sz, sy, sz corresponden a la velocidad
//age para controlar el recorrido en el sistema
struct PARTICLE {
	float x, y, z;
	float sx, sy, sz;
	float age;
};



class Particles {
public:
	const int static MAX_PARTICLES = 1000;
	int ORIGIN_X;
	int ORIGIN_Y;
	int ORIGIN_Z;

	int AGE_DECREMENT;
	int VEL_DECREMENT;
	int UPDATE_VEL_X;
	int UPDATE_VEL_Y;
	int UPDATE_VEL_Z;
	bool initial=true;
	

	//Constructor
	Particles();
	Particles(int typeOfParticles);

	void initialize(int typeOfParticles);
	int random(std::string valueToRandomize);
	void create(int i);
	void evolve(int i);
	void evolveClouds(int i);

	void draw(int size,int typeOfParticles);
private:
	PARTICLE particle[MAX_PARTICLES];

};


#endif