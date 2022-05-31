// MyMdiVw.cpp : implementation of the CMyMdiView class
//

#include "stdafx.h"
#include "MyMdi.h"

#include "MyMdiDoc.h"
#include "MyMdiVw.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyMdiView

IMPLEMENT_DYNCREATE(CMyMdiView, CView)

BEGIN_MESSAGE_MAP(CMyMdiView, CView)
	//{{AFX_MSG_MAP(CMyMdiView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyMdiView construction/destruction

CMyMdiView::CMyMdiView()
{
	// TODO: add construction code here

}

CMyMdiView::~CMyMdiView()
{
}

BOOL CMyMdiView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMyMdiView drawing

void CMyMdiView::OnDraw(CDC* pDC)
{
	CMyMdiDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMyMdiView printing

BOOL CMyMdiView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMyMdiView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMyMdiView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMyMdiView diagnostics

#ifdef _DEBUG
void CMyMdiView::AssertValid() const
{
	CView::AssertValid();
}

void CMyMdiView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyMdiDoc* CMyMdiView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyMdiDoc)));
	return (CMyMdiDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyMdiView message handlers
