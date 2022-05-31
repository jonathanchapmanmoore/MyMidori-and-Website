// TextDoc.h : interface of the CMyTextDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEXTDOC_H__8DEF9A4E_0858_11D2_873C_D28B633D8E0E__INCLUDED_)
#define AFX_TEXTDOC_H__8DEF9A4E_0858_11D2_873C_D28B633D8E0E__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CMyTextDoc : public CDocument
{
protected: // create from serialization only
	CMyTextDoc();
	DECLARE_DYNCREATE(CMyTextDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyTextDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyTextDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyTextDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEXTDOC_H__8DEF9A4E_0858_11D2_873C_D28B633D8E0E__INCLUDED_)
