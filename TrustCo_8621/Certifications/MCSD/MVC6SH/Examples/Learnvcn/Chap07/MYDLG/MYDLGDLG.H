// MyDlgDlg.h : header file
//

#if !defined(AFX_MYDLGDLG_H__5E426C86_63A9_11D2_873C_D5E416AAF519__INCLUDED_)
#define AFX_MYDLGDLG_H__5E426C86_63A9_11D2_873C_D5E416AAF519__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMyDlgDlg dialog

class CMyDlgDlg : public CDialog
{
// Construction
public:
	CMyDlgDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMyDlgDlg)
	enum { IDD = IDD_MYDLG_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyDlgDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMyDlgDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYDLGDLG_H__5E426C86_63A9_11D2_873C_D5E416AAF519__INCLUDED_)
