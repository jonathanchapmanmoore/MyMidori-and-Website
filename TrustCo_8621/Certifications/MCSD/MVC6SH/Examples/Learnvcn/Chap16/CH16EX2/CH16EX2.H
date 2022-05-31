// Ch16Ex2.h : main header file for the CH16EX2 application
//

#if !defined(AFX_CH16EX2_H__88D9EBB9_7D7E_11D2_873C_D2D0E0D78E1E__INCLUDED_)
#define AFX_CH16EX2_H__88D9EBB9_7D7E_11D2_873C_D2D0E0D78E1E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCh16Ex2App:
// See Ch16Ex2.cpp for the implementation of this class
//

class CCh16Ex2App : public CWinApp
{
public:
	CCh16Ex2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCh16Ex2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CCh16Ex2App)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CH16EX2_H__88D9EBB9_7D7E_11D2_873C_D2D0E0D78E1E__INCLUDED_)
