// tabsDoc.h : interface of the CTabsDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TABSDOC_H__C193E54D_D6A8_11D1_873C_A89A32B32032__INCLUDED_)
#define AFX_TABSDOC_H__C193E54D_D6A8_11D1_873C_A89A32B32032__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CTabsDoc : public CDocument
{
protected: // create from serialization only
	CTabsDoc();
	DECLARE_DYNCREATE(CTabsDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTabsDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTabsDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTabsDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TABSDOC_H__C193E54D_D6A8_11D1_873C_A89A32B32032__INCLUDED_)
