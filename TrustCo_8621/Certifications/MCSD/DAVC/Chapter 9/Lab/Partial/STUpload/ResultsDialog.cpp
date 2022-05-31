// ResultsDialog.cpp : implementation file
//

#include "stdafx.h"
#include "STUpload.h"
#include "ResultsDialog.h"
#include "_recordset.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CResultsDialog dialog


CResultsDialog::CResultsDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CResultsDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CResultsDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CResultsDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CResultsDialog)
	DDX_Control(pDX, IDC_ADODC1, m_adodc);
	DDX_Control(pDX, IDC_DATAGRID1, m_datagrid);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CResultsDialog, CDialog)
	//{{AFX_MSG_MAP(CResultsDialog)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CResultsDialog message handlers

BOOL CResultsDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_adodc.SetRecordSource( m_strQuery );
	m_adodc.Refresh();

	C_Recordset cRS = m_adodc.GetRecordset();

	long lRecs = cRS.GetRecordCount();

	if( lRecs < 1 )
	{
		AfxMessageBox( "No records match this query" );
		EndDialog( IDCANCEL );
	}

	m_datagrid.SetCaption( m_strCaption );
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
