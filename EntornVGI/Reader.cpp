#include "stdafx.h"
#include "Reader.h"
#include <stdlib.h>
#include "math.h"
#include "fractals.h"
#include <fstream>
#include <iostream>

using namespace std;

//Base constructor
Reader::Reader() {

}

//Constructor overcharged
Reader::Reader(char* fileToRead) {
	readFromFile(fileToRead);
}

//Operator copy
void Reader::operator=(Reader &readerToCopy) {
	memcpy(Attribute1, readerToCopy.Attribute1, sizeof(Attribute1));
	memcpy(Attribute2, readerToCopy.Attribute2, sizeof(Attribute2));
	memcpy(Attribute3, readerToCopy.Attribute3, sizeof(Attribute3));
}

//Read Attributes from file
void Reader::readFromFile(char* fileToRead) {
	ifstream file;
	file.open(fileToRead, ifstream::in);
	if (file.good())
	{
		file.getline(Attribute1, BUFFERSIZE);
		file.getline(Attribute2, BUFFERSIZE);
		file.getline(Attribute3, BUFFERSIZE);
	}
	file.close();
}

//Setter & Getter for Attribute1
void Reader::setAttribute1(char* container) {
	memset(Attribute1, '\0', sizeof(char)*BUFFERSIZE);
	memcpy(Attribute1, container, sizeof(char)*BUFFERSIZE);
}

void Reader::getAttribute1(char* container) {
	memset(container, '\0', sizeof(char)*BUFFERSIZE);
	memcpy(container, Attribute1, sizeof(char)*BUFFERSIZE);

}


//Setter & Getter for Attribute2
void Reader::setAttribute2(char* container) {
	memset(Attribute1, '\0', sizeof(char)*BUFFERSIZE);
	memcpy(Attribute1, container, sizeof(char)*BUFFERSIZE);

}

void Reader::getAttribute2(char* container) {
	memset(container, '\0', sizeof(char)*BUFFERSIZE);
	memcpy(container, Attribute2, sizeof(char)*BUFFERSIZE);

}


//Setter & Getter for Attribute3
void Reader::setAttribute3(char* container) {
	memset(Attribute1, '\0', sizeof(char)*BUFFERSIZE);
	memcpy(Attribute1, container, sizeof(char)*BUFFERSIZE);
}

void Reader::getAttribute3(char* container) {
	memset(container, '\0', sizeof(char)*BUFFERSIZE);
	memcpy(container, Attribute3, sizeof(char)*BUFFERSIZE);
}