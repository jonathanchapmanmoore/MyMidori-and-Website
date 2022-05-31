// MyMdiVw.h : interface of the CMyMdiView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYMDIVW_H__E71AF44B_6381_11D2_873C_444553540000__INCLUDED_)
#define AFX_MYMDIVW_H__E71AF44B_6381_11D2_873C_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMyMdiView : public CView
{
protected: // create from serialization only
	CMyMdiView();
	DECLARE_DYNCREATE(CMyMdiView)

// Attributes
public:
	CMyMdiDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyMdiView)
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
	virtual ~CMyMdiView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyMdiView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MyMdiVw.cpp
inline CMyMdiDoc* CMyMdiView::GetDocument()
   { return (CMyMdiDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYMDIVW_H__E71AF44B_6381_11D2_873C_444553540000__INCLUDED_)
