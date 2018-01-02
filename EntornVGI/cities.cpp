#include "stdafx.h"
#include "cities.h"
#include <stdlib.h>
#include "math.h"
#include "fractals.h"
#include <iostream>

using namespace std;
Cities::Cities() {
	chargeMatrixContainer();
	activateSpecificBlocks();
}

Cities::~Cities() {

}

void Cities::chargeMatrixContainer() { //gotta rewrite that on future 
	char iluminacio = GOURAUD; //PLANA, ,FILFERROS
	int step= llegir_pts("./../Muntanyes_fractals/CAT128P.MNT");
	itera_fractal(S_SENSE,step);
	fract(iluminacio, true, 4, matrixContainer,true);
	int counter = 0;

	//Find the values that are okay to print there(over sea level)
	for (int i = 0; i <= FMAX + 1; i++) {
		for (int j = 0; j < FMAX + 1; j++) {
			if (matrixContainer[i][j]>=0) {
				validPositionsFromScratch[counter][0] = i;
				validPositionsFromScratch[counter][1] = j;
				validPositionsFromScratch[counter][2] = matrixContainer[i][j];
				counter++;
			}
		}
	}


}

unsigned long long Cities::Randomize() {
	unsigned long long r = 0;
	for (int i = 0; i < 2; ++i) {
		r = (r << 5) | (rand() % 0xFFF);
	}
	return r & 0xFFFFFFFFFFFFFFFFULL;
}

void Cities::activateSpecificBlocks() {
	srand(time(NULL));
	unsigned long long randomBlockIndex = 0;
	int counter = numOfActiveBlocks;
	int iter = 0;
	while (counter >= 0) {
		randomBlockIndex = Randomize();
		if (randomBlockIndex < 111250) {
			validPositionsActive[iter] = randomBlockIndex;
			iter++;
			counter--;
		}
	}
}