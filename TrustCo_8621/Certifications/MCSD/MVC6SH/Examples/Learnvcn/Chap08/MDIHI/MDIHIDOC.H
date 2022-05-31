// MdiHiDoc.h : interface of the CMdiHiDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MDIHIDOC_H__B9B29D0D_6508_11D2_873C_E7CEFA286A32__INCLUDED_)
#define AFX_MDIHIDOC_H__B9B29D0D_6508_11D2_873C_E7CEFA286A32__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMdiHiDoc : public CDocument
{
protected: // create from serialization only
	CMdiHiDoc();
	DECLARE_DYNCREATE(CMdiHiDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMdiHiDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMdiHiDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMdiHiDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MDIHIDOC_H__B9B29D0D_6508_11D2_873C_E7CEFA286A32__INCLUDED_)
