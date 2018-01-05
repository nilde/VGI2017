#ifndef _READER
#define _READER

#include <string>
using namespace std;
const int BUFFERSIZE = 256;

class Reader {
public:
	//Methods
	Reader();
	Reader(char * fileToRead);

	void operator=(Reader &Copy);

	void readFromFile(char* fileToRead);

	void setSizePlanet(string newValue);
	int getSizePlanet();

	void setRocketType(string newValue);
	int getRocketType();

	void setPlanetType(string newValue);
	int getPlanetType();

	void setPropellantType(string newValue);
	int getPropellantType();

	void setGravityPlanet(string newValue);
	float getGravityPlanet();

	string sizePlanet;
	string rocketType;
	string planetType;
	string propellantType;
	string gravityPlanet;


};
#endif
