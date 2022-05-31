// TextVw.cpp : implementation of the CMyTextView class
//

#include "stdafx.h"
#include "MyText.h"

#include "TextDoc.h"
#include "TextVw.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyTextView

IMPLEMENT_DYNCREATE(CMyTextView, CScrollView)

BEGIN_MESSAGE_MAP(CMyTextView, CScrollView)
	//{{AFX_MSG_MAP(CMyTextView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyTextView construction/destruction

CMyTextView::CMyTextView()
{
	// TODO: add construction code here
	// For Try It Yourself exercise #2, Chapter 15
	m_pFontNew = NULL;
}

CMyTextView::~CMyTextView()
{
	// For Try It Yourself exercise #2, Chapter 15
	delete m_pFontNew;
}

BOOL CMyTextView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMyTextView drawing

const int MARGIN_LEFT = 5;
const int LINES = 30;

void CMyTextView::OnDraw(CDC* pDC)
{
	CMyTextDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
	// For Try It Yourself exercise #1, Chapter 15
	COLORREF colorOld;
	colorOld = pDC->SetTextColor(RGB(0,0,255));	// Blue

	// For Try It Yourself exercise #2, Chapter 15
	CFont* pFontOld = pDC->SelectObject(m_pFontNew);

	// Main text-drawing code
	ASSERT(m_nHeightLine > 0);
	CString strLines;

	for(int nLines = 0; nLines < LINES; nLines++)		
	{
		strLines.Format("%d: ", nLines);		
		if(nLines < 10)
			strLines += "  ";
		pDC->TextOut(MARGIN_LEFT, nLines * m_nHeightLine, strLines + m_strTextDraw);
	}

	// For Try It Yourself exercises, Chapter 15
	pDC->SetTextColor(colorOld);
	pDC->SelectObject(pFontOld);
}

/////////////////////////////////////////////////////////////////////////////
// CMyTextView printing

BOOL CMyTextView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMyTextView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMyTextView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMyTextView diagnostics

#ifdef _DEBUG
void CMyTextView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CMyTextView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CMyTextDoc* CMyTextView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyTextDoc)));
	return (CMyTextDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyTextView message handlers

void CMyTextView::OnInitialUpdate() 
{
    CScrollView::OnInitialUpdate();
    
    // TODO: Add your specialized code here and/or call the base class
	CClientDC dc(this);

	// For Try It Yourself exercise #2, Chapter 15
	int nPointSize = 18;
	int nHeightFont = -((dc.GetDeviceCaps(LOGPIXELSY) * nPointSize) / 72);
	m_pFontNew = new CFont();
	m_pFontNew->CreateFont(nHeightFont, 0, 0, 0, FW_NORMAL, FALSE, FALSE, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial");
	// Select the font long enough to obtain text metrics
	CFont* pFontOld = (CFont*)dc.SelectObject(m_pFontNew);

	// For text-drawing code
    TEXTMETRIC tm;
    dc.GetTextMetrics(&tm);
	
	// For Try It Yourself exercise #2, Chapter 15

    //int cxChar = tm.tmAveCharWidth;
    //int cyChar = tm.tmHeight;
    m_nHeightLine = tm.tmHeight + tm.tmExternalLeading; 

    m_strTextDraw = "No matter where you go, there you are.";
    m_strTextDraw += "   -- Buckaroo Banzai, ";
    m_strTextDraw += "The Adventures of Buckaroo Banzai Across ";
    m_strTextDraw += "the Eighth Dimension";
	CString str = "999: " + m_strTextDraw;  // Allow for line numbering
    CSize size = dc.GetTextExtent(str);

	const int FUDGE_H = 0;//60;
	const int FUDGE_V = 0;//30;

    int nWidth = size.cx + FUDGE_H;
    int nHeight = m_nHeightLine * 30 + FUDGE_V;

    CSize sizeTotal = CSize(nWidth, nHeight);
    CSize sizePage = CSize(nWidth / 3, nHeight / 3);
    CSize sizeLine = CSize(nWidth / 10, m_nHeightLine);

    SetScrollSizes(MM_TEXT, sizeTotal, sizePage, sizeLine);

	// Reselect the default font
	dc.SelectObject(pFontOld);		

}

// For Try It Yourself exercise #3, Chapter 15
void CMyTextView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default

	switch(nChar)
    {
    case VK_UP: 
        OnVScroll(SB_LINEUP, 0, NULL);
        break;
    case VK_DOWN: 
        OnVScroll(SB_LINEDOWN, 0, NULL);
        break;
    case VK_PRIOR:
        OnVScroll(SB_PAGEUP, 0, NULL);
        break;
    case VK_NEXT:
        OnVScroll(SB_PAGEDOWN, 0, NULL);
        break;
    }
	
	CScrollView::OnKeyDown(nChar, nRepCnt, nFlags);
}
