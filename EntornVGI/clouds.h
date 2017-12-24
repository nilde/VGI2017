#ifndef _CLOUDS
#define _CLOUDS

const int numClouds = 50; //1D
const int numProf = 3;	//2D
const int numRows = 3;	//3D
const int numCols = 4;	//4D
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

	//Variables
	const int sizeOfBox = 30; //Tamano de los cubos que van a aparecer


	const int minOffsetBetweenCloudsX = -1000; //Distancia minima entre nubes
	const int maxOffsetBetweenCloudsX = 1000; //Distancia maxima entre nubes
	const int minOffsetBetweenCloudsY = -1000; //Distancia minima entre nubes
	const int maxOffsetBetweenCloudsY = 1000; //Distancia maxima entre nubes
	const int minOffsetBetweenCloudsZ = -300; //Distancia minima entre nubes
	const int maxOffsetBetweenCloudsZ = 300; //Distancia maxima entre nubes
	
	const float posXFirstCloud = 0;
	const float posYFirstCloud = 0;
	const float posZFirstCloud = 0;
	
	int numCloudsR = numClouds;
	int numProfR = numProf;	//2D
	int numRowsR = numRows;	//3D
	int numColsR = numCols;	//4D
	int numDimensionsR = numDimensions; //5D

	int OffsetsBetweenClouds[numClouds][numDimensions];
	float cloudProbability[numClouds][numProf][numRows][numCols];
	int cloudContentOffset[numClouds][numProf][numRows][numClouds][numDimensions];
	bool cloudContentActive[numClouds][numProf][numRows][numCols] = {0};

};


#endif