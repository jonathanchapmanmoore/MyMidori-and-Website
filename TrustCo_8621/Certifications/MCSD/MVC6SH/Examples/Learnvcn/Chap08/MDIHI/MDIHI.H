// MdiHi.h : main header file for the MDIHI application
//

#if !defined(AFX_MDIHI_H__B9B29D05_6508_11D2_873C_E7CEFA286A32__INCLUDED_)
#define AFX_MDIHI_H__B9B29D05_6508_11D2_873C_E7CEFA286A32__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMdiHiApp:
// See MdiHi.cpp for the implementation of this class
//

class CMdiHiApp : public CWinApp
{
public:
	CMdiHiApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMdiHiApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMdiHiApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MDIHI_H__B9B29D05_6508_11D2_873C_E7CEFA286A32__INCLUDED_)
