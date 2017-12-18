#include "stdafx.h"
#include "AnimaController.h"
#include "escena.h"			// Include funcions d'objectes OpenGL


AnimaController::AnimaController()
{
	rocket = Rocket();
	planet = Planet(6371);
}

void AnimaController::DrawHumo()
{
		particula1.draw();
}
