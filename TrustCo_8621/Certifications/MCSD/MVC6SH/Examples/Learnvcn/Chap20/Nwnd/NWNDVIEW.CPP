// nwndView.cpp : implementation of the CNwndView class
//

#include "stdafx.h"
#include "nwnd.h"

#include "nwndDoc.h"
#include "nwndView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNwndView

IMPLEMENT_DYNCREATE(CNwndView, CScrollView)

BEGIN_MESSAGE_MAP(CNwndView, CScrollView)
	//{{AFX_MSG_MAP(CNwndView)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNwndView construction/destruction

CNwndView::CNwndView()
{
	// TODO: add construction code here
	m_nHeightLine = 0;
}

CNwndView::~CNwndView()
{
}

BOOL CNwndView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CNwndView drawing

void CNwndView::OnDraw(CDC* pDC)
{
	CNwndDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CString strNum;
	for(int i = 0; i < 100; i++)
	{
		strNum.Format("%d  ", i);
		pDC->TextOut(5, i * m_nHeightLine, strNum + "Hello, World!");
	}
}

/////////////////////////////////////////////////////////////////////////////
// CNwndView printing

BOOL CNwndView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CNwndView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CNwndView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CNwndView diagnostics

#ifdef _DEBUG
void CNwndView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CNwndView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CNwndDoc* CNwndView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CNwndDoc)));
	return (CNwndDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CNwndView message handlers

int CNwndView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CScrollView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	TEXTMETRIC tm;
	CClientDC dc(this);
	dc.GetTextMetrics(&tm);
	m_nHeightLine = tm.tmHeight + tm.tmExternalLeading;
	return 0;
}

void CNwndView::OnInitialUpdate() 
{
	CScrollView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	CClientDC dc(this);
	CSize size = dc.GetTextExtent("Hello, World!");
	int nWidth = size.cx + 20;
	int nHeight = size.cy * 100 + 20;
	CSize sizeTotal = CSize(nWidth, nHeight);
	CSize sizePage = CSize(nWidth / 2, nHeight / 3);
	CSize sizeLine = CSize(nWidth / 10, nHeight / 10);

	SetScrollSizes(MM_TEXT, sizeTotal, sizePage, sizeLine);

}
