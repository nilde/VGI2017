
// EntornVGI.h: archivo de encabezado principal para la aplicaci�n EntornVGI
//
#pragma once

#ifndef __AFXWIN_H__
	#error "incluir 'stdafx.h' antes de incluir este archivo para PCH"
#endif

#include "resource.h"       // S�mbolos principales


// CEntornVGIApp:
// Consulte la secci�n EntornVGI.cpp para obtener informaci�n sobre la implementaci�n de esta clase
//

class CEntornVGIApp : public CWinAppEx
{
public:
	CEntornVGIApp();


// Reemplazos
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementaci�n
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CEntornVGIApp theApp;
