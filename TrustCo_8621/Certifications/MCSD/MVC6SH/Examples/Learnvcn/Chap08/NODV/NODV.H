// nodv.h : main header file for the NODV application
//

#if !defined(AFX_NODV_H__0BB2A2A9_11A8_11D2_86D5_904A03C16C61__INCLUDED_)
#define AFX_NODV_H__0BB2A2A9_11A8_11D2_86D5_904A03C16C61__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CNodvApp:
// See nodv.cpp for the implementation of this class
//

class CNodvApp : public CWinApp
{
public:
	CNodvApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNodvApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

public:
	//{{AFX_MSG(CNodvApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NODV_H__0BB2A2A9_11A8_11D2_86D5_904A03C16C61__INCLUDED_)
