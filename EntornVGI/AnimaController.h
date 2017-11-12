#pragma once
#include "rocket.h"
#include "Planet.h"

class AnimaController {
public:
	AnimaController();


	Rocket rocket;
	Planet planet;

	const float TSTEP = 0.1;
	const float TIMER = 5; // milisegundos
	
};

