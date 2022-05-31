// tabsDoc.cpp : implementation of the CTabsDoc class
//

#include "stdafx.h"
#include "tabs.h"

#include "tabsDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTabsDoc

IMPLEMENT_DYNCREATE(CTabsDoc, CDocument)

BEGIN_MESSAGE_MAP(CTabsDoc, CDocument)
	//{{AFX_MSG_MAP(CTabsDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTabsDoc construction/destruction

CTabsDoc::CTabsDoc()
{
	// TODO: add one-time construction code here

}

CTabsDoc::~CTabsDoc()
{
}

BOOL CTabsDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTabsDoc serialization

void CTabsDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CTabsDoc diagnostics

#ifdef _DEBUG
void CTabsDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTabsDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTabsDoc commands
