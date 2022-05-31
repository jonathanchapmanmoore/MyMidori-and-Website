// Stat.h : main header file for the STAT application
//

#if !defined(AFX_STAT_H__905F84C5_612C_11D2_873C_B66B3F55AE21__INCLUDED_)
#define AFX_STAT_H__905F84C5_612C_11D2_873C_B66B3F55AE21__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CStatApp:
// See Stat.cpp for the implementation of this class
//

class CStatApp : public CWinApp
{
public:
	CStatApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStatApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CStatApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STAT_H__905F84C5_612C_11D2_873C_B66B3F55AE21__INCLUDED_)
