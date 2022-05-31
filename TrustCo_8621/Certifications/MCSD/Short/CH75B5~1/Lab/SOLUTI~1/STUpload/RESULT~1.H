//{{AFX_INCLUDES()
#include "adodc.h"
#include "datagrid.h"
//}}AFX_INCLUDES
#if !defined(AFX_RESULTSDIALOG_H__816388E3_4442_11D3_92FE_0080C7FA0C3E__INCLUDED_)
#define AFX_RESULTSDIALOG_H__816388E3_4442_11D3_92FE_0080C7FA0C3E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ResultsDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CResultsDialog dialog

class CResultsDialog : public CDialog
{
// Construction
public:
	CResultsDialog(CWnd* pParent = NULL);   // standard constructor

	CString m_strQuery;
	CString m_strCaption;

// Dialog Data
	//{{AFX_DATA(CResultsDialog)
	enum { IDD = IDD_RESULTSDIALOG };
	CAdodc	m_adodc;
	CDataGrid	m_datagrid;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CResultsDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CResultsDialog)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RESULTSDIALOG_H__816388E3_4442_11D3_92FE_0080C7FA0C3E__INCLUDED_)
