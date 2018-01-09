#include "stdafx.h"
#include "Reader.h"
#include <stdlib.h>
#include "math.h"
#include "fractals.h"
#include <fstream>
#include <iostream>



//Base constructor
Reader::Reader() {

}

//Constructor overcharged
Reader::Reader(char* fileToRead) {
	readFromFile(fileToRead);
}

//Operator copy
void Reader::operator=(Reader &readerToCopy) {
	sizePlanet = readerToCopy.sizePlanet;
	rocketType = readerToCopy.rocketType;
	planetType = readerToCopy.planetType;
	propellantType = readerToCopy.propellantType;
	gravityPlanet = readerToCopy.gravityPlanet;
}

//Read Attributes from file
void Reader::readFromFile(char* fileToRead) {
	ifstream file;
	file.open(fileToRead, ifstream::in);
	if (file.good())
	{
		char container[BUFFERSIZE];
		string delimiter = ":";

		file.getline(container, BUFFERSIZE);
		sizePlanet = container;
		sizePlanet=sizePlanet.substr(sizePlanet.find(delimiter) + 1, sizePlanet.length() - 1);

		file.getline(container, BUFFERSIZE);
		rocketType = container;
		rocketType = rocketType.substr(rocketType.find(delimiter) + 1, rocketType.length() - 1);

		file.getline(container, BUFFERSIZE);
		planetType = container;
		planetType=planetType.substr(planetType.find(delimiter) + 1, planetType.length() - 1);

		file.getline(container, BUFFERSIZE);
		propellantType = container;
		propellantType = propellantType.substr(propellantType.find(delimiter) + 1, propellantType.length() - 1);
	
		file.getline(container, BUFFERSIZE);
		gravityPlanet = container;
		gravityPlanet = gravityPlanet.substr(gravityPlanet.find(delimiter) + 1, gravityPlanet.length() - 1);

		file.getline(container, BUFFERSIZE);
		defective = container;
		defective = defective.substr(defective.find(delimiter) + 1, defective.length() - 1);

		file.getline(container, BUFFERSIZE);
		speedup = container;
		speedup = speedup.substr(speedup.find(delimiter) + 1, speedup.length() - 1);

	}
	file.close();
}

//Setter & Getter for size planet
void Reader::setSizePlanet(string newValue) {
	sizePlanet = newValue;
}

int Reader::getSizePlanet() {
	return stoi(sizePlanet);

}


//Setter & Getter for rocket type
void Reader::setRocketType(string newValue) {
	rocketType = newValue;
}

char Reader::getRocketType() {

	return rocketType[0];

}


//Setter & Getter for planet type
void Reader::setPlanetType(string newValue) {
	planetType = newValue;
}

char Reader::getPlanetType() {
	return planetType[0];
}

//Setter & Getter for propellant type
void Reader::setPropellantType(string newValue) {
	propellantType = newValue;
}

char Reader::getPropellantType() {
	return propellantType[0];
}
//Setter & Getter for gravity of the planet
void Reader::setGravityPlanet(string newValue) {
	gravityPlanet = newValue;
}

float Reader::getGravityPlanet() {
	return stof(gravityPlanet);
}