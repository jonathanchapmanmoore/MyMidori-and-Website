// TextVw.h : interface of the CMyTextView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEXTVW_H__8DEF9A50_0858_11D2_873C_D28B633D8E0E__INCLUDED_)
#define AFX_TEXTVW_H__8DEF9A50_0858_11D2_873C_D28B633D8E0E__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CMyTextView : public CScrollView
{
protected: // create from serialization only
	CMyTextView();
	DECLARE_DYNCREATE(CMyTextView)

// Attributes
public:
	CMyTextDoc* GetDocument();

	int m_nHeightLine;
	CString m_strTextDraw;

	// For Try It Yourself exercise #2
	CFont* m_pFontNew;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyTextView)
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
	virtual ~CMyTextView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyTextView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TextVw.cpp
inline CMyTextDoc* CMyTextView::GetDocument()
   { return (CMyTextDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEXTVW_H__8DEF9A50_0858_11D2_873C_D28B633D8E0E__INCLUDED_)
