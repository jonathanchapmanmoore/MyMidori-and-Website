// DrawVw.h : interface of the CMyDrawView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DRAWVW_H__24958326_5D0A_11D2_991B_00C04FC29F5C__INCLUDED_)
#define AFX_DRAWVW_H__24958326_5D0A_11D2_991B_00C04FC29F5C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

enum ShpType
{
    shpRectangle,
    shpEllipse
};


class CMyDrawView : public CView
{
protected: // create from serialization only
	CMyDrawView();
	DECLARE_DYNCREATE(CMyDrawView)

// Attributes
public:
	CMyDrawDoc* GetDocument();
	CRect m_boxShape;         // Bounding box for drawing current
                              //  shape
	ShpType m_typeShape;      // Currently: rectangle or ellipse

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyDrawView)
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
	void RandomRect(CRect* pRect);
	int RandomCoord();
	virtual ~CMyDrawView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyDrawView)
	afx_msg void OnToolRectangle();
	afx_msg void OnToolEllipse();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DrawVw.cpp
inline CMyDrawDoc* CMyDrawView::GetDocument()
   { return (CMyDrawDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWVW_H__24958326_5D0A_11D2_991B_00C04FC29F5C__INCLUDED_)
