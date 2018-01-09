#include "stdafx.h"
#include "constants.h"
#include "AnimaController.h"
#include "escena.h"			// Include funcions d'objectes OpenGL


AnimaController::AnimaController()
{
	reader = Reader("./../fitxerAModificar.txt");
	rocket = Rocket();
	rocket2 = Rocket();
	rocket3 = Rocket();
	rocket4 = Rocket();
	rocket.setGravity(reader.getGravityPlanet());

	activeRocket = reader.getRocketType();
	char planetReader = reader.getPlanetType();
	switch (planetReader)
	{
	case '1':
		activePlanet = TIERRA;
		break;
	case '2':
		activePlanet = MARTE;
		break;
	case '3':
		activePlanet = LUNA;
		break;
	default:
		activePlanet = TIERRA;
		break;
	}
	speedup = atof(reader.speedup.c_str());
	defective = atoi(reader.defective.c_str());
	rocket.setPropellant(atoi(reader.propellantType.c_str()));
	planet = Planet(6371);


	// modificamos los par�metros de las part�culas de humo

	humo.red_min = 90;
	humo.red_max = 100;
	humo.green_min = 90;
	humo.green_max = 100;
	humo.blue_min = 90;
	humo.blue_max = 100;
	humo.age_min = 10;
	humo.age_max = 777;
	humo.sx_min = -20;
	humo.sx_max = 20;
	humo.sy_min = -800;
	humo.sy_max = -100;
	humo.sz_min = -20;
	humo.sz_max = 20;
	humo.size_min = 20;
	humo.size_max = 30;
	humo.alpha = 0.45;


}
