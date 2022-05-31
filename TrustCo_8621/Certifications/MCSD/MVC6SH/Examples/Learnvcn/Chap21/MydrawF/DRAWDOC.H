// DrawDoc.h : interface of the CMyDrawDoc class
//
/////////////////////////////////////////////////////////////////////////////
#include "shape.h"

#if !defined(AFX_DRAWDOC_H__FD12CB4A_5E8E_11D2_873C_E44B3671671E__INCLUDED_)
#define AFX_DRAWDOC_H__FD12CB4A_5E8E_11D2_873C_E44B3671671E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMyDrawDoc : public CDocument
{
protected: // create from serialization only
	CMyDrawDoc();
	DECLARE_DYNCREATE(CMyDrawDoc)

// Attributes
public:
	// Following five data members moved here from view to facilitate
	//  coordinating multiple views.
    ShpType m_typeNext;        // Type of CShape to draw next
	bool m_bTransparent;	   // True if Transparent command selected
    UINT m_nColorNext;         // Store ID for color to simplify updating menus.
	bool m_bSelectionMode;     // True if selection mode in effect
	ShpType m_typeFormer;      // Save current tool while selecting

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyDrawDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual void DeleteContents();
	//}}AFX_VIRTUAL

// Implementation
public:
	bool SelectionExists();
	POSITION GetSelectedShape();
	void DeleteSelectedShape(); // Ex 1, Ch 11 (modified for Ch 18)
	void GetDocSizes(int nMapMode, CSize& sizeTotal, CSize& sizePage, CSize& sizeLine);
	void DeleteAllShapes();
	void DeleteLatestShape();
	void SetToLatestShape() { m_pos = m_listShapes.GetHeadPosition(); };
	void SetToOldestShape() { m_pos = m_listShapes.GetTailPosition(); };
	CShape* GetPrevShape()
		{
			// Sets m_pos to NULL if no shapes or latest shape is last in list
			return (CShape*)m_listShapes.GetPrev(m_pos);
		};
	CShape* GetNextShape()
		{
			// Sets m_pos to NULL if no shapes or latest shape is last in list
			return (CShape*)m_listShapes.GetNext(m_pos);
		};
	POSITION GetPos() const
		{
			// m_pos tells you where you are in an iteration of the shapes
			// Use GetPos with either iteration direction to test for end
			return m_pos;   // Can be NULL
		};
	int GetCount() const
		{
			// Return the number of stored shapes
			return m_listShapes.GetCount();
		};

	CShape* CreateShape(ShpType st);
	virtual ~CMyDrawDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

// Attributes
private:
    CObList m_listShapes;  // Linked list of all shapes drawn so far
    POSITION m_pos;        // Latest position accessed

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyDrawDoc)
	afx_msg void OnToolBringFwd();
	afx_msg void OnUpdateToolBringFwd(CCmdUI* pCmdUI);
	afx_msg void OnToolBringFront();
	afx_msg void OnUpdateToolBringFront(CCmdUI* pCmdUI);
	afx_msg void OnToolSendBack();
	afx_msg void OnUpdateToolSendBack(CCmdUI* pCmdUI);
	afx_msg void OnToolSendBehind();
	afx_msg void OnUpdateToolSendBehind(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWDOC_H__FD12CB4A_5E8E_11D2_873C_E44B3671671E__INCLUDED_)
