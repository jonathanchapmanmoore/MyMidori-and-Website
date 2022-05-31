// bballDoc.h : interface of the CBballDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BBALLDOC_H__8D974B33_0E79_11D2_86D5_904A03C16C61__INCLUDED_)
#define AFX_BBALLDOC_H__8D974B33_0E79_11D2_86D5_904A03C16C61__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBballDoc : public CDocument
{
protected: // create from serialization only
	CBballDoc();
	DECLARE_DYNCREATE(CBballDoc)

// Attributes
public:
	CStringArray arTeams;
	CStringArray arWinners;
	CStringArray arNoWins;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBballDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual void DeleteContents();
	//}}AFX_VIRTUAL

// Implementation
public:
	void WriteNonWinners();
	virtual ~CBballDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBballDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BBALLDOC_H__8D974B33_0E79_11D2_86D5_904A03C16C61__INCLUDED_)
