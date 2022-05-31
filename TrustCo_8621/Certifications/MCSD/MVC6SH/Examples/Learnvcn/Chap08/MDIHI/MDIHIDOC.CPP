// MdiHiDoc.cpp : implementation of the CMdiHiDoc class
//

#include "stdafx.h"
#include "MdiHi.h"

#include "MdiHiDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMdiHiDoc

IMPLEMENT_DYNCREATE(CMdiHiDoc, CDocument)

BEGIN_MESSAGE_MAP(CMdiHiDoc, CDocument)
	//{{AFX_MSG_MAP(CMdiHiDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMdiHiDoc construction/destruction

CMdiHiDoc::CMdiHiDoc()
{
	// TODO: add one-time construction code here

}

CMdiHiDoc::~CMdiHiDoc()
{
}

BOOL CMdiHiDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMdiHiDoc serialization

void CMdiHiDoc::Serialize(CArchive& ar)
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
// CMdiHiDoc diagnostics

#ifdef _DEBUG
void CMdiHiDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMdiHiDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMdiHiDoc commands
