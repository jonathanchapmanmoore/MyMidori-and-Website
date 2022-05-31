// nwndDoc.h : interface of the CNwndDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_NWNDDOC_H__2FA6F061_5467_11D2_873C_444553540000__INCLUDED_)
#define AFX_NWNDDOC_H__2FA6F061_5467_11D2_873C_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CNwndDoc : public CDocument
{
protected: // create from serialization only
	CNwndDoc();
	DECLARE_DYNCREATE(CNwndDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNwndDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CNwndDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CNwndDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NWNDDOC_H__2FA6F061_5467_11D2_873C_444553540000__INCLUDED_)
