// YCoordDoc.h : interface of the CYCoordDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_YCOORDDOC_H__0D7C3810_77BB_11D2_991B_00C04FC29F5C__INCLUDED_)
#define AFX_YCOORDDOC_H__0D7C3810_77BB_11D2_991B_00C04FC29F5C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CYCoordDoc : public CDocument
{
protected: // create from serialization only
	CYCoordDoc();
	DECLARE_DYNCREATE(CYCoordDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CYCoordDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CYCoordDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CYCoordDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_YCOORDDOC_H__0D7C3810_77BB_11D2_991B_00C04FC29F5C__INCLUDED_)
