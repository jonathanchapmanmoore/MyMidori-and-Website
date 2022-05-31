// StatForm.cpp : implementation file
//

#include "stdafx.h"
#include "Stat.h"
#include "StatForm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStatForm

IMPLEMENT_DYNCREATE(CStatForm, CFormView)

CStatForm::CStatForm()
	: CFormView(CStatForm::IDD)
{
	//{{AFX_DATA_INIT(CStatForm)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CStatForm::~CStatForm()
{
}

void CStatForm::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStatForm)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStatForm, CFormView)
	//{{AFX_MSG_MAP(CStatForm)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStatForm diagnostics

#ifdef _DEBUG
void CStatForm::AssertValid() const
{
	CFormView::AssertValid();
}

void CStatForm::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CStatForm message handlers
