// Dialogs.cpp : implementation file
//

#include "stdafx.h"
#include "MyDraw.h"
#include "Dialogs.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTitleDialog dialog


CTitleDialog::CTitleDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CTitleDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTitleDialog)
	m_strDrawing = _T("");
	//}}AFX_DATA_INIT
}


void CTitleDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTitleDialog)
	DDX_Text(pDX, IDC_DRAWING_TITLE, m_strDrawing);
	DDV_MaxChars(pDX, m_strDrawing, 70);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTitleDialog, CDialog)
	//{{AFX_MSG_MAP(CTitleDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTitleDialog message handlers
/////////////////////////////////////////////////////////////////////////////
// CLinePage property page

IMPLEMENT_DYNCREATE(CLinePage, CPropertyPage)

CLinePage::CLinePage() : CPropertyPage(CLinePage::IDD)
{
	//{{AFX_DATA_INIT(CLinePage)
	m_nThickness = 0;
	//}}AFX_DATA_INIT
}

CLinePage::~CLinePage()
{
}

void CLinePage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLinePage)
	DDX_Control(pDX, IDC_SPIN1, m_spinThickness);
	DDX_Control(pDX, IDC_COMBO1, m_comboColor);
	DDX_Text(pDX, IDC_EDIT1, m_nThickness);
	DDV_MinMaxUInt(pDX, m_nThickness, 0, 5);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLinePage, CPropertyPage)
	//{{AFX_MSG_MAP(CLinePage)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeComboColor)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLinePage message handlers
/////////////////////////////////////////////////////////////////////////////
// CShapePage property page

IMPLEMENT_DYNCREATE(CShapePage, CPropertyPage)

CShapePage::CShapePage() : CPropertyPage(CShapePage::IDD)
{
	//{{AFX_DATA_INIT(CShapePage)
	m_bTransparent = FALSE;
	m_nShpRectangle = -1;
	//}}AFX_DATA_INIT
}

CShapePage::~CShapePage()
{
}

void CShapePage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CShapePage)
	DDX_Check(pDX, IDC_CHECK1, m_bTransparent);
	DDX_Radio(pDX, IDC_RADIO1, m_nShpRectangle);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CShapePage, CPropertyPage)
	//{{AFX_MSG_MAP(CShapePage)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShapePage message handlers

BOOL CLinePage::OnSetActive() 
{
	// TODO: Add your specialized code here and/or call the base class
	
	// Initialize combo box just before 
	//  Line tab becomes active.
	// Initialize spin button control.
    m_spinThickness.SetRange(0, 5);

    // Load color names into combo box.
    for(int i = 0; i < 11; i++)
    {
        m_comboColor.AddString(arColorNames[i]);
    }
    // Set the combo box to the current color.
    m_comboColor.SetCurSel(m_nColorIndex);

	return CPropertyPage::OnSetActive();
}

void CLinePage::OnSelchangeComboColor() 
{
	// TODO: Add your control notification handler code here
	m_nColorIndex = m_comboColor.GetCurSel();
    m_colorRGB = arColors[m_nColorIndex];
    // Respond if user chose "Custom Color" in the combo box.
    if(m_nColorIndex == CUSTOM_COLOR_INDEX)
    {
        GetCustomColor(); // Display the Color dialog.
    }

}

void CLinePage::GetCustomColor()
{
	// Display the Color dialog box.

    CColorDialog dlg;
    dlg.m_cc.rgbResult = m_colorRGB;
    if(dlg.DoModal() == IDOK)
    {
        m_colorRGB = dlg.GetColor();
        m_nColorIndex = CUSTOM_COLOR_INDEX;
    }
}
