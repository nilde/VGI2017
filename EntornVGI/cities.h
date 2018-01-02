#ifndef _CITIES
#define _CITIES

const int numOfPosiblePositions = 111250;
const int numOfActiveBlocks = 4000;

class Cities {
public:
	//Methods
	Cities();
	~Cities();
	void chargeMatrixContainer();
	void activateSpecificBlocks();
	unsigned long long Randomize();

	//Vars
	double matrixContainer[FMAX + 1][FMAX + 1];
	double validPositionsFromScratch[numOfPosiblePositions][3];
	int validPositionsActive[numOfActiveBlocks] = {0};
	int countOfTrueValues = 0;
	int numOfBlocks = numOfActiveBlocks;
	const int sizeOfBlock = 4;

};
#endif