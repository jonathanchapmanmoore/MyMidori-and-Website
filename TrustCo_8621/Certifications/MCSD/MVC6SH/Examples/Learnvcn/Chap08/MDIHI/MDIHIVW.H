// MdiHiVw.h : interface of the CMdiHiView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MDIHIVW_H__B9B29D0F_6508_11D2_873C_E7CEFA286A32__INCLUDED_)
#define AFX_MDIHIVW_H__B9B29D0F_6508_11D2_873C_E7CEFA286A32__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMdiHiView : public CView
{
protected: // create from serialization only
	CMdiHiView();
	DECLARE_DYNCREATE(CMdiHiView)

// Attributes
public:
	CMdiHiDoc* GetDocument();
	CString m_strHi;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMdiHiView)
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
	virtual ~CMdiHiView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMdiHiView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MdiHiVw.cpp
inline CMdiHiDoc* CMdiHiView::GetDocument()
   { return (CMdiHiDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MDIHIVW_H__B9B29D0F_6508_11D2_873C_E7CEFA286A32__INCLUDED_)
