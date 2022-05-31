// nwndView.h : interface of the CNwndView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_NWNDVIEW_H__2FA6F063_5467_11D2_873C_444553540000__INCLUDED_)
#define AFX_NWNDVIEW_H__2FA6F063_5467_11D2_873C_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CNwndView : public CScrollView
{
protected: // create from serialization only
	CNwndView();
	DECLARE_DYNCREATE(CNwndView)

// Attributes
public:
	CNwndDoc* GetDocument();
	int m_nHeightLine;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNwndView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CNwndView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CNwndView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in nwndView.cpp
inline CNwndDoc* CNwndView::GetDocument()
   { return (CNwndDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NWNDVIEW_H__2FA6F063_5467_11D2_873C_444553540000__INCLUDED_)
