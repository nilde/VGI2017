#pragma once
#include "rocket.h"
#include "Planet.h"
#include "Particles.h"
#include "clouds.h"



class AnimaController {
public:
	AnimaController();
	//~AnimaController();

	void generateStructuresForClouds();
	Rocket rocket;
	Planet planet;
	Clouds clouds;

	Particles particles;

	char activePlanet = CAP;
	char activeRocket = '1';

	bool seguir = true;

	bool esferica = true;

	char lookat = ROCKET;

	int step;

	const float TSTEP = 0.1;
	const float TIMER = 100; // milisegundos

};

