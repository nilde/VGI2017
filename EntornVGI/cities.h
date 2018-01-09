#ifndef _CITIES
#define _CITIES

const int numOfPosiblePositions = 111250;
const int numBuildings = 50;
const int numTrees = 50;
const int numOfActiveBlocks = numBuildings + numTrees;

class Cities {
public:
	//Methods
	Cities();
	~Cities();
	void chargeMatrixContainer();
	void activateSpecificBlocks();
	unsigned long long Randomize();
	void randomAgain();

	//Vars
	double matrixContainer[FMAX + 1][FMAX + 1];
	double validPositionsFromScratch[numOfPosiblePositions][3] = {0}; // index 0,1,2 for position and 4 identifier for buildings/trees
	int validPositionsActive[numOfActiveBlocks] = { 0 };// first component contains the index of the position, and  second contain the value(0-building,1-tree)
	int validPositionsActiveContent[numOfActiveBlocks] = { -1 };
	int numOfBlocks = numOfActiveBlocks;
	int numActiveBuildings = numBuildings;
	int numActiveTrees = 50;
	const int compBuilding = numBuildings;
	const int compTrees = numTrees;
	bool isActive = true;

};
#endif