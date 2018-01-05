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