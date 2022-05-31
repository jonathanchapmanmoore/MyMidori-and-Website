// YCoord.h : main header file for the YCOORD application
//

#if !defined(AFX_YCOORD_H__0D7C3808_77BB_11D2_991B_00C04FC29F5C__INCLUDED_)
#define AFX_YCOORD_H__0D7C3808_77BB_11D2_991B_00C04FC29F5C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CYCoordApp:
// See YCoord.cpp for the implementation of this class
//

class CYCoordApp : public CWinApp
{
public:
	CYCoordApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CYCoordApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CYCoordApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_YCOORD_H__0D7C3808_77BB_11D2_991B_00C04FC29F5C__INCLUDED_)
