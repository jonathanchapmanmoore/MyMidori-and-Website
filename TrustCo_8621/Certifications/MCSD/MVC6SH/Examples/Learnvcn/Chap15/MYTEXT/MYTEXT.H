// MyText.h : main header file for the MYTEXT application
//

#if !defined(AFX_MYTEXT_H__8DEF9A48_0858_11D2_873C_D28B633D8E0E__INCLUDED_)
#define AFX_MYTEXT_H__8DEF9A48_0858_11D2_873C_D28B633D8E0E__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyTextApp:
// See MyText.cpp for the implementation of this class
//

class CMyTextApp : public CWinApp
{
public:
	CMyTextApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyTextApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMyTextApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYTEXT_H__8DEF9A48_0858_11D2_873C_D28B633D8E0E__INCLUDED_)
