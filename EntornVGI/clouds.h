#ifndef _CLOUDS
#define _CLOUDS

const int numClouds = 120; //1D
const int numProf = 5;	//2D
const int numRows = 14;	//3D
const int numCols = 17;	//4D
const int numDimensions = 3; //5D

class Clouds {
public:
	//Methods
	Clouds();
	~Clouds();

	void initDistancesBetweenClouds();
	void initProbabilitiesClouds();
	void calcTrueActiveBlocks();
	void calcPositions();
	void maxPrune();
	void optimizedVersionOfClouds();

	//Variables
	const float sizeOfBox =70; //Tamano de los cubos que van a aparecer


	const int minOffsetBetweenCloudsX = -4100; //Distancia minima entre nubes
	const int maxOffsetBetweenCloudsX = 4010; //Distancia maxima entre nubes
	const int minOffsetBetweenCloudsY = -3000; //Distancia minima entre nubes
	const int maxOffsetBetweenCloudsY = 3000; //Distancia maxima entre nubes
	const int minOffsetBetweenCloudsZ = 0; //Distancia minima entre nubes
	const int maxOffsetBetweenCloudsZ = 7000; //Distancia maxima entre nubes
	
	const float posXFirstCloud = 0;
	const float posYFirstCloud = 0;
	const float posZFirstCloud = 0;
	
	int numCloudsR = numClouds;
	int numProfR = numProf;	//2D
	int numRowsR = numRows;	//3D
	int numColsR = numCols;	//4D
	int numDimensionsR = numDimensions; //5D
	int maxHighCloud = 0;
	int minHighCloud = 999999;
	bool rocketOverClouds=false;
	int numStepsBeforeDelete = 20;
	bool deleteCatalunya = false;
	bool isActive = true;

	//optimization
	int numOfActivePoints = 0;

	int OffsetsBetweenClouds[numClouds][numDimensions];
	float cloudProbability[numClouds][numProf][numRows][numCols];
	int cloudContentOffset[numClouds][numProf][numRows][numClouds][numDimensions];
	bool cloudContentActive[numClouds][numProf][numRows][numCols] = {0};
	int probabilitiesClouds[numClouds];
	int **optimizationForClouds;

};


#endif