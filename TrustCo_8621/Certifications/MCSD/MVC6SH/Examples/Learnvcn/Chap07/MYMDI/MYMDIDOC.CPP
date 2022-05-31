// MyMdiDoc.cpp : implementation of the CMyMdiDoc class
//

#include "stdafx.h"
#include "MyMdi.h"

#include "MyMdiDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyMdiDoc

IMPLEMENT_DYNCREATE(CMyMdiDoc, CDocument)

BEGIN_MESSAGE_MAP(CMyMdiDoc, CDocument)
	//{{AFX_MSG_MAP(CMyMdiDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyMdiDoc construction/destruction

CMyMdiDoc::CMyMdiDoc()
{
	// TODO: add one-time construction code here

}

CMyMdiDoc::~CMyMdiDoc()
{
}

BOOL CMyMdiDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMyMdiDoc serialization

void CMyMdiDoc::Serialize(CArchive& ar)
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
// CMyMdiDoc diagnostics

#ifdef _DEBUG
void CMyMdiDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMyMdiDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyMdiDoc commands
