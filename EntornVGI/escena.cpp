//******** PRACTICA VISUALITZACI� GR�FICA INTERACTIVA (Escola Enginyeria - UAB)
//******** Entorn b�sic VS2013 MULTIFINESTRA amb OpenGL, interf�cie MFC i Status Bar
//******** Ferran Poveda, Marc Vivet, Carme Juli�, D�bora Gil, Enric Mart� (Setembre 2017)
// escena.cpp : Aqui es on ha d'anar el codi de les funcions que 
//              dibuixin les escenes.

#include "stdafx.h"
#include "material.h"
#include "escena.h"
#include "AnimaController.h"
#include "fractals.h"
#include "constants.h"

//////////////////////////////////////////////////////////////
const float PI = 3.141516;
const int CACHE_SIZE = 200;




// --- ESFERA
void gluEsfera(GLdouble radius, GLint slices, GLint stacks)
{
	GLint i, j;
	GLfloat sinCache1a[CACHE_SIZE];
	GLfloat cosCache1a[CACHE_SIZE];
	GLfloat sinCache2a[CACHE_SIZE];
	GLfloat cosCache2a[CACHE_SIZE];
	GLfloat sinCache1b[CACHE_SIZE];
	GLfloat cosCache1b[CACHE_SIZE];
	GLfloat sinCache2b[CACHE_SIZE];
	GLfloat cosCache2b[CACHE_SIZE];
	GLfloat angle;
	GLfloat zLow, zHigh;
	GLfloat sintemp1 = 0.0, sintemp2 = 0.0, sintemp3 = 0.0, sintemp4 = 0.0;
	GLfloat costemp1 = 0.0, costemp2 = 0.0, costemp3 = 0.0, costemp4 = 0.0;
	GLboolean needCache2;
	GLint start, finish;

	if (slices >= CACHE_SIZE) slices = CACHE_SIZE - 1;
	if (stacks >= CACHE_SIZE) stacks = CACHE_SIZE - 1;
	if (slices < 2 || stacks < 1 || radius < 0.0) return;

	/* Cache2 is the various normals at the vertices themselves */
	needCache2 = GL_TRUE;

	for (i = 0; i < slices; i++) {
		angle = 2 * PI * i / slices;
		sinCache1a[i] = sin(angle);
		cosCache1a[i] = cos(angle);
		sinCache2a[i] = sinCache1a[i];
		cosCache2a[i] = cosCache1a[i];
	}

	for (j = 0; j <= stacks; j++) {
		angle = PI * j / stacks;
		sinCache2b[j] = sin(angle);
		cosCache2b[j] = cos(angle);
		sinCache1b[j] = radius * sin(angle);
		cosCache1b[j] = radius * cos(angle);
	}

	/* Make sure it comes to a point */
	sinCache1b[0] = 0;
	sinCache1b[stacks] = 0;

	sinCache1a[slices] = sinCache1a[0];
	cosCache1a[slices] = cosCache1a[0];

	sinCache2a[slices] = sinCache2a[0];
	cosCache2a[slices] = cosCache2a[0];

	//	** When texturing we need to respecify the
	//	** texture coordinates of the apex for every adjacent vertex (because
	//	** it isn't a constant for that point)
	start = 0;
	finish = stacks;

	for (j = start; j < finish; j++) {
		zLow = cosCache1b[j];
		zHigh = cosCache1b[j + 1];
		sintemp1 = sinCache1b[j];
		sintemp2 = sinCache1b[j + 1];
		sintemp3 = sinCache2b[j + 1];
		costemp3 = cosCache2b[j + 1];
		sintemp4 = sinCache2b[j];
		costemp4 = cosCache2b[j];

		glBegin(GL_QUAD_STRIP);
		for (i = 0; i <= slices; i++) {
			glNormal3f(sinCache2a[i] * sintemp3, cosCache2a[i] * sintemp3, costemp3);
			glTexCoord2f(1 - (float)i / slices, 1 - (float)(j + 1) / stacks);
			glVertex3f(sintemp2 * sinCache1a[i], sintemp2 * cosCache1a[i], zHigh);

			glNormal3f(sinCache2a[i] * sintemp4, cosCache2a[i] * sintemp4, costemp4);
			glTexCoord2f(1 - (float)i / slices, 1 - (float)j / stacks);
			glVertex3f(sintemp1 * sinCache1a[i], sintemp1 * cosCache1a[i], zLow);
		}
		glEnd();
	}
}


// TEXTURES: Vector de noms de textura
GLuint texturID[NUM_MAX_TEXTURES] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };



// dibuixa_EscenaGL: Dibuix de l'escena amb comandes GL
void dibuixa_EscenaGL(char objecte, CColor col_object, bool ref_mat, bool sw_mat[4], bool textur, AnimaController &animaController)
{
	float altfar = 0;


		glColor3f(1.0, 1.0, 1.0);
		if (animaController.activePlanet == TIERRA) {
			glBindTexture(GL_TEXTURE_2D, texturID[1]);

		}
		else if (animaController.activePlanet == LUNA) {
			glBindTexture(GL_TEXTURE_2D, texturID[5]);

		}
		else if (animaController.activePlanet == MARTE) {
			glBindTexture(GL_TEXTURE_2D, texturID[4]);

		}

		glEnable(GL_TEXTURE_2D);
		glPushMatrix();
		glTranslatef(animaController.planet.center[0], animaController.planet.center[1], animaController.planet.center[2]);
		glRotatef(312, 155, 1, 1);
		gluEsfera(animaController.planet.radius, 1000, 10000);
		glPopMatrix();
		if (animaController.activeFractal && (animaController.lookat == ROCKET) && (animaController.rocket.get_altura() < 6550)) {
			char iluminacio = GOURAUD; //PLANA, ,FILFERROS
			GLfloat mida = 0.55;
			glPushMatrix();
			glTranslatef(70, -90, 6370);
			glScalef(mida, mida, mida);
			fract(iluminacio, true, animaController.step, animaController.matrixContainer, false);			glPopMatrix();
		}
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		if (animaController.activePlanet == TIERRA) {
			for (int i = 0; i < 4; i++) {
				glBindTexture(GL_TEXTURE_2D, texturID[3]);
				glEnable(GL_TEXTURE_2D);
				glColor4f(0.5, 0.8, 1, 0.13 - 0.005*i);
				glPushMatrix();
				glRotatef(300 + 50 * i, 50 * i, 90 * i + 10 * i, 1);
				gluEsfera(6300 + 500 * i, 100, 100);
				glPopMatrix();
			}
		}
		


		glBindTexture(GL_TEXTURE_2D, texturID[6]);
		glEnable(GL_TEXTURE_2D);
		glColor4f(1, 1, 1, 0.15);
		glPushMatrix();
		glRotatef(312, 155, 1, 1);
		if (animaController.lookat == ROCKET) {
			gluEsfera(10000, 1000, 10000);
		}
		else {
			gluEsfera(9000000, 1000, 10000);
		}
		glPopMatrix();
		//glDisable(GL_TEXTURE_2D);
	
		// animaController.DrawHumo();
		
		if ((animaController.lookat == ROCKET) && (animaController.rocket.get_altura() < 6700)) {
			//Plataforma de llençament
			glPushMatrix();
			glTranslatef(67, -60, 6374-animaController.moved);
			glRotatef(90, 1, 0, 0);
			glScalef(1.5, 0.6, 1.5);
			glCallList(PLATAFORMAOBJ);
			glPopMatrix();
		}
		//Other Rockets
		if (animaController.activeRocket == '2')
		{//Coete Deposito
			animaController.rocket2.m_z -= animaController.moved;
			glPushMatrix();
			glTranslatef(animaController.rocket2.m_x + 0.25, animaController.rocket2.m_y, animaController.rocket2.m_z- animaController.moved);
			glRotatef(animaController.rocket2.m_alpha, 90, 1, 0);
			glRotatef(270, 0, 90, 0);
			glScalef(0.05, 0.05, 0.05);
			glCallList(SUBROCKET1OBJ);
			glPopMatrix();

			//Coete Aux1
			glPushMatrix();
			glTranslatef(animaController.rocket3.m_x + 0.25, animaController.rocket3.m_y - 0.25, animaController.rocket3.m_z- animaController.moved);
			glRotatef(animaController.rocket3.m_alpha, 90, 1, 0);
			glRotatef(270, 0, 90, 0);
			glRotatef(animaController.rocket3.m_special, 0, 90, 0);
			glScalef(0.05, 0.05, 0.05);
			glCallList(SUBROCKET2OBJ);
			glPopMatrix();

			//Coete Aux2
			glPushMatrix();
			glTranslatef(animaController.rocket4.m_x + 0.25, animaController.rocket4.m_y + 0.25, animaController.rocket4.m_z- animaController.moved);
			glRotatef(animaController.rocket4.m_alpha, 90, 1, 0);
			glRotatef(270, 0, 90, 0);
			glRotatef(animaController.rocket4.m_special, 0, 90, 0);
			glScalef(0.05, 0.05, 0.05);
			glCallList(SUBROCKET2OBJ);
			glPopMatrix();
		}

		if (animaController.cities.isActive) {
			//Generacion de las ciudades
			glPushMatrix();
			glTranslatef(35, -231, 6370);
			glScalef(0.55, 0.55, 0.55);
			generateRandomCities(animaController);
			glPopMatrix();
		}
		/////////// COHETE!!
		//glColor3f(1.0, 0, 1.0);
		//SeleccionaMaterialiColor(MAT_CAP, sw_mat, ref_mat, col_object);
		glPushMatrix();
		glTranslatef(animaController.rocket.m_x, animaController.rocket.m_y, animaController.rocket.m_z- animaController.moved);
		//rotación variable del coete
		glRotatef(animaController.rocket.m_alpha, 90, 1, 0);
		//glRotatef(max(0, 270 - animaController.count*0.055), 0, 1, 0);
		glRotatef(270, 0, 90, 0);
		glRotatef(animaController.rocket.m_special, 0, 90, 0);
		glScalef(0.05, 0.05, 0.05);
		animaController.count--;
		switch (animaController.activeRocket) {
		case '1':
		{
			glCallList(ROCKET1OBJ);
			break;
		}
		case '2':
		{
			glCallList(ROCKET2OBJ);
			break;
		}
		case '3':
		{
			glCallList(ROCKET3OBJ);
			break;
		}
		case '4':
		{
			glCallList(ROCKET4OBJ);
			break;
		}
		default:
			break;

		}
		glScalef(0.005, 0.005, 0.005);
		glTranslatef(0, 0, -2);
			glBindTexture(GL_TEXTURE_2D, texturID[0]);
			glEnable(GL_TEXTURE_2D);
			glDisable(GL_LIGHTING);
			if (animaController.lookat == ROCKET && animaController.rocket.combustible) {
				animaController.fuego.draw();
				if (animaController.activePlanet == TIERRA)
					animaController.humo.draw();
			}
		glPopMatrix();


		if (animaController.clouds.isActive) {
			glPushMatrix();
			glTranslatef(150, 50, 6400);
			glRotatef(90, 1, 0, 0);
			glBindTexture(GL_TEXTURE_2D, texturID[0]);
			glEnable(GL_TEXTURE_2D);
			glScalef(0.05, 0.05, 0.05);
			generateRandomClouds(animaController);
			glPopMatrix();
		}


	// Enviar les comandes grafiques a pantalla
	glFlush();

}


// dibuixa: Funci� que dibuixa objectes simples de la llibreria GLUT segons obj
void dibuixa(char obj)
{
	switch(obj)
	{

// Cub
	case CUB:
		glColor3f(1.0,1.0,1.0);
		glPushMatrix();
		  glScalef(5.0f,5.0f,5.0f);
		  glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
		glScalef(5.0f, 5.0f, 5.0f);
		glTranslatef(5,5,5);
		glCallList(ROCKET1OBJ);
		glPopMatrix();
		break;

// Esfera
	case ESFERA:
//		glColor3f(1.0,1.0,1.0);	
		glPushMatrix();
		  glScalef(5.0f,5.0f,5.0f);
		  glutSolidSphere(1.0,40,40);
		glPopMatrix();
		break;

// Tetera
	case TETERA:
//		glColor3f(1.0,1.0,1.0);
		glPushMatrix();
		  glScalef(5.0f,5.0f,5.0f);
		  glutSolidTeapot(0.5);
		glPopMatrix();
		break;

	}

}





void generateRandomClouds(AnimaController &animaController) {
	float alpha = 0;
	if (animaController.rocket.m_z > animaController.clouds.maxHighCloud + 50) {
		animaController.clouds.isActive = false;
		return;
	}
	//Print all the data of the blocks
	if (animaController.rocket.m_z + 300 > animaController.clouds.maxHighCloud)
		animaController.clouds.rocketOverClouds = true;
	if (animaController.clouds.rocketOverClouds)
		alpha = (animaController.rocket.m_z + 400 - animaController.clouds.maxHighCloud) / 5.0;
	if (alpha >= 0.3) {
		animaController.clouds.numStepsBeforeDelete--;
		if (animaController.clouds.numStepsBeforeDelete == 0)
			animaController.clouds.deleteCatalunya = true;
	}
	if (alpha >= 0.3) {
		alpha = 0.3;
	}

	for (int counter = 0; counter < animaController.clouds.numOfActivePoints; ++counter) {

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glColor4f(0.97, 0.95, 0.92, 0.1 + alpha);
		glPointSize(float(animaController.clouds.sizeOfBox));
		glBegin(GL_POINTS);
		glVertex3f(animaController.clouds.optimizationForClouds[counter][0], animaController.clouds.optimizationForClouds[counter][1], animaController.clouds.optimizationForClouds[counter][2]);
		glEnd();

	}
}
void generateRandomCities(AnimaController &animaController) {
	int accessIndex = 0;
	int cont = 0;
	if (animaController.rocket.m_z - 30 > animaController.clouds.minHighCloud + 6575) {
		animaController.cities.isActive = false;
		return;
	}
	for (int i = 0; i < animaController.cities.numOfBlocks; i++) {
		cont++;
		if (animaController.cities.compBuilding + animaController.cities.compTrees > cont) {
			accessIndex = animaController.cities.validPositionsActive[i];
			glPushMatrix();
			glTranslatef(animaController.cities.validPositionsFromScratch[accessIndex][0], animaController.cities.validPositionsFromScratch[accessIndex][1], animaController.cities.validPositionsFromScratch[accessIndex][2] + 0.75);
			glRotatef(90, 90, 1, 0);
			glScalef(0.05, 0.05, 0.04);
			if (!animaController.cities.validPositionsActiveContent[i])
				glCallList(BUILDINGOBJ);
			if (animaController.cities.validPositionsActiveContent[i]) {
				glScalef(10, 10, 10);
				glCallList(TREEOBJ);
			}
			glPopMatrix();
		}
	}
}
