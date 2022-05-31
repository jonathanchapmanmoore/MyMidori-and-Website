// Ch14Ex2.h : main header file for the CH14EX2 application
//

#if !defined(AFX_CH14EX2_H__FD12CB5B_5E8E_11D2_873C_E44B3671671E__INCLUDED_)
#define AFX_CH14EX2_H__FD12CB5B_5E8E_11D2_873C_E44B3671671E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCh14Ex2App:
// See Ch14Ex2.cpp for the implementation of this class
//

class CCh14Ex2App : public CWinApp
{
public:
	CCh14Ex2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCh14Ex2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

public:
	//{{AFX_MSG(CCh14Ex2App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CH14EX2_H__FD12CB5B_5E8E_11D2_873C_E44B3671671E__INCLUDED_)
