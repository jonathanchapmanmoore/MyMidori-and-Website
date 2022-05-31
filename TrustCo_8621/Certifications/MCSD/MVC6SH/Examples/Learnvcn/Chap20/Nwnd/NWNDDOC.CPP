// nwndDoc.cpp : implementation of the CNwndDoc class
//

#include "stdafx.h"
#include "nwnd.h"

#include "nwndDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNwndDoc

IMPLEMENT_DYNCREATE(CNwndDoc, CDocument)

BEGIN_MESSAGE_MAP(CNwndDoc, CDocument)
	//{{AFX_MSG_MAP(CNwndDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNwndDoc construction/destruction

CNwndDoc::CNwndDoc()
{
	// TODO: add one-time construction code here

}

CNwndDoc::~CNwndDoc()
{
}

BOOL CNwndDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CNwndDoc serialization

void CNwndDoc::Serialize(CArchive& ar)
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
// CNwndDoc diagnostics

#ifdef _DEBUG
void CNwndDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CNwndDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CNwndDoc commands
