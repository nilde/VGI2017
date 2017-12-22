
#pragma once
#include "rocket.h"
#include "planet.h"
#include <string>
/////////////////////////////////////////////////////////////////////////////
// Ventana de COutputList

class CInformationList : public CListBox
{
	// Construcci�n
public:
	CInformationList();

	// Implementaci�n
public:
	virtual ~CInformationList();

protected:
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnEditCopy();
	afx_msg void OnEditClear();
	afx_msg void OnViewOutput();

	DECLARE_MESSAGE_MAP()
};

class CInformationWnd : public CDockablePane
{
	// Construcci�n
public:
	CInformationWnd();
	void printRocketDetails(Rocket const rocket);
	void UpdateFonts();
	void FillExampleWindow();

	// Atributos
protected:
	CMFCTabCtrl	m_wndTabs;
	CInformationList m_wndInformationDebug;
	CInformationList m_wndInformationReal;

protected:
	
	void AdjustHorzScroll(CListBox& wndListBox);

	// Implementaci�n
public:
	virtual ~CInformationWnd();

protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);

	DECLARE_MESSAGE_MAP()
};

