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

	void setAttribute1(string newValue);
	string getAttribute1();

	void setAttribute2(string newValue);
	string getAttribute2();

	void setAttribute3(string newValue);
	string getAttribute3();

	string Attribute1;
	string Attribute2;
	string Attribute3;


};
#endif
