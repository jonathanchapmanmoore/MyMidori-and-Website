// STUploadDoc.h : interface of the CSTUploadDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_STUPLOADDOC_H__8F89ECBF_D435_11D2_925F_0080C7FA0C3E__INCLUDED_)
#define AFX_STUPLOADDOC_H__8F89ECBF_D435_11D2_925F_0080C7FA0C3E__INCLUDED_

#include "StockDataList.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSTUploadDoc : public CDocument
{
protected: // create from serialization only
	CSTUploadDoc();
	DECLARE_DYNCREATE(CSTUploadDoc)

// Attributes
public:
	CString GetCurrentFund () { return m_strCurrentFund; }
	void SetCurrentFund (CString strSet){ m_strCurrentFund= strSet;}

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSTUploadDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual void DeleteContents();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSTUploadDoc();
	const CStockDataList & GetDocList() { return m_DocList; }

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	CString m_strCurrentFund;
	BOOL LoadData( CStdioFile & infile );
	CStockDataList m_DocList;
	//{{AFX_MSG(CSTUploadDoc)
	afx_msg void OnDataImport();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STUPLOADDOC_H__8F89ECBF_D435_11D2_925F_0080C7FA0C3E__INCLUDED_)
