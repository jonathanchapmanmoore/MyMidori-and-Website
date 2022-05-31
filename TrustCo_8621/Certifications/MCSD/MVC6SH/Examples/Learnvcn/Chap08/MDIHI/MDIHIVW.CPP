// MdiHiVw.cpp : implementation of the CMdiHiView class
//

#include "stdafx.h"
#include "MdiHi.h"

#include "MdiHiDoc.h"
#include "MdiHiVw.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMdiHiView

IMPLEMENT_DYNCREATE(CMdiHiView, CView)

BEGIN_MESSAGE_MAP(CMdiHiView, CView)
	//{{AFX_MSG_MAP(CMdiHiView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMdiHiView construction/destruction

CMdiHiView::CMdiHiView()
{
	// TODO: add construction code here
	m_strHi = "Hi, MFC!";
}

CMdiHiView::~CMdiHiView()
{
}

BOOL CMdiHiView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMdiHiView drawing

void CMdiHiView::OnDraw(CDC* pDC)
{
	CMdiHiDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	pDC->TextOut(10, 10, m_strHi);
}

/////////////////////////////////////////////////////////////////////////////
// CMdiHiView printing

BOOL CMdiHiView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMdiHiView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMdiHiView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMdiHiView diagnostics

#ifdef _DEBUG
void CMdiHiView::AssertValid() const
{
	CView::AssertValid();
}

void CMdiHiView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMdiHiDoc* CMdiHiView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMdiHiDoc)));
	return (CMdiHiDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMdiHiView message handlers
