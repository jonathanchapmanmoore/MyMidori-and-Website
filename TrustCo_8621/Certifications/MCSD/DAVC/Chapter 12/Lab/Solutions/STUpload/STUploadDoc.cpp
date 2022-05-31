// STUploadDoc.cpp : implementation of the CSTUploadDoc class
//

#include "stdafx.h"
#include "STUpload.h"

#include "STUploadDoc.h"
#include "SrvrItem.h"
#include "MainFrm.h"
#include "ResultsDialog.h"
#include "QueryDialog.h"

#include "ConflictDialog.h"

#include <comdef.h>	 // for Compiler COM support
#include <lmcons.h>  // for the UNLEN constant
#include ".\STLoadData\STLoadData.h"
#include ".\STLoadData\STLoadData_i.c"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSTUploadDoc

IMPLEMENT_DYNCREATE(CSTUploadDoc, COleServerDoc)

BEGIN_MESSAGE_MAP(CSTUploadDoc, COleServerDoc)
	//{{AFX_MSG_MAP(CSTUploadDoc)
	ON_COMMAND(ID_DATA_IMPORT, OnDataImport)
	ON_COMMAND(ID_DATA_UPLOAD, OnDataUpload)
	ON_UPDATE_COMMAND_UI(ID_DATA_UPLOAD, OnUpdateDataUpload)
	ON_COMMAND(ID_DATA_QUERYDATABASE, OnDataQuerydatabase)
	ON_UPDATE_COMMAND_UI(ID_DATA_QUERYDATABASE, OnUpdateDataQuerydatabase)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSTUploadDoc construction/destruction
CSTUploadDoc::CSTUploadDoc()
{
	// Use OLE compound files
	EnableCompoundFile();

	m_strCurrentFund = "";
}


CSTUploadDoc::~CSTUploadDoc()
{
}

BOOL CSTUploadDoc::OnNewDocument()
{
	if (!COleServerDoc::OnNewDocument())
		return FALSE;

	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CSTUploadDoc server implementation

COleServerItem* CSTUploadDoc::OnGetEmbeddedItem()
{
	// OnGetEmbeddedItem is called by the framework to get the COleServerItem
	//  that is associated with the document.  It is only called when necessary.

	CSTUploadSrvrItem* pItem = new CSTUploadSrvrItem(this);
	ASSERT_VALID(pItem);
	return pItem;
}

/////////////////////////////////////////////////////////////////////////////
// CSTUploadDoc Active Document server implementation

CDocObjectServer *CSTUploadDoc::GetDocObjectServer(LPOLEDOCUMENTSITE pDocSite)
{
	return new CDocObjectServer(this, pDocSite);
}



/////////////////////////////////////////////////////////////////////////////
// CSTUploadDoc serialization

void CSTUploadDoc::Serialize(CArchive& ar)
{
	m_DocList.Serialize( ar );

	if (ar.IsStoring())
	{
		ar << m_strCurrentFund;	
	}
	else
	{
		ar >> m_strCurrentFund;

		// Update Fund Selection window
		CMainFrame* pWnd = 
		dynamic_cast< CMainFrame * > (AfxGetMainWnd());

		if( pWnd ) 
		// Will fail if running from icon or from
		// command line with file name argument
		{
			// Update and show fund window
			pWnd->UpdateFundList( m_DocList, m_strCurrentFund );
			pWnd->SetFundsVisible( TRUE );
		}
	
	}
}

/////////////////////////////////////////////////////////////////////////////
// CSTUploadDoc diagnostics

#ifdef _DEBUG
void CSTUploadDoc::AssertValid() const
{
	COleServerDoc::AssertValid();
}

void CSTUploadDoc::Dump(CDumpContext& dc) const
{
	COleServerDoc::Dump(dc);
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

	if( nID == IDOK )
	{
		CStdioFile aFile;

		CFileException fx;
		if( !aFile.Open( aFileDialog.GetPathName(), CFile::modeRead | CFile::typeText, &fx ) )
		{
			TCHAR buf[ 255 ];
			fx.GetErrorMessage( buf, 255 );
			CString strPrompt( buf );
			AfxMessageBox( strPrompt );
			return;
		}

		if( LoadData( aFile ) )
		{
			SetModifiedFlag();
			UpdateAllViews( NULL );
		}
	}
}




BOOL CSTUploadDoc::LoadData(CStdioFile &infile)
{
	// Check for NULL
	ASSERT( infile.m_hFile != NULL );
	
	// Hold data in temporary list of CStockData objects
	// which we only assign to CSTUploadDoc::m_DocList
	// when we are sure load has been completed succesfully
	CStockDataList TempList;

	// Additions are cumulative so we need to copy in existing data
	TempList.AddHead( &m_DocList );

	// line buffer
	CString strTemp;

	// Today's date
	COleDateTime Today = COleDateTime::GetCurrentTime();;
	COleDateTime FileDate;
	CString strFileHeader;

	int addedCtr = 0;	// count added items
	int discardedCtr = 0;	// count discarded items

	BOOL bFirstLine = TRUE;

	while( infile.ReadString( strTemp ) )
	{
		BOOL bValidDate = FALSE;
		CString strFund;
		CString strDate;
		
		// Exclude blank lines
		if( strTemp.GetLength() == 0 ) continue;

		if( bFirstLine )
		{
			// Get Header information
			strFileHeader = strTemp.Left(18);
			strFileHeader.TrimRight();
			strDate = strTemp.Mid( 18, 10 );
		}
		else
		{
			strFund = strTemp.Left(8);
			strFund.TrimRight();
			strDate = strTemp.Mid( 8, 10 );
		}


		int nYear = atoi( strDate.Right( 4 ));
		int nMonth = atoi( strDate.Left( 2 ));
		int nDay = atoi( strDate.Mid( 3, 2 ));
	
		
		COleDateTime aDate( nYear, nMonth, nDay, 0, 0, 0 );
		
		if( aDate.GetStatus() != COleDateTime::valid )
		{
			if( bFirstLine )
			{
				// Cannot read file date - assume invalid
				AfxMessageBox( "Invalid File Format" );
				return FALSE;
			}
			else
			{
				// Cannot read record date - discard line
				discardedCtr++;
				continue;
			}
		}


		if( bFirstLine )
		{
			// Get file date - loop back to top 
			FileDate = aDate;
			bFirstLine = FALSE;
			continue;
		}

		double dPrice = atof( strTemp.Mid( 19 ));

		// Make a CStockData object and add it 
		// to our temporary array
		CStockData aStData( strFund, aDate, dPrice );
		CStockDataList::errorstatus err;
		POSITION CurPos = TempList.AddSorted( aStData, err );

		switch( err )
		{
			// Discard identical entry
			case CStockDataList::duplicate_entry :

				discardedCtr ++ ;
				continue;

			// Same record, different price value
			case CStockDataList::conflicting_entry :  
			{
				// Query if user wishes to discard duplicate, replace or abort.
				CConflictDialog aDialog;

				// Construct text to appear in Rich Edit control
				CString strText = "Existing entry:\n\n";

				CStockData SDTemp = TempList.GetAt( CurPos );

				strText += SDTemp.GetAsString();
				strText += "\n\nReplacement entry:\n\n";
				strText += aStData.GetAsString();

				// Assign text to control variable
				aDialog.m_REditText = strText;

				switch( aDialog.DoModal() )
				{
					case IDABORT : // Abandon
					return FALSE;

					case IDCANCEL : // Discard new record
					discardedCtr++ ;
					continue;

					case IDOK :		// Replace existing record
					TempList.SetAt( CurPos, aStData );
				}
			}
			
			default:  // ok
				addedCtr++ ;
		}
	}

	// If we got this far then everything is OK -

	CString strPrompt;
	strPrompt.Format( 
		"Import of file %s complete:\nRecords loaded: %d \
		\nRecords discarded: %d  \
		\n\nHit OK to load data into document.",
		strFileHeader, addedCtr, discardedCtr );

	if( AfxMessageBox( strPrompt, MB_OKCANCEL ) == IDOK )
	{
		// Update document data
		m_DocList.RemoveAll();
		m_DocList.AddHead( &TempList );

		// Update fund view
		CMainFrame * pWnd = 
		dynamic_cast< CMainFrame * > (AfxGetMainWnd());

		if( pWnd )
		{
			pWnd->UpdateFundList( m_DocList );
			// Show fund window after loading new funds
			pWnd->SetFundsVisible( TRUE );
		}

		return TRUE;
	}
	else
		return FALSE;

}

void CSTUploadDoc::DeleteContents() 
{
	m_DocList.RemoveAll();

	CMainFrame * pWnd = 
		dynamic_cast< CMainFrame * > (AfxGetMainWnd());

	if( pWnd )
	{
		pWnd->UpdateFundList( m_DocList );
		// No funds on file, so hide fund window 
		pWnd->SetFundsVisible( FALSE );
		// And reset current fund value
		SetCurrentFund("");
	}

	
	COleServerDoc::DeleteContents();
}


void CSTUploadDoc::OnDataUpload() 
{
	if( AfxMessageBox( "Upload current file to database?",
					   MB_OKCANCEL ) == IDCANCEL )
		return;


	::CoInitialize( NULL ); 

	_COM_SMARTPTR_TYPEDEF(IUploadStockData, __uuidof(IUploadStockData));
	 
	IUploadStockDataPtr pServer;

	HRESULT hr = pServer.CreateInstance( CLSID_UploadStockData );

	if( SUCCEEDED( hr ) )
		hr = pServer->ConnectToDatabase();


	if( SUCCEEDED( hr ) )
	{
		try
		{
			POSITION pos = m_DocList.GetHeadPosition();

			while( pos )
			{
				CStockData sd = m_DocList.GetNext( pos );

				BSTR fund = sd.GetFund().AllocSysString();
				DATE date = sd.GetDate().m_dt;
				double price = sd.GetPrice();

				DWORD dwLen = UNLEN + 1;
				TCHAR cUser[ UNLEN + 1 ];
				::GetUserName( cUser, &dwLen );
				CString strUser( cUser );

				BSTR uplBy = (strUser.Left( 10 )).AllocSysString();
				COleDateTime dtToday = COleDateTime::GetCurrentTime();
				DATE uplDate = dtToday.m_dt;

				HRESULT hr = pServer->UploadRecord(fund,  
					date, price, uplBy, uplDate);

				::SysFreeString( fund );
				::SysFreeString( uplBy );

				if( FAILED( hr ))
				{
					CString strPrompt = "Upload of:\n";
					strPrompt += sd.GetAsString();
					strPrompt += "\nfailed";
					
					if( AfxMessageBox( strPrompt, MB_OKCANCEL ) == IDCANCEL )
						break;
				}
						 
			}

			if( !pos ) // We got to the end of the loop
				AfxMessageBox( "Upload completed successfully" );
		}
		catch( _com_error e )
		{
			::MessageBox( NULL, e.ErrorMessage(), NULL, MB_OK );
		}
		pServer->Disconnect();

	}
	
	::CoUninitialize();
	
}

void CSTUploadDoc::OnUpdateDataUpload(CCmdUI* pCmdUI) 
{
	// Enable the UploadData command only if there is 
	// data on file and a fund currently selected for viewing
		
	BOOL bEnable = GetCurrentFund().IsEmpty() ? FALSE : TRUE;

	pCmdUI->Enable( bEnable );		
	
}

void CSTUploadDoc::OnDataQuerydatabase() 
{
	CQueryDialog aQDlg;
	
	// Set the default values for the Date Time Picker controls
	// with first and last date on file (all funds)
	CStockData sdFirst = m_DocList.GetHead();
	CStockData sdLast = m_DocList.GetTail();

	aQDlg.m_fromdate = sdFirst.GetDate();
	aQDlg.m_todate = sdLast.GetDate();


	if( aQDlg.DoModal() == IDOK )
	{
		// Construct query
		CString strQuery = "select * from PriceHistory where ph_fund = '";
		strQuery += aQDlg.m_strFund;
		strQuery += "' and ph_date between '";
		strQuery += aQDlg.m_fromdate.Format( "%Y/%m/%d" );
		strQuery += "' and '";
		strQuery += aQDlg.m_todate.Format( "%Y/%m/%d" );
		strQuery += "'";

		// Construct caption string
		CString strCaption = aQDlg.m_strFund;
		strCaption += " Prices ";
		strCaption += aQDlg.m_fromdate.Format( "%d/%m/%Y" );
		strCaption += " - ";
		strCaption += aQDlg.m_todate.Format( "%d/%m/%Y" );

		CResultsDialog rd;

		rd.m_strQuery = strQuery;
		rd.m_strCaption = strCaption;

		rd.DoModal();

	}	
}

void CSTUploadDoc::OnUpdateDataQuerydatabase(CCmdUI* pCmdUI) 
{
	// Enable the Query Database command only if there is 
	// data on file and a fund currently selected for viewing

	BOOL bEnable = FALSE;

	bEnable = m_strCurrentFund.IsEmpty() ? FALSE : TRUE;

	pCmdUI->Enable( bEnable );		
	
}
