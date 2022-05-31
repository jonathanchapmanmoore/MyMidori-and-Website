// Ch16x2Vw.h : interface of the CCh16Ex2View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CH16X2VW_H__88D9EBC1_7D7E_11D2_873C_D2D0E0D78E1E__INCLUDED_)
#define AFX_CH16X2VW_H__88D9EBC1_7D7E_11D2_873C_D2D0E0D78E1E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCh16Ex2View : public CView
{
protected: // create from serialization only
	CCh16Ex2View();
	DECLARE_DYNCREATE(CCh16Ex2View)

// Attributes
public:
	CCh16Ex2Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCh16Ex2View)
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
	virtual ~CCh16Ex2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCh16Ex2View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Ch16x2Vw.cpp
inline CCh16Ex2Doc* CCh16Ex2View::GetDocument()
   { return (CCh16Ex2Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CH16X2VW_H__88D9EBC1_7D7E_11D2_873C_D2D0E0D78E1E__INCLUDED_)
