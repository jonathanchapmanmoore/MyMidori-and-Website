// DrawVw.cpp : implementation of the CMyDrawView class
//

#include "stdafx.h"
#include "MyDraw.h"

#include "DrawDoc.h"
#include "DrawVw.h"

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
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_UPDATE_COMMAND_UI(ID_TOOL_RECTANGLE, OnUpdateToolRectangle)
	ON_UPDATE_COMMAND_UI(ID_TOOL_ELLIPSE, OnUpdateToolEllipse)
	ON_COMMAND(ID_TOOL_TRANSPARENT, OnToolTransparent)
	ON_UPDATE_COMMAND_UI(ID_TOOL_TRANSPARENT, OnUpdateToolTransparent)
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
    m_typeNext = shpRectangle;
    m_bCaptured = false;
    m_pBrushOld = NULL;
    m_countShapes = 0;
    m_bTransparent = true;

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
    for(int nShp = 0; nShp < m_countShapes; nShp++)
    {
        // Draw
        ASSERT(m_arShps[nShp].m_typeShape == shpRectangle ||
               m_arShps[nShp].m_typeShape == shpEllipse);
		SetPenBrush(pDC, m_arShps[nShp].m_bTransparent);

		switch(m_arShps[nShp].m_typeShape)
        {
        case shpRectangle: 
            pDC->Rectangle(m_arShps[nShp].m_boxShape);
            break;
        case shpEllipse: 
            pDC->Ellipse(m_arShps[nShp].m_boxShape);
            break;
            // Add other shape tools here.
        default: ;
        }
	// Restore DC's old attributes.
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
    m_shpTemp.m_typeShape = m_typeNext;
	m_shpTemp.m_bTransparent = m_bTransparent;
    
    // Store starting point - literally a point, initially 
    //   (topLeft == botRight).
    m_shpTemp.m_boxShape.left = 
		m_shpTemp.m_boxShape.right = point.x;
    m_shpTemp.m_boxShape.top = 
		m_shpTemp.m_boxShape.bottom = point.y;


	CView::OnLButtonDown(nFlags, point);
}

void CMyDrawView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_bCaptured)
    {
        CClientDC dc(this);

        // Erase previous rectangle first.
        InvertShape(&dc, m_shpTemp);

        // Store new temporary corner as bottom right.
        m_shpTemp.m_boxShape.bottom = point.y;
        m_shpTemp.m_boxShape.right = point.x;

        // Draw new rectangle (latest rubberbanded rectangle).
        InvertShape(&dc, m_shpTemp);
    }

	CView::OnMouseMove(nFlags, point);
}

void CMyDrawView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
if(m_bCaptured)
    {
        ::ReleaseCapture();
        m_bCaptured = false;

        CClientDC dc(this);

        // Erase previous rubberband rectangle.
        InvertShape(&dc, m_shpTemp);

        // Set the botRight corner's final values.
        m_shpTemp.m_boxShape.right = point.x;
        m_shpTemp.m_boxShape.bottom = point.y;
        
        // Draw final rectangle.
        InvertShape(&dc, m_shpTemp, false);  // Draw
        
        // Put current Shape in array.
        m_arShps[m_countShapes] = m_shpTemp;
        m_countShapes++;
    }

	CView::OnLButtonUp(nFlags, point);
}

void CMyDrawView::SetPenBrush(CDC *pDC, bool bTransparent)
{
    ASSERT(pDC != NULL);
    // Make shape's interior empty (transparent).
    if(bTransparent)
    {
        m_pBrushOld = (CBrush*)pDC->SelectStockObject(NULL_BRUSH);
    }
    else
    {
        m_pBrushOld = (CBrush*)pDC->SelectStockObject(WHITE_BRUSH);
    }
    ASSERT(m_pBrushOld != NULL);

    // Device context restored in companion function 
	//  ResetPenBrush

}

void CMyDrawView::ResetPenBrush(CDC *pDC)
{
    ASSERT(pDC != NULL);
    // Restore previous pen and brush to device context after use.
    ASSERT(m_pBrushOld != NULL);
    pDC->SelectObject(m_pBrushOld);
    m_pBrushOld = NULL;

}

void CMyDrawView::InvertShape(CDC *pDC, Shape &s, bool bInvert)
{
    ASSERT(pDC != NULL);
    // Drawing mode is R2_NOT: black -> white, white -> black,
    //  colors -> inverse color.
    // If shape already drawn, this erases; else draws it.
    int nModeOld;
    if(bInvert)
    {
        nModeOld = pDC->SetROP2(R2_NOT);
    }

    // Draw the shape (or erase it).
    SetPenBrush(pDC, s.m_bTransparent);
    switch(s.m_typeShape)
    {
    case shpRectangle: pDC->Rectangle(s.m_boxShape);
        break;
    case shpEllipse: pDC->Ellipse(s.m_boxShape);
        break;
    }
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
