#include "stdafx.h"
#include "Particles.h"
using namespace std;


int Particles::random(string valueToRandomize) {
	int output = 0;
	int max = 1;
	int min = 0;

	if (valueToRandomize == "age") {
		min = 1;
		max = 50;
	}
	else if (valueToRandomize == "speedX") {
		min = -3;
		max = 1;
	}
	else if (valueToRandomize == "speedY") {
		min = -1;
		max = 1;
	}

	else if (valueToRandomize == "speedZ") {
		min = -1;
		max = 1;
	}
	else if (valueToRandomize == "size") {
		min = 0.0001;
		max = 1.0;
	}

	return output = min + (rand() % static_cast<int>(max - min + 1));
}


//Inicializa las part�culas en el punto (0,0,0) y da una velocidad
//diferente y un tiempo de vida diferente a cada una
void Particles::create(int i) {

	particle[i].age = random("age");
	particle[i].x = 0; // ORIGIN_X;
	particle[i].y = 0; // ORIGIN_Y;
	particle[i].z = 0; // ORIGIN_Z;
	particle[i].sx = random("speedX");
	particle[i].sy = random("speedY");
	particle[i].sz = random("speedZ");
}

//Se calcula la evoluci�n de las part�culas teniendo en cuenta la f�rmula
// NextPosition = CurrentPosition + (Speed * UpdateSpeed) 
void Particles::evolve(int i) {

	particle[i].age = particle[i].age - AGE_DECREMENT;

	//Desactivado temporalmente la actualizaci�n para encontrar el error
	particle[i].x = particle[i].x + (particle[i].sx * UPDATE_VEL_X);
	particle[i].y = particle[i].y + (particle[i].sy * UPDATE_VEL_Y);
	particle[i].z = particle[i].z + (particle[i].sz * UPDATE_VEL_Z);

	particle[i].sx = particle[i].sx - VEL_DECREMENT;
	particle[i].sy = particle[i].sy - VEL_DECREMENT;
	particle[i].sz = particle[i].sz - VEL_DECREMENT;
}

//Bucle para dibujar en pantalla los diferentes puntos que componen
//el sistema de part�culas. Para ello crea los puntos y los va
//evolucionando para que pueda existir un movimiento
void Particles::draw() {

	for (int i = 0; i < MAX_PARTICLES; i++) {
		if (particle[i].age < 0) {
			create(i);
		}
		else {
			glPointSize(random("size"));
			glBegin(GL_POINTS);
			glVertex3f(particle[i].x,particle[i].y, particle[i].z);
			glEnd();
		}
		evolve(i);
	}
}

void Particles::initialize() {
	//MAX_PARTICLES = 1000; Se edita en el .h
	ORIGIN_X = 0;
	ORIGIN_Y = 0;
	ORIGIN_Z = 0;

	AGE_DECREMENT = 2;
	VEL_DECREMENT = 2;
	UPDATE_VEL_X = 2;
	UPDATE_VEL_Y = 2;
	UPDATE_VEL_Z = 2;



}

Particles::Particles()
{
	initialize();
}



/*
int main(int argc, char** argv)
{
//Inicializa la librer�a GLUT i se configura la visualizaci�n en pantalla
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
glutInitWindowPosition(WINDOW_X, WINDOW_Y);
glutInitWindowSize(SIZE_X, SIZE_Y);
glutCreateWindow("Particle System");

//Define el timer de la aplicaci�n
//El 4 es el valor en ms de la actualizaci�n
glutDisplayFunc(draw);
glutTimerFunc(4, timerCallBack, 1);
//trabaja en conjunto con glutPostRedisplay()
}
*/