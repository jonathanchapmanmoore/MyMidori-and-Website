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

// A simple shape class
struct Shape
{
    CRect m_boxShape;        // Bounding rectangle
    ShpType m_typeShape;     // Rectangle, ellipse, etc.
	bool m_bTransparent;
};

// Number of shapes to store at a time
const int SHPS_MAX = 1000;

class CMyDrawView : public CView
{
protected: // create from serialization only
	CMyDrawView();
	DECLARE_DYNCREATE(CMyDrawView)

// Attributes
public:
	CMyDrawDoc* GetDocument();
	ShpType m_typeNext;       // Type of shape to draw next
    Shape m_shpTemp;          // The current shape being drawn
    Shape m_arShps[SHPS_MAX]; // Array of drawn shapes
    int m_countShapes;        // Number of shapes drawn so far
    bool m_bCaptured;         // True if mouse has been captured
    CBrush* m_pBrushOld;      // Store brush for interior of shapes
    bool m_bTransparent;      // True if Transparent selected
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
	void InvertShape(CDC *pDC, Shape &s, bool bInvert = true);
	void ResetPenBrush(CDC * pDC);
	void SetPenBrush(CDC * pDC, bool bTransparent);
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
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnUpdateToolRectangle(CCmdUI* pCmdUI);
	afx_msg void OnUpdateToolEllipse(CCmdUI* pCmdUI);
	afx_msg void OnToolTransparent();
	afx_msg void OnUpdateToolTransparent(CCmdUI* pCmdUI);
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
