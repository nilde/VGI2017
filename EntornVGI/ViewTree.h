
#pragma once

/////////////////////////////////////////////////////////////////////////////
// Ventana de CViewTree

class CViewTree : public CTreeCtrl
{
// Construcci�n
public:
	CViewTree();

// Invalidaciones
protected:
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);

// Implementaci�n
public:
	virtual ~CViewTree();

protected:
	DECLARE_MESSAGE_MAP()
};
