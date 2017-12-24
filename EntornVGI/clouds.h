#ifndef _CLOUDS
#define _CLOUDS

const int numClouds = 20; //1D
const int numProf = 35;	//2D
const int numRows = 35;	//3D
const int numCols = 35;	//4D
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
	const int sizeOfBox = 10; //Tamano de los cubos que van a aparecer

	const float lateralProbability = 0.3; //Probabilidad de nube en el borde de la malla
	const int numOfLateralRestrictionsH = 2; //Numero de cuadrados sometidos a la prob anterior (Altura)
	const int numOfLateralRestrictionsW = 2; //Numero de cuadrados sometidos a la prob anterior (Anchura)
	const float principalProbability = 0.8; //Probabilidad de nube en el centro de la malla

	const int minOffsetBetweenCloudsX = -1000; //Distancia minima entre nubes
	const int maxOffsetBetweenCloudsX = 1000; //Distancia maxima entre nubes
	const int minOffsetBetweenCloudsY = -100; //Distancia minima entre nubes
	const int maxOffsetBetweenCloudsY = 100; //Distancia maxima entre nubes
	const int minOffsetBetweenCloudsZ = -500; //Distancia minima entre nubes
	const int maxOffsetBetweenCloudsZ = 500; //Distancia maxima entre nubes
	
	const float posXFirstCloud = 0;
	const float posYFirstCloud = 0;
	const float posZFirstCloud = 0;
	
	int numCloudsR = numClouds;
	int numProfR = numProf;	//2D
	int numRowsR = numRows;	//3D
	int numColsR = numCols;	//4D
	int numDimensionsR = numDimensions; //5D

	int OffsetsBetweenClouds[numClouds][numDimensions];
	float cloudProbability[numProf][numRows][numCols];
	int cloudContentOffset[numClouds][numProf][numRows][numClouds][numDimensions];
	bool cloudContentActive[numClouds][numProf][numRows][numCols] = {0};

};


#endif