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
	ON_COMMAND(ID_TOOL_SELECTION, OnToolSelection)
	ON_UPDATE_COMMAND_UI(ID_TOOL_SELECTION, OnUpdateToolSelection)
	ON_COMMAND(ID_EDIT_DRAWING_TITLE, OnEditDrawingTitle)
	ON_COMMAND(ID_TOOL_CUSTOM_COLOR, OnToolCustomColor)
	ON_UPDATE_COMMAND_UI(ID_TOOL_CUSTOM_COLOR, OnUpdateToolCustomColor)
	ON_COMMAND(ID_TOOL_SETTINGS, OnToolSettings)
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
	m_strDrawing = "Untitled drawing";
	m_bSelectionMode = false;   // Added for selection
	m_typeFormer = m_typeNext;  // Added for selection
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
		pShape->Draw(pDC, m_bSelectionMode);
		// Clean up.
		ResetPenBrush(pDC);
	}

}


/////////////////////////////////////////////////////////////////////////////
// CMyDrawView printing

BOOL CMyDrawView::OnPreparePrinting(CPrintInfo* pInfo)
{
	pInfo->SetMaxPage(2);
	// default preparation
	int nResult = DoPreparePrinting(pInfo);
    pInfo->m_nNumPreviewPages = 2;
    return nResult;

}

void CMyDrawView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// TODO: add extra initialization before printing
	// Get the printer's resolution in millimeters
    int nHorzSize = pDC->GetDeviceCaps(HORZSIZE);  // Millimeters
    int nVertSize = pDC->GetDeviceCaps(VERTSIZE);

    // Compute page width and height in logical units (0.01 in).
    // Accept double to int truncation (cuts off fractional units).
    // TRACE statements let us see values for planning purposes.
    m_nPageWidth = (double)nHorzSize / 25.4 * 100.0;
    TRACE("m_nPageWidth = %d\n", m_nPageWidth);

    m_nPageHeight = (double)nVertSize / 25.4 * 100.0;
    TRACE("m_nPageHeight = %d\n", m_nPageHeight);

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
	CancelSelection();
}

void CMyDrawView::OnToolEllipse() 
{
	// TODO: Add your command handler code here
	m_typeNext = shpEllipse;
    CancelSelection();
}

// Generate a random positive coordinate within a COORD_MAX- 
//  by COORD_MAX-unit drawing area.

void CMyDrawView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

    CMyDrawDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    if(m_bSelectionMode)    // Selecting
    {
        // Find which shape was clicked, if any.
        // Sets the selected shape, if there is one.
        DoHitTesting(point);
    }
    else                    // Drawing
    {

	SetCapture();
    m_bCaptured = true;

    ASSERT(m_typeNext == shpRectangle || m_typeNext == 
		shpEllipse);

    // Create CShape and add it to our list; return a ptr to it.
    m_pShpTemp = pDoc->CreateShape(m_typeNext);
    // Mark the document as changed.
    pDoc->SetModifiedFlag();

    // Start setting properties of the new shape.
	m_pShpTemp->m_bTransparent = m_bTransparent;
    m_pShpTemp->m_nColorShape = m_nColorNext;
	m_pShpTemp->m_bSelected = false;

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
	} // Add this brace
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

		// Update extra views with the new shape.
		CMyDrawDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		pDoc->UpdateAllViews(NULL);
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
	s.Draw(pDC, m_bSelectionMode);

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

    m_nMapMode = MM_LOENGLISH;
    CSize sizeTotal, sizePage, sizeLine;
    sizeTotal = sizePage = sizeLine = CSize(0,0);

    CMyDrawDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    pDoc->GetDocSizes(m_nMapMode, sizeTotal, sizePage, sizeLine);
    SetScrollSizes(m_nMapMode, sizeTotal, sizePage, sizeLine);
}

void CMyDrawView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	CScrollView::OnPrepareDC(pDC, pInfo);
	if(pDC->IsPrinting())
    {
        int nPages = pInfo->m_nCurPage - 1;
        int x = (nPages & 1) * m_nPageWidth;
        int y = (nPages / 2) * -m_nPageHeight;
        
        pDC->SetWindowOrg(x, y);
    }
}

void CMyDrawView::OnPrint(CDC* pDC, CPrintInfo* pInfo) 
{
	// TODO: Addyour specialized code here and/or call the base class
	ASSERT_VALID(pDC);
	PrintHeader(pDC, pInfo);
    pDC->SetWindowOrg(pInfo->m_rectDraw.left, 
		              -pInfo->m_rectDraw.top);

	CScrollView::OnPrint(pDC, pInfo);
	PrintFooter(pDC, pInfo);
}

void CMyDrawView::PrintHeader(CDC *pDC, CPrintInfo *pInfo)
{
	// Start header at left margin.
    pDC->SetTextAlign(TA_LEFT);

    // Print the header string.
    pDC->TextOut(pInfo->m_rectDraw.left, -25, m_strDrawing);

    // Draw a line under the header and across the page.
    TEXTMETRIC tm;
    pDC->GetTextMetrics(&tm);
    int y = -35 - tm.tmHeight;

    pDC->MoveTo(0, y);
    pDC->LineTo(pInfo->m_rectDraw.right, y);

    // Compensate for the header with the rest of the drawing.
    // Subtract space used by header from drawing rectangle.
    y -= 25;
    pInfo->m_rectDraw.top += y; 

}

void CMyDrawView::PrintFooter(CDC *pDC, CPrintInfo *pInfo)
{
	CMyDrawDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    // Construct a footer string with document's pathname or title
    //  and current page number.
    // If document's pathname is too long or doc hasn't been saved,
    //  use its title in footer instead of pathname.
    const int LINE_WIDTH = 75;
    CString strFooter = pDoc->GetPathName();
    CString strTitle = pDoc->GetTitle();
    int nLength = strFooter.GetLength();
    if(nLength > LINE_WIDTH || strTitle == "Untitled")
        strFooter = strTitle; 
    
    // Add the page number to the footer.
    CString strPage;
    strPage.Format("%d", pInfo->m_nCurPage);
    strFooter = strFooter + "    " + strPage;

    pDC->SetTextAlign(TA_LEFT);
    pDC->TextOut(pInfo->m_rectDraw.left, 
                 pInfo->m_rectDraw.bottom + 100, strFooter);

    // Draw a line over the footer and across the page.
    TEXTMETRIC tm;
    pDC->GetTextMetrics(&tm);
    int y = pInfo->m_rectDraw.bottom + 90 + tm.tmHeight;

    pDC->MoveTo(0, y);
    pDC->LineTo(pInfo->m_rectDraw.right, y);

}

void CMyDrawView::OnToolSelection() 
{
	// TODO: Add your command handler code here
	m_typeFormer = m_typeNext;  // Save old tool for restoration
    m_typeNext = shpSelecting;  // For toolbar management
    m_bSelectionMode = true;

}

void CMyDrawView::OnUpdateToolSelection(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_typeNext == shpSelecting);
	
}

void CMyDrawView::CancelSelection()
{
	// End selection mode because another tool was chosen
    // Other tool sets m_typeNext to other than shpSelecting
    CMyDrawDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);
    m_bSelectionMode = false;
    pDoc->UpdateAllViews(NULL);
}

void CMyDrawView::DoHitTesting(CPoint point)
{
	CMyDrawDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    // Convert point to logical coordinates.
    // Corrects y coordinate for mapping mode
    CClientDC dc(this);
    OnPrepareDC(&dc);
    dc.DPtoLP(&point);

    // Walk the shape list from newest to oldest.
    bool bSelectionMade = false;
    CRect rect;
    CShape* pShape;
    pDoc->SetToLatestShape();
    while(pDoc->GetPos() != NULL /*&& !bSelectionMade */)
    {
        // Start with last shape in list.
        pShape = pDoc->GetNextShape();  // Last shape sets to NULL
        // Normalize the shape's bounding rectangle
        //  to correct for mapping mode.
        rect = pShape->m_boxShape;
        rect.NormalizeRect();
        // See if shape has been hit.
        // But ignore a hit if there has already been one in a
        //  higher layer (higher shape overlaps current shape).
        if(!bSelectionMade && rect.PtInRect(point))
        {
            //m_pSelectedShape = pShape;
            // Tell shape it has been selected.
            pShape->m_bSelected = true;
            // Once a selection has been made, no other is possible
            //  (but we still need to turn off selection in rest of
			//  shapes).
            bSelectionMade = true;
        }
        else
        {
            // Only one selected shape at a time,
            //  so turn off selection in any other shapes.
            pShape->m_bSelected = false;
        }
    }
    // Click was outside any shape: cancel selection.
    if(!bSelectionMade)
    {
        m_typeNext = m_typeFormer;   // Restore previous tool
        CancelSelection();
    }
    else    // Update any other views to show new selection.
    {
        pDoc->UpdateAllViews(NULL);  // Moved out of while for 
		                             //  selection
    }
}

void CMyDrawView::OnEditDrawingTitle() 
{
	// TODO: Add your command handler code here
	CTitleDialog dlg;
    // Put current drawing title in dialog.
    dlg.m_strDrawing = m_strDrawing; 
    if(dlg.DoModal() == IDOK)
    {
        // Retrieve value entered by user. 
        m_strDrawing = dlg.m_strDrawing;
    }

}

void CMyDrawView::OnToolCustomColor() 
{
	// TODO: Add your command handler code here
	CColorDialog dlg;
    // Put current color in dialog.
    COLORREF color = arColors[m_nColorNext - ID_COLOR_BLACK];
    dlg.m_cc.rgbResult = color;
    if(dlg.DoModal() == IDOK)
    {
        m_nColorNext = CUSTOM_COLOR;
        arColors[CUSTOM_COLOR - ID_COLOR_BLACK] =
			dlg.GetColor();
    }
}

void CMyDrawView::OnUpdateToolCustomColor(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nColorNext == CUSTOM_COLOR);
	
}

void CMyDrawView::OnToolSettings() 
{
	// TODO: Add your command handler code here
	// Create property sheet and the 3 contained pages.
    CPropertySheet settings("MyDraw Settings");
    CLinePage dlgLine;
    CShapePage dlgShape;

    // Add the pages to the sheet, in desired order.
    settings.AddPage(&dlgLine);
    settings.AddPage(&dlgShape);

    // Initialize members associated with controls.
    dlgLine.m_nThickness = 1;
    dlgLine.m_nColorIndex = m_nColorNext - ID_COLOR_BLACK;
    dlgLine.m_colorRGB = arColors[m_nColorNext -
		ID_COLOR_BLACK];
    // Radio buttons: 0 = Rectangle, 1 = Ellipse
    dlgShape.m_nShpRectangle = 
                     (m_typeNext == shpRectangle ? 0 : 1);
    // Check box
    dlgShape.m_bTransparent = m_bTransparent;   

    if(settings.DoModal() == IDOK)
    {
        // Retrieve values set by user: radio buttons.
        m_typeNext = (dlgShape.m_nShpRectangle ? 
                          shpEllipse : shpRectangle);
        // Check box
		m_bTransparent = (dlgShape.m_bTransparent == 1 ? 
			              true : false);
        // Get selected color.
        m_nColorNext = dlgLine.m_nColorIndex + ID_COLOR_BLACK;
        // Store selected color in color array.
        if(m_nColorNext == CUSTOM_COLOR)
        {
            arColors[CUSTOM_COLOR_INDEX] = dlgLine.m_colorRGB;
        }
        // Other values in view updated 
		//  during dialog operation
    }
}
