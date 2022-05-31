////////////////////////////////
//
// MyHiView.h
//
////////////////////////////////

#if !defined(AFX_MYHIVIEW_H__D2FA402F_B990_11D1_873C_CC328AE73F3B__INCLUDED_)
#define AFX_MYHIVIEW_H__D2FA402F_B990_11D1_873C_CC328AE73F3B__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CMyHiView : public CView
{
protected: // create from serialization only
	CMyHiView();
	DECLARE_DYNCREATE(CMyHiView)

// Attributes
public:
	CMyHiDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyHiView)
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
	virtual ~CMyHiView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyHiView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MyHiView.cpp
inline CMyHiDoc* CMyHiView::GetDocument()
   { return (CMyHiDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYHIVIEW_H__D2FA402F_B990_11D1_873C_CC328AE73F3B__INCLUDED_)
