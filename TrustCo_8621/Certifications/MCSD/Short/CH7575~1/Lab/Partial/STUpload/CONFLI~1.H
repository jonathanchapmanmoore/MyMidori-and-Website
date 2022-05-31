#if !defined(AFX_CONFLICTDIALOG_H__33633443_049F_11D3_92A6_0080C7FA0C3E__INCLUDED_)
#define AFX_CONFLICTDIALOG_H__33633443_049F_11D3_92A6_0080C7FA0C3E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ConflictDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CConflictDialog dialog

class CConflictDialog : public CDialog
{
// Construction
public:
	CConflictDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CConflictDialog)
	enum { IDD = IDD_CONFLICT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CConflictDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CConflictDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONFLICTDIALOG_H__33633443_049F_11D3_92A6_0080C7FA0C3E__INCLUDED_)
