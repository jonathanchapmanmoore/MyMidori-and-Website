// bball.h : main header file for the BBALL application
//

#if !defined(AFX_BBALL_H__8D974B2D_0E79_11D2_86D5_904A03C16C61__INCLUDED_)
#define AFX_BBALL_H__8D974B2D_0E79_11D2_86D5_904A03C16C61__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CBballApp:
// See bball.cpp for the implementation of this class
//

class CBballApp : public CWinApp
{
public:
	CBballApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBballApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CBballApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BBALL_H__8D974B2D_0E79_11D2_86D5_904A03C16C61__INCLUDED_)
