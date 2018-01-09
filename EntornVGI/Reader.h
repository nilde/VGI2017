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
	char getRocketType();

	void setPlanetType(string newValue);
	char getPlanetType();

	void setPropellantType(string newValue);
	char getPropellantType();

	void setGravityPlanet(string newValue);
	float getGravityPlanet();

	string sizePlanet;
	string rocketType;
	string planetType;
	string propellantType;
	string gravityPlanet;
	string defective;
	string speedup;


};
#endif
