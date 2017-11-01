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

	void ExecuteTrayectory(float t);

	void Restart();

	void Initialize();

	void createRocket();

};


#endif