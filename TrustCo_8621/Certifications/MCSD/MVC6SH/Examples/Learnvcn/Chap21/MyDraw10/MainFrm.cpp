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
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	ON_WM_CREATE()
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
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// Changed window name when adding new toolbar
	// Create the Standard toolbar
	if (!m_wndToolBarStd.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBarStd.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	// Added for new toolbar
    // Create the Drawing toolbar
	if (!m_wndToolBarDraw.CreateEx(this, TBSTYLE_FLAT, WS_CHILD 
        | WS_VISIBLE | CBRS_LEFT | CBRS_GRIPPER | CBRS_TOOLTIPS
        | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
    !m_wndToolBarDraw.LoadToolBar(IDR_DRAWING))
	{
		TRACE0("Failed to create toolbar\n");
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


BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, 
								CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return m_wndSplitter.Create(this, 2, 2, CSize(1,1), 
		pContext);
}
