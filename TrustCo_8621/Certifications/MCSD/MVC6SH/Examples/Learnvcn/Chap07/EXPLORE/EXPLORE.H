// Explore.h : main header file for the EXPLORE application
//

#if !defined(AFX_EXPLORE_H__E71AF429_6381_11D2_873C_444553540000__INCLUDED_)
#define AFX_EXPLORE_H__E71AF429_6381_11D2_873C_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CExploreApp:
// See Explore.cpp for the implementation of this class
//

class CExploreApp : public CWinApp
{
public:
	CExploreApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExploreApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CExploreApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXPLORE_H__E71AF429_6381_11D2_873C_444553540000__INCLUDED_)
