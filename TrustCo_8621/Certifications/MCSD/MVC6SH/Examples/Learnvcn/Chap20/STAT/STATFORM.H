#if !defined(AFX_STATFORM_H__905F84D5_612C_11D2_873C_B66B3F55AE21__INCLUDED_)
#define AFX_STATFORM_H__905F84D5_612C_11D2_873C_B66B3F55AE21__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StatForm.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStatForm form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CStatForm : public CFormView
{
protected:
	CStatForm();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CStatForm)

// Form Data
public:
	//{{AFX_DATA(CStatForm)
	enum { IDD = IDD_FORM1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStatForm)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CStatForm();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CStatForm)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STATFORM_H__905F84D5_612C_11D2_873C_B66B3F55AE21__INCLUDED_)
