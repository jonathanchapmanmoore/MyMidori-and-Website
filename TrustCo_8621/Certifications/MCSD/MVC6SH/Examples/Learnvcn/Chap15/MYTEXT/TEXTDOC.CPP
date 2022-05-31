// TextDoc.cpp : implementation of the CMyTextDoc class
//

#include "stdafx.h"
#include "MyText.h"

#include "TextDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyTextDoc

IMPLEMENT_DYNCREATE(CMyTextDoc, CDocument)

BEGIN_MESSAGE_MAP(CMyTextDoc, CDocument)
	//{{AFX_MSG_MAP(CMyTextDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyTextDoc construction/destruction

CMyTextDoc::CMyTextDoc()
{
	// TODO: add one-time construction code here

}

CMyTextDoc::~CMyTextDoc()
{
}

BOOL CMyTextDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMyTextDoc serialization

void CMyTextDoc::Serialize(CArchive& ar)
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
// CMyTextDoc diagnostics

#ifdef _DEBUG
void CMyTextDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMyTextDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyTextDoc commands
