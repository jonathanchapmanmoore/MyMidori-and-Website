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
	void DeleteAllShapes();
	void DeleteLatestShape();
	int GetCount() const
		{
			// Return the number of stored shapes
			return m_listShapes.GetUpperBound();
		};
	CShape* GetAt(UINT nIndex)
		{
			return (CShape*)m_listShapes.GetAt(nIndex);
		};

	CShape* CreateShape(ShpType st);

	virtual ~CMyDrawDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

// Attributes
private:
    CObArray m_listShapes;  // Linked list of all shapes drawn so far
    POSITION m_pos;         // Latest position accessed

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyDrawDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWDOC_H__FD12CB4A_5E8E_11D2_873C_E44B3671671E__INCLUDED_)
