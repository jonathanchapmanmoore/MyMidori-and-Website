// bballVw.cpp : implementation of the CBballView class
//

#include "stdafx.h"
#include "bball.h"

#include "bballDoc.h"
#include "bballVw.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBballView

IMPLEMENT_DYNCREATE(CBballView, CScrollView)

BEGIN_MESSAGE_MAP(CBballView, CScrollView)
	//{{AFX_MSG_MAP(CBballView)
	ON_COMMAND(ID_VIEW_MODERNTEAMS, OnViewModernteams)
	ON_UPDATE_COMMAND_UI(ID_VIEW_MODERNTEAMS, OnUpdateViewModernteams)
	ON_COMMAND(ID_VIEW_NEVERWON, OnViewNeverwon)
	ON_UPDATE_COMMAND_UI(ID_VIEW_NEVERWON, OnUpdateViewNeverwon)
	ON_COMMAND(ID_VIEW_WORLDSERIESWINNERS, OnViewWorldserieswinners)
	ON_UPDATE_COMMAND_UI(ID_VIEW_WORLDSERIESWINNERS, OnUpdateViewWorldserieswinners)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBballView construction/destruction

CBballView::CBballView()
{
	// TODO: add construction code here
	m_opType = opShowTeams;
}

CBballView::~CBballView()
{
}

BOOL CBballView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CBballView drawing

void CBballView::OnDraw(CDC* pDC)
{
	CBballDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	switch(m_opType)
	{
	case opShowTeams: ShowTeams(pDC);
		break;
	case opShowWinners: ShowSeriesWinners(pDC);
		break;
	case opShowNoWins: ShowNeverWon(pDC);
		break;
	default:;
	}
}

/////////////////////////////////////////////////////////////////////////////
// CBballView printing

BOOL CBballView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CBballView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CBballView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CBballView diagnostics

#ifdef _DEBUG
void CBballView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CBballView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CBballDoc* CBballView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBballDoc)));
	return (CBballDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBballView message handlers

void CBballView::ShowTeams(CDC *pDC)
{
	CBballDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->SetTitle(m_strTitle + " - Teams");


	const int MARGIN_LEFT = 5;
	CString strTeam;
	int nLength = pDoc->arTeams.GetSize();
	for(int nLines = 0; nLines < nLength; nLines++)
	{
		strTeam = pDoc->arTeams[nLines];
		pDC->TextOut(MARGIN_LEFT, nLines * m_nHeightLine, strTeam);
	}
}

void CBballView::ShowSeriesWinners(CDC *pDC)
{
	CBballDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->SetTitle(m_strTitle + " - World Series Winners");


	const int MARGIN_LEFT = 5;
	CString strTeam;
	int nLength = pDoc->arWinners.GetSize();
	for(int nLines = 0; nLines < nLength; nLines++)
	{
		strTeam = pDoc->arWinners[nLines];
		pDC->TextOut(MARGIN_LEFT, nLines * m_nHeightLine, strTeam);
	}

}

void CBballView::ShowNeverWon(CDC *pDC)
{
	CBballDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->SetTitle(m_strTitle + " - Never Won World Series");


	const int MARGIN_LEFT = 5;
	CString strTeam;
	int nLength = pDoc->arNoWins.GetSize();
	for(int nLines = 0; nLines < nLength; nLines++)
	{
		strTeam = pDoc->arNoWins[nLines];
		pDC->TextOut(MARGIN_LEFT, nLines * m_nHeightLine, strTeam);
	}
}

void CBballView::OnInitialUpdate() 
{
	CScrollView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	// Specify sizes for scrolling
	SetDocSize();
	// Get window title for later use
	CBballDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	m_strTitle = pDoc->GetTitle();
}

void CBballView::OnViewModernteams() 
{
	// TODO: Add your command handler code here
	m_opType = opShowTeams;
	CBballDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->UpdateAllViews(NULL);
}

void CBballView::OnUpdateViewModernteams(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
}

void CBballView::OnViewNeverwon() 
{
	// TODO: Add your command handler code here
	m_opType = opShowNoWins;
	ListNeverWinners();
	CBballDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->UpdateAllViews(NULL);
}

void CBballView::OnUpdateViewNeverwon(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}

void CBballView::OnViewWorldserieswinners() 
{
	// TODO: Add your command handler code here
	m_opType = opShowWinners;
	CBballDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->UpdateAllViews(NULL);
}

void CBballView::OnUpdateViewWorldserieswinners(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}

void CBballView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	// TODO: Add your specialized code here and/or call the base class
	SetDocSize();
	SetScrollPos(SB_VERT, 0);   // Undo any scrolling
	Invalidate();
}

int CBballView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CScrollView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	CClientDC dc(this);
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);
	m_nHeightLine = tm.tmHeight + tm.tmExternalLeading;

	return 0;
}

void CBballView::SetDocSize()
{
	CBballDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	int nLines;
	switch(m_opType)
	{
	case opShowTeams: nLines = pDoc->arTeams.GetSize();
		break;
	case opShowWinners: nLines = pDoc->arWinners.GetSize();
		break;
	case opShowNoWins: nLines = pDoc->arNoWins.GetSize();
		break;
	}

	int nHeight = nLines * m_nHeightLine + 20;
	CSize sizeTotal = CSize(0, nHeight);
	CSize sizePage = CSize(0, nHeight / 3);
	CSize sizeLine = CSize(0, m_nHeightLine);
	SetScrollSizes(MM_TEXT, sizeTotal, sizePage, sizeLine);	
}

void CBballView::ListNeverWinners()
{
	CBballDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// Compare each modern team with list of past winners
	// Add team to list if not found in winner list
	const int YEAR_LEN = 5;
	int nTeams = pDoc->arTeams.GetSize();
	int nWinners = pDoc->arWinners.GetSize();
	CString strTeam, strWinner;
	bool bHasWon = false;
	int nIndexNoWin = 0;

	for(int i = 0; i < nTeams; i++)
	{
		strTeam = pDoc->arTeams[i];
		for(int j = 0; j < nWinners; j++)
		{
			strWinner = pDoc->arWinners[j];
			int nLen = strWinner.GetLength();
			strWinner = strWinner.Right(nLen - YEAR_LEN);
			if(strTeam == strWinner)
			{
				bHasWon = true;
				break;	// Eliminate this team - they've won
			}
		}
		if(!bHasWon)
			pDoc->arNoWins[nIndexNoWin++] = strTeam;
		bHasWon = false;  // Reset for next team
	}

	// Write the non-winners to a text file
	pDoc->WriteNonWinners();
}
