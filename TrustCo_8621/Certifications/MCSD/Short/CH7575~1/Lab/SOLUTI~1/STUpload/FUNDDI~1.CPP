// FundDialog.cpp : implementation file
//

#include "stdafx.h"
#include "STUpload.h"
#include "FundDialog.h"
#include "MainFrm.h"
#include "STUploadDoc.h"

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
	DDX_Control(pDX, IDC_LIST1, m_listBox);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFundDialog, CDialog)
	//{{AFX_MSG_MAP(CFundDialog)
	ON_LBN_SELCHANGE(IDC_FUNDLIST, OnSelchangeFundlist)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFundDialog message handlers

void CFundDialog::OnOK() 
{	
}

void CFundDialog::OnCancel() 
{
}

void CFundDialog::OnSelchangeFundlist() 
{
	CMainFrame * pWnd = 
		dynamic_cast< CMainFrame * > (AfxGetMainWnd());
	ASSERT_VALID( pWnd );
	
	CSTUploadDoc * pDoc = 
		dynamic_cast< CSTUploadDoc * >( pWnd->GetActiveDocument());
	ASSERT_VALID( pDoc );
	
	CString strCurFund;
	
	int sel = m_listBox.GetCurSel();
	
	if( sel == LB_ERR ) sel = 0;
	
	m_listBox.GetText( sel, strCurFund );
	
	pDoc->SetCurrentFund( strCurFund );
	
	pDoc->UpdateAllViews( NULL );
	
	
}
