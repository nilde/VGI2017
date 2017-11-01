#include "stdafx.h"
#include "AnimaController.h"
#include "escena.h"			// Include funcions d'objectes OpenGL


AnimaController::AnimaController()
{
	seguir = false;
	camara1 = Camera(rocket.xo, rocket.yo, rocket.zo, 10, 0, 0, 0);
	camara2 = Camera(rocket.xo, rocket.yo, rocket.zo, 20, 0, 0, 0);
	camara3 = Camera(rocket.xo, rocket.yo, rocket.zo, 30, 0, 0, 0);
	camara4 = Camera(rocket.xo, rocket.yo, rocket.zo, 40, 0, 0, 0);
}

bool AnimaController::Siguiendo() {
	return(seguir);
}

Camera::Camera() {

	objetivo_xo = rocket.xo;
	objetivo_yo = rocket.yo;
	objetivo_zo = rocket.zo;

	pos_xo = 10;
	pos_yo = 0;
	pos_zo = 0;

	angulo_o = 0;

	objetivo_x = objetivo_xo;
	objetivo_y = objetivo_yo;
	objetivo_z = objetivo_zo;

	pos_x = pos_xo;
	pos_y = pos_yo;
	pos_z = pos_zo;

	angulo = angulo_o;
}

void Camera::ExecuteTrayectory(float t) {
	if (!rocket.stop) {
		objetivo_x += rocket.DespX(t);
		objetivo_y += rocket.DespY(t);
		objetivo_z += rocket.DespZ(t);
		pos_x += rocket.DespX(t);
		pos_y += rocket.DespY(t);
		pos_z += rocket.DespZ(t);
	}
}