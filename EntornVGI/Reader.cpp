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
	Attribute1 = readerToCopy.Attribute1;
	Attribute1 = readerToCopy.Attribute1;
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
		Attribute1 = container;
		Attribute1=Attribute1.substr(Attribute1.find(delimiter) + 1, Attribute1.length() - 1);

		file.getline(container, BUFFERSIZE);
		Attribute2 = container;
		Attribute2=Attribute2.substr(Attribute2.find(delimiter) + 1, Attribute2.length() - 1);

		file.getline(container, BUFFERSIZE);
		Attribute3 = container;
		Attribute3=Attribute3.substr(Attribute3.find(delimiter) + 1, Attribute3.length() - 1);
	}
	file.close();
}

//Setter & Getter for Attribute1
void Reader::setAttribute1(string newValue) {
	Attribute3 = newValue;
}

string Reader::getAttribute1() {
	return Attribute1;

}


//Setter & Getter for Attribute2
void Reader::setAttribute2(string newValue) {
	Attribute3 = newValue;
}

string Reader::getAttribute2() {

	return Attribute2;

}


//Setter & Getter for Attribute3
void Reader::setAttribute3(string newValue) {
	Attribute3 = newValue;
}

string Reader::getAttribute3() {
	return Attribute3;
}