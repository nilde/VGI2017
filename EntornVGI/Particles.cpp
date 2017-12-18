#include "stdafx.h"
#include "Particles.h"
using namespace std;

void Particles::draw() {
	for (int i = 0; i < this->MAX_PARTICLES; i++) {
		this->particle[i].draw();
	}
}



void Particles::initialize() {
	//MAX_PARTICLES = 1000; Se edita en el .h
	ORIGIN_X = 1;
	ORIGIN_Y = 1;
	ORIGIN_Z = 1;

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
//Inicializa la librería GLUT i se configura la visualización en pantalla
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
glutInitWindowPosition(WINDOW_X, WINDOW_Y);
glutInitWindowSize(SIZE_X, SIZE_Y);
glutCreateWindow("Particle System");

//Define el timer de la aplicación
//El 4 es el valor en ms de la actualización
glutDisplayFunc(draw);
glutTimerFunc(4, timerCallBack, 1);
//trabaja en conjunto con glutPostRedisplay()
}
*/