
// ChildFrm.cpp: implementaci�n de la clase CChildFrame
//

#include "stdafx.h"
#include "EntornVGI.h"

#include "ChildFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CChildFrame

IMPLEMENT_DYNCREATE(CChildFrame, CMDIChildWndEx)

BEGIN_MESSAGE_MAP(CChildFrame, CMDIChildWndEx)
END_MESSAGE_MAP()

// Construcci�n o destrucci�n de CChildFrame

CChildFrame::CChildFrame()
{
	// TODO: agregar aqu� el c�digo de inicializaci�n de miembros
}

CChildFrame::~CChildFrame()
{
}


BOOL CChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: modificar aqu� la clase Window o los estilos cambiando CREATESTRUCT cs
	if( !CMDIChildWndEx::PreCreateWindow(cs) )
		return FALSE;

	return TRUE;
}

// Diagn�sticos de CChildFrame

#ifdef _DEBUG
void CChildFrame::AssertValid() const
{
	CMDIChildWndEx::AssertValid();
}

void CChildFrame::Dump(CDumpContext& dc) const
{
	CMDIChildWndEx::Dump(dc);
}
#endif //_DEBUG

// Controladores de mensaje de CChildFrame
