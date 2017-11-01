#pragma once


class Camera {
public:
	float objetivo_x;
	float objetivo_y;
	float objetivo_z;

	float pos_x;
	float pos_y;
	float pos_z;

	float objetivo_xo;
	float objetivo_yo;
	float objetivo_zo;

	float pos_xo;
	float pos_yo;
	float pos_zo;

	float angulo;
	float angulo_o;

	Camera(float n_0, float n_1, float n_2, float xx, float yy, float zz, float ang);
	Camera();

	void ExecuteTrayectory(float t);

};


class AnimaController {
public:
	AnimaController();

	void ExecuteTrayectory(float t);

	bool Siguiendo();

	bool seguir;

	Camera camaras[5];

	int camara_activa = 0;

	const float TSTEP = 0.01;
	const float TIMER = 10; // milisegundos
	
};

