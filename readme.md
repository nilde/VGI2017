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