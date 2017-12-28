//******** PRACTICA VISUALITZACIÓ GRÀFICA INTERACTIVA (Escola Enginyeria - UAB)
//******** Entorn bàsic VS2013 MULTIFINESTRA amb OpenGL, interfície MFC i Status Bar
//******** Ferran Poveda, Marc Vivet, Carme Julià, Débora Gil, Enric Martí (Setembre 2017)
// escena.cpp : Aqui es on ha d'anar el codi de les funcions que 
//              dibuixin les escenes.

#include "stdafx.h"
#include "material.h"
#include "escena.h"
#include "AnimaController.h"
#include "fractals.h"








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



///////////////////////////////////////77













// TEXTURES: Vector de noms de textura
GLuint texturID[NUM_MAX_TEXTURES] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

// dibuixa_EscenaGL: Dibuix de l'escena amb comandes GL
void dibuixa_EscenaGL(char objecte, CColor col_object, bool ref_mat, bool sw_mat[4], bool textur, AnimaController &animaController)
{
	float altfar = 0;

		glColor3f(1.0, 1.0, 1.0);
		glBindTexture(GL_TEXTURE_2D, texturID[6]);

		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		//glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

		glEnable(GL_TEXTURE_2D);
		glPushMatrix();
		glTranslatef(animaController.planet.center[0], animaController.planet.center[1], animaController.planet.center[2]);
		glRotatef(312, 155, 1, 1);
		gluEsfera(animaController.planet.radius, 1000, 10000);
		glPopMatrix();


		char iluminacio = GOURAUD; //PLANA, ,FILFERROS
		GLfloat mida = 0.55;
		glPushMatrix();
		glTranslatef(70, -90, 6366);
		glScalef(mida, mida, mida);
		fract(iluminacio, true, animaController.step);
		glPopMatrix();

		glBindTexture(GL_TEXTURE_2D, texturID[7]);
		glEnable(GL_TEXTURE_2D);
		glColor3f(1.0, 1.0, 1.0);
		glPushMatrix();
		gluEsfera(8000, 1000, 10000);
		glPopMatrix();
		//glDisable(GL_TEXTURE_2D);

		// animaController.DrawHumo();



		/////////// COHETE!!
		glColor3f(1.0, 0, 1.0);

		//SeleccionaMaterialiColor(MAT_CAP, sw_mat, ref_mat, col_object);
		glPushMatrix();
		glTranslatef(animaController.rocket.m_x, animaController.rocket.m_y, animaController.rocket.m_z);
		glRotatef(animaController.rocket.m_alpha, 90, 1, 0);
		glScalef(0.5, 0.5, 0.5);

		switch (animaController.activeRocket) {
		case '1':
		{

			glCallList(ROCKET1OBJ);
			animaController.particles.draw();

			break;
		}
		case '2':
		{

			glCallList(ROCKET2OBJ);
			animaController.particles.draw();

			break;
		}
		case '3':
		{

			glCallList(ROCKET3OBJ);
			animaController.particles.draw();

			break;
		}
		case '4':
		{

			glCallList(ROCKET4OBJ);
			animaController.particles.draw();

			break;
		}
		default:
			break;

		}

		glPopMatrix();


	// Enviar les comandes gràfiques a pantalla
	glFlush();

}


// dibuixa: Funció que dibuixa objectes simples de la llibreria GLUT segons obj
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

// OBJECTE Truck amb imatges textura si són actives
// Truck: Paràmetres:
//    - textu: Flag de textures activades o no.
//    - VTextu: Vector d'imatges textura.
void truck(bool textu,GLuint VTextu[NUM_MAX_TEXTURES])
{

glPushMatrix();
  glTranslatef(0.0f,0.0f,20.0f);

// MOTOR
// Textura carrosseria
	if (textu)  
		{	GLfloat sPlane[4] = { 0.05f, 0.0f, 0.00f, 0.250f };
		  	GLfloat tPlane[4] = { 0.00f, 0.05f, 0.1f, 0.00f };
// Activar textura planxa
			glBindTexture(GL_TEXTURE_2D,VTextu[5]) ;
			glEnable(GL_TEXTURE_2D);
			glTexGenfv(GL_S, GL_OBJECT_PLANE, sPlane);
			glTexGenfv(GL_T, GL_OBJECT_PLANE, tPlane);
			
			glTexGeni(GL_S,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
			glTexGeni(GL_T,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
			glEnable(GL_TEXTURE_GEN_S);
			glEnable(GL_TEXTURE_GEN_T);

		}

// Color carrosseria sense textura
	glColor4f(0.5f,0.7f,1.0f,0.5f); 

	glPushMatrix();		
		glScalef(2.0f, 4.4f, 2.0f);
		glutSolidCube(10.0f);
	glPopMatrix();

// CABINA
// Cabina inferior
	glPushMatrix();
		glTranslatef(0.0f,32.0f,0.0f);
		glScalef(4.0f, 2.0f, 2.0f);
		glutSolidCube(10.0f);
	glPopMatrix();

// Cabina superior
	glPushMatrix();
		glTranslatef(0.0f,32.0f,15.0f);
		glScalef(2.0f, 2.0f, 1.0f);
		glutSolidCube(10.0f);
	glPopMatrix();

// Cabina trasera
	glPushMatrix();
		glTranslatef(0.0f,49.5f,12.5f);
		glScalef(4.0f, 1.5f, 4.5f);
		glutSolidCube(10.0f);
	glPopMatrix();

// CANTONADES
// Cantonada esquerra
	glPushMatrix() ;
	  glTranslatef(10.0f,22.0f,-10.0f);

  	  glBegin(GL_QUADS);  // Cara de 4 costats
	 	glNormal3f(200.0f, 200.0f, 0.0f);
		glVertex3f(10.0f ,  0.0f , 0.0f ); //P1
		glVertex3f(10.0f , 0.0f , 20.0f ); //P2
		glVertex3f(0.0f , -10.0f ,20.0f ); //P3
		glVertex3f(0.0f ,  -10.0f ,0.0f ); //P4
	  glEnd();

	  glBegin(GL_POLYGON);  // Triangle d'abaix
		glNormal3f(0.0f, 0.0f, -200.0f);
		glVertex3f(0.0f ,  0.0f , 0.0f );  // T1
		glVertex3f(10.0f ,  0.0f ,0.0f );  // P1
		glVertex3f(0.0f , -10.0f , 0.0f ); // P4
	  glEnd();

	  glBegin(GL_POLYGON);  // Triangle de dalt
		glNormal3f(0.0f, 0.0f, 200.0f);
		glVertex3f(0.0f ,  0.0f , 20.0f );	// T2
	    glVertex3f(0.0f , -10.0f , 20.0f ); // P3
		glVertex3f(10.0f ,  0.0f, 20.0f );  // P2
	  glEnd();
	glPopMatrix();

// Cantonada dreta
	glPushMatrix() ;
	  glTranslatef(-10.0f,22.0f,-10.0f);
	  glRotatef(-90.0f,0.0f,0.0f,1.0f);

  	  glBegin(GL_QUADS);  // Cara de 4 costats
	 	glNormal3f(200.0f, 200.0f, 0.0f);
		glVertex3f(10.0f ,  0.0f , 0.0f ); //P1
		glVertex3f(10.0f , 0.0f , 20.0f ); //P2
		glVertex3f(0.0f , -10.0f ,20.0f ); //P3
		glVertex3f(0.0f ,  -10.0f ,0.0f ); //P4
	  glEnd();

	  glBegin(GL_POLYGON);  // Triangle d'abaix
		glNormal3f(0.0f, 0.0f, -200.0f);
		glVertex3f(0.0f ,  0.0f , 0.0f );  // T1
		glVertex3f(10.0f ,  0.0f ,0.0f );  // P1
		glVertex3f(0.0f , -10.0f , 0.0f ); // P4
	  glEnd();

	  glBegin(GL_POLYGON);  // Triangle de dalt
		glNormal3f(0.0f, 0.0f, 200.0f);
		glVertex3f(0.0f ,  0.0f , 20.0f );	// T2
	    glVertex3f(0.0f , -10.0f , 20.0f ); // P3
		glVertex3f(10.0f ,  0.0f, 20.0f );  // P2
	  glEnd();
	glPopMatrix();


// PROTECCIONS DE RODA
// Textura Proteccions de roda (metall)
//	if (textu)
//		{				
//			glBindTexture(GL_TEXTURE_2D,VTextu[5]) ;
//			glEnable(GL_TEXTURE_2D) ;
//			glTexGeni(GL_S,GL_TEXTURE_GEN_MODE,GL_SPHERE_MAP);
//			glTexGeni(GL_T,GL_TEXTURE_GEN_MODE,GL_SPHERE_MAP);
//			glTexGeni(GL_S,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
//			glTexGeni(GL_T,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
//			}

// Color proteccions roda sense textura
	glColor4f(0.5f,0.7f,1.0f,0.5f);

// Protecció de roda esquerra
	glPushMatrix();		
		glTranslatef(10.0f, 0.0f, 3.0f);
		glBegin(GL_QUADS);
		//  glNormal3f(200.0f, 200.0f, 0.0f);
			glVertex3f(7.0f , -5.0f , 0.0f );
			glVertex3f(7.0f , 5.0f , 0.0f );
			glVertex3f(0.0f , 5.0f , 0.0f );
			glVertex3f(0.0f , -5.0f , 0.0f );

			glVertex3f(7.0f , -12.0f , -8.0f );
			glVertex3f(7.0f , -5.0f , 0.0f );
			glVertex3f(0.0f , -5.0f , 0.0f );
			glVertex3f(0.0f , -12.0f , -8.0f );

			glVertex3f(0.0f , 15.0f , -10.0f );
			glVertex3f(0.0f , 5.0f , 0.0f );
			glVertex3f(7.0f , 5.0f , 0.0f );
			glVertex3f(7.0f , 15.0f , -10.0f );

			glVertex3f(7.5f , -5.0f , -3.0f );
			glVertex3f(7.5f , 5.0f , -3.0f );
			glVertex3f(7.0f , 5.0f , 0.0f );
			glVertex3f(7.0f , -5.0f , 0.0f );
				
			glVertex3f(7.5f , -12.0f , -8.0f );
			glVertex3f(7.5f , -5.0f , -3.0f );
			glVertex3f(7.0f , -5.0f , 0.0f );
			glVertex3f(7.0f , -12.0f , -8.0f );
				
			glVertex3f(7.0f , 15.0f , -10.0f );
			glVertex3f(7.0f , 5.0f , 0.0f );
			glVertex3f(7.5f , 5.0f , -3.0f );
			glVertex3f(7.5f , 15.0f , -10.0f );

		glEnd();
	glPopMatrix();

// Protecció de roda dreta
	glPushMatrix();		
		glTranslatef(-16.0f, 0.0f, 3.0f);
		glBegin(GL_QUADS);
		//  glNormal3f(200.0f, 200.0f, 0.0f);
			glVertex3f(7.0f , -5.0f , 0.0f );
			glVertex3f(7.0f , 5.0f , 0.0f );
			glVertex3f(0.0f , 5.0f , 0.0f );
			glVertex3f(0.0f , -5.0f , 0.0f );

			glVertex3f(7.0f , -12.0f , -8.0f );
			glVertex3f(7.0f , -5.0f , 0.0f );
			glVertex3f(0.0f , -5.0f , 0.0f );
			glVertex3f(0.0f , -12.0f , -8.0f );

			glVertex3f(0.0f , 15.0f , -10.0f );
			glVertex3f(0.0f , 5.0f , 0.0f );
			glVertex3f(7.0f , 5.0f , 0.0f );
			glVertex3f(7.0f , 15.0f , -10.0f );

			glVertex3f(7.5f , -5.0f , -3.0f );
			glVertex3f(7.5f , 5.0f , -3.0f );
			glVertex3f(7.0f , 5.0f , 0.0f );
			glVertex3f(7.0f , -5.0f , 0.0f );
				
			glVertex3f(7.5f , -12.0f , -8.0f );
			glVertex3f(7.5f , -5.0f , -3.0f );
			glVertex3f(7.0f , -5.0f , 0.0f );
			glVertex3f(7.0f , -12.0f , -8.0f );
				
			glVertex3f(7.0f , 15.0f , -10.0f );
			glVertex3f(7.0f , 5.0f , 0.0f );
			glVertex3f(7.5f , 5.0f , -3.0f );
			glVertex3f(7.5f , 15.0f , -10.0f );
		glEnd();
	glPopMatrix();

// Textura Reixeta Motor
	if (textu)  
		{	GLfloat sPlane[4] = { 0.05f, 0.25f, 0.00f, 0.00f };
		  	GLfloat tPlane[4] = { 0.00f, 0.25f, 0.05f, 0.00f };
// Activar textura
			glBindTexture(GL_TEXTURE_2D,VTextu[3]) ;
	
			glTexGenfv(GL_S, GL_OBJECT_PLANE, sPlane);
			glTexGenfv(GL_T, GL_OBJECT_PLANE, tPlane);
			
			glTexGeni(GL_S,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
			glTexGeni(GL_T,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
			glEnable(GL_TEXTURE_GEN_S);
			glEnable(GL_TEXTURE_GEN_T);
			glEnable(GL_TEXTURE_2D);
		}

// Color reixeta motor sense textura
	glColor4f(0.5f,0.7f,1.0f,0.5f);	

// Reixeta Motor
	glPushMatrix();
		glTranslatef(0.0f,-22.0f,0.0f);
		glBegin(GL_QUADS);
		    glNormal3f(0.0f,-1.0f,0.0f);	
			glTexCoord2f(0.0f,0.0f);
			glVertex3f(-10.0f , -2.0f , -10.0f );
			glTexCoord2f(1.0f,0.00f);
			glVertex3f(10.0f , -2.0f , -10.0f );
			glTexCoord2f(1.0f,1.0);
			glVertex3f(10.0f , -2.0f , 10.0f );
			glTexCoord2f(0.0f,1.0f);	
			glVertex3f(-10.0f , -2.0f , 10.0f );
		glEnd();
	glPopMatrix();

// Desactivar textura
	if (textu) glDisable(GL_TEXTURE_2D);

// Color eix sense textura
	glColor4f(0.1f,0.4f,1.0f,0.5f);

// Eix Davanter
	glPushMatrix();
	  glTranslatef(0.0f,0.0f,-10.0f);
	  glRotatef(90.0f,0.0f,1.0f,0.0f);
  	  glTranslatef(0.0f,0.0f,-13.0f);
	  gluCilindre(2,2,26.0f,6,1);
	glPopMatrix();
	
// Roda Dreta Davantera
	glPushMatrix();
		glTranslatef(-10.0f,0.0f,-10.0f);
		neumatic(textu,VTextu);
	glPopMatrix();

// Roda Esquerra Davantera
	glPushMatrix();
		glTranslatef(17.0f,0.0f,-10.0f);
		neumatic(textu,VTextu);
	glPopMatrix();

// Desactivar textura
	if (textu) glDisable(GL_TEXTURE_2D);

// FARS	
// Color fars sense textura
	glColor4f(1.0f,0.0f,0.0f,0.5f);

// Far Esquerra	
	glPushMatrix();
		glTranslatef(-13.5f,-17.0f,-8.0f);
		glScalef(7.0f, 2.0f, 4.0f);
		glutSolidCube(1.0f);
	glPopMatrix();

// Far dret
	glPushMatrix();
		glTranslatef(13.5f,-17.0f,-8.0f);
		glScalef(7.0f, 2.0f, 4.0f);
		glRotatef(90.0f,1.0f,0.0f,0.0f); // Per a la textura
		glutSolidCube(1.0f);
	glPopMatrix();

// Textura frontal fars
	  if (textu)  
		{	GLfloat sPlane[4] = { 0.15f, 0.0f, 0.0f, 0.5f };
	  		GLfloat tPlane[4] = { 0.0f, 0.35f, 0.25f, 0.15f };
// Activar textura
			glBindTexture(GL_TEXTURE_2D,VTextu[4]) ;
	
			glTexGenfv(GL_S, GL_OBJECT_PLANE, sPlane);
			glTexGenfv(GL_T, GL_OBJECT_PLANE, tPlane);
				
			glTexGeni(GL_S,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
			glTexGeni(GL_T,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
			glEnable(GL_TEXTURE_GEN_S);
			glEnable(GL_TEXTURE_GEN_T);
			glEnable(GL_TEXTURE_2D);
			}

// Color frontal fars sense textura
	glColor4f(1.0f,1.0f,1.0f,0.5f);

// Frontal far dret
	glPushMatrix();
		glTranslatef(-13.5f,-16.5f,-8.0f);
		glBegin(GL_QUADS);
			glNormal3f(0.0f,-1.0f,0.0f);	
			glTexCoord2f(0.0f,0.0f);
			glVertex3f(-3.5f , -2.0f , -2.0f );
			glTexCoord2f(1.0f,0.00f);
			glVertex3f(3.5f , -2.0f , -2.0f );
			glTexCoord2f(1.0f,1.0);
			glVertex3f(3.5f , -2.0f , 2.0f );
			glTexCoord2f(0.0f,1.0f);	
			glVertex3f(-3.5f , -2.0f , 2.0f );
		glEnd();	
	glPopMatrix();

// Frontal far esquerre
	glPushMatrix();
		glTranslatef(13.5f,-16.5f,-8.0f);
		glBegin(GL_QUADS);
			glNormal3f(0.0f,-1.0f,0.0f);	
			glTexCoord2f(0.0f,0.0f);
			glVertex3f(-3.5f , -2.0f , -2.0f );
			glTexCoord2f(1.0f,0.00f);
			glVertex3f(3.5f , -2.0f , -2.0f );
		glTexCoord2f(1.0f,1.0);
			glVertex3f(3.5f , -2.0f , 2.0f );
			glTexCoord2f(0.0f,1.0f);	
			glVertex3f(-3.5f , -2.0f , 2.0f );
		glEnd();
	glPopMatrix();

// Desactivar textura
	if (textu) glDisable(GL_TEXTURE_2D);

// VIDRE CABINA (SENSE TEXTURA)
// Activar transparència
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);

// Color vidre cabina sense textura
	glColor4f(0.3f,0.8f,0.7f,0.5f);

// Vidre
	glPushMatrix() ;
	  glTranslatef(0.0f,22.0f,10.0f);
	  glRotatef(-90.0f,1.0f,0.0f,0.0f);
	  glRotatef(90.0f,0.0f,1.0f,0.0f);
	  glTranslatef(0.0f,00.0f,-10.0f);

   	  glBegin(GL_QUADS);  // Cara de 4 costats
	 	glNormal3f(200.0f, 200.0f, 0.0f);
		glVertex3f(10.0f ,  0.0f , 0.0f ); //P1
		glVertex3f(10.0f , 0.0f , 20.0f ); //P2
		glVertex3f(0.0f , -10.0f ,20.0f ); //P3
		glVertex3f(0.0f ,  -10.0f ,0.0f ); //P4
	  glEnd();

	  glBegin(GL_POLYGON);  // Triangle d'abaix
		glNormal3f(0.0f, 0.0f, -200.0f);
		glVertex3f(0.0f ,  0.0f , 0.0f );  // T1
		glVertex3f(10.0f ,  0.0f ,0.0f );  // P1
		glVertex3f(0.0f , -10.0f , 0.0f ); // P4
	  glEnd();

	  glBegin(GL_POLYGON);  // Triangle de dalt
		glNormal3f(0.0f, 0.0f, 200.0f);
		glVertex3f(0.0f ,  0.0f , 20.0f );	// T2
	    glVertex3f(0.0f , -10.0f , 20.0f ); // P3
		glVertex3f(10.0f ,  0.0f, 20.0f );  // P2
	  glEnd();
	glPopMatrix();

// Desactivar transparència
	glDisable(GL_BLEND);

// TUBS D'ESCAPAMENT (SENSE TEXTURA)
// Color tub d'escapament sense textura
	glColor4f(1.0f,0.0f,0.0f,0.5f);

// Tub d'escapament esquerre
	glPushMatrix();
		glTranslatef(18.0f,42.0f,10.0f);	
		gluCilindre(2,2,40.0f,12,1);	
	glPopMatrix();
	
// Tub d'escapament dret
	glPushMatrix();
		glTranslatef(-18.0f,42.0f,10.0f);	
		gluCilindre(2, 2, 40.0f, 12, 1);
	glPopMatrix();

// CARROSSERIA
// Textura carrosseria
	if (textu)
		{	GLfloat sPlane[4] = { 0.05f, 0.0f, 0.00f, 0.250f };
		  	GLfloat tPlane[4] = { 0.00f, 0.05f, 0.1f, 0.00f };

// Activar textura
			glBindTexture(GL_TEXTURE_2D,VTextu[5]) ;
	
			glTexGenfv(GL_S, GL_OBJECT_PLANE, sPlane);
			glTexGenfv(GL_T, GL_OBJECT_PLANE, tPlane);
			
			glTexGeni(GL_S,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
			glTexGeni(GL_T,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
			glEnable(GL_TEXTURE_GEN_S);
			glEnable(GL_TEXTURE_GEN_T);
			glEnable(GL_TEXTURE_2D);
		}

// Color porta-eix motriu sense textura
	glColor4f(0.5f,0.7f,1.0f,0.5f);

// Porta-eix motriu mig
	glPushMatrix();
	  glTranslatef(0.0f,82.0f,-5.0f);
	  glScalef(1.0f, 5.0f, 1.0f);
	  glutSolidCube(10.0f);
	glPopMatrix();

	if (textu) glDisable(GL_TEXTURE_2D);

// Conjunt eixos i rodes eix mig
	glPushMatrix();
// Desplaçament Eix Mig
	  glTranslatef(0.0f,72.0f,0.0f);

// Color eix sense textura
	  glColor4f(0.1f,0.4f,1.0f,0.5f);

// Eix Mig Davanter
	  glPushMatrix();
	    glTranslatef(0.0f,0.0f,-10.0f);
	    glRotatef(90.0f,0.0f,1.0f,0.0f);
	    glTranslatef(0.0f,0.0f,-13.0f);
		gluCilindre(2, 2, 26.0f, 6, 1);
	  glPopMatrix();
	
// Roda Dreta Davantera Eix Mig Davanter
	  glPushMatrix();
	    glTranslatef(-10.0f,0.0f,-10.0f);
	    neumatic(textu,VTextu);
	  glPopMatrix();

// Roda Esquerra Davantera Eix Mig Davanter
	  glPushMatrix();
	    glTranslatef(17.0f,0.0f,-10.0f);
	    neumatic(textu,VTextu);
	  glPopMatrix();

// Desactivar textura
	if (textu) glDisable(GL_TEXTURE_2D);

// Desplaçament entre dos eixos
	  glTranslatef(0.0f,25.0f,0.0f);

// Color eix sense textura
	  glColor4f(0.1f,0.4f,1.0f,0.5f);

// Eix Mig Darrera
	  glPushMatrix();
	    glTranslatef(0.0f,0.0f,-10.0f);
	    glRotatef(90.0f,0.0f,1.0f,0.0f);
	    glTranslatef(0.0f,0.0f,-13.0f);
		gluCilindre(2, 2, 26.0f, 6, 1);
	  glPopMatrix();
	
// Roda Dreta Davantera Eix Mig Darrera
	  glPushMatrix();
	    glTranslatef(-10.0f,0.0f,-10.0f);
	    neumatic(textu,VTextu);
	  glPopMatrix();

// Roda Esquerra Davantera Eix Mig Darrera
	  glPushMatrix();
	    glTranslatef(17.0f,0.0f,-10.0f);
	    neumatic(textu,VTextu);
	  glPopMatrix();

// Fi conjunt d'eixos i rodes eix mig
    glPopMatrix();

// Desactivar textura
	if (textu) glDisable(GL_TEXTURE_2D);
		
// REMOLC	
// Textura carrosseria
	if (textu)
		{	GLfloat sPlane[4] = { 0.05f, 0.0f, 0.00f, 0.250f };
		  	GLfloat tPlane[4] = { 0.00f, 0.05f, 0.1f, 0.00f };

// Activar textura
			glBindTexture(GL_TEXTURE_2D,VTextu[5]);
	
			glTexGenfv(GL_S, GL_OBJECT_PLANE, sPlane);
			glTexGenfv(GL_T, GL_OBJECT_PLANE, tPlane);
			
			glTexGeni(GL_S,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
			glTexGeni(GL_T,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
			glEnable(GL_TEXTURE_GEN_S);
			glEnable(GL_TEXTURE_GEN_T);
			glEnable(GL_TEXTURE_2D);
		}


// Color plataforma sense textura
	glColor4f(0.5f,0.7f,1.0f,0.5f);

// Plataforma
	glPushMatrix();
		glTranslatef(0.0f,127.0f,4.0f);
		glScalef(3.0f, 14.0f, 0.8f);
		glutSolidCube(10.0f);
	glPopMatrix();

// Textura Cisterna
	if (textu)
		{	glBindTexture(GL_TEXTURE_2D,VTextu[6]);
			glTexGeni(GL_S,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
			glTexGeni(GL_T,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
			glEnable(GL_TEXTURE_2D);			
		}

// Color cisterna sense textura
	glColor4f(0.9f,0.9f,1.0f,0.5f);

// Cisterna
	glPushMatrix();
	  glTranslatef(0.0f,60.0f,20.0f);
	  glScalef(0.75f,1.0f,0.5f);
	  glRotatef(270.0f,1.0f,0.0f,0.0f);
// Part de davant
	  gluCilindre(20, 25, 5.0f, 25, 1);
	  glPushMatrix();
	  	glRotatef(180.0f,1.0f,0.0f,0.0f);
		gluDisc(0.0f, 20.0f, 25, 1);	
	  glPopMatrix();
// Part Central
	  glTranslatef(0.0f,0.0f,5.0f);
	  gluCilindre(25, 25, 125.0f, 25, 1);
// Part Darrera
	  glPushMatrix();
		glTranslatef(0.0f,0.0f,125.0f);
		gluCilindre(25, 20, 5.0f, 25, 1);
		glTranslatef(0.0f,0.0f,5.0f);
		gluDisc(0.0f, 20.0f, 25, 1);	
	  glPopMatrix();
	glPopMatrix();

// Desactivar textura
//	if (textu) glDisable(GL_TEXTURE_2D);

// Textura planxa
	if (textu)  
		{	
			GLfloat sPlane[4] = { 0.05f, 0.0f, 0.00f, 0.250f };
		  	GLfloat tPlane[4] = { 0.00f, 0.05f, 0.1f, 0.00f };
// Activar textura planxa
			glBindTexture(GL_TEXTURE_2D,VTextu[5]) ;
	
			glTexGenfv(GL_S, GL_OBJECT_PLANE, sPlane);
			glTexGenfv(GL_T, GL_OBJECT_PLANE, tPlane);
			
			glTexGeni(GL_S,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
			glTexGeni(GL_T,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
			glEnable(GL_TEXTURE_GEN_S);
			glEnable(GL_TEXTURE_GEN_T);
			glEnable(GL_TEXTURE_2D);
		}

// Color porta-eix motriu
	glColor4f(0.5f,0.7f,1.0f,0.5f);

// Porta-eix motriu darrera
	glPushMatrix();
	  glTranslatef(0.0f,172.0f,-5.0f);
	  glScalef(1.0f, 5.0f, 1.0f);
	  glutSolidCube(10.0f);
	glPopMatrix();

// Desactivar textura
	if (textu) glDisable(GL_TEXTURE_2D);

// Conjunt eixos i rodes eix darrera
	glPushMatrix();

// Desplaçament Eix Darrera
	  glTranslatef(0.0f,162.0f,0.0f);

// Color eix sense textura
	  glColor4f(0.1f,0.4f,1.0f,0.5f);

// Eix Darrera Davanter
	  glPushMatrix();
	    glTranslatef(0.0f,0.0f,-10.0f);
	    glRotatef(90.0f,0.0f,1.0f,0.0f);
	    glTranslatef(0.0f,0.0f,-13.0f);
		gluCilindre(2, 2, 26.0f, 6, 1);
	  glPopMatrix();
	
// Roda Dreta Davantera Eix Darrera Davanter
	  glPushMatrix();
	    glTranslatef(-10.0f,0.0f,-10.0f);
	    neumatic(textu,VTextu);
	  glPopMatrix();

// Roda Esquerra Davantera Eix Darrera Davanter
	  glPushMatrix();
	    glTranslatef(17.0f,0.0f,-10.0f);
	    neumatic(textu,VTextu);
	  glPopMatrix();

// Desactivar textura
	if (textu) glDisable(GL_TEXTURE_2D);

// Desplaçament entre dos eixos
	  glTranslatef(0.0f,25.0f,0.0f);

// Color eix sense textura
	  glColor4f(0.1f,0.4f,1.0f,0.5f);

// Eix Darrera Darrera
	  glPushMatrix();
		glTranslatef(0.0f,0.0f,-10.0f);
	 	glRotatef(90.0f,0.0f,1.0f,0.0f);
		glTranslatef(0.0f,0.0f,-13.0f);
		gluCilindre(2, 2, 26.0f, 6, 1);
	  glPopMatrix();
	
// Roda Dreta Davantera Eix Darrera Darrera
	  glPushMatrix();
	    glTranslatef(-10.0f,0.0f,-10.0f);
	    neumatic(textu,VTextu);
	  glPopMatrix();

// Roda Esquerra Davantera Eix Darrera Darrera
	  glPushMatrix();
	    glTranslatef(17.0f,0.0f,-10.0f);
	    neumatic(textu,VTextu);
	  glPopMatrix();
// Fi conjunt eixos i rodes eix darrera
	glPopMatrix();

// Fi dibuix Truck
glPopMatrix();

// Restaurar textura[0]
if (textu)
	{	glBindTexture(GL_TEXTURE_2D,VTextu[0]);
//		glTexGeni(GL_S,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
//		glTexGeni(GL_T,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
		glEnable(GL_TEXTURE_2D);			
	}
}


// Dibuix de roda
// neumatic: Paràmetres:
//    - textur: Flag de textures activades o no.
//    - VTextur: Vector d'imatges textura.
void neumatic(bool textur, GLuint VTextur[NUM_MAX_TEXTURES])
{
// Textura neumàtic
	if (textur)  
		{	
// Activar textura neumàtic
			glBindTexture(GL_TEXTURE_2D,VTextur[1]) ;
			
			glTexGeni(GL_S,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
			glTexGeni(GL_T,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
			glEnable(GL_TEXTURE_2D);
		}

// Color neumàtic sense textura
	glColor4f(0.2f,0.2f,0.2f,0.5f);	

	glPushMatrix();
// Tapa inferior neumàtic
	  glRotatef(90.0f,0.0f,1.0f,0.0f);
	  gluDisc(5.0f, 10.0f, RESOLUCIO_RODA, 1);

// Dibuix de la llanta
	  llanta(textur,VTextur);

// Textura neumàtic
	  if (textur)  
		{	
// Activar textura neumàtic
			glBindTexture(GL_TEXTURE_2D,VTextur[1]) ;	
			glTexGeni(GL_S,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
			glTexGeni(GL_T,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
			glEnable(GL_TEXTURE_2D);
		}

// Color neumàtic sense textura
	glColor4f(0.2f,0.2f,0.2f,0.5f);	

// Gruix del neumàtic
	  glTranslatef(0.0f,0.0f,-6.0f);
	  gluCilindre(10, 10, 6.0f, RESOLUCIO_RODA, 1);
// Tapa superior neumàtic
	  glRotatef(180.0f,0.0f,1.0f,0.0f);
	  gluDisc(5.0f, 10.0f, RESOLUCIO_RODA, 1);
// Dibuix de la llanta
	  llanta(textur,VTextur);
	glPopMatrix();

// Desactivar textures
//	if (textur) glDisable(GL_TEXTURE_2D);

}

// Dibuix de la llanta de la roda
// llanta: Paràmetres:
//    - textur: Flag de textures activades o no.
//    - VTextur: Vector d'imatges textura.
void llanta(bool textur, GLuint VTextur[NUM_MAX_TEXTURES])
{

// Textura de la llanta
	if (textur)  
		{	GLfloat sPlane[4] = { 0.0f, -0.1f, 0.5f, 0.5f };
		  	GLfloat tPlane[4] = { 0.1f, 0.0f, 0.5f, 0.5f };
// Activar la textura
			glBindTexture(GL_TEXTURE_2D,VTextur[2]) ;
			glEnable(GL_TEXTURE_2D) ;
		
			glTexGenfv(GL_S, GL_OBJECT_PLANE, sPlane);
			glTexGenfv(GL_T, GL_OBJECT_PLANE, tPlane);
			
			glTexGeni(GL_S,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR) ;
			glTexGeni(GL_T,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR) ;
			glEnable(GL_TEXTURE_GEN_S) ;
			glEnable(GL_TEXTURE_GEN_T) ;
		}

// Dibuix de la llanta (disc de radi 5 de color clar)
	glColor4f(0.7f,0.7f,0.7f,0.5f);	
	gluDisc(0.0f, 5.0f, RESOLUCIO_RODA, 1);

}


// Mar amb ondulacions
void sea(void)
{
	int i, j, step, it1, it2;
	//     GLfloat pi=3.14159;
	float angle, delay;

	//aigua plana
	/*	glColor3f(0.5,0.4,0.9);
	glNormal3f(0.0,0.0,1.0);
	glBegin(GL_POLYGON);
	glVertex3f(-250,-250,0);
	glVertex3f(250,-250,0);
	glVertex3f(250,250,0);
	glVertex3f(-250,250,0);
	glEnd();*/

	// Aigua amb ondulacions simulades a partir de normals sinusoidals
	step = 5;
	delay = 0;
	it1 = 0;

	//   SeleccionaMaterial(MAT_DEFAULT);	

	float h = 2 * pi*step / 500;
	for (j = -250; j<250 - step; j = j + step)
	{

		delay = 1.0*h*it1;

		it2 = 0;
		glColor3f(0.5f, 0.4f, 0.9f);
		for (i = -250; i<250 - step; i = i + step)
		{
			glBegin(GL_POLYGON);
			angle = 1.0*it2*h * 15;
			glNormal3f(-cos(angle), 0, 1);
			glVertex3f(i, j, 0);

			angle = 1.0*(it2 + 1)*h * 15;
			glNormal3f(-cos(angle), 0, 1);
			glVertex3f(i + step, j, 0);

			angle = 1.0*(it2 + 1)*h * 15;
			glNormal3f(-cos(angle), 0, 1);
			glVertex3f(i + step, j + step, 0);
			glEnd();

			glBegin(GL_POLYGON);
			angle = 1.0*it2*h * 15;
			glNormal3f(-cos(angle), 0, 1);
			glVertex3f(i, j, 0);

			angle = 1.0*(it2 + 1)*h * 15;
			glNormal3f(-cos(angle), 0, 1);
			glVertex3f(i + step, j + step, 0);

			angle = 1.0*it2*h * 15;
			glNormal3f(-cos(angle), 0, 1);
			glVertex3f(i, j + step, 0);
			glEnd();
			it2++;
		}
		it1++;
	}

}
