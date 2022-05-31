// StatDoc.h : interface of the CStatDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_STATDOC_H__905F84CB_612C_11D2_873C_B66B3F55AE21__INCLUDED_)
#define AFX_STATDOC_H__905F84CB_612C_11D2_873C_B66B3F55AE21__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CStatDoc : public CDocument
{
protected: // create from serialization only
	CStatDoc();
	DECLARE_DYNCREATE(CStatDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStatDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CStatDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CStatDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STATDOC_H__905F84CB_612C_11D2_873C_B66B3F55AE21__INCLUDED_)
