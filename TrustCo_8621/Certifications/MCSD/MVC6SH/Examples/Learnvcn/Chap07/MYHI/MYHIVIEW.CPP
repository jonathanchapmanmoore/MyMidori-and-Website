////////////////////////////////
//
// MyHiView.cpp
//
////////////////////////////////

#include "stdafx.h"
#include "MyHi.h"

#include "MyHiDoc.h"
#include "MyHiView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyHiView

IMPLEMENT_DYNCREATE(CMyHiView, CView)

BEGIN_MESSAGE_MAP(CMyHiView, CView)
	//{{AFX_MSG_MAP(CMyHiView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyHiView construction/destruction

CMyHiView::CMyHiView()
{
	// TODO: add construction code here

}

CMyHiView::~CMyHiView()
{
}

BOOL CMyHiView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMyHiView drawing

void CMyHiView::OnDraw(CDC* pDC)
{
    CMyHiDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    // TODO: add draw code for native data here
    pDC->TextOut(100, 100, pDoc->m_strText);
}

/////////////////////////////////////////////////////////////////////////////
// CMyHiView printing

BOOL CMyHiView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMyHiView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMyHiView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMyHiView diagnostics

#ifdef _DEBUG
void CMyHiView::AssertValid() const
{
	CView::AssertValid();
}

void CMyHiView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyHiDoc* CMyHiView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyHiDoc)));
	return (CMyHiDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyHiView message handlers

void CMyHiView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	// TODO: Add your specialized code here and/or call the base class
	//Invalidate();
	
}

void CMyHiView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	//Invalidate();
	
}
