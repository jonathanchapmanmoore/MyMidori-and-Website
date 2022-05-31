// tabsView.cpp : implementation of the CTabsView class
//

#include "stdafx.h"
#include "tabs.h"

#include "tabsDoc.h"
#include "tabsView.h"

#include <string.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTabsView

IMPLEMENT_DYNCREATE(CTabsView, CView)

BEGIN_MESSAGE_MAP(CTabsView, CView)
	//{{AFX_MSG_MAP(CTabsView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTabsView construction/destruction

CTabsView::CTabsView()
{
	// TODO: add construction code here

}

CTabsView::~CTabsView()
{
}

BOOL CTabsView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTabsView drawing

void CTabsView::OnDraw(CDC* pDC)
{
	CTabsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
	TEXTMETRIC tm;
	pDC->GetTextMetrics(&tm);
	int cxChar = tm.tmAveCharWidth;

	int x = 5;
	int y = 20;
	CString str = "From\tTo\tSubject\tDate";

	pDC->TabbedTextOut(x, y, str, str.GetLength(), 0, NULL, x);

	CRect rect;
	GetClientRect(&rect);
	pDC->DrawText("Blue Blazer Irregulars", -1, &rect, 
               DT_SINGLELINE | DT_CENTER | DT_VCENTER);
}

/////////////////////////////////////////////////////////////////////////////
// CTabsView printing

BOOL CTabsView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTabsView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTabsView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTabsView diagnostics

#ifdef _DEBUG
void CTabsView::AssertValid() const
{
	CView::AssertValid();
}

void CTabsView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTabsDoc* CTabsView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTabsDoc)));
	return (CTabsDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTabsView message handlers
