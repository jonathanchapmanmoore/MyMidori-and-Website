// tabsView.h : interface of the CTabsView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TABSVIEW_H__C193E54F_D6A8_11D1_873C_A89A32B32032__INCLUDED_)
#define AFX_TABSVIEW_H__C193E54F_D6A8_11D1_873C_A89A32B32032__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CTabsView : public CView
{
protected: // create from serialization only
	CTabsView();
	DECLARE_DYNCREATE(CTabsView)

// Attributes
public:
	CTabsDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTabsView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTabsView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTabsView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in tabsView.cpp
inline CTabsDoc* CTabsView::GetDocument()
   { return (CTabsDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TABSVIEW_H__C193E54F_D6A8_11D1_873C_A89A32B32032__INCLUDED_)
