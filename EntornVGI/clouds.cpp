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
		
			OffsetsBetweenClouds[i][0] = OffsetsBetweenClouds[i - 1][0] + rand() % (maxOffsetBetweenCloudsX - minOffsetBetweenCloudsX + 1);
			OffsetsBetweenClouds[i][1] = OffsetsBetweenClouds[i - 1][1] + rand() % (maxOffsetBetweenCloudsY - minOffsetBetweenCloudsY + 1);
			OffsetsBetweenClouds[i][2] = OffsetsBetweenClouds[i - 1][2] + rand() % (maxOffsetBetweenCloudsZ - minOffsetBetweenCloudsZ + 1);

		}
	}

void Clouds::initProbabilitiesClouds() {

	float bonification;
	int limitOfMesh=2;
	//Assignation of the probabilities
	for (int i = 0; i < numProf; i++) {
		for (int j = 0; j < numRows; j++) {
			if (j == 0) { bonification = 0.8; }
			else if (j == numRows - 1) { bonification = 0.7; }
			else { bonification = 1.0; }
				for (int k = 0; k < numCols; k++) {
				if (i < limitOfMesh || numCols - i < limitOfMesh) {
					cloudProbability[i][j][k] = lateralProbability*bonification;
				}
				if (j < limitOfMesh || numCols - j < limitOfMesh) {
					cloudProbability[i][j][k] = lateralProbability*bonification;
				}
				else {
					cloudProbability[i][j][k] = principalProbability*bonification;
				}
			}
		}
	}

}
void Clouds::calcTrueActiveBlocks() {
	float randomValue = 0;
	//Generation of the pos for the cloud
	for (int cloud = 0; cloud < numClouds; cloud++) {
		for (int prof = 0; prof < numProf; prof++) {
			for (int row = 0; row < numRows; row++) {
				for (int col = 0; col < numCols; col++) {
					randomValue = (float)rand() / ((float)RAND_MAX);
					if ( randomValue> cloudProbability[prof][row][col]) {
						cloudContentActive[cloud][prof][row][col] = 1;
					}
					else {
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
				actualOffsetX = cloudContentOffset[cloud - 1][0][numRows - 1][0][0] + minOffsetBetweenCloudsX + rand()%(maxOffsetBetweenCloudsX - minOffsetBetweenCloudsX);
				actualOffsetY = cloudContentOffset[cloud - 1][0][numRows - 1][0][1] + minOffsetBetweenCloudsY + rand()%(maxOffsetBetweenCloudsY - minOffsetBetweenCloudsY);
				actualOffsetZ = cloudContentOffset[cloud - 1][0][numRows - 1][0][2] + minOffsetBetweenCloudsZ + rand()%(maxOffsetBetweenCloudsZ - minOffsetBetweenCloudsZ);
			}
			for (int row = 0; row < numRows; row++) {

				for (int col = 0; col < numCols; col++) {

					 // 0 X; 1 Y, 2 Z
					cloudContentOffset[cloud][prof][row][col][0] = actualOffsetX + sizeOfBox*col;
					cloudContentOffset[cloud][prof][row][col][1] = actualOffsetY + sizeOfBox*prof;
					cloudContentOffset[cloud][prof][row][col][2] = actualOffsetZ + sizeOfBox*row;
					
				}
			}
		}
	}

}
