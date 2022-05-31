// dialogs.cpp : implementation file
//

#include "stdafx.h"
#include "MyDraw.h"
#include "dialogs.h"

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
	DDX_Control(pDX, IDC_COMBO1, m_comboColor);
	DDX_Control(pDX, IDC_SPIN1, m_spinThickness);
	DDX_Text(pDX, IDC_EDIT1, m_nThickness);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLinePage, CPropertyPage)
	//{{AFX_MSG_MAP(CLinePage)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeComboColor)
	ON_WM_CTLCOLOR()
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
    // Initialize spin button control
    m_spinThickness.SetRange(0, 5);

	// Load color names into combo box
    for(int i = 0; i < 11; i++)
    {
        m_comboColor.AddString(arColorNames[i]);
    }
    // Set the combo box to the current color
    m_comboColor.SetCurSel(m_nColorIndex);
	
	return CPropertyPage::OnSetActive();
}

void CLinePage::OnSelchangeComboColor() 
{
	// TODO: Add your control notification handler code here
    m_nColorIndex = m_comboColor.GetCurSel();
    m_colorRGB = arColors[m_nColorIndex];
    // Respond if user chose "Custom Color" in the combo box
    if(m_nColorIndex == CUSTOM_COLOR_INDEX)
    {
        GetCustomColor(); // Display the Color dialog
    }
	UpdateStaticColor();
}

void CLinePage::GetCustomColor()
{
    CColorDialog dlg;
    dlg.m_cc.rgbResult = m_colorRGB;
    if(dlg.DoModal() == IDOK)
    {
        m_colorRGB = dlg.GetColor();
        m_nColorIndex = CUSTOM_COLOR_INDEX;
    }
}

void CLinePage::UpdateStaticColor()
{
    // Update the static text color indicator in the Line tab

    // Get current color
    // Obtain ptrs to static text color indicator control
    //   & its device context
    CWnd* pWnd = (CWnd*) GetDlgItem(IDC_STATIC_COLOR);
    CDC* pDC = pWnd->GetDC();

    // Use ptrs to change color indicator's color
    HBRUSH hbr = OnCtlColor(pDC, pWnd, CTLCOLOR_STATIC);

    // Cause the dialog window to be redrawn so color shows up
    Invalidate();	
}

HBRUSH CLinePage::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
    // Change text color of static text color indicator control
    //   to currently selected color

    HBRUSH hbr = CPropertyPage::OnCtlColor(pDC, pWnd, nCtlColor);
    
    // TODO: Change any attributes of the DC here
    // See if pWnd points to our static text color indicator
    if(pWnd->GetDlgCtrlID() == IDC_STATIC_COLOR)
        pDC->SetTextColor(m_colorRGB);
	
	// TODO: Return a different brush if the default is not desired
	return hbr;
}
