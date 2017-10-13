#pragma once

class Rocket {
private:
	//Coordenadas en que se encontrará el objeto rocket a lo largo de la ejecución
	int m_x;
	int m_y;
	int m_z;
	int m_alpha;
public:
	//Constructor
	Rocket();

	//En esta se calclaran las coordenadas a partir de las físicas
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


