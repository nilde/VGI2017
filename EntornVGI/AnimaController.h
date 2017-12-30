#pragma once
#include "rocket.h"
#include "Planet.h"
#include "Particles.h"
#include "clouds.h"



class AnimaController {
public:

	int count = 0;

	AnimaController();
	//~AnimaController();

	void generateStructuresForClouds();
	Rocket rocket;
	Planet planet;
	Clouds clouds;

	Particles fuego;
	Particles humo;

	char activePlanet = CAP;
	char activeRocket = '1';

	bool seguir = true;

	bool esferica = true;

	bool multiView = false;

	char lookat = ROCKET;

	int step;

	const float TSTEP = 0.1;
	const float TIMER = 100; // milisegundos

};

