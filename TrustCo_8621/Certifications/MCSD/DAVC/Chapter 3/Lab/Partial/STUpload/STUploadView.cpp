// STUploadView.cpp : implementation of the CSTUploadView class
//

#include "stdafx.h"
#include "STUpload.h"

#include "STUploadDoc.h"
#include "STUploadView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSTUploadView

IMPLEMENT_DYNCREATE(CSTUploadView, CScrollView)

BEGIN_MESSAGE_MAP(CSTUploadView, CScrollView)
	//{{AFX_MSG_MAP(CSTUploadView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSTUploadView construction/destruction

CSTUploadView::CSTUploadView()
{
	// TODO: add construction code here

}

CSTUploadView::~CSTUploadView()
{
}

BOOL CSTUploadView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSTUploadView drawing

void CSTUploadView::OnDraw(CDC* pDC)
{
	CSTUploadDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

void CSTUploadView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

/////////////////////////////////////////////////////////////////////////////
// CSTUploadView printing

BOOL CSTUploadView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSTUploadView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSTUploadView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSTUploadView diagnostics

#ifdef _DEBUG
void CSTUploadView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CSTUploadView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CSTUploadDoc* CSTUploadView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSTUploadDoc)));
	return (CSTUploadDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSTUploadView message handlers
