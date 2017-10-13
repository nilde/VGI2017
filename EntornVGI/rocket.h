#pragma once

class Rocket {
private:
	//Coordenadas en que se encontrar� el objeto rocket a lo largo de la ejecuci�n
	int m_x;
	int m_y;
	int m_z;
	int m_alpha;
public:
	//Constructor
	Rocket();

	//En esta se calclaran las coordenadas a partir de las f�sicas
	void calculateCoords();

	void createRocket();
	//Se van a usar para mover el objeto a partir de botones
	void incX();
	void decX();
	void incY();
	void decY();
	void incZ();
	void decZ();
	void incAlpha();
};


