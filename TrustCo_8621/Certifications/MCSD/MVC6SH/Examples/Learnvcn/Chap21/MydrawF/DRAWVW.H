// DrawVw.h : interface of the CMyDrawView class
//
/////////////////////////////////////////////////////////////////////////////
#include "DrawDoc.h"
#include "Dialogs.h"
#include "Resource.h"

#if !defined(AFX_DRAWVW_H__FD12CB4C_5E8E_11D2_873C_E44B3671671E__INCLUDED_)
#define AFX_DRAWVW_H__FD12CB4C_5E8E_11D2_873C_E44B3671671E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


// Array of actual colors, indexed
//   by CMyDrawView::m_nColorNext
static COLORREF arColors[11] =  
{
    RGB(0,0,0),         // Black
    RGB(0,0,255),       // Blue
    RGB(0,255,0),       // Green
    RGB(0,255,255),     // Cyan
    RGB(255,0,0),       // Red
    RGB(255,0,255),     // Magenta
    RGB(255,255,0),     // Yellow
    RGB(255,255,255),   // White
    RGB(128,128,128),   // Dark gray
    RGB(192,192,192),   // Light gray
    RGB(0,0,0)          // Custom color
};

const UINT CUSTOM_COLOR_INDEX = 10;
const UINT CUSTOM_COLOR = ID_COLOR_BLACK + CUSTOM_COLOR_INDEX;

class CMyDrawView : public CScrollView
{
protected: // create from serialization only
	CMyDrawView();
	DECLARE_DYNCREATE(CMyDrawView)

// Attributes
public:
	CMyDrawDoc* GetDocument();
    CShape* m_pShpTemp;        // The current CShape being drawn
    bool m_bCaptured;          // True if mouse has been captured
    CBrush* m_pBrushOld;       // Store brush for interior of shapes
    CPen* m_pPenOld;           // Store pen for drawing CShape outlines.
    CPen* m_pPenNew;           // Store pens we create.
    int m_nMapMode;            // The current mapping mode in use.
    int m_nPageWidth;          // The width of a printed page.
    int m_nPageHeight;         // The height of a printed page.
    CString m_strDrawing;      // User's title for the drawing

	// For MyDrawF, the following data members were moved to the
	//  document to facilitate coordinating multiple views:
	//  m_bSelectionMode, m_typeNext, m_bTransparent, m_nColorNext,
	//  and m_typeFormer

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyDrawView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	void DoHitTesting(CPoint point);
	void CancelSelection();
	void PrintFooter(CDC *pDC, CPrintInfo *pInfo);
	void PrintHeader(CDC* pDC, CPrintInfo* pInfo);
	void InvertShape(CDC* pDC, CShape& s, bool bInvert = true);
	void ResetPenBrush(CDC* pDC);
	void SetPenBrush(CDC* pDC, bool bTransparent, UINT nColor);
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
	afx_msg void OnToolSelection();
	afx_msg void OnUpdateToolSelection(CCmdUI* pCmdUI);
	afx_msg void OnEditDrawingTitle();
	afx_msg void OnToolCustomColor();
	afx_msg void OnUpdateToolCustomColor(CCmdUI* pCmdUI);
	afx_msg void OnToolSettings();
	afx_msg void OnEditErase();
	afx_msg void OnUpdateEditErase(CCmdUI* pCmdUI);
	afx_msg void OnEditEraseAll();
	afx_msg void OnUpdateEditEraseAll(CCmdUI* pCmdUI);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	//}}AFX_MSG
	afx_msg void OnToolColor(UINT nID);  // ON_COMMAND_RANGE handler
	afx_msg void OnUpdateToolColor(CCmdUI* pCmdUI);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DrawVw.cpp
inline CMyDrawDoc* CMyDrawView::GetDocument()
   { return (CMyDrawDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWVW_H__FD12CB4C_5E8E_11D2_873C_E44B3671671E__INCLUDED_)
