// StatVw.cpp : implementation of the CStatView class
//

#include "stdafx.h"
#include "Stat.h"

#include "StatDoc.h"
#include "StatVw.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStatView

IMPLEMENT_DYNCREATE(CStatView, CView)

BEGIN_MESSAGE_MAP(CStatView, CView)
	//{{AFX_MSG_MAP(CStatView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStatView construction/destruction

CStatView::CStatView()
{
	// TODO: add construction code here

}

CStatView::~CStatView()
{
}

BOOL CStatView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CStatView drawing

void CStatView::OnDraw(CDC* pDC)
{
	CStatDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CRect rect = CRect(10, 10, 100, 100);
	pDC->Ellipse(rect);
}

/////////////////////////////////////////////////////////////////////////////
// CStatView printing

BOOL CStatView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CStatView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CStatView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CStatView diagnostics

#ifdef _DEBUG
void CStatView::AssertValid() const
{
	CView::AssertValid();
}

void CStatView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CStatDoc* CStatView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStatDoc)));
	return (CStatDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CStatView message handlers
