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
	ON_COMMAND(ID_DATA_IMPORT, OnDataImport)
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
					   25.44 ));
	m_DocList.AddTail( CStockData( _T("ARSC"), 
					   COleDateTime( 1999, 4, 3, 0, 0, 0 ),
					   23.55 ));
	m_DocList.AddTail( CStockData( _T("ARSC"), 
					   COleDateTime( 1999, 4, 4, 0, 0, 0 ),
					   27.66 ));
	m_DocList.AddTail( CStockData( _T("ARSC"), 
					   COleDateTime( 1999, 4, 5, 0, 0, 0 ),
					   28.77 ));
	m_DocList.AddTail( CStockData( _T("BBIC"), 
					   COleDateTime( 1999, 4, 1, 0, 0, 0 ),
					   15.33 ));
	m_DocList.AddTail( CStockData( _T("BBIC"), 
					   COleDateTime( 1999, 4, 2, 0, 0, 0 ),
					   16.44 ));
	m_DocList.AddTail( CStockData( _T("BBIC"), 
					   COleDateTime( 1999, 4, 3, 0, 0, 0 ),
					   13.55 ));
	m_DocList.AddTail( CStockData( _T("BBIC"), 
					   COleDateTime( 1999, 4, 4, 0, 0, 0 ),
					   14.66 ));
	m_DocList.AddTail( CStockData( _T("BBIC"), 
					   COleDateTime( 1999, 4, 5, 0, 0, 0 ),
					   12.77 ));
	m_DocList.AddTail( CStockData( _T("COMP"), 
					   COleDateTime( 1999, 4, 1, 0, 0, 0 ),
					   15.33 ));
	m_DocList.AddTail( CStockData( _T("COMP"), 
					   COleDateTime( 1999, 4, 2, 0, 0, 0 ),
					   16.44 ));
	m_DocList.AddTail( CStockData( _T("COMP"), 
					   COleDateTime( 1999, 4, 3, 0, 0, 0 ),
					   18.55 ));
	m_DocList.AddTail( CStockData( _T("COMP"), 
					   COleDateTime( 1999, 4, 4, 0, 0, 0 ),
					   21.66 ));
	m_DocList.AddTail( CStockData( _T("COMP"), 
					   COleDateTime( 1999, 4, 5, 0, 0, 0 ),
					   19.77 ));

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

void CSTUploadDoc::OnDataImport() 
{
	// String to customize File Dialog
	CString strFilter = "Data Files (*.dat)|*.dat|All Files (*.*)|*.*||";
	
	CFileDialog aFileDialog( TRUE, NULL, NULL,
		                     OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
							 strFilter);
	
	int nID = aFileDialog.DoModal();
	
}
