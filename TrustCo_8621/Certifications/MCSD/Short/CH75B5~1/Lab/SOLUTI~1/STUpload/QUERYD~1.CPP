// QueryDialog.cpp : implementation file
//

#include "stdafx.h"
#include "STUpload.h"
#include "QueryDialog.h"

#include "Mainfrm.h"
#include "STUploadDoc.h"
#include "FundDialog.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CQueryDialog dialog


CQueryDialog::CQueryDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CQueryDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CQueryDialog)
	m_nFund = -1;
	m_fromdate = COleDateTime::GetCurrentTime();
	m_todate = COleDateTime::GetCurrentTime();
	//}}AFX_DATA_INIT
}


void CQueryDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CQueryDialog)
	DDX_Control(pDX, IDC_FUND, m_cbFund);
	DDX_Control(pDX, IDC_TODATE, m_dtTo);
	DDX_Control(pDX, IDC_FROMDATE, m_dtFrom);
	DDX_CBIndex(pDX, IDC_FUND, m_nFund);
	DDX_DateTimeCtrl(pDX, IDC_FROMDATE, m_fromdate);
	DDX_DateTimeCtrl(pDX, IDC_TODATE, m_todate);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CQueryDialog, CDialog)
	//{{AFX_MSG_MAP(CQueryDialog)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CQueryDialog message handlers

BOOL CQueryDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	CMainFrame * pWnd = 
		dynamic_cast< CMainFrame * > (AfxGetApp()->m_pMainWnd);

	ASSERT_VALID( pWnd );

	CSTUploadDoc * pDoc = 
		dynamic_cast< CSTUploadDoc * >( pWnd->GetActiveDocument() );

	ASSERT_VALID( pDoc );

	const CFundDialog * pFD = pWnd->GetFundDialog();

	ASSERT_VALID( pFD );

	// Fill combo box with current fund names
	for( int n = 0; n < pFD->m_listBox.GetCount(); n++ )
	{
		CString strBuf;
		pFD->m_listBox.GetText( n, strBuf );
		m_cbFund.AddString( strBuf );
	}

	// Set listbox selection to strCurrentFund parameter
	int iPos = 
		m_cbFund.FindStringExact( -1, pDoc->GetCurrentFund() );
	
	m_cbFund.SetCurSel( iPos );

	// Setup Date Time Pickers
	m_dtFrom.SetFormat( "d MMM yyy" );
	m_dtTo.SetFormat( "d MMM yyy" );
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CQueryDialog::OnOK() 
{
	int nChoice = m_cbFund.GetCurSel();

	if( nChoice >= 0 )
		m_cbFund.GetLBText( nChoice, m_strFund );
	
	CDialog::OnOK();
}

