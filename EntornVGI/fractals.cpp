//******** PRACTICA VISUALITZACIï¿½ GRï¿½FICA INTERACTIVA
//******** Marc Vivet, Carme Juliï¿½, Dï¿½bora Gil, Enric Martï¿½ (Setembre 2016)
// fractals.cpp : Funcions de lectura i generaciï¿½ de fractals 


#include "stdafx.h"
#include "fractals.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "normals.h"
#include <fstream>
#include <time.h>
#include "escena.h"
#include "trajectories.h"

using namespace std;

// -------------- Entorn VGI: VARIABLES utilitzades en els fractals
// FMAX: Index mï¿½xim de la matriu d'alï¿½ades. Definida a fractals.h (valor:512)
double zz[FMAX+1][FMAX+1];
double normalsC[FMAX+1][FMAX+1][3];
double normalsV[FMAX+1][FMAX+1][3];
int colorPalette = 0; // Inicializaciï¿½n a  Paleta mediterrani

// -------------- Entorn VGI: Valors mï¿½xim i mï¿½nim de Z necessaris per interpolar
//                            correctament la paleta de colors (iluminaciï¿½ suau del fractal)
double zmax = -999999;
double zmin = 999999;

// -------------- Entorn VGI: Variables pics
double cx[6],cy[6],radi[6],hmax[6]; // Centres, radis i alï¿½ades de les muntanyes
double a=1.0*FMAX*(0.65);			// Parametre lemniscata

// -------------- Entorn VGI: Nï¿½mero de pics
int npics=0;

double r;

// -------------- Entorn VGI: DEFINICIï¿½ DE LES FUNCIONS

// llegir_pts: Funciï¿½ de lectura d'un fitxer fractal amb pics.
// Variables:	- nomf: Nom del fitxer a llegir.
int llegir_pts(char *nomf)
{	
	int i, j, step = 1;
	ifstream file;

	// 1. INICIALITZAR MATRIUS zz i normals
	for (i = 0; i <= FMAX; i = i++)
	{ 
		for (j = 0; j <= FMAX; j = j++)
		{	
			zz[i][j]=0.0;
			normalsC[i][j][0]=0.0;
			normalsC[i][j][1]=0.0;
			normalsC[i][j][2]=0.0;
			normalsV[i][j][0]=0.0;
			normalsV[i][j][1]=0.0;
			normalsV[i][j][2]=0.0;
		}
	}

	// 2. INICIALITZAR PICS
	for (i = 0; i <= 6; i = i++)
	{ 
		cx[i]=0; 
		cy[i]=0; 
		radi[i]=0; 
		hmax[i]=0;
	}

	// 3. OBRIR FITXER FRACTAL I LLEGIR ALC, ADES ASSIGNANT-LES
	//    A LA MATRIU ZZ DE FORMA EQUIESPAIADA.
	file.open(nomf, ifstream::in);
	double Qx = 0, Qy = 0;
	int pics = 0;
	int in = 0;
	if (file.good())
	{
		file >> Qx; // Tamany de la quadrï¿½cula en punts
		file >> Qy; // Tamany de la quadrï¿½cula en punts
		Qx -= 1;
		Qy -= 1;
		in = FMAX / Qx;

		for (int i = 0; i <= Qx; i++) 
		{
			for (int j = 0; j <= Qy; j++) 
			{
				file >> zz[i * in][j * in];
				if (zmin > zz[i * in][j * in])
				{
					zmin = zz[i * in][j * in];
				}
				if (zmax < zz[i * in][j * in])
				{
					zmax = zz[i * in][j * in];
				}
			}
		}
		
	// 4. LLEGIR EL NOMBRE DE PICS I ELS VALORS (CENTRE,RADI,I ALï¿½ADA Mï¿½XIMA).
		file >> npics; // Nombre de pics significatius de lï¿½escena
		if (npics > 0)
		{
			for (int pic = 0; pic < npics; pic++)
			{
				file >> cx[pic];
				file >> cy[pic];
				file >> radi[pic];
				file >> hmax[pic];
			}
		}
	}

	// 5. INICIALITZAR LA VARIABLE ALEATï¿½RIA
	srand((unsigned) time(NULL));
	r=(double) rand()/RAND_MAX;

	// 6. CALCUL DEL MAXIM I MINIM DE LES ALï¿½ADES INICIALS

	// Funciï¿½ retorna el pas entre alï¿½ades a la variable step, 
	// calculat en funciï¿½ del nombre d'alï¿½ades inicials i del
	// tamany de la matriu.

	step = in;
	return step;

}

// escriure_pts: Funciï¿½ d'escriptura en un fitxer de les alï¿½ades i pics 
//               d'un fractal segons la resoluciï¿½ actual.
// Variables:	- nomf: Nom del fitxer a escriure.
//				- paso: Resoluciï¿½ del fractal a escriure.
bool escriure_pts(char *nomf,int paso)
{	int i,j;
	FILE *fd;
	int dimension = (FMAX / paso) + 1;
// 1. OBRIR FITXER
    ofstream file(nomf);

// 2. ESCRIURE ALï¿½ADES
	file << dimension;
	file << " ";
	file << dimension;
	file << " ";
	file << "\n";
	for (i = 0; i < FMAX + 1; i += paso) {
		for (j = 0; j < FMAX + 1; j += paso) {
			file << zz[i][j];
			file << " ";
			file << "\n";

		}
	}
	file << npics;
	file << "\n";
	for (i = 0; i < npics; i++) {
		file << cx[i];
		file << " ";
		file << cy[i];
		file << " ";
		file << radi[i];
		file << " ";
		file << hmax[i];
		file << " ";
		file << "\n";
	}


// 2.1 Capï¿½alera n n segons la variable paso

// 2.2 Alï¿½ades Z (una per lï¿½nia)

// 3. ESCRIURE PICS
// 3.1 Escriure nï¿½mero de pics <cr>
// 3.2 Escriure centre cx,cy, radi i alï¿½ada dels pics (un pic per lï¿½nia).

// retorna true si escritura s'ha realitzat amb ï¿½xit.
	return true;

}

// itera_fractal: Cï¿½lcul de les alï¿½ades intermitges.
// Variables: - bruit: Tipus de soroll (Linial,Quadrï¿½tic,SQRT o diferenciable)
//            - paso: Pas d'iteraciï¿½ del fractal.
void itera_fractal(char bruit,  int paso)
{
	int aux = 0;
	while (paso != 1) 
	{
		aux = paso;
		paso = paso / 2;
		for (int i = FMAX - paso; i >= 0; i = i - (paso * 2)) 
		{
			for (int j = paso; j <= FMAX; j = j + (paso * 2)) 
			{
				zz[i][j] = ((zz[i - paso][j - paso] + zz[i + paso][j + paso]) / 2) + soroll(i, j, aux, bruit);
				zz[i + paso][j] = ((zz[i + paso][j - paso] + zz[i + paso][j + paso]) / 2) + soroll(i, j, aux, bruit);
				zz[i][j - paso] = ((zz[i + paso][j - paso] + zz[i - paso][j - paso]) / 2) + soroll(i, j, aux, bruit);
				zz[i - paso][j] = ((zz[i - paso][j - paso] + zz[i - paso][j + paso]) / 2) + soroll(i, j, aux, bruit);
				zz[i][j + paso] = ((zz[i - paso][j + paso] + zz[i + paso][j + paso]) / 2) + soroll(i, j, aux, bruit);
			}
		}
	}
}


//soroll: Calcul del soroll en les alsades segons la distï¿½ncia
//        als picsdistancia.
// Variables: - i,j: Posiciï¿½ de l'alï¿½ada a calcular el soroll..
// 			  - alf: Mï¿½xim valor permï¿½s. En el nostre cas, el valor del
//                   de la variable pas que ens dï¿½na la resoluciï¿½ del fractal.
//            - noise: Tipus de soroll (linial, quadrï¿½tic,sqrt o diferenciable).
double soroll(int i,int j,double alf,char noise)
{
	double ff,s,r;

// Cï¿½lcul de la variable aleatï¿½ria entre (0,1).
	r=(double) rand()/RAND_MAX;

// Cï¿½lcul del soroll segons el tipus.
	switch(noise)
	{
	case S_LINIAL:
		ff=soroll_lin(i,j);
		break;
	case S_QUADRATIC:
		ff=soroll_quad(i,j);
		break;
	case S_SQRT:
		ff=soroll_sq(i,j);
		break;
	case S_DIFERENCIABLE:
		ff=soroll_dif(i,j);
		break;
	default:
		ff=0;
	} 
	s=ff*r*alf;
//Retorn del valor del soroll.
	return s;
	
}

// TRIANGULACIO DEL TERRENY. Dibuix de la muntanya fractal
// Variables: - Iluminaciï¿½: Defineix el tipus d'iluminaciï¿½ (filferros, plana o suau).
//            - step: Pas de dibuix del fractal.
void fract(char iluminacio,bool paletaColor,int step)
{
	if (colorPalette != -1) // Se ha asignado alguna paleta
	{
		for (int z = 0; z <= FMAX; z++)
		{
			for (int s = 0; s <= FMAX; s++)
			{
				if (zmin > zz[z][s])
					zmin = zz[z][s];

				if (zmax < zz[z][s])
					zmax = zz[z][s];
			}
		}
	}

	double paletteColorR[MAX_PALETA_FRACTAL];
	double paletteColorG[MAX_PALETA_FRACTAL];
	double paletteColorB[MAX_PALETA_FRACTAL];


	switch (colorPalette) // Asignamos los valores de la paleta correspondiente
	{
	case 0: //Paleta Mediterrani
		memcpy(paletteColorR, med_colorR, MAX_PALETA_FRACTAL * sizeof(double));
		memcpy(paletteColorG, med_colorG, MAX_PALETA_FRACTAL * sizeof(double));
		memcpy(paletteColorB, med_colorB, MAX_PALETA_FRACTAL * sizeof(double));
		break;
	case 1: //Paleta glaciar
		memcpy(paletteColorR, glaciar_colorR, MAX_PALETA_FRACTAL * sizeof(double));
		memcpy(paletteColorG, glaciar_colorG, MAX_PALETA_FRACTAL * sizeof(double));
		memcpy(paletteColorB, glaciar_colorB, MAX_PALETA_FRACTAL * sizeof(double));
		break;
	case 2: //Paleta tundra
		memcpy(paletteColorR, tundra_colorR, MAX_PALETA_FRACTAL * sizeof(double));
		memcpy(paletteColorG, tundra_colorG, MAX_PALETA_FRACTAL * sizeof(double));
		memcpy(paletteColorB, tundra_colorB, MAX_PALETA_FRACTAL * sizeof(double));
		break;
	}

	int k = 23; // De 23 a 0 --> 24

	glPushMatrix();
// 1. CENTRAR EL FRACTAL EN EL (0,0,0).
	glColor3f(255, 255, 255);
<<<<<<< HEAD
	glTranslatef(-FMAX / 8.0, -FMAX / 2.0, 0);
// 2. DIBUIXAR ELS Vï¿½RTEXS DELS TRIANGLES SEGONS EL PAS (step)
//    I DEFINIR ELS VECTORS NORMALS DE CADA Vï¿½RTEX EN FUNCIï¿½ DE
//	  LA ILUMINACIï¿½ (iluminacio)
=======
	glTranslatef(-FMAX / 8.0, -FMAX / 2.0, -0.0);
// 2. DIBUIXAR ELS VÈRTEXS DELS TRIANGLES SEGONS EL PAS (step)
//    I DEFINIR ELS VECTORS NORMALS DE CADA VÈRTEX EN FUNCIÖ DE
//	  LA ILUMINACIÖ (iluminacio)
>>>>>>> master


	switch (iluminacio)
	{
	case FILFERROS:
		for (int i = 0; i < FMAX; i = i + step)
		{
			for (int j = 0; j < FMAX; j = j + step)
			//for (int j = FMAX - step; j >= 0; j = j - step)
			{
				glBegin(GL_TRIANGLES);
					if (colorPalette != -1)
					{
						k = abs(zmin) + (zz[i][j] + zz[i + step][j] + zz[i + step][j + step]) / 3;
						k /= ((abs(zmax) + abs(zmin)) / 24);
						glColor3f(paletteColorR[k], paletteColorG[k], paletteColorB[k]);
					}
					glScalef(1, 1, 1);
					glVertex3f(i, j, zz[i][j]); //v1                   
					glVertex3f(i + step, j, zz[i + step][j]); //v2      
					glVertex3f(i + step, j + step, zz[i + step][j + step]); //v3
				glEnd();
				glBegin(GL_TRIANGLES);
					if (colorPalette != -1)
					{
						k = abs(zmin) + (zz[i][j] + zz[i][step + j] + zz[i + step][j + step]) / 3;
						k /= ((abs(zmax) + abs(zmin)) / 24);
						glColor3f(paletteColorR[k], paletteColorG[k], paletteColorB[k]);
					}
					glVertex3f(i, j, zz[i][j]); //v1            
					glVertex3f(i + step, j + step, zz[i + step][j + step]); //v3 
					glVertex3f(i, j + step, zz[i][j + step]); //v4
				glEnd();
				
			}
		}
		break;
	case PLANA:
		normalcara(step);
		for (int i = 0; i<(FMAX); i += step) {
			for (int j = 0; j<(FMAX); j += step) {
				glBegin(GL_TRIANGLES);
					if (colorPalette != -1)
					{
						k = abs(zmin) + (zz[i][j] + zz[i + step][j] + zz[i + step][j + step]) / 3;
						k /= ((abs(zmax) + abs(zmin)) / 24);
						glColor3f(paletteColorR[k], paletteColorG[k], paletteColorB[k]);
					}
					glNormal3f(normalsC[i][j][0], normalsC[i][j][1], normalsC[i][j][2]); // VNorm.
					glVertex3f(i, j, zz[i][j]); //v1                   
					glVertex3f(i + step, j, zz[i + step][j]); //v2      
					glVertex3f(i + step, j + step, zz[i + step][j + step]); //v3
				glEnd();

				glBegin(GL_TRIANGLES);
					if (colorPalette != -1)
					{
						k = abs(zmin) + (zz[i][j] + zz[i][step + j] + zz[i + step][j + step]) / 3;
						k /= ((abs(zmax) + abs(zmin)) / 24);
						glColor3f(paletteColorR[k], paletteColorG[k], paletteColorB[k]);
					}
					glNormal3f(normalsV[i][j][0], normalsV[i][j][1], normalsV[i][j][2]); // VNorm.
					glVertex3f(i, j, zz[i][j]); //v1            
					glVertex3f(i + step, j + step, zz[i + step][j + step]); //v3 
					glVertex3f(i, j + step, zz[i][j + step]); //v4
				glEnd();				
			}
		}
		break;
	case GOURAUD:
		normalvertex(step);
		for (int i = 0; i<(FMAX); i += step) {
			for (int j = 0; j<(FMAX); j += step) {
				glBegin(GL_TRIANGLES);
					if (colorPalette != -1)
					{
						k = abs(zmin) + (zz[i][j] + zz[i + step][j] + zz[i + step][j + step]) / 3;
						k /= ((abs(zmax) + abs(zmin)) / 24);
						glColor3f(paletteColorR[k], paletteColorG[k], paletteColorB[k]);
					}
					glNormal3f(normalsV[i][j][0], normalsV[i][j][1], normalsV[i][j][2]); // Normal a V1
					glVertex3f(i, j, zz[i][j]); // V1
					glNormal3f(normalsV[i + step][j][0], normalsV[i + step][j][1], normalsV[i + step][j][2]); // Normal a V2
					glVertex3f(i + step, j, zz[i + step][j]); // V2
					glNormal3f(normalsV[i + step][j + step][0], normalsV[i + step][j + step][1], normalsV[i + step][j + step][2]); // Normal a V3 
					glVertex3f(i + step, j + step, zz[i + step][j + step]); // V3
				glEnd();
				glBegin(GL_TRIANGLES);
					if (colorPalette != -1)
					{
						k = abs(zmin) + (zz[i][j] + zz[i][step + j] + zz[i + step][j + step]) / 3;
						k /= ((abs(zmax) + abs(zmin)) / 24);
						glColor3f(paletteColorR[k], paletteColorG[k], paletteColorB[k]);
					}
					glNormal3f(normalsV[i][j][0], normalsV[i][j][1], normalsV[i][j][2]); // Normal a V1
					glVertex3f(i, j, zz[i][j]); // V1
					glNormal3f(normalsV[i + step][j + step][0], normalsV[i + step][j + step][1], normalsV[i + step][j + step][2]); // Normal a V3
					glVertex3f(i + step, j + step, zz[i + step][j + step]); // V3
					glNormal3f(normalsV[i][j + step][0], normalsV[i][j + step][1], normalsV[i][j + step][2]); // Normal a V4
					glVertex3f(i, j + step, zz[i][j + step]); // V4
				glEnd();
			}
		}
		break;
	}

<<<<<<< HEAD

	glPopMatrix();


=======
>>>>>>> master
	/*glPopMatrix();
//  3. DIBUIX DEL MAR A L'ALï¿½ADA Z=0.
	glPushMatrix();
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glColor4f(0.2f,0.75f,0.9f,0.5f);
		glRectf(-FMAX/2,-FMAX/2,FMAX/2,FMAX/2);
		glDisable(GL_BLEND);
	glPopMatrix();*/
<<<<<<< HEAD
=======
	
>>>>>>> master
}


//------------------ CALCUL DELS SOROLLS  --------------------/

// Cï¿½lcul del soroll linial segons la posiciï¿½ del punt (x,y)
double soroll_lin(int x, int y)
{ 
	double aux_sl = 0;
	for (int pic = 0; pic <= npics; pic++) 
	{
		if (sqrt(pow(x - cx[pic], 2) + pow(y - cy[pic], 2)) < radi[pic]) 
		{
			aux_sl += hmax[pic] * (1 - ((sqrt(pow(x - cx[pic], 2) + pow(y - cy[pic], 2))) / radi[pic]));
		}
	}
	return aux_sl;
}

// Cï¿½lcul del soroll quadrï¿½tic segons la posiciï¿½ del punt (x,y)
double soroll_quad(int x,int y)
{ 
	double aux_sq = 0;
	double dist = 0;
	for (int pic = 0; pic <= npics; pic++) 
	{
		dist = sqrt(pow(x - cx[pic], 2) + pow(y - cy[pic], 2));
		if (dist < radi[pic]) 
		{
			aux_sq += hmax[pic] * (1 - dist *dist / (pow(radi[pic], 2)));
		}
	}
	return aux_sq;
}

// Cï¿½lcul del soroll arrel quadrada segons la posiciï¿½ del punt (x,y)
double soroll_sq(int x,int y)
{ 
	double aux_sq = 0;
	double dist = 0;
	for (int pic = 0;pic <= npics; pic++) 
	{
		dist = sqrt(pow(x - cx[pic], 2) + pow(y - cy[pic], 2));
		if (dist < radi[pic]) 
		{
			aux_sq += hmax[pic] * (1 - sqrt(dist) / sqrt(radi[pic]));
		}
	}
	return aux_sq;
}

// Cï¿½lcul del soroll diferenciable segons la posiciï¿½ del punt (x,y)
double soroll_dif(int x,int y)
{ 
	double aux_sd = 0;
	double dist = 0;
	for (int pic = 0;pic <= npics; pic++) 
	{
		dist = sqrt(pow(x - cx[pic], 2) + pow(y - cy[pic], 2));
		if (dist < radi[pic]) 
		{
			aux_sd += hmax[pic] * (pow(1 - dist / radi[pic], 2));
		}
	}
	return aux_sd;
}

// Obtenciï¿½ de la paleta de colors actual
int getColorPalette()
{
	return colorPalette;
}

// Fixa una paleta de colors concreta
void setColorPalette(int colorPaletteValue)
{
	colorPalette = colorPaletteValue;
}
