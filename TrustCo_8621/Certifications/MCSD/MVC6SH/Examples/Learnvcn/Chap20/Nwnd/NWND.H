// nwnd.h : main header file for the NWND application
//

#if !defined(AFX_NWND_H__2FA6F059_5467_11D2_873C_444553540000__INCLUDED_)
#define AFX_NWND_H__2FA6F059_5467_11D2_873C_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CNwndApp:
// See nwnd.cpp for the implementation of this class
//

class CNwndApp : public CWinApp
{
public:
	CNwndApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNwndApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CNwndApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NWND_H__2FA6F059_5467_11D2_873C_444553540000__INCLUDED_)
