#include "stdafx.h"
#include "clouds.h"
#include <stdlib.h>
#include "math.h"

#include <iostream>
using namespace std;




Clouds::Clouds()
{




	//Assignations of the offsets between clouds

	initDistancesBetweenClouds();
	initProbabilitiesClouds();

	calcTrueActiveBlocks();
	calcPositions();
	maxPrune();

	

}

Clouds::~Clouds() {


}
void Clouds::initDistancesBetweenClouds() {


	int OffsetX;
	int OffsetY;
	int OffsetZ;

	OffsetsBetweenClouds[0][0] = posXFirstCloud;
	OffsetsBetweenClouds[0][1] = posYFirstCloud;
	OffsetsBetweenClouds[0][2] = posZFirstCloud;

	for (int i = 1; i < numClouds; i++) {
		
			OffsetsBetweenClouds[i][0] = OffsetsBetweenClouds[i - 1][0] + rand() % (maxOffsetBetweenCloudsX - minOffsetBetweenCloudsX + 1)+minOffsetBetweenCloudsX;
			OffsetsBetweenClouds[i][1] = OffsetsBetweenClouds[i - 1][1] + rand() % (maxOffsetBetweenCloudsY - minOffsetBetweenCloudsY + 1)+minOffsetBetweenCloudsY;
			OffsetsBetweenClouds[i][2] = OffsetsBetweenClouds[i - 1][2] + rand() % (maxOffsetBetweenCloudsZ - minOffsetBetweenCloudsZ + 1)+minOffsetBetweenCloudsZ;

		}
	}

void Clouds::initProbabilitiesClouds() {

	int bonification;
	int limitOfMesh=2;
	int probabilityCloud = 0;
	int probabilityLevel = 0;
	int probabilityRow=0;
	int ProbabilityCol=0;

	//Assignation of the probabilities
	for (int i = 0; i < numClouds; i++) {
		probabilityCloud = rand() % (10 - 1) + 1;
		for (int j = 0; j < numProf; j++) {
			if (j == 0) {
				probabilityLevel = rand() % (3 - 1) + 1;
			}
			else if(j%2==0){
				probabilityLevel = rand() % (5 - 3) + 3;
			}
			else if (j % 2 >0) {
				probabilityLevel= rand() % (4 - 1) + 1;
			}
				for (int k = 0; k < numRows; k++) {
					if (k<numRows - numRows*.75 || k>numRows - numRows*.80) {
						probabilityRow = rand() % (4 - 1) + 1;
					}
					else {
						probabilityRow = rand() % (6 - 3) + 3;
					}
					for (int l = 0; l < numCols; l++) {
						if (l<numCols/3) {
							cloudProbability[i][j][k][l] = ((probabilityCloud*0.8) / 10) +((probabilityRow+probabilityLevel)*0.2 / 10) ;
						}
						else if (l>numCols-2) {
							cloudProbability[i][j][k][l] = ((probabilityCloud*0.7) / 10) + ((probabilityRow + probabilityLevel)*0.3 / 10);
						}
						else {
							cloudProbability[i][j][k][l] = ((probabilityCloud*0.5) / 10) + ((probabilityRow + probabilityLevel)*0.5  / 10);
						}
					}
			}
		}
	}

}
void Clouds::calcTrueActiveBlocks() {
	for (int i = 0; i < numClouds;i++) {
		probabilitiesClouds[i] = rand()%(8)+1;

	}
	float randomValue = 0;
	//Generation of the pos for the cloud
	for (int cloud = 0; cloud < numClouds; cloud++) {
		for (int prof = 0; prof < numProf; prof++) {
			for (int row = 0; row < numRows; row++) {
				for (int col = 0; col < numCols; col++) {
					randomValue = (float)rand() / ((float)RAND_MAX);
					if ( randomValue > cloudProbability[cloud][prof][row][col]) {
						cloudContentActive[cloud][prof][row][col] = 1;
					}
					else {
						cloudContentActive[cloud][prof][row][col] = 0;
					}
				}
			}
		}
	}
	int randomValueCloud = 0;
	for (int cloud = 0; cloud < numClouds; cloud++) {
		for (int prof = 0; prof < numProf; prof++) {
			for (int row = 0; row < numRows; row++) {
				for (int col = 0; col < numCols; col++) {
					randomValueCloud =rand()%(8);
					if (randomValueCloud < probabilitiesClouds[cloud]) {
						cloudContentActive[cloud][prof][row][col] = 0;
					}
				}
			}
		}
	}
	
}


void Clouds::calcPositions() {

	int actualOffsetX=0;
	int actualOffsetY=0;
	int actualOffsetZ=0;
	for (int cloud = 0; cloud < numClouds; cloud++) {
	
		for (int prof = 0; prof < numProf; prof++) {
			if (prof == 0 && cloud > 0) { 
				actualOffsetX =  minOffsetBetweenCloudsX + rand()%(maxOffsetBetweenCloudsX - minOffsetBetweenCloudsX);
				actualOffsetY = minOffsetBetweenCloudsY + rand() % (maxOffsetBetweenCloudsY - minOffsetBetweenCloudsY);
				actualOffsetZ = minOffsetBetweenCloudsZ + rand() % (maxOffsetBetweenCloudsZ - minOffsetBetweenCloudsZ);
			}
			for (int row = 0; row < numRows; row++) {

				for (int col = 0; col < numCols; col++) {

					 // 0 X; 1 Y, 2 Z
					cloudContentOffset[cloud][prof][row][col][0] = actualOffsetX + sizeOfBox*row*((rand()%(8-3)+3) / 10.0);
					cloudContentOffset[cloud][prof][row][col][1] = actualOffsetY + sizeOfBox*col*((rand() % (8 - 3) + 3) / 10.0);
					cloudContentOffset[cloud][prof][row][col][2] = actualOffsetZ + sizeOfBox*prof*((rand() % (8 - 3) + 3) / 10.0);
					if (maxHighCloud < cloudContentOffset[cloud][prof][row][col][2])
						maxHighCloud = cloudContentOffset[cloud][prof][row][col][2]-100;
				}
			}
		}
	}

}
void Clouds::maxPrune() {
	int numPrunesForCloud = (numCols*numRows*numProf)/2;
	int numPrunesClouds = numClouds / 3;

	int randomIndexCloud = 0;
	int randomPositionSelected = 0;
	int randomProf = 0;
	int randomCol = 0;
	int randomRow = 0;

	for (int actualCloud = 0; actualCloud < numPrunesClouds; ++actualCloud) {
		randomIndexCloud = rand() % (numClouds - 1);
		for (int actualPrune = 0; actualPrune < numPrunesForCloud; ++actualPrune) {
			randomProf = rand() % (numProf - 1);
			randomRow = rand() % (numRows - 1);
			randomCol = rand() % (numCols - 1);
			cloudContentActive[randomIndexCloud][randomProf][randomRow][randomCol] = 0;
		}
	}
}
