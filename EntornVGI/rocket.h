#pragma once

class Rocket {
private:
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


public:
	//Constructor
	Rocket();

	void ExecuteTrayectory(float t);

	bool Stoped();

	void Restart();

	void createRocket();

};


