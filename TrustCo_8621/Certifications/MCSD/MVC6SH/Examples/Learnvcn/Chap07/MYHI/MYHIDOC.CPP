////////////////////////////////
//
// MyHiDoc.cpp
//
////////////////////////////////

#include "stdafx.h"
#include "MyHi.h"

#include "MyHiDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyHiDoc

IMPLEMENT_DYNCREATE(CMyHiDoc, CDocument)

BEGIN_MESSAGE_MAP(CMyHiDoc, CDocument)
	//{{AFX_MSG_MAP(CMyHiDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyHiDoc construction/destruction

CMyHiDoc::CMyHiDoc()
{
	// TODO: add one-time construction code here
	m_strText = "Hi, MFC!";
}

CMyHiDoc::~CMyHiDoc()
{
}

BOOL CMyHiDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMyHiDoc serialization

void CMyHiDoc::Serialize(CArchive& ar)
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
// CMyHiDoc diagnostics

#ifdef _DEBUG
void CMyHiDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMyHiDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyHiDoc commands
