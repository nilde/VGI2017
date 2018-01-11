//******** PRACTICA VISUALITZACI� GR�FICA INTERACTIVA (Escola Enginyeria - UAB)
//******** Entorn b�sic VS2013 MULTIFINESTRA amb OpenGL, interf�cie MFC i Status Bar
//******** Ferran Poveda, Marc Vivet, Carme Juli�, D�bora Gil, Enric Mart� (Setembre 2017)
// EntornVGIView.h : interface of the CEntornVGI class
//
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include "MainFrm.h"

// Entorn VGI: Constants de l'aplicaci� entorn VGI
#include "constants.h"

// Entorn VGI: Includes shaders GLSL
#include <gl/glew.h>
#include <gl/wglew.h>

// Entorn VGI: Llibreries OpenGL
//#include <gl/gl.h>
//#include <gl/glu.h>
//#include <gl/glut.h>

// Entorn VGI: OBJECTE 3DS. Include per la definici� de l'objecte Obj_3DS
#include "Obj3DS.h"	

// Entorn VGI: OBJECTE OBJ. Include per la definici� de l'objecte Obj_OBJ
#include "objLoader.h"	
#include "AnimaController.h"

#include <mmsystem.h>


class CEntornVGIView : public CView
{
protected: // Crear s�lo a partir de serializaci�n
	CEntornVGIView();
	DECLARE_DYNCREATE(CEntornVGIView)

// Atributos
public:
	bool firstIter = true;

	float altura;

	int iter = 0;

	float dist = 10;

	AnimaController animaController;

	CEntornVGIDoc* GetDocument() const;

//-------------- Entorn VGI: Variables globals de CPractivaView
	HGLRC	 m_hrc;		// OpenGL Rendering Context 

// Entorn VGI: Variables de control per Men� Veure->Pantalla Completa 
	bool fullscreen;	// Opci� booleana per Pantalla Completal [0:NO,1:SI]

// Entorn VGI: Variables de control per Men� Vista: canvi PV interactiu, Zoom i dibuixar eixos 
	bool mobil;	 // Opci� canvi de Punt de Vista interactiu (mobil) [0:NO,1:SI]
	bool zzoom;	 // Opci� Zoom interactiu (zoom) [0:NO,1:SI]
	bool satelit; // Opci� de navegaci� animada al volt de l'objecte centrat definint increment per mouse (SAT�LIT)
	bool pan;    // Opcio Pan. Despla�ament del centre de l'esfera de Vista [0:NO,1:SI]
	bool navega; // Opci� Navega [F:NO,T:SI].
	bool eixos;	 // Opci� per dibuixar els eixos X,Y,Z (Eixos?) [0:NO,1:SI]

// Entorn VGI: Variables de l'opci� Vista->Pan
	float fact_pan;	  // Factor de despla�ament de la c�mara (opci� pan).
	CPunt3D tr_cpv;   // Vector de Traslaci� del Centre del Punt de Vista actiu dins opci� pan.
	CPunt3D tr_cpvF;  // Vector de Traslaci� del Centre del Punt de Vista (fixat amb INSERT dins opci� pan) 
					  //       i actiu fora l'opci� pan.

// Entorn VGI: Variables de control de l'opci� Vista->Navega?
	GLfloat n[3];   // Punt cap on mira.
	CPunt3D opvN;   // Definici� Or�gen Punt de Vista (en coordenades m�n)
	CPunt3D opvNStatic1;
	float angleZ;   // angle de rotaci� de la traject�ria.

// Entorn VGI: Variables de control per les opcions de men� Projecci�, Objecte
	char projeccio;	// Men� Projecci�: Tipus de projeccio 
	char objecte;	// Men� Objecte: Tipus d'Objecte

// Entorn VGI: Variables de control del men� Transforma
	bool transf;	// Booleana per activar Transformacions (true) o no (false).
	bool trasl;		// Booleana d'activaci� de la Traslaci� (true) o no (false).
	bool rota;		// Booleana d'activaci� de la Rotaci� (true) o no (false).
	bool escal;		// Booleana d'activaci� de l'Escalatge (true) o no (false).
	float fact_Tras, fact_Rota;	// Increments de Traslaci� i Rotaci�.
	INSTANCIA TG;	// Estructura que cont� TG del men� Transforma actiu dins qualsevol opci� de Transforma 
					//      (Traslaci� Rotaci� i Escalatge).
	INSTANCIA TGF;	// Estructura que cont� TG del men� Transforma fixat amb INSERT dins les opcions de Transforma
					//     i actiu fora l'opci� Transforma.
	bool transX;	// Opci� Mobil Eix X?: TG interactives per l'eix X via mouse [F:NO,T:SI].
	bool transY;	// Opci� Mobil Eix Y?: TG interactives per l'eix Y via mouse [F:NO,T:SI].
	bool transZ;	// Opci� Mobil Eix Z?: TG interactives per l'eix Z via mouse [F:NO,T:SI].

// Entorn VGI: Variables de control per les opcions de men� Ocultacions
	bool test_vis;  // Men� ocultacions: Activa [true] o desactiva [false] Test Visibilitat.
	bool oculta;    // Men� ocultacions: Activa [true] o desactiva [false] Ocultacions (Z-buffer).
	bool back_line; // Men� ocultacions: Activa [true] o desactiva [false] dibuix cares back com a l�nies.

// Entorn VGI: Variables de control del men� Iluminaci�	
	bool ifixe;         // Iluminaci� fixe independent del PV (ifixe=1) 
						// o depenent (mobil) respecte el PV (casc miner) (ifixe=0)
	char ilumina;		// Tipus d'il.luminaci� [FILFERROS 'f',PLANA 'c',SUAU 'c']
	bool sw_material[4];// Variable que controla els coeficients de reflectivitat del material [TRUE] o no [FALSE]:
	// [0]: emission, [1]: ambient, [2]: difusa, [3] especular.
	bool sw_material_old[4]; // Variable que guarda els valors de sw_material mentre no hi ha reflectivitat de material (refl_material=false).
	bool textura;       // Control de textures desactivades [0:NO] o activades [1:SI]
	char t_textura;		// Tipus de textures (predefinides o per fitxer)
	bool textura_map;	// Mapping de textura modulat amb la llum [TRUE] o calcat [FALSE]

// Entorn VGI: Variables de control del men� Llums
	bool llum_ambient;	// Booleana que controla la llum ambient (SI/NO).
	LLUM llumGL;		// Llum 0
	bool sw_llambient;	// Booleana que controla modus de configurar el color de la llum ambient [TRUE] o no [FALSE]
	CColor col_llambient;// Color llum ambient.

// Entorn VGI: Variables de control del men� Shaders
	bool sw_shader;			// Variable que controla si els shaders s�n actius [TRUE] o no [FALSE]
	char shader_menu;		// Variable que defineix el shader actiu
	GLuint shader_program;	// Shader Program que cont� el Vertex i Fragment program.

// Entorn VGI: Variables butons de mouse 
	CPoint m_PosEAvall, m_PosDAvall; // Coordenades del cursor quan el boto esquerre(E) o dret(D) del 
									 //    mouse ha estat clicat.
	bool m_ButoEAvall, m_ButoDAvall; //TRUE si el boto esquerre(E) o dret(D) del mouse esta clicat.
	CEsfe3D m_EsfeEAvall;			 // Coordenades Esf�riques del PV (OPV) quan el boto esquerre(E) o dret(D) del 
	//										mouse ha estat clicat.
	CEsfe3D m_EsfeIncEAvall;		 // Increment de despla�ament en coordenades Esf�riques del PV (OPV).

// Entorn VGI: Variables que controlen par�metres visualitzaci�: Mides finestra Windows i PV
	int w, h;				// Mides de la finestra Windows (w-amplada,h-al�ada)
	CEsfe3D OPV;			// Par�metres camera en coord. esf�riques (R,alfa,beta)
	char Vis_Polar;			// Variable que controla orientaci� dels eixos en Visualitzaci� Interactiva (POLARZ,POLARY,POLARX)
	GLfloat center[3];   // Punt cap on mira.

	float cfr, cfg, cfb;

// Entorn VGI: Color de fons i de l'objecte
	bool fonsR, fonsG, fonsB;	// Booleanes per controlar variaci� de color per teclat.
	CColor c_fons;			// Intensitat de color de fons.
	bool sw_color;			// Booleana que controla el modus de configurar color de l'objecte per teclat [TRUE] o no [FALSE]
	CColor col_obj;			// Color de l'objecte simple.

// Entorn VGI: Objecte 3DS:
	Obj_3DS* Ob3DS;			// Variable d'objecte 3D Studio (*.3DS)

// Entorn VGI: Objecte OBJ:
	COBJModel* ObOBJ;		// Variable d'objecte format OBJ (*.OBJ)
	COBJModel* R0CKET1;
	COBJModel* R0CKET2;
	COBJModel* R0CKET3;
	COBJModel* R0CKET4;
	COBJModel* BUILDING;
	COBJModel* TREE;
	COBJModel* ROCK;
	COBJModel* ROCK_MARTE;
	COBJModel* PLATAFORMA;
	COBJModel* SUBROCKET1;
	COBJModel* SUBROCKET2;

// Entorn VGI: Variables del Timer
	float t;		// Par�metre t pel Timer.
	bool anima;		// Booleana que controla si l'animaci� �s activa (TRUE) o no (FALSE)
					//    dins la funci� de control del rellotge OnTimer.

// Entorn VGI: Variables de l'objecte FRACTAL
	char t_fractal;		// Tipus de fractal.
	char soroll;		// Men� Fractals: Tipus de soroll
	int pas, pas_ini;	// Resoluci� del fractal inicial (pas_ini) i de visualitzaci� (pas).
	bool sw_il;			// Booleana que controla si cal compilar el fractal (sw_il=1) o no (sw_il=0)
	bool palcolFractal;	// Booleana que activa coloraci� del fractal segons paleta de colors [TRUE] o no [FALSE].

// Entorn VGI: Altres variables
	GLfloat mida;	// Factor d'escala per calcular Volum de Visualitzaci� de l'objecte que encaixi.
	CString nom;	// Nom de fitxer.
	CString buffer; // Buffer que magatzema string caracters corresponent a variables float a printar en Status Bar (funci� Barra_Estat).
//-------------- Entorn VGI: Fi De Variables globals de CEntornVGIView

// Reemplazos
public:
	virtual void OnDraw(CDC* pDC);  // Reemplazado para dibujar esta vista
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Funcions de c�rrega i activaci� de shaders
	void InitAPI();
	void GetGLVersion(int* major, int* minor);
	void OnInitialUpdate();

// Implementaci�n
public:
	virtual ~CEntornVGIView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	void CEntornVGIView::configura_Escena();
	void CEntornVGIView::dibuixa_Escena();
	void CEntornVGIView::Barra_Estat();
	void CEntornVGIView::float2CString(float varf);
	int CEntornVGIView::Log2(int num);							// Log2: C�lcul del log base 2 de num
	char * CEntornVGIView::CString2Char(CString entrada);		// Conversi� string CString --> char *
	void CEntornVGIView::Refl_MaterialOff();					// Desactivar Reflexi� de Material
	void CEntornVGIView::Refl_MaterialOn();						// Activar Reflexi� de Material

// Entorn VGI: Funcions de c�rrega i activaci� de shaders
	GLuint CEntornVGIView::initializeShaders(CString filename);
	char *CEntornVGIView::textFileRead(char *fn);
	void CEntornVGIView::releaseAllShaders();

// // Entorn VGI: Funcions de tractament de teclat en diferents modus
	void CEntornVGIView::Teclat_ColorObjecte(UINT nChar, UINT nRepCnt);
	void CEntornVGIView::Teclat_ColorFons(UINT nChar, UINT nRepCnt);
	void CEntornVGIView::Teclat_Navega(UINT nChar, UINT nRepCnt);
	void CEntornVGIView::Teclat_Pan(UINT nChar, UINT nRepCnt);
	void CEntornVGIView::Teclat_TransEscala(UINT nChar, UINT nRepCnt);
	void CEntornVGIView::Teclat_TransRota(UINT nChar, UINT nRepCnt);
	void CEntornVGIView::Teclat_TransTraslada(UINT nChar, UINT nRepCnt);

	CMFCStatusBar& GetStatusBar() const
	{
		return ((CMainFrame*)AfxGetMainWnd())->GetStatusBar();
	}

private:

//Rendering Context and Device Context Pointers
	HGLRC     m_hRC;
	CDC*      m_pDC;

// Funciones de asignaci�n de mensajes generadas
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnPaint();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnArxiuObrirFractal();
	afx_msg void OnArxiuObrirFitxerObj();
	afx_msg void OnArxiuObrirFitxer3ds();
	afx_msg void OnVistaMobil();
	afx_msg void OnUpdateVistaMobil(CCmdUI *pCmdUI);
	afx_msg void OnVistaZoom();
	afx_msg void OnUpdateVistaZoom(CCmdUI *pCmdUI);
	afx_msg void OnVistaPolarsX();
	afx_msg void OnUpdateVistaPolarsX(CCmdUI *pCmdUI);
	afx_msg void OnVistaPolarsY();
	afx_msg void OnUpdateVistaPolarsY(CCmdUI *pCmdUI);
	afx_msg void OnVistaPolarsZ();
	afx_msg void OnUpdateVistaPolarsZ(CCmdUI *pCmdUI);
	afx_msg void OnVistaPan();
	afx_msg void OnUpdateVistaPan(CCmdUI *pCmdUI);
	afx_msg void OnVistaOrigenpan();
	afx_msg void OnVistaNavega();
	afx_msg void OnUpdateVistaNavega(CCmdUI *pCmdUI);
	afx_msg void OnVistaOrigennavega();
	afx_msg void OnVistaEixos();
	afx_msg void OnUpdateVistaEixos(CCmdUI *pCmdUI);
	afx_msg void OnProjeccioPerspectiva();
	afx_msg void OnUpdateProjeccioPerspectiva(CCmdUI *pCmdUI);
	afx_msg void OnObjecteCub();
	afx_msg void OnUpdateObjecteCub(CCmdUI *pCmdUI);
	afx_msg void OnObjecteEsfera();
	afx_msg void OnUpdateObjecteEsfera(CCmdUI *pCmdUI);
	afx_msg void OnObjecteTetera();
	afx_msg void OnUpdateObjecteTetera(CCmdUI *pCmdUI);
	afx_msg void OnObjecteTruck();
	afx_msg void OnUpdateObjecteTruck(CCmdUI *pCmdUI);
	afx_msg void OnTransformaTraslacio();
	afx_msg void OnUpdateTransformaTraslacio(CCmdUI *pCmdUI);
	afx_msg void OnTransformaOrigentraslacio();
	afx_msg void OnTransformaRotacio();
	afx_msg void OnUpdateTransformaRotacio(CCmdUI *pCmdUI);
	afx_msg void OnTransformaOrigenrotacio();
	afx_msg void OnTransformaEscalat();
	afx_msg void OnUpdateTransformaEscalat(CCmdUI *pCmdUI);
	afx_msg void OnTransformaOrigenescalat();
	afx_msg void OnTransformaMobilx();
	afx_msg void OnUpdateTransformaMobilx(CCmdUI *pCmdUI);
	afx_msg void OnTransformaMobily();
	afx_msg void OnUpdateTransformaMobily(CCmdUI *pCmdUI);
	afx_msg void OnTransformaMobilz();
	afx_msg void OnUpdateTransformaMobilz(CCmdUI *pCmdUI);
	afx_msg void OnOcultacionsTestvis();
	afx_msg void OnUpdateOcultacionsTestvis(CCmdUI *pCmdUI);
	afx_msg void OnOcultacionsZbuffer();
	afx_msg void OnUpdateOcultacionsZbuffer(CCmdUI *pCmdUI);
	afx_msg void OnOcultacionsBackline();
	afx_msg void OnUpdateOcultacionsBackline(CCmdUI *pCmdUI);
	afx_msg void OnIluminacioLlumfixe();
	afx_msg void OnUpdateIluminacioLlumfixe(CCmdUI *pCmdUI);
	afx_msg void OnIluminacioFilferros();
	afx_msg void OnUpdateIluminacioFilferros(CCmdUI *pCmdUI);
	afx_msg void OnIluminacioPlana();
	afx_msg void OnUpdateIluminacioPlana(CCmdUI *pCmdUI);
	afx_msg void OnIluminacioGouraud();
	afx_msg void OnUpdateIluminacioGouraud(CCmdUI *pCmdUI);
	afx_msg void OnMaterialEmissio();
	afx_msg void OnUpdateMaterialEmissio(CCmdUI *pCmdUI);
	afx_msg void OnMaterialAmbient();
	afx_msg void OnUpdateMaterialAmbient(CCmdUI *pCmdUI);
	afx_msg void OnMaterialDifusa();
	afx_msg void OnUpdateMaterialDifusa(CCmdUI *pCmdUI);
	afx_msg void OnMaterialEspecular();
	afx_msg void OnUpdateMaterialEspecular(CCmdUI *pCmdUI);
	afx_msg void OnIluminacioTextures();
	afx_msg void OnUpdateIluminacioTextures(CCmdUI *pCmdUI);
	afx_msg void OnIluminacioTexturaFitxerimatge();
	afx_msg void OnUpdateIluminacioTexturaFitxerimatge(CCmdUI *pCmdUI);
	afx_msg void OnLlumsLlumambient();
	afx_msg void OnUpdateLlumsLlumambient(CCmdUI *pCmdUI);
	afx_msg void OnLlumsLlum0();
	afx_msg void OnUpdateLlumsLlum0(CCmdUI *pCmdUI);
	afx_msg void OnShadersSense();
	afx_msg void OnUpdateShadersSense(CCmdUI *pCmdUI);
	afx_msg void OnShadersGouraud();
	afx_msg void OnUpdateShadersGouraud(CCmdUI *pCmdUI);
	afx_msg void OnShadersPhong();
	afx_msg void OnUpdateShadersPhong(CCmdUI *pCmdUI);
	afx_msg void OnVistaSatelit();
	afx_msg void OnUpdateVistaSatelit(CCmdUI *pCmdUI);
	afx_msg void OnProjeccioOrtografica();
	afx_msg void OnUpdateProjeccioOrtografica(CCmdUI *pCmdUI);
	afx_msg void OnObjecteRocket();
	afx_msg void OnUpdateObjecteRocket(CCmdUI *pCmdUI);
	afx_msg void executeTrayectory();
	void OnLaunch();
	afx_msg void OnTrayectoriaStop();
	afx_msg void OnTrayectoriaRestart();
	afx_msg void OnCameraSeguir();
	afx_msg void OnUpdateCameraSeguir(CCmdUI *pCmdUI);
	void Navega();
	afx_msg void OnUpdateTrayectoriaStop(CCmdUI *pCmdUI);
	void setCenterWith(char object);
	afx_msg void OnCameraEsf32864();
	afx_msg void OnUpdateCameraEsf32864(CCmdUI *pCmdUI);
	afx_msg void OnMiraraRocket();
	afx_msg void OnUpdateMiraraRocket(CCmdUI *pCmdUI);
	afx_msg void OnMiraraPlanet();
	afx_msg void OnUpdateMiraraPlanet(CCmdUI *pCmdUI);
	afx_msg void OnPlanetaTierra();
	afx_msg void OnUpdatePlanetaTierra(CCmdUI *pCmdUI);
	afx_msg void OnCoheteUno();
	afx_msg void OnUpdateCoheteUno(CCmdUI *pCmdUI);
	afx_msg void ShowFractal(char*fitxer);
	void insertPlataforma();

	afx_msg void OnCoheteLanzadera();
	afx_msg void OnUpdateCoheteLanzadera(CCmdUI *pCmdUI);
	afx_msg void OnCoheteTres();
	afx_msg void OnUpdateCoheteTres(CCmdUI *pCmdUI);
	afx_msg void OnCoheteQuatre();
	afx_msg void OnUpdateCoheteQuatre(CCmdUI *pCmdUI);


	afx_msg void buildingCreation();
	afx_msg void OnUpdateBuildingCreation(CCmdUI *pCmdUI);
	afx_msg void OnCameraMultiview();
	afx_msg void OnUpdateCameraMultiview(CCmdUI *pCmdUI);
	afx_msg void OnPlanetaMarte();
	afx_msg void OnUpdatePlanetaMarte(CCmdUI *pCmdUI);
	afx_msg void OnPlanetaLuna();
	afx_msg void OnUpdatePlanetaLuna(CCmdUI *pCmdUI);
};

#ifndef _DEBUG  // Versi�n de depuraci�n en EntornVGIView.cpp
inline CEntornVGIDoc* CEntornVGIView::GetDocument() const
   { return reinterpret_cast<CEntornVGIDoc*>(m_pDocument); }
#endif
