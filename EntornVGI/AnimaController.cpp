#include "stdafx.h"
#include "AnimaController.h"
#include "escena.h"			// Include funcions d'objectes OpenGL


AnimaController::AnimaController()
{
	seguir = false;
	camaras[0] = Camera(rocket.xo, rocket.yo, rocket.zo, 10, 10, 10, 110);
	camaras[1] = Camera(rocket.xo, rocket.yo, rocket.zo, 10, 10, 10, 110);
	camaras[2] = Camera(rocket.xo, rocket.yo, rocket.zo, 100, 0, 0, 100);
	camaras[3] = Camera(rocket.xo, rocket.yo, rocket.zo, 100, 100, 0, 0);
	camaras[4] = Camera(rocket.xo, rocket.yo, rocket.zo, 10, 100, 20, 100);
}

void AnimaController::ExecuteTrayectory(float t) {
	camaras[camara_activa].ExecuteTrayectory(t);
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

Camera::Camera(float n_0, float n_1, float n_2, float xx, float yy, float zz, float ang) {
	objetivo_xo = n_0;
	objetivo_yo = n_1;
	objetivo_zo = n_2;
	pos_xo = xx;
	pos_yo = yy;
	pos_zo = zz;
	angulo_o = ang;
	objetivo_x = objetivo_xo;
	objetivo_y = objetivo_yo;
	objetivo_z = objetivo_zo;
	pos_x = pos_xo;
	pos_y = pos_yo;
	pos_z = pos_zo;
	angulo = angulo_o;
}

void Camera::ExecuteTrayectory(float t) {
		objetivo_x = objetivo_xo + rocket.DespX(t);
		objetivo_y = objetivo_yo + rocket.DespY(t);
		objetivo_z = objetivo_zo + rocket.DespZ(t);
		pos_x = pos_xo + rocket.DespX(t);
		pos_y = pos_yo + rocket.DespY(t);
		pos_z = pos_zo + rocket.DespZ(t);
}