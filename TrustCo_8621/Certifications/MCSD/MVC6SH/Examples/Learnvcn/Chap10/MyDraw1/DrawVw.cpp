// DrawVw.cpp : implementation of the CMyDrawView class
//

#include "stdafx.h"
#include "MyDraw.h"

#include "DrawDoc.h"
#include "DrawVw.h"

#include <stdlib.h>    // For rand and srand and abs
#include <time.h>      // For time function

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyDrawView

IMPLEMENT_DYNCREATE(CMyDrawView, CView)

BEGIN_MESSAGE_MAP(CMyDrawView, CView)
	//{{AFX_MSG_MAP(CMyDrawView)
	ON_COMMAND(ID_TOOL_RECTANGLE, OnToolRectangle)
	ON_COMMAND(ID_TOOL_ELLIPSE, OnToolEllipse)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDrawView construction/destruction

CMyDrawView::CMyDrawView()
{
	// TODO: add construction code here
	// Initialize random number generator for random bounding rects.
    srand((unsigned)time(NULL));

}

CMyDrawView::~CMyDrawView()
{
}

BOOL CMyDrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMyDrawView drawing

void CMyDrawView::OnDraw(CDC* pDC)
{
	CMyDrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	switch(m_typeShape)
    {
    case shpRectangle: pDC->Rectangle(m_boxShape);
        break;
    case shpEllipse: pDC->Ellipse(m_boxShape);
        break;
    }

}

/////////////////////////////////////////////////////////////////////////////
// CMyDrawView printing

BOOL CMyDrawView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMyDrawView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMyDrawView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMyDrawView diagnostics

#ifdef _DEBUG
void CMyDrawView::AssertValid() const
{
	CView::AssertValid();
}

void CMyDrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyDrawDoc* CMyDrawView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyDrawDoc)));
	return (CMyDrawDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyDrawView message handlers

void CMyDrawView::OnToolRectangle() 
{
	// TODO: Add your command handler code here
	CClientDC dc(this);
    RandomRect(&m_boxShape);
    dc.Rectangle(m_boxShape);
	m_typeShape = shpRectangle;
	
}

void CMyDrawView::OnToolEllipse() 
{
	// TODO: Add your command handler code here
	CClientDC dc(this);
    RandomRect(&m_boxShape);
    dc.Ellipse(m_boxShape);
    m_typeShape = shpEllipse;

}

const int COORD_MAX = 1000;

// Generate a random positive coordinate within a COORD_MAX- 
//  by COORD_MAX-unit drawing area.

int CMyDrawView::RandomCoord()
{
	static int nLastCoord;

    int nNextCoord = rand();
    int nFudge = rand() % 100;
    nLastCoord = (nNextCoord > nLastCoord ? nNextCoord : nLastCoord);
    nLastCoord = (nLastCoord + nFudge) % COORD_MAX;

    return nLastCoord;

}

// Generate a random CRect.
void CMyDrawView::RandomRect(CRect *pRect)
{
	ASSERT(pRect != NULL);  // Error if user passes a bad rect
    pRect->top = RandomCoord();
    pRect->left = RandomCoord();
    pRect->bottom = RandomCoord();
    pRect->right = RandomCoord();

}
