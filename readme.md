# VGI2017
---
## SIMULACI�N DE DESPEGUE DE UN COHETE
Descripci�n :
En este proyecto vamos a realizar un simulador de despegues de cohetes usando OpenGL y C.

__PARTICIPANTES:__
1. Rafael D�az Rodr�guez
2. Nil Domene Esteban
3. Jordi Gonz�lez Cano
4. Daniel Herb�n M�ndez
5. Francisco Navarro Morales
6. Jonat�n Luz�n Monta�o

__FUNCIONAMIENTO D ELAS TEXTURAS:__

Para a�adir una textura nueva se tiene que hacer en el visualitzaci�.cpp en la funci�n de Inicialitzar_Textures_Tierra()[NO MODIFICAR EL NOMBRE!!!] o en una funci�n que se cree, pero recomiendo aqu�, ya que as� estan todas juntas. En esa funci�n ya teneis ejemplos de como se tiene que hacer. por el momento solo hay hasta textures[2], as� que la siguiente seria textures[3].

Luego para aplicar la textura, se tiene que hacer antes de crear el objeto en escena.cpp. Se tiene un ejemplo de la TIERRA y de el CIELO, tal como se puede ver a continuaci�n:

				glBindTexture(GL_TEXTURE_2D, texturID[7]);
				glEnable(GL_TEXTURE_2D);
				glColor3f(1.0, 1.0, 1.0);
				glPushMatrix();
				gluEsfera(8000, 1000, 10000);
				glPopMatrix();

el valor de texturID[7], no es random, se tiene que depurar poniendo un breack point en el momento que se hace el loadIMA(".//",[i]) y entrar dentro de esta funci�n. Y ir pasoa  paso hasta al final que se mete en una variable de textura. Una vez se haya ejecutado esa l�nea, se tiene que ver que valor se ha metido en la posici�n i, en este caso un 7.

Por alguna duda contacten con Jordi Gonzalez Cano ;-)






__C�mo hacer pruebas con el tama�o y n�mero de part�culas:__

En particles.h tiene una constante:
	const int static MAX_PARTICLES = 2500;

con el n�mero m�ximo de particulas de TODOS LOS FUEGOS Y HUMOS

el tama�o de los puntos est� en la l�nea 91 de Particles.cpp
Pone: glPointSize(random("size")/10);

Random("size") te da un valor entre 	
	int size_min = 5 y 
	int size_max = 30 que est�n en particles.h y se pueden modificar para un humo concreto
(pero ahora mismo todos los fuegos lo tienen con el valor por defecto)


Luego, puedes cambiar el 10 que va dividiendo al random de size o cambiar el min size y el m�x size.
Lo hago as� porque el random ese que usamos da siempre valores enteros y el 10 lo uso pa poder tener decimales.

Si quieres probar a tocar colores, duraci�n y dem�s. En animaController.cpp tienes, por ejemplp:

	fuego1.red_min = 80;
	fuego1.red_max = 100;
	fuego1.green_min = 0;
	fuego1.green_max = 100;
	fuego1.blue_min = 1;
	fuego1.blue_max = 10;

	fuego1.ORIGIN_Y = 200;
	fuego1.ORIGIN_X = 400;
	fuego1.ORIGIN_Z = -100;

	Adem�s de los colores y la posici�n, puedes cambiar:

	int AGE_DECREMENT;
	int VEL_DECREMENT;
	int UPDATE_VEL_X;
	int UPDATE_VEL_Y;
	int UPDATE_VEL_Z;
	int age_min = 30;
	int age_max = 80;
	int sx_min = -50;
	int sx_max = 50;
	int sy_min = -200;
	int sy_max = -100;// esto son las velocidades
	int sz_min = -50;
	int sz_max = 50;
	int size_min = 5;
	int size_max = 30;

