// Shape.cpp: implementation of the CShape class and subclasses.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MyDraw.h"
#include "Shape.h"
#include "resource.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
// Class CShape
IMPLEMENT_SERIAL(CShape, CObject, 1)

CShape::CShape()
{
    m_boxShape.SetRect(0, 0, 0, 0);
    m_bTransparent = true;
    m_nColorShape = ID_COLOR_BLACK;
    m_bSelected = false;
}

CShape::~CShape()
{

}

void CShape::Serialize(CArchive& ar)
{
    BYTE byTransparent;

    CObject::Serialize(ar);

    if (ar.IsStoring())
    {
        // TODO: add storing code here
        byTransparent = (m_bTransparent ? 1 : 0);
        ar << m_boxShape << byTransparent << m_nColorShape;
    }
    else
    {
        // TODO: add loading code here
        ar >> m_boxShape >> byTransparent >> m_nColorShape;
        m_bTransparent = (byTransparent != 0);
	    m_bSelected = false; // We don't store selection state
    }
}

void CShape::DrawHandles(CDC *pDC)
{
    // Put selection handles on a selected shape

    // Set up brush for painting selection handles
    CBrush* pBrush = new CBrush(COLOR_HIGHLIGHT);
    CBrush* pBrushOld = (CBrush*)pDC->SelectObject(pBrush);
    // Calculate areas to paint for handles
    CreateHandleRects();
    // Draw the handle rects with black interior brush
    for(int i = 0; i < 8; i++)
    {
        pDC->Rectangle(arHandles[i]);
    }
    pDC->SelectObject(pBrushOld);
    // We created this brush, so we must dispose of it.
    // We only borrowed pBrushOld, so Windows disposes of it.
    delete pBrush;
}

void CShape::CreateHandleRects()
{
    // Calculate the rectangles for a set of selection handles
    // Store them in array of handle rects

    int nHandSize = GetSystemMetrics(SM_CXBORDER) * 7;

    // Create an inflated rect around the shape's bounding rect, m_boxShape
    CRect ri = m_boxShape;
    ri.InflateRect(nHandSize, -nHandSize);

    // Calculate rects for corner handles

    // Left top corner selection handle
    CRect rectLeftTop(ri.left, ri.top, 
                             m_boxShape.left, m_boxShape.top);
    rectLeftTop.OffsetRect(4, -4);
    arHandles[0] = rectLeftTop;

    // Right top corner selection handle
    CRect rectRightTop(m_boxShape.right, ri.top, 
                                    ri.right, m_boxShape.top);
    rectRightTop.OffsetRect(-4, -4);
    arHandles[1] = rectRightTop;

    // Right bottom corner selection handle
    CRect rectRightBottom(m_boxShape.right, m_boxShape.bottom, 
                                       ri.right, ri.bottom);
    rectRightBottom.OffsetRect(-4, 4);
    arHandles[2] = rectRightBottom;

    // Left bottom corner selection handle
    CRect rectLeftBottom(ri.left, m_boxShape.bottom, 
                                       m_boxShape.left, ri.bottom);
    rectLeftBottom.OffsetRect(4, 4);
    arHandles[3] = rectLeftBottom;

    // Calculate rects for handles in centers of sides

    // Calculate x values for top and bottom center selection handles
    int centerVert = ri.left + (ri.right - ri.left) / 2;
    int leftVert = centerVert - (nHandSize / 2);
    int rightVert = centerVert + (nHandSize / 2);

    // Bottom center selection handle
    CRect rectBottomCenter(leftVert, ri.top, rightVert, m_boxShape.top);
    rectBottomCenter.OffsetRect(0, -4);
    arHandles[4] = rectBottomCenter;

    // Top center selection handle
    CRect rectTopCenter(leftVert, m_boxShape.bottom, rightVert, ri.bottom);
    rectTopCenter.OffsetRect(0, 4);
    arHandles[6] = rectTopCenter;

    // Calculate y values for left and right center selection handles
    int centerHorz = ri.top + (ri.bottom - ri.top) / 2;
    int topHorz = centerHorz - (nHandSize / 2);
    int bottomHorz = centerHorz + (nHandSize / 2);

    // Right center selection handle
    CRect rectRightCenter(m_boxShape.right, topHorz, ri.right, bottomHorz);
    rectRightCenter.OffsetRect(-4, 0);
    arHandles[5] = rectRightCenter;

    // Left center selection handle
    CRect rectLeftCenter(ri.left, topHorz, m_boxShape.left, bottomHorz);
    rectLeftCenter.OffsetRect(4, 0);
    arHandles[7] = rectLeftCenter;
}

////////////////////////////////////////////
// CShape diagnostics

// ********** For details, see the document Diagnost.doc in
//            \learnvcn\Chap13 in the companion code.
#ifdef _DEBUG

// Utility function used in AssertValid for CShape and CMyDrawDoc
bool InRange(int nRangeStart, int nRangeEnd, int nTestItem)
{
	return (nTestItem >= nRangeStart && nTestItem <= nRangeEnd);
}

// Test the validity of a shape object.
//  MFC calls this function when we call ASSERT_VALID in
//  CMyDrawDoc::CreateShape.
void CShape::AssertValid() const
{
	CObject::AssertValid();

	ASSERT(InRange(int(ID_COLOR_BLACK), int(ID_COLOR_LTGRAY), m_nColorShape));
	// Uncomment the TRACE statement below to see how often this
	//  function is called. Enable tracing on the Tools menu.
	//TRACE("\nIn CShape::AssertValid\n");
}

// Obtain a diagnostic dump of a shape's contents.
//  The document calls this function when it dumps the shape list.
//  Output appears in the Debug pane of the Output window after the
//  application exits--when run in the debugger only.
void CShape::Dump(CDumpContext& dc) const
{
	CObject::Dump(dc);

	// Note that we print a nice, readable display here.
	dc << "*** Shape data:\n";
	dc << "\nm_boxShape = (" << m_boxShape.left << ", "
							 << m_boxShape.top  << ", "
							 << m_boxShape.right << ", "
							 << m_boxShape.bottom << ")";
	dc << "\nm_bTransparent = " << (m_bTransparent ? "true" : "false");
	dc << "\nm_nColorShape = " << m_nColorShape << " -- "
	   << arColorNames[m_nColorShape - ID_COLOR_BLACK];
	dc << "\nm_bSelected = " << (m_bSelected ? "true" : "false") << "\n\n";
}
#endif


// Class CShpRectangle
IMPLEMENT_SERIAL(CShpRectangle, CShape, 1)

// Virtual override
void CShpRectangle::Draw(CDC* pDC, bool bSelectionModeOn)
{
    pDC->Rectangle(m_boxShape);
    if(m_bSelected && bSelectionModeOn)
        DrawHandles(pDC);
}

// Class CShpEllipse
IMPLEMENT_SERIAL(CShpEllipse, CShape, 1)

// Virtual override
void CShpEllipse::Draw(CDC* pDC, bool bSelectionModeOn)
{
    pDC->Ellipse(m_boxShape);
    if(m_bSelected && bSelectionModeOn)
        DrawHandles(pDC);
}


