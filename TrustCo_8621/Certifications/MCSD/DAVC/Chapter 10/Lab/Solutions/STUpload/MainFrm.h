// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__8F89ECBD_D435_11D2_925F_0080C7FA0C3E__INCLUDED_)
#define AFX_MAINFRM_H__8F89ECBD_D435_11D2_925F_0080C7FA0C3E__INCLUDED_

#include "FundDialog.h"	// Added by ClassView
#include "StockDataList.h"	
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMainFrame : public CFrameWnd
{
	
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Attributes
public:
	BOOL AreFundsVisible() { return m_bFundsVisible; }

	void SetFundsVisible( BOOL bSet ) 
	{ 
		m_bFundsVisible = bSet; 
		if( bSet ) m_wndFundDialog.ShowWindow( SW_SHOW );
		else m_wndFundDialog.ShowWindow( SW_HIDE );
	} 

// Operations
public:
	const CFundDialog * GetFundDialog() 
	{ return &m_wndFundDialog; }

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	void UpdateFundList( const CStockDataList & pList,  CString strCurrentFund = "");
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;

// Generated message map functions
protected:
	BOOL m_bFundsVisible;
	CFundDialog m_wndFundDialog;
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnViewFundselection();
	afx_msg void OnUpdateViewFundselection(CCmdUI* pCmdUI);
	afx_msg void OnActivateApp(BOOL bActive, HTASK hTask);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__8F89ECBD_D435_11D2_925F_0080C7FA0C3E__INCLUDED_)
