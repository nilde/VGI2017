#pragma once
#include "rocket.h"
#include "Planet.h"
#include "Particles.h"
#include "clouds.h"
#include "cities.h"
#include "reader.h"

const int numActivePointsCat = 111250;
const int numTrueActivePoints = 5000;

class AnimaController {
public:

	int count = 0;

	AnimaController();
	Rocket rocket;
	Rocket rocket2;
	Rocket rocket3;
	Rocket rocket4;
	Planet planet;
	Clouds clouds;
	Cities cities;
	Reader reader;

	Particles fuego;
	Particles humo;
	Particles fuegoDefectuoso;
	Particles onCrash;

	char activePlanet;
	char activeRocket;
	bool activeFractal;
	float speedup;
	int defective;

	bool seguir = true;

	bool esferica = true;

	bool multiView = false;

	char lookat = ROCKET;

	int step;
	int moved;
	
	//matrix for the respectives heights of Catalunya map
	double matrixContainer[FMAX + 1][FMAX + 1];
	int matrixPointsCoords[numActivePointsCat][3];
	


	const float TSTEP = 0.1;
	const float TIMER = 100; // milisegundos

};

