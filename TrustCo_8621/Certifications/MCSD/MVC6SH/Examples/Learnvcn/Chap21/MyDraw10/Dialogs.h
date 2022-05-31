#if !defined(AFX_DIALOGS_H__5F38F323_7ED4_11D2_991B_00C04FC29F5C__INCLUDED_)
#define AFX_DIALOGS_H__5F38F323_7ED4_11D2_991B_00C04FC29F5C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dialogs.h : header file
//

#include "DrawVw.h"

/////////////////////////////////////////////////////////////////////////////
// CTitleDialog dialog

class CTitleDialog : public CDialog
{
// Construction
public:
	CTitleDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTitleDialog)
	enum { IDD = IDD_DRAWING_TITLE };
	CString	m_strDrawing;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTitleDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTitleDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// CLinePage dialog

class CLinePage : public CPropertyPage
{
	DECLARE_DYNCREATE(CLinePage)

// Construction
public:
	void GetCustomColor();
	CLinePage();
	~CLinePage();
	UINT m_nColorIndex;
	COLORREF m_colorRGB;


// Dialog Data
	//{{AFX_DATA(CLinePage)
	enum { IDD = IDD_PS_LINE };
	CSpinButtonCtrl	m_spinThickness;
	CComboBox	m_comboColor;
	UINT	m_nThickness;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CLinePage)
	public:
	virtual BOOL OnSetActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CLinePage)
	afx_msg void OnSelchangeComboColor();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};
/////////////////////////////////////////////////////////////////////////////
// CShapePage dialog

class CShapePage : public CPropertyPage
{
	DECLARE_DYNCREATE(CShapePage)

// Construction
public:
	CShapePage();
	~CShapePage();

// Dialog Data
	//{{AFX_DATA(CShapePage)
	enum { IDD = IDD_PSS_SHAPE };
	BOOL	m_bTransparent;
	int		m_nShpRectangle;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CShapePage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CShapePage)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGS_H__5F38F323_7ED4_11D2_991B_00C04FC29F5C__INCLUDED_)
