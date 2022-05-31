// DrawVw.cpp : implementation of the CMyDrawView class
//

#include "stdafx.h"

#include "MyDraw.h"
#include "DrawVw.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyDrawView

IMPLEMENT_DYNCREATE(CMyDrawView, CScrollView)

BEGIN_MESSAGE_MAP(CMyDrawView, CScrollView)
	//{{AFX_MSG_MAP(CMyDrawView)
	ON_COMMAND(ID_TOOL_RECTANGLE, OnToolRectangle)
	ON_COMMAND(ID_TOOL_ELLIPSE, OnToolEllipse)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_UPDATE_COMMAND_UI(ID_TOOL_RECTANGLE, OnUpdateToolRectangle)
	ON_UPDATE_COMMAND_UI(ID_TOOL_ELLIPSE, OnUpdateToolEllipse)
	ON_COMMAND(ID_TOOL_TRANSPARENT, OnToolTransparent)
	ON_UPDATE_COMMAND_UI(ID_TOOL_TRANSPARENT, OnUpdateToolTransparent)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
	ON_COMMAND_RANGE(ID_COLOR_BLACK, ID_COLOR_LTGRAY, OnToolColor)
	ON_UPDATE_COMMAND_UI_RANGE(ID_COLOR_BLACK, ID_COLOR_LTGRAY, 
                                      OnUpdateToolColor)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDrawView construction/destruction

CMyDrawView::CMyDrawView()
{
	// TODO: add construction code here
	// Initialize random number generator for random bounding rects.
    m_typeNext = shpRectangle;
    m_bCaptured = false;
    m_pBrushOld = NULL;
    m_bTransparent = true;
	m_nColorNext = ID_COLOR_BLACK;
	m_pPenOld = NULL;
	m_pPenNew = NULL;

}

CMyDrawView::~CMyDrawView()
{
}

BOOL CMyDrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMyDrawView drawing

void CMyDrawView::OnDraw(CDC* pDC)
{
    CMyDrawDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
    
	// Iterate the shapes from oldest to newest.
	// (Draw them in the same order as originally drawn).
	CShape* pShape;
	pDoc->SetToOldestShape();
	while(pDoc->GetPos() != NULL)
	{
		// Get the shape and use it to set the pen and brush.
		// Last shape sets position to NULL.
		pShape = pDoc->GetPrevShape();
		SetPenBrush(pDC, pShape->m_bTransparent, 
			pShape->m_nColorShape);
		// Ask the shape to draw itself.
		pShape->Draw(pDC);
		// Clean up.
		ResetPenBrush(pDC);
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
	CScrollView::AssertValid();
}

void CMyDrawView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
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
	m_typeNext = shpRectangle;
}

void CMyDrawView::OnToolEllipse() 
{
	// TODO: Add your command handler code here
	m_typeNext = shpEllipse;    
}

// Generate a random positive coordinate within a COORD_MAX- 
//  by COORD_MAX-unit drawing area.

void CMyDrawView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	SetCapture();
    m_bCaptured = true;

    ASSERT(m_typeNext == shpRectangle || m_typeNext == 
		shpEllipse);

    CMyDrawDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);
    // Create CShape and add it to our list; return a ptr to it.
    m_pShpTemp = pDoc->CreateShape(m_typeNext);
    // Mark the document as changed.
    pDoc->SetModifiedFlag();

    // Start setting properties of the new shape.
	m_pShpTemp->m_bTransparent = m_bTransparent;
    m_pShpTemp->m_nColorShape = m_nColorNext;

	// Convert point to logical coordinates.
	CClientDC dc(this);
	OnPrepareDC(&dc);
	dc.DPtoLP(&point);
    
    // Store starting point - literally a point, initially 
    //  (topLeft == botRight).
    m_pShpTemp->m_boxShape.left = 
		m_pShpTemp->m_boxShape.right = point.x;
    m_pShpTemp->m_boxShape.top = 
		m_pShpTemp->m_boxShape.bottom = point.y;

    CScrollView::OnLButtonDown(nFlags, point);  

}

void CMyDrawView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_bCaptured)
    {
        CClientDC dc(this);

		OnPrepareDC(&dc);
		dc.DPtoLP(&point);

        // Erase previous rectangle first.
        InvertShape(&dc, *m_pShpTemp);

        // Store new temporary corner as bottom right.
        m_pShpTemp->m_boxShape.bottom = point.y;
        m_pShpTemp->m_boxShape.right = point.x;

        // Draw new rectangle (latest rubberbanded rectangle).
        InvertShape(&dc, *m_pShpTemp);
    }

	CScrollView::OnMouseMove(nFlags, point);
}

void CMyDrawView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
if(m_bCaptured)
    {
        ::ReleaseCapture();
        m_bCaptured = false;

        CClientDC dc(this);

		OnPrepareDC(&dc);
		dc.DPtoLP(&point);

        // Erase previous rubberband rectangle.
        InvertShape(&dc, *m_pShpTemp);

        // Set the botRight corner's final values.
        m_pShpTemp->m_boxShape.right = point.x;
        m_pShpTemp->m_boxShape.bottom = point.y;
        
        // Draw final rectangle.
        InvertShape(&dc, *m_pShpTemp, false);  // Draw
           
    }

	CScrollView::OnLButtonUp(nFlags, point);
}

void CMyDrawView::SetPenBrush(CDC *pDC, bool bTransparent, 
							  UINT nColor)
{
    ASSERT(pDC != NULL);
    // Make CShape's interior empty (transparent).
    if(bTransparent)
    {
        m_pBrushOld = (CBrush*)pDC->SelectStockObject(NULL_BRUSH);
    }
    else
    {
        m_pBrushOld = (CBrush*)pDC->SelectStockObject(WHITE_BRUSH);
    }
    ASSERT(m_pBrushOld != NULL);

	// Set up the pen
    ASSERT(nColor - ID_COLOR_BLACK >= 0 &&
           nColor - ID_COLOR_BLACK <= 
           (sizeof(arColors) / sizeof(arColors[0])));
    // Construct pen object on heap so we can clean it up after use
    m_pPenNew = new CPen();
    // Create the GDI pen & select it into the device context.
    m_pPenNew->CreatePen(PS_INSIDEFRAME, 0, 
                           arColors[nColor - ID_COLOR_BLACK]);
    m_pPenOld = (CPen*)pDC->SelectObject(m_pPenNew);

    // Device context restored in companion function 
	//  ResetPenBrush

}

void CMyDrawView::ResetPenBrush(CDC *pDC)
{
    ASSERT(pDC != NULL);
    // Restore previous pen and brush to device context after use.
    ASSERT(m_pBrushOld != NULL);
    pDC->SelectObject(m_pBrushOld);
	pDC->SelectObject(m_pPenOld);
    // Our responsibility to delete the heap object
    delete m_pPenNew;
    m_pPenNew = NULL;
    m_pPenOld = NULL;
    m_pBrushOld = NULL;
}

void CMyDrawView::InvertShape(CDC *pDC, CShape &s, bool bInvert)
{
    ASSERT(pDC != NULL);
    // Drawing mode is R2_NOT: black -> white, white -> black,
    //  colors -> inverse color.
    // If CShape already drawn, this erases; else draws it.
    int nModeOld;
    if(bInvert)
    {
        nModeOld = pDC->SetROP2(R2_NOT);
    }

    // Draw the CShape (or erase it).
    SetPenBrush(pDC, s.m_bTransparent, s.m_nColorShape);
    s.Draw(pDC);

    // Restore old values in DC.
    if(bInvert)
    {
        pDC->SetROP2(nModeOld);
    }
    ResetPenBrush(pDC);

}

void CMyDrawView::OnUpdateToolRectangle(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_typeNext == shpRectangle);   
}

void CMyDrawView::OnUpdateToolEllipse(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_typeNext == shpEllipse); 
}

void CMyDrawView::OnToolTransparent() 
{
	// TODO: Add your command handler code here
	m_bTransparent = !m_bTransparent;
}

void CMyDrawView::OnUpdateToolTransparent(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_bTransparent);
}

void CMyDrawView::OnToolColor(UINT nID)
{
    // Set the color for future CShape drawing
    m_nColorNext = nID;
}

void CMyDrawView::OnUpdateToolColor(CCmdUI* pCmdUI)
{
    // Check or uncheck all color menu items
    // Check item if it's the currently selected color
    // Uncheck all other colors
    pCmdUI->SetCheck(pCmdUI->m_nID == m_nColorNext);
}

void CMyDrawView::OnInitialUpdate() 
{
	CScrollView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
    CClientDC dc(this); 

    m_nMapMode = MM_TEXT;
    CSize sizeTotal, sizePage, sizeLine;
    sizeTotal = sizePage = sizeLine = CSize(0,0);

    CMyDrawDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    pDoc->GetDocSizes(m_nMapMode, sizeTotal, sizePage, sizeLine);
    SetScrollSizes(m_nMapMode, sizeTotal, sizePage, sizeLine);
}
