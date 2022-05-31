// C16x2Doc.h : interface of the CCh16Ex2Doc class
//

///////////////////
//
//  See the document Ch16Ex2.doc in the companion code
//  for a description of this program.
//
///////////////////

/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_C16X2DOC_H__88D9EBBF_7D7E_11D2_873C_D2D0E0D78E1E__INCLUDED_)
#define AFX_C16X2DOC_H__88D9EBBF_7D7E_11D2_873C_D2D0E0D78E1E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// A class derived from CObject
class CMyObject : public CObject
{
public:
	CMyObject() { m_intObj = 0; m_strObj = "String: CMyObject."; };
	int m_intObj;
	CString m_strObj;
	void Serialize(CArchive& ar) 
	{ 
		//CObject::Serialize(ar);
		if(ar.IsStoring())
		{
			ar << m_intObj << m_strObj;
		}
		else
		{
			ar >> m_intObj >> m_strObj;
		}
	}
};

// A class not derived from CObject
class CMyObject2
{
public:
	CMyObject2() { m_intObj2 = 1; m_strObj2 = "String: CMyObject2."; };
	int m_intObj2;
	CString m_strObj2;
};

class CCh16Ex2Doc : public CDocument
{
protected: // create from serialization only
	CCh16Ex2Doc();
	DECLARE_DYNCREATE(CCh16Ex2Doc)

// Attributes
public:
	// Some primitive types
	int m_int;
	double m_double;
	BYTE m_byte;
	CString m_str;    // Not technically primitive, but
	                  //  already supported for serialization
	// An embedded object derived from CObject
	CMyObject m_myObj;
	// A pointer to an object derived from CObject
	CMyObject* m_pMyObj;
	// An embedded object not derived from CObject
	CMyObject2 m_myObj2;
	// A pointer to an object not derived from CObject
	CMyObject2* m_pMyObj2;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCh16Ex2Doc)
	public:
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnNewDocument();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCh16Ex2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCh16Ex2Doc)
	afx_msg void OnChangeEditValues();
	afx_msg void OnChangeZeroOut();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_C16X2DOC_H__88D9EBBF_7D7E_11D2_873C_D2D0E0D78E1E__INCLUDED_)
