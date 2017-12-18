#include "stdafx.h"
#include "Particula.h"


Particula::Particula()
{
	x = 0;
	y = 0;
	z = 0;
	sx = 0;
	sy = 0;
	sz = 0;
	age = -1;
	ox = 0.5;
	oy = 0.5;
	oz = 0.5;
}


int Particula::random(std::string valueToRandomize) {
	int output = 0;
	int max = 1;
	int min = 0;

	if (valueToRandomize == "age") {
		//min = 3000000;
		//max = 4000000;
		min = 10;
		max = 1;
	}
	else if (valueToRandomize == "speedX") {
		min = 1;
		max = 20;
	}
	else if (valueToRandomize == "speedY") {
		min = 300;
		max = 400;
	}

	else if (valueToRandomize == "speedZ") {
		min = 1;
		max = 20;
	}
	else {
		return 0;
	}

	return output = min + (rand() % static_cast<int>(max - min + 1));
}



Particula::~Particula()
{
}

void Particula::Create()
{
	age = random("age");
	x = ox;
	y = oy;
	z = oz;
	sx = random("speedX");
	sy = random("speedY");
	sz = random("speedZ");
}



//Se calcula la evolución de las partículas teniendo en cuenta la fórmula
// NextPosition = CurrentPosition + (Speed * UpdateSpeed) 
void Particula::evolve() {

	z = z + 0.3;
	age--;

	/*
	particle[i].age = particle[i].age - AGE_DECREMENT;

	//	Desactivado temporalmente la actualización para encontrar el error
	particle[i].x = particle[i].x + (particle[i].sx * UPDATE_VEL_X);
	particle[i].y = particle[i].y + (particle[i].sy * UPDATE_VEL_Y);
	particle[i].z = particle[i].z + (particle[i].sz * UPDATE_VEL_Z);


	particle[i].sy = particle[i].sy - VEL_DECREMENT;
	*/
}

//Bucle para dibujar en pantalla los diferentes puntos que componen
//el sistema de partículas. Para ello crea los puntos y los va
//evolucionando para que pueda existir un movimiento
void Particula::draw() {
	if (age < 0) {
		Create();
	}else{
			glPointSize(10);
			glBegin(GL_POINTS);
			glVertex3f(x, y, z);
			glEnd();
		evolve();
	}

}