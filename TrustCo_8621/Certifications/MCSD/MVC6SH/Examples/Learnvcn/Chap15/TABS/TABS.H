// tabs.h : main header file for the TABS application
//

#if !defined(AFX_TABS_H__C193E547_D6A8_11D1_873C_A89A32B32032__INCLUDED_)
#define AFX_TABS_H__C193E547_D6A8_11D1_873C_A89A32B32032__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTabsApp:
// See tabs.cpp for the implementation of this class
//

class CTabsApp : public CWinApp
{
public:
	CTabsApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTabsApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTabsApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TABS_H__C193E547_D6A8_11D1_873C_A89A32B32032__INCLUDED_)
