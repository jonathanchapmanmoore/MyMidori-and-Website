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
