// STUploadView.h : interface of the CSTUploadView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_STUPLOADVIEW_H__8F89ECC1_D435_11D2_925F_0080C7FA0C3E__INCLUDED_)
#define AFX_STUPLOADVIEW_H__8F89ECC1_D435_11D2_925F_0080C7FA0C3E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSTUploadView : public CScrollView
{
protected: // create from serialization only
	CSTUploadView();
	DECLARE_DYNCREATE(CSTUploadView)

// Attributes
public:
	CSTUploadDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSTUploadView)
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
	virtual ~CSTUploadView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSTUploadView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	afx_msg void OnCancelEditSrvr();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in STUploadView.cpp
inline CSTUploadDoc* CSTUploadView::GetDocument()
   { return (CSTUploadDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STUPLOADVIEW_H__8F89ECC1_D435_11D2_925F_0080C7FA0C3E__INCLUDED_)
