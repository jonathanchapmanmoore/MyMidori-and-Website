// YCoordView.h : interface of the CYCoordView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_YCOORDVIEW_H__0D7C3812_77BB_11D2_991B_00C04FC29F5C__INCLUDED_)
#define AFX_YCOORDVIEW_H__0D7C3812_77BB_11D2_991B_00C04FC29F5C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CYCoordView : public CScrollView
{
protected: // create from serialization only
	CYCoordView();
	DECLARE_DYNCREATE(CYCoordView)

// Attributes
public:
	CYCoordDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CYCoordView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CYCoordView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CYCoordView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in YCoordView.cpp
inline CYCoordDoc* CYCoordView::GetDocument()
   { return (CYCoordDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_YCOORDVIEW_H__0D7C3812_77BB_11D2_991B_00C04FC29F5C__INCLUDED_)
