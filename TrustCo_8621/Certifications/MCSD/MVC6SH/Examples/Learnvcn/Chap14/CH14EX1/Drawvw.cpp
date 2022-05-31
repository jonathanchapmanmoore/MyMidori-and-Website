// DrawVw.cpp : implementation of the CMyDrawView class
//

#include "stdafx.h"
#include "MyDraw.h"

//#include "DrawDoc.h"	// Removed while adding CShape class, step 4
#include "DrawVw.h"
#include <stdlib.h>		// For rand and srand and abs
#include <time.h>		// For time function

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
	ON_COMMAND(ID_EDIT_ERASE, OnEditErase)
	ON_UPDATE_COMMAND_UI(ID_EDIT_ERASE, OnUpdateEditErase)
	ON_COMMAND(ID_EDIT_ERASE_ALL, OnEditEraseAll)
	ON_UPDATE_COMMAND_UI(ID_EDIT_ERASE_ALL, OnUpdateEditEraseAll)
	ON_WM_LBUTTONDBLCLK()
	//}}AFX_MSG_MAP
    ON_COMMAND_RANGE(ID_COLOR_BLACK, ID_COLOR_LTGRAY, OnToolColor)
	ON_UPDATE_COMMAND_UI_RANGE(ID_COLOR_BLACK, ID_COLOR_LTGRAY, OnUpdateToolColor)
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

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMyDrawView drawing

void CMyDrawView::OnDraw(CDC* pDC)
{
	CMyDrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
    // Iterate the shapes from oldest to newest
    // (Draw them in the same order as originally drawn)
    CShape* pShape;
	// The doc's GetCount calls the array's GetSize.
    for(int i = pDoc->GetCount();i >= 0; i--)
    {
        // Get the shape and use it to set the pen and brush
 		// The doc's GetAt calls the array's GetAt.
        pShape = (CShape*)pDoc->GetAt(i);
        SetPenBrush(pDC, pShape->m_bTransparent, pShape->m_nColorShape);
        // Ask the shape to draw itself
        pShape->Draw(pDC);
        // Clean up
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

void CMyDrawView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
    SetCapture();
    m_bCaptured = true;

    ASSERT(m_typeNext == shpRectangle || m_typeNext == shpEllipse);

	CMyDrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// Create shape and add it to our list; return a ptr to it
    m_pShpTemp = pDoc->CreateShape(m_typeNext);
    // Mark the document as changed
    pDoc->SetModifiedFlag();

    // Start setting properties of the new shape
	// Added next line for Ex 1, Chapter 11.
	m_pShpTemp->m_bTransparent = m_bTransparent;
    m_pShpTemp->m_nColorShape = m_nColorNext;
    
    // Store starting point - literally a point, initially 
    //   (topLeft == botRight)
    m_pShpTemp->m_boxShape.left = m_pShpTemp->m_boxShape.right = point.x;
    m_pShpTemp->m_boxShape.top = m_pShpTemp->m_boxShape.bottom = point.y;

	CView::OnLButtonDown(nFlags, point);
}

void CMyDrawView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
    if(m_bCaptured)
    {
        CClientDC dc(this);

        // Erase previous rectangle first
        InvertShape(&dc, *m_pShpTemp);

        // Store new temporary corner as bottom right
        m_pShpTemp->m_boxShape.bottom = point.y;
        m_pShpTemp->m_boxShape.right = point.x;

        // Draw new rectangle (latest rubberbanded rectangle)
        InvertShape(&dc, *m_pShpTemp);
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

        // Erase previous rubberband rectangle
        InvertShape(&dc, *m_pShpTemp);

        // Set the botRight corner's final values
        m_pShpTemp->m_boxShape.right = point.x;
        m_pShpTemp->m_boxShape.bottom = point.y;
        
        // Draw final rectangle
        InvertShape(&dc, *m_pShpTemp, false);  // Draw        
    }
	
	CView::OnLButtonUp(nFlags, point);
}

void CMyDrawView::SetPenBrush(CDC *pDC, bool bTransparent, UINT nColor)
{
    ASSERT(pDC != NULL);
    // Make shape's interior empty (transparent)
    if(m_bTransparent)
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
    // Construct pen object: on heap so we can clean it up after use.
    m_pPenNew = new CPen();
    // Create the GDI pen & select it into the device context.
    m_pPenNew->CreatePen(PS_INSIDEFRAME, 0, 
                           arColors[nColor - ID_COLOR_BLACK]);
    m_pPenOld = (CPen*)pDC->SelectObject(m_pPenNew);

    // Device context restored in companion function ResetPenBrush
}

void CMyDrawView::ResetPenBrush(CDC *pDC)
{
    ASSERT(pDC != NULL);
    // Restore previous pen and brush to the device context after use.
    pDC->SelectObject(m_pBrushOld);
    pDC->SelectObject(m_pPenOld);
    // Our responsibility to delete the heap object.
    delete m_pPenNew;
    m_pPenNew = NULL;
    m_pPenOld = NULL;
    m_pBrushOld = NULL;
}

void CMyDrawView::InvertShape(CDC *pDC, CShape &s, bool bInvert)
{
    ASSERT(pDC != NULL);
	// Set up pen and brush for drawing: Added for Ex 1, Chapter 11
    SetPenBrush(pDC, s.m_bTransparent, s.m_nColorShape);

    // Drawing mode is R2_NOT: black -> white, white -> black, 
    //   colors -> inverse color
    // If shape already drawn, this erases; else draws it
    int nModeOld;
    if(bInvert)
    {
        nModeOld = pDC->SetROP2(R2_NOT);
    }
    
    // Draw the shape (or erase it)
	s.Draw(pDC);

   // Restore old values in DC
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

// Added for Ex 1, Chapter 11
void CMyDrawView::OnEditErase() 
{
	// TODO: Add your command handler code here
	// Erase the most recently drawn figure
    CMyDrawDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    pDoc->DeleteLatestShape();
    Invalidate();
}

// Added for Ex 1, Chapter 11
void CMyDrawView::OnUpdateEditErase(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	// Enable Edit/Erase if shape list not empty.
    CMyDrawDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    pCmdUI->Enable(pDoc->GetCount() >= 0);
}

// Added for Ex 2, Chapter 11
void CMyDrawView::OnEditEraseAll() 
{
	// TODO: Add your command handler code here
    CMyDrawDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    pDoc->DeleteAllShapes();
    Invalidate();
}

// Added for Ex 2, Chapter 11
void CMyDrawView::OnUpdateEditEraseAll(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	// Enable Edit/Erase All if shape list not empty.
    CMyDrawDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    pCmdUI->Enable(pDoc->GetCount() >= 0);
}

// Added for Ex 2, Chapter 11
void CMyDrawView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	// Easiest way to erase with double-click: call erase all handler.
	OnEditEraseAll();
	
	CView::OnLButtonDblClk(nFlags, point);
}

void CMyDrawView::OnToolColor(UINT nID)
{
    // Set the color for future shape drawing
    m_nColorNext = nID;
}

void CMyDrawView::OnUpdateToolColor(CCmdUI* pCmdUI)
{
    // Check or uncheck all color menu items
    // Check item if it's the currently selected color
    // Uncheck all other colors
    pCmdUI->SetCheck(pCmdUI->m_nID == m_nColorNext);
}
