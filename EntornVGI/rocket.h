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

	void set_x(int x);

	void set_y(int y);

	void set_z(int z);

	void set_alpha(float alpha);

	void createRocket();
	//Se van a usar para mover el objeto a partir de botones
	void incX();
	void decX();
	void incY();
	void decY();
	void incZ();
	void decZ();
	void incAlpha();
	void decAlpha();
	float get_x();
	float get_y();
	float get_z();
	float get_alpha();
};


