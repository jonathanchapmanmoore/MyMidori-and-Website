// DrawDoc.h : interface of the CMyDrawDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DRAWDOC_H__24958324_5D0A_11D2_991B_00C04FC29F5C__INCLUDED_)
#define AFX_DRAWDOC_H__24958324_5D0A_11D2_991B_00C04FC29F5C__INCLUDED_

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
	//}}AFX_VIRTUAL

// Implementation
public:
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
