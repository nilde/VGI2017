#include <iostream>
#include <GL/glew.h>
#include <GL\glut.h>
#include <iostream>
#include <string>
#include <stdlib.h> 

using namespace std;

//#pragma comment(lib, "glut32.lib")
//#define WINDOW_TITLE "Project"
//using namespace std;

const int WINDOW_X = 800;
const int WINDOW_Y = 800;
const int SIZE_X = 100;
const int SIZE_Y = 100;
const int MAX_PARTICLES = 100;
const int ORIGIN_X = 0;
const int ORIGIN_Y = 0;
const int ORIGIN_Z = 0;

const int AGE_DECREMENT = 2;
const int VEL_DECREMENT = 2;
const int UPDATE_VEL_X = 2;
const int UPDATE_VEL_Y = 2;
const int UPDATE_VEL_Z = 2;


//Se define un struct con todas las propiedades de cada partícula
//x, y, z corresponden a la posición
//sz, sy, sz corresponden a la velocidad
//age para controlar el recorrido en el sistema
struct PARTICLE {
	float x, y, z;
	float sx, sy, sz;
	float age;
} particle[MAX_PARTICLES];


//Crea valores random en unos parámetros determinados según lo que se quiere randomizar
int random(string valueToRandomize) {
	
	int output = 0;
	int max = 1;
	int min = 0;

	if (valueToRandomize == "age") {
		min = 3000;
		max = 4000;
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

	return output = min + (rand() % static_cast<int>(max - min + 1))
}


//Inicializa las partículas en el punto (0,0,0) y da una velocidad
//diferente y un tiempo de vida diferente a cada una
void create(int i) {

	particle[i].age = random("age");
	particle[i].x = ORIGIN_X;
	particle[i].y = ORIGIN_Y;
	particle[i].z = ORIGIN_Z;
	particle[i].sx = random("speedX");
	particle[i].sy = random("speedY");
	particle[i].sz = random("speedZ");
}

//Se calcula la evolución de las partículas teniendo en cuenta la fórmula
// NextPosition = CurrentPosition + (Speed * UpdateSpeed) 
void evolve(int i) {

	particle[i].age = particle[i].age - AGE_DECREMENT;
	particle[i].x = particle[i].x + (particle[i].sx * UPDATE_VEL_X);
	particle[i].y = particle[i].y + (particle[i].sy * UPDATE_VEL_Y);
	particle[i].z = particle[i].z + (particle[i].sz * UPDATE_VEL_Z);
	particle[i].sy = particle[i].sy - VEL_DECREMENT;

}

//Bucle para dibujar en pantalla los diferentes puntos que componen
//el sistema de partículas. Para ello crea los puntos y los va
//evolucionando para que pueda existir un movimiento
void draw() {

	for (int i = 0; i < MAX_PARTICLES; i++) {
		if (particle[i].age < 0) {
			create(i);
		}
		else {
			glBegin(GL_POINTS);
			glVertex3f(particle[i].x, particle[i].y, particle[i].z);
			glEnd();
		}
		evolve(i);
	}
}

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
