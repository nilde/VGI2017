#ifndef _READER
#define _READER

#include <string.h>
const int BUFFERSIZE = 256;

class Reader {
public:
	//Methods
	Reader();
	Reader(char * fileToRead);

	void operator=(Reader &Copy);

	void readFromFile(char* fileToRead);

	void setAttribute1(char* container);
	void getAttribute1(char* container);

	void setAttribute2(char* container);
	void getAttribute2(char* container);

	void setAttribute3(char* container);
	void getAttribute3(char* container);

	char Attribute1[BUFFERSIZE] = { '\0' };
	char Attribute2[BUFFERSIZE] = { '\0' };
	char Attribute3[BUFFERSIZE] = { '\0' };


};
#endif
