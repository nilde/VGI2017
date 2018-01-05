#include "stdafx.h"
#include "constants.h"
#include "AnimaController.h"
#include "escena.h"			// Include funcions d'objectes OpenGL


AnimaController::AnimaController()
{
	reader = Reader("./../fitxerAModificar.txt");
	rocket = Rocket();
	planet = Planet(6371);
	


	// modificamos los par�metros de las part�culas de humo

	humo.red_min = 90;
	humo.red_max = 100;
	humo.green_min = 90;
	humo.green_max = 100;
	humo.blue_min = 90;
	humo.blue_max = 100;
	humo.age_min = 200;
	humo.age_max = 600;
	humo.sx_min = -50;
	humo.sx_max = 50;
	humo.sy_min = -350;
	humo.sy_max = -50;
	humo.sz_min = -50;
	humo.sz_max = 50;
	humo.size_min = 20;
	humo.size_max = 30;
	humo.alpha = 0.45;


}
