// STUploadDoc.cpp : implementation of the CSTUploadDoc class
//

#include "stdafx.h"
#include "STUpload.h"

#include "STUploadDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSTUploadDoc

IMPLEMENT_DYNCREATE(CSTUploadDoc, CDocument)

BEGIN_MESSAGE_MAP(CSTUploadDoc, CDocument)
	//{{AFX_MSG_MAP(CSTUploadDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSTUploadDoc construction/destruction
CSTUploadDoc::CSTUploadDoc()
{
	m_DocList.AddTail( CStockData( _T("ARSC"), 
					   COleDateTime( 1999, 4, 1, 0, 0, 0 ),
					   22.33 ));
	m_DocList.AddTail( CStockData( _T("ARSC"), 
					   COleDateTime( 1999, 4, 2, 0, 0, 0 ),
					   23.44 ));
	m_DocList.AddTail( CStockData( _T("ARSC"), 
					   COleDateTime( 1999, 4, 3, 0, 0, 0 ),
					   24.55 ));
	m_DocList.AddTail( CStockData( _T("ARSC"), 
					   COleDateTime( 1999, 4, 4, 0, 0, 0 ),
					   25.66 ));
	m_DocList.AddTail( CStockData( _T("ARSC"), 
					   COleDateTime( 1999, 4, 5, 0, 0, 0 ),
					   26.77 ));
	
}


CSTUploadDoc::~CSTUploadDoc()
{
}

BOOL CSTUploadDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSTUploadDoc serialization

void CSTUploadDoc::Serialize(CArchive& ar)
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
// CSTUploadDoc diagnostics

#ifdef _DEBUG
void CSTUploadDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSTUploadDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSTUploadDoc commands
