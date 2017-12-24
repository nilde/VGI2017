#include "stdafx.h"
#include "AnimaController.h"
#include "escena.h"			// Include funcions d'objectes OpenGL


AnimaController::AnimaController()
{
	rocket = Rocket();
	planet = Planet(6371);

	

}

//AnimaController::~AnimaController() {
	//some mine code
	//Delete of dynamic matrix
	/*
	for (int i = 0; i < numRows; ++i) {
		delete cloudProbability[i];
	}
	delete[] cloudProbability;

	for (int i = 0; i < numClouds; ++i) {
		for (int j = 0; j < numClouds; ++j) {
			cloudContentOffsetZ[i][j];
		}
		delete cloudContentOffsetZ[i];
	}
	delete[] cloudContentOffsetZ;

	for (int i = 0; i < numClouds; ++i) {
		for (int j = 0; j < numClouds; ++j) {
			cloudContentOffsetY[i][j];
		}
		delete cloudContentOffsetY[i];
	}
	delete[] cloudContentOffsetY;

	delete[] OffsetsX;
	delete[] OffsetsY;
	delete[] OffsetsZ;*/
//}
void AnimaController::generateStructuresForClouds() {


}