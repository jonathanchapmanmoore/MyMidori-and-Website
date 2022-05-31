// STUpload.h : main header file for the STUPLOAD application
//

#if !defined(AFX_STUPLOAD_H__8F89ECB9_D435_11D2_925F_0080C7FA0C3E__INCLUDED_)
#define AFX_STUPLOAD_H__8F89ECB9_D435_11D2_925F_0080C7FA0C3E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSTUploadApp:
// See STUpload.cpp for the implementation of this class
//

class CSTUploadApp : public CWinApp
{
public:
	CSTUploadApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSTUploadApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSTUploadApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STUPLOAD_H__8F89ECB9_D435_11D2_925F_0080C7FA0C3E__INCLUDED_)
