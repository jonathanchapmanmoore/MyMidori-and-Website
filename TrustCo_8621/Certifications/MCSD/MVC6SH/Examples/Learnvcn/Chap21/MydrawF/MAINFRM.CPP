// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "MyDraw.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_VIEW_TOOLBAR_STD, OnViewToolbarStd)
	ON_COMMAND(ID_VIEW_TOOLBAR_DRAWING, OnViewToolbarDrawing)
	ON_UPDATE_COMMAND_UI(ID_VIEW_TOOLBAR_STD, OnUpdateViewToolbarStd)
	ON_UPDATE_COMMAND_UI(ID_VIEW_TOOLBAR_DRAWING, OnUpdateViewToolbarDrawing)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
    // TODO: add member initialization code here
    // Toolbars are initially visible.
    m_bToolBarStdVisible = true;
    m_bToolBarDrawVisible = true;
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBarStd.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBarStd.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create standard toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndToolBarDraw.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_LEFT
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBarDraw.LoadToolBar(IDR_DRAWING))
	{
		TRACE0("Failed to create drawing toolbar\n");
		return -1;      // fail to create
	}

	// Set the style of Drawing toolbar buttons
	const int NUM_DRAW_BUTTONS = 3;
	for(int i = 0; i < NUM_DRAW_BUTTONS; i++)
	{
		m_wndToolBarDraw.SetButtonStyle(i, 
			 m_wndToolBarDraw.GetButtonStyle(i) | TBBS_CHECKGROUP);
	}

	// Set window captions for when toolbars are floating
	m_wndToolBarStd.SetWindowText("Standard");
	m_wndToolBarDraw.SetWindowText("Drawing");

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	// Changed window name while adding new toolbar
	m_wndToolBarStd.EnableDocking(CBRS_ALIGN_ANY);
	m_wndToolBarDraw.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	// Changed name while adding new toolbar
	DockControlBar(&m_wndToolBarStd);
	DockControlBar(&m_wndToolBarDraw);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class
    return m_wndSplitter.Create(this, 2, 2, CSize(1,1), pContext);
//	return CFrameWnd::OnCreateClient(lpcs, pContext);
}

// Next four functions added to handle displaying or hiding
//  the two toolbars. The commands toggle visibility of the toolbars.
void CMainFrame::OnViewToolbarStd() 
{
    // TODO: Add your command handler code here
    m_bToolBarStdVisible = !m_bToolBarStdVisible;
    ShowControlBar(&m_wndToolBarStd, m_bToolBarStdVisible, false);
}

void CMainFrame::OnViewToolbarDrawing() 
{
    // TODO: Add your command handler code here
    m_bToolBarDrawVisible = !m_bToolBarDrawVisible;
    ShowControlBar(&m_wndToolBarDraw, m_bToolBarDrawVisible, false);
}

void CMainFrame::OnUpdateViewToolbarStd(CCmdUI* pCmdUI) 
{
    // TODO: Add your command update UI handler code here
    pCmdUI->SetCheck(m_bToolBarStdVisible);
}

void CMainFrame::OnUpdateViewToolbarDrawing(CCmdUI* pCmdUI) 
{
    // TODO: Add your command update UI handler code here
    pCmdUI->SetCheck(m_bToolBarDrawVisible);
}
