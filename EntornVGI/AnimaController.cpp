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

	fuego1.red_min = 80;
	fuego1.red_max = 100;
	fuego1.green_min = 1;
	fuego1.green_max = 100;
	fuego1.blue_min = 1;
	fuego1.blue_max = 10;

	fuego2.red_min = 80;
	fuego2.red_max = 100;
	fuego2.green_min = 3;
	fuego2.green_max = 100;
	fuego2.blue_min = 1;
	fuego2.blue_max = 10;

	fuego3.red_min = 80;
	fuego3.red_max = 96;
	fuego3.green_min = 20;
	fuego3.green_max = 87;
	fuego3.blue_min = 1;
	fuego3.blue_max = 10;

	fuego4.red_min = 80;
	fuego4.red_max = 90;
	fuego4.green_min = 3;
	fuego4.green_max = 88;
	fuego4.blue_min = 1;
	fuego4.blue_max = 10;

	fuego5.red_min = 70;
	fuego5.red_max = 100;
	fuego5.green_min = 2;
	fuego5.green_max = 90;
	fuego5.blue_min = 1;
	fuego5.blue_max = 10;

	fuego6.red_min = 90;
	fuego6.red_max = 100;
	fuego6.green_min = 40;
	fuego6.green_max = 80;
	fuego6.blue_min = 2;
	fuego6.blue_max = 30;

	fuego1.red_min = 80;
	fuego1.red_max = 100;
	fuego1.green_min = 0;
	fuego1.green_max = 100;
	fuego1.blue_min = 1;
	fuego1.blue_max = 10;




	fuego1.ORIGIN_Y = 200;
	fuego1.ORIGIN_X = 400;
	fuego1.ORIGIN_Z = -100;

	fuego2.ORIGIN_Y = 200;
	fuego2.ORIGIN_X = -400;
	fuego2.ORIGIN_Z = -100;

	fuego3.ORIGIN_Y = 200;
	fuego3.ORIGIN_X = 0;
	fuego3.ORIGIN_Z = 400;

	fuego4.ORIGIN_Y = 200;
	fuego4.ORIGIN_X = 0;
	fuego4.ORIGIN_Z = -1200;

	fuego5.ORIGIN_Y = 200;
	fuego5.ORIGIN_X = 950;
	fuego5.ORIGIN_Z = -1100;

	fuego6.ORIGIN_Y = 200;
	fuego6.ORIGIN_X = -950;
	fuego6.ORIGIN_Z = -1100;


}
