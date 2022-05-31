// YCoordView.cpp : implementation of the CYCoordView class
//

#include "stdafx.h"
#include "YCoord.h"

#include "YCoordDoc.h"
#include "YCoordView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CYCoordView

IMPLEMENT_DYNCREATE(CYCoordView, CScrollView)

BEGIN_MESSAGE_MAP(CYCoordView, CScrollView)
	//{{AFX_MSG_MAP(CYCoordView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CYCoordView construction/destruction

CYCoordView::CYCoordView()
{
	// TODO: add construction code here

}

CYCoordView::~CYCoordView()
{
}

BOOL CYCoordView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CYCoordView drawing

void CYCoordView::OnDraw(CDC* pDC)
{
	CYCoordDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
    CRect rect = CRect(10, 10, 110, 110);
    pDC->Rectangle(rect);

}

void CYCoordView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

/////////////////////////////////////////////////////////////////////////////
// CYCoordView printing

BOOL CYCoordView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CYCoordView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CYCoordView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CYCoordView diagnostics

#ifdef _DEBUG
void CYCoordView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CYCoordView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CYCoordDoc* CYCoordView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CYCoordDoc)));
	return (CYCoordDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CYCoordView message handlers
