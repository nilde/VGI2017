#pragma once
#include "rocket.h"
#include "Planet.h"

class AnimaController {
public:
	AnimaController();

	Rocket rocket;
	Planet planet;

	char activePlanet = CAP;
	char activeRocket = '1';

	bool seguir = true;

	bool esferica = true;

	char lookat = ROCKET;

	const float TSTEP = 0.1;
	const float TIMER = 5; // milisegundos
	
};

