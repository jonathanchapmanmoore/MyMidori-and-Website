#if !defined(AFX_QUERYDIALOG_H__C151A526_43CA_11D3_92FD_0080C7FA0C3E__INCLUDED_)
#define AFX_QUERYDIALOG_H__C151A526_43CA_11D3_92FD_0080C7FA0C3E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// QueryDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CQueryDialog dialog

class CQueryDialog : public CDialog
{
// Construction
public:
	CQueryDialog(CWnd* pParent = NULL);   // standard constructor

	CString m_strFund;

// Dialog Data
	//{{AFX_DATA(CQueryDialog)
	enum { IDD = IDD_QUERYDIALOG };
	CComboBox	m_cbFund;
	CDateTimeCtrl	m_dtTo;
	CDateTimeCtrl	m_dtFrom;
	int		m_nFund;
	COleDateTime	m_fromdate;
	COleDateTime	m_todate;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQueryDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CQueryDialog)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QUERYDIALOG_H__C151A526_43CA_11D3_92FD_0080C7FA0C3E__INCLUDED_)
