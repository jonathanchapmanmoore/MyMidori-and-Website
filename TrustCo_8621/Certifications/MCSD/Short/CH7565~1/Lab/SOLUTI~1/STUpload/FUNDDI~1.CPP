// FundDialog.cpp : implementation file
//

#include "stdafx.h"
#include "STUpload.h"
#include "FundDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFundDialog dialog


CFundDialog::CFundDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CFundDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFundDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CFundDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFundDialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFundDialog, CDialog)
	//{{AFX_MSG_MAP(CFundDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFundDialog message handlers
