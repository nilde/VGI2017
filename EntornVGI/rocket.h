#ifndef _ROCKET
#define _ROCKET


class Rocket {
public:
	//Coordenadas en que se encontrará el objeto rocket a lo largo de la ejecución
	int m_x;
	int m_y;
	int m_z;
	int m_alpha;

	bool stop;

	float xo;
	float yo;
	float zo;

	float vyo;
	float vxo;
	float vzo;

	float vx;
	float vy;
	float vz;

	float ax;
	float ay;
	float az;

	//Constructor
	Rocket();

	float DespZ(float t);

	float DespX(float t);

	float DespY(float t);

		void ExecuteTrayectory(int iteracion, float step, GLfloat center[3]);

	void Restart();

	void Initialize();

	float Rocket::angleGenerated(float previousX, float previousY, float actualX, float actualY);

};


#endif