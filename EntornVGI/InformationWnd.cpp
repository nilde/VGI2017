
#include "stdafx.h"

#include "InformationWnd.h"
#include "Resource.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInformationBar

CInformationWnd::CInformationWnd()
{
}

CInformationWnd::~CInformationWnd()
{
}

BEGIN_MESSAGE_MAP(CInformationWnd, CDockablePane)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()

int CInformationWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	CRect rectDummy;
	rectDummy.SetRectEmpty();

	// Crear ventana de pestañas:
	if (!m_wndTabs.Create(CMFCTabCtrl::STYLE_FLAT, rectDummy, this, 1))
	{
		TRACE0("No se pudo crear la ventana de pestañas de resultados\n");
		return -1;      // no se pudo crear
	}

	// Crear paneles de resultados:
	const DWORD dwStyle = LBS_NOINTEGRALHEIGHT | WS_CHILD | WS_VISIBLE | WS_HSCROLL | WS_VSCROLL;

	if (!m_wndInformationRocket.Create(dwStyle, rectDummy, &m_wndTabs, 2) ||
		!m_wndInformationPlanet.Create(dwStyle, rectDummy, &m_wndTabs, 3))
	{
		TRACE0("No se pudieron crear las ventanas de salida\n");
		return -1;      // no se pudo crear
	}

	UpdateFonts();

	CString strTabName;
	BOOL bNameValid;

	// Adjuntar ventanas de lista a la pestaña:
	bNameValid = strTabName.LoadString(IDS_ROCKET_TAB);
	ASSERT(bNameValid);
	m_wndTabs.AddTab(&m_wndInformationRocket, strTabName, (UINT)0);
	bNameValid = strTabName.LoadString(IDS_PLANET_TAB);
	ASSERT(bNameValid);
	m_wndTabs.AddTab(&m_wndInformationPlanet, strTabName, (UINT)1);

	// Rellenar pestañas de resultados con texto ficticio (nada especial)
	FillExampleWindow();

	return 0;
}

void CInformationWnd::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);

	// El control de pestaña debe cubrir todo el área cliente:
	m_wndTabs.SetWindowPos(NULL, -1, -1, cx, cy, SWP_NOMOVE | SWP_NOACTIVATE | SWP_NOZORDER);
}

void CInformationWnd::AdjustHorzScroll(CListBox& wndListBox)
{
	CClientDC dc(this);
	CFont* pOldFont = dc.SelectObject(&afxGlobalData.fontRegular);

	int cxExtentMax = 0;

	for (int i = 0; i < wndListBox.GetCount(); i++)
	{
		CString strItem;
		wndListBox.GetText(i, strItem);

		cxExtentMax = max(cxExtentMax, (int)dc.GetTextExtent(strItem).cx);
	}

	wndListBox.SetHorizontalExtent(cxExtentMax);
	dc.SelectObject(pOldFont);
}


void CInformationWnd::FillExampleWindow()
{
	m_wndInformationRocket.AddString(_T("Inicia la simulación para ver los datos del cohete."));
	m_wndInformationPlanet.AddString(_T("Inicia la simulación para ver los datos del planeta."));

}


void CInformationWnd::UpdateFonts()
{
	m_wndInformationRocket.SetFont(&afxGlobalData.fontRegular);
	m_wndInformationPlanet.SetFont(&afxGlobalData.fontRegular);
}

/////////////////////////////////////////////////////////////////////////////
// COutputList1

CInformationList::CInformationList()
{
}

CInformationList::~CInformationList()
{
}

BEGIN_MESSAGE_MAP(CInformationList, CListBox)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
	ON_COMMAND(ID_EDIT_CLEAR, OnEditClear)
	ON_COMMAND(ID_VIEW_OUTPUTWND, OnViewOutput)
	ON_WM_WINDOWPOSCHANGING()
END_MESSAGE_MAP()
/////////////////////////////////////////////////////////////////////////////
// Controladores de mensajes de COutputList

void CInformationList::OnContextMenu(CWnd* /*pWnd*/, CPoint point)
{
	CMenu menu;
	menu.LoadMenu(IDR_OUTPUT_POPUP);

	CMenu* pSumMenu = menu.GetSubMenu(0);

	if (AfxGetMainWnd()->IsKindOf(RUNTIME_CLASS(CMDIFrameWndEx)))
	{
		CMFCPopupMenu* pPopupMenu = new CMFCPopupMenu;

		if (!pPopupMenu->Create(this, point.x, point.y, (HMENU)pSumMenu->m_hMenu, FALSE, TRUE))
			return;

		((CMDIFrameWndEx*)AfxGetMainWnd())->OnShowPopupMenu(pPopupMenu);
		UpdateDialogControls(this, FALSE);
	}

	SetFocus();
}

void CInformationList::OnEditCopy()
{
	MessageBox(_T("Copiar resultado"));
}

void CInformationList::OnEditClear()
{
	MessageBox(_T("Borrar resultado"));
}

void CInformationList::OnViewOutput()
{
	/*
	CDockablePane* pParentBar = DYNAMIC_DOWNCAST(CDockablePane, GetOwner());
	CMDIFrameWndEx* pMainFrame = DYNAMIC_DOWNCAST(CMDIFrameWndEx, GetTopLevelFrame());

	if (pMainFrame != NULL && pParentBar != NULL)
	{
		pMainFrame->SetFocus();
		pMainFrame->ShowPane(pParentBar, FALSE, FALSE, FALSE);
		pMainFrame->RecalcLayout();

	}
	*/
}
void CInformationWnd::printRocketDetails(Rocket const rocket) {
	CString str;
	for (int i = m_wndInformationRocket.GetCount() - 1; i >= 0; i--) {
		m_wndInformationRocket.DeleteString(i);
	}
	//ax,ay,az,m_alpha,m_x,m_y,m_z,vx,vy,vz
	str.Format(_T("Aceleración en el eje X: %.3f "),rocket.ax);
	m_wndInformationRocket.AddString(str);
	str.Format(_T("Aceleración en el eje Y: %.3f "), rocket.ay);
	m_wndInformationRocket.AddString(str);
	str.Format(_T("Aceleración en el eje Z: %.3f "), rocket.az);
	m_wndInformationRocket.AddString(str);
	str.Format(_T("Posición en el eje X: %.1d "), rocket.m_x);
	m_wndInformationRocket.AddString(str);
	str.Format(_T("Posición en el eje Y: %.1d "), rocket.m_y);
	m_wndInformationRocket.AddString(str);
	str.Format(_T("Posición en el eje Z: %.1d "), rocket.m_z);
	m_wndInformationRocket.AddString(str);
	str.Format(_T("Angulo alpha: %.1d "), rocket.m_alpha);
	m_wndInformationRocket.AddString(str);
	str.Format(_T("Velocidad en el eje X: %.3f "), rocket.vx);
	m_wndInformationRocket.AddString(str);
	str.Format(_T("Velocidad en el eje Y: %.3f "), rocket.vy);
	m_wndInformationRocket.AddString(str);
	str.Format(_T("Velocidad en el eje Z: %.3f "), rocket.vz);
	m_wndInformationRocket.AddString(str);
}