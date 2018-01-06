#ifndef _CITIES
#define _CITIES

const int numOfPosiblePositions = 111250;
const int numOfActiveBlocks = 4000;
const int numBuildings = 600;
const int numTrees=2000;

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
	double validPositionsFromScratch[numOfPosiblePositions][3]; // index 0,1,2 for position and 4 identifier for buildings/trees
	int validPositionsActive[numOfActiveBlocks] = {0};// first component contains the index of the position, and  second contain the value(0-building,1-tree)
	int validPositionsActiveContent[numOfActiveBlocks] = { -1 };
	int countOfTrueValues = 0;
	int numOfBlocks = numOfActiveBlocks;
	const int sizeOfBlock = 4;
	int numActiveBuildings = numBuildings;
	int numActiveTrees = numTrees;
	int compBuilding = numBuildings;
	int compTrees = numTrees;
	bool isActive = true;

};
#endif