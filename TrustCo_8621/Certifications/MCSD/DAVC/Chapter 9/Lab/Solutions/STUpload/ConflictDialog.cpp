// ConflictDialog.cpp : implementation file
//

#include "stdafx.h"
#include "STUpload.h"
#include "ConflictDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CConflictDialog dialog


CConflictDialog::CConflictDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CConflictDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CConflictDialog)
	m_REditText = _T("");
	//}}AFX_DATA_INIT
}


void CConflictDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CConflictDialog)
	DDX_Text(pDX, IDC_DUPL_RICHEDIT, m_REditText);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CConflictDialog, CDialog)
	//{{AFX_MSG_MAP(CConflictDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CConflictDialog message handlers
