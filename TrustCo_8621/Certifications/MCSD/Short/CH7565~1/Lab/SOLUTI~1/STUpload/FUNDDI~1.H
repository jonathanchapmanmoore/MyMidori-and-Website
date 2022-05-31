#if !defined(AFX_FUNDDIALOG_H__33633444_049F_11D3_92A6_0080C7FA0C3E__INCLUDED_)
#define AFX_FUNDDIALOG_H__33633444_049F_11D3_92A6_0080C7FA0C3E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FundDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFundDialog dialog

class CFundDialog : public CDialog
{
// Construction
public:
	CFundDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFundDialog)
	enum { IDD = IDD_FUNDDIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFundDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFundDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FUNDDIALOG_H__33633444_049F_11D3_92A6_0080C7FA0C3E__INCLUDED_)
