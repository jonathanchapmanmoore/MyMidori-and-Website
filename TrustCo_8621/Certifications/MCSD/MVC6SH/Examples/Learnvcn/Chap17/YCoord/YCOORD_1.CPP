// YCoordDoc.cpp : implementation of the CYCoordDoc class
//

#include "stdafx.h"
#include "YCoord.h"

#include "YCoordDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CYCoordDoc

IMPLEMENT_DYNCREATE(CYCoordDoc, CDocument)

BEGIN_MESSAGE_MAP(CYCoordDoc, CDocument)
	//{{AFX_MSG_MAP(CYCoordDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CYCoordDoc construction/destruction

CYCoordDoc::CYCoordDoc()
{
	// TODO: add one-time construction code here

}

CYCoordDoc::~CYCoordDoc()
{
}

BOOL CYCoordDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CYCoordDoc serialization

void CYCoordDoc::Serialize(CArchive& ar)
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
// CYCoordDoc diagnostics

#ifdef _DEBUG
void CYCoordDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CYCoordDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CYCoordDoc commands
