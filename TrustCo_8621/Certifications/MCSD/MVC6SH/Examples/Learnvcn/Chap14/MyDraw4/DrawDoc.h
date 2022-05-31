// DrawDoc.h : interface of the CMyDrawDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DRAWDOC_H__24958324_5D0A_11D2_991B_00C04FC29F5C__INCLUDED_)
#define AFX_DRAWDOC_H__24958324_5D0A_11D2_991B_00C04FC29F5C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Shape.h"


class CMyDrawDoc : public CDocument
{
protected: // create from serialization only
	CMyDrawDoc();
	DECLARE_DYNCREATE(CMyDrawDoc)

// Attributes
public:
	void SetToOldestShape() { m_pos = m_listShapes.GetTailPosition(); };
	void SetToLatestShape() { m_pos = m_listShapes.GetHeadPosition(); };

	CShape* GetPrevShape()
    {
        // Sets m_pos to NULL if no shapes or if
        //  latest shape is last in list.
        return (CShape*)m_listShapes.GetPrev(m_pos);
    };

	CShape* GetNextShape()
    {
        // Sets m_pos to NULL if no shapes or if
        //  latest shape is last in list
        return (CShape*)m_listShapes.GetNext(m_pos);
    };

	POSITION GetPos() const
    {
        // m_pos tells you where you are in a list of the shapes.
        // Use GetPos with either iteration direction to test for end.
        return m_pos;   // Can be NULL
    };
	
	int GetCount() const
    {
        // Return the number of stored shapes.
        return m_listShapes.GetCount();
    };

private:
    CObList m_listShapes;  // Linked list of all shapes drawn so far
    POSITION m_pos;        // Latest position accessed

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
	CShape* CreateShape(ShpType st);
	void DeleteAllShapes();
	void DeleteLatestShape();
	virtual ~CMyDrawDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

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

#endif // !defined(AFX_DRAWDOC_H__24958324_5D0A_11D2_991B_00C04FC29F5C__INCLUDED_)
