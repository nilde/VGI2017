//******** PRACTICA GRAFICS VISUALITZACI� GR�FICA INTERACTIVA
//******** Entorn basic VS2013 amb interf�cie MFC i Status Bar
//******** Enric Marti (Setembre 2017)
// simple.vert: Vertex Program en GLSL simple.
attribute vec4 gl_Color;
void main()
{
        gl_FrontColor = gl_Color;
        gl_Position = ftransform();
}
