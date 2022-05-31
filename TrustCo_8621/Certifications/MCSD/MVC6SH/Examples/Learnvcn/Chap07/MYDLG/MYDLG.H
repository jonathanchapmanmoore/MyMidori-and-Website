// MyDlg.h : main header file for the MYDLG application
//

#if !defined(AFX_MYDLG_H__5E426C84_63A9_11D2_873C_D5E416AAF519__INCLUDED_)
#define AFX_MYDLG_H__5E426C84_63A9_11D2_873C_D5E416AAF519__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyDlgApp:
// See MyDlg.cpp for the implementation of this class
//

class CMyDlgApp : public CWinApp
{
public:
	CMyDlgApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyDlgApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMyDlgApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYDLG_H__5E426C84_63A9_11D2_873C_D5E416AAF519__INCLUDED_)
