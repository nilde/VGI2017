//******** PRACTICA VISUALITZACI� GR�FICA INTERACTIVA (Entorn Basic)
//******** Marc Vivet, Carme Juli�, D�bora Gil, Enric Mart�  (Setembre 2016)
// normals.h : interface de normals.cpp
//             Declaracions de les funcions de c�lcul de 
//			   vectors normals per la visualitzaci� dels fractals 


#ifndef NORMALS
#define NORMALS

// -------------- Entorn VGI: Refer�ncia a les quadr�cules zz i normals, definides
//                            a fractals.cpp.
extern double zz[513][513];
extern double normalsC[513][513][3];
extern double normalsV[513][513][3];

// normal: C�lcul del producte vectorial normalitzat de dos vectors v1,v2.
//         Resultat a la variable n.
void normal(double v1[3],double v2[3],double n[3]);

/// normalvertex: C�lcul de les normals unit�ries als VERTEXS
//				  a una triangulaci� de la matriu zz segons el pas 'step'
//				  tenint en compte les normals de les superf�cies ve�nes.
//                S'utilitza en la il.luminaci� SUAU del fractal
void normalvertex(int step);

// normalcara:	C�lcul de les normals unit�ries a les CARES 
//				per una triangulaci� de la matriu zz segons el pas 'step'
//				tenint en compte les normals de les superf�cies ve�nes.
//              S'utilitza en la il.luminaci� PLANA del fractal
void normalcara(int step);

#endif
