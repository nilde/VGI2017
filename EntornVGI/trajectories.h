//******** PRACTICA VISUALITZACI� GR�FICA INTERACTIVA (Codi Pr�ctica 4)
//********  Marc Vivet, Carme Juli�, D�bora Gil, Enric Mart� (Novembre 2016)
// trajectories.h : Interf�cie de trajectories.cpp
//		Definici� de les funcions per la traject�ria spline:
//                    * spline:  Calcula les coordenades del punt (x,y,z) segons t.
//                    * Dspline: Calcula la tangent segonst t.
//					  * PtsV,PtsH:  Punts de control de la traject�ria del vaixell o l'hidroavi�.
//                    * A:       Matriu dels splines.

#ifndef TRAJECT_H
#define TRAJECT_H

// spline: Funci� per a calcular la posici� de la corba spline segons:
//     * t: par�metre entre (0,1).
//     * ctr: Punts de control.
CPunt3D spline(float t, CPunt3D * ctr);

// Dspline: Funci� per a calcular la primera derivada de la corba spline segons:
//     * t: par�metre entre (0,1).
//     * ctr: Punts de control.
CPunt3D Dspline(float t, CPunt3D * ctr);

// ComputeAngleZ:	C�lcul de l'angle de rotaci� Z entre els vectors
//					eix i tangent projectats sobre el pla X-Y,
float ComputeAngleZ(CPunt3D eix,CPunt3D tangent);

// ComputeAngleX:	C�lcul de l'angle de rotaci� X entre els vectors
//					eix i tangent projectats sobre el pla Y-Z.
float ComputeAngleX(CPunt3D eix,CPunt3D tangent);

// ComputeAngleY:	C�lcul de l'angle de rotaci� Y segons la torsi�
float ComputeAngleY(float angle_nou,float angle_vell);

//Matriu dels Splines
const double A[4][4] =
    {
     {-1.0/6.0,   0.5,  -0.5,  1.0/6.0 },
     {   0.5, -1.0,   0.0,  4.0/6.0 },
     {  -0.5,  0.5,   0.5,  1.0/6.0 },
     { 1.0/6.0,   0.0,   0.0,    0.0   }
    };

//Vector dels punts de control Vaixell
const CPunt3D PtsV[ ]={{256+16,256,3},{-256,256,3},{-256,0,3},{-128-16,0,3},
{-16,64+32+32,3},{256-32,64-32,3},{256+16,256,3},{-256,256,3},{-256,0,3}};

//Vector dels punts de control Hidroavi�
const CPunt3D PtsH[ ]={{256+16,256,30},{-256,256,-10},{-256,0,30},{-128-16,0,75},
{-16,64+32+32,150},{256-32,64-32,75},{256+16,256,30},{-256,256,-10},{-256,0,30}};

// Numero Pts control
const int npts=9;
#endif