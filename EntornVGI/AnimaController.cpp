#include "stdafx.h"
#include "constants.h"
#include "AnimaController.h"
#include "escena.h"			// Include funcions d'objectes OpenGL


AnimaController::AnimaController()
{
	rocket = Rocket();
	planet = Planet(6371);
}


