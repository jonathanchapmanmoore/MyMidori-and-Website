// ExplDoc.cpp : implementation of the CExploreDoc class
//

#include "stdafx.h"
#include "Explore.h"

#include "ExplDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExploreDoc

IMPLEMENT_DYNCREATE(CExploreDoc, CDocument)

BEGIN_MESSAGE_MAP(CExploreDoc, CDocument)
	//{{AFX_MSG_MAP(CExploreDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExploreDoc construction/destruction

CExploreDoc::CExploreDoc()
{
	// TODO: add one-time construction code here

}

CExploreDoc::~CExploreDoc()
{
}

BOOL CExploreDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CExploreDoc serialization

void CExploreDoc::Serialize(CArchive& ar)
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
// CExploreDoc diagnostics

#ifdef _DEBUG
void CExploreDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CExploreDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CExploreDoc commands
