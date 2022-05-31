// Ch16x2Vw.cpp : implementation of the CCh16Ex2View class
//

#include "stdafx.h"
#include "Ch16Ex2.h"

#include "C16x2Doc.h"
#include "Ch16x2Vw.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCh16Ex2View

IMPLEMENT_DYNCREATE(CCh16Ex2View, CView)

BEGIN_MESSAGE_MAP(CCh16Ex2View, CView)
	//{{AFX_MSG_MAP(CCh16Ex2View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCh16Ex2View construction/destruction

CCh16Ex2View::CCh16Ex2View()
{
	// TODO: add construction code here

}

CCh16Ex2View::~CCh16Ex2View()
{
}

BOOL CCh16Ex2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCh16Ex2View drawing

void CCh16Ex2View::OnDraw(CDC* pDC)
{
	// Draw some sample data so user can see changes as files are
	//  opened.

	CCh16Ex2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	// Create string versions of the document's numeric data.
	CString strInt;
	strInt.Format("%d", pDoc->m_int);
	CString strDouble;
	strDouble.Format("%f", pDoc->m_double);
	CString strByte;
	strByte.Format("%c", pDoc->m_byte);
	CString strObjectEmb;
	strObjectEmb.Format("%d", pDoc->m_myObj.m_intObj);
	CString strObjectPtr;
	strObjectPtr.Format("%d", pDoc->m_myObj.m_intObj);
	CString strObject2Emb;
	strObject2Emb.Format("%d", pDoc->m_myObj2.m_intObj2);
	CString strObject2Ptr;
	strObject2Ptr.Format("%d", pDoc->m_myObj2.m_intObj2);

	// Obtain text metrics for spacing lines in the display.
	TEXTMETRIC tm;
	pDC->GetTextMetrics(&tm);
	int nHeightLine = tm.tmHeight + tm.tmExternalLeading;

	// Display the sample data.
	int x = 5;
	int y = 0;
	pDC->TextOut(x, y, "A sampling of the values stored in the document:");
	y = y + nHeightLine;
	pDC->TextOut(x + 10, y, "Integer data member m_int: " + strInt);
	y = y + nHeightLine;
	pDC->TextOut(x + 10, y, "Double data member m_double: " + strDouble);
	y = y + nHeightLine;
	pDC->TextOut(x + 10, y, "Byte data member m_byte: " + strByte);
	y = y + nHeightLine;
	pDC->TextOut(x + 10, y, "String data member m_str: " + pDoc->m_str);
	y = y + nHeightLine;
	pDC->TextOut(x + 10, y, "An embedded object derived from CObject:");
	y = y + nHeightLine;
	pDC->TextOut(x + 20, y, "CMyObject.m_intObj: " + strObjectEmb);
	y = y + nHeightLine;
	pDC->TextOut(x + 20, y, "CMyObject.m_strObj: " + pDoc->m_myObj.m_strObj);
	y = y + nHeightLine;
	pDC->TextOut(x + 10, y, "A pointer to an object derived from CObject: ");
	y = y + nHeightLine;
	pDC->TextOut(x + 20, y, "CMyObject->m_intObj: " + strObjectPtr);
    y = y + nHeightLine / 2;

	// Print instructions in a box.
	int yBoxTop = y + nHeightLine + 8;
	CString strLineLong = "1. Select Assign Non-Zero Values on the Change menu (note non-zero values).";
	CRect rectBox;
	rectBox.left = x - 3;
	rectBox.top = yBoxTop;
	CSize size = pDC->GetTextExtent(strLineLong);
	rectBox.right = size.cx + 8;
	rectBox.bottom = y + 10 * nHeightLine + 3;
	pDC->Rectangle(rectBox);
	y = y + nHeightLine;
	pDC->TextOut(x, y, "Instructions:");
	y = y + nHeightLine;
	pDC->TextOut(x, y, strLineLong);
	y = y + nHeightLine;
    pDC->TextOut(x, y, "2. Save the file (.ser extension).");
	y = y + nHeightLine;
	pDC->TextOut(x, y, "3. Then select Save As on the File menu and save with a different name.");
	y = y + nHeightLine;
	pDC->TextOut(x, y, "4. Select Zero Out Values on the Change menu (note zeroed values).");
	y = y + nHeightLine;
	pDC->TextOut(x, y, "5. Reopen the first file you saved (Cancel the Save message).");
	y = y + nHeightLine;
	pDC->TextOut(x, y, "6. Note the non-zero values.");
	y = y + 2 * nHeightLine;
	pDC->TextOut(x, y, "Result: Non-zero values stored in file replace zero values in display.");
}

/////////////////////////////////////////////////////////////////////////////
// CCh16Ex2View printing

BOOL CCh16Ex2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCh16Ex2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCh16Ex2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CCh16Ex2View diagnostics

#ifdef _DEBUG
void CCh16Ex2View::AssertValid() const
{
	CView::AssertValid();
}

void CCh16Ex2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCh16Ex2Doc* CCh16Ex2View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCh16Ex2Doc)));
	return (CCh16Ex2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCh16Ex2View message handlers
