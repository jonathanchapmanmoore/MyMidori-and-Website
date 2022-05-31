// bballVw.h : interface of the CBballView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BBALLVW_H__8D974B35_0E79_11D2_86D5_904A03C16C61__INCLUDED_)
#define AFX_BBALLVW_H__8D974B35_0E79_11D2_86D5_904A03C16C61__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

enum OperationType
{
	opShowTeams,
	opShowWinners,
	opShowNoWins
};

class CBballView : public CScrollView
{
protected: // create from serialization only
	CBballView();
	DECLARE_DYNCREATE(CBballView)

// Attributes
public:
	CBballDoc* GetDocument();

	OperationType m_opType;
	int m_nHeightLine;
	CString m_strTitle;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBballView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
public:
	void ListNeverWinners();
	void SetDocSize();
	void ShowNeverWon(CDC* pDC);
	void ShowSeriesWinners(CDC* pDC);
	void ShowTeams(CDC* pDC);
	virtual ~CBballView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBballView)
	afx_msg void OnViewModernteams();
	afx_msg void OnUpdateViewModernteams(CCmdUI* pCmdUI);
	afx_msg void OnViewNeverwon();
	afx_msg void OnUpdateViewNeverwon(CCmdUI* pCmdUI);
	afx_msg void OnViewWorldserieswinners();
	afx_msg void OnUpdateViewWorldserieswinners(CCmdUI* pCmdUI);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in bballVw.cpp
inline CBballDoc* CBballView::GetDocument()
   { return (CBballDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BBALLVW_H__8D974B35_0E79_11D2_86D5_904A03C16C61__INCLUDED_)
