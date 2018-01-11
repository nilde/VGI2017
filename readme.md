# VGI2017
---
## SIMULACIÓN DE DESPEGUE DE UN COHETE
Descripción :
En este proyecto vamos a realizar un simulador de despegues de cohetes usando OpenGL y C.

__PARTICIPANTES:__
1. Rafael Díaz Rodríguez
2. Nil Domene Esteban
3. Jordi González Cano
4. Daniel Herbón Méndez
5. Francisco Navarro Morales
6. Jonatán Luzón Montaño

__FUNCIONAMIENTO D ELAS TEXTURAS:__

Para añadir una textura nueva se tiene que hacer en el visualització.cpp en la función de Inicialitzar_Textures_Tierra()[NO MODIFICAR EL NOMBRE!!!] o en una función que se cree, pero recomiendo aquí, ya que así estan todas juntas. En esa función ya teneis ejemplos de como se tiene que hacer. por el momento solo hay hasta textures[2], así que la siguiente seria textures[3].

Luego para aplicar la textura, se tiene que hacer antes de crear el objeto en escena.cpp. Se tiene un ejemplo de la TIERRA y de el CIELO, tal como se puede ver a continuación:

				glBindTexture(GL_TEXTURE_2D, texturID[7]);
				glEnable(GL_TEXTURE_2D);
				glColor3f(1.0, 1.0, 1.0);
				glPushMatrix();
				gluEsfera(8000, 1000, 10000);
				glPopMatrix();

el valor de texturID[7], no es random, se tiene que depurar poniendo un breack point en el momento que se hace el loadIMA(".//",[i]) y entrar dentro de esta función. Y ir pasoa  paso hasta al final que se mete en una variable de textura. Una vez se haya ejecutado esa línea, se tiene que ver que valor se ha metido en la posición i, en este caso un 7.

Por alguna duda contacten con Jordi Gonzalez Cano ;-)






__Cómo hacer pruebas con el tamaño y número de partículas:__

En particles.h tiene una constante:
	const int static MAX_PARTICLES = 2500;

con el número máximo de particulas de TODOS LOS FUEGOS Y HUMOS

el tamaño de los puntos está en la línea 91 de Particles.cpp
Pone: glPointSize(random("size")/10);

Random("size") te da un valor entre 	
	int size_min = 5 y 
	int size_max = 30 que están en particles.h y se pueden modificar para un humo concreto
(pero ahora mismo todos los fuegos lo tienen con el valor por defecto)


Luego, puedes cambiar el 10 que va dividiendo al random de size o cambiar el min size y el máx size.
Lo hago así porque el random ese que usamos da siempre valores enteros y el 10 lo uso pa poder tener decimales.

Si quieres probar a tocar colores, duración y demás. En animaController.cpp tienes, por ejemplp:

	fuego1.red_min = 80;
	fuego1.red_max = 100;
	fuego1.green_min = 0;
	fuego1.green_max = 100;
	fuego1.blue_min = 1;
	fuego1.blue_max = 10;

	fuego1.ORIGIN_Y = 200;
	fuego1.ORIGIN_X = 400;
	fuego1.ORIGIN_Z = -100;

	Además de los colores y la posición, puedes cambiar:

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

