// ExplView.cpp : implementation of the CExploreView class
//

#include "stdafx.h"
#include "Explore.h"

#include "ExplDoc.h"
#include "ExplView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExploreView

IMPLEMENT_DYNCREATE(CExploreView, CListView)

BEGIN_MESSAGE_MAP(CExploreView, CListView)
	//{{AFX_MSG_MAP(CExploreView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CListView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExploreView construction/destruction

CExploreView::CExploreView()
{
	// TODO: add construction code here

}

CExploreView::~CExploreView()
{
}

BOOL CExploreView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CListView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CExploreView drawing

void CExploreView::OnDraw(CDC* pDC)
{
	CExploreDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CListCtrl& refCtrl = GetListCtrl();
	refCtrl.InsertItem(0, "Item!");
	// TODO: add draw code for native data here
}

void CExploreView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();


	// TODO: You may populate your ListView with items by directly accessing
	//  its list control through a call to GetListCtrl().
}

/////////////////////////////////////////////////////////////////////////////
// CExploreView printing

BOOL CExploreView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CExploreView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CExploreView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CExploreView diagnostics

#ifdef _DEBUG
void CExploreView::AssertValid() const
{
	CListView::AssertValid();
}

void CExploreView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CExploreDoc* CExploreView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExploreDoc)));
	return (CExploreDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CExploreView message handlers
void CExploreView::OnStyleChanged(int nStyleType, LPSTYLESTRUCT lpStyleStruct)
{
	//TODO: add code to react to the user changing the view style of your window
}
