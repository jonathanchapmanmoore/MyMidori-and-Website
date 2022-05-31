// StatDoc.cpp : implementation of the CStatDoc class
//

#include "stdafx.h"
#include "Stat.h"

#include "StatDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStatDoc

IMPLEMENT_DYNCREATE(CStatDoc, CDocument)

BEGIN_MESSAGE_MAP(CStatDoc, CDocument)
	//{{AFX_MSG_MAP(CStatDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStatDoc construction/destruction

CStatDoc::CStatDoc()
{
	// TODO: add one-time construction code here

}

CStatDoc::~CStatDoc()
{
}

BOOL CStatDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CStatDoc serialization

void CStatDoc::Serialize(CArchive& ar)
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
// CStatDoc diagnostics

#ifdef _DEBUG
void CStatDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CStatDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CStatDoc commands
