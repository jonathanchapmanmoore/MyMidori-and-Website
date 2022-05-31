////////////////////////////////
//
// MyHi.h
//
////////////////////////////////

#if !defined(AFX_MYHI_H__D2FA4027_B990_11D1_873C_CC328AE73F3B__INCLUDED_)
#define AFX_MYHI_H__D2FA4027_B990_11D1_873C_CC328AE73F3B__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyHiApp:
// See MyHi.cpp for the implementation of this class
//

class CMyHiApp : public CWinApp
{
public:
	CMyHiApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyHiApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMyHiApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYHI_H__D2FA4027_B990_11D1_873C_CC328AE73F3B__INCLUDED_)
